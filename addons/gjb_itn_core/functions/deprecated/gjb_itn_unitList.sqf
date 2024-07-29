#include "script_component.hpp"

//***************************************************//
//Collects and maintains list of units to be simulated
// by ITN, retrieves and stores device state for each
//***************************************************//

_gjb_itn_units = allUnits select {
	if (alive _x 
		&& ((_x getVariable ["gjb_itn_deviceState", [0]] # 0) == 1)
		&& (player == _x || (player distance _x) <= 1000)
	) then {};
};


// uh...... net magick...