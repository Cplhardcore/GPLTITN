#include "script_component.hpp"

//*****************************************************************************//
//	
//	gjb_itn_fnc_dualDeviceActivate
//
//	Handles partialized activation of dual-unit devices, such as lasers with
//	independent flashlights, when toggled via the device interface.
//
//*****************************************************************************//

/*/--------------
change device "knob" to store status
store current deviceState in new place
if called from laser button, toggle laser only
	if light is off
		find nearest mode with laser only
	if light is on
		find nearest mode with both lasers and light
	set that mode, do not update knobs, run activation
if called from light button, toggle light only
	if laser is off
		find nearest mode with light only
	if laser is om
		find nearest mode with both laser and light
	set that mode, do not update knobs, run activation
//--------------