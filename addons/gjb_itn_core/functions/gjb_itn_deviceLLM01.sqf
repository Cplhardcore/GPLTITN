#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_deviceLLM01
//
//	Takes input from Interface and controls general and unique device features for the Rheinmetall LLM01
//	 weapon light.
//
//		Side buttons activate selected mode, rear button always (except OFF) sets mode to and activates
//		 flash/illum only
//
//*****************************************************************************//

params ["_ctrl","_input","_type"];

private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];

//Ensures device is defaulted if first activation
if(!(_deviceState isEqualType []))then{
	_deviceState = [_unit] call gjb_itn_fnc_initMode;
};

private _llmMode = _unit getVariable ["gjb_itn_knobModeLLM",3];
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
		_mode2knob  = {
			//convert deviceMode into knobState
			private _mode = _deviceState #4;
			private _knobOps1 = ["VD_co.paa","VA_co.paa","OFF_co.paa","IA_co.paa","ID_co.paa"];

			private _file1 = "";
			switch(_mode)do{
				case 0: {	//Vis dual
					_file1 = _knobOps1 #0;
				};
				case 1: {	//vis flash
					_file1 = _knobOps1 #_llmMode;
				};
				case 2: {	//vis aim
					_file1 = _knobOps1 #1;
				};
				case 3: {	//off
					_file1 = _knobOps1 #2;
				};
				case 4: {	//ir aim
					_file1 = _knobOps1 #3;
				};
				case 5: {	//ir flash
					_file1 = _knobOps1 #_llmMode;
				};
				case 6: {	//ir dual
					_file1 = _knobOps1 #4;
				};
			};

			//combine into full file path
			private _knob1 =  [_base,"\",_file1] joinString "";

			_knob1;
		};
		_initToolTip = {
			private _tipMode = missionNamespace getVariable ["gjb_itn_setting_toolTipMode",0];
			private _dispNum = getNumber (configFile >> _interface >> "idd");
			private _disp = findDisplay _dispNum;
			private _ctrl = _disp displayCtrl 1060;
			private _modeSw = _ctrl controlsGroupCtrl 1100;
			private _pwrbt = _ctrl controlsGroupCtrl 1101;
			private _pwrbt2 = _ctrl controlsGroupCtrl 1102;
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
					private _pwrbtKeys2 = localize "STR_GJB_ITN_CUP_LLM01BACKPWRKEY";
					_pwrbt ctrlSetTooltip (localize "STR_GJB_ITN_CUP_LLM01SIDEPWR" + _pwrbtKeys);
					_pwrbt2 ctrlSetTooltip (localize "STR_GJB_ITN_CUP_LLM01BACKPWR" + _pwrbtKeys2);
					private _illumKeys = localize "STR_GJB_ITN_CORE_IRDFKEY" + localize "STR_GJB_ITN_CORE_IRFOKEY";
					_illum ctrlSetTooltip (localize "STR_GJB_ITN_CORE_DEVIRDFFO" + _illumKeys);
				};
				case 1: {
					_modeSw ctrlSetTooltip _modeStr;
					_pwrbt ctrlSetTooltip localize "STR_GJB_ITN_CUP_LLM01SIDEPWR";
					_pwrbt2 ctrlSetTooltip localize "STR_GJB_ITN_CUP_LLM01BACKPWR";
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
			private _knob1 = ["VD_co.paa","VA_co.paa","OFF_co.paa","IA_co.paa","ID_co.paa"];
			private _count1 = (count _knob1) -1;

			//Retrieve current knob state and hide knobs
				//mode
				private _currentKnob1 = ctrlText 1001; 
				_currentKnob1 = _currentKnob1 splitString "\";
				private _countStr = (count _currentKnob1)-1;
				_currentKnob1 = _knob1 find (_currentKnob1 #_countStr);

			//Adjust knob pos
			
			private _shortStop = false;
			private _newKnob = _currentKnob1;
			switch(_input)do{
				case 0:{
					//next mode
					if(_newKnob < _count1)then{
						_newKnob = _newKnob +1;
						if(_newKnob == 2 && _simpleCtrl)then{
							_newKnob = _newKnob +1;
						};
					}else{
						_shortStop = true;
					};
				};
				case 1:{
					//previous mode
					if(_newKnob > 0)then{
						_newKnob = _newKnob -1;
						if(_newKnob == 2 && _simpleCtrl)then{
							_newKnob = _newKnob -1;
						};
					}else{
						_shortStop = true;
					};
				};
			};

			//end script if knobs are at end of range
			if(_shortStop)exitWith{};

			//Turn off device if device mode is off or when changing mode when not Simplified controls
			if(_deviceState #0 > 0 && (!_simpleCtrl || _newKnob == 3))then{
				private _inverter = -(_deviceState #0);
				_deviceState set [0,_inverter];
			};

			//Set new knob
			private _newKnobName = _knob1 #_newKnob;
			_newKnobName = [_base,"\",_newKnobName] joinString "";
			ctrlSetText [1001,_newKnobName];
			playSound "click";

			//get device mode
			private _newMode = 0;
			switch(true)do{
				case (_newKnob == 0):{	//vis dual
					_newMode = 0;
				};
				case (_newKnob == 1 ):{	//vis laser
					_newMode = 2;
				};
				case (_newKnob == 2):{		//off
					_newMode = 3;
				};
				case (_newKnob == 3):{	//ir laser
					_newMode = 4;
				};
				case (_newKnob == 4):{	//ir dual
					_newMode = 6;
				};
			};
			_deviceState set [4,_newMode];
			_unit setVariable ["gjb_itn_knobModeLLM",_newKnob];
			_unit setVariable ["gjb_itn_deviceState",_deviceState,true];
			[_unit,_deviceState] call gjb_itn_fnc_modeSpec;

			//set tooltips
			private _newKnob = _newMode;
			[] call _changeToolTip;
		};
		_interfacePower = {
			private _mode = _deviceState #4;
			private _off = _deviceCtrls #1 #0;
			if(_mode == _off)exitWith{};

			private _isOn = _deviceState #0;
			switch(_button)do{
				case 1:{	//left/right buttons
					if(_mode in [1,5])then{
						private _newMode = 0;
						switch(_llmMode)do{
							case 0:{	//vis dual
								_newMode = 0;
							};
							case 1:{	//vis laser
								_newMode = 2;
							};
							case 2:{		//off
								_newMode = 3;
							};
							case 3:{	//ir laser
								_newMode = 4;
							};
							case 4:{	//ir dual
								_newMode = 6;
							};
						};
						_deviceState set [4,_newMode];
						_deviceState set [0,1];
						[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
					}else{
						if(_isOn == 0)then{
							_deviceState set [0,1];
							//Ensures player has own offset determined
							private _deviceOffset = _unit getVariable ["gjb_itn_deviceOffset",0];
							if(!(_deviceOffset isEqualType []))then{
								[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
							};
						}else{
							private _invert = -(_isOn);
							_deviceState set [0,_invert];
						};
						_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
					};
				};
				case 2:{	//back button
					switch(_mode)do{
						case 1;
						case 5:{
							//if already flash mode, turn on or off as appropriate
							if(_isOn == 0)then{
								_deviceState set [0,1];
								//Ensures player has own offset determined
								private _deviceOffset = _unit getVariable ["gjb_itn_deviceOffset",0];
								if(!(_deviceOffset isEqualType []))then{
									[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
								};
							}else{
								private _invert = -(_isOn);
								_deviceState set [0,_invert];
							};
							_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
						};
						case 0;
						case 2:{
							_deviceState set [4,1];
							_deviceState set [0,1];
							[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
						};
						case 4;
						case 6:{
							_deviceState set [4,5];
							_deviceState set [0,1];
							[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
						};
					};
				};
			};
			playSound "ClickSoft";
		};
		//key controls
		_openInterface = {
			//create interface and assign appropriate color
			createDialog _interface;

			private _baseFile = [_base,"\","base_co.paa"] joinString "";
			ctrlSetText [1000,_baseFile];

			//convert deviceMode into knobState
			private _knob = call _mode2knob;

			//set knobs
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
				} forEach [1000,1001];
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
			};

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			ctrlShow [_idOverlay,_overlay];

			//Hide auto-on menu
			private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");
			ctrlShow [_autoOnMenu,false];
			
			//set tooltips
			[] call _initTooltip;
		};
		_changeMode = {
			//convert deviceMode into knobState
			private _knob = call _mode2knob;

			//set knobs
			ctrlSetText [1001,_knob];

			//record filter state
			_unit setVariable ["gjb_itn_knobModeLLM",_knob];
			
			//set tooltips
			private _newKnob = _mode;
			[] call _changeToolTip;
		};

switch(_ctrl)do{
	case "fire1":{
		switch(true)do{
			case (_input == 0 && _type == "b"):{
				private _button = 1;
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
		if(_input == 0 && _type == "b")then{
			private _button = 2;
			call _interfacePower;
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
		call _interfaceChangeMode;
	};
	case "interface":{
		[] call _openInterface;
	};
};