class CfgITNCompat
{
//Accessories
	class accessories
	{
		class deviceBase_la5b;
		class deviceBase_la5b_comboGenVIR;
		class deviceBase_la5b_comboVIR;
		class deviceBase_ngal;
		class deviceBase_ngal_comboGenWO;
		class deviceBase_ngal_comboGenVIR;
		class deviceBase_ngal_comboWO;
		class deviceBase_ngal_comboVIR;
		/LAMG
			class GPLT_sideLAMG_1_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00314038,0.0280959,-0.0219772},
						{0.00314038,0.0280959,-0.0219772},
						{-0.0441965,-0.00256648,0.0344117}
					};
					gjb_itn_interface[]=
					{
						"generic", //la_5b_combo
						"Rsc_gjb_itn_generic_deviceclass"
					};
				};
		//LA5B
			class GPLT_SideFSP3_LASER: deviceBase_la5b
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.124116,0.0342058,-0.0504326},
					{-0.124116,0.0342058,-0.0504326},
					{0,0,0}
				};
				gjb_itn_interface[]=
				{
					"generic", //la_5b
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideFSP3_Vis_Laser: GPLT_SideFSP3_LASER
			{};
			class GPLT_SideFSP3_FLASH: GPLT_SideFSP3_LASER
			{};
			class GPLT_SideLima_LASER: GPLT_SideFSP3_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0325237,-0.0317199,0.0217183},
					{-0.0325237,-0.0317199,0.0217183},
					{0,0,0}
				};
			};
			class GPLT_SideLima_Vis_Laser: GPLT_SideLima_LASER
			{};
			class GPLT_SideLima_FLASH: GPLT_SideLima_LASER
			{};
			class GPLT_SideMonsoor_LASER: GPLT_SideFSP3_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0268072,0.0424439,-0.020848},
					{-0.0268072,0.0424439,-0.020848},
					{0,0,0}
				};
			};
			class GPLT_SideMonsoor_Vis_Laser: GPLT_SideMonsoor_LASER
			{};
			class GPLT_SideMonsoor_FLASH: GPLT_SideMonsoor_LASER
			{};
			class GPLT_SideMRAD_LASER: GPLT_SideFSP3_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.136676,0.0352467,-0.0525828},
					{-0.136676,0.0352467,-0.0525828},
					{0,0,0}
				};
			};
			class GPLT_SideMRAD_Vis_Laser: GPLT_SideMRAD_LASER
			{};
			class GPLT_SideMRAD_FLASH: GPLT_SideMRAD_LASER
			{};
			class GPLT_SideSASS_LASER: GPLT_SideFSP3_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0182602,0.0342705,-0.0532825},
					{-0.0182602,0.0342705,-0.0532825},
					{0,0,0}
				};
			};
			class GPLT_SideSASS_Vis_Laser: GPLT_SideSASS_LASER
			{};
			class GPLT_SideSASS_FLASH: GPLT_SideSASS_LASER
			{};
			class GPLT_SideSCAR2_LASER: GPLT_SideFSP3_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0665806,0.0349925,-0.0661533},
					{-0.0665806,0.0349925,-0.0661533},
					{0,0,0}
				};
			};
			class GPLT_SideSCAR2_Vis_Laser: GPLT_SideSCAR2_LASER
			{};
			class GPLT_SideSCAR2_FLASH: GPLT_SideSCAR2_LASER
			{};
		//LA5B + WMX
			class GPLT_SideBlock_LASER: deviceBase_la5b_comboGenVIR
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.104871,0.0226421,0.00964181},
					{-0.104871,0.0226421,0.00964181},
					{-0.158386,0.0440008,-0.0245223}
				};
				gjb_itn_interface[]=
				{
					"generic", //la_5b_combo
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideBlock_Vis_Laser: GPLT_SideBlock_LASER
			{};
			class GPLT_SideBlock_FLASH: GPLT_SideBlock_LASER
			{};/*
			class GPLT_SideEBR_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{},
					{},
					{}
				};
			};
			class GPLT_SideEBR_Vis_Laser: GPLT_SideEBR_LASER
			{};
			class GPLT_SideEBR_FLASH: GPLT_SideEBR_LASER
			{};*/
			class GPLT_SideFSP_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.153753,0.0220119,0.00922584},
					{-0.153753,0.0220119,0.00922584},
					{-0.186926,0.0433706,-0.0249383}
				};
			};
			class GPLT_SideFSP_Vis_Laser: GPLT_SideFSP_LASER
			{};
			class GPLT_SideFSP_FLASH: GPLT_SideFSP_LASER
			{};
			class GPLT_SideFSP2_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0158161,0.0213502,0.00909799},
					{-0.0158161,0.0213502,0.00909799},
					{-0.160048,0.0432247,-0.0219228}
				};
			};
			class GPLT_SideFSP2_Vis_Laser: GPLT_SideFSP2_LASER
			{};
			class GPLT_SideFSP2_FLASH: GPLT_SideFSP2_LASER
			{};
			class GPLT_SideHound_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.10025,0.0229773,0.00983691},
					{-0.10025,0.0229773,0.00983691},
					{-0.0953981,0.0418601,-0.0282062}
				};
			};
			class GPLT_SideHound_Vis_Laser: GPLT_SideHound_LASER
			{};
			class GPLT_SideHound_FLASH: GPLT_SideHound_LASER
			{};
			class GPLT_SideHound2_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0715816,0.0332094,-0.0553189},
					{-0.0715816,0.0332094,-0.0553189},
					{-0.09278,-0.0422672,-0.0345861}
				};
			};
			class GPLT_SideHound2_Vis_Laser: GPLT_SideHound2_LASER
			{};
			class GPLT_SideHound2_FLASH: GPLT_SideHound2_LASER
			{};
			class GPLT_SideLURGI_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0846088,0.0232258,0.0102457},
					{-0.0846088,0.0232258,0.0102457},
					{-0.117782,0.0445845,-0.0239184}
				};
			};
			class GPLT_SideLURGI_Vis_Laser: GPLT_SideLURGI_LASER
			{};
			class GPLT_SideLURGI_FLASH: GPLT_SideLURGI_LASER
			{};
			class GPLT_SideLURGI2_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{0.0895537,0.0233287,0.00985665},
					{0.0895537,0.0233287,0.00985665},
					{-0.117782,0.0446874,-0.0243075}
				};
			};
			class GPLT_SideLURGI2_Vis_Laser: GPLT_SideLURGI2_LASER
			{};
			class GPLT_SideLURGI2_FLASH: GPLT_SideLURGI2_LASER
			{};
			class GPLT_SideMod_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0372351,0.0219663,0.00917259},
					{-0.0372351,0.0219663,0.00917259},
					{-0.0971142,0.0433705,-0.0229798}
				};
			};
			class GPLT_SideMod_Vis_Laser: GPLT_SideMod_LASER
			{};
			class GPLT_SideMod_FLASH: GPLT_SideMod_LASER
			{};/*
			class GPLT_SideMonsoor2_LASER: GPLT_SideBlock_LASER	//way to high right forward
			{
				gjb_itn_memoryPoints[]=
				{
					{},
					{},
					{}
				};
			};
			class GPLT_SideMonsoor2_Vis_Laser: GPLT_SideMonsoor2_LASER
			{};
			class GPLT_SideMonsoor2_FLASH: GPLT_SideMonsoor2_LASER
			{};*/
			class GPLT_SideSCAR_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0601169,0.0221503,0.0103575},
					{-0.0601169,0.0221503,0.0103575},
					{-0.0740561,0.0413396,-0.0183965}
				};
			};
			class GPLT_SideSCAR_Vis_Laser: GPLT_SideSCAR_LASER
			{};
			class GPLT_SideSCAR_FLASH: GPLT_SideSCAR_LASER
			{};
			class GPLT_SideSURGI_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{0.084937,0.0237426,0.00955612},
					{0.084937,0.0237426,0.00955612},
					{-0.0103059,0.044143,-0.0247806}
				};
			};
			class GPLT_SideSURGI_Vis_Laser: GPLT_SideSURGI_LASER
			{};
			class GPLT_SideSURGI_FLASH: GPLT_SideSURGI_LASER
			{};
			class GPLT_SideSURGI3_LASER: GPLT_SideBlock_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{0.0249036,0.0246607,0.00990411},
					{0.0249036,0.0246607,0.00990411},
					{-0.00826921,0.0460194,-0.02426}
				};
			};
			class GPLT_SideSURGI3_Vis_Laser: GPLT_SideSURGI3_LASER
			{};
			class GPLT_SideSURGI3_FLASH: GPLT_SideSURGI3_LASER
			{};
		//LA5B + M3X-200
			class GPLT_SideBlock2_LASER: deviceBase_la5b_comboGenVIR
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.104871,0.0226421,0.00964181},
					{-0.104871,0.0226421,0.00964181},
					{-0.15345,0.0440008,-0.0265665}
				};
				gjb_itn_interface[]=
				{
					"generic", //la_5b_combo
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideBlock2_Vis_Laser: GPLT_SideBlock2_LASER
			{};
			class GPLT_SideBlock2_FLASH: GPLT_SideBlock2_LASER
			{};
			class GPLT_SideMod2_LASER: GPLT_SideBlock2_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0372351,0.0225521,0.00974869},
					{-0.0372351,0.0225521,0.00974869},
					{-0.085989,0.0439563,-0.0261443}
				};
			};
			class GPLT_SideMod2_Vis_Laser: GPLT_SideMod2_LASER
			{};
			class GPLT_SideMod2_FLASH: GPLT_SideMod2_LASER
			{};/*
		//NGAL
			class GPLT_SideMonsoor3_LASER: deviceBase_ngal	//way to high front left
			{
				gjb_itn_memoryPoints[]=
				{
					{},
					{},
					{}
				};
				gjb_itn_interface[]=
				{
					"generic", //ngal
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideMonsoor3_Vis_Laser: GPLT_SideMonsoor3_LASER
			{};
			class GPLT_SideMonsoor3_FLASH: GPLT_SideMonsoor3_LASER
			{};*/
		//NGAL + WMX
			class GPLT_SideFSP4_LASER: deviceBase_ngal_comboGenVIR
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.147461,0.0178189,0.0180332},
					{-0.147461,0.0178189,0.0180332},
					{-0.184714,-0.0411218,-0.00274943}
				};
				gjb_itn_interface[]=
				{
					"generic", //ngal_combo
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideFSP4_Vis_Laser: GPLT_SideFSP4_LASER
			{};
			class GPLT_SideFSP4_FLASH: GPLT_SideFSP4_LASER
			{};
			class GPLT_SideLURGI3_LASER: GPLT_SideFSP4_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0968189,0.0194645,0.00674649},
					{-0.0968189,0.0194645,0.00674649},
					{-0.15672,-0.0406184,-0.00160074}
				};
			};
			class GPLT_SideLURGI3_Vis_Laser: GPLT_SideLURGI3_LASER
			{};
			class GPLT_SideLURGI3_FLASH: GPLT_SideLURGI3_LASER
			{};
			class GPLT_SideLURGI4_LASER: GPLT_SideFSP4_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0873638,0.0341644,-0.0444541},
					{-0.0873638,0.0341644,-0.0444541},
					{-0.120299,-0.037625,-0.0033277}
				};
			};
			class GPLT_SideLURGI4_Vis_Laser: GPLT_SideLURGI4_LASER
			{};
			class GPLT_SideLURGI4_FLASH: GPLT_SideLURGI4_LASER
			{};
			class GPLT_SideMod3_LASER: GPLT_SideFSP4_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0470857,0.0156678,0.00669407},
					{-0.0470857,0.0156678,0.00669407},
					{-0.108367,0.0405131,-0.00295485}
				};
			};
			class GPLT_SideMod3_Vis_Laser: GPLT_SideMod3_LASER
			{};
			class GPLT_SideMod3_FLASH: GPLT_SideMod3_LASER
			{};/*
			class GPLT_SideMonsoor4_LASER: GPLT_SideFSP4_LASER	//way to high forward, roughly center to proxy
			{
				gjb_itn_memoryPoints[]=
				{
					{},
					{},
					{}
				};
			};
			class GPLT_SideMonsoor4_Vis_Laser: GPLT_SideMonsoor4_LASER
			{};
			class GPLT_SideMonsoor4_FLASH: GPLT_SideMonsoor4_LASER
			{};*/
			class GPLT_SideSURGI4_LASER: GPLT_SideFSP4_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{0.00641891,0.0169099,0.00688798},
					{0.00641891,0.0169099,0.00688798},
					{-0.0241515,0.042763,-0.00210545}
				};
			};
			class GPLT_SideSURGI4_Vis_Laser: GPLT_SideSURGI4_LASER
			{};
			class GPLT_SideSURGI4_FLASH: GPLT_SideSURGI4_LASER
			{};
		//NGAL + M3X-200
			class GPLT_SideSCAR3_LASER: deviceBase_ngal_comboGenVIR
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0527679,0.0159203,0.00748659},
					{-0.0527679,0.0159203,0.00748659},
					{-0.0553423,0.0444841,-0.0438607}
				};
				gjb_itn_interface[]=
				{
					"generic", //ngal_combo
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideSCAR3_Vis_Laser: GPLT_SideSCAR3_LASER
			{};
			class GPLT_SideSCAR3_FLASH: GPLT_SideSCAR3_LASER
			{};
			class GPLT_SideSURGI2_LASER: GPLT_SideSCAR3_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{0.0881184,0.0168163,0.00665757},
					{0.0881184,0.0168163,0.00665757},
					{-0.032999,0.0462687,-0.0271074}
				};
			};
			class GPLT_SideSURGI2_Vis_Laser: GPLT_SideSURGI2_LASER
			{};
			class GPLT_SideSURGI2_FLASH: GPLT_SideSURGI2_LASER
			{};
		//NGAL + Modlight
			class GPLT_SideLT_LASER: deviceBase_ngal_comboGenWO
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0918739,0.015958,0.0118999},
					{-0.0918739,0.015958,0.0118999},
					{-0.154575,0.0308994,-0.00516383}
				};
				gjb_itn_interface[]=
				{
					"generic", //ngal_combo
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideLT_Vis_Laser: GPLT_SideLT_LASER
			{};
			class GPLT_SideLT_FLASH: GPLT_SideLT_LASER
			{};
			class GPLT_SideLT2_LASER: GPLT_SideLT_LASER
			{
				gjb_itn_memoryPoints[]=
				{
					{0.0456217,0.015958,0.0118999},
					{0.0456217,0.015958,0.0118999},
					{-0.121484,0.0308994,-0.00516383}
				};
			};
			class GPLT_SideLT2_Vis_Laser: GPLT_SideLT2_LASER
			{};
			class GPLT_SideLT2_FLASH: GPLT_SideLT2_LASER
			{};
		//MAWL + M600
			class GPLT_SideLT4_LASER: deviceBase_ngal_comboGenVIR
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.103569,0.0408642,0.0160881},
					{-0.103569,0.0408642,0.0160881},
					{-0.120531,0.0445017,-0.0319771}
				};
				gjb_itn_interface[]=
				{
					"generic", //mawl_combo
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideLT4_Vis_Laser: GPLT_SideLT4_LASER
			{};
			class GPLT_SideLT4_FLASH: GPLT_SideLT4_LASER
			{};
		//RAID-X + M300
			class GPLT_SideLT3_LASER: deviceBase_ngal_comboGenWO
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.0889901,4.06637e-005,0.0227054},
					{-0.0889901,4.06637e-005,0.0227054},
					{-0.111995,-0.0387956,-0.0108937}
				};
				gjb_itn_interface[]=
				{
					"generic", //raidx_combo
					"Rsc_gjb_itn_generic_deviceclass"
				};
			};
			class GPLT_SideLT3_Vis_Laser: GPLT_SideLT3_LASER
			{};
			class GPLT_SideLT3_FLASH: GPLT_SideLT3_LASER
			{};
	};
//Weapons
	class weapons
	{
		class GPLT_M110_SASS
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.301,0,0.101}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_M110K1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.301,0,0.101}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_M240L
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.375,0,0.044}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_Block_II
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.188,0,0.099}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_FSP_Base
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.188,0,0.099}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_MK17	//collision with geometry
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.172,0,0.119}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_MK18
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.188,0,0.099}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_MK48
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.242,0,0.037}
			};
			gjb_itn_nonStdRailFix="rawPos";
			gjb_itn_beltFedFix=0.18;
		};
		class GPLT_MK48_S
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.242,0,0.037}
			};
			gjb_itn_nonStdRailFix="rawPos";
			gjb_itn_beltFedFix=0.18;
		};
		class GPLT_MRAD
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.321,0,0.107}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_SPEAR_LT
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.188,0,0.099}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_URGI_10
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.234,0.001,0.098}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_URGI_14
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.234,0.001,0.098}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
	};
};