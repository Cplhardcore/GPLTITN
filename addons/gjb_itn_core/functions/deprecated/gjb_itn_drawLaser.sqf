#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_drawLaser
//
//	computes final position of emitter and draws laser
//	is called from inside a mission event handler 
//	(EachFrame, to cut visible lag) when device is active
//
//	parameters =	_unit being drawn for
//
//					gjb_itn_deviceOffset of unit being drawn for
//					gjb_itn_lasSpec of unit being drawn for
//
//*****************************************************************************//

params ["_unit"];

private _lasData = _unit getVariable ["gjb_itn_lasSpec",[[0,0,0],0,0,0,false]];

//Retrieve position data
private _posData = _unit getVariable ["gjb_itn_deviceOffset",[[],[],[],[],""]];
private _offset = _posData #0;
private _direction = +_offset;
private _proxy = _posData #4;

//Compute position of memory point
_unit selectionVectorDirAndUp [_proxy, 1] params ["_vy", "_vz"];
private _pos = selectionPosition [_unit,_proxy,0,true,"FirstPoint"];
private _posDir = +_pos;
private _vx = _vy vectorCrossProduct _vz;
private _mat = matrixTranspose [_vx, _vy, _vz];
_pos = _pos vectorAdd flatten(_mat matrixMultiply _offset);

private _p1 = _unit modelToWorldVisualWorld _pos;

//Compute direction point and vector
_directionT = _direction #0 #0;
_directionT = _directionT - 10;
(_direction #0) set [0,_directionT];
_posDir = _posDir vectorAdd flatten(_mat matrixMultiply _direction);

private _p2 = _unit modelToWorldVisualWorld _posDir;
private _v2 = _p1 vectorFromTo _p2;

//Draw the laser
drawLaser [_p1, _v2,_lasData #0,[], _lasData #1, _lasData #2, _lasData #3, _lasData #4];
