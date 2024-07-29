#include "script_component.hpp"
/*
gjb_itn_fnc_zm_activateLaser
*/

params ["_logic"];

private _unit = attachedTo _logic;
deleteVehicle _logic;

private _isAttached = !isNull _unit;

//Checks that unit is infantry
if (_isAttached && {!(_unit isKindOf "CAManBase")}) exitWith {
    [objNull,"UNIT MUST BE INFANTRY"] call BIS_fnc_showCuratorFeedbackMessage;
};

//Checks that unit is alive
if (_isAttached && {!alive _unit}) exitWith {
    [objNull,"UNIT MUST BE ALIVE"] call BIS_fnc_showCuratorFeedbackMessage;
};

//Checks that unit has appropriate device
private _w = currentWeapon _unit;
private _cfgW = configFile >> "CfgWeapons" >> _w;
private _t = getNumber(_cfgW >> "type");
private _a = "";
switch(_t)do{
	case 1: {	//rifles
		_a = primaryWeaponItems _unit #1;
	};
	case 2: {	//pistols
		_a = handgunItems _unit #1;
	};
	case 4: {	//launchers
		_a = secondaryWeaponItems _unit #1;
	};
};
private _cfg = configFile >> "CfgITNCompat" >> "accessories" >> _a;
private _hasDevice = isClass (_cfg);

if (_isAttached && !_hasDevice) exitWith {
    [objNull,"UNIT MUST HAVE COMPATIBLE DEVICE"] call BIS_fnc_showCuratorFeedbackMessage;
};

//Activate _unit's laser device

private _deviceState = _unit getVariable ["gjb_itn_deviceState",[0,0,0,0,0,0]];
_deviceState set [0,1];
_deviceState set [1,1];
_deviceState set [2,1];

private _mode = (getArray (_cfg >> "gjb_itn_controls") #0) +1;
_deviceState set [4,_mode];

_unit setVariable ["gjb_itn_deviceState",_deviceState];
