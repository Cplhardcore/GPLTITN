class CfgITNCompat
{//===================================================================================//
	/*
	Devices to be affected by ITN should have an entry in this class
	that is identical in name to the one in CfgWeapons. This class here
	will store the appropriate memory position names and operating modes
	for each device.
	
	gjb_itn_memoryPoints is an array of strings holding the memory points for
		Laser position (can be located inside model)
		Illuminator position (should be located at the "emmision point" of model)
		Flashlight position (should be located in or at the reflector dish of model)
	
	gjb_itn_controls is an array of

	gjb_itn_deviceModes is an array of 

	gjb_itn_deviceSpecs is an array of 
	
	USEFUL SCRIPT BITS
		//For gather weapon offsets
			//To Use:
			//Equip a weapon. Determine its type,
			//input for _type, and run the script.
			//If [0,0,0] is returned,  try a different
			//value for _lod. LODs 0-2 should return
			//a value.
			
			//Define weapon type.
			//	Primaries = 0
			//	Handguns = 1
			//	Launchers = 2
			_type = 0;

			//Define model LOD to check
			_lod = 1;

			//Prepare pull
			_unit = player;
			_w = currentWeapon _unit;
			_cfgW = configFile >> "CfgWeapons" >> _w;
			_mW = getText(_cfgW >> "model");
			_oW = createSimpleObject [_mW, [0,0,0], true]; 
			_proxies = [
				"proxy:\a3\data_f\proxies\weapon_slots\side.001",
				"proxy:\a3\data_f\proxies\weapon_slots\side.002",
				"proxy:\a3\data_f\proxies\weapon_slots\side.001"];
			_proxy = _proxies #_type;
			_woff = _oW selectionPosition [_proxy,_lod]; 

			//Clean up and report offset values.
			//Reports in format:
			// "Weapon class" : [x,z,y] (Time, differentiates outputs)
			deleteVehicle _oW;
			_time = [systemTime #3, systemTime #4, systemTime #5];
			format ["%1 : %2 (%3)",_w,_woff,_time];
		//	
	
		//For gathering device offsets
			//To Use:
			//Equip a laser device on whatever
			//weapon will accept it. Determine the name
			//of the memory point needed (e.g. "las pos")
			// and run the script for it.
			//If [0,0,0] is returned, double check the name
			//or spelling of the memory point.

			//Prepare pull
			_unit = player;
			_w = primaryWeaponItems _unit #1;
			_cfgW = configFile >> "CfgWeapons" >> _w;
			_mW = getText(_cfgW >> "model");
			_oW = createSimpleObject [_mW, [0,0,0], true]; 

			//If the memory points name is unknown,
			//refer to the configFile >> CfgWeapons class
			//entry for the memory points used by either
			//Pointer or Flashlight. Alternatively, select
			//a memory point from this array:
			_woff = _oW selectionNames "Memory";

			//Define name of desired memory point
			_mPoint = "";

			//Gather modelspace coords of desired
			//memory point. Comment out this line when
			//pulling memory point names.
			_woff = _oW selectionPosition [_mPoint,"Memory"];

			//Clean up and report offset values.
			//Reports in format:
			// "Device class" : [x,z,y] (Time, differentiates outputs)
			deleteVehicle _oW;
			_time = [systemTime #3, systemTime #4, systemTime #5];
			format ["%1 : %2 (%3)",_w,_woff,_time];
		//

		// For manually developing device offsets
			//Begin with [0,0,0] in for device in config,
			//will return running total of adjustments 

			// To use:  
			// Equip a laser device with an easily seen laser 
			// beam (IR HI in combination with NODs works well). 
			// Input adjustments and run script. 
			// Adjustments are cumulative, so be aware of your  
			// totals. 
			// To reset defaults, swap to another weapon and back, 
			// or remove and reattach device to the weapon. 
			
			//==Enter desired adjustments here== 
			_xMod = 0.0; //+ downrange, - towards player 
			_yMod = 0.0; //+ to players right, - to players left 
			_zMod = 0.0; //+ upwards, - downwards 
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

			//Tally total offset
			_tot = player getVariable ["totalOffsetTally",[0,0,0]];
			_xMod = _xMod + _tot #0;
			_yMod = _yMod + _tot #1;
			_zMod = _zMod + _tot #2;
			_tot = [_xMod,_yMod,_zMod];
			player setVariable ["totalOffsetTally",_tot];
			_tot
		//
	*/
//===================================================================================//
	class accessories
	{
//Common Device Bases
		class deviceBase_peq2
		{
			gjb_itn_controls[]=
			{
				{0,1},
				{0,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,0,"OFF"},
				{1,0,0,"AIM LO"},
				{1,3,0,"DUAL LO"},
				{2,0,0,"AIM HI"},
				{1,4,0,"DUAL LO/HI"},
				{2,4,0,"DUAL HI/HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{10,0,0},{3,0,0},0.3,0.00001,150,1},
				{{10000,0,0},{5,0,0},1.2,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class deviceBase_peq2_comboGen
		{
			gjb_itn_controls[]=
			{
				{1,3},
				{1,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,5,"VIS Flash"},
				{0,0,0,"OFF"},
				{0,0,6,"IR Flash"},
				{1,0,0,"AIM LO"},
				{1,0,6,"AIM LO + Flash"},
				{1,3,0,"DUAL LO"},
				{1,3,6,"DUAL LO + Flash"},
				{2,0,0,"AIM HI"},
				{2,0,6,"AIM HI + Flash"},
				{1,4,0,"DUAL LO/HI"},
				{1,4,6,"DUAL LO/HI + Flash"},
				{2,4,0,"DUAL HI/HI"},
				{2,4,6,"DUAL HI/HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{10,0,0},{3,0,0},0.3,0.00001,150,1},
				{{10000,0,0},{5,0,0},1.2,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
		class deviceBase_peq2_comboWO
		{};
		class deviceBase_peq2_comboVIR
		{
			gjb_itn_controls[]=
			{
				{6,8},
				{6,5},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"peq_2_combo",
				"Rsc_gjb_itn_peq2_combo_cup",
				"",
				""
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,5,"AIM LO + Vis Flash"},
				{1,3,5,"DUAL LO + Vis Flash"},
				{2,0,5,"AIM HI + Vis Flash"},
				{1,4,5,"DUAL LO/HI + Vis Flash"},
				{2,4,5,"DUAL HI/HI + Vis Flash"},
				//
				{0,0,5,"VIS Flash"},
				{0,0,0,"OFF"},
				{0,0,6,"IR Flash"},
				{1,0,0,"AIM LO"},
				{1,0,6,"AIM LO + Flash"},
				{1,3,0,"DUAL LO"},
				{1,3,6,"DUAL LO + Flash"},
				{2,0,0,"AIM HI"},
				{2,0,6,"AIM HI + Flash"},
				{1,4,0,"DUAL LO/HI"},
				{1,4,6,"DUAL LO/HI + Flash"},
				{2,4,0,"DUAL HI/HI"},
				{2,4,6,"DUAL HI/HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{10,0,0},{3,0,0},0.3,0.00001,150,1},
				{{10000,0,0},{5,0,0},1.2,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
			};
		class deviceBase_peq15
		{
			gjb_itn_controls[]=
			{
				{1,2},
				{1,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{2,0,0,"IR AIM LO"},
				{2,4,0,"IR DUAL LO"},
				{3,0,0,"IR AIM HI"},
				{0,5,0,"IR ILLUM HI"},
				{3,5,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class deviceBase_peq15_comboGen
		{
			gjb_itn_controls[]=
			{
				{3,5},
				{3,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,6,"VIS Flash"},
				{1,0,6,"VIS AIM + Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{0,0,7,"IR Flash"},
				{2,0,0,"IR AIM LO"},
				{2,0,7,"IR AIM LO + Flash"},
				{2,4,0,"IR DUAL LO"},
				{2,4,7,"IR DUAL LO + Flash"},
				{3,0,0,"IR AIM HI"},
				{3,0,7,"IR AIM HI + Flash"},
				{0,5,0,"IR ILLUM HI"},
				{0,5,7,"IR ILLUM HI + Flash"},
				{3,5,0,"IR DUAL HI"},
				{3,5,7,"IR DUAL HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
		class deviceBase_peq15_comboWO
		{};
		class deviceBase_peq15_comboVIR
		{
			gjb_itn_controls[]=
			{
				{9,11},
				{9,6},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"",
				""
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,7,"VIS AIM + IR Flash"},
				{2,0,6,"IR AIM LO + Vis Flash"},
				{2,4,6,"IR DUAL LO + Vis Flash"},
				{3,0,6,"IR AIM HI + Vis Flash"},
				{0,5,6,"IR ILLUM HI + Vis Flash"},
				{3,5,6,"IR DUAL HI + Vis Flash"},
				//
				{0,0,6,"VIS Flash"},
				{1,0,6,"VIS AIM + Flash"},
				{1,0,0,"VIS AIM"},
				{0,0,0,"OFF"},
				{0,0,7,"IR Flash"},
				{2,0,0,"IR AIM LO"},
				{2,0,7,"IR AIM LO + Flash"},
				{2,4,0,"IR DUAL LO"},
				{2,4,7,"IR DUAL LO + Flash"},
				{3,0,0,"IR AIM HI"},
				{3,0,7,"IR AIM HI + Flash"},
				{0,5,0,"IR ILLUM HI"},
				{0,5,7,"IR ILLUM HI + Flash"},
				{3,5,0,"IR DUAL HI"},
				{3,5,7,"IR DUAL HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
		class deviceBase_la5b
		{
			gjb_itn_controls[]=
			{
				{2,3},
				{2,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"la_5b",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{2,0,0,"VIS AIM HI"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{3,0,0,"IR AIM LO"},
				{3,5,0,"IR DUAL LO"},
				{4,0,0,"IR AIM HI"},
				{0,6,0,"IR ILLUM HI"},
				{4,6,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class deviceBase_la5b_comboGenWO
		{
			gjb_itn_controls[]=
			{
				{5,6},
				{5,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,7,"VIS Flash"},
				{2,0,7,"VIS AIM HI+ Flash"},
				{2,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{3,0,0,"IR AIM LO"},
				{3,5,0,"IR DUAL LO"},
				{4,0,0,"IR AIM HI"},
				{0,6,0,"IR ILLUM HI"},
				{4,6,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis"
			};
		};
		class deviceBase_la5b_comboGenVIR
		{
			gjb_itn_controls[]=
			{
				{5,6},
				{5,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,7,"VIS Flash"},
				{1,0,7,"VIS AIM HI+ Flash"},
				{1,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{0,0,8,"IR Flash"},
				{3,0,0,"IR AIM LO"},
				{3,0,8,"IR AIM LO + Flash"},
				{3,5,0,"IR DUAL LO"},
				{3,5,8,"IR DUAL LO + Flash"},
				{4,0,0,"IR AIM HI"},
				{4,0,8,"IR AIM HI + Flash"},
				{0,6,0,"IR ILLUM HI"},
				{0,6,8,"IR ILLUM HI + Flash"},
				{4,6,0,"IR DUAL HI"},
				{4,6,8,"IR DUAL HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
		class deviceBase_la5b_comboWO
		{
			gjb_itn_controls[]=
			{
				{10,11},
				{10,5},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"la_5b_combo",
				"Rsc_gjb_itn_generic_deviceclass",
				"",
				""
			};
			gjb_itn_deviceModes[]=
			{
				{3,0,7,"IR AIM LO + Vis Flash"},
				{3,5,7,"IR DUAL LO + Vis Flash"},
				{4,0,7,"IR AIM HI + Vis Flash"},
				{0,6,7,"IR ILLUM HI + Vis Flash"},
				{4,6,7,"IR DUAL HI + Vis Flash"},
				//
				{0,0,7,"VIS Flash"},
				{2,0,7,"VIS AIM HI+ Flash"},
				{2,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{3,0,0,"IR AIM LO"},
				{3,5,0,"IR DUAL LO"},
				{4,0,0,"IR AIM HI"},
				{0,6,0,"IR ILLUM HI"},
				{4,6,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis"
			};
		};
		class deviceBase_la5b_comboVIR
		{
			gjb_itn_controls[]=
			{
				{12,13},
				{12,7},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"la_5b_combo",
				"Rsc_gjb_itn_generic_deviceclass",
				"",
				""
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,8,"VIS AIM LO + IR Flash"},
				{2,0,8,"VIS AIM HI + IR Flash"},
				{3,0,7,"IR AIM LO + Vis Flash"},
				{3,5,7,"IR DUAL LO + Vis Flash"},
				{4,0,7,"IR AIM HI + Vis Flash"},
				{0,6,7,"IR ILLUM HI + Vis Flash"},
				{4,6,7,"IR DUAL HI + Vis Flash"},
				//
				{0,0,7,"VIS Flash"},
				{1,0,7,"VIS AIM HI+ Flash"},
				{1,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{0,0,8,"IR Flash"},
				{3,0,0,"IR AIM LO"},
				{3,0,8,"IR AIM LO + Flash"},
				{3,5,0,"IR DUAL LO"},
				{3,5,8,"IR DUAL LO + Flash"},
				{4,0,0,"IR AIM HI"},
				{4,0,8,"IR AIM HI + Flash"},
				{0,6,0,"IR ILLUM HI"},
				{0,6,8,"IR ILLUM HI + Flash"},
				{4,6,0,"IR DUAL HI"},
				{4,6,8,"IR DUAL HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
		class deviceBase_ngal
		{
			gjb_itn_controls[]=
			{
				{2,3},
				{2,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{2,0,0,"VIS AIM HI"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{3,0,0,"IR AIM LO"},
				{3,5,0,"IR DUAL LO"},
				{4,0,0,"IR AIM HI"},
				{0,6,0,"IR ILLUM HI"},
				{4,6,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class deviceBase_ngal_comboGenWO
		{
			gjb_itn_controls[]=
			{
				{5,6},
				{5,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,7,"VIS Flash"},
				{2,0,7,"VIS AIM HI+ Flash"},
				{2,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{3,0,0,"IR AIM LO"},
				{3,5,0,"IR DUAL LO"},
				{4,0,0,"IR AIM HI"},
				{0,6,0,"IR ILLUM HI"},
				{4,6,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis"
			};
		};
		class deviceBase_ngal_comboGenVIR
		{
			gjb_itn_controls[]=
			{
				{5,6},
				{5,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,7,"VIS Flash"},
				{1,0,7,"VIS AIM HI+ Flash"},
				{1,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{0,0,8,"IR Flash"},
				{3,0,0,"IR AIM LO"},
				{3,0,8,"IR AIM LO + Flash"},
				{3,5,0,"IR DUAL LO"},
				{3,5,8,"IR DUAL LO + Flash"},
				{4,0,0,"IR AIM HI"},
				{4,0,8,"IR AIM HI + Flash"},
				{0,6,0,"IR ILLUM HI"},
				{0,6,8,"IR ILLUM HI + Flash"},
				{4,6,0,"IR DUAL HI"},
				{4,6,8,"IR DUAL HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
		class deviceBase_ngal_comboWO
		{
			gjb_itn_controls[]=
			{
				{10,11},
				{10,5},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"ngal_combo",
				"Rsc_gjb_itn_ngal_roa",
				"",
				""
			};
			gjb_itn_deviceModes[]=
			{
				{3,0,7,"IR AIM LO + Vis Flash"},
				{3,5,7,"IR DUAL LO + Vis Flash"},
				{4,0,7,"IR AIM HI + Vis Flash"},
				{0,6,7,"IR ILLUM HI + Vis Flash"},
				{4,6,7,"IR DUAL HI + Vis Flash"},
				//
				{0,0,7,"VIS Flash"},
				{2,0,7,"VIS AIM HI+ Flash"},
				{2,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{3,0,0,"IR AIM LO"},
				{3,5,0,"IR DUAL LO"},
				{4,0,0,"IR AIM HI"},
				{0,6,0,"IR ILLUM HI"},
				{4,6,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis"
			};
		};
		class deviceBase_ngal_comboVIR
		{
			gjb_itn_controls[]=
			{
				{12,13},
				{12,7},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"ngal_combo",
				"Rsc_gjb_itn_ngal_roa",
				"",
				""
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,8,"VIS AIM LO + IR Flash"},
				{2,0,8,"VIS AIM HI + IR Flash"},
				{3,0,7,"IR AIM LO + Vis Flash"},
				{3,5,7,"IR DUAL LO + Vis Flash"},
				{4,0,7,"IR AIM HI + Vis Flash"},
				{0,6,7,"IR ILLUM HI + Vis Flash"},
				{4,6,7,"IR DUAL HI + Vis Flash"},
				//
				{0,0,7,"VIS Flash"},
				{1,0,7,"VIS AIM HI+ Flash"},
				{1,0,0,"VIS AIM HI"},
				{1,0,7,"VIS AIM LO+ Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{0,0,8,"IR Flash"},
				{3,0,0,"IR AIM LO"},
				{3,0,8,"IR AIM LO + Flash"},
				{3,5,0,"IR DUAL LO"},
				{3,5,8,"IR DUAL LO + Flash"},
				{4,0,0,"IR AIM HI"},
				{4,0,8,"IR AIM HI + Flash"},
				{0,6,0,"IR ILLUM HI"},
				{0,6,8,"IR ILLUM HI + Flash"},
				{4,6,0,"IR DUAL HI"},
				{4,6,8,"IR DUAL HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.3,0.00007,150,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
		class deviceBase_mawl	//in progress
		{
			gjb_itn_controls[]=
			{
				{1,2},
				{1,0},
				{1,1,10}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,0,"VIS AIM LO"},	// 0
				{0,0,0,"OFF"},			// 1
				{2,0,0,"IR AIM LO"},	// 2
				{2,4,0,"IR DUAL LO"},	// 3
				{3,0,0,"IR AIM HI"},	// 4
				{0,5,0,"IR ILLUM HI"},	// 5
				{3,5,0,"IR DUAL HI"}	// 6
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",							// 0 NULL entry to sidestep complicated fix
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},	// 1 vis laser red ; was {100,0,0},0.02,0.001,150,0
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},		// 2 ir laser lo
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},				// 3 ir laser hi ; was {100,0,0},0.1,0.1,-1,1
				"gjb_itn_illum_dbal_a2_10_Lo",		// 4 ir illuminator lo
				"gjb_itn_illum_dbal_a2_10_Hi"		// 5 ir illuminator hi
			};
		};
		class deviceBase_mawl_comboGen
		{};
		class deviceBase_mawl_comboWO
		{};
		class deviceBase_mawl_comboVIR
		{};
		class deviceBase_m952
		{
			gjb_itn_controls[]=
			{
				{1,0},
				{1,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,1,"VIS"},
				{0,0,0,"OFF"},
				{0,0,2,"IR"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
//Vanilla Devices======================================================================//
		class acc_flashlight
		{
			gjb_itn_memoryPoints[]=
			{ 
				{0,0,0},
				{0,0,0},
				{-0.0669806,-0.0126352,0.0358054}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"utg",
				"Rsc_gjb_itn_acc_flashlight",
				"\gjb_itn\addons\gjb_itn_core\ui\utg"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,1,"ON"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				"gjb_itn_flash_gen_vis"
			};
		};
		class acc_flashlight_pistol: acc_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0368911,7.78949e-005,-0.0213387}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"utg",
				"Rsc_gjb_itn_acc_flashlight_pistol",
				"\gjb_itn\addons\gjb_itn_core\ui\tls"
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				"gjb_itn_flash_gen_vis"
			};
		};
		class acc_flashlight_smg_01: acc_flashlight	//in progress
		{};
		class acc_pointer_IR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0424448,0.000860501,0.0175099},//Laser position; "laser pos"
				{-0.0424448,0.000860501,0.0175099},//Illuminator position; "laser pos"
				{0,0,0}//Flashlight position; "flash dir"
			};
			gjb_itn_controls[]=
			{
				{1,6},	//specifies default modes normal and simple controls
				{1,0},	//specifies FULL OFF mode, -1 if no such mode and bottom stop to hide compelx modes
				{1,1,6}	//0, can focus illuminator; 1, can diffuse illuminator; maximum beam angle
			};
			gjb_itn_interface[]=
			{
				"dbal_a2",
				"Rsc_gjb_itn_dbala2",
				"\gjb_itn\addons\gjb_itn_core\ui\peq15a"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,0,"VIS POINT",0},
				{0,0,0,"OFF",0},
				{0,4,0,"I/R ILLUM LO",1},
				{0,5,0,"I/R ILLUM HI",2},
				{2,4,0,"I/R POINT AND ILLUM LO",1},
				{3,5,0,"I/R POINT AND ILLUM HI",2},
				{2,0,0,"I/R POINT LO",1},
				{3,0,0,"I/R POINT HI",2}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class gjb_itn_generic_device_las
		{
			gjb_itn_controls[]=
			{
				{1,2},
				{1,0},
				{1,1,8}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{2,0,0,"IR AIM LO"},
				{2,4,0,"IR DUAL LO"},
				{3,0,0,"IR AIM HI"},
				{0,5,0,"IR ILLUM HI"},
				{3,5,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class gjb_itn_generic_device_flash
		{
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,1,"ON"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				"gjb_itn_flash_gen_vis"
			};
		};
		class gjb_itn_generic_device_combo
		{
			gjb_itn_controls[]=
			{
				{3,5},
				{3,0},
				{1,1,8}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,6,"VIS Flash"},
				{1,0,6,"VIS AIM + Flash"},
				{1,0,0,"VIS AIM LO"},
				{0,0,0,"OFF"},
				{0,0,7,"IR Flash"},
				{2,0,0,"IR AIM LO"},
				{2,0,7,"IR AIM LO + Flash"},
				{2,4,0,"IR DUAL LO"},
				{2,4,7,"IR DUAL LO + Flash"},
				{3,0,0,"IR AIM HI"},
				{3,0,7,"IR AIM HI + Flash"},
				{0,5,0,"IR ILLUM HI"},
				{0,5,7,"IR ILLUM HI + Flash"},
				{3,5,0,"IR DUAL HI"},
				{3,5,7,"IR DUAL HI + Flash"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis",
				"gjb_itn_flash_m952_ir"
			};
		};
//ACE devices========================================================================//
		class ace_acc_pointer_red: acc_pointer_IR
		{};
		class ace_acc_pointer_green: acc_pointer_IR
		{
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{0,25000,0},{0,50,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class ace_acc_pointer_green_IR: ace_acc_pointer_green
		{};
//RHS devices========================================================================//
	//peq15a
		class rhsusf_acc_anpeq15A: acc_pointer_IR
		{};
	//peq15
		class rhsusf_acc_anpeq15side: deviceBase_peq15
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,-0.0019568,0.0468706},
				{-0.0401166,0.00702431,0.0143004},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
		};
		class rhsusf_acc_anpeq15_top: rhsusf_acc_anpeq15side
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0361294,-0.0104568},
				{-0.0401166,0.0687026,-0.00147115},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
		};
		class rhsusf_acc_anpeq15_top_h: rhsusf_acc_anpeq15_top
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0361294,-0.0224568},
				{-0.0401166,0.0687026,-0.0134711},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
		};
		class rhsusf_acc_anpeq15_top_sc: rhsusf_acc_anpeq15_top
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0299294,-0.0289568},
				{-0.0401166,0.0625026,-0.0199711},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
		};
		class rhsusf_acc_anpeq15side_bk: rhsusf_acc_anpeq15side
		{};
		class rhsusf_acc_anpeq15_bk_top: rhsusf_acc_anpeq15_top
		{};
		class rhsusf_acc_anpeq15_bk_top_h: rhsusf_acc_anpeq15_top_h
		{};
		class rhsusf_acc_anpeq15_bk_top_sc: rhsusf_acc_anpeq15_top_sc
		{};
	//peq15 + m952v
		class rhsusf_acc_anpeq15: deviceBase_peq15_comboGen
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0361294,-0.0104568},
				{-0.0401166,0.0687026,-0.00147115},	//"ir_flash dir", DEV Branch
				{-0.0810881,-0.0168364,0.0363066}
			};
		};
		class rhsusf_acc_anpeq15_h: rhsusf_acc_anpeq15
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0361294,-0.0224568},
				{-0.0401166,0.0687026,-0.0134711},	//"ir_flash dir", DEV Branch
				{-0.0810881,-0.0168364,0.0363066}
			};
		};
		class rhsusf_acc_anpeq15_sc: rhsusf_acc_anpeq15
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0299294,-0.0289568},
				{-0.0401166,0.0625026,-0.0199711},	//"ir_flash dir", DEV Branch
				{-0.0810881,-0.0168364,0.0363066}
			};
		};
		class rhsusf_acc_anpeq15_light: rhsusf_acc_anpeq15
		{};
		class rhsusf_acc_anpeq15_light_h: rhsusf_acc_anpeq15_h
		{};
		class rhsusf_acc_anpeq15_light_sc: rhsusf_acc_anpeq15_sc
		{};
		class rhsusf_acc_anpeq15_bk: rhsusf_acc_anpeq15
		{};
		class rhsusf_acc_anpeq15_bk_h: rhsusf_acc_anpeq15_h
		{};
		class rhsusf_acc_anpeq15_bk_sc: rhsusf_acc_anpeq15_sc
		{};
		class rhsusf_acc_anpeq15_bk_light: rhsusf_acc_anpeq15_bk
		{};
		class rhsusf_acc_anpeq15_bk_light_h: rhsusf_acc_anpeq15_h
		{};
		class rhsusf_acc_anpeq15_bk_light_sc: rhsusf_acc_anpeq15_sc
		{};
	//peq15 + wmx
		class rhsusf_acc_anpeq15_wmx: rhsusf_acc_anpeq15
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0361294,-0.0104568},
				{-0.0397188,0.0687026,-0.00147115},	//"ir_flash dir", DEV Branch
				{-0.083932,-0.00471184,0.0352501}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",						// 0 NULL entry to sidestep complicated fix
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},// 1 vis laser red ; was {100,0,0},0.02,0.001,150,0
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},	// 2 ir laser lo
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},			// 3 ir laser hi ; was {100,0,0},0.1,0.1,-1,1
				"gjb_itn_illum_dbal_a2_10_Lo",	// 4 ir illuminator lo
				"gjb_itn_illum_dbal_a2_10_Hi",	// 5 ir illuminator hi
				"gjb_itn_flash_wmx200_vis",		// 6 vis flash
				"gjb_itn_flash_wmx200_ir"		// 7 ir flash
			};
		};
		class rhsusf_acc_anpeq15_wmx_h: rhsusf_acc_anpeq15_wmx
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0361294,-0.0224568},
				{-0.0397188,0.0687026,-0.0134711},	//"ir_flash dir", DEV Branch
				{-0.083932,-0.00471184,0.0352501}
			};
		};
		class rhsusf_acc_anpeq15_wmx_sc: rhsusf_acc_anpeq15_wmx
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0299294,-0.0289568},
				{-0.0397188,0.0625026,-0.0199711},	//"ir_flash dir", DEV Branch
				{-0.083932,-0.00471184,0.0352501}
			};
		};
		class rhsusf_acc_anpeq15_wmx_light: rhsusf_acc_anpeq15_wmx
		{};
		class rhsusf_acc_anpeq15_wmx_light_h: rhsusf_acc_anpeq15_wmx_h
		{};
		class rhsusf_acc_anpeq15_wmx_light_sc: rhsusf_acc_anpeq15_wmx_sc
		{};
	//peq16
		class rhsusf_acc_anpeq16a: acc_pointer_IR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0243592,0.00797443,0.00903933},
				{-0.0349761,-0.000901868,0.0575951},
				{-0.0342286,0.00504607,0.0165455}
			};
			gjb_itn_controls[]=
			{
				{3,4},
				{3,0},
				{1,1,6}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,6,"VIS DUAL"},
				{0,0,6,"VIS LIGHT"},
				{1,0,0,"VIS AIM"},
				{0,0,0,"OFF"},
				{2,0,0,"IR AIM LO"},
				{2,4,0,"IR DUAL LO"},
				{3,0,0,"IR AIM HI"},
				{3,5,0,"IR DUAL HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_wmx200_vis"
			};
		};
		class rhsusf_acc_anpeq16a_top: rhsusf_acc_anpeq16a
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0243592,0.0741607,-0.000925568},
				{-0.0349761,0.0256049,-0.00980187},	//"ir_flash dir", DEV Branch
				{-0.0342286,0.0666545,-0.00385393}
			};
		};
		class rhsusf_acc_anpeq16a_top_light: rhsusf_acc_anpeq16a_top
		{};
		class rhsusf_acc_anpeq16a_top_h: rhsusf_acc_anpeq16a
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0243592,0.0741607,-0.0154256},
				{-0.0349761,0.0256049,-0.0243019},	//"ir_flash dir", DEV Branch
				{-0.0342286,0.0666545,-0.0183539}
			};
		};
		class rhsusf_acc_anpeq16a_top_light_h: rhsusf_acc_anpeq16a_top_h
		{};
		class rhsusf_acc_anpeq16a_top_sc: rhsusf_acc_anpeq16a
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0243592,0.0686607,-0.0197256},
				{-0.0349761,0.0201049,-0.0286019},	//"ir_flash dir", DEV Branch
				{-0.0342286,0.0611545,-0.0226539}
			};
		};
		class rhsusf_acc_anpeq16a_top_light_sc: rhsusf_acc_anpeq16a_top_sc
		{};
	//M952 & WMX
		class rhsusf_acc_m952v: deviceBase_m952
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0810881,-0.0168364,0.0363066}
			};
		};
		class rhsusf_acc_wmx: rhsusf_acc_m952v
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.083932,-0.00471184,0.0352501}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				"gjb_itn_flash_wmx200_vis",
				"gjb_itn_flash_wmx200_ir"
			};
		};
		class rhsusf_acc_wmx_bk: rhsusf_acc_wmx
		{};
	//perst1-ik
		class rhs_acc_perst1ik: acc_pointer_IR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0230783,0.0196943,-0.00828404},
				{0,0,0},
				{0,0,0}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,0,"ON"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{100,0,0},{5,0,0},0.4,0.00001,400,1}
			};
		};
		class rhs_acc_perst1ik_ris: rhs_acc_perst1ik
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0237245,0.00984618,0.0449393},
				{0,0,0},
				{0,0,0}
			};
		};
	//klesh2dp
		class rhs_acc_2dpzenit: acc_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0476827,0.0362558,0.000105539}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,1,"ON"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				"gjb_itn_flash_gen_vis"
			};
		};
		class rhs_acc_2dpzenit_ris: rhs_acc_2dpzenit
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0476827,-0.00794826,0.0361945}
			};
		};
	//perst3
		class rhs_acc_perst3: acc_pointer_IR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0271538,0.0075881,0.0559478},
				{-0.0595559,0.00244527,0.0100904},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
			gjb_itn_controls[]=
			{
				{3,4},
				{3,0},
				{1,1}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{3,0,0,"RED 3"},
				{2,0,0,"RED 2"},
				{1,0,0,"RED 1"},
				{0,0,0,"OFF"},
				{4,0,0,"IR 1"},
				{5,0,0,"IR 2"},
				{6,0,0,"IR 3"},
				{0,7,0,"ILLUMINATOR 1"},
				{0,8,0,"ILLUMINATOR 2"},
				{4,7,0,"IR 1 + ILLUMINATOR 1"},
				{5,7,0,"IR 2 + ILLUMINATOR 1"},
				{6,8,0,"IR 3 + ILLUMINATOR 2"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{2500,0,0},{50,0,0},0.08,0.00001,100,0},
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.2,0.00006,400,0},
				{{100,0,0},{4,0,0},0.3,0.00001,400,1},
				{{1000,0,0},{5,0,0},0.8,0.0001,700,1},
				{{10000,0,0},{6,0,0},1.5,0.0008,1000,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi"
			};
		};
		class rhs_acc_perst3_top: rhs_acc_perst3
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0271538,0.0258257,0.00109411},
				{-0.0595559,0.0716831,-0.00404872},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
		};
		class rhs_acc_perst3_top_h: rhs_acc_perst3
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0271538,0.0201757,-0.00980589},
				{-0.0595559,0.0660331,-0.0149487},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
		};
	//perst3 + klesh2
		class rhs_acc_perst3_2dp_h: acc_pointer_IR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0271538,0.0075881,0.0559478},
				{-0.0595559,0.00244527,0.0100904},	//"ir_flash dir", DEV Branch
				{-0.148401,0.0385748,0.0853492}
			};
			gjb_itn_controls[]=
			{
				{7,8},
				{7,0},
				{1,1}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,9,"VIS Flash"},
				{3,0,9,"RED 3 + Flash"},
				{2,0,9,"RED 2 + Flash"},
				{1,0,9,"RED 1 + Flash"},
				{3,0,0,"RED 3"},
				{2,0,0,"RED 2"},
				{1,0,0,"RED 1"},
				{0,0,0,"OFF"},
				{4,0,0,"IR 1"},
				{5,0,0,"IR 2"},
				{6,0,0,"IR 3"},
				{0,7,0,"ILLUMINATOR 1"},
				{0,8,0,"ILLUMINATOR 2"},
				{4,7,0,"IR 1 + ILLUMINATOR 1"},
				{5,7,0,"IR 2 + ILLUMINATOR 1"},
				{6,8,0,"IR 3 + ILLUMINATOR 2"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{2500,0,0},{50,0,0},0.08,0.00001,100,0},
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{250000,0,0},{50,0,0},0.2,0.00006,400,0},
				{{100,0,0},{4,0,0},0.3,0.00001,400,1},
				{{1000,0,0},{5,0,0},0.8,0.0001,700,1},
				{{10000,0,0},{6,0,0},1.5,0.0008,1000,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_gen_vis"
			};
		};
		class rhs_acc_perst3_2dp_light_h: rhs_acc_perst3_2dp_h
		{};
		class rhs_acc_perst3_2dp: rhs_acc_perst3_2dp_h
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0271538,0.0075881,0.0559478},
				{-0.0595559,0.00244527,0.0100904},	//"ir_flash dir", DEV Branch
				{-0.0476827,0.0976124,0.0360591}
			};
		};
		class rhs_acc_perst3_2dp_light: rhs_acc_perst3_2dp
		{};
//CUP devices=======================================================================//
	//peq15
		class cup_acc_anpeq_15: deviceBase_peq15
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0450204,-0.00489144,0.0469509},
				{-0.0450204,-0.00489144,0.0469509},	
				{0,0,0}
			};
		};
		class cup_acc_anpeq_15_v: cup_acc_anpeq_15
		{};
		class cup_acc_anpeq_15_black: cup_acc_anpeq_15
		{};
		class cup_acc_anpeq_15_black_v: cup_acc_anpeq_15_black
		{};
		class cup_acc_anpeq_15_od: cup_acc_anpeq_15
		{};
		class cup_acc_anpeq_15_od_v: cup_acc_anpeq_15_od
		{};
		class cup_acc_anpeq_15_tan_top: cup_acc_anpeq_15
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0205406,0.0304315,-0.0125795},
				{-0.0205406,0.0304315,-0.0125795},
				{0,0,0}
			};
		};
		class cup_acc_anpeq_15_tan_top_v: cup_acc_anpeq_15_tan_top
		{};
		class cup_acc_anpeq_15_black_top: cup_acc_anpeq_15_tan_top
		{};
		class cup_acc_anpeq_15_black_top_v: cup_acc_anpeq_15_black_top
		{};
		class cup_acc_anpeq_15_od_top: cup_acc_anpeq_15_tan_top
		{};
		class cup_acc_anpeq_15_od_top_v: cup_acc_anpeq_15_od_top
		{};
	//peq15 + m952v
		class cup_acc_anpeq_15_flashlight_tan_l: deviceBase_peq15_comboGen
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0455724,-0.00466293,0.0471343},
				{-0.0455724,-0.00466293,0.0471343},
				{-0.062963,0.0961085,0.0370812}
			};
		};
		class cup_acc_anpeq_15_flashlight_tan_F: cup_acc_anpeq_15_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_flashlight_tan_V: cup_acc_anpeq_15_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_flashlight_od_l: cup_acc_anpeq_15_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_flashlight_od_F: cup_acc_anpeq_15_flashlight_od_l
		{};
		class cup_acc_anpeq_15_flashlight_od_V: cup_acc_anpeq_15_flashlight_od_l
		{};
		class cup_acc_anpeq_15_flashlight_black_l: cup_acc_anpeq_15_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_flashlight_black_F: cup_acc_anpeq_15_flashlight_black_l
		{};
		class cup_acc_anpeq_15_flashlight_black_V: cup_acc_anpeq_15_flashlight_black_l
		{};
		class cup_acc_anpeq_15_top_flashlight_tan_l: cup_acc_anpeq_15_flashlight_tan_l
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.020231,0.0304115,-0.0125038},
				{-0.020231,0.0304115,-0.0125038},
				{-0.062963,-0.0122202,0.036748}
			};
		};
		class cup_acc_anpeq_15_top_flashlight_tan_f: cup_acc_anpeq_15_top_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_top_flashlight_tan_v: cup_acc_anpeq_15_top_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_top_flashlight_od_l: cup_acc_anpeq_15_top_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_top_flashlight_od_f: cup_acc_anpeq_15_top_flashlight_od_l
		{};
		class cup_acc_anpeq_15_top_flashlight_od_v: cup_acc_anpeq_15_top_flashlight_od_l
		{};
		class cup_acc_anpeq_15_top_flashlight_black_l: cup_acc_anpeq_15_top_flashlight_tan_l
		{};
		class cup_acc_anpeq_15_top_flashlight_black_f: cup_acc_anpeq_15_top_flashlight_black_l
		{};
		class cup_acc_anpeq_15_top_flashlight_black_v: cup_acc_anpeq_15_top_flashlight_black_l
		{};
	//peq2
		class cup_acc_anpeq_2_grey: deviceBase_peq2
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0425263,-0.0059574,0.0556513},
				{-0.0425263,-0.0059574,0.0556513},
				{0,0,0}
			};
		};
		class cup_acc_anpeq_2_desert: cup_acc_anpeq_2_grey
		{};
		class cup_acc_anpeq_2_camo: cup_acc_anpeq_2_grey
		{};
		class cup_acc_anpeq_2_black_top: cup_acc_anpeq_2_grey
		{
			gjb_itn_memoryPoints[]=
			{
				{0.00234227,0.0235869,-0.0113415},
				{0.00234227,0.0235869,-0.0113415},
				{0,0,0}
			};
		};
		class cup_acc_anpeq_2_coyote_top: cup_acc_anpeq_2_black_top
		{};
		class cup_acc_anpeq_2_od_top: cup_acc_anpeq_2_black_top
		{};
	//peq2 + m952v
		class cup_acc_anpeq_2_flashlight_black_l: deviceBase_peq2_comboGen
		{
			gjb_itn_memoryPoints[]=
			{
				{0.00198064,0.0235857,-0.0113381},
				{0.00198064,0.0235857,-0.0113381},
				{-0.062963,-0.0122202,0.036748}
			};
		};
		class cup_acc_anpeq_2_flashlight_od_l: cup_acc_anpeq_2_flashlight_black_l
		{};
		class cup_acc_anpeq_2_flashlight_coyote_l: cup_acc_anpeq_2_flashlight_black_l
		{};
		class cup_acc_anpeq_2_flashlight_black_f: cup_acc_anpeq_2_flashlight_black_l
		{};
		class cup_acc_anpeq_2_flashlight_od_f: cup_acc_anpeq_2_flashlight_od_l
		{};
		class cup_acc_anpeq_2_flashlight_coyote_f: cup_acc_anpeq_2_flashlight_coyote_l
		{};
	//m952v
		class cup_acc_flashlight: rhsusf_acc_m952v
		{};
		class cup_acc_flashlight_desert: cup_acc_flashlight
		{};
		class cup_acc_flashlight_wdl: cup_acc_flashlight
		{};
	//llm01
		class cup_acc_llm01_l
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0247245,0.0021095,0.0470302},
				{-0.0247245,0.0021095,0.0470302},
				{-0.032275,-0.0139818,0.035502}
			};
			gjb_itn_controls[]=
			{
				{3,4},
				{3,0},
				{0,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,4,"VIS Marker + Lamp"},
				{0,0,4,"VIS Lamp"},
				{1,0,0,"VIS Marker"},
				{0,0,0,"OFF"},
				{2,0,0,"IR Marker"},
				{0,3,0,"IR Illuminator"},
				{2,3,0,"IR Marker + Illuminator"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				"gjb_itn_flash_dbal_pl_ir",	
				"gjb_itn_flash_gen_vis"
			};
		};
		class cup_acc_llm01_f: cup_acc_llm01_l
		{};
		class cup_acc_llm01_v: cup_acc_llm01_l
		{};
		class cup_acc_llm01_coyote_l: cup_acc_llm01_l
		{};
		class cup_acc_llm01_coyote_f: cup_acc_llm01_coyote_l
		{};
		class cup_acc_llm01_coyote_v: cup_acc_llm01_coyote_l
		{};
		class cup_acc_llm01_desert_l: cup_acc_llm01_l
		{};
		class cup_acc_llm01_desert_f: cup_acc_llm01_desert_l
		{};
		class cup_acc_llm01_desert_v: cup_acc_llm01_desert_l
		{};
		class cup_acc_llm01_hex_l: cup_acc_llm01_l
		{};
		class cup_acc_llm01_hex_f: cup_acc_llm01_hex_l
		{};
		class cup_acc_llm01_hex_v: cup_acc_llm01_hex_l
		{};
		class cup_acc_llm01_od_l: cup_acc_llm01_l
		{};
		class cup_acc_llm01_od_f: cup_acc_llm01_od_l
		{};
		class cup_acc_llm01_od_v: cup_acc_llm01_od_l
		{};
	//llm									(Add GRN variant in compat)
		class cup_acc_llm
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0402674,-0.0123361,0.0333767},
				{-0.0402674,-0.0123361,0.0333767},
				{-0.0577619,-0.00804048,0.0581984}
			};
			gjb_itn_controls[]=
			{
				{3,4},
				{3,0},
				{1,1}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,6,"VIS Marker + Lamp"},
				{0,0,6,"VIS Lamp"},
				{1,0,0,"VIS Marker"},
				{0,0,0,"OFF"},
				{2,0,0,"IR Marker LO"},
				{3,0,0,"IR Marker HI"},
				{0,4,0,"IR Illuminator  LO"},
				{0,5,0,"IR Illuminator HI"},
				{2,4,0,"IR Marker + Illuminator LO"},
				{3,5,0,"IR Marker + Illuminator HI"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
				"gjb_itn_illum_dbal_a2_10_Lo",
				"gjb_itn_illum_dbal_a2_10_Hi",
				"gjb_itn_flash_m952_vis"
			};
		};
		class cup_acc_llm_flashlight: cup_acc_llm
		{};
		class cup_acc_llm_v: cup_acc_llm
		{};
		class cup_acc_llm_black: cup_acc_llm
		{};
		class cup_acc_llm_black_flashlight: cup_acc_llm_black
		{};
		class cup_acc_llm_black_v: cup_acc_llm_black
		{};
		class cup_acc_llm_od: cup_acc_llm
		{};
		class cup_acc_llm_od_flashlight: cup_acc_llm_od
		{};
		class cup_acc_llm_od_v: cup_acc_llm_od
		{};
	//Pistol Lasers
		class cup_acc_glock17_flashlight: acc_flashlight_pistol
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0221782,0.00379688,-0.0364927},
				{0,0,0},
				{-0.0349927,0.000106238,-0.0197455}
			};
			gjb_itn_controls[]=
			{
				{0,2},
				{0,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{0,0,0,"OFF"},
				{1,0,0,"LASER"},
				{0,0,2, "FLASHLIGHT"},
				{1,0,2,"DUAL LIGHT/LASER"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				"gjb_itn_flash_gen_vis"
			};
		};
		class cup_acc_glock17_l: cup_acc_glock17_flashlight
		{};
		class cup_acc_glock17_v: cup_acc_glock17_flashlight
		{};
		class cup_acc_cz_m3x: cup_acc_glock17_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0176356,-0.000355525,-0.032807},
				{0,0,0},
				{-0.0494894,9.02452e-006,-0.0165993}
			};
		};
		class cup_acc_cz_m3x_l: cup_acc_cz_m3x
		{};
		class cup_acc_mk23_lam_f: cup_acc_glock17_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0.014608,0.00598459,-0.0119338},
				{0,0,0},
				{-0.037987,-3.70884e-009,-0.031716}
			};
			gjb_itn_controls[]=
			{
				{4,2},
				{4,2}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,3,"VIS LASER AND ILLUM"},
				{1,0,0,"VIS LASER"},
				{0,0,0,"OFF"},
				{2,0,0,"IR LASER"},
				{2,0,4,"IR LASER AND ILLUM"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{10,0,0},{3,0,0},3,0.00001,150,1},
				"gjb_itn_flash_gen_vis",
				"gjb_itn_flash_pistol_ir"
			};
		};
		class cup_acc_mk23_lam_v: cup_acc_mk23_lam_f
		{};
		class cup_acc_mk23_lam_l: cup_acc_mk23_lam_f
		{};
		class cup_acc_mlpls_laser: acc_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0159931,-0.000314401,-0.0143347},
				{0,0,0},
				{0,0,0}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,0,"LASER"},
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0}
			};
		};
		class cup_acc_lcu_pm_laser: cup_acc_mlpls_laser
		{};
	//Random Lights
		class cup_acc_xm8_light_module: acc_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0604838,-0.0105282,0.0349864}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class cup_acc_zenit_2ds: acc_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0897764,-0.0149663,0.037037}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class cup_acc_flashlight_mp5: acc_flashlight
		{};
		class CUP_acc_Flashlight_MP5SD: cup_acc_flashlight_mp5
		{};
//NIArms devices=====================================================================//
	//DBAL-PL
		class hlc_acc_dbalpl: acc_pointer_IR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0471006,-0.00411236,-0.00992358},
				{-0.0471006,-0.00411236,-0.00992358},
				{-0.0471006,-0.00411236,-0.00992358}
			};
			gjb_itn_controls[]=
			{
				{0,1},
				{-1,0},
				{0,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceModes[]=
			{
				{1,0,4,"VIS AIM/FLOOD"},
				{2,3,0,"IR AIM/ILLUMINATOR"},
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0},
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},
				"gjb_itn_flash_dbal_pl_ir",
				"gjb_itn_flash_dbal_pl_vis"
			};
		};
		class hlc_acc_dbalpl_fl: hlc_acc_dbalpl
		{};
		class hlc_acc_dbalpl_side: hlc_acc_dbalpl
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0471006,0.00707642,0.0410124},
				{-0.0471006,0.00707642,0.0410124},
				{-0.0471006,0.00707642,0.0410124}
			};
		};
		class hlc_acc_dbalpl_side_fl: hlc_acc_dbalpl_side
		{};
	//TLR1
		class hlc_acc_tlr1: acc_flashlight
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0505712,-0.000158894,-0.0229058}
			};
			gjb_itn_controls[]=
			{
				{0,0},
				{-1,0},
				{0,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				"gjb_itn_flash_gen_vis"
			};
		};
		class hlc_acc_tlr1_side: hlc_acc_tlr1
		{
			gjb_itn_memoryPoints[]=
			{
				{0,0,0},
				{0,0,0},
				{-0.0505712,-0.00590583,0.0370589}
			};
		};
//Roanoke's devices=====(In Progress)======================================================//
	//mawl									(characterize)
		class acc_mc1laserROA: deviceBase_mawl
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0714937,0.0243118,-0.00456663},
				{0,0,0},
				{0,0,0}
			};
		};
	//ngal
		class acc_Ngal_F: deviceBase_ngal_comboGenWO
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0220532,0.0547334,-0.0081264},
				{-0.0220532,0.0547334,-0.0081264},
				{-0.0630622,-0.00326606,0.0335759}
			};
		};
		class acc_ngal_f_il: acc_Ngal_F
		{};
//Tier1 devices======================================================================//
		/*class t1_class_la5b : deviceBase_la5b
		{
			gjb_itn_memoryPoints[]=
			{
			};
		};
		class  t1_class_la5b_combo: deviceBase_la5b_comboGenWO
		{
			gjb_itn_memoryPoints[]=
			{
			};
		};*/
	};
//Weapons
	class weapons
	{
		/*	class 
			{
				gjb_itn_memoryPoints[]=
				{
					
				};
			};	*/
	//BIS - Base
		//TAR-21
			class arifle_TRG20_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0981154,0.0378849,0.124945}
				};
			};
			class arifle_TRG21_GL_F: arifle_TRG20_F
			{};
			class arifle_TRG21_F: arifle_TRG20_F
			{};
		//F2000
			class arifle_Mk20_plain_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.10337,0.0470403,0.0891989}
				};
			};
			class arifle_Mk20_F: arifle_Mk20_plain_F
			{};
			class arifle_Mk20_GL_plain_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.10337,0.0578005,0.0886932}
				};
			};
			class arifle_Mk20_GL_F: arifle_Mk20_GL_plain_F
			{};
			class arifle_Mk20C_plain_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.10337,0.0470403,0.0891989}
				};
			};
			class arifle_Mk20C_F: arifle_Mk20C_plain_F
			{};
		//GM Lynx
			class srifle_GM6_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0780196,0.0504675,0.0903694}
				};
			};
			class srifle_GM6_camo_F: srifle_GM6_F
			{};
		//Katiba
			class arifle_Katiba_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0999884,0.0346133,0.10022}
				};
			};
			class arifle_Katiba_GL_F: arifle_Katiba_F
			{};
			class arifle_Katiba_C_F: arifle_Katiba_F
			{};
		//Mk14 EBR
			class srifle_EBR_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.269205,0.0343084,0.116786}
				};
			};
		//MX Series
			class arifle_MX_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.195502,0.0388199,0.121786}
				};
			};
			class arifle_MX_Black_F: arifle_MX_F
			{};
			class arifle_MX_GL_F: arifle_MX_F
			{};
			class arifle_MX_GL_Black_F: arifle_MX_F
			{};
			class arifle_MX_SW_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.179756,0.0388199,0.117347}
				};
			};
			class arifle_MX_SW_Black_F: arifle_MX_SW_F
			{};
			class arifle_MXC_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.115346,0.0388199,0.114347}
				};
			};
			class arifle_MXC_Black_F: arifle_MXC_F
			{};
			class arifle_MXM_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.314528,0.0388199,0.111571}
				};
			};
			class arifle_MXM_Black_F: arifle_MXM_F
			{};
		//Negev
			class LMG_Zafir_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.12101,0.0446722,0.111697}
				};
				gjb_itn_beltFedFix=0.37;
			};
		//P90-TR
			class SMG_03C_TR_black
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0151421,0.0394999,0.133378}
				};
			};
			class SMG_03C_TR_camo: SMG_03C_TR_black
			{};
			class SMG_03C_TR_hex: SMG_03C_TR_black
			{};
			class SMG_03C_TR_khaki: SMG_03C_TR_black
			{};
			class SMG_03_TR_black: SMG_03C_TR_black
			{};
			class SMG_03_TR_camo: SMG_03C_TR_black
			{};
			class SMG_03_TR_hex: SMG_03C_TR_black
			{};
			class SMG_03_TR_khaki: SMG_03C_TR_black
			{};
		//Skorpion EVO
			class SMG_02_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.131691,0.0426543,0.101379}
				};
			};
		//Stoner 99
			class LMG_Mk200_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.20201,0.0511504,0.0998249}
				};
			};
		//VS-121
			class srifle_DMR_01_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.132975,0.0398508,0.108663}
				};
			};
		//MPRL
			class launch_I_Titan_F
			{
				gjb_itn_nonStdRailFix="topRailOnly";
			};
			class launch_O_Titan_F: launch_I_Titan_F
			{};
			class launch_B_Titan_F: launch_I_Titan_F
			{};
		//MPRL Compact
			class launch_O_Titan_short_F
			{
				gjb_itn_nonStdRailFix="topRailOnly";
			};
			class launch_I_Titan_short_F: launch_O_Titan_short_F
			{};
			class launch_B_Titan_short_F: launch_O_Titan_short_F
			{};
	//BIS - Apex
		//AK-15
			class arifle_AK12_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.189083,0.0365383,0.109673}
				};
			};
			class arifle_AK12_GL_F: arifle_AK12_F
			{};
		//FN Minimi SPW
			class LMG_03_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.153801,0.0467144,0.0766314}
				};
			};
		//HK416
			class arifle_SPAR_01_blk_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.249093,0.0393487,0.0985026}
				};
			};
			class arifle_SPAR_01_khk_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_01_snd_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_01_GL_blk_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_01_GL_khk_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_01_GL_snd_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_02_blk_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_02_khk_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_02_snd_F: arifle_SPAR_01_blk_F
			{};
			class arifle_SPAR_03_blk_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.287659,0.0388199,0.101363}
				};
			};
			class arifle_SPAR_03_khk_F: arifle_SPAR_03_blk_F
			{};
			class arifle_SPAR_03_snd_F: arifle_SPAR_03_blk_F
			{};
		//MP5-K
			class SMG_05_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0655187,0.0384541,0.110347}
				};
			};
		//MX Series (Green)
			class arifle_MX_khk_F: arifle_MX_F
			{};
			class arifle_MX_GL_khk_F: arifle_MX_F
			{};
			class arifle_MX_SW_khk_F: arifle_MX_SW_F
			{};
			class arifle_MXC_khk_F: arifle_MXC_F
			{};
			class arifle_MXM_khk_F: arifle_MXM_F
			{};
		//QBZ-95
			class arifle_CTAR_blk_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.137581,0.0388199,0.120143}
				};
			};
			class arifle_CTAR_ghex_F: arifle_CTAR_blk_F
			{};
			class arifle_CTAR_hex_F: arifle_CTAR_blk_F
			{};
			class arifle_CTAR_gl_blk_F: arifle_CTAR_blk_F
			{};
			class arifle_CTAR_gl_ghex_F: arifle_CTAR_blk_F
			{};
			class arifle_CTAR_gl_hex_F: arifle_CTAR_blk_F
			{};
			class arifle_CTARS_blk_F: arifle_CTAR_blk_F
			{};
			class arifle_CTARS_ghex_F: arifle_CTAR_blk_F
			{};
			class arifle_CTARS_hex_F: arifle_CTAR_blk_F
			{};
		//Type 115
			class arifle_ARX_blk_F
			{
				gjb_itn_nonStdRailFix="leftRailOnly";
				gjb_itn_memoryPoints[]=
				{
					{-0.222606,-0.0362163,0.0065527}
				};
			};
			class arifle_ARX_ghex_F: arifle_ARX_blk_F
			{};
			class arifle_ARX_hex_F: arifle_ARX_blk_F
			{};
		//MPRL
			class launch_O_Titan_ghex_F: launch_I_Titan_F
			{};
			class launch_B_Titan_tna_F: launch_I_Titan_F
			{};
		//MPRL Compact
			class launch_O_Titan_short_ghex_F: launch_O_Titan_short_F
			{};
			class launch_B_Titan_short_tna_F: launch_O_Titan_short_F
			{};
	//BIS - Contact
		//AK-15
			class arifle_AK12_arid_F: arifle_AK12_F
			{};
			class arifle_AK12_lush_F: arifle_AK12_F
			{};
			class arifle_AK12_GL_arid_F: arifle_AK12_F
			{};
			class arifle_AK12_GL_lush_F: arifle_AK12_F
			{};
			class arifle_AK12U_F: arifle_AK12_F
			{};
			class arifle_AK12U_arid_F: arifle_AK12_F
			{};
			class arifle_AK12U_lush_F: arifle_AK12_F
			{};
		//MSBS 
			class arifle_MSBS65_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.156688,0.0526744,0.0701674}
				};
			};
			class arifle_MSBS65_black_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_camo_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_sand_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_GL_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_GL_black_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_GL_camo_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_GL_sand_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_Mark_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_Mark_black_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_Mark_camo_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_Mark_sand_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_UBS_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_UBS_black_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_UBS_camo_F: arifle_MSBS65_F
			{};
			class arifle_MSBS65_UBS_sand_F: arifle_MSBS65_F
			{};
		//RPK
			class arifle_RPK12_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.175707,0.0366832,0.113265}
				};
			};
			class arifle_RPK12_arid_F: arifle_RPK12_F
			{};
			class arifle_RPK12_lush_F: arifle_RPK12_F
			{};
		//Stoner 99
			class LMG_Mk200_black_F: LMG_Mk200_F
			{};
		//MPRL
			class launch_B_Titan_olive_F: launch_I_Titan_F
			{};
			class launch_B_Titan_eaf_F: launch_I_Titan_F
			{};
	//BIS - Marksmen DLC
		//ASP-1
			class srifle_DMR_04_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.265774,0.0473997,0.122518}
				};
			};
			class srifle_DMR_04_Tan_F: srifle_DMR_04_F
			{};
		//Cyrus
			class srifle_DMR_05_blk_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.367816,0.0535279,0.110453}
				};
			};
			class srifle_DMR_05_hex_F: srifle_DMR_05_blk_F
			{};
			class srifle_DMR_05_tan_f: srifle_DMR_05_blk_F
			{};
		//HK121
			class MMG_01_hex_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.355775,0.0379835,0.0646645}
				};
			};
			class MMG_01_tan_F: MMG_01_hex_F
			{};
		//LWMMG
			class MMG_02_black_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.375353,0.0485796,0.0766925}
				};
			};
			class MMG_02_camo_F: MMG_02_black_F
			{};
			class MMG_02_sand_F: MMG_02_black_F
			{};
		//Noreen ULR
			class srifle_DMR_02_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.439697,0.0473219,0.111457}
				};
			};
			class srifle_DMR_02_camo_F: srifle_DMR_02_F
			{};
			class srifle_DMR_02_sniper_F: srifle_DMR_02_F
			{};
		//SIG556
			class srifle_DMR_03_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.264756,0.0393498,0.123392}
				};
			};
			class srifle_DMR_03_multicam_F: srifle_DMR_03_F
			{};
			class srifle_DMR_03_khaki_F: srifle_DMR_03_F
			{};
			class srifle_DMR_03_tan_F: srifle_DMR_03_F
			{};
			class srifle_DMR_03_woodland_F: srifle_DMR_03_F
			{};
	//BIS - Tanks DLC
		//MAAWS
			class launch_MRAWS_green_rail_F
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.398505,0.084,0.009}
				};
				gjb_itn_beltFedFix=0.05;
			};
			class launch_MRAWS_olive_rail_F: launch_MRAWS_green_rail_F
			{};
			class launch_MRAWS_sand_rail_F: launch_MRAWS_green_rail_F
			{};
			class launch_MRAWS_green_F: launch_MRAWS_green_rail_F
			{};
			class launch_MRAWS_olive_F: launch_MRAWS_green_rail_F
			{};
			class launch_MRAWS_sand_F: launch_MRAWS_green_rail_F
			{};
	//
	//Fixes
		//NIArms
			//M249
				class hlc_m249_SQuantoon
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.17556,0.047151,0.0603418}
					};
					gjb_itn_beltFedFix=0.27;
				};
				class hlc_m249_pip4: hlc_m249_SQuantoon
				{};
			//Mk46
				class hlc_lmg_mk46
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.22947,0.0502855,0.0903269}
					};
					gjb_itn_beltFedFix=0.26;
				};
				class hlc_lmg_mk46mod1: hlc_lmg_mk46
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.227471,0.0508562,0.0839419}
					};
				};
			//Mk48
				class hlc_lmg_mk48
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.250428,0.0502855,0.0903269}
					};
					gjb_itn_beltFedFix=0.24;
				};
				class hlc_lmg_mk48mod1: hlc_lmg_mk48
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.19472,0.0508562,0.0839419}
					};
					gjb_itn_beltFedFix=0.29;
				};
			//MG3
				class hlc_lmg_MG3KWS_b
				{
					gjb_itn_nonStdRailFix="leftRailOnly";
					gjb_itn_memoryPoints[]=
					{
						{-0.518157,-0.0483725,0.00838994}
					};
					gjb_itn_beltFedFix=0.15;
				};
				class hlc_lmg_MG3KWS_g: hlc_lmg_MG3KWS_b
				{};
				class hlc_lmg_MG3KWS: hlc_lmg_MG3KWS_b
				{};
			//MG42
				class hlc_lmg_mg42kws_b: hlc_lmg_MG3KWS_b
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.485,-0.047,0.0137}
					};
					gjb_itn_beltFedFix=0.19;
				};
				class hlc_lmg_mg42kws_g: hlc_lmg_mg42kws_b
				{};
				class hlc_lmg_mg42kws_t: hlc_lmg_mg42kws_b
				{};
		//RHS
			//RPK
				class rhs_weap_rpk74m
				{
					gjb_itn_nonStdRailFix="leftRailOnly";
				};
				class rhs_weap_rpk74m_npz: rhs_weap_rpk74m
				{};
			//AS VAL, VSS Vintorez
				class rhs_weap_asval_grip
				{
					gjb_itn_nonStdRailFix="bottomRailOnly";
				};
				class rhs_weap_asval_grip_npz: rhs_weap_asval_grip
				{};
				class rhs_weap_vss_grip: rhs_weap_asval_grip
				{};
				class rhs_weap_vss_grip_npz: rhs_weap_asval_grip
				{};
			//M249
				class rhs_weap_m249_light_L 
				{
					gjb_itn_beltFedFix=0.1;
				};
				class rhs_weap_m249_pip_L_para: rhs_weap_m249_light_L
				{};
				class rhs_weap_m249_pip_L: rhs_weap_m249_light_L
				{};
				class rhs_weap_m249_pip_ris: rhs_weap_m249_light_L
				{};
				class rhs_weap_m249_light_S: rhs_weap_m249_light_L
				{};
				class rhs_weap_m249_pip_S_para: rhs_weap_m249_light_L
				{};
				class rhs_weap_m249_pip_S: rhs_weap_m249_light_L
				{};
			//M72 LAW
				class rhs_weap_m72a7
				{
					gjb_itn_nonStdRailFix="topRailOnly";
					gjb_itn_beltFedFix=0.4;
				};
			//Minimi
				class rhs_weap_minimi_para_railed
				{
					gjb_itn_beltFedFix=0.1;
				};
			//Mk11 Mod0
				class rhs_weap_sr25
				{
					gjb_itn_nonStdRailFix="leftRailOnly";
				};
				class rhs_weap_sr25_d: rhs_weap_sr25
				{};
				class rhs_weap_sr25_wd: rhs_weap_sr25
				{};
				class rhs_weap_sr25_ec: rhs_weap_sr25
				{};
				class rhs_weap_sr25_ec_d: rhs_weap_sr25
				{};
				class rhs_weap_sr25_ec_wd: rhs_weap_sr25
				{};
			//MP7 Pistol
				class rhsusf_weap_mp7a2_folded
				{
					gjb_itn_nonStdRailFix="rifleNotPistol";
				};
				class rhsusf_weap_mp7a2_folded_aor1: rhsusf_weap_mp7a2_folded
				{};
				class rhsusf_weap_mp7a2_folded_desert: rhsusf_weap_mp7a2_folded
				{};
				class rhsusf_weap_mp7a2_folded_winter: rhsusf_weap_mp7a2_folded
				{};
			//SMAW
				class rhs_weap_smaw
				{
					gjb_itn_nonStdRailFix="leftRailOnly";
					gjb_itn_beltFedFix=0.4;
				};
				class rhs_weap_smaw_green: rhs_weap_smaw
				{};
			//Socom16
				class rhs_weap_m14_socom_rail
				{
					gjb_itn_nonStdRailFix="topRailOnly";
				};
		//CUP
			//L85
				class CUP_arifle_L85A2_NG
				{
					gjb_itn_beltFedFix=0.16;
				};
				class CUP_arifle_L85A2_G: CUP_arifle_L85A2_NG
				{};
				class CUP_arifle_L85A2_GL
				{
					gjb_itn_beltFedFix=0.08;
				};
			//Launchers
				class CUP_launch_Mk153Mod0
				{
					gjb_itn_nonStdRailFix="leftRailOnly";
					gjb_itn_beltFedFix=0.47;
				};
				class CUP_launch_Mk153Mod0_blk: CUP_launch_Mk153Mod0
				{};
	};
};