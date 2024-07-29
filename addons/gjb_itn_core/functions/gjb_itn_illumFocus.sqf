#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_illumFocus
//
//	handles illuminator options in gjb_itn_deviceState
//
//	Player only, will broadcast!
//
//	_deviceState
//
//*****************************************************************************//

params ["_ctrl"];

//Shortstop if player is in zeus menu
if (!isNull findDisplay 312) exitWith {false};

private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable "gjb_itn_deviceState";

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

private _deviceC = [_device] call gjb_itn_fnc_hasCompat;

private _config = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;
private _options = getArray(_config >> "gjb_itn_controls");
private _interfaceCfg = getArray (_config >> "gjb_itn_interface");
private _controller = _interfaceCfg #0;
private _interface = _interfaceCfg #1;

private _function = "";
private _newInput = 0;
switch(_ctrl)do{
	case 0: {	//widen
		_function = "illumW";
		_newInput = 1;
	};
	case 1: {	//tighten
		_function = "illumW";
		_newInput = -1;
	};
	case 2: {	//diff
		_function = "illumU";};
};

/*private _genericsOnly = missionNamespace getVariable "gjb_itn_setting_genericInterface";
if(_genericsOnly)then{
	_controller = "generic";
};*/

private _shortStop = true;
switch(_controller)do{
	case "dbal_a2":{[_function,_newInput,"k"] call gjb_itn_fnc_deviceDbalA2;};
	case "peq_15":{[_function,_newInput,"k"] call gjb_itn_fnc_devicePeq15;};
	case "peq_16":{[_function,_newInput,"k"] call gjb_itn_fnc_devicePeq16;};
	case "peq_15_combo":{[_function,_newInput,"k"] call gjb_itn_fnc_devicePeq15Combo;};
	case "perst3":{[_function,_newInput,"k"] call gjb_itn_fnc_devicePerst3;};
	case "perst3_combo":{[_function,_newInput,"k"] call gjb_itn_fnc_devicePerst3Combo;};
	case "peq_2":{[_function,_newInput,"k"] call gjb_itn_fnc_devicePeq2;};
	case "peq_2_combo":{[_function,_newInput,"k"] call gjb_itn_fnc_devicePeq2Combo;};
	case "mk23":{
		if(_type == 2)then{
			["filter",0,"k"] call gjb_itn_fnc_deviceMk23;
		};
	};
	case "llm_mk3":{["illum",_ctrl,"k"]  call gjb_itn_fnc_deviceLLMmk3;};
	case "la_5b":{[_function,_newInput,"k"] call gjb_itn_fnc_deviceLA5B;};
	case "la_5b_combo":{[_function,_newInput,"k"] call gjb_itn_fnc_deviceLA5BCombo;};
	case "ngal":{
		if(_ctrl == 2)then{
			_function = "illumDiff";
		};
		[_function,_newInput,"k"] call gjb_itn_fnc_deviceNGAL;
	};
	case "ngal_combo":{
		if(_ctrl == 2)then{
			_function = "illumDiff";
		};
		[_function,_newInput,"k"] call gjb_itn_fnc_deviceNGALCombo;
	};
	default {_shortStop = false;};
};
if(_shortStop)exitWith{};

private _illumMode = _deviceState #2;
private _canFocus = _options #2 #0;
private _canDiffuse = _options #2 #1;
private _isOff = false;

private _genericState = "10";

switch(_ctrl)do{
	case 1:{	//Focus tighten		- 0.001
		if(_canFocus == 1)then{
			switch(true)do{
				case (_illumMode == 0);
				case (_illumMode == -1): {
					_illumMode = -1.009;
				};
				case (_illumMode > -1.011 && _illumMode < -1.001);
				case (_illumMode > -1.111 && _illumMode < -1.101):{
					_illumMode = _illumMode +0.001;
				};
				case (_illumMode == 1):{
					_illumMode = 1.009;
				};
				case (_illumMode > 1.001 && _illumMode < 1.011);
				case (_illumMode > 1.101 && _illumMode < 1.111): {
					_illumMode = _illumMode -0.001;
				};
			};
		};
	};
	case 0:{	//focus widen		+0.01
		if(_canFocus == 1)then{
			switch(true)do{
				case (_illumMode == 0);
				case (_illumMode == -1): {
					_illumMode = -1.010;
				};
				case (_illumMode > -1.010 && _illumMode < -1.000);
				case (_illumMode > -1.110 && _illumMode < -1.100):{
					_illumMode = _illumMode -0.001;
				};
				case (_illumMode == 1):{
					_illumMode = 1.010;
				};
				case (_illumMode > 1.000 && _illumMode < 1.010);
				case (_illumMode > 1.100 && _illumMode < 1.110): {
					_illumMode = _illumMode +0.001;
				};
			};
		};
	};
	case 2:{	//Diffusor cap toggle +/- 0.60
		if(_canDiffuse == 1)then{
			switch(true)do{
				case (_illumMode == 0);
				case (_illumMode == -1): {
					_illumMode = -1.110;
				};
				case (_illumMode == 1): {
					_illumMode = 1.110;
				};
				case (_illumMode >-1.1 && _illumMode < -1);
				case (_illumMode > 1.1): {
					_illumMode = _illumMode -0.1;
				};
				case (_illumMode > 1 && _illumMode < 1.1);
				case (_illumMode < -1.1): {
					_illumMode = _illumMode +0.1;
				};
			};
		};
	};
};

_deviceState set [2,_illumMode];
//_unit setVariable ["gjb_itn_deviceState",_deviceState,true];

[_unit,_deviceState] call gjb_itn_fnc_modeSpec;