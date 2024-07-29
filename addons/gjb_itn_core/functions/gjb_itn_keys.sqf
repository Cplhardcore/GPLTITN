#include "script_component.hpp"

//*****************************************************************************//
//
//	Adds keybinds using CBA
//
//*****************************************************************************//

#include "\a3\ui_f\hpp\defineDIKCodes.inc"

	//activate device
[	"Illuminate The Night","gjb_itn_key_togDevice",
	["Activate Rail Device","Activates the rail device"],
	{[0,1] call gjb_itn_fnc_ctrlPwr},
	{[1,1] call gjb_itn_fnc_ctrlPwr},
	[DIK_F1,[false,false,false]]] call cba_fnc_addkeybind;

	//dialog hold-to-open
[	"Illuminate The Night","gjb_itn_key_guiHold",
	["Open Rail Device Interface (Toggle/Hold)","While held opens an interface to set rail device modes"],
	{
		//begin timer
		_sTime = +time;
		player setVariable ["gjb_itn_dpTimer",_sTime];
		private _isOpen = player getVariable ["gjb_itn_interfaceOpen",false];
		if(!_isOpen)then{
			[] call gjb_itn_fnc_ctrlOpenInterface;
		};
	},
	{
		//check timer
		private _sTime = player getVariable ["gjb_itn_dpTimer",0];
		private _hold = time - _sTime;
		private _isOpen = player getVariable ["gjb_itn_interfaceOpen",false];
		switch(true)do{
			case (_hold <= 0.2 && _sTime != 0 && !_isOpen):{
				player setVariable ["gjb_itn_interfaceOpen",true];
			};
			case (_hold <= 0.2 && _sTime != 0 && _isOpen);
			case (_hold > 0.2):{
				closeDialog 1;
				player setVariable ["gjb_itn_interfaceOpen",false];
			};
		};
		player setVariable ["gjb_itn_dpTimer",nil];
	},
	[DIK_F4,[false,false,false]]] call cba_fnc_addkeybind;

	//mode-prev (toward VIS)
[	"Illuminate The Night","gjb_itn_key_devSelPrv",
	["Previous Rail Device Mode","Selects previous available mode for rail device"],
	{[1] call gjb_itn_fnc_ctrlMode},
	{},
	[DIK_F2,[false,false,false]]] call cba_fnc_addkeybind;

	//mode-next (toward IR)
[	"Illuminate The Night","gjb_itn_key_devSelNex",
	["Next Rail Device Mode","Selects next available mode for rail device"],
	{[0] call gjb_itn_fnc_ctrlMode},
	{},
	[DIK_F3,[false,false,false]]] call cba_fnc_addkeybind;

	//power selector / switch mode selector?
	//Alt buttons?

	//illuminator angle narrow
[	"Illuminate The Night","gjb_itn_key_illumN",
	["Rail Device Illuminator Beam - Narrower","Narrows beam angle for compatible IR illuminators"],
	{[1] call gjb_itn_fnc_illumFocus},
	{},
	[DIK_F2,[true,false,false]]] call cba_fnc_addkeybind;
	
	//illuminator angle widen
[	"Illuminate The Night","gjb_itn_key_illumW",
	["Rail Device Illuminator Beam - Wider","Widens beam angle for compatible IR illuminators"],
	{[0] call gjb_itn_fnc_illumFocus},
	{},
	[DIK_F3,[true,false,false]]] call cba_fnc_addkeybind;

	//illuminator toggle diffusor
[	"Illuminate The Night","gjb_itn_key_illumD",
	["Rail Device Illuminator Diffusor Toggle","Toggles diffuse mode for compatible IR illuminators"],
	{[2] call gjb_itn_fnc_illumFocus},
	{},
	[DIK_F1,[true,false,false]]] call cba_fnc_addkeybind;
	
	//debug variable rest
[	"Illuminate The Night","gjb_itn_key_debugCmd",
	["DEBUG: Reset ITN","Clears storage variables and forces a remake of offsets. ONLY USE IF ITN IS NOT FUNCTIONING PROPERLY"],
	{[] call gjb_itn_fnc_debugCmd},
	{},
	[DIK_F5,[false,false,false]]] call cba_fnc_addkeybind;