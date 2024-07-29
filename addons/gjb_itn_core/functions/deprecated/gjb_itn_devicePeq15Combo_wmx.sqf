#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_devicePeq15Combo_wmx
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
private _autoOnMode = -1;
private _comboMode = _unit getVariable ["gjb_itn_deviceComboState",0];	//0 is standard/dual, 1 is PEQ only, 2 is light only

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

//retrieve directory
private _base1 = _interfaceCfg #2;
private _base2 = _interfaceCfg #3;

//Functions
		//internal functions
		_mode2knob  = {
			//convert deviceMode into knobState
			private _mode = _deviceState #4;
			private _knobOps1 = ["VAL_co.paa","OFF_co.paa","AL_co.paa","DL_co.paa","AH_co.paa","IH_co.paa","DH_co.paa"];
			private _knobOps2 = ["","OFF_combo_co.paa","IR_combo_co.paa"];

			private _file1 = "";
			private _file2 = "";
			switch(_mode)do{
				case 0: {	//VIS AIM LO + IR Flash
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #2;
				};
				case 1: {	//IR AIM LO + Vis Flash
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #0;
				};
				case 2: {	//IR DUAL LO + Vis Flash
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #0;
				};
				case 3: {	//IR AIM HI + Vis Flash
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #0;
				};
				case 4: {	//IR ILLUM HI + Vis Flash
					_file1 = _knobOps1 #5;
					_file2 = _knobOps2 #0;
				};
				case 5: {	//IR DUAL HI + Vis Flash
					_file1 = _knobOps1 #6;
					_file2 = _knobOps2 #0;
				};
				case 6: {	//VIS Flash
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #0;
				};
				case 7: {	//VIS AIM + Flash
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #0;
				};
				case 8:{	//VIS AIM LO
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #1;
				};
				case 9:{	//OFF
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #1;
				};
				case 10:{	//IR Flash
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #2;
				};
				case 11:{	//IR AIM LO
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #1;
				};
				case 12:{	//IR AIM LO + Flash
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #2;
				};
				case 13:{	//IR DUAL LO
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #1;
				};
				case 14:{	//IR DUAL LO + Flash
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #2;
				};
				case 15:{	//IR AIM HI
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #1;
				};
				case 16:{	//IR AIM HI + Flash
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #2;
				};
				case 17:{	//IR ILLUM HI
					_file1 = _knobOps1 #5;
					_file2 = _knobOps2 #1;
				};
				case 18:{	//IR ILLUM HI + Flash
					_file1 = _knobOps1 #5;
					_file2 = _knobOps2 #2;
				};
				case 19:{	//IR DUAL HI
					_file1 = _knobOps1 #6;
					_file2 = _knobOps2 #1;
				};
				case 20:{	//IR DUAL HI + Flash
					_file1 = _knobOps1 #6;
					_file2 = _knobOps2 #2;
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
		//interface controls
		_interfaceChangeMode = {
			//possible knob positions, from left to right and clockwise
			private _knob1 = ["VAL_co.paa","OFF_co.paa","AL_co.paa","DL_co.paa","AH_co.paa","IH_co.paa","DH_co.paa"];
			private _count1 = (count _knob1) -1;
			private _knob2 = ["","OFF_combo_co.paa","IR_combo_co.paa"];
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
			private _irCheck = +(_knobs #0);

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

			if(_deviceState #0 > 0 && _ctrl == 0 && (_newKnob == 1 || _newKnob == 0 || _irCheck == 0))then{
				private _inverter = -(_deviceState #0);
				_deviceState set [0,_inverter];
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
				};
				case (_newKnob1 == 2 && _newKnob2 == 0): {	//IR AIM LO + Vis Flash
					_newMode = 1;
				};
				case (_newKnob1 == 3 && _newKnob2 == 0): {	//IR DUAL LO + Vis Flash
					_newMode = 2;
				};
				case (_newKnob1 == 4 && _newKnob2 == 0): {	//IR AIM HI + Vis Flash
					_newMode = 3;
				};
				case (_newKnob1 == 5 && _newKnob2 == 0): {	//IR ILLUM HI + Vis Flash
					_newMode = 4;
				};
				case (_newKnob1 == 6 && _newKnob2 == 0): {	//IR DUAL HI + Vis Flash
					_newMode = 5;
				};
				case (_newKnob1 == 1 && _newKnob2 == 0): {	//VIS Flash
					_newMode = 6;
				};
				case (_newKnob1 == 0 && _newKnob2 == 0): {	//VIS AIM + Flash
					_newMode = 7;
				};
				case (_newKnob1 == 0 && _newKnob2 == 1):{	//VIS AIM LO
					_newMode = 8;
				};
				case (_newKnob1 == 1 && _newKnob2 == 1):{	//OFF
					_newMode = 9;
				};
				case (_newKnob1 == 1 && _newKnob2 == 2):{	//IR Flash
					_newMode = 10;
				};
				case (_newKnob1 == 2 && _newKnob2 == 1):{	//IR AIM LO
					_newMode = 11;
				};
				case (_newKnob1 == 2 && _newKnob2 == 2):{	//IR AIM LO + Flash
					_newMode = 12;
				};
				case (_newKnob1 == 3 && _newKnob2 == 1):{	//IR DUAL LO
					_newMode = 13;
				};
				case (_newKnob1 == 3 && _newKnob2 == 2):{	//IR DUAL LO + Flash
					_newMode = 14;
				};
				case (_newKnob1 == 4 && _newKnob2 == 1):{	//IR AIM HI
					_newMode = 15;
				};
				case (_newKnob1 == 4 && _newKnob2 == 2):{	//IR AIM HI + Flash
					_newMode = 16;
				};
				case (_newKnob1 == 5 && _newKnob2 == 1):{	//IR ILLUM HI
					_newMode = 17;
				};
				case (_newKnob1 == 5 && _newKnob2 == 2):{	//IR ILLUM HI + Flash
					_newMode = 18;
				};
				case (_newKnob1 == 6 && _newKnob2 == 1):{	//IR DUAL HI
					_newMode = 19;
				};
				case (_newKnob1 == 6 && _newKnob2 == 2):{	//IR DUAL HI + Flash
					_newMode = 20;
				};
			};

			_deviceState set [4,_newMode];
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
		};
		_interfacePower = {
			private _isOn = _deviceState #0;
			switch(_button)do{
				case 1:{
					if(_isOn > 0)then{
						private _invert = -(_isOn);
						_deviceState set [0,_invert];
						playSound "ClickSoft";
						private _dbalA2OnCounter = _unit getVariable ["gjb_itn_dbalA2OnCounter",0];
						if(!(_dbalA2OnCounter isEqualType 0))then{
							terminate _dbalA2OnCounter;
						};
					}else{
						if(_isOn == 0)then{
							_deviceState set [0,1];
						}else{
							private _invert = -(_isOn);
							_deviceState set [0,_invert];
						};
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
					if(_isOn > 0)then{
						private _invert = -(_isOn);
						_deviceState set [0,_invert];
						playSound "ClickSoft";
					}else{
						if(_isOn == 0)then{
							_deviceState set [0,1];
						}else{
							private _invert = -(_isOn);
							_deviceState set [0,_invert];
						};
					};
				};
			};
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0)then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};
		_illumFocus = {
			private _illumMode = _deviceState #2;
			switch(_input)do{
				case 0:{	//Widen focus
					switch(_illumMode)do{
						case 2;
						case 3;
						case 12;
						case 13:{
							_illumMode = _illumMode -1;
						};
						case -2;
						case -3;
						case -12;
						case -13:{
							_illumMode = _illumMode +1;
						};
					};
				};
				case 1:{	//Tighten focus
					switch(_illumMode)do{
						case 1;
						case 2;
						case 11;
						case 12:{
							_illumMode = _illumMode +1;
						};
						case 0:{
							_illumMode = -2;
						};
						case -1;
						case -2;
						case -11;
						case -12:{
							_illumMode = _illumMode -1;
						};
					};
				};
			};
			_deviceState set [2,_illumMode];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
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

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			private _idOverlayL = getNumber (configFile >> _interface >> "overlayL" >> "idc");
			private _isOn = false;
			if( _deviceState #0 > 0)then{
				_isOn = true;
			};
			private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
			ctrlShow [_idOverlay,_overlay];
			ctrlShow [_idOverlay,_overlay];
			ctrlShow [_idOnIndic,_isOn];

			//Hide auto-on menu
			private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");
			ctrlShow [_autoOnMenu,false];
		};
		_momentaryControl = {
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
					//Activate device if OFF
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
			if(_deviceState #0 > 0)then{
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
							case (_illumMode == 1): {
								_illumMode = 1.110;
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