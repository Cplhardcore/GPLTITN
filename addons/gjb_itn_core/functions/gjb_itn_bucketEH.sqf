#include "script_component.hpp"

private _gjb_itn_bucketEH = addMissionEventHandler ["EachFrame",{

	private _checker = player getVariable ["gjb_itn_unitChecker",false];
	private _drawDist = missionNamespace getVariable ["gjb_itn_setting_drawDist",1000];
	private _visMode = currentVisionMode player;


	//Prep environmental effect variables
		//Humidity
		private _aceHumActive = missionNamespace getVariable ["ace_weather_enabled",false];
		private _humidity = humidity;
		if(_aceHumActive)then{
			_humidity = missionNamespace getVariable ["ace_weather_currentHumidity",-1];
			if(_humidity == 1)then{_humidity = 0.95;};
		};
		//Daylight
		private _sun = getLighting #1;
			//prep formulae
			private _dayDotColorMod = 740 * (1 - (1.5/(1.5 + (_sun/85000))));//(74 * (1 + _sun))/85000;
			private _dayDotSizeMod = (0.08 /(0.08 + (_sun/400)));
			private _dayBeamColorMod =  1/(1 + (_sun/100));  //final *0.001 by 2k illum should work great
			private _dayBeamSizeMod = 100/(100 + (_sun/4));
			private _dayBeamLengthMod = 0.5/(0.5 + (_sun/25));
			if(_debug)then{
				private _dDCMa = player getVariable ["gjb_itn_debugLaserDotColor",[740,1.5,85000]];
				_dayDotColorMod = _dDCMa #0 * (1 - (_dDCMa #1/(_dDCMa #1 + (_sun/_dDCMa #2))));
				private _dDSMa = player getVariable ["gjb_itn_debugLaserDotSize",[0.08,400]];
				_dayDotSizeMod = (_dDSMa #0 /(_dDSMa #0 + (_sun/_dDSMa #1)));
				private _dBCMa = player getVariable ["gjb_itn_debugLaserBeamColor",[1,100]];
				_dayBeamColorMod = _dBCMa #0/(_dBCMa #0 + (_sun/_dBCMa #1));
				private _dBSMa = player getVariable ["gjb_itn_debugLaserBeamSize",[100,4]];
				_dayBeamSizeMod = _dBSMa #0/(_dBSMa #0 + (_sun/_dBSMa #1));
				private _dBLMa = player getVariable ["gjb_itn_debugLaserBeamLength",[0.5,25]];
				_dayBeamLengthMod = _dBLMa #0/(_dBLMa #0 + (_sun/_dBLMa #1));
			};
			private _dayModArray = [_dayDotColorMod,_dayDotSizeMod,_dayBeamColorMod,_dayBeamSizeMod,_dayBeamLengthMod];
		//
	//


	//create list of nearby living units for consideration once per second
	if (!_checker) then {
		player setVariable ["gjb_itn_unitChecker",true];
		[_drawDist] spawn {
			private _list = allUnits select { 
				alive _x 
				&& (player == _x || (player distance _x) <= ((_this #0) + 0.5))};
			player setVariable ["gjb_itn_nearUnits",_list];
			sleep 1;
			player setVariable ["gjb_itn_unitChecker",false];
			private _debug = missionNamespace getVariable ["gjb_itn_setting_debug",false];
			if(_debug)then{
				private _time = systemTime #6;
				private _varList = _list select {
					(_x getVariable ["gjb_itn_deviceState",0]) isEqualType []
				};
				private _count = count _varList;
				systemChat format ["%1: %2",_time,_count];
			};
		};
	};

	//Select and handle only units that have deviceState variable attached
	private _nearUnits = player getVariable ["gjb_itn_nearUnits",[]];
	private _activeUnits = _nearUnits select {
		(_x getVariable ["gjb_itn_deviceState",0]) isEqualType []
	};
	{		//perform tasks
		private _deviceState = _x getVariable ["gjb_itn_deviceState", [0]];

		//Turns off dead devices
		if (!alive _x) then {
			_deviceState set [0,0];
			_x setVariable ["gjb_itn_deviceState",_deviceState];
		};
		
		//run checkers in scheduled environment
		[_x,_deviceState] call gjb_itn_fnc_checkBucket;

		//render emissives (lasers, lights, etc) if origin is close enough to player and vision mode is not thermal
		if ((_deviceState #0) > 0 && (player distance _x) <= _drawDist && _visMode != 2)then{
			[_x,_deviceState,_humidity,_dayModArray] call gjb_itn_fnc_emissionCombined;
		}else{
			private _dScount = count _deviceState;
			if(_x == player && _dScount == 1)then{
				[player,_deviceState] spawn {[_this #0,_this #1] call gjb_itn_fnc_getWeaponOffset;};
			};
			//clean up all light objects for unit if device is not on
			private _illumObject = _x getVariable ["gjb_itn_illumObject",objNull];
			private _flashObject = _x getVariable ["gjb_itn_flashObject",objNull];
			deleteVehicle _illumObject;
			_x setVariable ["gjb_itn_illumObject",objNull];
			deleteVehicle _flashObject;
			_x setVariable ["gjb_itn_flashObject",objNull];
		};
		//=nix the vanilla IR laser==================
		if(_x isIRLaserOn currentWeapon _x || _x isFlashlightOn currentWeapon _x )then{
			private _vanillaOverride = _x getVariable ["gjb_itn_vanillaOverride",false];	//for cases such as IZLID mods that may want to keep using vanilla IR beam
			if(!_vanillaOverride)then{
				_x action ["IRLaserOff"];
				_x action ["GunLightOff"];
				//systemChat "IR Lightsaber disabled";
			}
		};
		//==================
	} forEach _activeUnits;

	//Handle canting auto-on feature==============
	private _autoOnMode = player getVariable ["gjb_itn_autoOnMode",0];
	if(_autoOnMode == 3 || _autoOnMode == 4)then{
		private _itnCantMode = missionNamespace getVariable ["gjb_itn_setting_cantingMods","gjb_itn_cantMode"];
		private _tog = player getVariable ["gjb_itn_autoOnCantToggle",false];
		switch(_itnCantMode)do{
			case "gjb_itn_cantMode": {
				private _canting = player getVariable ["gjb_itn_cantMode",false];
				switch(true)do{
					case (_canting && !_tog): {	//activate device
						player setVariable ["gjb_itn_autoOnCantToggle",true];
						_deviceState = player getVariable "gjb_itn_deviceState";
						_deviceState set [0,1];
						player setVariable ["gjb_itn_deviceState",_deviceState,true];
					};
					case (!_canting && _tog): {		//deactivate device
						player setVariable ["gjb_itn_autoOnCantToggle",false];
						_deviceState = player getVariable "gjb_itn_deviceState";
						_deviceState set [0,-1];
						player setVariable ["gjb_itn_deviceState",_deviceState,true];
					};
				};
			};
			case "gge_canting_var_cantingAim": {
				private _mode = missionNamespace getVariable "gge_canting_var_cantMode"; 
				private _aim = missionNamespace getVariable "gge_canting_var_cantingAim";
				switch(true)do{
					case (_mode && _aim && !_tog): {	//activate device
						player setVariable ["gjb_itn_autoOnCantToggle",true];
						_deviceState = player getVariable "gjb_itn_deviceState";
						_deviceState set [0,1];
						player setVariable ["gjb_itn_deviceState",_deviceState,true];
					};
					case (!_mode && !_aim && _tog);
					case (_mode && !_aim && _tog):{		//deactivate device
						player setVariable ["gjb_itn_autoOnCantToggle",false];
						_deviceState = player getVariable "gjb_itn_deviceState";
						_deviceState set [0,-1];
						player setVariable ["gjb_itn_deviceState",_deviceState,true];
					};
				};
			};
		};
	};
	//=================================

}];
player setVariable ["gjb_itn_bucketEH",_gjb_itn_bucketEH];