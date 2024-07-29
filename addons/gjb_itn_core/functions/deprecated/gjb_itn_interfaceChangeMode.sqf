#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_interfaceChangeMode
//
//	When called from clicked knob, changes knob position to next appropriate
//	position, and then updates deviceState to represent appropriate mode
//
//*****************************************************************************//

params ["_button","_input"];

private _debug = missionNamespace getVariable ["gjb_itn_setting_debug",false];

private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",[0,0,0,0,0,0]];
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
private _deviceC = [_device] call gjb_itn_fnc_hasCompat;
private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;

//pull interface
private _interface = getArray (_deviceCfg >> "gjb_itn_interface") #1;

//Retrieve current knob state and hide knobs
private _knobPos = _unit getVariable "gjb_itn_knobPos";
private _modeHolder = _knobPos deleteAt 0;
{
	if(_x !=99)then{
		private _ctrl = (getArray (configFile >> _interface >> "controls")) # _x;
		private _id = getNumber (configFile >> _interface >> _ctrl >> "idc");
		ctrlShow [_id,false];
	};
} forEach _knobPos;
_knobPos = [_modeHolder] + _knobPos;

//Prepare for handling specific knob change
private _knobStates = getArray (configFile >> _interface >> "gjb_itn_knobStates");
private _knobLimits = _knobStates #0 #_button;
private _knobMin = _knobLimits #0;
private _knobMax = _knobLimits #1;
private _currentKnob = _knobPos #_button;

//Identify new knob position
switch(_input)do{
	//LEFT click
	case 0: {
		if(_currentKnob < (_knobMax))then{
			private _newKnob = _currentKnob +1;
			_knobPos set [_button,_newKnob];
			playSound "click";
		};
	};
	//RIGHT click
	case 1: {
		if(_currentKnob > (_knobMin))then{
			private _newKnob = _currentKnob -1;
			_knobPos set [_button,_newKnob];
			playSound "click";
		};
	};
};

//Fix a first-run error with turning knobs
private _index = _knobPos findIf {_x ==99};
if(_index !=-1)then{
	_knobPos set [_index,(_knobStates #0 #_index) #0];
};

//Identify appropriate mode from knob positions
private _totalButtons = (count (_knobStates #0)) -1;
private _knobCheck = _knobStates select [1,100];
/*private _knobCheck = +_knobStates;
_knobCheck deleteAt 0;*/
private _newMode = -1;
switch(_totalButtons)do{
	case 1: {
		_state = [];
		{
			if (_x #1 == _knobPos #1 || _x #1 ==99) then {
					_state pushBackUnique _x;
				};
		} forEach _knobCheck;
		_newMode = flatten _state #0;
	};
	case 2: {
		_state = [];
		{
			if ((_x #1 == _knobPos #1 || _x #1 ==99) &&
				(_x #2 == _knobPos #2 || _x #2 ==99)) then {
					_state pushBackUnique _x;
				};
		} forEach _knobCheck;
		_newMode = flatten _state #0;
	};
	case 3: {
		_state = [];
		{
			if ((_x #1 == _knobPos #1 || _x #1 ==99) &&
				(_x #2 == _knobPos #2 || _x #2 ==99) &&
				(_x #3 == _knobPos #3 || _x #3 ==99)) then {
					_state pushBackUnique _x;
				};
		} forEach _knobCheck;
		_newMode = flatten _state #0;
	};
	//add more AS NECESSARY! Or make self-building system...
};

_knobPos set [0,_newMode];

//Update variables
_unit setVariable ["gjb_itn_knobPos",_knobPos];

_deviceState set [4,_newMode];
_unit setVariable ["gjb_itn_deviceState",_deviceState,true];

//Initiate update to modeSpec and interface knobs
[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
[_unit,_newMode,_interface] call gjb_itn_fnc_getInterfaceKnobs;