#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_initMode
//	
//	Initializes the gjb_itn_deviceState for the player on first interaction with
//	device controls (gjb_itn_fnc_ctrlPwr, gjb_itn_fnc_ctrlMode, or 
//	gjb_itn_fnc_ctrlOpenInterface) and sets device to appropriate defualt/off mode.
//
//	Returns value for _deviceState to calling script.
//
//*****************************************************************************//

params ["_unit"];

private _w = currentWeapon _unit;
private _wP = primaryWeapon _unit;
private _wH = handgunWeapon _unit;
private _wL = secondaryWeapon _unit;
private _device = "";

switch(_w)do{
	case(_wP):{
		_device = primaryWeaponItems _unit #1;
	};
	case(_wH):{
		_device = handgunItems _unit #1;
	};
	case(_wL):{
		_device = secondaryWeaponItems _unit #1;
	};
};

private _deviceState = [0,0,0,0,0,0];
private _deviceC = [_device] call gjb_itn_fnc_hasCompat;
private _cfgAc = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;

// default modes
private _default = 0;
if(_device != "")then{
	private _controls = getArray (_cfgAc >> "gjb_itn_controls"); 
	_default =  _controls #0;
	//Set default mode to IR if Simple Controls
	private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];
	private _choose = 0;
	if(_simpleCtrl == true)then{
		_choose = 1;
	};
	_default = _default #_choose;
};
_deviceState set [4,_default];
_deviceState set [0,0];

[_unit,_deviceState] call gjb_itn_fnc_getWeaponOffset;
[_unit,_deviceState] call gjb_itn_fnc_modeSpec;

_deviceState;