#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_deviceLLMmk3
//
//	Takes input from Interface and controls general and unique device features for the LLM Mk3 VarioRay
//
//		Device specific features:
//				Selective component activation buttons, knob selects keybind activation mode
//				Holding buttons cycles power levels per component
//
//*****************************************************************************//

params ["_ctrl","_input","_type"];

private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];

//Ensures device is defaulted if first activation
if(!(_deviceState isEqualType []))then{
	_deviceState = [_unit] call gjb_itn_fnc_initMode;
};

private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];
private _genericInterface = missionNamespace getVariable ["gjb_itn_setting_genericInterface",false];
private _autoOnMode = -1;
private _powerLevel = _unit getVariable ["gjb_itn_llm3pwr",[1,1,1,false]];
private _knobSaver = _unit getVariable ["gjb_itn_llm3knob",[3,33,false,false]]; // Carries 1) Knob Mode from interface and 2) Device Mode from keys 3) press state for FB 4)if DIFF before 2xPress
private _stateSaver = _unit getVariable ["gjb_itn_llm3state",[false,false,false]];	//las, illum, flash

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
private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> _device;
private _deviceCtrls = getArray (_deviceCfg >> "gjb_itn_controls");
private _interfaceCfg = getArray (_deviceCfg >> "gjb_itn_interface");
private _interface = _interfaceCfg #1;
private _base = _interfaceCfg #2;

private _deviceModes = getArray (_deviceCfg >> "gjb_itn_deviceModes");
private _deviceModeNames = [];
{
	private _name = _x #3;
	_deviceModeNames pushBack _name;
} forEach _deviceModes;


//Functions
		//internal functions
		_mode2Knob  = {		// returns [_knob,_knobSaver,_powerLevel]
			//convert deviceMode into knobState
			private _knobOps = ["VD_co.paa","VL_co.paa","VA_co.paa","OFF_co.paa","IA_co.paa","IL_co.paa","ID_co.paa"];

			private _mode = _deviceState #4;
			if(_ctrl == "keys")then{
				_mode = _knobSaver #1;
			};
			private _knobPos = _knobSaver #0;
			switch(_mode)do{
				case 0:{	//IR Marker 1 + Lamp 1
					_powerLevel set [0,1];
					_powerLevel set [2,1];
					_knobPos = 4;
					_stateSaver = [true,false,true];
				};
				case 1:{	//IR Marker 2 + Lamp 1
					_powerLevel set [0,2];
					_powerLevel set [2,1];
					_knobPos = 4;
					_stateSaver = [true,false,true];
				};
				case 2:{	//IR Marker 3 + Lamp 1
					_powerLevel set [0,3];
					_powerLevel set [2,1];
					_knobPos = 4;
					_stateSaver = [true,false,true];
				};
				case 3:{	//IR Marker 1 + Lamp 2
					_powerLevel set [0,1];
					_powerLevel set [2,2];
					_knobPos = 4;
					_stateSaver = [true,false,true];
				};
				case 4:{		//IR Marker 2 + Lamp 2
					_powerLevel set [0,2];
					_powerLevel set [2,2];
					_knobPos = 4;
					_stateSaver = [true,false,true];
				};
				case 5:{	//IR Marker 3 + Lamp 2
					_powerLevel set [0,3];
					_powerLevel set [2,2];
					_knobPos = 4;
					_stateSaver = [true,false,true];
				};
				case 6:{	//IR Illuminator 1 + Lamp 1
					_powerLevel set [1,1];
					_powerLevel set [2,1];
					_knobPos = 5;
					_stateSaver = [false,true,true];
				};
				case 7:{	//IR Illuminator 2 + Lamp 1
					_powerLevel set [1,2];
					_powerLevel set [2,1];
					_knobPos = 5;
					_stateSaver = [false,true,true];
				};
				case 8:{	//IR Illuminator 1 + Lamp 2
					_powerLevel set [1,1];
					_powerLevel set [2,2];
					_knobPos = 5;
					_stateSaver = [false,true,true];
				};
				case 9:{	//IR Illuminator 2 + Lamp 2
					_powerLevel set [1,2];
					_powerLevel set [2,2];
					_knobPos = 5;
					_stateSaver = [false,true,true];
				};
				case 10:{	//IR Marker 1 + Illuminator 1 + Lamp 1
					_powerLevel set [0,1];
					_powerLevel set [1,1];
					_powerLevel set [2,1];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 11:{	//IR Marker 2 + Illuminator 1 + Lamp 1
					_powerLevel set [0,2];
					_powerLevel set [1,1];
					_powerLevel set [2,1];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 12:{	//IR Marker 3 + Illuminator 1 + Lamp 1
					_powerLevel set [0,3];
					_powerLevel set [1,1];
					_powerLevel set [2,1];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 13:{	//IR Marker 1 + Illuminator 2 + Lamp 1
					_powerLevel set [0,1];
					_powerLevel set [1,2];
					_powerLevel set [2,1];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 14:{	//IR Marker 2 + Illuminator 2 + Lamp 1
					_powerLevel set [0,2];
					_powerLevel set [1,2];
					_powerLevel set [2,1];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 15:{	//IR Marker 3 + Illuminator 2 + Lamp 1
					_powerLevel set [0,3];
					_powerLevel set [1,2];
					_powerLevel set [2,1];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 16:{	//IR Marker 1 + Illuminator 1 + Lamp 2
					_powerLevel set [0,1];
					_powerLevel set [1,1];
					_powerLevel set [2,2];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 17:{	//IR Marker 2 + Illuminator 1 + Lamp 2
					_powerLevel set [0,2];
					_powerLevel set [1,1];
					_powerLevel set [2,2];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 18:{	//IR Marker 3 + Illuminator 1 + Lamp 2
					_powerLevel set [0,3];
					_powerLevel set [1,1];
					_powerLevel set [2,2];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 19:{	//IR Marker 1 + Illuminator 2 + Lamp 2
					_powerLevel set [0,1];
					_powerLevel set [1,2];
					_powerLevel set [2,2];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 20:{	//IR Marker 2 + Illuminator 2 + Lamp 2
					_powerLevel set [0,2];
					_powerLevel set [1,2];
					_powerLevel set [2,2];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				case 21:{	//IR Marker 3 + Illuminator 2 + Lamp 2
					_powerLevel set [0,3];
					_powerLevel set [1,2];
					_powerLevel set [2,2];
					_knobPos = 6;
					_stateSaver = [true,true,true];
				};
				//
				case 22:{	//VIS Marker 3 + Lamp 2
					_powerLevel set [0,3];
					_powerLevel set [2,2];
					_knobPos = 0;
					_stateSaver = [true,false,true];
				};
				case 23:{	//VIS Marker 2 + Lamp 2
					_powerLevel set [0,2];
					_powerLevel set [2,2];
					_knobPos = 0;
					_stateSaver = [true,false,true];
				};
				case 24:{	//VIS Marker 1 + Lamp 2
					_powerLevel set [0,1];
					_powerLevel set [2,2];
					_knobPos = 0;
					_stateSaver = [true,false,true];
				};
				case 25:{	//VIS Marker 3 + Lamp 1
					_powerLevel set [0,3];
					_powerLevel set [2,1];
					_knobPos = 0;
					_stateSaver = [true,false,true];
				};
				case 26:{	//VIS Marker 2 + Lamp 1
					_powerLevel set [0,2];
					_powerLevel set [2,1];
					_knobPos = 0;
					_stateSaver = [true,false,true];
				};
				case 27:{	//VIS Marker 1 + Lamp 1
					_powerLevel set [0,1];
					_powerLevel set [2,1];
					_knobPos = 0;
					_stateSaver = [true,false,true];
				};
				case 28:{	//VIS Lamp 2
					_powerLevel set [2,2];
					_knobPos = 1;
					_stateSaver = [false,false,true];
				};
				case 29:{	//VIS Lamp 1
					_powerLevel set [2,1];
					_knobPos = 1;
					_stateSaver = [false,false,true];
				};
				case 30:{	//VIS Marker 3
					_powerLevel set [0,3];
					_knobPos = 2;
					_stateSaver = [true,false,false];
				};
				case 31:{	//VIS Marker 2
					_powerLevel set [0,2];
					_knobPos = 2;
					_stateSaver = [true,false,false];
				};
				case 32:{	//VIS Marker 1
					_powerLevel set [0,1];
					_knobPos = 2;
					_stateSaver = [true,false,false];
				};
				case 33:{	//OFF
					_knobPos = 3;
					_stateSaver = [false,false,false];
				};
				case 34:{	//IR Marker 1
					_powerLevel set [0,1];
					_knobPos = 4;
					_stateSaver = [true,false,false];
				};
				case 35:{	//IR Marker 2
					_powerLevel set [0,2];
					_knobPos = 4;
					_stateSaver = [true,false,false];
				};
				case 36:{	//IR Marker 3
					_powerLevel set [0,3];
					_knobPos = 4;
					_stateSaver = [true,false,false];
				};
				case 37:{	//IR Illuminator 1
					_powerLevel set [1,1];
					_knobPos = 5;
					_stateSaver = [false,true,false];
				};
				case 38:{	//IR Illuminator 2
					_powerLevel set [1,2];
					_knobPos = 5;
					_stateSaver = [false,true,false];
				};
				case 39:{	//IR Marker 1 + Illuminator 1
					_powerLevel set [0,1];
					_powerLevel set [1,1];
					_knobPos = 6;
					_stateSaver = [true,true,false];
				};
				case 40:{	//IR Marker 2 + Illuminator 1
					_powerLevel set [0,2];
					_powerLevel set [1,1];
					_knobPos = 6;
					_stateSaver = [true,true,false];
				};
				case 41:{	//IR Marker 3 + Illuminator 1
					_powerLevel set [0,3];
					_powerLevel set [1,1];
					_knobPos = 6;
					_stateSaver = [true,true,false];
				};
				case 42:{	//IR Marker 1 + Illuminator 2
					_powerLevel set [0,1];
					_powerLevel set [1,2];
					_knobPos = 6;
					_stateSaver = [true,true,false];
				};
				case 43:{	//IR Marker 2 + Illuminator 2
					_powerLevel set [0,2];
					_powerLevel set [1,2];
					_knobPos = 6;
					_stateSaver = [true,true,false];
				};
				case 44:{	//IR Marker 3 + Illuminator 2
					_powerLevel set [0,3];
					_powerLevel set [1,2];
					_knobPos = 6;
					_stateSaver = [true,true,false];
				};
				default {};
			};

			_unit setVariable ["gjb_itn_llm3state",_stateSaver];

			private _file = _knobOps #_knobPos;

			//combine into full file path
			private _knob =  [_base,"\",_file] joinString "";

			_knobSaver set [0,_knobPos];

			[_knob,_knobSaver,_powerLevel];
		};
		_knob2mode = {		// returns _mode
			params ["_knob"];
			private _newMode = 0;
			switch(true)do{
				case (_knob == 0 && _powerLevel #0 == 3 && _powerLevel #2 == 2):{	//VIS Marker 3 + Lamp 2
					_newMode = 22;
				};
				case (_knob == 0 && _powerLevel #0 == 2 && _powerLevel #2 == 2):{	//VIS Marker 2 + Lamp 2
					_newMode = 23;
				};
				case (_knob == 0 && _powerLevel #0 == 1 && _powerLevel #2 == 2):{	//VIS Marker 1 + Lamp 2
					_newMode = 24;
				};
				case (_knob == 0 && _powerLevel #0 == 3 && _powerLevel #2 == 1):{	//VIS Marker 3 + Lamp 1
					_newMode = 25;
				};
				case (_knob == 0 && _powerLevel #0 == 2 && _powerLevel #2 == 1):{	//VIS Marker 2 + Lamp 1
					_newMode = 26;
				};
				case (_knob == 0 && _powerLevel #0 == 1 && _powerLevel #2 == 1): {	//VIS Marker 1 + Lamp 1
					_newMode = 27;
				};
				case (_knob == 1 && _powerLevel #2 == 2):{	//VIS Lamp 2
					_newMode = 28;
				};
				case (_knob == 1 && _powerLevel #2 == 1):{	//VIS Lamp 1
					_newMode = 29;
				};
				case (_knob == 2 && _powerLevel #0 == 3):{	//VIS Marker 3
					_newMode = 30;
				};
				case (_knob == 2 && _powerLevel #0 == 2):{	//VIS Marker 2
					_newMode = 31;
				};
				case (_knob == 2 && _powerLevel #0 == 1):{	//VIS Marker 1
					_newMode = 32;
				};
				case (_knob == 3):{	//OFF
					_newMode = 33;
				};
				case (_knob == 4 && _powerLevel #0 == 1):{	//IR Marker 1
					_newMode = 34;
				};
				case (_knob == 4 && _powerLevel #0 == 2):{	//IR Marker 2
					_newMode = 35;
				};
				case (_knob == 4 && _powerLevel #0 == 3):{	//IR Marker 3
					_newMode = 36;
				};
				case (_knob == 5&& _powerLevel #1 == 1):{	//IR Illuminator 1
					_newMode = 37;
				};
				case (_knob == 5 && _powerLevel #1 == 2):{	//IR Illuminator 2
					_newMode = 38;
				};
				case (_knob == 6 && _powerLevel #0 == 1 && _powerLevel #1 == 1):{	//IR Marker 1 + Illuminator 1
					_newMode = 39;
				};
				case (_knob == 6 && _powerLevel #0 == 2 && _powerLevel #1 == 1):{	//IR Marker 2 + Illuminator 1
					_newMode = 40;
				};
				case (_knob == 6 && _powerLevel #0 == 3 && _powerLevel #1 == 1):{	//IR Marker 3 + Illuminator 1
					_newMode = 41;
				};
				case (_knob == 6 && _powerLevel #0 == 1 && _powerLevel #1 == 2):{	//IR Marker 1 + Illuminator 2
					_newMode = 42;
				};
				case (_knob == 6 && _powerLevel #0 == 2 && _powerLevel #1 == 2):{	//IR Marker 2 + Illuminator 2
					_newMode = 43;
				};
				case (_knob == 6 && _powerLevel #0 == 3 && _powerLevel #1 == 2):{	//IR Marker 3 + Illuminator 2
					_newMode = 44;
				};
			};
			_newMode;
		};
			//figure this out.... ugh
			//"Current mode"(real/buttons) and "Tail-switch mode"(key) indicators
			//Update doubletap depending switch mode...
		_initToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrl = _disp displayCtrl 1060;
			private _modeSw = _ctrl controlsGroupCtrl 1100;
			private _pwrbt = _ctrl controlsGroupCtrl 1101;
			private _illum = _ctrl controlsGroupCtrl 1110;
			private _curMode =  localize "STR_GJB_ITN_CORE_CURMODE";
			//prep mode tip
			private _modeLas = _deviceModeNames #_mode;
			_modeLas = _curMode + _modeLas;
			private _modeStr = localize "STR_GJB_ITN_CORE_DEVMODE" + _modeLas;
			switch(_tipMode)do{
				case 0: {
					private _keysVerb = localize "STR_GJB_ITN_CORE_MODEKEY";
					_modeStr = _modeStr + _keysVerb;
					_modeSw ctrlSetTooltip _modeStr;
					private _pwrbtKeys = localize "STR_GJB_ITN_CORE_PWRKEYB";
					_pwrbt ctrlSetTooltip (localize "STR_GJB_ITN_CORE_PEQ15PWR" + _pwrbtKeys);
					private _illumKeys = localize "STR_GJB_ITN_CORE_IRDFKEY" + localize "STR_GJB_ITN_CORE_IRFOKEY";
					_illum ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVIRDFFO" + _illumKeys);
				};
				case 1: {
					_modeSw ctrlSetTooltip _modeStr;
					_pwrbt ctrlSetTooltip localize "STR_GJB_ITN_CORE_PEQ15PWR";
					_illum ctrlSetTooltip localize "STR_GJB_ITN_CORE_DEVIRDFFO";
				};
				case 2: {
					{
						_x ctrlSetTooltip "";
						_x ctrlSetTooltipColorBox [0,0,0,0];
						_x ctrlSetTooltipColorShade [0,0,0,0];
					} forEach [_modeSw,_pwrbt,_illum];
				};
			};
		};
		_changeToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrl = _disp displayCtrl 1060;
			private _modeSw = _ctrl controlsGroupCtrl 1100;
			private _curMode =  localize "STR_GJB_ITN_CORE_CURMODE";
			//prep mode tip
			private _modeLas = _deviceModeNames #_newKnob;
			_modeLas = _curMode + " " + _modeLas;
			private _modeStr = localize "STR_GJB_ITN_CORE_DEVMODE" + _modeLas;
			switch(_tipMode)do{
				case 0: {
					_modeStr = _modeStr + localize "STR_GJB_ITN_CORE_MODEKEY";
					_modeSw ctrlSetTooltip _modeStr;
				};
				case 1: {
					_modeSw ctrlSetTooltip _modeStr;
				};
			};
		};
		//interface controls
		_interfaceChangeMode = {
			//possible knob positions, from left to right and clockwise
			private _knob = ["VD_co.paa","VL_co.paa","VA_co.paa","OFF_co.paa","IA_co.paa","IL_co.paa","ID_co.paa"];
			private _count = (count _knob) -1;

			//Retrieve current knob state and hide knobs
				private _currentKnob = ctrlText 1001; 
				_currentKnob = _currentKnob splitString "\";
				private _countStr = (count _currentKnob)-1;
				_currentKnob = _knob find (_currentKnob #_countStr);

			//Adjust knob pos
			private _shortStop = false;
			private _newKnob = 0;
			switch(_input)do{
				case 0:{
					//next mode
					_newKnob = _currentKnob;
					if(_newKnob < _count)then{
						_newKnob = _newKnob +1;
						if(_newKnob == 3 && _simpleCtrl)then{
							_newKnob = _newKnob +1;
						};
					}else{
						_shortStop = true;
					};
				};
				case 1:{
					//previous mode
					_newKnob = _currentKnob;
					if(_newKnob > 0)then{
						_newKnob = _newKnob -1;
						if(_newKnob == 3 && _simpleCtrl)then{
							_newKnob = _newKnob -1;
						};
					}else{
						_shortStop = true;
					};
				};
			};

			//end script if knobs are at end of range
			if(_shortStop)exitWith{};

			//Turn off device if changing between vis/ir or set to OFF pos
			if(_deviceState #0 > 0 && _newKnob == 3)then{
				private _inverter = -(_deviceState #0);
				_deviceState set [0,_inverter];
			};

			playSound "click";

			private _newKnobNum = +_newKnob;

			_newKnob = _knob #_newKnob;
			_newKnob = [_base,"\",_newKnob] joinString "";
			ctrlSetText [1001,_newKnob];

			//get device mode
			_newMode = [_newKnobNum] call _knob2mode;

			if(_newMode == 33)then{
				_deviceState set [4,_newMode];
				_unit setVariable ["gjb_itn_llm3state",[false,false,false]];
			};

			//Make sure simple controls updates mode properly
			if(_simpleCtrl)then{
				_deviceState set [4,_newMode];
			};

			_knobSaver set [0,_newKnobNum];
			_knobSaver set [1,_newMode];
			_unit setVariable ["gjb_itn_llm3knob",_knobSaver];
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
			
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && _deviceState #4 != 33)then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
		};
		_interfacePower = {		//handles turning on various modes regardless of knob
			private _isOn = _deviceState #0;
			private _mode = _deviceState #4;
			private _off = _deviceCtrls #1 #0;
			if(_knobSaver #0 == 3)exitWith{};

			//FB2 functions like FB3 if knob is in VIS mode
			private _swapped = false;
			if(_knobSaver #0 < 3 && _button == 1)then{
				_button = 2;
				_swapped = true;
			};
			//Adjust states per button
			if(_stateSaver #_button)then{
				_stateSaver set [_button,false];
			}else{
				_stateSaver set [_button,true];
			};

			if(_swapped)then{
				_button = 1;
			};

			//determine appropriate mode for new state
			private _newMode = 33;
			private _isIR = _knobSaver #0 > 3;
			private _las = _stateSaver #0;
			private _illum = _stateSaver #1;
			private _flash = _stateSaver #2;
			private _lasP = _powerLevel #0;
			private _illumP = _powerLevel #1;
			private _flashP = _powerLevel #2; 
			switch(true)do{
				case (_las && !_illum && _flash && _isIR):{	//IR Marker + Lamp
					switch(true)do{
						case (_lasP == 1 && _flashP == 1):{
							_newMode = 0;
						};
						case (_lasP == 2 && _flashP == 1):{
							_newMode = 1;
						};
						case (_lasP == 3 && _flashP == 1):{
							_newMode = 2;
						};
						case (_lasP == 1 && _flashP == 2):{
							_newMode = 3;
						};
						case (_lasP == 2 && _flashP == 2):{
							_newMode = 4;
						};
						case (_lasP == 3 && _flashP == 2):{
							_newMode = 5;
						};
					};
				};
				case (!_las && _illum && _flash):{	//IR Illuminator + Lamp
					switch(true)do{
						case (_illumP == 1 && _flashP == 1):{
							_newMode = 6;
						};
						case (_illumP == 2 && _flashP == 1):{
							_newMode = 7;
						};
						case (_illumP == 1 && _flashP == 2):{
							_newMode = 8;
						};
						case (_illumP == 2 && _flashP == 2):{
							_newMode = 9;
						};
					};
				};
				case (_las && _illum && _flash):{	//IR Marker + Illuminator + Lamp
					switch(true)do{
						case (_lasP == 1 && _illumP == 1 && _flashP == 1):{
							_newMode = 10;
						};
						case (_lasP == 2 && _illumP == 1 && _flashP == 1):{
							_newMode = 11;
						};
						case (_lasP == 3 && _illumP == 1 && _flashP == 1):{
							_newMode = 12;
						};
						case (_lasP == 1 && _illumP == 2 && _flashP == 1):{
							_newMode = 13;
						};
						case (_lasP == 2 && _illumP == 2 && _flashP == 1):{
							_newMode = 14;
						};
						case (_lasP == 3 && _illumP == 2 && _flashP == 1):{
							_newMode = 15;
						};
						case (_lasP == 1 && _illumP == 1 && _flashP == 2):{
							_newMode = 16;
						};
						case (_lasP == 2 && _illumP == 1 && _flashP == 2):{
							_newMode = 17;
						};
						case (_lasP == 3 && _illumP == 1 && _flashP == 2):{
							_newMode = 18;
						};
						case (_lasP == 1 && _illumP == 2 && _flashP == 2):{
							_newMode = 19;
						};
						case (_lasP == 2 && _illumP == 2 && _flashP == 2):{
							_newMode = 20;
						};
						case (_lasP == 3 && _illumP == 2 && _flashP == 2):{
							_newMode = 21;
						};
					};
				};
				//
				case (_las && !_illum && _flash):{	//VIS Marker + Lamp
					switch(true)do{
						case (_lasP == 3 && _flashP == 2):{
							_newMode = 22;
						};
						case (_lasP == 2 && _flashP == 2):{
							_newMode = 23;
						};
						case (_lasP == 1 && _flashP == 2):{
							_newMode = 24;
						};
						case (_lasP == 3 && _flashP == 1):{
							_newMode = 25;
						};
						case (_lasP == 2 && _flashP == 1):{
							_newMode = 26;
						};
						case (_lasP == 1 && _flashP == 1):{
							_newMode = 27;
						};
					};
				};
				case (!_las && !_illum && _flash):{	//VIS Lamp
					switch(true)do{
						case (_flashP == 2):{
							_newMode = 28;
						};
						case (_flashP == 1):{
							_newMode = 29;
						};
					};
				};
				case (_las && !_illum && !_flash && !_isIR):{	//VIS Marker
					switch(true)do{
						case (_lasP == 3):{
							_newMode = 30;
						};
						case (_lasP == 2):{
							_newMode = 31;
						};
						case (_lasP == 1):{
							_newMode = 32;
						};
					};
				};
				case (!_las && !_illum && !_flash):{	//OFF
					_newMode = 33;
				};
				case (_las && !_illum && !_flash && _isIR):{	//IR Marker
					switch(true)do{
						case (_lasP == 1):{
							_newMode = 34;
						};
						case (_lasP == 2):{
							_newMode = 35;
						};
						case (_lasP == 3):{
							_newMode = 36;
						};
					};
				};
				case (!_las && _illum && !_flash):{	//IR Illuminator
					switch(true)do{
						case (_illumP == 1):{
							_newMode = 37;
						};
						case (_illumP == 2):{
							_newMode = 38;
						};
					};
				};
				case (_las && _illum && !_flash):{	//IR Marker + Illuminator
					switch(true)do{
						case (_lasP == 1 && _illumP == 1):{
							_newMode = 39;
						};
						case (_lasP == 2 && _illumP == 1):{
							_newMode = 40;
						};
						case (_lasP == 3 && _illumP == 1):{
							_newMode = 41;
						};
						case (_lasP == 1 && _illumP == 2):{
							_newMode = 42;
						};
						case (_lasP == 2 && _illumP == 2):{
							_newMode = 43;
						};
						case (_lasP == 3 && _illumP == 2):{
							_newMode = 44;
						};
					};
				};
			};
			
			_stateSaver = [_las,_illum,_flash];
			_unit setVariable ["gjb_itn_llm3state",_stateSaver];
			_deviceState set [4,_newMode];

			//turn off device if mode is off, otherwise ensure device is on
			if(_newMode == 33)then{
				_newMode = _mode;
				_deviceState set [0,0];
			}else{
				_deviceState set [0,1];
			};

			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && _deviceState #4 != 33)then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
			playSound "ClickSoft";
		};
		_contChange = {		// spawns script to cycle power level
			[_unit,_deviceState ,_powerLevel,_button,_knobSaver #0,_stateSaver] spawn {
				params ["_unit","_devStat","_pwrLvl","_btn","_knb","_stt"];
				_unit setVariable ["gjb_itn_llm3PwrCycle",[_thisScript,time]];
				sleep 0.2;
				_devStat set [0,1];
				_unit setVariable ["gjb_itn_deviceState",_devStat];
				if(_knb < 3 && _btn == 1)then{
					_btn = 2;
				};
				for "_i" from 1 to 99 do {
					private _lvl = _pwrLvl #_btn;
					switch(_btn)do{
						case 0:{
							switch(_lvl)do{
								case 0;
								case 1;
								case 2:{
									sleep 1;
									_lvl = _lvl +1;
								};
								case 3:{
									[_unit,_devStat] spawn {
										params ["_unit","_devStat"];
										sleep 0.3;
										_devStat set [0,0];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
										sleep 0.2;
										_devStat set [0,1];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
										sleep 0.3;
										_devStat set [0,0];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
										sleep 0.2; 
										_devStat set [0,1];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
									};
									sleep 1.5;
									_lvl = 1;
								};
							};
						};
						case 1;
						case 2:{
							switch(_lvl)do{
								case 0;
								case 1:{
									sleep 1;
									_lvl = _lvl +1;
								};
								case 2:{
									[_unit,_devStat] spawn {
										params ["_unit","_devStat"];
										sleep 0.3;
										_devStat set [0,0];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
										sleep 0.2;
										_devStat set [0,1];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
										sleep 0.3;
										_devStat set [0,0];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
										sleep 0.2; 
										_devStat set [0,1];
										_unit setVariable ["gjb_itn_deviceState",_devStat];
									};
									sleep 1.5;
									_lvl = 1;
								};
							};
						};
					};
					_pwrLvl set [_btn,_lvl];
					_pwrLvl set [3,true];
					_unit setVariable ["gjb_itn_llm3pwr",_pwrLvl];
				  
					_newMode = 33; 
					_isIR = _knb > 3; 
					_las = _stt #0; 
					_illum = _stt #1; 
					_flash = _stt #2; 
					_lasP = _pwrLvl #0; 
					_illumP = _pwrLvl #1; 
					_flashP = _pwrLvl #2; 
					switch(true)do{
						case (_las && !_illum && _flash && _isIR):{
							switch(true)do{
								case (_lasP == 1 && _flashP == 1):{
									_newMode = 0;
								};
								case (_lasP == 2 && _flashP == 1):{
									_newMode = 1;
								};
								case (_lasP == 3 && _flashP == 1):{
									_newMode = 2;
								};
								case (_lasP == 1 && _flashP == 2):{
									_newMode = 3;
								};
								case (_lasP == 2 && _flashP == 2):{
									_newMode = 4;
								};
								case (_lasP == 3 && _flashP == 2):{
									_newMode = 5;
								};
							};
						};
						case (!_las && _illum && _flash):{
							switch(true)do{
								case (_illumP == 1 && _flashP == 1):{
									_newMode = 6;
								};
								case (_illumP == 2 && _flashP == 1):{
									_newMode = 7;
								};
								case (_illumP == 1 && _flashP == 2):{
									_newMode = 8;
								};
								case (_illumP == 2 && _flashP == 2):{
									_newMode = 9;
								};
							};
						};
						case (_las && _illum && _flash):{
							switch(true)do{
								case (_lasP == 1 && _illumP == 1 && _flashP == 1):{
									_newMode = 10;
								};
								case (_lasP == 2 && _illumP == 1 && _flashP == 1):{
									_newMode = 11;
								};
								case (_lasP == 3 && _illumP == 1 && _flashP == 1):{
									_newMode = 12;
								};
								case (_lasP == 1 && _illumP == 2 && _flashP == 1):{
									_newMode = 13;
								};
								case (_lasP == 2 && _illumP == 2 && _flashP == 1):{
									_newMode = 14;
								};
								case (_lasP == 3 && _illumP == 2 && _flashP == 1):{
									_newMode = 15;
								};
								case (_lasP == 1 && _illumP == 1 && _flashP == 2):{
									_newMode = 16;
								};
								case (_lasP == 2 && _illumP == 1 && _flashP == 2):{
									_newMode = 17;
								};
								case (_lasP == 3 && _illumP == 1 && _flashP == 2):{
									_newMode = 18;
								};
								case (_lasP == 1 && _illumP == 2 && _flashP == 2):{
									_newMode = 19;
								};
								case (_lasP == 2 && _illumP == 2 && _flashP == 2):{
									_newMode = 20;
								};
								case (_lasP == 3 && _illumP == 2 && _flashP == 2):{
									_newMode = 21;
								};
							};
						};
						case (_las && !_illum && _flash):{
							switch(true)do{
								case (_lasP == 3 && _flashP == 2):{
									_newMode = 22;
								};
								case (_lasP == 2 && _flashP == 2):{
									_newMode = 23;
								};
								case (_lasP == 1 && _flashP == 2):{
									_newMode = 24;
								};
								case (_lasP == 3 && _flashP == 1):{
									_newMode = 25;
								};
								case (_lasP == 2 && _flashP == 1):{
									_newMode = 26;
								};
								case (_lasP == 1 && _flashP == 1):{
									_newMode = 27;
								};
							};
						};
						case (!_las && !_illum && _flash):{
							switch(true)do{
								case (_flashP == 2):{
									_newMode = 28;
								};
								case (_flashP == 1):{
									_newMode = 29;
								};
							};
						};
						case (_las && !_illum && !_flash && !_isIR):{
							switch(true)do{
								case (_lasP == 3):{
									_newMode = 30;
								};
								case (_lasP == 2):{
									_newMode = 31;
								};
								case (_lasP == 1):{
									_newMode = 32;
								};
							};
						};
						case (!_las && !_illum && !_flash):{
							_newMode = 33;
						};
						case (_las && !_illum && !_flash && _isIR):{
							switch(true)do{
								case (_lasP == 1):{
									_newMode = 34;
								};
								case (_lasP == 2):{
									_newMode = 35;
								};
								case (_lasP == 3):{
									_newMode = 36;
								};
							};
						};
						case (!_las && _illum && !_flash):{
							switch(true)do{
								case (_illumP == 1):{
									_newMode = 37;
								};
								case (_illumP == 2):{
									_newMode = 38;
								};
							};
						};
						case (_las && _illum && !_flash):{
							switch(true)do{
								case (_lasP == 1 && _illumP == 1):{
									_newMode = 39;
								};
								case (_lasP == 2 && _illumP == 1):{
									_newMode = 40;
								};
								case (_lasP == 3 && _illumP == 1):{
									_newMode = 41;
								};
								case (_lasP == 1 && _illumP == 2):{
									_newMode = 42;
								};
								case (_lasP == 2 && _illumP == 2):{
									_newMode = 43;
								};
								case (_lasP == 3 && _illumP == 2):{
									_newMode = 44;
								};
							};
						};
					};
					_devStat set [4,_newMode];
					[_unit,_devStat] call gjb_itn_fnc_modeSpec;
				};
			};
		};
		_illumFocus = {		// spawns script to cycle illuminator focus
			[_unit,_deviceState ] spawn {
				params ["_unit","_devStat"];
				_unit setVariable ["gjb_itn_llm3FcsCycle",[_thisScript,time]];
				sleep 0.2;
				_devStat set [0,1];
				_unit setVariable ["gjb_itn_deviceState",_devStat];
				for "_i" from 1 to 99 do {
					private _md = _devStat #2;
					switch(_md)do{
						case 1;
						case 1.009:{
							sleep 1;
							_md = 1.004;
						};
						case 1.004:{
							sleep 1;
							_md = 1.001;
						};
						case 1.001:{
							[_unit,_devStat] spawn {
								params ["_unit","_devStat"];
								sleep 0.3;
								_devStat set [0,0];
								_unit setVariable ["gjb_itn_deviceState",_devStat];
								sleep 0.2;
								_devStat set [0,1];
								_unit setVariable ["gjb_itn_deviceState",_devStat];
								sleep 0.3;
								_devStat set [0,0];
								_unit setVariable ["gjb_itn_deviceState",_devStat];
								sleep 0.2; 
								_devStat set [0,1];
								_unit setVariable ["gjb_itn_deviceState",_devStat];
							};
							sleep 1.5;
							_md = 1.109;
						};
						case 1.109:{
							sleep 1;
							_md = 1.009;
						};
					};
					_devStat set [2,_md];
					[_unit,_devStat] call gjb_itn_fnc_modeSpec;
				};
			};
		};
		//key controls
		_openInterface = {
			//create interface
			createDialog _interface;

			//convert mode to knob positions
			//private _knobs = call _mode2Knob;

			//set devices
			private _device = [_base,"base_co.paa"] joinString "\";

			ctrlSetText [1000,_device];

			//set knobs
			private _knobOps = ["VD_co.paa","VL_co.paa","VA_co.paa","OFF_co.paa","IA_co.paa","IL_co.paa","ID_co.paa"];
			private _file = _knobOps #(_knobSaver #0);
			private _knob =  [_base,"\",_file] joinString "";
			ctrlSetText [1001,_knob];

			//colorize if under NODs
				private _iddMain = getNumber (configFile >> _interface >> "idd");
				private _dis = findDisplay _iddMain;
			if(currentVisionMode player == 1)then{
				private _nvgColor = missionNamespace getVariable "gjb_itn_setting_nvgColor";
				switch(true)do{
					case (_nvgColor isEqualType []):{
						if(count _nvgColor < 4)then{
							_nvgColor = _nvgColor + [1];
						};
					};
					case (_nvgColor isEqualType ""): {
						_nvgColor = missionNamespace getVariable "gjb_itn_setting_nvgCustom";
						_nvgColor = _nvgColor + [1];
					};
				};
				{
					private _layer = _dis displayCtrl _x;
					_layer ctrlSetTextColor _nvgColor;
				} forEach [1000,1001,999];
			}else{
				private _lightV = getLightingAt player;
				_lightV = (_lightV #1  / 100) max (_lightV #3 / 150) + 0.05;
				if(_lightV < 1)then{
					private _dimmer = [_lightV,_lightV,_lightV,1];
					{
						private _layer = _dis displayCtrl _x;
						_layer ctrlSetTextColor _dimmer;
					} forEach [1000,1001];
				};
				private _indic = _dis displayCtrl 999;
				private _peq15Indic = [0.74,0,0,1];
				private _dbalIndic = [0.38,0.77,0,1];
				private _perstIndic = [0,0.48,0.9,1];
				_indic ctrlSetTextColor _peq15Indic; 
			};

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			private _isOn = false;
			if(_deviceState #0 > 0 && _deviceState #4 != 33)then{
				_isOn = true;
			};
			private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
			ctrlShow [_idOverlay,_overlay];
			ctrlShow [_idOnIndic,_isOn];

			//Hide auto-on menu
			private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");
			ctrlShow [_autoOnMenu,false];
		};
		_momentaryControl = { 
			private _mode = _knobSaver #1;
			private _off = _deviceCtrls #1 #0;
			if(_mode == _off)exitWith{};
			
			//propigate new power levels into momentary controls
			if(_powerLevel #3)then{
				_mode = [_knobSaver #0] call _knob2mode;
				_knobSaver set [1,_mode];
				_unit setVariable ["gjb_itn_llm3knob",_knobSaver];
				_powerLevel set [3,false];
				_unit setVariable ["gjb_itn_llm3pwr",_powerLevel];
			};

			private _state = _deviceState #0;
			private _time = time;
			private _sTime = _unit getVariable ["gjb_itn_dpTimer",0];
			private _isDP = 1;
			private _dpCount = _unit getVariable ["gjb_itn_dpCount",-1];

			switch(_input)do{
				case 0:{	//key-down is on, starts timer if using dual purpose keybind
					_sTime = +_time;
					_unit setVariable ["gjb_itn_dpTimer",_sTime];
					_unit setVariable ["gjb_itn_dpState",_state];
					
					//prep different behavior for single-tap and double-tap functions
					switch(_dpCount)do{
						case -1:{
							_unit setVariable ["gjb_itn_dpCount",1];
							//update mode if first on since GUI knob change
							private _deviceOffset = _unit getVariable ["gjb_itn_deviceOffset",0];
							if(_deviceState #4 != _mode || !(_deviceOffset isEqualType []))then{
								_deviceState set [4,_mode];
								[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
							};
						};
						case 1:{
							_unit setVariable ["gjb_itn_dpCount",2];

							//stop cleanup script
							private _dpKiller = _unit getVariable ["gjb_itn_dpKiller",0];
							if(!(_dpKiller isEqualType 0))then{
								terminate _dpKiller;
							};

							/*============================
							add in check for knob 0/6.
							Knob 6 doubles to WIDE Illum
							Knob 0 doubles to STROBE light, likely with light in bright mode
							============================*/

							//set dual mode (IR/VIS)
							if(_mode < 33)then{
								_mode = [0] call _knob2mode;
							}else{
								_mode = [6] call _knob2mode;
							};
							_deviceState set [4,_mode];

							// if already IR Dual, set Illum diffuse
							if(_knobSaver #0 == 6)then{
								_illumState = _deviceState #2;
								switch(_illumState)do{
									case -3;
									case -2;
									case -1:{
										_illumState = _illumState-10;
										_knobSaver set [3,false];
									};
									case 1;
									case 2;
									case 3:{
										_illumState = _illumState+10;
										_knobSaver set [3,false];
									};
									case -13;
									case -12;
									case -11;
									case 11;
									case 12;
									case 13:{
										_knobSaver set [3,true];
									};
								};
								_unit setVariable ["gjb_itn_llm3knob",_knobSaver];
								_deviceState set [2,_illumState];
							};

							[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
						};
						case 3:{
							//reset device mode to original mode
							_deviceState set [4,_mode];
							
							// if already IR Dual, reset Illum to prior focus
							if(_knobSaver #0 == 6)then{
								_illumState = _deviceState #2;
								switch(_illumState)do{
									case 11;
									case 12;
									case 13:{
										if(!(_knobSaver#3))then{
											_illumState = _illumState-10;
										};
									};
								};
								_deviceState set [2,_illumState];
							};
							
							[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
						};
					};

					//Turn on device if not already on
					if(_state == 0)then{
						_deviceState set [0,1];
					}else{
						if(_state < 0)then{
							private _invert = -(_state);
							_deviceState set [0,_invert];
						};
					};

					playSound "ClickSoft";
				};
				case 1:{	//key-up is off, adjusts behavior depending on time pressed if using dual purpose keybind
					_time = time;
					private _hold = _time - _sTime;
					switch(true)do{
						case (_dpCount == 1 && _hold <= 0.4):{	//1x tap
							//toggle device
							private _dpState = _unit getVariable ["gjb_itn_dpState",-1];
							if(_dpState > 0)then{
								private _invert = -(_state);
								_deviceState set [0,_invert];
								_unit setVariable ["gjb_itn_llm3state",[false,false,false]];
							}else{
								if(_state == 0)then{
									_deviceState set [0,1];
								}else{
									if(_state < 0)then{
										private _invert = -(_state);
										_deviceState set [0,_invert];
									};
								};

								//just to update stateSaver
								call _mode2Knob #2;
							};

							//prep cleanup script in case no second press
							private _dpKiller = [_unit, _sTime] spawn {
								params ["_unit","_sTime"];
								//_delay = 0.85 - (time -_sTime);
								sleep 0.6;
								_unit setVariable ["gjb_itn_dpTimer",nil];
								_unit setVariable ["gjb_itn_dpCount",nil];
								_unit setVariable ["gjb_itn_dpState",nil];
								_unit setVariable ["gjb_itn_dpKiller",nil];
							};
							_unit setVariable ["gjb_itn_dpKiller",_dpKiller];
						};
						case (_dpCount == 1 && _hold > 0.4):{	// 1x press + hold
							//turn off device
							if(_state > 0)then{
								private _invert = -(_state);
								_deviceState set [0,_invert];
							};
							
							//clean up variables
							_unit setVariable ["gjb_itn_dpTimer",nil];
							_unit setVariable ["gjb_itn_dpCount",nil];
							_unit setVariable ["gjb_itn_dpState",nil];

							//update state saver
							_unit setVariable ["gjb_itn_llm3state",[false,false,false]];
							
							playSound "ClickSoft";
						};
						case (_dpCount == 2 && _hold <= 0.8):{	// 2x tap
							//just to update stateSaver
							call _mode2Knob #2;
							
							//prep for resetting device on 2x tap's following tap toggle off
							_unit setVariable ["gjb_itn_dpCount",3];

							//clean up variables
							_unit setVariable ["gjb_itn_dpTimer",nil];
							_unit setVariable ["gjb_itn_dpState",nil];

							//ensure device is ON after 2x tap
							if(_state == 0)then{
								_deviceState set [0,1];
							}else{
								if(_state < 0)then{
									private _invert = -(_state);
									_deviceState set [0,_invert];
								}/*else{
									//or clean up and turn off in the case of weird presses
									private _invert = -(_state);
									_deviceState set [0,_invert];

									//reset device mode to original mode
									_deviceState set [4,_mode];
									[_unit,_deviceState] call gjb_itn_fnc_modeSpec;

									//clean up variables
									_unit setVariable ["gjb_itn_dpCount",nil];
								}*/;
							};
						};
						case (_dpCount == 2 && _hold > 0.8):{	// 2x press + hold
							//turn off device
							if(_state > 0)then{
								private _invert = -(_state);
								_deviceState set [0,_invert];
							};
							
							//reset device mode to original mode
							_deviceState set [4,_mode];

							// if already IR Dual, reset Illum to prior focus
							if(_knobSaver #0 == 6)then{
								_illumState = _deviceState #2;
								switch(_illumState)do{
									case 11;
									case 12;
									case 13:{
										if(!(_knobSaver#3))then{
											_illumState = _illumState-10;
										};
									};
								};
								_deviceState set [2,_illumState];
							};

							[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
							
							//clean up variables
							_unit setVariable ["gjb_itn_dpTimer",nil];
							_unit setVariable ["gjb_itn_dpCount",nil];
							_unit setVariable ["gjb_itn_dpState",nil];

							//update state saver
							_unit setVariable ["gjb_itn_llm3state",[false,false,false]];
							
							playSound "ClickSoft";
						};
						case (_dpCount == 3 && _hold isEqualType 0):{	// 1x tap after 2x tap
							//turn off device
							if(_state > 0)then{
								private _invert = -(_state);
								_deviceState set [0,_invert];
							};

							//clean up variables
							_unit setVariable ["gjb_itn_dpTimer",nil];
							_unit setVariable ["gjb_itn_dpCount",nil];
							_unit setVariable ["gjb_itn_dpState",nil];

							//update state saver
							_unit setVariable ["gjb_itn_llm3state",[false,false,false]];
							
							playSound "ClickSoft";
						};
					};
				};
			};
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && _deviceState #4 != 33)then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};
		_changeMode = {
			//get knobState
			private _knobs = call _mode2Knob;	//_knob2mode
			_knobToSave = _knobs #1;
			_knobToSave set [1,_deviceState #4];

			//change knobs to reflect mode
			ctrlSetText [1001,_knobs #0];
			_unit setVariable ["gjb_itn_llm3knob",_knobToSave];
			_unit setVariable ["gjb_itn_llm3pwr",_knobs #2];
		};

switch(_ctrl)do{
	case "keys":{
		[] call _momentaryControl;
	};
	case "fire1":{
		private _button = 0;
		switch(true)do{
			case (_input == 0 && _type == "bd"):{
				if(!(_stateSaver #0))then{
					_knobSaver set [2,true];
					_unit setVariable ["gjb_itn_llm3knob",_knobSaver];
					call _interfacePower;
				};
				call _contChange;
			};
			case (_input == 0 && _type == "bu"):{
				private _script = _unit getVariable ["gjb_itn_llm3PwrCycle",0];
				private _handle = _script #0;
				private _sTime = _script #1;
				if(!(_script isEqualType 0))then{
					terminate _handle;
					_unit setVariable ["gjb_itn_llm3PwrCycle",nil];
				};
				private _counter = time - _sTime;
				if(_stateSaver #0 && !(_knobSaver #2) && _counter < 0.2)then{
					call _interfacePower;
				};
				_knobSaver set [2,false];
				_unit setVariable ["gjb_itn_llm3knob",_knobSaver];
			};
			case (_input == 1 && _type == "bd"):{
				private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");			
				ctrlShow [_autoOnMenu,true];
				//Prep color change for active auto-mode button
				private _autoMode = player getVariable ["gjb_itn_autoOnMode",0];
				private _idcA = ["1051","1052","1053","1054","1055"];
				private _idc = _idcA deleteAt _autoMode;
				private _idd = str getNumber (configFile >> _interface >> "idd");
				private _iddX = allDisplays findIf {_idd in str _x}; 
				private _disp = allDisplays #_iddX;
				//Set active button orange
				private  _idcX = allControls _disp findIf { _idc in str _x};
				private _ctrl = allControls _disp #_idcX;
				_ctrl ctrlSetTextColor [1,0.56,0,0.8];
				//Set all inactive buttons white
				{
					private _idc2 = _x; 
					private  _idcX2 = allControls _disp findIf { _idc2 in str _x};
					private _ctrl2 = allControls _disp #_idcX2;
					_ctrl2 ctrlSetTextColor [1,1,1,0.8];
				} forEach _idcA;
				ctrlShow [1060,false];
			};
			case (_input == 1 && _type == "bu"):{
				private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");
				[_autoOnMenu] spawn {
					sleep 0.05;
					ctrlShow [_this #0,false];
					ctrlShow [1060,true];
				};
			};
		};
	};
	case "fire2":{
		private _button = 1;
		switch(_type)do{
			case "bd":{
				if(!(_stateSaver #1 || _stateSaver #2))then{
					_knobSaver set [2,true];
					_unit setVariable ["gjb_itn_llm3knob",_knobSaver];
					call _interfacePower;
				};
				switch(true)do{
					case (_input == 0 && _knobSaver #0 != 3):{
						call _contChange;
					};
					case (_input == 1 && _knobSaver #0 > 3):{
						call _illumFocus;
					};
				};
			};
			case "bu":{	
				private _script = 0;
				private _sTime = time -0.05;
				switch(true)do{
					case (_input == 0 && _knobSaver #0 != 3):{
						_script = _unit getVariable ["gjb_itn_llm3PwrCycle",0];
						_sTime = _script #1;
						if(!(_script isEqualType 0))then{
							private _handle = _script #0;
							terminate _handle;
							_unit setVariable ["gjb_itn_llm3PwrCycle",nil];
						};
					};
					case (_input == 1 && _knobSaver #0 > 3):{
						_script = _unit getVariable ["gjb_itn_llm3FcsCycle",0];
						_sTime = _script #1;
						if(!(_script isEqualType 0))then{
							private _handle = _script #0;
							terminate _handle;
							_unit setVariable ["gjb_itn_llm3FcsCycle",nil];
						};
					};
				};
				private _counter = time - _sTime;
				if((_stateSaver #1 || _stateSaver #2) && !(_knobSaver #2) && _counter < 0.2)then{
					call _interfacePower;
				};
				_knobSaver set [2,false];
				_unit setVariable ["gjb_itn_llm3knob",_knobSaver];
			}
		};
	};
	case "fire3":{
		private _button = 2;
		switch(true)do{
			case (_input == 0 && _type == "bd"):{
				call _interfacePower;
			};
			case (_input == 1):{
				call _autoOnMenu;
			};
		};
	};
	case "mode0":{
		call _changeMode;
	};
	case "mode1":{
		switch(true)do{
			case (_type == "w" && _input > 0): {
				_input = 0;
			};
			case (_type == "w" && _input < 0): {
				_input = 1;
			};
		};
		_ctrl = 0;
		call _interfaceChangeMode;
	};
	case "illum":{
		private _illumMode = _deviceState #2;
		switch(_input)do{
			case 0:{	//widen focus
				switch (_illumMode)do{
					case -1.109:{
						_illumMode = -1.001;
					};
					case -1.001:{
						_illumMode = -1.004;
					};
					case -1.004:{
						_illumMode = -1.009;
					};
					case -1.009;
					case -1;
					case 0:{
						_illumMode = -1.109;
					};
					case 1;
					case 1.009:{
						_illumMode = 1.109;
					};
					case 1.004:{
						_illumMode = 1.009;
					};
					case 1.001:{
						_illumMode = 1.004;
					};
					case 1.109:{
						_illumMode = 1.001;
					};
				};
			};
			case 1:{	//tighten focus
				switch (_illumMode)do{
					case -1.109:{
						_illumMode = -1.009;
					};
					case -1.001:{
						_illumMode = -1.109;
					};
					case -1.004:{
						_illumMode = -1.001;
					};
					case -1.009;
					case -1;
					case 0:{
						_illumMode = -1.004;
					};
					case 1;
					case 1.009:{
						_illumMode = 1.004;
					};
					case 1.004:{
						_illumMode = 1.001;
					};
					case 1.001:{
						_illumMode = 1.109;
					};
					case 1.109:{
						_illumMode = 1.009;
					};
				};
			};
		};
		_deviceState set [2,_illumMode];
		[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
	};
	case "interface":{
		[] call _openInterface;
	};
};