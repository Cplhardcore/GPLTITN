#include "script_component.hpp"

[] call gjb_itn_fnc_keys;
[] call gjb_itn_fnc_bucketEH;

/*/prep laser/light key hijacker
_hijack = missionNamespace getVariable "gjb_itn_setting_hijackHeadlights";
missionNamespace setVariable ["gjb_test_var","noEH"];
if(_hijack)then{
	missionNamespace setVariable ["gjb_test_var","EH"];
	_eh1 = addUserActionEventHandler ["headlights","Activate",
	{
	player action ["IRLaserOn",player];
	[0,1] call gjb_itn_fnc_ctrlPwr
	}];
	_eh2 = addUserActionEventHandler ["headlights","Deactivate",
	{
	[1,1] call gjb_itn_fnc_ctrlPwr
	}];
	missionNamespace setVariable ["gjb_itn_setting_hijackHeadlightsEH",[_eh1,_eh2]];
};*/

//prep GGE weapon canting laser fix
if(isClass (configFile >> "CfgPatches" >> "gge_canting"))then{
	_eh = addUserActionEventHandler ["opticsTemp","Activate",{
		_pfeh = addMissionEventHandler ["EachFrame",{
			_mode = missionNamespace getVariable "gge_canting_var_cantMode"; 
			_aim = missionNamespace getVariable "gge_canting_var_cantingAim";
			if(_mode && _aim)then{
				player action ["IRLaserOff",player];
				player action ["GunLightOff",player];
				_pfeh = player getVariable ["gjb_itn_ggeCantingLasFixPfeh",-1];
				removeMissionEventHandler ["EachFrame",_pfeh];
			};
		}];
		player setVariable ["gjb_itn_ggeCantingLasFixPfeh",_pfeh];
	}];
	player setVariable ["gjb_itn_ggeCantingLasFixEh",_eh];
};




/*
//=================================================================================//
Variable List

#	gjb_itn_deviceState = [0,0,0,0,0,0]

		Purpose: tracks state of _unit's current laser device, including on/off,
			mode, which weapon it is currently equipped to, and a quick-reference
			to which functions are active. Is edited by player for player, then
			broadcast to other clients for local use.
		Used in:
			gjb_itn_fnc_devicePwr,		edited by player for on/off and broadcast
			gjb_itn_fnc_bucketEH,		locally determines per-frame functions
			gjb_itn_fnc_getModelOffset, copied to player holder var and updated
										from appropriate holder var before broadcast
			gjb_itn_fnc_modeSpec,		converted locally into appropriate device
										function specs
		Level: Public, player-authoratative

		0. device state
			0 = off
			1 = on
		1. laser state
			0 = off
			1 = on
		2. illum state
			0 = off
			1 = on
		3. flash state
			0 = off
			1 = on
		4. mode
			# = 0-index pulled from gjb_itn_deviceState in CfgITNCompat
		5. parent weapon system
			-1 = empty, nothing
			0 = rifle/primary
			1 = handgun
			2 = launcher/secondary
			3 = binoculars

#	gjb_itn_dpTimer = 0

		Purpose: part of dual-function device switch (tog/mom), acts as count-up
			timer between key-down and key-up event.
		Used in:
			gjb_itn_fnc_devicePwr,	carries mission time of key-down event
		Level: Local, player only

#	gjb_itn_dpState = 0

		Purpose: part of dual-function device switch (tog/mom), adjusts key-up
			behavior in gjb_itn_fnc_devicePwr to check time since key-down event.
		Used in:
			gjb_itn_fnc_devicePwr,	adjusts behavior of key-up result
		Level: Local, player only

#	gjb_itn_bucketEH = ?

		Purpose: carries the event handler that draws all lasers and positions
			all light sources for ITN.
		Used in:
			gjb_itn_fnc_bucketEH,	carries EH
		Level: Local, player only

#	gjb_itn_lastConfig = ["?","?","?","?",0,0,0]

		Purpose: helps track when _unit changes its current weapon or the laser
			device on any of its weapon systems by storing the last weapon and
			attachments the _unit had. Is used to determine if offsets need to
			be updated.
		Used in:
			gjb_itn_fnc_getModelOffset,	tracks last items as part of short-stop
		Level: Local

		0 = _unit's last current weapon
		1 = _unit's last primary weapon accessory
		2 = _unit's last handgun accessory
		3 = _unit's last launcher accessory
		4 = last device mode (gjb_itn_deviceState #4)
		5 = last device illum mode (gjb_itn_deviceState #2)
		6 = which type of weapon _unit last had in hand (gjb_itn_deviceState #5)

#	gjb_itn_deviceOffset = [[0,0,0],[0,0,0],[0,0,0],[0,0,0],"?"]

		Purpose: stores the offset of a device's appropriate memory points in
			model coordinate space, to be combined with the location and orientation
			of the _unit's appropriate weapon proxy, so as to accurately locate where
			lasers and lights should emit from. Updated by player whenever device or
			weapon system changes, and is broadcast to all clients.
		Used in:
			gjb_itn_fnc_getModelOffset,	stores offsets for use in other functions
			gjb_itn_fnc_drawLaser,	is combined with model proxy to locate emitter
			gjb_itn_fnc_creatLight,	is combined with model proxy to locate emitter
			gjb_itn_fnc_creatIlluminator,	is combined with model proxy to locate
											emitter
		Level: Public, player-authoritative

		0 = Array of model-space coordinates with offset for laser memory point
		1 = Array of model-space coordinates with offset for illuminator memory point
		2 = Array of model-space coordinates with offset for flashlight memory point
		3 = Array of model-space coordinates of weapon's accesory proxy
		4 = String, name of model proxy which the coordinates are related to

#	gjb_itn_stateHolderRifle = [0,0,0,0,0,0]

		Purpose: stores current mode for the device attached to the primary weapon
			when not using that weapon system, and is used to restore correct state
			for the device when transitioning back to the primary weapon system.
		Used in:
			gjb_itn_fnc_getModelOffset,	backs up and restores gjb_itn_deviceState
										as appropriate
		Level: Local

#	gjb_itn_stateHolderPistol = [0,0,0,0,0,0]

		Purpose: stores current mode for the device attached to the handgun
			when not using that weapon system, and is used to restore correct state
			for the device when transitioning back to the handgun.
		Used in:
			gjb_itn_fnc_getModelOffset,	backs up and restores gjb_itn_deviceState
										as appropriate
		Level: Local

#	gjb_itn_stateHolderLauncher = [0,0,0,0,0,0]

		Purpose: stores current mode for the device attached to the launcher
			when not using that weapon system, and is used to restore correct state
			for the device when transitioning back to the launcher.
		Used in:
			gjb_itn_fnc_getModelOffset,	backs up and restores gjb_itn_deviceState
										as appropriate
		Level: Local

#	gjb_itn_lastState = [0,0,0,0,0,0] <<Depreciated>>

		Purpose: helps track when _unit changes the mode of its device by storing
			its last state. Is used to determine if laser or light source specs need
			to be updated.
		Used in:
			gjb_itn_fnc_modeSpec,	tracks last mode as part of short-stop
		Level: Local, for each unit

#	gjb_itn_lasSpec = [[0,0,0],0,0,0,false]

		Purpose: stores specs for the _unit's currently equipped laser device, such
			as color, dot and beam sizes, and whether it is IR or not, for use in
			gjb_itn_fnc_drawLaser. Updated by gjb_itn_fnc_modeSpec.
		Used in:
			gjb_itn_fnc_modeSpec,	updated from relavent config file entry
			gjb_itn_fnc_drawLaser,	holds laser specifications for drawing
		Level: Local, for each unit

		0 = ARRAY, color in [r,g,b]
		1 = NUMBER, dot size
		2 = NUMBER, beam thickness
		3 = NUMBER, beam maximum length
		4 = BOOLEAN, whether IR

#	gjb_itn_illumSpec = [?]

		Purpose: stores specs for the _unit's currently equipped laser illuminator
			device such as intensity, beam angle and sharpness, and whether it is IR,
			for use in gjb_itn_fnc_createIlluminator. Updated by gjb_itn_fnc_modeSpec.
		Used in:
			gjb_itn_fnc_modeSpec,	updated from relavent config file entry
			gjb_itn_fnc_createIlluminator,	holds illuminator specifications for
											creating light source
		Level: Local, for each unit

		??

#	gjb_itn_flashSpec = [?]

		Purpose: stores specs for the _unit's currently equipped flashlight device
			such as intensity, beam angle, if it has a spill, and whether it is IR,
			for use in gjb_itn_fnc_createLight. Updated by gjb_itn_fnc_modeSpec.
		Used in:
			gjb_itn_fnc_modeSpec,	updated from relavent config file entry
			gjb_itn_fnc_createLight,	holds flashlight specifications for
										creating light source
		Level: Local, for each unit

		??

#	gjb_itn_checker = [false,false]

		Purpose: stores run state of gjb_itn_fnc_getModelOffset and gjb_itn_fnc_modeSpec
			for use in gjb_itn_fnc_checkBucket to determine whether those scripts can be
			run again, ensuring only one instance of each script at any one time.
		Used in:
			gjb_itn_fnc_checkBucket,	used in IF statements
			gjb_itn_fnc_getModelOffset,	sets to false at end of script
			gjb_itn_fnc_modeSpec,	sets to false at end of script
		Level: Local

		0 = BOOLEAN, is gjb_itn_fnc_getModelOffset running?
		1 = BOOLEAN, is gjb_itn_fnc_modeSpec running?

#	gjb_itn_knobPos = [0,0,0] (fill out!)

//=================================================================================//

Use this init on troops in editor to give laser!

		_this setVariable ["gjb_itn_deviceState",[1,1,1,0,5,0]];
		_deviceState = _this getVariable "gjb_itn_deviceState";
		[_this,_deviceState] call gjb_itn_fnc_getWeaponOffset;

//=================================================================================//

For developing gjb_itn_beltFedFix  offset value
		// To use: 
		// Equip a laser device with an easily seen laser
		// beam (IR HI in combination with NODs works well).
		// Input adjustments and run script.
		// Adjustments are cumulative, so be aware of your 
		// totals.
		// To reset defaults, swap to another weapon and back,
		// or remove and reattach device to the weapon.

		//==Enter desired adjustments here==
		_xMod = 0; //+ downrange, - towards player
		_yMod = 0; //+ to players right, - to players left
		_zMod = 0; //+ upwards, - downwards
		//==================================

		//Pull variable
		_u = player;
		_allOff = player getVariable ["gjb_itn_deviceOffset",[]];
		_lasOff = flatten (_allOff #0);

		//Prep for adjustments
		_x = _lasOff #0;
		_y = _lasOff #1;
		_z = _lasOff #2;

		//Update laser offset variable
		_lasOff = [[_x - _xMod],[_y + _yMod],[_z + _zMod]];
		_allOff set [0,_lasOff];
		_u setVariable ["gjb_itn_deviceOffset",_allOff];

*/