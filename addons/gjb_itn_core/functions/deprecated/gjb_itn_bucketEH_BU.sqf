#include "script_component.hpp"

private _gjb_itn_bucketEH = addMissionEventHandler ["EachFrame",{

	//Collect all units the client is to deal with this frame
		//would cutting this to every 0.5s help with frames?
	private _activeUnits = allUnits select {
		alive _x 
		&& (player == _x
		|| (((_x getVariable ["gjb_itn_deviceState",0]) isEqualType [])
			&& (player distance _x) <= 1000))
	};
	{
		//perform tasks
		private _deviceState = _x getVariable ["gjb_itn_deviceState", [0,0,0,0,0,0]];
		private _illumObject = _x getVariable ["gjb_itn_illumObject",objNull];
		private _flashObject = _x getVariable ["gjb_itn_flashObject",objNull];

		[_x,_deviceState] call gjb_itn_fnc_checkBucket;		//runs checkers in scheduler

		if ((_deviceState #0) == 1)then{
			//Draw laser if device is on and set to a laser mode
			if ((_deviceState #1) == 1) then{
				[_x] call gjb_itn_fnc_drawLaser;	//client determins positions of all lasers
													//locally using broadcasted offsets from remote
													//systems.
			};
			//Create and position illuminator if device is on and set to an illuminator mode,
			//	otherwise clean up illuminator object
			if ((_deviceState #2) == 1) then{
				[_x] call gjb_itn_fnc_createIlluminator;
			}else{
				deleteVehicle _illumObject;
				_x setVariable ["gjb_itn_illumObject",objNull];
			};
			//Create and position flashlight if device is on and set to an flashlight mode,
			//	otherwise clean up flashlight object
			if ((_deviceState #3) == 1) then{
				[_x] call gjb_itn_fnc_createLight;
			}else{
				deleteVehicle _flashObject;
				_x setVariable ["gjb_itn_flashObject",objNull];
			};
		}else{
			//clean up all light objects for unit if device is not on
			deleteVehicle _illumObject;
			_x setVariable ["gjb_itn_illumObject",objNull];
			deleteVehicle _flashObject;
			_x setVariable ["gjb_itn_flashObject",objNull];
		};
		//[_x,_deviceState,-1] call gjb_itn_fnc_createIlluminator;
		//[_x,_deviceState,-1] call gjb_itn_fnc_createLight;
	} forEach _activeUnits;

	//clean up lasers and lights from dead units
	private _dearlyDeparted = allDead select {
		((_x getVariable ["gjb_itn_deviceState", [0,0,0,0,0,0]]) # 0) == 1
	};
	{
		private _deviceState = _x getVariable "gjb_itn_deviceState";
		_deviceState set [0,0];
		_x setVariable ["gjb_itn_deviceState",_deviceState];
		private _illumObject = _x getVariable ["gjb_itn_illumObject",objNull];
		deleteVehicle _illumObject;
		private _flashObject = _x getVariable ["gjb_itn_flashObject",objNull];
		deleteVehicle _flashObject;
	} forEach _dearlyDeparted;
}];
player setVariable ["gjb_itn_bucketEH",_gjb_itn_bucketEH];