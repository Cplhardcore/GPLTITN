class CfgITNCompat
{
//Accessories
	class accessories
	{
		class deviceBase_mawl;
		class deviceBase_ngal_comboWO;
	//mawl
		/*class acc_mc1laserROA: deviceBase_mawl
		{
			gjb_itn_interface[]=
			{
				"generic",	//"mawl"
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};*/
	//ngal
		class acc_Ngal_F: deviceBase_ngal_comboWO
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0220532,0.0547334,-0.0081264},
				{-0.0220532,0.0547334,-0.0081264},
				{-0.0630622,-0.00326606,0.0335759}
			};
			gjb_itn_interface[]=
			{
				"ngal_combo",
				"Rsc_gjb_itn_ngal_roa",
				"\gjb_itn\addons\gjb_itn_compat_roa\ui\ngal",
				"\gjb_itn\addons\gjb_itn_compat_roa\ui\m300"
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
	};
//Weapons
	class weapons
	{
	};
};