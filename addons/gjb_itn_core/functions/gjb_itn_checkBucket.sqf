#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_checkBucket
//
//	runs gjb_itn_fnc_getModelOffset and gjb_itn_fnc_modeSpec in scheduled space,
//	only if they are not already running for the given _unit.
//
//		===	potentially use "AnimChanged" EH to detect weapon swapping and new weapon?
//
//*****************************************************************************//

params ["_unit","_deviceState"];

private _check = _unit getVariable ["gjb_itn_checker",false];
private _debug = missionNamespace getVariable ["gjb_itn_setting_debug",false];

if(_debug)then{
	private _reset = missionNamespace getVariable ["gjb_itn_setting_reset",false];
	if(_reset)then{
		[] call gjb_itn_fnc_debugCmd;
	};
};

private _offsetRun = _check;
private _specRun = _check;

//Run gjb_itn_fnc_getModelOffset in scheduled space if it isn't already running
if(Local _unit && !_offsetRun)then{

	private _last = _unit getVariable ["gjb_itn_lastConfig",["?","?","?","?",0,0,0]];

	private _w = currentWeapon _unit;
	private _aP = primaryWeaponItems _unit #1;
	private _aH = handgunItems _unit #1;
	private _aL = secondaryWeaponItems _unit #1;

	if(_w != _last #0)then{
		_unit setVariable ["gjb_itn_checker",true];

		//systemChat format ["Checker level Weapon Offset :: %1",systemTime #6];

		[_unit,_deviceState] spawn {[_this #0,_this #1] call gjb_itn_fnc_getWeaponOffset;};
	}else{
		if((_aP != _last #1 && (primaryWeapon _unit) != "Rifle") || _aH != _last #2 || _aL != _last #3)then{
			_unit setVariable ["gjb_itn_checker",true];

			//systemChat format ["Checker level Device Offset :: %1",systemTime #6];

			[_unit,_deviceState] spawn {[_this #0,_this #1,"",""] call gjb_itn_fnc_getDeviceOffset;};
		};
	};
};

//Run gjb_itn_fnc_modeSpec in scheduled space if it isn't already running
if(_unit != player && !_specRun)then{

	private _last = _unit getVariable ["gjb_itn_lastConfig",["?","?","?","?",0,0,0]];
	private _lastDS = _last #4;
	private _lastIS = _last #5;
	private _dS = _deviceState #4;
	private _iS = _deviceState #2;

	//runs only if mode has changed
	if (_dS != _lastDS || _iS != _lastIS)then{
		_unit setVariable ["gjb_itn_checker",true];

		//systemChat format ["Checker level Mode Spec :: %1",systemTime #6];

		[_unit,_deviceState] spawn {[_this #0,_this #1] call gjb_itn_fnc_modeSpec;};
	};
};