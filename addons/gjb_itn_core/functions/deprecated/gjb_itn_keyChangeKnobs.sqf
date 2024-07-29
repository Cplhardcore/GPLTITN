#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_keyChangeKnobs
//
//	Hides active knobs on interface if deviceMode changes while
//	the interface is still open before calling gjb_itn_fnc_getInterfaceKnobs
//	to update and show appropriate knobs. Is called from gjb_itn_fnc_ctrlModes
//
//*****************************************************************************//

params ["_unit","_mode","_interface"];

//Collect previous states
private _knobState = _unit getVariable "gjb_itn_knobPos";
private _cfgRsc = configFile >> _interface;
_knobState deleteAt 0;
{
	private _ctrl = (getArray (_cfgRsc >> "controls")) # _x;
	private _id = getNumber (configFile >> _interface >> _ctrl >> "idc");
	ctrlShow [_id,false];
} forEach _knobState;

[_unit,_mode,_interface] call gjb_itn_fnc_getInterfaceKnobs;