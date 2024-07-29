#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_devicePeq15Combo
//
//	Takes input from Interface and controls general and unique device features for the PEQ-15 laser
//	aiming device when combined with a flashlight.
//
//		Device specific features:
//				Constant-on lasts 5 minutes
//				Programmable pulse/strobe for laser mode
//				Patterned diffusors for the laser?
//				Flashlight modes
//				Flashlight and PEQ can be activated independent of each other
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
private _comboMode = _unit getVariable ["gjb_itn_deviceComboState",0];	//1 is standard/dual, 2 is PEQ only, 3 is light only

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

private _deviceModes = getArray (_deviceCfg >> "gjb_itn_deviceModes");
private _deviceModeNames = [];
{
	private _name = _x #3;
	_deviceModeNames pushBack _name;
} forEach _deviceModes;


//retrieve directory
private _base1 = _interfaceCfg #2;
private _base2 = _interfaceCfg #3;

//Functions
		//internal functions
		_mode2knob  = {
			//convert deviceMode into knobState
			private _mode = _deviceState #4;
			private _knobOps1 = ["VAL_co.paa","OFF_co.paa","AL_co.paa","DL_co.paa","AH_co.paa","IH_co.paa","DH_co.paa"];
			private _knobOps2 = ["VIS_co.paa","OFF_co.paa","IR_co.paa"];

			private _file1 = "";
			private _file2 = "";
			switch(_mode)do{
				case 0: {	//VIS AIM LO + IR Flash
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #2;
					_comboMode = 1;
				};
				case 1: {	//IR AIM LO + Vis Flash
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #0;
					_comboMode = 1;
				};
				case 2: {	//IR DUAL LO + Vis Flash
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #0;
					_comboMode = 1;
				};
				case 3: {	//IR AIM HI + Vis Flash
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #0;
					_comboMode = 1;
				};
				case 4: {	//IR ILLUM HI + Vis Flash
					_file1 = _knobOps1 #5;
					_file2 = _knobOps2 #0;
					_comboMode = 1;
				};
				case 5: {	//IR DUAL HI + Vis Flash
					_file1 = _knobOps1 #6;
					_file2 = _knobOps2 #0;
					_comboMode = 1;
				};
				case 6: {	//VIS Flash
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #0;
					_comboMode = 3;
				};
				case 7: {	//VIS AIM + Flash
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #0;
					_comboMode = 1;
				};
				case 8:{	//VIS AIM LO
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #1;
					_comboMode = 2;
				};
				case 9:{	//OFF
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #1;
					_comboMode = 0;
				};
				case 10:{	//IR Flash
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #2;
					_comboMode = 3;
				};
				case 11:{	//IR AIM LO
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #1;
					_comboMode = 2;
				};
				case 12:{	//IR AIM LO + Flash
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #2;
					_comboMode = 1;
				};
				case 13:{	//IR DUAL LO
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #1;
					_comboMode = 2;
				};
				case 14:{	//IR DUAL LO + Flash
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #2;
					_comboMode = 1;
				};
				case 15:{	//IR AIM HI
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #1;
					_comboMode = 2;
				};
				case 16:{	//IR AIM HI + Flash
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #2;
					_comboMode = 1;
				};
				case 17:{	//IR ILLUM HI
					_file1 = _knobOps1 #5;
					_file2 = _knobOps2 #1;
					_comboMode = 2;
				};
				case 18:{	//IR ILLUM HI + Flash
					_file1 = _knobOps1 #5;
					_file2 = _knobOps2 #2;
					_comboMode = 1;
				};
				case 19:{	//IR DUAL HI
					_file1 = _knobOps1 #6;
					_file2 = _knobOps2 #1;
					_comboMode = 2;
				};
				case 20:{	//IR DUAL HI + Flash
					_file1 = _knobOps1 #6;
					_file2 = _knobOps2 #2;
					_comboMode = 1;
				};
			};

			//combine into full file path
			private _knob1 =  [_base1,"\",_file1] joinString "";
			private _knob2 = "";
			if(_file2 != "")then{
				_knob2 = [_base2,"\",_file2] joinString "";
			};

			[_knob1,_knob2];
		};
		_initToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrlId = _disp displayCtrl 1060;
			private _modeSw = _ctrlId controlsGroupCtrl 1100;
			private _pwrbt = _ctrlId controlsGroupCtrl 1101;
			private _illum = _ctrlId controlsGroupCtrl 1110;
			private _modeFl= _ctrlId controlsGroupCtrl 1120;
			private _pwrbtFl = _ctrlId controlsGroupCtrl 1121;
			private _curMode =  localize "STR_GJB_ITN_CORE_CURMODE";
			//prep mode tip
				//laser mode
				private _mode = _deviceState #4;
				private _modeLas = _deviceModeNames #_mode;
				_modeLas = _modeLas splitString "+";
				_modeLas = _modeLas #0;
				if(((_knobs #0) splitString "\") #-1 == "OFF_co.paa")then{
					_modeLas = "OFF";
				};
				_modeLas = _curMode + " " + _modeLas;
				private _modeStr = localize "STR_GJB_ITN_CORE_DEVMODE" + _modeLas;
				//flashlight mode
				private _knobFl = _knobs #1;
				_knobFl = _knobFl splitString "\";
				_knobFl = ["VIS_co.paa","OFF_co.paa","IR_co.paa"] find (_knobFl #-1);
				_knobFl = ["VIS","OFF","IR"] #_knobFl;
				_knobFl = _curMode + " " + _knobFl;
				private _flString = localize "STR_GJB_ITN_CORE_DEVMODEALT" + _knobFl;
				switch(_tipMode)do{
					case 0: {
						private _keysVerb = localize "STR_GJB_ITN_CORE_MODEKEY";
						_modeStr = _modeStr + _keysVerb;
						_modeSw ctrlSetTooltip _modeStr;
						private _keysVerbAlt = localize "STR_GJB_ITN_CORE_FLMODEKEYALT";
						_flString = _flString + _keysVerbAlt;
						_modeFl ctrlSetTooltip _flString;
						private _pwrbtKeys = localize "STR_GJB_ITN_CORE_PWRKEYB";
						_pwrbt ctrlSetTooltip (localize "STR_GJB_ITN_CORE_PEQ15PWR" + _pwrbtKeys);
						private _illumKeys = localize "STR_GJB_ITN_CORE_IRDFKEY" + localize "STR_GJB_ITN_CORE_IRFOKEY";
						_illum ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVIRDFFO" + _illumKeys);
						private _pwrbtKeysAlt = localize "STR_GJB_ITN_CORE_PWRKEYC";
						_pwrbtFl ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVPWR" + _pwrbtKeysAlt);
					};
					case 1: {
						_modeSw ctrlSetTooltip _modeStr;
						_pwrbt ctrlSetTooltip localize "STR_GJB_ITN_CORE_PEQ15PWR";
						_illum ctrlSetTooltip localize "STR_GJB_ITN_CORE_DEVIRDFFO";
						_modeFl ctrlSetTooltip _flString;
						_pwrbtFl ctrlSetTooltip localize "STR_GJB_ITN_CORE_DEVPWR";
					};
					case 2: {
						{
							_x ctrlSetTooltip "";
							_x ctrlSetTooltipColorBox [0,0,0,0];
							_x ctrlSetTooltipColorShade [0,0,0,0];
						} forEach [_modeSw,_pwrbt,_illum,_modeFl,_pwrbtFl];
					};
				};
		};
		_changeToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrlId = _disp displayCtrl 1060;
			private _modeSw = _ctrlId controlsGroupCtrl 1100;
			private _modeFl= _ctrlId controlsGroupCtrl 1120;
			private _curMode =  localize "STR_GJB_ITN_CORE_CURMODE";
			//prep mode tip
			switch(true)do{
				case (_tipMode != 2 &&_type == "k"): {
					private _mode = _deviceState #4;
					private _modeLas = _deviceModeNames #_mode;
					//private _modeLas = _knobs #0 splitString "\";
					_modeLas = _modeLas splitString "+";
					_modeLas = _modeLas #0;
					if(((_knobs #0) splitString "\") #-1 == "OFF_co.paa")then{
						_modeLas = "OFF";
					};
					_modeLas = _curMode + " " + _modeLas;
					private _modeType = localize "STR_GJB_ITN_CORE_DEVMODE";
					private _modeKey = localize "STR_GJB_ITN_CORE_MODEKEY";
					private _modeFlash =  _knobs #1 splitString "\";
					_modeFlash = ["VIS_co.paa","OFF_co.paa","IR_co.paa"] find (_modeFlash #-1);
					_modeFlash = ["VIS","OFF","IR"] #_modeFlash;
					_modeFlash = _curMode + " " + _modeFlash;
					private _modeTypeFl = localize "STR_GJB_ITN_CORE_DEVMODEALT";
					private _modeKeyFl= localize "STR_GJB_ITN_CORE_MODEKEY";
					private _modeStr = _modeType + _modeLas;
					private _flashStr = _modeTypeFl + _modeFlash;
					if(_tipMode == 0)then{
						_modeStr = _modeStr + _modeKey;
						_flashStr = _flashStr + _modeKeyFl;
					};
					_modeSw ctrlSetTooltip _modeStr;
					_modeFl ctrlSetTooltip _flashStr;
				};
				case (_tipMode != 2 && _type != "k"): {
					private _modeType = localize "STR_GJB_ITN_CORE_DEVMODE";
					private _modeKey = localize "STR_GJB_ITN_CORE_MODEKEY";
					private _modeLas = _deviceModeNames #_newMode;
					if(_ctrl == 1)then{
						//_modeLas = _knobs #1;
						_modeLas = _newKnob splitString "\";
						_modeLas = ["VIS_co.paa","OFF_co.paa","IR_co.paa"] find (_modeLas #-1);
						_modeLas = ["VIS","OFF","IR"] #_modeLas;
						_modeSw = _modeFl;
						_modeLas = _curMode + " " + _modeLas;
						_modeType = localize "STR_GJB_ITN_CORE_DEVMODEALT";
						//_modeKey = localize "STR_GJB_ITN_CORE_FLMODEKEYALT";
					}else{
						_modeLas = _modeLas splitString "+";
						_modeLas = _modeLas #0;
						if((_newKnob splitString "\") #-1 == "OFF_co.paa")then{
							_modeLas = "OFF";
						};
						_modeLas = _curMode + " " + _modeLas;
					};
					private _modeStr = _modeType + _modeLas;
					if(_tipMode == 0)then{
						_modeStr = _modeStr + _modeKey;
					};
					_modeSw ctrlSetTooltip _modeStr;
				};
			};
		};
		//interface controls
		_interfaceChangeMode = {
			//possible knob positions, from left to right and clockwise
			private _knob1 = ["VAL_co.paa","OFF_co.paa","AL_co.paa","DL_co.paa","AH_co.paa","IH_co.paa","DH_co.paa"];
			private _count1 = (count _knob1) -1;
			private _knob2 = ["VIS_co.paa","OFF_co.paa","IR_co.paa"];
			private _count2 = (count _knob2) -1;

			//Retrieve current knob state and hide knobs
				//laser device
				private _currentKnob1 = ctrlText 1001; 
				_currentKnob1 = _currentKnob1 splitString "\";
				private _countStr = (count _currentKnob1)-1;
				_currentKnob1 = _knob1 find (_currentKnob1 #_countStr);
				//flashlight
				private _currentKnob2 = ctrlText 1002; 
				if(_currentKnob2 != "")then{
					_currentKnob2 = _currentKnob2 splitString "\";
					_countStr = (count _currentKnob2)-1;
					_currentKnob2 = _currentKnob2 #_countStr;
				};
				_currentKnob2 = _knob2 find (_currentKnob2);

			private _knobs = [_currentKnob1,_currentKnob2];
			private _counts = [_count1,_count2];

			//Invert keypresses for flashlight rings as needed (standardized LMB _> turn right/CW)
			if(_button == 2)then{
				if(_input == 0)then{
					_input = 1;
				}else{
					_input = 0;
				};	
			};

			//Adjust knob pos
			private _shortStop = false;
			private _newKnob = 0;
			switch(_input)do{
				case 0:{
					//next mode
					_newKnob = _knobs #_ctrl;
					private _count = _counts #_ctrl;
					if(_newKnob < _count)then{
						_newKnob = _newKnob +1;
						if(_ctrl == 0 && _newKnob == 1 && _simpleCtrl)then{
							_newKnob = _newKnob +1;
						};
					}else{
						_shortStop = true;
					};
				};
				case 1:{
					//previous mode
					_newKnob = _knobs #_ctrl;
					if(_newKnob > 0)then{
						_newKnob = _newKnob -1;
						if(_ctrl == 0 && _newKnob == 1 && _simpleCtrl)then{
							_newKnob = _newKnob -1;
						};
					}else{
						_shortStop = true;
					};
				};
			};

			//end script if knobs are at end of range
			if(_shortStop)exitWith{};

			if(ctrl == 0 && _deviceState #0 > 0)then{
				switch(true)do{
					case (!_simpleCtrl && _newKnob == 1 && _deviceState == 1 && _comboMode == 1):{
						_deviceState set [0,3];
					};
					case (!_simpleCtrl && _newKnob == 1 && _deviceState == 1 && _comboMode == 2);
					case (!_simpleCtrl && _newKnob == 1 && _deviceState == 2);
					case (_simpleCtrl && (_newKnob == 0 || _newKnob == 2)):{
						private _inverter = -(_deviceState #0);
						_deviceState set [0,_inverter];
					};
				};
			};

			playSound "click";

			private _newKnobNum = +_newKnob;

			switch(_ctrl)do{
				case 0:{
					_newKnob = _knob1 #_newKnob;
					_newKnob = [_base1,"\",_newKnob] joinString "";
					ctrlSetText [1001,_newKnob];
				};
				case 1:{
					_newKnob = _knob2 #_newKnob;
					if(_newKnob != "")then{
						_newKnob = [_base2,"\",_newKnob] joinString "";
					};
					ctrlSetText [1002,_newKnob];
				};
			};

			//get device mode
			private _newKnobs = +_knobs;
			_newKnobs set [_ctrl,_newKnobNum];
			private _newKnob1 = _newKnobs #0;
			private _newKnob2 = _newKnobs #1;
			private _newMode = 0;
			switch(true)do{
				case (_newKnob1 == 0 && _newKnob2 == 2): {	//VIS AIM LO + IR Flash
					_newMode = 0;
					_comboMode = 1;
				};
				case (_newKnob1 == 2 && _newKnob2 == 0): {	//IR AIM LO + Vis Flash
					_newMode = 1;
					_comboMode = 1;
				};
				case (_newKnob1 == 3 && _newKnob2 == 0): {	//IR DUAL LO + Vis Flash
					_newMode = 2;
					_comboMode = 1;
				};
				case (_newKnob1 == 4 && _newKnob2 == 0): {	//IR AIM HI + Vis Flash
					_newMode = 3;
					_comboMode = 1;
				};
				case (_newKnob1 == 5 && _newKnob2 == 0): {	//IR ILLUM HI + Vis Flash
					_newMode = 4;
					_comboMode = 1;
				};
				case (_newKnob1 == 6 && _newKnob2 == 0): {	//IR DUAL HI + Vis Flash
					_newMode = 5;
					_comboMode = 1;
				};
				case (_newKnob1 == 1 && _newKnob2 == 0): {	//VIS Flash
					_newMode = 6;
					_comboMode = 3;
					if(_deviceState #0 > 0)then{
						_deviceState set [0,_comboMode];
					};
				};
				case (_newKnob1 == 0 && _newKnob2 == 0): {	//VIS AIM + Flash
					_newMode = 7;
					_comboMode = 1;
				};
				case (_newKnob1 == 0 && _newKnob2 == 1):{	//VIS AIM LO
					_newMode = 8;
					_comboMode = 2;
				};
				case (_newKnob1 == 1 && _newKnob2 == 1):{	//OFF
					_newMode = 9;
					_comboMode = 0;
				};
				case (_newKnob1 == 1 && _newKnob2 == 2):{	//IR Flash
					_newMode = 10;
					_comboMode = 3;
					if(_deviceState #0 > 0)then{
						_deviceState set [0,_comboMode];
					};
				};
				case (_newKnob1 == 2 && _newKnob2 == 1):{	//IR AIM LO
					_newMode = 11;
					_comboMode = 2;
				};
				case (_newKnob1 == 2 && _newKnob2 == 2):{	//IR AIM LO + Flash
					_newMode = 12;
					_comboMode = 1;
				};
				case (_newKnob1 == 3 && _newKnob2 == 1):{	//IR DUAL LO
					_newMode = 13;
					_comboMode = 2;
				};
				case (_newKnob1 == 3 && _newKnob2 == 2):{	//IR DUAL LO + Flash
					_newMode = 14;
					_comboMode = 1;
				};
				case (_newKnob1 == 4 && _newKnob2 == 1):{	//IR AIM HI
					_newMode = 15;
					_comboMode = 2;
				};
				case (_newKnob1 == 4 && _newKnob2 == 2):{	//IR AIM HI + Flash
					_newMode = 16;
					_comboMode = 1;
				};
				case (_newKnob1 == 5 && _newKnob2 == 1):{	//IR ILLUM HI
					_newMode = 17;
					_comboMode = 2;
				};
				case (_newKnob1 == 5 && _newKnob2 == 2):{	//IR ILLUM HI + Flash
					_newMode = 18;
					_comboMode = 1;
				};
				case (_newKnob1 == 6 && _newKnob2 == 1):{	//IR DUAL HI
					_newMode = 19;
					_comboMode = 2;
				};
				case (_newKnob1 == 6 && _newKnob2 == 2):{	//IR DUAL HI + Flash
					_newMode = 20;
					_comboMode = 1;
				};
			};

			_deviceState set [4,_newMode];
			_unit setVariable ["gjb_itn_deviceComboState",_comboMode];
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
			
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 6 || _deviceState #4 == 10))then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};

			//set tooltips
			[] call _changeToolTip;
		};
		_interfacePower = {
			private _isOn = _deviceState #0;
			switch(_button)do{
				case 1:{
					private _mode = _deviceState #4;
					private _off = _deviceCtrls #1 #0;
					if(_mode == _off || _comboMode == 3)exitWith{};

					//turn off device
					if(_isOn > 0)then{
						//handle independent activation
						switch(_isOn)do{
							case 1:{
								_deviceState set [0,3];
							};
							case 2:{
								_deviceState set [0,0];
							};
							case 3:{
								_deviceState set [0,1];
							};
						};
						playSound "ClickSoft";
						private _dbalA2OnCounter = _unit getVariable ["gjb_itn_dbalA2OnCounter",0];
						if(!(_dbalA2OnCounter isEqualType 0))then{
							terminate _dbalA2OnCounter;
						};
					}else{
						//turn on device independent
						_deviceState set [0,2];

						//Ensures player has own offset determined
						private _deviceOffset = _unit getVariable ["gjb_itn_deviceOffset",0];
						if(!(_deviceOffset isEqualType []))then{
							[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
						};
						[] spawn {
							playSound "ClickSoft";
							sleep 0.15;
							playSound "ClickSoft";
						};
						if(_simpleCtrl != true && _momentaryMode == 1)then{
							private _dbalA2OnCounter = [_unit] spawn {
								sleep 600;
								private _unit = _this #0;
								private _deviceState = _unit getVariable ["gjb_itn_deviceState",[0,0,0,0,0,0]];
								private _invert = _deviceState #0;
								if(_invert > 0)then{
									_invert = -(_invert);
									_deviceState set [0,_invert];
								};
								_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
								//Turn off interface onIndicator
								ctrlShow [999,false];
							};
							_unit setVariable ["gjb_itn_dbalA2OnCounter",_dbalA2OnCounter];
						};
					};
				};
				case 2:{	//finish out for partial-activation system
					private _mode = _deviceState #4;
					private _off = _deviceCtrls #1 #0;
					if(_mode == _off || _comboMode == 2)exitWith{};

					if(_isOn > 0)then{
						//handle independent activation
						switch(_isOn)do{
							case 1:{
								_deviceState set [0,2];
							};
							case 2:{
								_deviceState set [0,1];
							};
							case 3:{
								_deviceState set [0,0];
							};
						};
						playSound "ClickSoft";
					}else{
						//turn on device independent
						_deviceState set [0,3];
					};
				};
			};
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 6 || _deviceState #4 == 10))then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};
		//key controls
		_openInterface = {
			//create interface
			createDialog _interface;

			//convert mode to knob positions
			private _knobs = call _mode2knob;

			//set devices
			private _illumMode = _deviceState #2;
			private _diffMode = "base_doff_co.paa";
			if(_illumMode > 1.1 || _illumMode < -1.1)then{
				_diffMode = "base_don_co.paa";
			};
			private _device1 = [_base1,_diffMode] joinString "\";
			private _device2 = [_base2,"base_co.paa"] joinString "\";

			ctrlSetText [1000,_device1];
			ctrlSetText [1003,_device2];

			//set knobs
			ctrlSetText [1001,_knobs #0];
			ctrlSetText [1002,_knobs #1];

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
					_layer = _dis displayCtrl _x;
					_layer ctrlSetTextColor _nvgColor;
				} forEach [1000,1001,1002,1003,999];
			}else{
				private _lightV = getLightingAt player;
				_lightV = (_lightV #1  / 100) max (_lightV #3 / 150) + 0.05;
				if(_lightV < 1)then{
					private _dimmer = [_lightV,_lightV,_lightV,1];
					{
						_layer = _dis displayCtrl _x;
						_layer ctrlSetTextColor _dimmer;
					} forEach [1000,1001,1002,1003];
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
			private _idOverlayL = getNumber (configFile >> _interface >> "overlayL" >> "idc");
			private _isOn = false;
			if( _deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 6 || _deviceState #4 == 9 || _deviceState #4 == 10))then{
				_isOn = true;
			};
			private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
			ctrlShow [_idOverlay,_overlay];
			ctrlShow [_idOverlayL,_overlay];
			ctrlShow [_idOnIndic,_isOn];

			//Hide auto-on menu
			private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");
			ctrlShow [_autoOnMenu,false];

			//set tooltips
			[] call _initToolTip;
		};
		_momentaryControl = {
			private _mode = _deviceState #4;
			private _off = _deviceCtrls #1 #0;
			if(_mode == _off)exitWith{};
			
			private _state = _deviceState #0;
			private _time = time;
			private _sTime = _unit getVariable ["gjb_itn_dpTimer",0];
			switch(_input)do{
				case 0:{	//key-down is on, starts timer for double-click
					//Cancel DBAL's constant-on timer, if active
					private _dbalA2OnCounter = _unit getVariable ["gjb_itn_dbalA2OnCounter",0];
					if(!(_dbalA2OnCounter isEqualType 0))then{
						terminate _dbalA2OnCounter;
					};
					//Begin double-click timer
					private _diff = _time - _sTime;
					if(_diff < 0.25 && _diff >= 0)then{
						_unit setVariable ["gjb_itn_dpState",1];
						private _dbalA2OnCounter = [_unit] spawn {
							sleep 600;
							private _unit = _this #0;
							private _deviceState = _unit getVariable ["gjb_itn_deviceState",[0,0,0,0,0,0]];
							private _invert = _deviceState #0;
							if(_invert > 0)then{
								_invert = -(_invert);
								_deviceState set [0,_invert];
							};
							_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
							//Turn off interface onIndicator
							ctrlShow [999,false];
						};
						_unit setVariable ["gjb_itn_dbalA2OnCounter",_dbalA2OnCounter];
					}else{
						_sTime = +_time;
						_unit setVariable ["gjb_itn_dpTimer",_sTime];
						_unit setVariable ["gjb_itn_dpState",0];
					};
					//Activate device if OFF (clears partial activation)
					if(_state == 1)then{
						_deviceState set [0,0];
					}else{
						_deviceState set [0,1];
					};
					//Ensures player has own offset determined
					private _deviceOffset = _unit getVariable ["gjb_itn_deviceOffset",0];
					if(!(_deviceOffset isEqualType []))then{
						[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
					};
					playSound "ClickSoft";
				};
				case 1:{	//key-up is off, adjusts behavior depending on time between last two key-downs
					//Determin if double-click, and ignore input if yes
					private _isDP = _unit getVariable ["gjb_itn_dpState",0];
					if(_isDP == 0 && _state > 0)then{
						//Turn off device
						private _invert = -(_state);
						_deviceState set [0,_invert];
					}else{
						_unit setVariable ["gjb_itn_dpState",0];
					};
				};
			};
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 6 || _deviceState #4 == 9 || _deviceState #4 == 10))then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};
		_changeMode = {
			//get knobState
			private _knobs = call _mode2knob;

			//change knobs to reflect mode
			ctrlSetText [1001,_knobs #0];
			ctrlSetText [1002,_knobs #1];
			_unit setVariable ["gjb_itn_deviceComboState",_comboMode];

			//set tooltips
			[] call _changeToolTip;
		};

switch(_ctrl)do{
	case "keys":{
		[] call _momentaryControl;
	};
	case "fire1":{
		private _button = 1;
		switch(true)do{
			case (_input == 0 && _type == "b"):{
				call _interfacePower;
			};
			case (_input == 1 && _type == "b"):{
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
		private _button = 2;
		switch(true)do{
			case (_input == 0 && _type == "b"):{
				call _interfacePower;
			};
			case (_input == 1 && _type == "b"):{
				call _autoOnMenu;
			};
		};
	};
	case "mode0":{
		call _changeMode;
	};
	case "mode1":{
		private _button = 1;
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
	case "mode2":{
		private _button = 2;
		switch(true)do{
			case (_type == "w" && _input > 0): {
				_input = 0;
			};
			case (_type == "w" && _input < 0): {
				_input = 1;
			};
		};
		_ctrl = 1;
		call _interfaceChangeMode;
	};
	case "illumD":{	//hold cycles focus, LMB(0) tight RMB(1) loose
		private _time = time;
		private _counter = [_unit,_deviceState,_input] spawn {
			params ["_unit","_devStat","_input"];
			sleep 0.35;
			private _illumMode = _devStat #2;
			switch(_input)do{
				case 1: {	//RMB tighten
					for "_i" from 1 to 10 do{
						switch(true)do{
							case (_illumMode == 0);
							case (_illumMode == -1): {
								_illumMode = -1.005;
							};
							case (_illumMode > -1.007 && _illumMode < -1.001);
							case (_illumMode > -1.107 && _illumMode < -1.101):{
								_illumMode = _illumMode +0.001;
							};
							case (_illumMode == 1):{
								_illumMode = 1.005;
							};
							case (_illumMode > 1.001 && _illumMode < 1.007);
							case (_illumMode > 1.101 && _illumMode < 1.107): {
								_illumMode = _illumMode -0.001;
							};
						};
						_devStat set [2,_illumMode];
						[_unit,_devStat] call gjb_itn_fnc_modeSpec;
						sleep 0.2;
					};
				};
				case 0: {	//LMB widen
					for "_i" from 1 to 10 do{
						switch(true)do{
							case (_illumMode == 0);
							case (_illumMode == -1): {
								_illumMode = -1.006;
							};
							case (_illumMode > -1.006 && _illumMode < -1.000);
							case (_illumMode > -1.106 && _illumMode < -1.100):{
								_illumMode = _illumMode -0.001;
							};
							case (_illumMode == 1):{
								_illumMode = 1.006;
							};
							case (_illumMode > 1.000 && _illumMode < 1.006);
							case (_illumMode > 1.100 && _illumMode < 1.106): {
								_illumMode = _illumMode +0.001;
							};
						};
						_devStat set [2,_illumMode];
						[_unit,_devStat] call gjb_itn_fnc_modeSpec;
						sleep 0.2;
					};
				};
			};
			_devStat set [2,_illumMode];
			[_unit,_devStat] call gjb_itn_fnc_modeSpec;
		};
		_unit setVariable ["gjb_itn_diffTimer",_time];
		_unit setVariable ["gjb_itn_diffCounter",_counter];
	};
	case "illumU":{	//tap toggles diffuse, otherwise release stops focus cycle
		private _time = time;
		private _stime = _unit getVariable ["gjb_itn_diffTimer",0];
		private _dwell = _time - _stime;
		if(_dwell < 0.3 || _type == "k")then{	//if click, toggle diffuse
			private _illumMode = _deviceState #2;
			switch(true)do{
				case (_illumMode == 0);
				case (_illumMode == -1): {
					_illumMode = -1.106;
				};
				case (_illumMode == 1): {
					_illumMode = 1.106;
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
			_deviceState set [2,_illumMode];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
			//Change gui to reflect diff mode
			if(!_genericInterface)then{
				private _device = ctrlText 1000; 
				_device = _device splitString "\";
				private _countStr = (count _device)-1;
				if(_illumMode > 1.1 || _illumMode < -1.1)then{
					_device set [_countStr,"base_don_co.paa"];
				}else{
					_device set [_countStr,"base_doff_co.paa"];
				};
				_device = _device joinString "\";
				ctrlSetText [1000,_device];
			};
		};
		private _counter = _unit getVariable ["gjb_itn_diffCounter",0];
		if(!(_counter isEqualType 0))then{
			terminate _counter #0;
		};
	};
	case "illumW":{	//wheel cycles through focus modes, up tight down loose
		private _illumMode = _deviceState #2;
		switch(true)do{
			case (_input > 0):{	//focus widen		+0.01
				switch(true)do{
					case (_illumMode == 0);
					case (_illumMode == -1): {
						_illumMode = -1.006;
					};
					case (_illumMode > -1.006 && _illumMode < -1.000);
					case (_illumMode > -1.106 && _illumMode < -1.100):{
						_illumMode = _illumMode -0.001;
					};
					case (_illumMode == 1):{
						_illumMode = 1.006;
					};
					case (_illumMode > 1.000 && _illumMode < 1.006);
					case (_illumMode > 1.100 && _illumMode < 1.106): {
						_illumMode = _illumMode +0.001;
					};
				};
			};
			case (_input < 0):{	//Focus tighten		- 0.01
				switch(true)do{
					case (_illumMode == 0);
					case (_illumMode == -1): {
						_illumMode = -1.005;
					};
					case (_illumMode > -1.007 && _illumMode < -1.001);
					case (_illumMode > -1.107 && _illumMode < -1.101):{
						_illumMode = _illumMode +0.001;
					};
					case (_illumMode == 1):{
						_illumMode = 1.005;
					};
					case (_illumMode > 1.001 && _illumMode < 1.007);
					case (_illumMode > 1.101 && _illumMode < 1.107): {
						_illumMode = _illumMode -0.001;
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