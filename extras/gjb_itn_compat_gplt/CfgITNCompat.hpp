class CfgITNCompat
{
//Accessories
	class accessories
	{
		class acc_flashlight;
		class deviceBase_m952;
		class deviceBase_la5b;
		class deviceBase_la5b_comboWO;
		class deviceBase_la5b_comboVIR;
		class deviceBase_ngal;
		class deviceBase_ngal_comboWO;
		class deviceBase_ngal_comboVIR;
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
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sidelima_LASER: deviceBase_la5b
				{
					gjb_itn_memoryPoints[]=
					{ 
						{-0.0431546,-0.00993953,0.0236848},
						{-0.0431546,-0.00993953,0.0236848},
						{0,0,0}
					};
					gjb_itn_interface[]=
					{
						"la_5b",
						"Rsc_gjb_itn_la5b_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b"
					};
				};
				class GPLT_sidefoster_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.140517,0.022622,-0.00231253},
						{-0.140517,0.022622,-0.00231253},
						{-0.163857,0.000499235,0.0358282}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class Louetta_sidefsp_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.142712,0.0227977,-0.0026075},
						{-0.142712,0.0227977,-0.0026075},
						{-0.142149,-0.00133174,0.036764}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class Louetta_sidefsp2_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00316963,0.0228322,-0.00252764},
						{-0.00316963,0.0228322,-0.00252764},
						{-0.147873,-0.000896983,0.036923}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class Louetta_sidefsp3_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.142712,0.0227977,-0.0026075},
						{-0.142712,0.0227977,-0.0026075},
						{-0.142149,0.09436,0.036764}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sidehotch_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0247917,0.0295443,0.00130102},
						{-0.0247917,0.0295443,0.00130102},
						{-0.0428405,0.0830315,0.0194584}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300"
					};
				};
				class GPLT_sidescar2_LASER: deviceBase_la5b_comboVIR
				{	
					gjb_itn_memoryPoints[]=
					{
						{-0.169262,-0.0366819,0.0693878},
						{-0.169262,-0.0366819,0.0693878},
						{-0.189229,0.0438918,0.0456499}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sidescar_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.013767,-0.0273162,-0.00982422},
						{-0.013767,-0.0273162,-0.00982422},
						{-0.0326958,0.0449866,0.046257}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sidetim_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0040788,0.0221144,-0.00256965},
						{-0.0040788,0.0221144,-0.00256965},
						{-0.0372582,0.000366144,0.0357173}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sidetim3_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0161455,0.0294905,-0.00841968},
						{-0.0161455,0.0294905,-0.00841968},
						{-0.0370695,0.000982035,0.0350474}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300"
					};
				};
				class GPLT_SideMRAD_LASER: deviceBase_la5b
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.145602,0.0352467,-0.0525828},
						{-0.145602,0.0352467,-0.0525828},
						{0,0,0}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300"
					};
				};
				class GPLT_sideurgi2_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0168677,0.0220702,-0.00206376},
						{-0.0168677,0.0220702,-0.00206376},
						{-0.0584723,0.091493,0.0367756}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sideurgi5_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0168677,0.0220702,-0.00206376},
						{-0.0168677,0.0220702,-0.00206376},
						{-0.0584723,-0.00102174,0.0362551}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sideurgi4_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0794153,0.029007,0.00108599},
						{0.0794153,0.029007,0.00108599},
						{-0.0385695,0.0138974,0.0166917}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sideurgi3_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0367541,0.0293591,0.00114851},
						{-0.0367541,0.0293591,0.00114851},
						{-0.0584723,0.091493,0.0367756}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300"
					};
				};
				class GPLT_sideurgi6_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0367541,0.0293591,0.00114851},
						{-0.0367541,0.0293591,0.00114851},
						{-0.0584723,-0.00133179,0.0367756}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300"
					};
				};
				class GPLT_sideurgi7_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0229692,0.0217679,-0.00244795},
						{0.0229692,0.0217679,-0.00244795},
						{-0.012445,-0.00132403,0.0358709}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300_bk"
					};
				};
				class GPLT_sideurgi9_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0100276,0.0295701,0.001244},
						{0.0100276,0.0295701,0.001244},
						{-0.012445,0.00122349,0.0361895}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300"
					};
				};
				class GPLT_sideurgi8_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0100276,0.0295701,0.001244},
						{0.0100276,0.0295701,0.001244},
						{-0.012445,-0.00132403,0.0358709}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300"
					};
				};
				class GPLT_sidesass_p_LASER: deviceBase_la5b
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0489236,-0.0343846,0.0512323},
						{-0.0489236,-0.0343846,0.0512323},
						{0,0,0}
					};
					gjb_itn_interface[]=
					{
						"la_5b",
						"Rsc_gjb_itn_la5b_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b"
					};
				};
				class GPLT_SideSASS_LASER: deviceBase_la5b
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0271855,0.0342705,-0.0532825},
						{-0.0271855,0.0342705,-0.0532825},
						{0,0,0}
					};
					gjb_itn_interface[]=
					{
						"la_5b",
						"Rsc_gjb_itn_la5b_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b"
					};
				};
	};
class CfgWeapons
	{
		//HK416 D10
			class GPLT_tran_foster
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.283867,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class Louetta_tran_fsp_base
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.212695,0.046036,0.10621}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class GPLT_tran_Hotch
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.283867,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class GPLT_tran_mk17
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.283867,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class GPLT_tran_mk17_wht: GPLT_tran_mk17{};
			class GPLT_tran_mk17_blk: GPLT_tran_mk17{};
			class GPLT_tran_mk17_s_1: GPLT_tran_mk17{};
			class GPLT_tran_mk17_s_2: GPLT_tran_mk17{};
			class GPLT_tran_mk17_s_3: GPLT_tran_mk17{};
			class GPLT_tran_mk17_s_4: GPLT_tran_mk17{};
			class GPLT_tran_mk17_gry: GPLT_tran_mk17{};
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.214441,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class GPLT_tran_URGI_Short
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.283867,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class GPLT_tran_URGI
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.283867,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class GGPLT_M110_SASS
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.283867,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
			class GPLT_tran_M110_SASS_P
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.283867,0.046036,0.106207}
				};
				gjb_itn_nonStdRailFix="rawpos";
			};
	};
};