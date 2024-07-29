#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_createIlluminator
//
//	computes final position and vector of illuminator beam 
//	is called from inside a mission event handler (EachFrame)
//	when device is active
//
//	parameters =	_unit being created for
//					_deviceState of unit being created for
//					_change if fnc is being called by gjb_itn_fnc_modeSpec
//
//					gjb_itn_deviceOffset of unit being created for
//					gjb_itn_illumSpec of unit being created for
//
//*****************************************************************************//

params ["_unit"];

private _illumObject = _unit getVariable ["gjb_itn_illumObject",objNull];
private _illumSpec = _unit getVariable ["gjb_itn_illumSpec",""];
private _lightObjects = _unit getVariable ["gjb_itn_lightObjects",["",""]];

//if the illuminator is the wrong type, delete it
if((_lightObjects #0) != _illumSpec)then{
	deleteVehicle _illumObject;
	_illumObject = objNull;
};
//If the illuminator does not already exist, create it
if(isNull _illumObject)then{
	_illumObject = _illumSpec createVehicleLocal [0,0,0];
	_unit setVariable ["gjb_itn_illumObject",_illumObject];
	_lightObjects set [0,_illumSpec];
	_unit setVariable ["gjb_itn_lightObjects",_lightObjects];
};

_posData = _unit getVariable ["gjb_itn_deviceOffset",[[],[],[],[],""]];
_offset = _posData #1;
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
_illumObject setPosASL _p1;
_illumObject setVectorDirAndUp [_v2,[0,1,0]];