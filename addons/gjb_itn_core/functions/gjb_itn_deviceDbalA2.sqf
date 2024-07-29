#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_deviceDbalA2
//
//	Takes input from Interface and controls general and unique device features for the DBAL-A2/PEQ-15A
//	laser aiming device.
//
//		Device specific features:
//				MOM/ON Power mode distinction
//				Constant-on lasts 5 minutes
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
private _momentaryMode = _unit getVariable ["gjb_itn_dbala2MomState",1];	//0 is constant, 1 is momentary

private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> "acc_pointer_IR";
private _deviceCtrls = getArray (_deviceCfg >> "gjb_itn_controls");
private _interfaceCfg = getArray (_deviceCfg >> "gjb_itn_interface");
private _interface = _interfaceCfg #1;
private _base = _interfaceCfg #2;

//Functions
		//internal functions
		_mode2knob  = {
			//convert deviceMode into knobState
			private _mode = _deviceState #4;
			private _knobOps1 = ["OL_co.paa","ML_co.paa","OFF_co.paa","MH_co.paa","OH_co.paa"];
			private _knobOps2 = ["VA_co.paa","IL_co.paa","ID_co.paa","IA_co.paa"];

			private _file1 = "";
			private _file2 = "";
			switch(_mode)do{
				case 0: {
					private _heldModes = _unit getVariable ["gjb_itn_knobModes",[[1,0],[1,0],[1,0]]];
					private _lastMode = _heldModes #0;
					private _choice = _lastMode #0;
					if(_choice == 2)then{
						_choice = _heldModes #1 #0;
						if(_choice == 2)then{
							_choice = _heldModes #2 #0;
						};
					};
					_file1 = _knobOps1 #_choice;
					_file2 = _knobOps2 #0;
				};
				case 1: {
					private _heldModes = _unit getVariable ["gjb_itn_knobModes",[[1,3],[1,3],[1,3]]];
					private _lastMode = _heldModes #0;
					private _choice = _lastMode #1;
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #_choice;
				};
				case 2: {
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #1;
				};
				case 3: {
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #1
				};
				case 4: {
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #2;
				};
				case 5: {
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #2;
				};
				case 6: {
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #3;
				};
				case 7: {
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #3;
				};
			};

			//set appropriate power mode
			if(_simpleCtrl == false && _file1 != _knobOps1 #2)then{
				_file1 = _file1 splitString "";
				if(_momentaryMode == 1)then{
					_file1 set [0,"M"];
				}else{
					_file1 set [0,"O"];
				};
				_file1 = _file1 joinString "";
			};
			
			//combine into full file path
			private _knob1 =  [_base,"\",_file1] joinString "";
			private _knob2 = [_base,"\",_file2] joinString "";

			[_knob1,_knob2];
		};
		_initToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrl = _disp displayCtrl 1060;
			private _pwr = _ctrl controlsGroupCtrl 1100;
			private _mode = _ctrl controlsGroupCtrl 1101;
			private _pwrbt = _ctrl controlsGroupCtrl 1102;
			private _illum = _ctrl controlsGroupCtrl 1103;
			private _curMode =  localize "STR_GJB_ITN_CORE_CURMODE";
			//prep mode tip
				//power select
			private _knobAct = ["OL_co.paa","ML_co.paa","OFF_co.paa","MH_co.paa","OH_co.paa"];
			private _txtAct = _knobs #0;
			_txtAct = (_txtAct splitString "\") #-1;
			_knobAct = _knobAct find _txtAct;
			private _modeAct = ["ON LO","MOM LO", "OFF","MOM HI","ON HI"];
			_modeAct = _modeAct #_knobAct;
			_modeAct = _curMode + " " + _modeAct;
				//activation select
			private _knobLas = ["VA_co.paa","IL_co.paa","ID_co.paa","IA_co.paa"];
			private _txtLas = _knobs #1;
			_txtLas = (_txtLas splitString "\") #-1;
			_knobLas = _knobLas find _txtLas;
			private  _modeLas = ["VIS POINT","I/R ILLUM","I/R POINT & ILLUM","I/R POINT"];
			_modeLas = _modeLas #_knobLas;
			_modeLas = _curMode + " " + _modeLas;
			private _pwrStr = localize "STR_GJB_ITN_CORE_DBALACT" + _modeAct;
			private _modeStr = localize "STR_GJB_ITN_CORE_DBALMODE" + _modeLas;
			switch(_tipMode)do{
				case 0: {
					private _keysVerb = localize "STR_GJB_ITN_CORE_MODEKEY";
					_pwrStr = _pwrStr + _keysVerb;
					_pwr ctrlSetTooltip _pwrStr;
					_modeStr = _modeStr + _keysVerb;
					_mode ctrlSetTooltip _modeStr;
					private _pwrbtKeys = localize "STR_GJB_ITN_CORE_PWRKEYB";
					_pwrbt ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DBALPWR" + _pwrbtKeys);
					private _illumKeys = localize "STR_GJB_ITN_CORE_IRDFKEY" + localize "STR_GJB_ITN_CORE_IRFOKEY";
					_illum ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVIRDFFO" + _illumKeys);
				};
				case 1: {
					_pwr ctrlSetTooltip _pwrStr;
					_mode ctrlSetTooltip _modeStr;
					_pwrbt ctrlSetTooltip localize "STR_GJB_ITN_CORE_DBALPWR";
					_illum ctrlSetTooltip localize "STR_GJB_ITN_CORE_DEVIRDFFO";
				};
				case 2: {
					{
						_x ctrlSetTooltip "";
						_x ctrlSetTooltipColorBox [0,0,0,0];
						_x ctrlSetTooltipColorShade [0,0,0,0];
					} forEach [_pwr,_mode,_pwrbt,_illum];
				};
			};
		};
		_changeToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrlGrp = _disp displayCtrl 1060;
			private _pwr = _ctrlGrp controlsGroupCtrl 1100;
			private _mode = _ctrlGrp controlsGroupCtrl 1101;
			private _curMode =  localize "STR_GJB_ITN_CORE_CURMODE";
			//prep mode tip
			private _knobLas = ["OL_co.paa","ML_co.paa","OFF_co.paa","MH_co.paa","OH_co.paa"];
			private  _modeLas = ["ON LO","MOM LO", "OFF","MOM HI","ON HI"];
			if(_ctrl == 1)then{
				_knobLas = ["VA_co.paa","IL_co.paa","ID_co.paa","IA_co.paa"];
				_modeLas = ["VIS POINT","I/R ILLUM","I/R POINT & ILLUM","I/R POINT"];
			};
			private _txtLas = _newKnob splitString "\";
			_txtLas = _txtLas #-1;
			_knobLas = _knobLas find _txtLas;
			_modeLas = _modeLas #_knobLas;
			_modeLas = _curMode + " " + _modeLas;
			private _pwrStr = localize "STR_GJB_ITN_CORE_DBALACT";
			if(_ctrl == 1)then{
				_pwrStr = localize "STR_GJB_ITN_CORE_DBALMODE";
				_pwr = _mode;
			};
			_pwrStr = _pwrStr + _modeLas;
			if(_tipMode == 0)then{
				_pwrStr = _pwrStr + localize "STR_GJB_ITN_CORE_MODEKEY";
			};
			if(_tipMode != 2)then{
				_pwr ctrlSetTooltip _pwrStr;
			};
		};
		//interface controls
		_interfaceChangeMode = {
			//possible knob positions, from left to right and clockwise
			private _knob1 = ["OL_co.paa","ML_co.paa","OFF_co.paa","MH_co.paa","OH_co.paa"];
			private _count1 = (count _knob1) -1;
			private _knob2 = ["VA_co.paa","IL_co.paa","ID_co.paa","IA_co.paa"];
			private _count2 = (count _knob2) -1;

			//Retrieve current knob state and hide knobs
				//power
				private _currentKnob1 = ctrlText 1001; 
				_currentKnob1 = _currentKnob1 splitString "\";
				private _countStr = (count _currentKnob1)-1;
				_currentKnob1 = _knob1 find (_currentKnob1 #_countStr);
				//mode
				private _currentKnob2 = ctrlText 1002; 
				_currentKnob2 = _currentKnob2 splitString "\";
					_countStr = (count _currentKnob2)-1;
				_currentKnob2 = _knob2 find (_currentKnob2 #_countStr);

			private _knobs = [_currentKnob1,_currentKnob2];
			private _counts = [_count1,_count2];
			private _irCheck = +(_knobs #1);

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
						if(_ctrl == 0 && _newKnob == 2 && _simpleCtrl)then{
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
						if(_ctrl == 0 && _newKnob == 2 && _simpleCtrl)then{
							_newKnob = _newKnob -1;
						};
					}else{
						_shortStop = true;
					};
				};
			};

			//end script if knobs are at end of range
			if(_shortStop)exitWith{};
			
			if(_deviceState #0 > 0 && _ctrl == 1 && (_newKnob == 0 || _irCheck == 0))then{
				private _inverter = -(_deviceState #0);
				_deviceState set [0,_inverter];
			};

			playSound "click";

			private _newKnobNum = +_newKnob;

			switch(_ctrl)do{
				case 0:{
					_newKnob = _knob1 #_newKnob;
					_newKnob = [_base,"\",_newKnob] joinString "";
					ctrlSetText [1001,_newKnob];
				};
				case 1:{
					_newKnob = _knob2 #_newKnob;
					_newKnob = [_base,"\",_newKnob] joinString "";
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
				case (_newKnob1 == 2):{
					//off mode
					_newMode = 1;
				};
				case (_newKnob1 != 2 && _newKnob2 == 0):{
					//vis aim
					_newMode = 0;
				};
				case (_newKnob1 < 2 && _newKnob2 == 1):{
					//ir illum LO
					_newMode = 2;
				};
				case (_newKnob1 > 2 && _newKnob2 == 1):{
					//ir illum HI
					_newMode = 3;
				};
				case (_newKnob1 < 2 && _newKnob2 == 2):{
					//ir dual LO
					_newMode = 4;
				};
				case (_newKnob1 > 2 && _newKnob2 == 2):{
					//ir dual HI
					_newMode = 5;
				};
				case (_newKnob1 < 2 && _newKnob2 == 3):{
					//ir aim LO
					_newMode = 6;
				};
				case (_newKnob1 > 2 && _newKnob2 == 3):{
					//ir aim HI
					_newMode = 7;
				};
			};

			//update momentary state
			if(_newKnob1 == 0 || _newKnob1 == 4)then{
				_momentaryMode = 0;
			}else{
				_momentaryMode = 1;
			};
			_unit setVariable ["gjb_itn_dbala2MomState",_momentaryMode];
			
			private _lastKnobs = player getVariable ["gjb_itn_knobModes",[[0,0],[0,0],[0,0]]];
			 private _knobHolder = [_newKnobs] +_lastKnobs;
			 if(count _knobHolder >2)then{
				_knobHolder resize 3;
			 };
			player setVariable ["gjb_itn_knobModes",_knobHolder];

			//Toggle device ON if not momentary mode
			switch(true)do{
				case (_momentaryMode == 0 && (_deviceState #0) == 0):{
					_deviceState set [0,1];
				};
				case (_momentaryMode == 0 && (_deviceState #0) < 0):{
					private _inverter = -(_deviceState #0);
					_deviceState set [0,_inverter];
				};
				default {};
			};

			_deviceState set [4,_newMode];
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
			
			//set tooltips
			[] call _changeToolTip;
		};
		_interfacePower = {
			private _mode = _deviceState #4;
			private _off = _deviceCtrls #1 #0;
			if(_mode == _off)exitWith{};

			private _isOn = _deviceState #0;
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
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && _deviceState #4 != 1)then{
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

			//set diffusor mode
			private _device = ctrlText 1000; 
			_device = _device splitString "\";
			private _countStr = (count _device)-1;
			
			private _illumMode = _deviceState #2;
			if(_illumMode > 1.1 || _illumMode < -1.1)then{
				_device set [_countStr,"base_don_co.paa"];
			}else{
				_device set [_countStr,"base_doff_co.paa"];
			};
			_device = _device joinString "\";
			ctrlSetText [1000,_device];

			//convert mode to knob positions
			
			private _knobs = call _mode2knob;

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
					private _layer = _dis displayCtrl _x;
					_layer ctrlSetTextColor _nvgColor;
				} forEach [1000,1001,1002,999];
			}else{
				private _lightV = getLightingAt player;
				_lightV = (_lightV #1  / 100) max (_lightV #3 / 150) + 0.05;
				if(_lightV < 1)then{
					private _dimmer = [_lightV,_lightV,_lightV,1];
					{
						private _layer = _dis displayCtrl _x;
						_layer ctrlSetTextColor _dimmer;
					} forEach [1000,1001,1002];
				};
				private _indic = _dis displayCtrl 999;
				private _peq15Indic = [0.74,0,0,1];
				private _dbalIndic = [0.38,0.77,0,1];
				private _perstIndic = [0,0.48,0.9,1];
				_indic ctrlSetTextColor _dbalIndic; 
			};

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			private _isOn = false;
			if( _deviceState #0 > 0 && _deviceState #4 != 1)then{
				_isOn = true;
			};
			private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
			ctrlShow [_idOverlay,_overlay];
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
			if(_deviceState #0 > 0 && _deviceState #4 != 1)then{
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

			//update knobPos var
			private _knob1 = ["OL_co.paa","ML_co.paa","OFF_co.paa","MH_co.paa","OH_co.paa"];
			private _knob2 = ["VA_co.paa","IL_co.paa","ID_co.paa","IA_co.paa"];

			//power
			private _currentKnob1 = _knobs #0;
			_currentKnob1 = _currentKnob1 splitString "\";
			private _countStr = (count _currentKnob1)-1;
			_currentKnob1 = _knob1 find (_currentKnob1 #_countStr);
			//mode
			private _currentKnob2 = _knobs #1;
			_currentKnob2 = _currentKnob2 splitString "\";
				_countStr = (count _currentKnob2)-1;
			_currentKnob2 = _knob2 find (_currentKnob2 #_countStr);

			private _newKnobs = [_currentKnob1,_currentKnob2];

			private _lastKnobs = player getVariable ["gjb_itn_knobModes",[[0,0],[0,0],[0,0]]];
			 private _knobHolder = [_newKnobs] +_lastKnobs;
			 if(count _knobHolder >2)then{
				_knobHolder resize 3;
			 };
			player setVariable ["gjb_itn_knobModes",_knobHolder];

			//set tooltips
			[] call _changeToolTip;
		};

switch(_ctrl)do{
	case "keys":{
		[] call _momentaryControl;
	};
	case "fire":{
		switch(true)do{
			case (_input == 0 && _momentaryMode == 1 && _type == "b"):{
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