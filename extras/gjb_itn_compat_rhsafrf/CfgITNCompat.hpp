class CfgITNCompat
{
//Accessories
	class accessories
	{
		class acc_flashlight;
		class acc_pointer_IR;
	//perst1-ik
		class rhs_acc_perst1ik: acc_flashlight
		{
			gjb_itn_interface[]=
			{
				"utg",
				"Rsc_gjb_itn_perst1_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst1"
			};
		};
	//perst1-k
		class rhs_acc_perst1_k: rhs_acc_perst1ik
		{
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{25000,0,0},{50,0,0},0.12,0.00003,200,0}
			};
		};
		class rhs_acc_perst1_k_ris: rhs_acc_perst1_k
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
			gjb_itn_interface[]=
			{
				"utg",
				"Rsc_gjb_itn_klesh2_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\klesh2"
			};
		};
	//perst3
		class rhs_acc_perst3: acc_pointer_IR
		{
			gjb_itn_interface[]=
			{
				"perst3",
				"Rsc_gjb_perst3_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst3"
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
				{6,7,0,"IR 3 + ILLUMINATOR 1"},
				{4,8,0,"IR 1 + ILLUMINATOR 2"},
				{5,8,0,"IR 2 + ILLUMINATOR 2"},
				{6,8,0,"IR 3 + ILLUMINATOR 2"}
			};
		};
		class rhs_acc_perst3_top: rhs_acc_perst3
		{};
		class rhs_acc_perst3_top_h: rhs_acc_perst3
		{};
	//perst3G+
		class rhs_acc_perst3_g: rhs_acc_perst3
		{
			gjb_itn_interface[]=
			{
				"perst3",
				"Rsc_gjb_perst3_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst3g"
			};
			gjb_itn_deviceModes[]=
			{
				{3,0,0,"GREEN 3"},
				{2,0,0,"GREEN 2"},
				{1,0,0,"GREEN 1"},
				{0,0,0,"OFF"},
				{4,0,0,"IR 1"},
				{5,0,0,"IR 2"},
				{6,0,0,"IR 3"},
				{0,7,0,"ILLUMINATOR 1"},
				{0,8,0,"ILLUMINATOR 2"},
				{4,7,0,"IR 1 + ILLUMINATOR 1"},
				{5,7,0,"IR 2 + ILLUMINATOR 1"},
				{6,7,0,"IR 3 + ILLUMINATOR 1"},
				{4,8,0,"IR 1 + ILLUMINATOR 2"},
				{5,8,0,"IR 2 + ILLUMINATOR 2"},
				{6,8,0,"IR 3 + ILLUMINATOR 2"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{0,2500,0},{0,50,0},0.08,0.00001,100,0},
				{{0,25000,0},{0,50,0},0.12,0.00003,200,0},
				{{0,250000,0},{0,50,0},0.2,0.00006,400,0},
				{{100,0,0},{4,0,0},0.3,0.00001,400,1},
				{{1000,0,0},{5,0,0},0.8,0.0001,700,1},
				{{10000,0,0},{6,0,0},1.5,0.0008,1000,1},
				"gjb_itn_illum_perst3_10_Lo",
				"gjb_itn_illum_perst3_10_Hi"
			};
		};
		class rhs_acc_perst3_g_top: rhs_acc_perst3_g
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0271538,0.0258257,0.00109411},
				{-0.0595559,0.0716831,-0.00404872},	//"ir_flash dir", DEV Branch
				{0,0,0}
			};
		};
		class rhs_acc_perst3_g_top_h: rhs_acc_perst3_g
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
			gjb_itn_controls[]=
			{
				{18,19},
				{18,11},
				{1,1}
			};
			gjb_itn_interface[]=
			{
				"perst3_combo",
				"Rsc_gjb_perst3_combo_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst3",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\klesh2"
			};
			gjb_itn_deviceModes[]=
			{
				{4,0,9,"IR 1 + Flash"},
				{5,0,9,"IR 2 + Flash"},
				{6,0,9,"IR 3 + Flash"},
				{0,7,9,"ILLUMINATOR 1 + Flash"},
				{0,8,9,"ILLUMINATOR 2 + Flash"},
				{4,7,9,"IR 1 + ILLUMINATOR 1 + Flash"},
				{5,7,9,"IR 2 + ILLUMINATOR 1 + Flash"},
				{6,7,9,"IR 3 + ILLUMINATOR 1 + Flash"},
				{4,8,9,"IR 1 + ILLUMINATOR 2 + Flash"},
				{5,8,9,"IR 2 + ILLUMINATOR 2 + Flash"},
				{6,8,9,"IR 3 + ILLUMINATOR 2 + Flash"},
				//
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
				{6,7,0,"IR 3 + ILLUMINATOR 1"},
				{4,8,0,"IR 1 + ILLUMINATOR 2"},
				{5,8,0,"IR 2 + ILLUMINATOR 2"},
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
				"gjb_itn_illum_perst3_10_Lo",
				"gjb_itn_illum_perst3_10_Hi",
				"gjb_itn_flash_gen_vis"
			};
		};
		class rhs_acc_perst3_2dp_light_h: rhs_acc_perst3_2dp_h
		{};
		class rhs_acc_perst3_2dp: rhs_acc_perst3_2dp_h
		{};
		class rhs_acc_perst3_2dp_light: rhs_acc_perst3_2dp_h
		{};
	//perst3G+ + klesh2
		class rhs_acc_perst3_g_2dp_h: rhs_acc_perst3_2dp_h
		{
			gjb_itn_interface[]=
			{
				"perst3_combo",
				"Rsc_gjb_perst3_combo_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst3g",
				"\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\klesh2"
			};
			gjb_itn_deviceModes[]=
			{
				{4,0,9,"IR 1 + Flash"},
				{5,0,9,"IR 2 + Flash"},
				{6,0,9,"IR 3 + Flash"},
				{0,7,9,"ILLUMINATOR 1 + Flash"},
				{0,8,9,"ILLUMINATOR 2 + Flash"},
				{4,7,9,"IR 1 + ILLUMINATOR 1 + Flash"},
				{5,7,9,"IR 2 + ILLUMINATOR 1 + Flash"},
				{6,7,9,"IR 3 + ILLUMINATOR 1 + Flash"},
				{4,8,9,"IR 1 + ILLUMINATOR 2 + Flash"},
				{5,8,9,"IR 2 + ILLUMINATOR 2 + Flash"},
				{6,8,9,"IR 3 + ILLUMINATOR 2 + Flash"},
				//
				{0,0,9,"VIS Flash"},
				{3,0,9,"GREEN 3 + Flash"},
				{2,0,9,"GREEN 2 + Flash"},
				{1,0,9,"GREEN 1 + Flash"},
				{3,0,0,"GREEN 3"},
				{2,0,0,"GREEN 2"},
				{1,0,0,"GREEN 1"},
				{0,0,0,"OFF"},
				{4,0,0,"IR 1"},
				{5,0,0,"IR 2"},
				{6,0,0,"IR 3"},
				{0,7,0,"ILLUMINATOR 1"},
				{0,8,0,"ILLUMINATOR 2"},
				{4,7,0,"IR 1 + ILLUMINATOR 1"},
				{5,7,0,"IR 2 + ILLUMINATOR 1"},
				{6,7,0,"IR 3 + ILLUMINATOR 1"},
				{4,8,0,"IR 1 + ILLUMINATOR 2"},
				{5,8,0,"IR 2 + ILLUMINATOR 2"},
				{6,8,0,"IR 3 + ILLUMINATOR 2"}
			};
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",
				{{0,2500,0},{0,50,0},0.08,0.00001,100,0},
				{{0,25000,0},{0,50,0},0.12,0.00003,200,0},
				{{0,250000,0},{0,50,0},0.2,0.00006,400,0},
				{{100,0,0},{4,0,0},0.3,0.00001,400,1},
				{{1000,0,0},{5,0,0},0.8,0.0001,700,1},
				{{10000,0,0},{6,0,0},1.5,0.0008,1000,1},
				"gjb_itn_illum_perst3_10_Lo",
				"gjb_itn_illum_perst3_10_Hi",
				"gjb_itn_flash_gen_vis"
			};
		};
		class rhs_acc_perst3_g_2dp_light_h: rhs_acc_perst3_g_2dp_h
		{};
		class rhs_acc_perst3_g_2dp: rhs_acc_perst3_g_2dp_h
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0271538,0.0075881,0.0559478},
				{-0.0595559,0.00244527,0.0100904},	//"ir_flash dir", DEV Branch
				{-0.0476827,0.0976124,0.0360591}
			};
		};
		class rhs_acc_perst3_g_2dp_light: rhs_acc_perst3_g_2dp
		{};
	};
//Weapons
	class weapons
	{
		//ak103
			class rhs_weap_ak103
			{
				//gjb_itn_nonStdRailFix="leftRailOnly";
				gjb_itn_memoryPoints[]=
				{
					{-0.310862,0.000159584,0.073575}
				};
			};
			class rhs_weap_ak103_npz: rhs_weap_ak103{};
			class rhs_weap_ak103_1:rhs_weap_ak103{};
			class rhs_weap_ak103_1_npz:rhs_weap_ak103{};
			class rhs_weap_ak103_2:rhs_weap_ak103{};
			class rhs_weap_ak103_2_npz:rhs_weap_ak103{};
			class rhs_weap_ak103_zenitco01
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.216837,0.038836,0.112894}
				};
			};
			class rhs_weap_ak103_zenitco01_b33: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak103_zenitco01_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak103_zenitco01_b33_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak103_zenitco01_grip1: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak103_zenitco01_b33_grip1: rhs_weap_ak103_zenitco01{};
		//ak104
			class rhs_weap_ak104: rhs_weap_ak103{};
			class rhs_weap_ak104_npz: rhs_weap_ak103{};
			class rhs_weap_ak104_zenitco01: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak104_zenitco01_b33: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak104_zenitco01_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak104_zenitco01_b33_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak104_zenitco01_grip1: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak104_zenitco01_b33_grip1: rhs_weap_ak103_zenitco01{};
		//ak105
			class rhs_weap_ak105: rhs_weap_ak103{};
			class rhs_weap_ak105_npz: rhs_weap_ak103{};
			class rhs_weap_ak105_zenitco01: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak105_zenitco01_b33: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak105_zenitco01_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak105_zenitco01_b33_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak105_zenitco01_grip1: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak105_zenitco01_b33_grip1: rhs_weap_ak103_zenitco01{};
		//ak74
			class rhs_weap_ak74
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.263646,0,0.0756}
				};
			};
			class rhs_weap_ak74n: rhs_weap_ak74{};
			class rhs_weap_ak74n_npz: rhs_weap_ak74{};
			class rhs_weap_ak74n_2: rhs_weap_ak74{};
			class rhs_weap_ak74n_2_npz: rhs_weap_ak74{};
			class rhs_weap_ak74_2: rhs_weap_ak74{};
			class rhs_weap_ak74_3: rhs_weap_ak74{};
			class rhs_weap_ak74m: rhs_weap_ak103{};
			class rhs_weap_ak74m_npz: rhs_weap_ak103{};
			class rhs_weap_ak74m_camo: rhs_weap_ak103{};
			class rhs_weap_ak74m_camo_npz: rhs_weap_ak103{};
			class rhs_weap_ak74m_desert: rhs_weap_ak103{};
			class rhs_weap_ak74m_desert_npz: rhs_weap_ak103{};
			class rhs_weap_ak74m_fullplum: rhs_weap_ak103{};
			class rhs_weap_ak74m_fullplum_npz: rhs_weap_ak103{};
			class rhs_weap_ak74m_zenitco01: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak74m_zenitco01_b33: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak74m_zenitco01_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak74m_zenitco01_b33_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak74m_zenitco01_grip1: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak74m_zenitco01_b33_grip1: rhs_weap_ak103_zenitco01{};
			class rhs_weap_ak74mr
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.216837,0.045036,0.125094}
				};
			};
			class rhs_weap_ak74mr_afg: rhs_weap_ak74mr{};
			class rhs_weap_ak74mr_grip: rhs_weap_ak74mr{};
			class rhs_weap_ak74mr_gp25: rhs_weap_ak74mr{};
			class rhs_weap_aks74
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.302862,0,0.0756}
				};
			};
			class rhs_weap_aks74_2: rhs_weap_aks74{};
			class rhs_weap_aks74n: rhs_weap_aks74{};
			class rhs_weap_aks74n_npz: rhs_weap_aks74{};
			class rhs_weap_aks74n_2: rhs_weap_aks74{};
			class rhs_weap_aks74n_2_npz: rhs_weap_aks74{};
		//akm
			class rhs_weap_akm: rhs_weap_ak103{};
			class rhs_weap_pm63: rhs_weap_ak103{};
			class rhs_weap_akmn: rhs_weap_ak103{};
			class rhs_weap_akmn_npz: rhs_weap_ak103{};
			class rhs_weap_akms: rhs_weap_ak103{};
			class rhs_weap_akm_zenitco01_b33: rhs_weap_ak103_zenitco01{};
			class rhs_weap_akm_zenitco01_b33_afg: rhs_weap_ak103_zenitco01{};
			class rhs_weap_akm_zenitco01_b33_grip1: rhs_weap_ak103_zenitco01{};
		//asval or vss
			class rhs_weap_asval_grip
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.299315,0.0364596,0.00907064}
				};
			};
			class rhs_weap_asval_grip_npz: rhs_weap_asval_grip{};
			class rhs_weap_asval_afg: rhs_weap_asval_grip{};
			class rhs_weap_asval_npz_afg: rhs_weap_asval_grip{};
			class rhs_weap_asval_grip1: rhs_weap_asval_grip{};
			class rhs_weap_asval_grip1_npz: rhs_weap_asval_grip{};
			class rhs_weap_vss_grip: rhs_weap_asval_grip{};
			class rhs_weap_vss_grip_npz: rhs_weap_asval_grip{};
			class rhs_weap_vss_afg: rhs_weap_asval_grip{};
			class rhs_weap_vss_npz_afg: rhs_weap_asval_grip{};
			class rhs_weap_vss_grip1: rhs_weap_asval_grip{};
			class rhs_weap_vss_grip1_npz: rhs_weap_asval_grip{};
		//pk
			/*class rhs_weap_pkp
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.166951,-0.0169548,0.119975}
				};
			};*/
		//rpk
			class rhs_weap_rpk74m
			{
				gjb_itn_nonStdRailFix="leftRailOnly";
				gjb_itn_memoryPoints[]=
				{
					{-0.305762,0.000159584,0.073575}
				};
			};
			class rhs_weap_rpk74m_npz: rhs_weap_rpk74m{};
	};
};