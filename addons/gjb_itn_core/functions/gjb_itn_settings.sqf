#include "script_component.hpp"

//*****************************************************************************//
//
//	Adds settings using CBA
//
//*****************************************************************************//

/*
[
	"Test_Setting_1",					//unique setting id
	"CHECKBOX",							//type
	["-test checkbox-", "-tooltip-"],	//display name, tooltip
	"My Category",						//setting category
	true,								//values (type dependent)
	2,									//is global? 1 = all client have same, 2 = no override
	{},									//script to run
	false								//need restart?
] call CBA_fnc_addSetting;
*/

/*UI Settings*/
	//Hijack vanilla Headlight keybind
	[
		"gjb_itn_setting_hijackHeadlights",
		"CHECKBOX",
		["Use base-game keybinds","When checked, the base-game 'Headlights' keybind will behave like ITN's 'Activate Rail Device' in regards to weapon lights and laser devices"],
		["Illuminate The Night","User Interface"],
		true,
		0,
		{
			private _ehs = missionNamespace getVariable ["gjb_itn_setting_hijackHeadlightsEH",[-1,-1]];
			removeUserActionEventHandler ["headlights","Activate",_ehs #0];
			removeUserActionEventHandler ["headlights","Deactivate",_ehs #1];
			missionNamespace setVariable ["gjb_itn_setting_hijackHeadlightsEH",nil];
			if(_this)then{
				private _eh1 = addUserActionEventHandler ["headlights","Activate",
				{
				//player action ["IRLaserOn",player];
				[0,1] call gjb_itn_fnc_ctrlPwr
				}];
				private _eh2 = addUserActionEventHandler ["headlights","Deactivate",
				{
				[1,1] call gjb_itn_fnc_ctrlPwr
				}];
				missionNamespace setVariable ["gjb_itn_setting_hijackHeadlightsEH",[_eh1,_eh2]];
			};
		},
		false
	] call CBA_fnc_addSetting; 

	//Select canting mod to look for
	private _cantingVars = ["gjb_itn_cantMode"];
	private _cantingMods = ["ITN Compatible"];
	//populate extra canting mods
	if(isClass (ConfigFile >> "CfgPatches" >> "gge_canting"))then{
		_cantingVars pushBack "gge_canting_var_cantingAim";
		private _name = getText (configFile >> "CfgPatches" >> "gge_canting" >> "name");
		_cantingMods pushBack _name;
	};
	//if(thereAreAnyMoreCantingModsInExistence)then{includeThemHere};
	[
		"gjb_itn_setting_cantingMods",
		"LIST",
		["Canting mod of choice","Select which canting mod you prefer to use"],
		["Illuminate The Night","User Interface"],
		[_cantingVars,_cantingMods,0],
		2/*,
		{
			//on select code, probably rerun the var grabber script?
		},
		false*/
	] call CBA_fnc_addSetting;

	//Control Simplicity/Simulation (sim ignores ButtonA Option in favor of device-defined control pattern)
	[
		"gjb_itn_setting_simpleCtrl",
		"CHECKBOX",
		["Simplified controls","When checked, devices will default to an IR laser mode, and the OFF position will be disabled"],
		["Illuminate The Night","User Interface"]
	] call CBA_fnc_addSetting; 

	//Use Generic device interface always
	[
		"gjb_itn_setting_genericInterface",
		"CHECKBOX",
		["Use generic interface","When checked, the generic interface will be used for all devices, regardless of compatibility"],
		["Illuminate The Night","User Interface"]
	] call CBA_fnc_addSetting; 

	/*/Auto-on options
	[
		"gjb_itn_setting_autoOn",
		"LIST",
		["Automatic Activation Mode","Choose whether rail devices will automatically turn on and off, and under what conditions"],
		["Illuminate The Night","User Interface"],
		[[0,1,2,3],["Manual/No Auto-On","When weapon is shouldered","When using GGE Canting","When aiming down sights"],0]
	] call CBA_fnc_addSetting;	*/

	/*/Button A option (Tog/Mom/Dual)
	[
		"gjb_itn_setting_ctrlModeA",
		"LIST",
		["Device button A mode","Choose the mode of functionality for the Rail device interaction keybind"],
		["Illuminate The Night","User Interface"],
		[[0,1,2],["Toggle on/off","Momentary on (Hold)","Dual Toggle (Tap)/Momentary (Hold)"],0]
	] call CBA_fnc_addSetting;	*/
	
	[
		"gjb_itn_setting_toolTipMode",
		"LIST",
		["Interface tooltip mode","Choose how verbose tooltips in the graphic interface will be"],
		["Illuminate The Night","User Interface"],
		[[0,1,2],["Verbose","Brief","Off"],0]
	] call CBA_fnc_addSetting;

	//Show-Hide Interface Overlay
	[
		"gjb_itn_setting_interfaceOverlay",
		"CHECKBOX",
		["Show interface overlay","Turns on an overlay in the device interface which highlights controls"],
		["Illuminate The Night","User Interface"]
	] call CBA_fnc_addSetting;

	//Select tube color
	private _nvgModColor = [1,1,1,1];
	[
		"gjb_itn_setting_nvgColor",
		"LIST",
		["Nightvision color mode","Indicate which color of nightvision you use"],
		["Illuminate The Night","User Interface"],
		[[[0.4,0.6,0.1,1],[0.6,0.9,1,1],_nvgModColor,"gjb_itn_setting_nvgCustom"],["Green phosphor","White phosphor","Modded value [WIP]","Custom value"]]
	] call CBA_fnc_addSetting;
	[
		"gjb_itn_setting_nvgCustom",
		"COLOR",
		["Custom nightvision color","Select a color to matche the base color of your current nightvision device"],
		["Illuminate The Night","User Interface"],
		[1,1,1]
	] call CBA_fnc_addSetting;


/*Performance Settings*/
	//add draw-distance slider for lasers and light sources
	[
		"gjb_itn_setting_drawDist",
		"SLIDER",
		["Draw distance","How far in meters a unit can be from the player before ITN will stop drawing its laser and flashlight/illuminator"],
		["Illuminate The Night","Performance"],
		[500,8000,1000,0,false]
	] call CBA_fnc_addSetting;

/*Debugging Settings*/
	//Debug mode
	[
		"gjb_itn_setting_debug",
		"CHECKBOX",
		["Debug mode","Turns on script returns in system chat"],
		["Illuminate The Night","Debugging"]
	] call CBA_fnc_addSetting;

	/*/Reset variables
	[
		"gjb_itn_setting_reset",
		"CHECKBOX",
		["Reset ITN","Clears variables and forces a remake of offsets. Debug mode must be active"],
		["Illuminate The Night","Debugging"]
	] call CBA_fnc_addSetting; */