#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_deviceUTG
//
//	Takes input from Interface and controls general and unique device features for the UTG weapon light.
//
//		Device specific features:
//				Constant-on lasts 5 minutes
//				Programmable pulse/strobe for laser mode
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

//Functions
		//interface controls
		_interfacePower = {
			private _isOn = _deviceState #0;
			if(_isOn > 0)then{
				private _invert = -(_isOn);
				_deviceState set [0,_invert];
				_isOn = false;
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
				_isOn = true;
			};

			//handle XM8 (CUP) flashlight toggle switch
			if(_interface == "Rsc_gjb_itn_xm8_cup")then{
				private _file = "base_co.paa";
				if(_deviceState #0 > 0)then{
					_file = "base_on_co.paa";
				}else{
					_file = "base_off_co.paa";
				};
				private _baseFile = [_base,"\",_file] joinString "";
				ctrlSetText [1000,_baseFile];
			};

			ctrlShow [999,_isOn];
			playSound "ClickSoft";
			_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
		};
		//key controls
		_openInterface = {
			//create interface and assign appropriate color
			createDialog _interface;

			//handle XM8 (CUP) flashlight toggle switch
			private _file = "base_co.paa";
			if(_interface == "Rsc_gjb_itn_xm8_cup")then{
				if(_deviceState #0 > 0)then{
					_file = "base_on_co.paa";
				}else{
					_file = "base_off_co.paa";
				};
			};
			private _baseFile = [_base,"\",_file] joinString "";
			ctrlSetText [1000,_baseFile];

			//toggle overlay and on-indicator as necessary
			private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
			private _idOverlay = getNumber (configFile >> _interface >> "overlay" >> "idc");
			private _isOn = false;
			if( _deviceState #0 > 0)then{
				_isOn = true;
			};
			private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
			ctrlShow [_idOverlay,_overlay];
			ctrlShow [_idOnIndic,_isOn];

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
				private _red = [0.74,0,0,1];
				private _green = [0.38,0.77,0,1];
				private _blue = [0,0.48,0.9,1];
				private _color = _red;
				if(_interface find "perst" != -1)then{
					_color = _blue;
				};
				_indic ctrlSetTextColor _color; 
			};

			//Hide auto-on menu
			private _autoOnMenu = getNumber (configFile >> _interface >> "fire_menu" >> "idc");
			ctrlShow [_autoOnMenu,false];
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
	case "interface":{
		[] call _openInterface;
	};
};