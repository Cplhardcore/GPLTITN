#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_modeSpec
//
//	takes gjb_itn_deviceState as input, compares current
//	device with list, and outputs device-specific values
//	for laser, illuminator, or flashlight outputs.
//
//	Local use only, no broadcast!!
//
//	_deviceState
//
//*****************************************************************************//

params ["_unit","_deviceState"];

//check if device mode has changed since last run
private _last = _unit getVariable ["gjb_itn_lastConfig",["?","?","?","?",0,0,0]];
private _dS = _deviceState #4;
private _w = currentWeapon _unit;

//retrieve device mode information
private _deviceC = _unit getVariable ["gjb_itn_currentDevice",0];
if(_deviceC isEqualType 0)then{
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
	_deviceC = [_device] call gjb_itn_fnc_hasCompat;
	_unit setVariable ["gjb_itn_currentDevice",_deviceC]
};

private _deviceCfg = configFile >> "CfgITNCompat" >> "accessories" >> _deviceC;
private _modes = getArray (_deviceCfg >> "gjb_itn_deviceModes");
private _mode = [];
if(count _modes > 0)then{
	_mode = _modes select _dS;
	
	//convert device mode into laser specs, if laser is on
	if ((_mode #0) == 0)then{
		_deviceState set [1,0];
	}else{
		private _lasMode = _mode #0;
		private _lasSpec = (getArray (_deviceCfg >> "gjb_itn_deviceSpecs")) select _lasMode;
		private _boolean = _lasSpec #5;
		if(_boolean == 1)then{
			_lasSpec set [5,true];
		}else{
			_lasSpec set [5,false];
		};
		_unit setVariable ["gjb_itn_lasSpec",_lasSpec];
		_deviceState set [1,1];
	};

	//convert device mode into illuminator specs, if illuminator is on
	private _illumState = _deviceState #2;
	private _negate = -_illumState;
	if ((_mode #1) == 0)then{
		if(_illumState > 0)then{
			_deviceState set [2,_negate];
		};
	}else{
		//set maximum beam angle
		private _maxBeamAngle = 0.01;
		private _adjIllum = false;
		private _illumCtrls = getArray (_deviceCfg >> "gjb_itn_controls") #2;
		if((count _illumCtrls ) >= 3)then{
			_maxBeamAngle = (_illumCtrls #2) / 1000;
			_adjIllum = true;
		}else{
			if(_illumCtrls #0 == 1 || _illumCtrls #1 == 1)then{
				_adjIllum = true;
			};
		};
		switch(true)do{
			case (_illumState == 0): {
				_illumState = 1 + _maxBeamAngle;
			};
			case (_illumState < 0): {
				_illumState = _negate;
			};
			default{};
		};
		if(_illumState > 1 + _maxBeamAngle && _illumState < 1.1)then{
			_illumState = 1 + _maxBeamAngle;
		};
		//harden LLMmk3 against bad illum settings from previous device
		private _controller = getArray (_deviceCfg >> "gjb_itn_interface") #0;
		if(_controller == "llm_mk3" && !(_illumState == 1.001 || _illumState == 1.004 || _illumState == 1.009 || _illumState == 1.109))then{
			switch(true)do{
				case (_illumState <= 1.003): {
					_illumState = 1.001;
				};
				case (_illumState > 1.003 && _illumState <= 1.007):{
					_illumState = 1.004;
				};
				case (_illumState > 1.007 && _illumState < 1.1):{
					_illumState = 1.009;
				};
				case (_illumState>= 1.1):{
					_illumState = 1.109;
				};
			};
		};
		//determine appropriate illuminator
		private _illumMode = _mode #1;
		private _illumSpec = (getArray (_deviceCfg >> "gjb_itn_deviceSpecs")) select _illumMode;
		if(_illumState != 1 && _adjIllum)then{
			private _focus = _illumSpec splitString "_";
			private _index = (count _focus) -2;
			switch(true)do{
				case (_illumState > 1.1):{
					_focus set [_index,"60"];
				};
				case (_illumState > 1 && _illumState <=1.1):{
					private _focusMode = str _illumState;
					_focusMode = _focusMode splitString "";
					if((count _focusMode) == 5)then{
						_focusMode = [_focusMode #3, _focusMode #4] joinString "";
					}else{
						_focusMode = [_focusMode #3,"0"] joinString "";
					};
					_focus set [_index,_focusMode];
				};
			};
			_illumSpec = _focus joinString "_";
		};
		_deviceState set [2,_illumState];
		_unit setVariable ["gjb_itn_illumSpec",_illumSpec];
	};

	//convert device mode into flashlight specs, if light is on
	if ((_mode #2) == 0)then{
		_deviceState set [3,0];
	}else{
		private _flashMode = _mode #2;
		private _flashSpec = (getArray (_deviceCfg >> "gjb_itn_deviceSpecs")) select _flashMode;
		_unit setVariable ["gjb_itn_flashSpec",_flashSpec];
		_deviceState set [3,1];
	};

	//turns off device if passing thru FULL OFF mode, if applicable
	private _fullOff = (getArray (_deviceCfg >> "gjb_itn_controls")) #1 #0;
	if(_dS == _fullOff)then{
		_deviceState set [0,0];
	};
	_last set [4,_dS];
}else{
	_unit setVariable ["gjb_itn_lasSpec",nil];
	_unit setVariable ["gjb_itn_illumSpec",nil];
	_unit setVariable ["gjb_itn_flashSpec",nil];
	_deviceState set [0,0];
	_deviceState set [1,0];
	_deviceState set [2,0];
	_deviceState set [3,0];
	_deviceState set [4,0];
	_last set [4,0];
};

//Toggle interface onIndicator appropriately
if(_deviceC != "")then{
	private _dOn = _deviceState #0;
	private _interface = getArray (_deviceCfg >> "gjb_itn_interface") #1;
	private _idd = getNumber (configFile >> _interface >> "idd");
	if(!isNull findDisplay _idd)then{
		private _fullOff = (getArray (_deviceCfg >> "gjb_itn_controls")) #1 #0;
		if(_dOn > 0 && _dOn != 3 && _dS != _fullOff)then{
			ctrlShow [999,true];
		}else{
			ctrlShow [999,false];
		};
	};
};
//updates deviceState variable globally if _unit is local to machine
if(local _unit)then{
	_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
};

_last set [0,_w];

//systemChat format ["Mode Spec:: %2 :: %1",systemTime #6,_last #0];

_unit setVariable ["gjb_itn_lastConfig",_last];

//tells gjb_itn_fnc_checkBucket that script has finished running
_unit setVariable ["gjb_itn_checker",false];