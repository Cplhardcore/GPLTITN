#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_hasCompat
//
//	Determins whether current device has a compatibility entry,
//	and if not, then assigns it the proper generic entry
//	(acc_flashlight for lights, acc_pointer_IR for lasers)
//
//	is called by the following scripts:
//			gjb_itn_fnc_ctrlMode
//			gjb_itn_fnc_getDeviceOffset
//			gjb_itn_fnc_modeSpec
//			gjb_itn_fnc_toggleLaser
//
//*****************************************************************************//

params ["_device"];

if(_device == "")exitWith{_device};

private _compat = configFile >> "CfgITNCompat" >> "accessories" >> _device;
if(!(isClass _compat))then{
	_unit = player; 
	_w = primaryWeaponItems _unit #1; 
	_cfgW = configFile >> "CfgWeapons" >> _w; 
	_mW = getText(_cfgW >> "model"); 
	_oW = createSimpleObject [_mW, [0,0,0], true];  
	_woff = _oW selectionNames "Memory";
	deleteVehicle _oW; 

	_las = _woff findIf {"las" in _x || "Las" in _x};
	_flash = _woff findIf {"flash" in _x || "Flash" in _x};

	switch(true)do{
		case (_las != -1 && _flash == -1):{_device = "gjb_itn_generic_device_las"};
		case (_las == -1 && _flash != -1):{_device = "gjb_itn_generic_device_flash"};
		case (_las != -1 && _flash != -1):{_device = "gjb_itn_generic_device_combo"};
	};
};

//systemChat format ["%1 :: %2",_device,systemTime #6];

_device



/*private _laser = configFile >> "CfgWeapons" >> _device >> "ItemInfo" >> "Pointer" >> "irLaserPos";
if((getText _laser) != "")then{
	_defualt = "gjb_itn_generic_device_las";
	private _light = configFile >> "CfgWeapons" >> _device >> "ItemInfo" >> "Flashlight" >> "position";
	if((getText _ligt) != "")then{
		_default = "gjb_itn_generic_device_combo";
	};
};
if(_default != "")exitWith{_defualt};

_defualt = "gjb_itn_generic_device_flash";
private _light = configFile >> "CfgWeapons" >> _device >> "ItemInfo" >> "Flashlight" >> "position";
if((getText _light) != "")exitWith{_defualt};*/