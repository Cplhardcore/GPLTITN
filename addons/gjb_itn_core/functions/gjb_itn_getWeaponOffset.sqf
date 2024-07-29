#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_getWeaponOffset
//
//	Determines and stores model space coordinates of weapon's accessory proxy
//	and saves device states for weapon categories when swapping
//
//	this script is only called by client FOR player (or local AI), but will
//	transmit results to all devices, IF run in full, via
//	gjb_itn_deviceOffset and gjb_itn_deviceState.
//
//*****************************************************************************//

params ["_unit","_deviceState"];

private _last = _unit getVariable ["gjb_itn_lastConfig",["?","?","?","?",0,0,0]];
private _debug = missionNamespace getVariable ["gjb_itn_setting_debug",false];
/*if(_debug)then{
	systemChat "getWeaponOffset Start";
};*/

private _w = currentWeapon _unit;
private _aP = primaryWeaponItems _unit #1;
private _aH = handgunItems _unit #1;
private _aL = secondaryWeaponItems _unit #1;

//This stops weapon-sling mods from defaulting primary device's mode after swap
private _crowSling = _unit getVariable ["crow_sling",false];
switch(true)do{
	case ((primaryWeapon _unit) == "Rifle");	//GGE, find Goobin's variable!
	case (_crowSling): {													//Crow's Weapon Slinging
		_aP = _last #1;
	};
};

private _defaultState = [0,0,0,0,0,0];

//Store device state for non-selected systems
//determine previous system
private _oldSys = _last #6;

//record current _deviceState to appropriate holder, or reset state if it has changed
private _oldState = +_deviceState;
switch(_oldSys)do{
	case 0: {	//rifles
		if(_aP != _last #1)then{
			_unit setVariable ["gjb_itn_stateHolderRifle",_defaultState];
		}else{
			_oldstate set [0,0];
			_unit setVariable ["gjb_itn_stateHolderRifle",_oldState];
		};
	};
	case 1: {	//pistols
		if(_aH != _last #2)then{
			_unit setVariable ["gjb_itn_stateHolderPistol",[0,0,0,0,0,1]];
		}else{
			_oldstate set [0,0];
			_unit setVariable ["gjb_itn_stateHolderPistol",_oldState];
		};
	};
	case 2: {	//launchers
		if(_aL != _last #3)then{
			_unit setVariable ["gjb_itn_stateHolderLauncher",[0,0,0,0,0,2]];
		}else{
			_oldstate set [0,0];
			_unit setVariable ["gjb_itn_stateHolderLauncher",_oldState];
		};
	};
	case 3: {	//binoculars
		_oldstate set [0,0];
	};
	case -1: {	//empty hands
		_oldstate set [0,0];
	};
};

/*if(_debug)then{
	systemChat "Old mode stored";
};*/

//Identify weapon system's accessory offset and player model proxy,
//retrieve appropriate device state for system
private _cfgW = configFile >> "CfgWeapons" >> _w;
private _t = getNumber(_cfgW >> "type");
private _cfgWc = configFile >> "CfgITNCompat" >> "weapons" >> _w;
_memPoints = _cfgWc >> "gjb_itn_memoryPoints";
if(!isArray _memPoints)then{
	private _memPoints = _cfgW >> "gjb_itn_memoryPoints";
};
private _woff = [0,0,0];
private _prox = "";	
private _newState = [];
private _newSys = -1;
switch(_t)do{
	case 1: {	//rifles
		if(isArray _memPoints)then{
			_woff = (getArray _memPoints) #0;
			if(_debug)then{systemChat format ["Weapon Config Used: %1",_woff];};
		}else{
			private _mW = getText(_cfgW >> "model");
			private _mWstr = _mW splitString "";
			if(_mWstr #0 == "\")then{
				_mWstr deleteAt 0;
				_mW = _mWstr joinString "";
			};
			private _oW = createSimpleObject [_mW, [0,0,0], true];
			_woff = _oW selectionPosition ["proxy:\a3\data_f\proxies\weapon_slots\side.001", 1];
			if(_woff #0 == 0 && _woff #1 == 0 && _woff #2 == 0)then{
				_woff = _oW selectionPosition ["proxy:\a3\data_f\proxies\weapon_slots\side.001", 2];
			};
			deleteVehicle _oW;
		};
		_prox = "proxy:\a3\characters_f\proxies\weapon.001";
		_newState = _unit getVariable ["gjb_itn_stateHolderRifle",_defaultState];
		_newSys = 0;
	};
	case 2: {	//pistols
		if(isArray _memPoints)then{
			_woff = (getArray _memPoints) #0;
			if(_debug)then{systemChat "Weapon Config Used";};
		}else{
			private _mW = getText(_cfgW >> "model");
			private _mWstr = _mW splitString "";
			if(_mWstr #0 == "\")then{
				_mWstr deleteAt 0;
				_mW = _mWstr joinString "";
			};
			private _oW = createSimpleObject [_mW, [0,0,0], true];
			_woff = _oW selectionPosition ["proxy:\a3\data_f\proxies\weapon_slots\side.002", 1];
			if(_woff #0 == 0 && _woff #1 == 0 && _woff #2 == 0)then{
				_woff = _oW selectionPosition ["proxy:\a3\data_f\proxies\weapon_slots\side.002", 2];
			};
			deleteVehicle _oW;
		};
		_prox = "proxy:\a3\characters_f\proxies\pistol.001";
		_defaultState set [5,1];
		_newState = _unit getVariable ["gjb_itn_stateHolderPistol",_defaultState];
		_newSys = 1;
	};
	case 4: {	//launchers
		if(isArray _memPoints)then{
			_woff = (getArray _memPoints) #0;
			if(_debug)then{systemChat "Weapon Config Used";};
		}else{
			private _mW = getText(_cfgW >> "model");
			private _mWstr = _mW splitString "";
			if(_mWstr #0 == "\")then{
				_mWstr deleteAt 0;
				_mW = _mWstr joinString "";
			};
			private _oW = createSimpleObject [_mW, [0,0,0], true];
			_woff = _oW selectionPosition ["proxy:\a3\data_f\proxies\weapon_slots\side.001", 1];
			if(_woff #0 == 0 && _woff #1 == 0 && _woff #2 == 0)then{
				_woff = _oW selectionPosition ["proxy:\a3\data_f\proxies\weapon_slots\side.001", 2];
			};
			deleteVehicle _oW;
		};
		_prox = "proxy:\a3\characters_f\proxies\launcher.001";
		_defaultState set [5,2];
		_newState = _unit getVariable ["gjb_itn_stateHolderLauncher",_defaultState];
		_newSys = 2;
	};
	case 4096: {//binoculars
		_prox = "proxy:\a3\characters_f\proxies\binoculars.001";
		_defaultState set [5,3];
		_newState = _defaultState;
		_newSys = 3;
	};
	case 0: {	//empty hands
		_defaultState set [5,-1];
		_newState = _defaultState;
	};
};

/*if(_debug)then{
	systemChat format ["Weapon's offset retrieved: %1, %2",_woff,_prox];
};*/

//Record offsets and retrieved device state onto object nameSpace variables and broadcast appropriately
private _posData = _unit getVariable ["gjb_itn_deviceOffset",[[0,0,0],[0,0,0],[0,0,0],[0,0,0],"?"]];
_posData set [3,_woff];
_posData set [4,_prox];

_last set [0,_w];
_last set [6,_newSys];

_newState set [5,_newSys];

/*if(_debug)then{
	_gTime = time;
	systemChat format ["%1: %2",_gTime,_newState];
};*/

//Runs gjb_itn_fnc_getDeviceOffset to immediately compute updated final offsets
[_unit,_newState,_last,_posData] call gjb_itn_fnc_getDeviceOffset;