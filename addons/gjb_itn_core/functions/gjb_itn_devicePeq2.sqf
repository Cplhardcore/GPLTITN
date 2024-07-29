#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_devicePeq2
//
//	Takes input from Interface and controls general and unique device features for the PEQ-2 laser
//	 aiming device.
//
//		Device specific features:
//				Patterned diffusors for the laser?
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
			//possible knob positions clockwise
			private _knob = ["OFF_co.paa","AL_co.paa","DL_co.paa","AH_co.paa","DLH_co.paa","DH_co.paa"];
			private _count = (count _knob) -1;

			//Retrieve current knob state and hide knobs
				//power
				private _currentKnob = ctrlText 1001; 
				_currentKnob = _currentKnob splitString "\";
				private _countStr = (count _currentKnob)-1;
				_currentKnob = _knob find (_currentKnob #_countStr);

			private _irCheck = +_currentKnob;

			//Adjust knob pos
			private _shortStop = false;
			private _newKnob = 0;
			switch(_input)do{
				case 1:{
					//next mode
					_newKnob = _currentKnob;
					if(_newKnob < _count)then{
						_newKnob = _newKnob +1;
					}else{
						_shortStop = true;
					};
				};
				case 0:{
					//previous mode
					_newKnob = _currentKnob;
					if(_newKnob > 0 || (_simpleCtrl && _newKnob > 1))then{
						_newKnob = _newKnob -1;
					}else{
						_shortStop = true;
					};
				};
			};

			//end script if knobs are at end of range
			if(_shortStop == true)exitWith{};
			
			//Turn off device if changing between vis/ir or set to OFF pos
			if(_deviceState #0 > 0 && _newKnob == 0)then{
				private _inverter = -(_deviceState #0);
				_deviceState set [0,_inverter];
			};

			playSound "click";

			//Set knob to new position
			_newKnobText = _knob #_newKnob;
			_newKnobText = [_base,"\",_newKnobText] joinString "";
			ctrlSetText [1001,_newKnobText];

			//get device mode
			private _newMode = _newKnob;

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
			};
			//Set  interface onIndicator as appropriate
			if(_deviceState #0 > 0 && _deviceState #4 != 0)then{
				ctrlShow [999,true];
			}else{
				ctrlShow [999,false];
			};
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};
		//key controls
		_openInterface = {
			//create interface and assign appropriate color
			createDialog _interface;

			private _illumMode = _deviceState #2;
			private _diffMode = "base_doff_co.paa";
			if(_illumMode > 1.1 || _illumMode < -1.1)then{
				_diffMode = "base_don_co.paa";
			};
			private _baseFile = [_base,_diffMode] joinString "\";
			ctrlSetText [1000,_baseFile];

			//convert deviceMode into knobState
			private _mode = _deviceState #4;
			private _knobOps =["OFF_co.paa","AL_co.paa","DL_co.paa","AH_co.paa","DLH_co.paa","DH_co.paa"];
			private _file = _knobOps #_mode;

			//set knobs
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
				_indic ctrlSetTextColor _dbalIndic; 
			};

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			private _isOn = false;
			if(_deviceState #0 > 0 && _deviceState #4 != 0)then{
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
		_changeMode = {
			//convert deviceMode into knobState
			private _mode = _deviceState #4;
			private _knobOps = ["OFF_co.paa","AL_co.paa","DL_co.paa","AH_co.paa","DLH_co.paa","DH_co.paa"];

			private _file = _knobOps #_mode;

			//set knobs
			private _knob =  [_base,"\",_file] joinString "";
			ctrlSetText [1001,_knob];
			
			//set tooltips
			private _newKnob = _mode;
			[] call _changeToolTip;
		};

switch(_ctrl)do{
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