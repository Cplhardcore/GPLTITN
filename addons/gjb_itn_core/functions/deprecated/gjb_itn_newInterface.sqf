#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_newInterface
//
//	Determines the appropriate position for interface knobs according to current
//	device mode, then shows appropriate knobs
//
//*****************************************************************************//

//params ["_unit","_mode","_interface"];

//Shortstop if player is in zeus menu
if (!isNull findDisplay 312) exitWith {false};

//Identify device and prepare data retrieval from namespaces
private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];
private _interfaceState = _unit getVariable ["gjb_itn_interfaceState",{0,0,0}];
private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];

//Ensures device is defaulted if first activation
if(!(_deviceState isEqualType []))then{
	_deviceState = [_unit] call gjb_itn_fnc_initMode;
};

private _mode = _deviceState #4;
private _deviceCategory = _deviceState #5;
private _device = "";
private _knobs = [];
switch(_deviceCategory)do{
	case 0: {
		_device = toLower (primaryWeaponItems _unit #1);
		_knobs = _interfaceState #0;
	};
	case 1: {
		_device = toLower (handgunItems _unit #1);
		_knobs = _interfaceState #1;
	};
	case 2: {
		_device = toLower (secondaryWeaponItems _unit #1);
		_knobs = _interfaceState #2;
	};
};
private _deviceC = [_device] call gjb_itn_fnc_hasCompat;
private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;

//Pull interface and relevant data from config
private _interface = getArray (_deviceCfg >> "gjb_itn_interface") #1;
private _offMode = getArray (_deviceCfg >> "gjb_itn_controls") #1 #0;

//Prep ON-state variable
private _isOn = _deviceState #0;
if(_isOn <= 0)then{_isOn = false;}else{_isOn = true;};

//Display interface
createDialog _interface;

if(_interface == "Rsc_gjb_itn_generic_deviceclass")then{
	//Generic Device Menu
		_unit setVariable ["gjb_itn_genDevListLatch",0];
		
		//populate listbox
		private _display = findDisplay 314000;
		private _idB = _display displayCtrl 314096;
		private _modes = getArray (_deviceCfg >> "gjb_itn_deviceModes");
		
		{
			private _modeName = _x #3;
			if(_simpleCtrl == false || _modeName != "OFF")then{
				_idB lbAdd _modeName;
			};
		} forEach _modes;

		//Highlight current mode in listbox
		if(_simpleCtrl == true && _mode > _offMode)then{
			_idB lbSetCurSel (_mode -1);
		}else{
			_idB lbSetCurSel _mode;
		};

		//check onIndic
		private _idO = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
		ctrlShow [_idO,_isOn];
}else{
	//Specific Device Menu

		if(_interfaceState isEqualType 0 || _mode != _interfaceState #0)then{
			//generate new state fresh
			private _knobStates = getArray (configFile >> _interface >> "gjb_itn_knobStates");
			private _ctrlKnobs = getArray (configFile >> _interface >> "controlsBackground");
		}else{
			//populate from last state
			private _lastMode = _interfaceState deleteAt 0;
			{
				private _knobState = _knobStates #_lastMode #(_forEachIndex +1); 
				private _knob = _ctrlKnobs # (_forEachIndex +1);
				private _knobImg = getArray (configFile >> _interface >> _knob) #_knobState;

			} forEach  _interfaceState;

			_interfaceState = [_lastMode] + _interfaceState;
		};

		/* Old method/hide all knobs by default
		private _knobs = getArray (configFile >> _interface >> "controls");
		{
			private _id = getNumber (configFile >> _interface >> _x >> "idc");
			private _ctrl = _x splitString "_";
			private _type = _ctrl #0;
			switch(_ctrl #0)do{
				case "button": {
					ctrlShow [_id,true];
				};
				case "overlay": {
					private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
					ctrlShow [_id,_overlay];
				};	
				case "onIndicator": {
					ctrlShow [_id,_isOn];
				};
				default {
					ctrlShow [_id,false];
				};
			};
		} forEach _knobs;*/

		private _overlay = missionNamespace getVariable ["gjb_itn_setting_interfaceOverlay",false];
		private _idOverlay = getNumber (configFile >> _interface >> _x >> "idc");
		private _idOnIndic = getNumber (configFile >> _interface >> "onIndicator" >> "idc");
		ctrlShow [_idOverlay,_overlay];
		ctrlShow [_idOnIndic,_isOn];
};