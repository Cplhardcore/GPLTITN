#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_devicePerst3
//
//	Takes input from Interface and controls general and unique device features for the Perst3 laser
//	aiming device.
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
//private _comboMode = _unit getVariable ["gjb_itn_deviceComboState",0];	//1 is standard/dual, 2 is PEQ only, 3 is light only

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
private _base = _interfaceCfg #2;

private _deviceModes = getArray (_deviceCfg >> "gjb_itn_deviceModes");
private _deviceModeNames = [];
{
	private _name = _x #3;
	_deviceModeNames pushBack _name;
} forEach _deviceModes;


//Functions
		//internal functions
		_mode2knob  = {
			//convert deviceMode into knobState
			private _mode = _deviceState #4;
			private _knobOps1 = ["VA_co.paa","OFF_co.paa","IA_co.paa","IL_co.paa","ID_co.paa"];

			private _file1 = "";
			switch(_mode)do{
				case 0: {	//RED 3
					_file1 = _knobOps1 #0;
					_powerLevel set [0,3];
				};
				case 1: {	//RED 2
					_file1 = _knobOps1 #0;
					_powerLevel set [0,2];
				};
				case 2: {	//RED 1
					_file1 = _knobOps1 #0;
					_powerLevel set [0,1];
				};
				case 3: {	//OFF
					_file1 = _knobOps1 #1;
				};
				case 4: {	//IR 1
					_file1 = _knobOps1 #2;
					_powerLevel set [0,1];
				};
				case 5: {	//IR 2
					_file1 = _knobOps1 #2;
					_powerLevel set [0,2];
				};
				case 6: {	//IR 3
					_file1 = _knobOps1 #2;
					_powerLevel set [0,3];
				};
				case 7: {	//ILLUMINATOR 1
					_file1 = _knobOps1 #3;
					_powerLevel set [1,1];
				};
				case 8:{	//ILLUMINATOR 2
					_file1 = _knobOps1 #3;
					_powerLevel set [1,2];
				};
				case 9:{	//IR 1 + ILLUMINATOR 1
					_file1 = _knobOps1 #4;
					_powerLevel = [1,1];
				};
				case 10:{	//IR 2 + ILLUMINATOR 1
					_file1 = _knobOps1 #4;
					_powerLevel = [2,1];
				};
				case 11:{	//IR 3 + ILLUMINATOR 1
					_file1 = _knobOps1 #4;
					_powerLevel = [3,1];
				};
				case 12:{	//IR 1 + ILLUMINATOR 2
					_file1 = _knobOps1 #4;
					_powerLevel = [1,2];
				};
				case 13:{	//IR 2 + ILLUMINATOR 2
					_file1 = _knobOps1 #4;
					_powerLevel = [2,2];
				};
				case 14:{	//IR 3 + ILLUMINATOR 2
					_file1 = _knobOps1 #4;
					_powerLevel = [3,2];
				};
			};

			//combine into full file path
			private _knob1 =  [_base,"\",_file1] joinString "";

			[_knob1,_powerLevel];
		};
		_initToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrl = _disp displayCtrl 1060;
			private _modeSw = _ctrl controlsGroupCtrl 1100;
			private _pwrbt = _ctrl controlsGroupCtrl 1101;
			private _pwrbt2 = _ctrl controlsGroupCtrl 1102;
			private _pwrLvl = _ctrl controlsGroupCtrl 1105;
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
					private _pwrbtKeys = localize "STR_GJB_ITN_CORE_PWRKEYA";
					_pwrbt ctrlSetTooltip (localize "STR_GJB_ITN_CORE_PEQ15PWR" + _pwrbtKeys);
					_pwrbt2 ctrlSetTooltip (localize "STR_GJB_ITN_CORE_PEQ15PWR" + _pwrbtKeys);
					private _illumKeys = localize "STR_GJB_ITN_CORE_IRDFKEY" + localize "STR_GJB_ITN_CORE_IRFOKEY";
					_illum ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVIRDFFO" + _illumKeys);
					_pwrLvl ctrlSetTooltip (localize "STR_GJB_ITN_RHSR_PERST3PLVL" + localize "STR_GJB_ITN_RHSR_PERST3PLVLKEYS");
				};
				case 1: {
					_modeSw ctrlSetTooltip _modeStr;
					_pwrbt ctrlSetTooltip localize "STR_GJB_ITN_CORE_PEQ15PWR";
					_pwrbt2 ctrlSetTooltip localize "STR_GJB_ITN_CORE_PEQ15PWR";
					_illum ctrlSetTooltip localize "STR_GJB_ITN_CORE_DEVIRDFFO";
					_pwrLvl ctrlSetTooltip (localize "STR_GJB_ITN_RHSR_PERST3PLVL");
				};
				case 2: {
					{
						_x ctrlSetTooltip "";
						_x ctrlSetTooltipColorBox [0,0,0,0];
						_x ctrlSetTooltipColorShade [0,0,0,0];
					} forEach [_modeSw,_pwrbt,_pwrbt2,_pwrLvl,_illum];
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
							if(_lasPwr < 3)then{
								_lasPwr = _lasPwr +1;
							}else{
								_shortStop = true;
							};
						};
						case 3:{
							if(_illumPwr < 2)then{
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
							if(_lasPwr > 1)then{
								_lasPwr = _lasPwr -1;
							}else{
								_shortStop = true;
							};
						};
						case 3:{
							if(_illumPwr > 1)then{
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

			if(_deviceState #0 > 0 && _ctrl == 1 && _newKnob == 1 )then{
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
						_newKnob = [_base,"\",_newKnob] joinString "";
					};
					ctrlSetText [1001,_newKnob];
				};
			};

			//get device mode
			private _newKnob1 = _newKnobNum;
			private _newMode = 0;
			switch(true)do{
				case (_newKnob1 == 0 && _powerLevel #0 == 3): {	//RED 3
					_newMode = 0;
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 2): {	//RED 2
					_newMode = 1;
				};
				case (_newKnob1 == 0 && _powerLevel #0 == 1): {	//RED 1
					_newMode = 2;
				};
				case (_newKnob1 == 1): {	//OFF
					_newMode = 3;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 1): {	//IR 1
					_newMode = 4;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 2): {	//IR 2
					_newMode = 5;
				};
				case (_newKnob1 == 2 && _powerLevel #0 == 3): {	//IR 3
					_newMode = 6;
				};
				case (_newKnob1 == 3 && _powerLevel #1 == 1): {	//ILLUMINATOR 1
					_newMode = 7;
				};
				case (_newKnob1 == 3 && _powerLevel #1 == 2):{	//ILLUMINATOR 2
					_newMode = 8;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 1 && _powerLevel #1 == 1):{	//IR 1 + ILLUMINATOR 1
					_newMode = 9;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 2 && _powerLevel #1 == 1):{	//IR 2 + ILLUMINATOR 1
					_newMode = 10;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 3 && _powerLevel #1 == 1):{	//IR 3 + ILLUMINATOR 1
					_newMode = 11;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 1 && _powerLevel #1 == 2):{	//IR 1 + ILLUMINATOR 2
					_newMode = 12;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 2 && _powerLevel #1 == 2):{	//IR 2 + ILLUMINATOR 2
					_newMode = 13;
				};
				case (_newKnob1 == 4 && _powerLevel #0 == 3 && _powerLevel #1 == 2):{	//IR 3 + ILLUMINATOR 2
					_newMode = 14;
				};
			};

			_deviceState set [4,_newMode];
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;

			//set tooltips
			private _newKnob = _newMode;
			[] call _changeToolTip;

			//set indicator color
			if(currentVisionMode player != 1)then{
				private _iddMain = getNumber (configFile >> _interface >> "idd");
				private _dis = findDisplay _iddMain;
				private _indic = _dis displayCtrl 999;
				private _peq15Indic = [0.74,0,0,1];
				private _perstIndic = [0,0.48,0.9,1];
				private _color = _perstIndic;
				if(_newMode < _off)then{
					_color = _peq15Indic;
				};
				_indic ctrlSetTextColor _color; 
			};
		};
		_interfacePower = {
			private _mode = _deviceState #4;
			if(_mode == _off)exitWith{};
			
			private _isOn = _deviceState #0;
			//turn off device
			if(_isOn == 0)then{
				_deviceState set [0,1];
				playSound "ClickSoft";
			}else{
				private _invert = -(_isOn);
				_deviceState set [0,_invert];
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

			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && _deviceState #4 != 3)then{
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
			private _baseFile = [_base,_diffMode] joinString "\";
			ctrlSetText [1000,_baseFile];

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
				private _deviceMode = _deviceState #4;
				private _color = _perstIndic;
				if(_deviceMode < _off)then{
					_color = _peq15Indic;
				};
				_indic ctrlSetTextColor _color; 
			};

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			private _isOn = false;
			if( _deviceState #0 > 0 && _deviceState #4 != 3)then{
				_isOn = true;
			};
			private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
			ctrlShow [_idOverlay,_overlay];
			ctrlShow [_idOnIndic,_isOn];

			//Hide auto-on menu
			private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");
			ctrlShow [_autoOnMenu,false];
			
			//set tooltips
			[] call _initTooltip;
		};
		/*_momentaryControl = {
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
					/*if(_state == 0)then{
						_deviceState set [0,1];
					}else{
						if(_state < 0)then{
							private _invert = -(_state);
							_deviceState set [0,_invert];
						};
					};* /
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
			if(_deviceState #0 > 0 && _deviceState #0 != 3)then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};*/
		_changeMode = {
			//get knobState
			private _knobs = call _mode2knob;

			//change knobs to reflect mode
			ctrlSetText [1001,_knobs #0];
			_unit setVariable ["gjb_itn_perst3pwr",_knobs #1];
			
			//set tooltips
			private _newKnob = _deviceState #4;
			[] call _changeToolTip;

			//set indicator color
			if(currentVisionMode player != 1)then{
				private _iddMain = getNumber (configFile >> _interface >> "idd");
				private _dis = findDisplay _iddMain;
				private _indic = _dis displayCtrl 999;
				private _peq15Indic = [0.74,0,0,1];
				private _perstIndic = [0,0.48,0.9,1];
				private _color = _perstIndic;
				if(_newKnob < _off)then{
					_color = _peq15Indic;
				};
				_indic ctrlSetTextColor _color; 
			};
		};

switch(_ctrl)do{
	case "keys":{
		[] call _momentaryControl;
	};
	case "fire":{
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