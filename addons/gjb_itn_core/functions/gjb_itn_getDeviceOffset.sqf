#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_getDeviceOffset
//
//	Determines proper position of emitters in model space
//
//	this script is only called by client FOR player (or local AI), but will
//	transmit results to all devices, IF run in full, via
//	gjb_itn_deviceOffset and gjb_itn_deviceState.
//
//*****************************************************************************//

params ["_unit","_deviceState","_last","_posData"];

if(!(_last isEqualType []))then{
	_last = _unit getVariable ["gjb_itn_lastConfig",["?","?","?","?",0,0,0]];
};
if(!(_posData isEqualType []))then{
	_posData = _unit getVariable ["gjb_itn_deviceOffset",[[0,0,0],[0,0,0],[0,0,0],[0,0,0],"?"]];
};

private _debug = missionNamespace getVariable ["gjb_itn_setting_debug",false];

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

//Identify which laser device is currently being looked at and default its mode if it is new
private _deviceCategory = _deviceState #5;
private _redefault = false;
private _cfg = configFile >> "CfgITNCompat" >> "accessories";
private _cfgAc = -1;
private _a = -1;
private _aC = -1;
switch(_deviceCategory)do{
	case 0: {
		_aC = [_aP] call gjb_itn_fnc_hasCompat;
		_cfgAc = _cfg >> _aC;
		_lastD = _last#1;
		if(_lastD != _aP || _lastD == "?")then{
			_redefault = true;
			_unit setVariable ["gjb_itn_knobPos",-1];
		};
		_a = _aP;
	};
	case 1: {
		_aC = [_aH] call gjb_itn_fnc_hasCompat;
		_cfgAc = _cfg >> _aC;
		_lastD = _last#2;
		if(_lastD != _aH || _lastD ==  "?")then{
			_redefault = true;
		};
		_a = _aH;
	};
	case 2: {
		_aC = [_aL] call gjb_itn_fnc_hasCompat;
		_cfgAc = _cfg >> _aC;
		_lastD = _last#3;
		if(_lastD != _aL || _lastD ==  "?")then{
			_redefault = true;
		};
		_a = _aL;
	};
	case 3;
	case -1: {
		_a = [currentWeapon _unit] call gjb_itn_fnc_hasCompat;
		_cfgAc = _cfg >> _a;
		_redefault = true;
	};
};

//systemChat format ["Device Offset :: %1",systemTime #6];

//if new device, default modes
if(_redefault == true)then{
	private _default = 0;
	if(_a != "")then{
		private _controls = getArray (_cfgAc >> "gjb_itn_controls"); 
		_default =  _controls #0;
		//Set default mode to IR if Simple Controls
		private _simpleCtrl = missionNamespace getVariable ["gjb_itn_setting_simpleCtrl",false];
		private _choose = 0;
		if(_simpleCtrl == true)then{
			_choose = 1;
		}/*else{
			_choose = 0;
		}*/;
		_default = _default #_choose;
	};
	_deviceState set [4,_default];
	_deviceState set [0,0];
};

// Save current device name for quick retrieval
_unit setVariable ["gjb_itn_currentDevice",_aC,true];

//Set vanilla override, if appropriate
private _vanillaOverrideC = getNumber  (_cfgAc >> "gjb_itn_vanillaOverride");
private _vanillaOverrideW = getNumber  (configFile >> "CfgWeapons" >> _a >> "gjb_itn_vanillaOverride");
if(_vanillaOverrideC == 1 || _vanillaOverrideW == 1)then{
	player setVariable ["gjb_itn_vanillaOverride",true,true];
}else{
	player setVariable ["gjb_itn_vanillaOverride",false,true];
};

//Identify accessory device's relevant memory point offsets and combine with weapon offset
private _mLas = -1; private _mIllum = -1; private _mFlash = -1;
private _pLas = [0,0,0]; private _pIllum = [0,0,0]; private _pFlash = [0,0,0];
private _woff = _posData #3;

//Get offset coordinates
if(!isArray (_cfgAc >> "gjb_itn_memoryPoints"))then{
	private _cfgAw = ConfigFile >> "CfgWeapons" >> _a;
	_mLas = getText (_cfgAw >> "ItemInfo" >> "Pointer" >> "irLaserPos");
	_mIllum = getText (_cfgAw >> "ItemInfo" >> "Pointer" >> "irLaserPos");
	_mFlash = getText (_cfgAw >> "ItemInfo" >> "Flashlight" >> "position");
	//coordinates need generation!
	private _mA = getText(_cfgAw >> "model");
	private _mAstr = _mA splitString "";
	//createSimpleObject apparently cannot have a leading "\" for the model
	if(_mAstr #0 == "\")then{
		_mAstr deleteAt 0;
		_mA = _mAstr joinString "";
	};
	private _oA = createSimpleObject [_mA, [0,0,0], true];
	if(_mLas != "")then{
		_pLas = _oA selectionPosition [_mLas, "memory"];
	};
	if(_mIllum != "")then{
		_pIllum = _oA selectionPosition [_mIllum, "memory"];
	};
	if(_mFlash != "")then{
		_pFlash = _oA selectionPosition [_mFlash, "memory"];
	};
	deleteVehicle _oA;
}else{
	private _mAc = getArray (_cfgAc >> "gjb_itn_memoryPoints");
	//coordinates are stored in config!
	_pLas = _mAc #0;
	_pIllum = _mAc #1;
	_pFlash = _mAc #2;
	if(_debug)then{systemChat "Device Config Used";};
};


//for fixing irregular rails
private _w = currentWeapon _unit;
private _cfgWc = configFile >> "CfgITNCompat" >> "weapons" >> _w;
private _nsrf = getText (_cfgWc >> "gjb_itn_nonStdRailFix");
private _bff = getNumber (_cfgWc >> "gjb_itn_beltFedFix");

//Correct device offsets for host platform type and special cases
switch(_deviceCategory)do{
	case 0: {	//Rifles
		switch(_nsrf)do{
			case "bottomRailOnly": {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasX = (_pLas #0) *-0.9;	//squash so laser emits inside device
					private _pLasY = (_pLas #1) *-1;	//correct for bottom rail 90* rot
					private _pLasZ = (_pLas #2);	//correct for bottom rail 90* rot
					_pLas set [0,_pLasX];
					_pLas set [2,_pLasY];	// Y - Z
					_pLas set [1,_pLasZ];	// Z + Y
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumX = (_pIllum #0) *-1;
					private _pIllumY = (_pIllum #1) *-1;
					private _pIllumZ = (_pIllum #2);
					_pIllum set [0,_pIllumX];
					_pIllum set [2,_pIllumY];	// Y - Z
					_pIllum set [1,_pIllumZ];	// Z + Y
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashX = (_pFlash #0) *-1;
					private _pFlashY = (_pFlash #1) *-1;
					private _pFlashZ = (_pFlash #2);
					_pFlash set [0,_pFlashX];
					_pFlash set [2,_pFlashY];	// Y - Z
					_pFlash set [1,_pFlashZ];	// Z + Y};
			};
			case "topRailOnly": {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasX = (_pLas #0) *-0.9;	//squash so laser emits inside device
					private _pLasY = (_pLas #1);	//correct for top rail 90* rot
					private _pLasZ = (_pLas #2) *-1;	//correct for top rail 90* rot
					_pLas set [0,_pLasX];
					_pLas set [2,_pLasY];	// Y + Z
					_pLas set [1,_pLasZ];	// Z - Y
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumX = (_pIllum #0) *-1;
					private _pIllumY = (_pIllum #1);
					private _pIllumZ = (_pIllum #2) *-1;
					_pIllum set [0,_pIllumX];
					_pIllum set [2,_pIllumY];	// Y + Z
					_pIllum set [1,_pIllumZ];	// Z - Y
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashX = (_pFlash #0) *-1;
					private _pFlashY = (_pFlash #1);
					private _pFlashZ = (_pFlash #2) *-1;
					_pFlash set [0,_pFlashX];
					_pFlash set [2,_pFlashY];	// Y + Z
					_pFlash set [1,_pFlashZ];	// Z - Y
			};
			case "leftRailOnly": {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasX = (_pLas #0) *-0.9;	//squash so laser emits inside device
					private _pLasY = (_pLas #1) *-1;	//correct for left rail 180* rot
					private _pLasZ = (_pLas #2) *-1;	//correct for left rail 180* rot
					_pLas set [0,_pLasX];
					_pLas set [1,_pLasY];
					_pLas set [2,_pLasZ];
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumX = (_pIllum #0) *-1;
					private _pIllumY = (_pIllum #1) *-1;
					private _pIllumZ = (_pIllum #2) *-1;
					_pIllum set [0,_pIllumX];
					_pIllum set [1,_pIllumY];
					_pIllum set [2,_pIllumZ];
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashX = (_pFlash #0) *-1;
					private _pFlashY = (_pFlash #1) *-1;
					private _pFlashZ = (_pFlash #2) *-1;
					_pFlash set [0,_pFlashX];
					_pFlash set [1,_pFlashY];
					_pFlash set [2,_pFlashZ];
			};/*
			case "avalon": {
				private _pLasX = (_pLas #0) *0.9;	//squash so laser emits inside device
				private _pLasY = _pLas #1;
				private _pLasZ = _pLas #2;
				_pLas set [0,_pLasX];
				_pLas set [2,_pLasY];
				_pLas set [1,_pLasZ];
			//Illuminators
				private _pIllumX = _pIllum #0;
				private _pIllumY = _pIllum #1;
				private _pIllumZ = _pIllum #2;
				_pIllum set [0,_pIllumX];
				_pIllum set [2,_pIllumY];
				_pIllum set [1,_pIllumZ];
			//Flashlights
				private _pFlashX = _pFlash #0;
				private _pFlashY = _pFlash #1;
				private _pFlashZ = _pFlash #2;
				_pFlash set [0,_pFlashX];
				_pFlash set [2,_pFlashY];
				_pFlash set [1,_pFlashZ];
			};*/
			case "rawPos": {
				//Lasers
					/*private _pLasT = (_pLas #0) *0.9;
					_pLas set [0,_pLasT];*/
				//Illuminators
				//Flashlights
			};
			default {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasT = (_pLas #0) *-0.9;
					_pLas set [0,_pLasT];
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumT = (_pIllum #0) *-1;
					_pIllum set [0,_pIllumT];
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashT = (_pFlash #0) *-1;
					_pFlash set [0,_pFlashT];
			};
		};
		if(isNumber (_cfgWc >> "gjb_itn_beltFedFix"))then{
			private _pLasT = (_pLas #0) - _bff;
			_pLas set [0,_pLasT];
		};
	};
	case 1: {	//pistols
		switch(_nsrf)do{
			case "rifleNotPistol": {	//treat as rifle
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasT = (_pLas #0) *-0.9;
					_pLas set [0,_pLasT];
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumT = (_pIllum #0) *-1;
					_pIllum set [0,_pIllumT];
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashT = (_pFlash #0) *-1;
					_pFlash set [0,_pFlashT];
			};
			default {
					private _pLasT = (_pLas #0) *0.1;	//squash so laser emits inside device
					_pLas set [0,_pLasT];
				//Illuminators on pistols do not need correcting
				//Flashlights on pistols do not need correcting
			};
		};
	};
	case 2: {	//launchers
		switch(_nsrf)do{
			case "bottomRailOnly": {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasX = (_pLas #0) *-0.9;	//squash so laser emits inside device
					private _pLasY = (_pLas #1) *-1;	//correct for bottom rail 90* rot
					private _pLasZ = (_pLas #2);	//correct for bottom rail 90* rot
					_pLas set [0,_pLasX];
					_pLas set [2,_pLasY];	// Y - Z
					_pLas set [1,_pLasZ];	// Z + Y
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumX = (_pIllum #0) *-1;
					private _pIllumY = (_pIllum #1) *-1;
					private _pIllumZ = (_pIllum #2);
					_pIllum set [0,_pIllumX];
					_pIllum set [2,_pIllumY];	// Y - Z
					_pIllum set [1,_pIllumZ];	// Z + Y
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashX = (_pFlash #0) *-1;
					private _pFlashY = (_pFlash #1) *-1;
					private _pFlashZ = (_pFlash #2);
					_pFlash set [0,_pFlashX];
					_pFlash set [2,_pFlashY];	// Y - Z
					_pFlash set [1,_pFlashZ];	// Z + Y};
			};
			case "topRailOnly": {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasX = (_pLas #0) *-0.9;	//squash so laser emits inside device
					private _pLasY = (_pLas #1);	//correct for top rail 90* rot
					private _pLasZ = (_pLas #2) *-1;	//correct for top rail 90* rot
					_pLas set [0,_pLasX];
					_pLas set [2,_pLasY];	// Y + Z
					_pLas set [1,_pLasZ];	// Z - Y
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumX = (_pIllum #0) *-1;
					private _pIllumY = (_pIllum #1);
					private _pIllumZ = (_pIllum #2) *-1;
					_pIllum set [0,_pIllumX];
					_pIllum set [2,_pIllumY];	// Y + Z
					_pIllum set [1,_pIllumZ];	// Z - Y
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashX = (_pFlash #0) *-1;
					private _pFlashY = (_pFlash #1);
					private _pFlashZ = (_pFlash #2) *-1;
					_pFlash set [0,_pFlashX];
					_pFlash set [2,_pFlashY];	// Y + Z
					_pFlash set [1,_pFlashZ];	// Z - Y
			};
			case "leftRailOnly": {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasX = (_pLas #0) *-0.9;	//squash so laser emits inside device
					private _pLasY = (_pLas #1) *-1;	//correct for left rail 180* rot
					private _pLasZ = (_pLas #2) *-1;	//correct for left rail 180* rot
					_pLas set [0,_pLasX];
					_pLas set [1,_pLasY];
					_pLas set [2,_pLasZ];
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumX = (_pIllum #0) *-1;
					private _pIllumY = (_pIllum #1) *-1;
					private _pIllumZ = (_pIllum #2) *-1;
					_pIllum set [0,_pIllumX];
					_pIllum set [1,_pIllumY];
					_pIllum set [2,_pIllumZ];
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashX = (_pFlash #0) *-1;
					private _pFlashY = (_pFlash #1) *-1;
					private _pFlashZ = (_pFlash #2) *-1;
					_pFlash set [0,_pFlashX];
					_pFlash set [1,_pFlashY];
					_pFlash set [2,_pFlashZ];
			};
			default {
				//Lasers
					_pLas = _pLas apply {-_x};
					private _pLasT = (_pLas #0) *-0.9;
					_pLas set [0,_pLasT];
				//Illuminators
					_pIllum = _pIllum apply {-_x};
					private _pIllumT = (_pIllum #0) *-1;
					_pIllum set [0,_pIllumT];
				//Flashlights
					_pFlash = _pFlash apply {-_x};
					private _pFlashT = (_pFlash #0) *-1;
					_pFlash set [0,_pFlashT];
			};
		};
		if(isNumber (_cfgWc >> "gjb_itn_beltFedFix"))then{
			//increase x-fix in case of Weapon Slinging Mods
				//Add this feature later
			private _pLasT = (_pLas #0) - _bff;
			private _pIllumT = (_pIllum #0) -( _bff/2);
			_pLas set [0,_pLasT];
			_pIllum set [0,_pIllumT];
		};
	};
	case 3;			//binoculars
	case -1: {};	//empty hands
};

//Combine device offsets with host platform offsets
_pLas = _pLas vectorAdd _woff;
_pLas = _pLas apply {[_x]};

_pIllum = _pIllum vectorAdd _woff;
_pIllum = _pIllum apply {[_x]};

_pFlash = _pFlash vectorAdd _woff;
_pFlash = _pFlash apply {[_x]};

//Record offsets and retrieved device state onto object nameSpace variables and broadcast appropriately
_posData set [0,_pLas];
_posData set [1,_pIllum];
_posData set [2,_pFlash];

_unit setVariable ["gjb_itn_deviceOffset",_posData, true];
_unit setVariable ["gjb_itn_deviceState",_deviceState, true];

_last set [1,_aP];
_last set [2,_aH];
_last set [3,_aL];

//systemChat format ["Device Offset:: %2 :: %1",systemTime #6,_last #0];

_unit setVariable ["gjb_itn_lastConfig", _last];

//calls modeSpec if mode = 0 (dirty fix)
if(_unit == player)then{
	[_unit,_deviceState] call gjb_itn_fnc_modeSpec;
};

//tells gjb_itn_fnc_checkBucket that script has finished running
_unit setVariable ["gjb_itn_checker",false];