#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_autoPwr
//	automatically toggles devices on/off depending on animation/gesture states. Specifically
//	turns devices on when weapon is up, canted, or player is aiming down the sights.
//
//	this script is only called by client FOR player, but will
//	transmit results to all devices via gjb_itn_deviceState
//
//*****************************************************************************//

params ["_mode"];

_eh = player getVariable ["gjb_itn_autoUpEH",["",-1]];
player removeEventHandler [_eh #0, _eh #1];

//_autoMode = player getVariable ["gjb_itn_autoOn",0];

//if(_autoMode == 0)then{
	switch (_mode)do {
		//Manual activation only
		case 0: {};

		//Weapon Up
		case 1: {
			_eh = player addEventHandler ["AnimChanged", { 
				params ["_unit","_anim"]; 
				_ds = player getVariable "gjb_itn_deviceState";
				if("mstpsras" in _anim || "mtacsras" in _anim || "mwlksras" in _anim || "mrunsras" in _anim || "mevasras" in _anim)then{ 
					_ds set [0,1];
					}else{ 
					_ds set [0,0];
					}; 
				player setVariable ["gjb_itn_deviceState",_ds,true];
			}];
			_anim = animationState player;
			if("mstpsras" in _anim || "mtacsras" in _anim || "mwlksras" in _anim || "mrunsras" in _anim || "mevasras" in _anim)then{ 
				_ds = player getVariable "gjb_itn_deviceState";
				_ds set [0,1];
				player setVariable ["gjb_itn_deviceState",_ds,true];
			};
			player setVariable ["gjb_itn_autoUpEH",["AnimChanged",_eh]];
		};

		//Weapon Pointed
		case 2: {
			_eh = player addEventHandler ["AnimChanged", { 
				params ["_unit","_anim"]; 
				_ds = player getVariable "gjb_itn_deviceState";
				if("mstpsras" in _anim || "mtacsras" in _anim || "mwlksras" in _anim)then{ 
					_ds set [0,1];
					}else{ 
					_ds set [0,0];
					}; 
				player setVariable ["gjb_itn_deviceState",_ds,true];
			}];
			_anim = animationState player;
			if("mstpsras" in _anim || "mtacsras" in _anim || "mwlksras" in _anim)then{ 
				_ds = player getVariable "gjb_itn_deviceState";
				_ds set [0,1];
				player setVariable ["gjb_itn_deviceState",_ds,true];
			};
			player setVariable ["gjb_itn_autoUpEH",["AnimChanged",_eh]];
		};

		//GGE Canting
		case 3:	{
			//something something set which variable to look for here
		/*	_eh = player addEventHandler ["GestureChanged", { 
				params ["_unit","_gesture"]; 
				_ds = player getVariable "gjb_itn_deviceState";
				if(_gesture == "gge_canting_anim_cantedaim")then{ 	//has issue when on normal and move muzzle
					player action ["IRLaserOff", player];
					player action ["GunLightOff", player];
					_ds set [0,1];
					}else{ 
					_ds set [0,0];
					}; 
				player setVariable ["gjb_itn_deviceState",_ds];
			}];
			_gesture = gestureState player;
			if(_gesture == "gge_canting_anim_cantedaim")then{
				_ds = player getVariable "gjb_itn_deviceState";
				_ds set [0,1];
				player setVariable ["gjb_itn_deviceState",_ds];
			};
			player setVariable ["gjb_itn_autoUpEH",["GestureChanged",_eh]];*/
		};

		//ADS	--------------	Add optional iron/reflex/magnified optic check?
		case 4:	{
			_eh = player addEventHandler ["OpticsSwitch", { 
				params ["_unit","_isADS"]; 
				_ds = player getVariable "gjb_itn_deviceState";
				if(_isADS)then{ 
					_ds set [0,1];
					}else{ 
					_ds set [0,0];
					}; 
				player setVariable ["gjb_itn_deviceState",_ds];
			}];
			if(cameraView == "GUNNER")then{ 
				_ds = player getVariable "gjb_itn_deviceState";
				_ds set [0,1];
				player setVariable ["gjb_itn_deviceState",_ds];
			};
			player setVariable ["gjb_itn_autoUpEH",["OpticsSwitch",_eh]];
		};
	};

	//player setVariable ["gjb_itn_autoOn",1];
	player setVariable ["gjb_itn_autoOnMode",_mode];
	private _modeTitle = [
		"Activate with button only",
		"Activate when weapon is raised",
		"Activate when weapon is aimed",
		"Activate when canting weapon",
		"Activate when aiming down sights"
	]; 
	[[_deviceImg, 2.0],[_modeTitle #_mode],true] call CBA_fnc_notify;
/*}else{
	_ds = player getVariable "gjb_itn_deviceState";
	_ds set [0,0];
	player setVariable ["gjb_itn_deviceState",_ds];
	player setVariable ["gjb_itn_autoOn",0];
	[[_deviceImg, 2.0],["Automatic activation: OFF"],true] call CBA_fnc_notify;
};*/



/*

	//===
	on toggle mode
	case dS#0
				== 0 then set -11							//powered off initialization
				>= 1 && <= 10 then +10			//Activate automode
				<= -1 && >= -10 then -10
				> 10 then -10									//Deactivate automode
				< -10 then +10

	if dS#0 < -10 || > 10 then ctrlPwr should remove 10 and invert

	in EH (fired every change anim/gesture or camera change)
				if dS#0 < -10 || > 10 then *-1					//auto-toggle device
	//===

	_wepUp = [
		"mstpsras",
		"mtacsras",
		"mwlksras"
	];
	_specAds = [
		"gge_canting_anim_cantedaim"
	];

	//For AWP
	_oldEh = player getVariable ["gjb_eh",-1];
	player removeEventHandler ["AnimChanged",_oldEh];
	_eh = player addEventHandler ["AnimChanged", { 
		params ["_unit","_anim"]; 
		_ds = player getVariable "gjb_itn_deviceState";
		_rep = -1; 
		if("mstpsras" in _anim || "mtacsras" in _anim || "mwlksras" in _anim)then{ 
			_rep = "Up";
			_ds set [0,1];
			}else{ 
			_rep = "Down";
			_ds set [0,0];
			}; 
		player setVariable ["gjb_itn_deviceState",_ds];
		systemChat format ["%1",_rep]; 
	}];
	player setVariable ["gjb_eh",_eh];
	_eh;

	//For AGGEC ------ GGE is broken, vLaser won't not activate
	_oldEh = player getVariable ["gjb_eh",-1];
	player removeEventHandler ["GestureChanged",_oldEh];
	_eh = player addEventHandler ["GestureChanged", { 
	params ["_unit","_gesture"]; 
	_ds = player getVariable "gjb_itn_deviceState";
	_rep = -1; 
	if(_gesture == "gge_canting_anim_cantedaim")then{ 
	_rep = "On";
	_ds set [0,1];
	}else{ 
	_rep = "Off";
	_ds set [0,0];
	}; 
	player setVariable ["gjb_itn_deviceState",_ds];
	systemChat format ["%1",_rep];
	}];
	player setVariable ["gjb_eh",_eh];
	_eh;

	//For autoADS
	_oldEh = player getVariable ["gjb_eh",-1];
	player removeEventHandler ["OpticsSwitch",_oldEh];
	_eh = player addEventHandler ["OpticsSwitch", { 
	params ["_unit","_isADS"]; 
	_ds = player getVariable "gjb_itn_deviceState";
	_rep = -1; 
	if(_isADS)then{ 
	_rep = "On";
	_ds set [0,1];
	}else{ 
	_rep = "Off";
	_ds set [0,0];
	}; 
	player setVariable ["gjb_itn_deviceState",_ds];
	systemChat format ["%1",_rep];
	}];
	player setVariable ["gjb_eh",_eh];
	_eh;

*/