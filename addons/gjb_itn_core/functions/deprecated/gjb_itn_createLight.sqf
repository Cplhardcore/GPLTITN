#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_createLight
//
//	computes final position and vector of light source 
//	is called from inside a mission event handler (EachFrame)
//	when device is active
//
//	parameters =	_unit being created for
//					_deviceState of unit being created for
//					_change if fnc is being called by gjb_itn_fnc_modeSpec
//
//					gjb_itn_deviceOffset of unit being created for
//					gjb_itn_flashSpec of unit being created for
//
//*****************************************************************************//

params ["_unit"];

private _flashObject = _unit getVariable ["gjb_itn_flashObject",objNull];
private _flashSpec = _unit getVariable ["gjb_itn_flashSpec",""];
private _lightObjects = _unit getVariable ["gjb_itn_lightObjects",["",""]];

//if the flashlight is the wrong type, delete it
if((_lightObjects #1) != _flashSpec)then{
	deleteVehicle _flashObject;
	_flashObject = objNull;
};
//If the flashlight does not already exist, create it
if(isNull _flashObject)then{
	_flashObject = _flashSpec createVehicleLocal [0,0,0];
	_unit setVariable ["gjb_itn_flashObject",_flashObject];
	_lightObjects set [1,_flashSpec];
	_unit setVariable ["gjb_itn_lightObjects",_lightObjects];
};

_posData = _unit getVariable ["gjb_itn_deviceOffset",[[],[],[],[],""]];
_offset = _posData #2;
_direction = +_offset;
_proxy = _posData #4;

//Compute position of memory point
_unit selectionVectorDirAndUp [_proxy, 1] params ["_vy", "_vz"];
_pos = selectionPosition [_unit, _proxy, 0];
_posDir = +_pos;
_vx = _vy vectorCrossProduct _vz;
_mat = matrixTranspose [_vx, _vy, _vz];
_pos = _pos vectorAdd flatten(_mat matrixMultiply _offset);
_p1 = _unit modelToWorldVisualWorld _pos;

//Compute direction point and vector
_directionT = _direction #0 #0;
_directionT = _directionT - 10;
(_direction #0) set [0,_directionT];
_posDir = _posDir vectorAdd flatten(_mat matrixMultiply _direction);
_p2 = _unit modelToWorldVisualWorld _posDir;
_v2 = _p1 vectorFromTo _p2;

//position and point illuminator
_flashObject setPosASL _p1;
_flashObject setVectorDirAndUp [_v2,[0,1,0]];

/*==============================================================
Use for testing light/illuminator values

_light = player getVariable ["light",objNull];  
_light2 = player getVariable ["light2",objNull]; 

if(isNull _light) then {  
 _light = "#lightreflector" createVehicleLocal [0,0,0];
};
 
_light setLightColor [1, 1, 1]; 
_light setLightAmbient [1, 1, 1]; 
_light setLightIntensity 600; 
_light setLightAttenuation [1, 1, 1, 0.001, 300, 400]; 
_light setLightConePars [25, 3, 10]; 
_light setLightIR false; 
 
player setVariable ["light",_light];  
_light attachTo [player, [0,0,0], "proxy:\a3\characters_f\proxies\weapon.001", true];

//===============
if(isNull _light2) then {  
 _light2 = "#lightreflector" createVehicleLocal [0,0,0];
};

_light2 setLightColor [1, 1, 1]; 
_light2 setLightAmbient [1, 1, 1]; 
_light2 setLightIntensity 100; 
_light2 setLightAttenuation [1, 1, 1, 0.001, 300, 400]; 
_light2 setLightConePars [70, 10, 4]; 
_light2 setLightIR false; 
 
player setVariable ["light2",_light2];  
 
_light2 attachTo [player, [0,0,0], "proxy:\a3\characters_f\proxies\weapon.001", true];


format ["%1 || %2",_light,_light2];
