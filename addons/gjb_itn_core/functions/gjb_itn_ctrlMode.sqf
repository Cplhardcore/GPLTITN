#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_ctrlMode
//	controls device mode switching
//
//	this script is only called by client FOR player, but will
//	transmit results to all devices via gjb_itn_deviceState
//
//	_fnc
//		0 = select next mode
//		1 = select prev mode
//
//*****************************************************************************//

params ["_fnc"];

//Shortstop if player is in zeus menu
if (!isNull findDisplay 312) exitWith {false};

//prepare data retrieval from config
private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];

//Ensures device is defaulted if first activation
if(!(_deviceState isEqualType []))then{
	_deviceState = [_unit] call gjb_itn_fnc_initMode;
};

private _mode = _deviceState #4;
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

//stops script if current weapon has no device attached
if(_device == "")exitWith{};

//retrieve device mode count
private _deviceC = [_device] call gjb_itn_fnc_hasCompat;
private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;
private _modes = getArray (_deviceCfg >> "gjb_itn_deviceModes");
private _modeCount = (count _modes) -1;
private _modeName = "";
private _deviceImg = getText (configFile >> "CfgWeapons" >> _device >> "picture");

//Prep in case interface is open
private _ctrls = (getArray (_deviceCfg >> "gjb_itn_controls"));
private _controller = getArray (_deviceCfg >> "gjb_itn_interface") #0;
private _interface = getArray (_deviceCfg >> "gjb_itn_interface") #1;
private _interID = getNumber (configFile >> _interface >> "idd");

//Prep for Simple Controls adjustment
private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];
private _genericOnly = missionNamespace getVariable ["gjb_itn_setting_genericInterface",false];
private _off = _ctrls #1 #0;
private _bottomStop = _ctrls #1 #1;

//Correct for generic interface input
switch(true)do{
	case (_fnc == 1.1);
	case (_fnc == 0.1): {
		_controller = "generic";
		_fnc = _fnc - 0.1;
		_interID = 314000;
	};
	case (_genericOnly): {
		_controller = "generic";
		_interID = 314000;
	};
};

//Function handles calling of applicable device control script
private _callControl = {
	switch(_controller)do{
		case "generic":{
			_unit setVariable ["gjb_itn_genDevListLatch",0];
			private _display = findDisplay 314000;
			private _id = _display displayCtrl 1000;
			_newMode = _newMode - _bottomStop;
			if(_simpleCtrl == true && _newMode > _off)then{
				_id lbSetCurSel (_newMode -1);
			}else{
				_id lbSetCurSel _newMode;
			};
		};
		case "dbal_a2":{["mode0",0,"k"] call gjb_itn_fnc_deviceDbalA2;};
		case "peq_15":{["mode0",0,"k"] call gjb_itn_fnc_devicePeq15;};
		case "peq_16":{["mode0",0,"k"] call gjb_itn_fnc_devicePeq16;};
		case "peq_15_combo":{["mode0",0,"k"] call gjb_itn_fnc_devicePeq15Combo;};
		case "m952":{["mode0",0,"k"]  call gjb_itn_fnc_deviceM952;};
		case "perst3":{["mode0",0,"k"] call gjb_itn_fnc_devicePerst3;};
		case "perst3_combo":{["mode0",0,"k"] call gjb_itn_fnc_devicePerst3Combo;};
		case "peq_2":{["mode0",0,"k"] call gjb_itn_fnc_devicePeq2;};
		case "peq_2_combo":{["mode0",0,"k"] call gjb_itn_fnc_devicePeq2Combo;};
		case "gtl_21":{["mode0",0,"k"] call gjb_itn_fnc_deviceGTL21;};
		case "mk23":{["mode0",0,"k"] call gjb_itn_fnc_deviceMk23;};
		case "llm_01":{["mode0",0,"k"]  call gjb_itn_fnc_deviceLLM01;};
		case "llm_mk3":{["mode0",0,"k"]  call gjb_itn_fnc_deviceLLMmk3;};
		case "la_5b":{["mode0",0,"k"] call gjb_itn_fnc_deviceLA5B;};
		case "la_5b_combo":{["mode0",0,"k"] call gjb_itn_fnc_deviceLA5BCombo;};
		case "ngal":{["mode0",0,"k"] call gjb_itn_fnc_deviceNGAL;};
		case "ngal_combo":{["mode0",0,"k"] call gjb_itn_fnc_deviceNGALCombo;};
		//case "la_5b_combo_vis":{["mode0",0,"k"] call gjb_itn_fnc_deviceLA5BComboVis;};
		default {/*	[_unit,_newMode,_interface] call gjb_itn_fnc_keyChangeKnobs;*/};
	};
};

//assign behavior depending on input
switch(true)do{
	//set next mode unless already at last mode
	case(_fnc == 0 && _mode < _modeCount):{
		private _newMode = _mode +1;
		//Disable OFF mode if Simple Controls
		if(_simpleCtrl == true && _newMode == _off && _newMode < _modeCount)then{
			_newMode = _mode +2;
		}; 
		_deviceState set [4,_newMode];
		_modeName = (_modes select _newMode) #3;
		[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
		if(!(isNull findDisplay _interID))then{
			[] call _callControl;
		}else{
			[[_deviceImg, 2.0],[_modeName],true] call CBA_fnc_notify;
			if(_controller == "mk23")then{
				[] call _callControl;
			};
		};
		playSound "click";
	};
	//set previous mode unless already at first mode
	case(_fnc == 1 && _mode > _bottomStop):{
		private _newMode = _mode -1;
		//Disable OFF mode if Simple Controls
		if(_simpleCtrl == true && _newMode == _off && _newMode > _bottomStop)then{
			_newMode = _mode -2;
		}; 
		_deviceState set [4,_newMode];
		_modeName = (_modes select _newMode) #3;
		[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
		if(!(isNull findDisplay _interID))then{
			[] call _callControl;
		}else{
			[[_deviceImg, 2.0],[_modeName],true] call CBA_fnc_notify;
			if(_controller == "mk23")then{
				[] call _callControl;
			};
		};
		playSound "click";
	};
};

_unit setVariable ["gjb_itn_deviceState",_deviceState, true];