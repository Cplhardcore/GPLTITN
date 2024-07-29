#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_deviceMk23
//
//	Takes input from Interface and controls general and unique device features for the Glock GTLweapon light.
//
//*****************************************************************************//

params ["_ctrl","_input","_type"];

private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];

//Ensures device is defaulted if first activation
if(!(_deviceState isEqualType []))then{
	_deviceState = [_unit] call gjb_itn_fnc_initMode;
};

private _filter = _unit getVariable ["gjb_itn_knobModeSec",0];
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
			private _knobOps2 = ["irOff_co.paa","irOn_co.paa"];

			private _file1 = "";
			private _file2 = "";
			switch(_mode)do{
				case 0: {
					_filter = 1;
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #_filter;
				};
				case 1: {
					_filter = 0;
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #_filter;
				};
				case 2: {
					_filter = 0;
					_file1 = _knobOps1 #0;
					_file2 = _knobOps2 #_filter;
				};
				case 3: {
					_file1 = _knobOps1 #1;
					_file2 = _knobOps2 #_filter;
				};
				case 4: {
					_file1 = _knobOps1 #2;
					_file2 = _knobOps2 #_filter;
				};
				case 5: {
					_file1 = _knobOps1 #3;
					_file2 = _knobOps2 #_filter;
				};
				case 6: {
					_filter = 1;
					_file1 = _knobOps1 #4;
					_file2 = _knobOps2 #_filter;
				};
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
			private _knob1 = ["VD_co.paa","VA_co.paa","OFF_co.paa","IA_co.paa","ID_co.paa"];
			private _count1 = (count _knob1) -1;
			private _knob2 = ["irOff_co.paa","irOn_co.paa"];

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
						private _newKnobName = _knob1 #_newKnob;
						_newKnobName = [_base,"\",_newKnobName] joinString "";
						ctrlSetText [1001,_newKnobName];
						playSound "click";
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
						private _newKnobName = _knob1 #_newKnob;
						_newKnobName = [_base,"\",_newKnobName] joinString "";
						ctrlSetText [1001,_newKnobName];
						playSound "click";
					}else{
						_shortStop = true;
					};
				};
				case 2:{
					//filter toggle
					private _newFilterPos = [1,0];
					_filter = _newFilterPos #_filter;
					private _newFilterName = _knob2 #_filter;
					_newFilterName = [_base,"\",_newFilterName] joinstring "";
					ctrlSetText [1002,_newFilterName];
					//Show and hide appropriate buttons
					private _filterBoolOps = [true,false];
					private _filterBool = _filterBoolOps #_filter;
					ctrlShow [1102,!_filterBool];
					ctrlShow [1103,_filterBool];
				};
			};

			//end script if knobs are at end of range
			if(_shortStop)exitWith{};
			
			//Turn off device if device mode is off
			if(_deviceState #0 > 0 && _newKnob == 2)then{
				private _inverter = -(_deviceState #0);
				_deviceState set [0,_inverter];
			};

			//get device mode
			private _newMode = 0;
			switch(true)do{
				case (_newKnob == 0 && _filter == 1):{	//vis laser and ir illum
					_newMode = 0;
				};
				case (_newKnob == 4 && _filter == 0):{	//ir laser and vis illum
					_newMode = 1;
				};
				case (_newKnob == 0 && _filter == 0):{	//vis dual
					_newMode = 2;
				};
				case (_newKnob == 1):{		//vis laser
					_newMode = 3;
				};
				case (_newKnob == 2):{	//off
					_newMode = 4;
				};
				case (_newKnob == 3):{	//ir laser
					_newMode = 5;
				};
				case (_newKnob == 4 && _filter == 1):{	//ir dual
					_newMode = 6;
				};
			};
			_deviceState set [4,_newMode];
			_unit setVariable ["gjb_itn_knobModeSec",_filter];
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
			};
			playSound "ClickSoft";
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};
		//key controls
		_openInterface = {
			//create interface and assign appropriate color
			createDialog _interface;

			private _baseFile = [_base,"\","base_co.paa"] joinString "";
			ctrlSetText [1000,_baseFile];

			//convert deviceMode into knobState
			private _knobs = call _mode2knob;

			//set knobs
			ctrlSetText [1001,_knobs #0];
			ctrlSetText [1002,_knobs #1];

			//show appropriate filter button
			private _filterBoolOps = [true,false];
			private _filterBool = _filterBoolOps #_filter;
			ctrlShow [1102,!_filterBool];
			ctrlShow [1103,_filterBool];

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
				} forEach [1000,1001,1002];
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
			private _knobs = call _mode2knob;

			//set knobs
			ctrlSetText [1001,_knobs #0];
			ctrlSetText [1002,_knobs #1];

			//show appropriate filter button
			private _filterBoolOps = [true,false];
			private _filterBool = _filterBoolOps #_filter;
			ctrlShow [1102,!_filterBool];
			ctrlShow [1103,_filterBool];

			//record filter state
			_unit setVariable ["gjb_itn_knobModeSec",_filter];
			
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
		call _interfaceChangeMode;
	};
	case "filter":{
		_input = 2;
		call _interfaceChangeMode;
	};
	case "interface":{
		[] call _openInterface;
	};
};