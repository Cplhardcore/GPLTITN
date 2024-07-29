#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_ctrlOpenInterface
//
//	Determines the appropriate device interface to create, hides all knobs, and
//	creates the appropriate dialog
//
//*****************************************************************************//

//Shortstop if player is in zeus menu
if (!isNull findDisplay 312) exitWith {false};

//identify device and prepare data retrieval from config
private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];
private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];
private _genericInterface = missionNamespace getVariable ["gjb_itn_setting_genericInterface",false];

//Ensures device is defaulted if first activation
if(!(_deviceState isEqualType []))then{
	_deviceState = [_unit] call gjb_itn_fnc_initMode;
};

private _isOn = _deviceState #0;
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

private _deviceC = [_device] call gjb_itn_fnc_hasCompat;
private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;

//pull interface
private _interfaceCfg = getArray (_deviceCfg >> "gjb_itn_interface");
private _controller = _interfaceCfg #0;
private _interface = _interfaceCfg #1;
private _offMode = getArray (_deviceCfg >> "gjb_itn_controls") #1 #0;

if(_genericInterface)then{
	_controller = "generic";
};

//Display interface
switch(_controller)do{
	case "dbal_a2":{["interface",0,"k"] call gjb_itn_fnc_deviceDbalA2;};
	case "xm8";
	case "utg":{["interface",0,"k"] call gjb_itn_fnc_deviceUTG;};
	case "peq_15":{["interface",0,"k"] call gjb_itn_fnc_devicePeq15;};
	case "peq_16":{["interface",0,"k"] call gjb_itn_fnc_devicePeq16;};
	case "peq_15_combo":{["interface",0,"k"] call gjb_itn_fnc_devicePeq15Combo;};
	case "m952":{["interface",0,"k"] call gjb_itn_fnc_deviceM952;};
	case "perst3":{["interface",0,"k"] call gjb_itn_fnc_devicePerst3;};
	case "perst3_combo":{["interface",0,"k"] call gjb_itn_fnc_devicePerst3Combo;};
	case "peq_2":{["interface",0,"k"] call gjb_itn_fnc_devicePeq2;};
	case "peq_2_combo":{["interface",0,"k"] call gjb_itn_fnc_devicePeq2Combo;};
	case "dbal_pl":{["interface",0,"k"] call gjb_itn_fnc_deviceDbalPl;};
	case "gtl_21":{["interface",0,"k"] call gjb_itn_fnc_deviceGTL21;};
	case "mk23":{["interface",0,"k"] call gjb_itn_fnc_deviceMk23;};
	case "llm_01":{["interface",0,"k"] call gjb_itn_fnc_deviceLLM01;};
	case "llm_mk3":{["interface",0,"k"]  call gjb_itn_fnc_deviceLLMmk3;};
	case "la_5b":{["interface",0,"k"] call gjb_itn_fnc_deviceLA5B;};
	case "la_5b_combo":{["interface",0,"k"] call gjb_itn_fnc_deviceLA5BCombo;};
	case "ngal":{["interface",0,"k"] call gjb_itn_fnc_deviceNGAL;};
	case "ngal_combo":{["interface",0,"k"] call gjb_itn_fnc_deviceNGALCombo;};
	//case "la_5b_combo_vis":{["interface",0,"k"] call gjb_itn_fnc_deviceLA5BComboVis;};
	default {
		createDialog "Rsc_gjb_itn_generic_deviceclass";
		_unit setVariable ["gjb_itn_genDevListLatch",0];
		//pop listbox
		private _display = findDisplay 314000;
		private _idB = _display displayCtrl 1000;
		private _bottomStop = getArray (_deviceCfg >> "gjb_itn_controls") #1 #1;
		private _modes = getArray (_deviceCfg >> "gjb_itn_deviceModes");
		//Remove OFF mode if in Simplified Controls
		if(_simpleCtrl == true && _offMode != -1)then{
			_modes deleteAt _offMode;
		};
		//Remove odd modes
		if(_bottomStop > 0)then{
			//_bottomStop = _bottomStop -1;
			_modes deleteRange [0,_bottomStop];
			_mode = _mode - _bottomStop;
		};
		{
			private _modeName = _x #3;
		//	if(_simpleCtrl == false || _modeName != "OFF")then{
				_idB lbAdd _modeName;
			//};
		} forEach _modes;
		if(_simpleCtrl == true && _mode > (_offMode - _bottomStop))then{
			_idB lbSetCurSel (_mode -1);
		}else{
			_idB lbSetCurSel _mode;
		};

		//Set illuminator controls
		private _canFoc = 0;
		private _canDif = 0;
		private _maxBeam = 10;
		private _ctrls = getArray (_deviceCfg >> "gjb_itn_controls");
		if((count _ctrls) > 2)then{
			private _illumCtrls = _ctrls #2;
			_canFoc = _illumCtrls #0;
			_canDif = _illumCtrls #1;
			if((count _illumCtrls) > 2)then{
				_maxBeam = _illumCtrls #2;
			};
		};
		private _illumMode = _deviceState #2;
		private _wButton = (findDisplay 314000) displayCtrl 1001;
		private _tButton = (findDisplay 314000) displayCtrl 1002;
		if(_canFoc == 1)then{
			private _maxModeB = 1.000 + (_maxBeam / 1000);
			private _maxModeD = 1.100 + (_maxBeam / 1000);
			switch(_illumMode)do{
				case 0;
				case 1;
				case -1;
				case _maxModeB;
				case -_maxModeB;
				case _maxModeD;
				case -_maxModeD: {
					_wButton ctrlSetTextColor [0.2,0.2,0.2,1];
				};
			};
			switch(true)do{
				case (_illumMode > 1 && _illumMode < 1.002);
				case (_illumMode > 1.1 && _illumMode < 1.102);
				case (_illumMode < -1 && _illumMode > -1.002);
				case (_illumMode < -1.1 && _illumMode > -1.102): {
					_tButton ctrlSetTextColor [0.2,0.2,0.2,1];
				};
			};
		}else{
			_tButton ctrlSetTextColor [0.2,0.2,0.2,1];
			_wButton ctrlSetTextColor [0.2,0.2,0.2,1];
		};
			//Diffusor button
		private _difButton = (findDisplay 314000) displayCtrl 1003;
		switch(true)do{
			case (_canDif == 1 && (_illumMode <= -1.1 || _illumMode >= 1.1)): {
				_difButton ctrlSetTextColor [1,0.8,0.2,1];
			};
			case (_canDif == 1 && (_illumMode > -1.1 && _illumMode < 1.1)): {};
			default {
				_difButton ctrlEnable false;
				_difButton ctrlSetTextColor [0.2,0.2,0.2,1];
			};
		};
		
		//Set fire button text color for OnIndic
		private _onButton = (findDisplay 314000) displayCtrl 989;
		if(_isOn > 0)then{
			_onButton ctrlSetTextColor [1,0.8,0.2,1];
		};
	};
};