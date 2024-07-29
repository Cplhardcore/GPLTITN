#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_devicePerst3Combo
//
//	Takes input from Interface and controls general and unique device features for the Perst3 laser
//	aiming device and Klesh-2DP weaponlight.
//
//		Device specific features:
//				Strobe mode
//				Variable power levels for laser and illuminator
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
private _powerLevel = _unit getVariable ["gjb_itn_perst3pwr",[1,1]];
private _comboMode = _unit getVariable ["gjb_itn_deviceComboState",[0,0]];	//#0 flash state, #1 combo mode; 1 is standard/dual, 2 is PEQ only, 3 is light only

if(_comboMode isEqualType 0)then{
	_comboMode = [0,0];
};

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
private _off = _deviceCtrls #1 #0;
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
			private _knobOps1 = ["VA_co.paa","OFF_co.paa","IA_co.paa","IL_co.paa","ID_co.paa"];

			private _file1 = "";
			switch(_mode)do{
				case 0: {	//IR 1 + Flash
					_file1 = _knobOps1 #2;
					_powerLevel set [0,1];
					_comboMode set [0,1];
				};
				case 1: {	//IR 2 + Flash
					_file1 = _knobOps1 #2;
					_powerLevel set [0,2];
					_comboMode set [0,1];
				};
				case 2: {	//IR 3 + Flash
					_file1 = _knobOps1 #2;
					_powerLevel set [0,3];
					_comboMode set [0,1];
				};
				case 3: {	//ILLUMINATOR 1 + Flash
					_file1 = _knobOps1 #3;
					_powerLevel set [1,1];
					_comboMode set [0,1];
				};
				case 4:{	//ILLUMINATOR 2 + Flash
					_file1 = _knobOps1 #3;
					_powerLevel set [1,2];
					_comboMode set [0,1];
				};
				case 5:{	//IR 1 + ILLUMINATOR 1 + Flash
					_file1 = _knobOps1 #4;
					_powerLevel = [1,1];
					_comboMode set [0,1];
				};
				case 6:{	//IR 2 + ILLUMINATOR 1 + Flash
					_file1 = _knobOps1 #4;
					_powerLevel = [2,1];
					_comboMode set [0,1];
				};
				case 7:{	//IR 3 + ILLUMINATOR 1 + Flash
					_file1 = _knobOps1 #4;
					_powerLevel = [3,1];
					_comboMode set [0,1];
				};
				case 8:{	//IR 1 + ILLUMINATOR 2 + Flash
					_file1 = _knobOps1 #4;
					_powerLevel = [1,2];
					_comboMode set [0,1];
				};
				case 9:{	//IR 2 + ILLUMINATOR 2 + Flash
					_file1 = _knobOps1 #4;
					_powerLevel = [2,2];
					_comboMode set [0,1];
				};
				case 10:{	//IR 3 + ILLUMINATOR 2 + Flash
					_file1 = _knobOps1 #4;
					_powerLevel = [3,2];
					_comboMode set [0,1];
				};
				case 11: {// Flash
					_file1 = _knobOps1 #1;
					_comboMode set [0,1];
				};
				case 12: {	//RED 3 + Flash
					_file1 = _knobOps1 #0;
					_powerLevel set [0,3];
					_comboMode set [0,1];
				};
				case 13: {	//RED 2 + Flash
					_file1 = _knobOps1 #0;
					_powerLevel set [0,2];
					_comboMode set [0,1];
				};
				case 14: {	//RED 1 + Flash
					_file1 = _knobOps1 #0;
					_powerLevel set [0,1];
					_comboMode set [0,1];
				};
				case 15: {	//RED 3
					_file1 = _knobOps1 #0;
					_powerLevel set [0,3];
					_comboMode set [0,0];
				};
				case 16: {	//RED 2
					_file1 = _knobOps1 #0;
					_powerLevel set [0,2];
					_comboMode set [0,0];
				};
				case 17: {	//RED 1
					_file1 = _knobOps1 #0;
					_powerLevel set [0,1];
					_comboMode set [0,0];
				};
				case 18: {	//OFF
					_file1 = _knobOps1 #1;
					_comboMode set [0,0];
				};
				case 19: {	//IR 1
					_file1 = _knobOps1 #2;
					_powerLevel set [0,1];
					_comboMode set [0,0];
				};
				case 20: {	//IR 2
					_file1 = _knobOps1 #2;
					_powerLevel set [0,2];
					_comboMode set [0,0];
				};
				case 21: {	//IR 3
					_file1 = _knobOps1 #2;
					_powerLevel set [0,3];
					_comboMode set [0,0];
				};
				case 22: {	//ILLUMINATOR 1
					_file1 = _knobOps1 #3;
					_powerLevel set [1,1];
					_comboMode set [0,0];
				};
				case 23:{	//ILLUMINATOR 2
					_file1 = _knobOps1 #3;
					_powerLevel set [1,2];
					_comboMode set [0,0];
				};
				case 24:{	//IR 1 + ILLUMINATOR 1
					_file1 = _knobOps1 #4;
					_powerLevel = [1,1];
					_comboMode set [0,0];
				};
				case 25:{	//IR 2 + ILLUMINATOR 1
					_file1 = _knobOps1 #4;
					_powerLevel = [2,1];
					_comboMode set [0,0];
				};
				case 26:{	//IR 3 + ILLUMINATOR 1
					_file1 = _knobOps1 #4;
					_powerLevel = [3,1];
					_comboMode set [0,0];
				};
				case 27:{	//IR 1 + ILLUMINATOR 2
					_file1 = _knobOps1 #4;
					_powerLevel = [1,2];
					_comboMode set [0,0];
				};
				case 28:{	//IR 2 + ILLUMINATOR 2
					_file1 = _knobOps1 #4;
					_powerLevel = [2,2];
					_comboMode set [0,0];
				};
				case 29:{	//IR 3 + ILLUMINATOR 2
					_file1 = _knobOps1 #4;
					_powerLevel = [3,2];
					_comboMode set [0,0];
				};
			};

			//combine into full file path
			private _knob1 =  [_base1,"\",_file1] joinString "";

			[_knob1,_powerLevel,_comboMode];
		};
		_initToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrlId = _disp displayCtrl 1060;
			private _modeSw = _ctrlId controlsGroupCtrl 1100;
			private _pwrbt = _ctrlId controlsGroupCtrl 1101;
			private _pwrbt2 = _ctrlId controlsGroupCtrl 1102;
			private _pwrLvl = _ctrlId controlsGroupCtrl 1105;
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
				/*/flashlight mode
				private _knobFl = _knobs #1;
				_knobFl = _knobFl splitString "\";
				_knobFl = ["VIS_co.paa","OFF_co.paa","IR_co.paa"] find (_knobFl #-1);
				_knobFl = ["VIS","OFF","IR"] #_knobFl;
				_knobFl = _curMode + " " + _knobFl;
				private _flString = localize "STR_GJB_ITN_CORE_DEVMODEALT" + _knobFl;*/
				switch(_tipMode)do{
					case 0: {
						private _keysVerb = localize "STR_GJB_ITN_CORE_MODEKEY";
						_modeStr = _modeStr + _keysVerb;
						_modeSw ctrlSetTooltip _modeStr;
						/*private _keysVerbAlt = localize "STR_GJB_ITN_CORE_FLMODEKEYALT";
						_flString = _flString + _keysVerbAlt;
						_modeFl ctrlSetTooltip _flString;*/
						private _pwrbtKeys = localize "STR_GJB_ITN_CORE_PWRKEYA";
						_pwrbt ctrlSetTooltip (localize "STR_GJB_ITN_CORE_PEQ15PWR" + _pwrbtKeys);
						_pwrbt2 ctrlSetTooltip (localize "STR_GJB_ITN_CORE_PEQ15PWR" + _pwrbtKeys);
						private _illumKeys = localize "STR_GJB_ITN_CORE_IRDFKEY" + localize "STR_GJB_ITN_CORE_IRFOKEY";
						_illum ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVIRDFFO" + _illumKeys);
						private _pwrbtKeysAlt = localize "STR_GJB_ITN_CORE_PWRKEYC";
						_pwrbtFl ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVPWR" + _pwrbtKeysAlt);
						_pwrLvl ctrlSetTooltip (localize "STR_GJB_ITN_RHSR_PERST3PLVL" + localize "STR_GJB_ITN_RHSR_PERST3PLVLKEYS");
					};
					case 1: {
						_modeSw ctrlSetTooltip _modeStr;
						_pwrbt ctrlSetTooltip localize "STR_GJB_ITN_CORE_PEQ15PWR";
						_pwrbt2 ctrlSetTooltip localize "STR_GJB_ITN_CORE_PEQ15PWR";
						_illum ctrlSetTooltip localize "STR_GJB_ITN_CORE_DEVIRDFFO";
						//_modeFl ctrlSetTooltip _flString;
						_pwrbtFl ctrlSetTooltip localize "STR_GJB_ITN_CORE_DEVPWR";
						_pwrLvl ctrlSetTooltip (localize "STR_GJB_ITN_RHSR_PERST3PLVL");
					};
					case 2: {
						{
							_x ctrlSetTooltip "";
							_x ctrlSetTooltipColorBox [0,0,0,0];
							_x ctrlSetTooltipColorShade [0,0,0,0];
						} forEach [_modeSw,_pwrbt,_pwrbt2,_pwrLvl,_illum,_modeFl,_pwrbtFl];
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
					/*private _modeFlash =  (_knobs #1) splitString "\";
					_modeFlash = ["VIS_co.paa","OFF_co.paa","IR_co.paa"] find (_modeFlash #-1);
					_modeFlash = ["VIS","OFF","IR"] #_modeFlash;
					_modeFlash = _curMode + " " + _modeFlash;
					private _modeTypeFl = localize "STR_GJB_ITN_CORE_DEVMODEALT";
					private _modeKeyFl= localize "STR_GJB_ITN_CORE_MODEKEY";*/
					private _modeStr = _modeType + _modeLas;
					//private _flashStr = _modeTypeFl + _modeFlash;
					if(_tipMode == 0)then{
						_modeStr = _modeStr + _modeKey;
						//_flashStr = _flashStr + _modeKeyFl;
					};
					_modeSw ctrlSetTooltip _modeStr;
					//_modeFl ctrlSetTooltip _flashStr;
				};
				case (_tipMode != 2 && _type != "k"): {
					private _modeType = localize "STR_GJB_ITN_CORE_DEVMODE";
					private _modeKey = localize "STR_GJB_ITN_CORE_MODEKEY";
					private _modeLas = _deviceModeNames #_newMode;
					/*if(_ctrl == 1)then{
						//_modeLas = _knobs #1;
						_modeLas = _newKnob splitString "\";
						_modeLas = ["VIS_co.paa","OFF_co.paa","IR_co.paa"] find (_modeLas #-1);
						_modeLas = ["VIS","OFF","IR"] #_modeLas;
						_modeSw = _modeFl;
						_modeLas = _curMode + " " + _modeLas;
						_modeType = localize "STR_GJB_ITN_CORE_DEVMODE";
						//_modeKey = localize "STR_GJB_ITN_CORE_FLMODEKEYALT";
					}else{*/
						_modeLas = _modeLas splitString "+";
						_modeLas = _modeLas #0;
						if((_newKnob splitString "\") #-1 == "OFF_co.paa")then{
							_modeLas = "OFF";
						};
						_modeLas = _curMode + " " + _modeLas;
					//};
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
			private _knob1 = ["VA_co.paa","OFF_co.paa","IA_co.paa","IL_co.paa","ID_co.paa"];
			private _count1 = (count _knob1) -1;

			//Retrieve current knob state and hide knobs
				//laser device
				private _currentKnob1 = ctrlText 1001; 
				_currentKnob1 = _currentKnob1 splitString "\";
				private _countStr = (count _currentKnob1)-1;
				_currentKnob1 = _knob1 find (_currentKnob1 #_countStr);

			//Adjust knob pos
			private _shortStop = false;
			private _newKnob = _currentKnob1;
			switch(true)do{
				case (_input == 0 && _ctrl == 1):{
					//next mode
					if(_newKnob < _count1)then{
						_newKnob = _newKnob +1;
						if(_newKnob == 1 && _simpleCtrl)then{
							_newKnob = _newKnob +1;
						};
					}else{
						_shortStop = true;
					};
				};
				case (_input == 1 && _ctrl == 1):{
					//previous mode
					if(_newKnob > 0)then{
						_newKnob = _newKnob -1;
						if(_newKnob == 1 && _simpleCtrl)then{
							_newKnob = _newKnob -1;
						};
					}else{
						_shortStop = true;
					};
				};
				case (_input == 0 && _ctrl == 0):{
					//power +
					private _lasPwr = _powerLevel #0;
					private _illumPwr = _powerLevel #1;
					switch(_currentKnob1)do{
						case 0;
						case 2;
						case 4:{
							if(_lasPwr < 3 && _deviceState #4 != 18)then{
								_lasPwr = _lasPwr +1;
							}else{
								_shortStop = true;
							};
						};
						case 3:{
							if(_illumPwr < 2 && _deviceState #4 != 18)then{
								_illumPwr = _illumPwr +1;
							}else{
								_shortStop = true;
							};
						};
						default {
							_shortStop = true;
						};
					};
					_powerLevel = [_lasPwr,_illumPwr];
				};
				case (_input == 1 && _ctrl == 0):{
					//power -
					private _lasPwr = _powerLevel #0;
					private _illumPwr = _powerLevel #1;
					switch(_currentKnob1)do{
						case 0;
						case 2;
						case 4:{
							if(_lasPwr > 1 && _deviceState #4 != 18)then{
								_lasPwr = _lasPwr -1;
							}else{
								_shortStop = true;
							};
						};
						case 3:{
							if(_illumPwr > 1 && _deviceState #4 != 18)then{
								_illumPwr = _illumPwr -1;
							}else{
								_shortStop = true;
							};
						};
						default {
							_shortStop = true;
						};
					};
					_powerLevel = [_lasPwr,_illumPwr];
				};
			};

			//end script if knobs are at end of range
			if(_shortStop)exitWith{};

			/*if(_ctrl == 1 && _deviceState #0 > 0)then{
				switch(true)do{
					case (!_simpleCtrl && _newKnob == 1 && _deviceState == 1 && _comboMode #0 == 1):{
						_deviceState set [0,3];
					};
					case (!_simpleCtrl && _newKnob == 1 && _deviceState == 1 && _comboMode #0 == 0);
					case (!_simpleCtrl && _newKnob == 1 && _deviceState == 2);
					case (_simpleCtrl && (_newKnob == 0 || _newKnob == 2)):{
						private _inverter = -(_deviceState #0);
						_deviceState set [0,_inverter];
					};
				};
			};*/
			if((_deviceState #0 == 1 || _deviceState #0 == 2) && _ctrl == 1 && _newKnob == 1 && _comboMode #0 == 0)then{
				private _inverter = -(_deviceState #0);
				_deviceState set [0,_inverter];
			};

			if(_ctrl == 1)then{
				playSound "click";
			}else{
			playSound "ClickSoft";
			};

			private _newKnobNum = +_newKnob;

			switch(_ctrl)do{
				case 0:{
					_unit setVariable ["gjb_itn_perst3pwr",_powerLevel];
				};
				case 1:{
					_newKnob = _knob1 #_newKnob;
					if(_newKnob != "")then{
						_newKnob = [_base1,"\",_newKnob] joinString "";
					};
					ctrlSetText [1001,_newKnob];
				};
			};

			//get device mode
			private _newKnob1 = _newKnobNum;
			private _newMode = 0;
			switch(true)do{
				case (_newKnob1 == 2 && _powerLevel #0 == 1 && _comboMode #0 == 1): {	//IR 1 + Flash
					_newMode = 0;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 2 && _comboMode #0 == 1): {	//IR 2 + Flash
					_newMode = 1;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 3 && _comboMode #0 == 1): {	//IR 3 + Flash
					_newMode = 2;
				};
				case (_newKnob1 == 3 && _powerLevel #1 == 1 && _comboMode #0 == 1): {	//ILLUMINATOR 1 + Flash
					_newMode = 3;
				};
				case (_newKnob1 == 3 && _powerLevel #1 == 2 && _comboMode #0 == 1):{	//ILLUMINATOR 2 + Flash
					_newMode = 4;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 1 && _powerLevel #1 == 1 && _comboMode #0 == 1):{	//IR 1 + ILLUMINATOR 1 + Flash
					_newMode = 5;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 2 && _powerLevel #1 == 1 && _comboMode #0 == 1):{	//IR 2 + ILLUMINATOR 1 + Flash
					_newMode = 6;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 3 && _powerLevel #1 == 1 && _comboMode #0 == 1):{	//IR 3 + ILLUMINATOR 1 + Flash
					_newMode = 7;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 1 && _powerLevel #1 == 2 && _comboMode #0 == 1):{	//IR 1 + ILLUMINATOR 2 + Flash
					_newMode = 8;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 2 && _powerLevel #1 == 2 && _comboMode #0 == 1):{	//IR 2 + ILLUMINATOR 2 + Flash
					_newMode = 9;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 3 && _powerLevel #1 == 2 && _comboMode #0 == 1):{	//IR 3 + ILLUMINATOR 2 + Flash
					_newMode = 10;
				};
				case (_newKnob1 == 1 && _comboMode #0 == 1): {	//Flash
					_newMode = 11;
					//_deviceState set [0,3];
					if(_deviceState #0 > 0)then{
						_deviceState set [0,3];
					}else{
						_deviceState set [0,-3];
					};
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 3 && _comboMode #0 == 1): {	//RED 3 + Flash
					_newMode = 12;
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 2 && _comboMode #0 == 1): {	//RED 2 + Flash
					_newMode = 13;
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 1 && _comboMode #0 == 1): {	//RED 1 + Flash
					_newMode = 14;
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 3): {	//RED 3
					_newMode = 15;
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 2): {	//RED 2
					_newMode = 16;
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 1): {	//RED 1
					_newMode = 17;
				};
				case (_newKnob1 == 1): {	//OFF
					_newMode = 18;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 1): {	//IR 1
					_newMode = 19;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 2): {	//IR 2
					_newMode = 20;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 3): {	//IR 3
					_newMode = 21;
				};
				case (_newKnob1 == 3 && _powerLevel #1 == 1): {	//ILLUMINATOR 1
					_newMode = 22;
				};
				case (_newKnob1 == 3 && _powerLevel #1 == 2):{	//ILLUMINATOR 2
					_newMode = 23;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 1 && _powerLevel #1 == 1):{	//IR 1 + ILLUMINATOR 1
					_newMode = 24;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 2 && _powerLevel #1 == 1):{	//IR 2 + ILLUMINATOR 1
					_newMode = 25;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 3 && _powerLevel #1 == 1):{	//IR 3 + ILLUMINATOR 1
					_newMode = 26;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 1 && _powerLevel #1 == 2):{	//IR 1 + ILLUMINATOR 2
					_newMode = 27;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 2 && _powerLevel #1 == 2):{	//IR 2 + ILLUMINATOR 2
					_newMode = 28;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 3 && _powerLevel #1 == 2):{	//IR 3 + ILLUMINATOR 2
					_newMode = 29;
				};
			};

			_deviceState set [4,_newMode];
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;

			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 11) )then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};

			//set tooltips
			[] call _changeToolTip;

			//set indicator color
			if(currentVisionMode player != 1)then{
				private _iddMain = getNumber (configFile >> _interface >> "idd");
				private _dis = findDisplay _iddMain;
				private _indic = _dis displayCtrl 999;
				private _peq15Indic = [0.74,0,0,1];
				private _perstIndic = [0,0.48,0.9,1];
				private _color = _perstIndic;
				private _bottomStop = _deviceCtrls #1 #1;
				if(_newMode < _off && _newMode >= _bottomStop)then{
					_color = _peq15Indic;
				};
				_indic ctrlSetTextColor _color; 
			};
		};
		_interfacePower = {
			private _mode = _deviceState #4;
			private _isOn = _deviceState #0;
			switch(_button)do{
				case 1:{
					//laser device
					private _mode = _deviceState #4;
					private _off = _deviceCtrls #1 #0;
					if(_mode == _off || (_isOn == 3 && _mode == 11 ))exitWith{};
					
					if(_isOn > 0)then{
						//handle independent activation
						switch(_isOn)do{
							case 1:{
								_deviceState set [0,3];
								_comboMode set [1,3];
							};
							case 2:{
								_deviceState set [0,0];
								_comboMode set [1,0];
							};
							case 3:{
								_deviceState set [0,1];
								_comboMode set [1,1];
							};
						};
						playSound "ClickSoft";
					}else{
						_deviceState set [0,2];
						_comboMode set [1,2];
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
					};
				};
				case 2:{
					//flashlight
					private _flashOn = _comboMode #0;
					if(_isOn > 0)then{
						//handle independent activation
						switch(_isOn)do{
							case 1:{
								_flashOn = 0;
								_deviceState set [0,2];
								_comboMode set [1,2];
							};
							case 2:{
								_flashOn = 1;
								_deviceState set [0,1];
								_comboMode set [1,1];
							};
							case 3:{
								_flashOn = 0;
								_deviceState set [0,0];
								_comboMode set [1,0];
							};
						};
					}else{
						//turn on device independent
						_flashOn = 1;
						_deviceState set [0,3];
						_comboMode set [1,3];
					};

					playSound "ClickSoft";

					private _mode = _deviceState #4;
					switch(true)do{
						case (_mode <= 10 && _flashOn == 0):{
							//if IR + Flash, then IR
							_mode = _mode +19;
							_deviceState set [4,_mode];
							//_deviceState set [0,2];
						};
						case (_mode == 11 && _flashOn == 0):{
							//if Flash only, then OFF
							_mode = 18;
							_deviceState set [4,_mode];
							//_deviceState set [0,0];
						};
						case (_mode == 18 && _flashOn == 1):{
							//if OFF, then Flash only
							_mode = 11 ;
							_deviceState set [4,_mode];
							//_deviceState set [0,3];
						};
						case (_mode >= 12 && _mode <= 14 && _flashOn == 0):{
							//if Vis + Flash, then Vis
							_mode = _mode +3;
							_deviceState set [4,_mode];
							//_deviceState set [0,2];
						};
						case (_mode >= 15 && _mode <= 17 && _flashOn == 1):{
							//if Vis, then Vis + Flash
							_mode = _mode -3;
							_deviceState set [4,_mode];
							//_deviceState set [0,1];
						};
						case (_mode >= 19 && _flashOn == 1):{
							//if IR, then IR + Flash
							_mode = _mode -19;
							_deviceState set [4,_mode];
							//_deviceState set [0,1];
						};
					};
					//Update mode
					[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
				};
			};

			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 11 || _deviceState #4 == 18) )then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
			_unit setVariable ["gjb_itn_deviceComboState",_comboMode];
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
			ctrlSetText [1002,_device2];

			//set knobs
			ctrlSetText [1001,_knobs #0];
			_unit setVariable ["gjb_itn_perst3pwr",_knobs #1];

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
				private _color = _perstIndic;
				private _deviceMode = _deviceState #4;
				private _bottomStop = _deviceCtrls #1 #1;
				if(_deviceMode < _off && _deviceMode >= _bottomStop)then{
					_color = _peq15Indic;
				};
				_indic ctrlSetTextColor _color; 
			};

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			private _idOverlayL = getNumber (configFile >> _interface >> "overlayL" >> "idc");
			private _isOn = false;
			if( _deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 11 || _deviceState #4 == 18))then{
				_isOn = true;
			};
			//private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
			ctrlShow [_idOverlay,_overlay];
			ctrlShow [_idOverlayL,_overlay];
			ctrlShow [999,_isOn];

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
			private _sTime = _unit getVariable ["gjb_itn_dpTimer",-1];
		
			//assign behavior depending on input
			switch(_input)do{
				case 0:{	//key-down is on, starts timerfor dual purpose keybind
					_sTime = +_time;
					_unit setVariable ["gjb_itn_dpTimer",_sTime];
					_unit setVariable ["gjb_itn_dpState",_state];
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
				case 1:{	//key-up is off, adjusts behavior depending on time pressed if using dual purpose keybind
					_time = time;
					private _hold = _time - _sTime;
					if(_hold <= 0.5)then{
						private _dpState = _unit getVariable ["gjb_itn_dpState",-1];
						if(_dpState > 0)then{
							private _invert = -(_state);
							_deviceState set [0,_invert];
						}else{
							if(_state == 0)then{
								_deviceState set [0,1];
							}else{
								if(_state < 0)then{
									private _invert = -(_state);
									_deviceState set [0,_invert];
								};
							};
							//Ensures player has own offset determined
							private _deviceOffset = _unit getVariable ["gjb_itn_deviceOffset",0];
							if(!(_deviceOffset isEqualType []))then{
								[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
							};
						};
					}else{
						private _invert = -(_state);
						_deviceState set [0,_invert];
						playSound "ClickSoft";
					};
					_unit setVariable ["gjb_itn_dpTimer",nil];
					_unit setVariable ["gjb_itn_dpState",nil];
				};
			};

			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 11 || _deviceState #4 == 18) )then{
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
			
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && !(_deviceState #0 == 3 || _deviceState #4 == 11 || _deviceState #4 == 18))then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};

			_unit setVariable ["gjb_itn_perst3pwr",_knobs #1];

			//set tooltips
			[] call _changeToolTip;

			//set indicator color
			if(currentVisionMode player != 1)then{
				private _iddMain = getNumber (configFile >> _interface >> "idd");
				private _dis = findDisplay _iddMain;
				private _indic = _dis displayCtrl 999;
				private _peq15Indic = [0.74,0,0,1];
				private _perstIndic = [0,0.48,0.9,1];
				private _color = _perstIndic;
				private _deviceMode = _deviceState #4;
				private _bottomStop = _deviceCtrls #1 #1;
				if(_deviceMode < _off && _deviceMode >= _bottomStop)then{
					_color = _peq15Indic;
				};
				_indic ctrlSetTextColor _color; 
			};
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
		_ctrl = 0;
		call _interfaceChangeMode;
	};
	case "mode2":{
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
			case (_input < 0):{	//Focus tighten		- 0.01
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
		_deviceState set [2,_illumMode];
		[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
	};
	case "interface":{
		[] call _openInterface;
	};
};