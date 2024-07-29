#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_debugCmd
//
//	Resets gjb_itn_deviceState, gjb_itn_lastConfig, and gjb_itn_deviceOffset, and
//	calls gjb_itn_fnc_getWeaponOffset to refresh those variables.
//
//*****************************************************************************//

systemChat "Begin reset";

private _unit = call CBA_fnc_currentUnit;

//clear variables
_unit setVariable ["gjb_itn_deviceState",nil];
_unit setVariable ["gjb_itn_deviceOffset",nil];
_unit setVariable ["gjb_itn_lastConfig",nil];
_unit setVariable ["gjb_itn_deviceComboState",nil];

systemChat "Variables cleared";

//prep dummy deviceState for function call
private _deviceState = [_unit] call gjb_itn_fnc_initMode; // [0,0,0,0,0,0];
private _curW = currentWeapon _unit;
private _primW = primaryWeapon _unit;
private _sideW = handgunWeapon _unit;
private _launW = secondaryWeapon _unit;
private _binoW = binocular _unit;

switch(_curW)do{
	case _primW : {_deviceState set [5,0]};
	case _sideW : {_deviceState set [5,1]};
	case _launW : {_deviceState set [5,2]};
	case _binoW : {_deviceState set [5,3]};
	default {_deviceState set [5,-1]};
};

systemChat "Mode prepped";

//call function to recreate variables
[_unit,_deviceState] call gjb_itn_fnc_getWeaponOffset;

systemChat "Reset called";

//Reset checkbox in settings
//missionNamespace setVariable ["gjb_itn_debugCmd",false];
missionNamespace setVariable ["gjb_itn_setting_reset",false];