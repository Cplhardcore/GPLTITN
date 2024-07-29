#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_changeKnobs
//
//	Updates the knob states for device interfaces, if deviceMode changes while
//	the interface is still open. Is called from gjb_itn_fnc_ctrlModes
//
//*****************************************************************************//

params ["_unit","_mode","_interface"];

//Collect previous states
private _knobState = _unit getVariable ["gjb_itn_knobState"];
private _lastMode = -1;
private _cfgRsc = configFile >> _interface;

nil;