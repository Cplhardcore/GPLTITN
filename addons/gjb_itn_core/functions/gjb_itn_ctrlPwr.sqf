#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_ctrlPwr
//	controls device activation state
//
//	this script is only called by client FOR player, but will
//	transmit results to all devices via gjb_itn_deviceState
//
//	_keyDir
//		0 = key down
//		1 = key up
//		2 = called from GUI
//
//
//	_mode
//		0 = toggle device between off and on
//		1 = on portion of momentary-on
//		2 = off portion of momentary-on
//	_isDP
//		0 = key is not dual-purpose
//		1 = key is dual-purpose, and will function as momOn only if held for < 0.5s
//
//*****************************************************************************//

//params ["_mode","_isDP"];
params ["_keyDir","_override"];

//Shortstop if player is in zeus menu
if (!isNull findDisplay 312) exitWith {false};

private _unit = call CBA_fnc_currentUnit;
private _deviceState = _unit getVariable ["gjb_itn_deviceState",0];

//Ensures device is defaulted if first activation
if(!(_deviceState isEqualType []))then{
	_deviceState = [_unit] call gjb_itn_fnc_initMode;
};


//If simplified controls is not active and device has its own control script, redirect to that
private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];
private _currentDevice = _unit getVariable ["gjb_itn_currentDevice",""];
if(_currentDevice == "")exitWith{};

private _config = configFile >> "CfgITNCompat" >> "accessories" >> _currentDevice;
private _exit = false;
private _genTog = false;
private _xm8Fix = false;
if(_simpleCtrl == false)then{
	private _controller = "";
	if(isClass _config)then{
		_controller = getArray (_config >> "gjb_itn_interface") #0;
	};
	if(_override == 1.1)then{
		_controller = "generic";
		_override = 1;
		_genTog = true;
	};
	switch(_controller)do{
		case "dbal_a2":{
			private _dbala2MomState = _unit getVariable ["gjb_itn_dbala2MomState", 1];
			if(_dbala2MomState == 1)then{
				["keys",_keyDir,"k"] call gjb_itn_fnc_deviceDbalA2;
			};
			_exit = true;
		};
		case "peq_15":{
			["keys",_keyDir,"k"] call gjb_itn_fnc_devicePeq15;
			_exit = true;
		};
		case "peq_16":{
			["keys",_keyDir,"k"] call gjb_itn_fnc_devicePeq16;
			_exit = true;
		};
		case "peq_15_combo":{
			["keys",_keyDir,"k"] call gjb_itn_fnc_devicePeq15Combo;
			_exit = true;
		};
		/*case "perst3":{
			//has tap/hold activation, but 2x activates a strobe. Holder for when strobes implemented
			["keys",_keyDir,"k"] call gjb_itn_fnc_devicePerst3;
		};*/
		case "perst3_combo":{
			//has tap/hold activation, but 2x activates a strobe. Holder for when strobes implemented
			["keys",_keyDir,"k"] call gjb_itn_fnc_devicePerst3Combo;
			_exit = true;
		};
		case "peq_2_combo":{
			["keys",_keyDir,"k"]  call gjb_itn_fnc_devicePeq2Combo;
			_exit = true;
		};
		case "llm_mk3":{
			//keybind acts as pressure switch, ignores previous state from buttons, only follows knob pos
			["keys",_keyDir,"k"]  call gjb_itn_fnc_deviceLLMmk3;
			_exit = true;
		};
		case "la_5b":{
			["keys",_keyDir,"k"] call gjb_itn_fnc_deviceLA5B;
			_exit = true;
		};
		case "la_5b_combo":{
			["keys",_keyDir,"k"] call gjb_itn_fnc_deviceLA5BCombo;
			_exit = true;
		};
		case "ngal":{
			["keys",_keyDir,"k"] call gjb_itn_fnc_deviceNGAL;
			_exit = true;
		};
		case "ngal_combo":{
			["keys",_keyDir,"k"] call gjb_itn_fnc_deviceNGALCombo;
			_exit = true;
		};
		case "xm8":{
			_xm8Fix = true;
		};
		default {};
	};
};

private _deviceCtrls = getArray (_config >> "gjb_itn_controls");
private _fullOff = _deviceCtrls #1 #0;
if(_deviceState #4 == _fullOff)then{
	_exit = true;
};

if(_exit) exitWith {};

//Adjust for auto-mode condition
private _mode = -1;
private _isDp = 0;
private _autoMode = missionNamespace getVariable ["gjb_itn_setting_autoOn",0];

private _setting = 2; //This used to be a setting, it MAY return later, who knows.

if(_autoMode == 0 || _override == 1)then{
	if(_keyDir == 2)then{
		_mode = 0;
	}else{
		switch(_setting)do{
			case 0: {
				if(_keyDir == 0)then{
					_mode = 0;
				};
			};
			case 1: {
				_mode = _keyDir + 1;
			};
			case 2: {
				_mode = _keyDir + 1;
				_isDp = 1;
			};
		};
	};

	private _state = +_deviceState #0;
	private _time = time;
	private _sTime = _unit getVariable ["gjb_itn_dpTimer",-1];

	//assign behavior depending on input
	switch(_mode)do{
		case 0:{	//toggle on/off
			if (_state > 0) then {
				private _invert = -(_state);
				_deviceState set [0,_invert];
				playSound "ClickSoft";
			} else {
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
			//toggles on indicator for generic menu
			if(_genTog)then{
				private _onButton = (findDisplay 314000) displayCtrl 989;
				if((_deviceState #0) > 0)then{
					_onButton ctrlSetTextColor [1,0.8,0.2,1];
				}else{
					_onButton ctrlSetTextColor [
						(profileNamespace getVariable ['igui_text_rgb_r',0.13]),
						(profileNamespace getVariable ['igui_text_rgb_g',0.54]),
						(profileNamespace getVariable ['igui_text_rgb_b',0.21]),
						(profileNamespace getVariable ['igui_text_rgb_a',0.8])
					];
				};
				private _list = (findDisplay 314000) displayCtrl 1000;
				ctrlSetFocus _list;
			};
		};
		case 1:{	//key-down is on, starts timer if using dual purpose keybind
			if(_isDP == 1)then{
				_sTime = +_time;
				_unit setVariable ["gjb_itn_dpTimer",_sTime];
				_unit setVariable ["gjb_itn_dpState",_state];
			};
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
		case 2:{	//key-up is off, adjusts behavior depending on time pressed if using dual purpose keybind
			if(_isDP == 1)then{
				_time = time;
				private _hold = _time - _sTime;
				if(_hold <= 0.5)then{
					private _dpState = _unit getVariable ["gjb_itn_dpState",-1];
					if(_dpState > 0)then{
						private _invert = -(_state);
						_deviceState set [0,_invert];
					}else{
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
					};
				}else{
					private _invert = -(_state);
					_deviceState set [0,_invert];
					playSound "ClickSoft";
				};
				_unit setVariable ["gjb_itn_dpTimer",nil];
				_unit setVariable ["gjb_itn_dpState",nil];
			}else{
				private _invert = -(_state);
				_deviceState set [0,_invert];
			};
		};
	};
	//handle XM8 (CUP) flashlight toggle switch
	if(_xm8Fix)then{
		private _base = getArray (_config >> "gjb_itn_interface") #2;
		private _file = "base_off_co.paa";
		if(_deviceState #0 > 0)then{
			_file = "base_on_co.paa";
		};
		private _baseFile = [_base,"\",_file] joinString "";
		ctrlSetText [1000,_baseFile];
	};
	//Set  interface onIndicator as appropriate
	if(_deviceState #0 > 0)then{
		ctrlShow [999,true];
	}else{
		ctrlShow [999,false];
	};
	_unit setVariable ["gjb_itn_deviceState",_deviceState, true];
}else{
	if(_keyDir == 2)then{
		[_autoMode] call gjb_itn_fnc_autoPwr;
	};
};