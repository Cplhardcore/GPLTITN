#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_getInterfaceKnobs
//
//	Determines the appropriate position for interface knobs according to current
//	device mode, then shows appropriate knobs
//
//*****************************************************************************//

params ["_unit","_mode","_interface"];

//Collect previous states
private _knobState = _unit getVariable ["gjb_itn_knobPos",-1];	//NEED track multiple device knob states
private _lastMode = -1;
private _cfgRsc = configFile >> _interface;

//Fix some oddities...
if(_knobState isEqualType [])then{
	private _vals = count (getArray (_cfgRsc >> "gjb_itn_knobStates") #0);
	if((count _knobState) == _vals)then{
		_lastMode = _knobState deleteAt 0;
	};
};

//Check if no change from last run
if((_knobState isEqualType []) && _lastMode == _mode)then{
	// Apply knobState
	{
		private _ctrl = (getArray (_cfgRsc >> "controls")) # _x;
		private _id = getNumber (configFile >> _interface >> _ctrl >> "idc");
		ctrlShow [_id,true];
	} forEach _knobState;
	_knobState = [_mode] + _knobState;
}else{
	// Build new knobState from deviceState
	private _knobStateList = getArray (_cfgRsc >> "gjb_itn_knobStates");
	private _knobMode = _knobStateList findIf {(_x #0) == _mode};
	_knobMode = _knobStateList # _knobMode;
	if(99 in _knobMode)then{
		private _index = _knobMode findIf {_x == 99};
		private _newMode = "Alphabet";
		if(_knobState isEqualType [])then{
			_newMode = _knobState #(_index -1);
		}else{
			private _defaultKnob = _knobStateList #0 #_index #0;
			_newMode = _defaultKnob;
		};
		_knobMode set [_index,_newMode];
	};
	_knobMode deleteAt 0;
	//DBAL-A2 power switch mode regulator
	if(_interface == "Rsc_gjb_itn_dbala2")then{
		private _dbalMoment = _unit getVariable ["gjb_itn_dbala2MomState", 1];
		switch(true)do{
			case (_knobMode #0 == 0 && _dbalMoment == 1):{
				_knobMode set [0,1];
			};
			case (_knobMode #0 == 1 && _dbalMoment == 0):{
				_knobMode set [0,0];
			};
			case (_knobMode #0 == 3 && _dbalMoment == 0):{
				_knobMode set [0,4];
			};
			case (_knobMode #0 == 4 && _dbalMoment == 1):{
				_knobMode set [0,3];
			};
		};
	};
	{
		if(_x != 99)then{
			private _ctrl = (getArray (_cfgRsc >> "controls")) # _x;
			private _id = getNumber (configFile >> _interface >> _ctrl >> "idc");
			ctrlShow [_id,true];
		};
	} forEach _knobMode;
	_knobState = [_mode] + _knobMode;
};
_unit setVariable ["gjb_itn_knobPos",_knobState];