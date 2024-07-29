#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_deviceGeneric
//
//	Takes input from Interface and controls general device features for generic and unsupported devices
//
//		Device specific features:
//				programmable pulse/strobe for laser mode
//				patterned diffusors for the laser?
//
//*****************************************************************************//

params ["_ctrl","_input","_type"];

//prepare data retrieval from config
private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];

//Determine device
private _deviceCategory = _deviceState #5;
private _device = "";
switch(_deviceCategory)do{
	case 0: {
		_device = toLower (primaryWeaponItems _unit #1);
	};
	case 1: {
		_device = toLower (handgunItems _unit #1);
	};
	case 2: {
		_device = toLower (secondaryWeaponItems _unit #1);
	};
};

//Pull device data from config
private _deviceC = [_device] call gjb_itn_fnc_hasCompat;
private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;
private _ctrls = getArray (_deviceCfg >> "gjb_itn_controls");
private _off = _ctrls #1 #0;
private _bottomStop = _ctrls #1 #1;
private _mode = _deviceState #4;
private _topStop = (count (getArray (_deviceCfg >> "gjb_itn_deviceModes")) ) -1;
private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];
private _genericInterface = missionNamespace getVariable ["gjb_itn_setting_genericInterface",false];
private _display = findDisplay 314000;

switch(_ctrl)do{
	case "mode":{
		[_input] call gjb_itn_fnc_ctrlMode;
		playSound "click";
		private _list = _display displayCtrl 1000;
		ctrlSetFocus _list;
	};
	case "fire":{
		[2,1.1] call gjb_itn_fnc_ctrlPwr;
		playSound "click";
	};
	case "list":{
		private _mode = _input;
		private _doWork = _unit getVariable ["gjb_itn_genDevListLatch",1];

		if(_doWork == 1)then{

			//adjust for culled modes
			if(_bottomStop > 0)then{
				_mode = _mode + _bottomStop;
			};

			if(_simpleCtrl == true && _mode >= _off)then{
				_mode = _mode +1;
			};
			_deviceState set [4,_mode];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			playSound "click";
		};
		_unit setVariable ["gjb_itn_genDevListLatch",nil];
	};
	case "autoMode":{};
	case "illum":{
		[_input] call gjb_itn_fnc_illumFocus;
		//selectively disable graphics, to cue player to state of illum
		private _newMode = _unit getVariable "gjb_itn_deviceState";
		_newMode = _newMode #2;
		private _canFoc = 0;
		private _canDif = 0;
		private _maxBeam = 10;
		if((count _ctrls) > 2)then{
			private _illumCtrls = _ctrls #2;
			_canFoc = _illumCtrls #0;
			_canDif = _illumCtrls #1;
			if((count _illumCtrls) > 2)then{
				_maxBeam = _illumCtrls #2;
			};
		};
		private _wButton = (findDisplay 314000) displayCtrl 1001;
		private _tButton = (findDisplay 314000) displayCtrl 1002;
		if(_canFoc == 1)then{
			private _maxModeB = 1.000 + (_maxBeam / 1000);
			private _maxModeD = 1.100 + (_maxBeam / 1000);
			switch(_newMode)do{
				case 0;
				case 1;
				case -1;
				case _maxModeB;
				case -_maxModeB;
				case _maxModeD;
				case -_maxModeD: {
					_wButton ctrlSetTextColor [0.2,0.2,0.2,1];
				};
				default {
					_wButton ctrlSetTextColor [
						(profileNamespace getVariable ['igui_text_rgb_r',0.13]),
						(profileNamespace getVariable ['igui_text_rgb_g',0.54]),
						(profileNamespace getVariable ['igui_text_rgb_b',0.21]),
						(profileNamespace getVariable ['igui_text_rgb_a',0.8])
					];
				};
			};
			switch(true)do{
				case (_newMode > 1 && _newMode <= 1.001);
				case (_newMode > 1.1 && _newMode <= 1.101);
				case (_newMode < -1 && _newMode >= -1.001);
				case (_newMode < -1.1 && _newMode >= -1.101): {
					_tButton ctrlSetTextColor [0.2,0.2,0.2,1];
				};
				default {
					_tButton ctrlSetTextColor [
						(profileNamespace getVariable ['igui_text_rgb_r',0.13]),
						(profileNamespace getVariable ['igui_text_rgb_g',0.54]),
						(profileNamespace getVariable ['igui_text_rgb_b',0.21]),
						(profileNamespace getVariable ['igui_text_rgb_a',0.8])
					];
				};
			};
		}else{
			_tButton ctrlSetTextColor [0.2,0.2,0.2,1];
			_wButton ctrlSetTextColor [0.2,0.2,0.2,1];
		};
		//Diffusor button
		private _difButton = (findDisplay 314000) displayCtrl 1003;
		if(_canDif == 1)then{
			switch(true)do{
				case (_newMode <= -1.1 || _newMode >= 1.1): {
					_difButton ctrlSetTextColor [1,0.8,0.2,1];
				};
				case (_newMode > -1.1 && _newMode < 1.1): {
					_difButton ctrlSetTextColor [
						(profileNamespace getVariable ['igui_text_rgb_r',0.13]),
						(profileNamespace getVariable ['igui_text_rgb_g',0.54]),
						(profileNamespace getVariable ['igui_text_rgb_b',0.21]),
						(profileNamespace getVariable ['igui_text_rgb_a',0.8])
					];
				};
			};
		}else{
			_difButton ctrlEnable false;
			_difButton ctrlSetTextColor [0.2,0.2,0.2,1];
		};
	};
};