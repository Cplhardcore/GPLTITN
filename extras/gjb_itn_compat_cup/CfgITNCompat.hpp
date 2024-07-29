class CfgITNCompat
{
//Accessories
	class accessories
	{
		class deviceBase_peq2;
		class deviceBase_peq2_comboVIR;
		class deviceBase_peq15;
		class deviceBase_peq15_comboVIR;
		class deviceBase_m952;
		class acc_flashlight;
		class acc_flashlight_pistol;
		class acc_pointer_IR;
		//peq15
			class cup_acc_anpeq_15: deviceBase_peq15
			{
				gjb_itn_interface[]=
				{
					"peq_15",
					"Rsc_gjb_itn_peq15_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15"
				};
			};
			class cup_acc_anpeq_15_v: cup_acc_anpeq_15{};
			class cup_acc_anpeq_15_tan_top: cup_acc_anpeq_15{};
			class cup_acc_anpeq_15_tan_top_v: cup_acc_anpeq_15{};
			class cup_acc_anpeq_15_black: cup_acc_anpeq_15
			{
				gjb_itn_interface[]=
				{
					"peq_15",
					"Rsc_gjb_itn_peq15_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_b"
				};
			};
			class cup_acc_anpeq_15_black_v: cup_acc_anpeq_15_black{};
			class cup_acc_anpeq_15_black_top: cup_acc_anpeq_15_tan_top
			{
				gjb_itn_interface[]=
				{
					"peq_15",
					"Rsc_gjb_itn_peq15_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_b"
				};
			};
			class cup_acc_anpeq_15_black_top_v: cup_acc_anpeq_15_black_top{};
			class cup_acc_anpeq_15_od: cup_acc_anpeq_15
			{
				gjb_itn_interface[]=
				{
					"peq_15",
					"Rsc_gjb_itn_peq15_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_g"
				};
			};
			class cup_acc_anpeq_15_od_v: cup_acc_anpeq_15_od{};
			class cup_acc_anpeq_15_od_top: cup_acc_anpeq_15_tan_top
			{
				gjb_itn_interface[]=
				{
					"peq_15",
					"Rsc_gjb_itn_peq15_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_g"
				};
			};
			class cup_acc_anpeq_15_od_top_v: cup_acc_anpeq_15_od_top{};
		//peq15 + m952v
			class cup_acc_anpeq_15_flashlight_tan_l: deviceBase_peq15_comboVIR
			{
				/*gjb_itn_memoryPoints[]=
				{
					{-0.0455724,-0.00466293,0.0471343},
					{-0.0455724,-0.00466293,0.0471343},
					{-0.062963,0.0961085,0.0370812}
				};*/
				gjb_itn_interface[]=
				{
					"peq_15_combo",
					"Rsc_gjb_itn_peq15_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952"
				};
			};
			class cup_acc_anpeq_15_flashlight_tan_F: cup_acc_anpeq_15_flashlight_tan_l{};
			class cup_acc_anpeq_15_flashlight_tan_V: cup_acc_anpeq_15_flashlight_tan_l{};
			class cup_acc_anpeq_15_flashlight_od_l: cup_acc_anpeq_15_flashlight_tan_l
			{
				gjb_itn_interface[]=
				{
					"peq_15_combo",
					"Rsc_gjb_itn_peq15_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_g",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_g"
				};
			};
			class cup_acc_anpeq_15_flashlight_od_f: cup_acc_anpeq_15_flashlight_od_l{};
			class cup_acc_anpeq_15_flashlight_od_v: cup_acc_anpeq_15_flashlight_od_l{};
			class cup_acc_anpeq_15_flashlight_black_l: cup_acc_anpeq_15_flashlight_tan_l
			{
				gjb_itn_interface[]=
				{
					"peq_15_combo",
					"Rsc_gjb_itn_peq15_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_b",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_b"
				};
			};
			class cup_acc_anpeq_15_flashlight_black_F: cup_acc_anpeq_15_flashlight_black_l{};
			class cup_acc_anpeq_15_flashlight_black_v: cup_acc_anpeq_15_flashlight_black_l{};
			class cup_acc_anpeq_15_top_flashlight_tan_l: cup_acc_anpeq_15_flashlight_tan_l
			{};
			class cup_acc_anpeq_15_top_flashlight_tan_f: cup_acc_anpeq_15_top_flashlight_tan_l{};
			class cup_acc_anpeq_15_top_flashlight_tan_v: cup_acc_anpeq_15_top_flashlight_tan_l{};
			class cup_acc_anpeq_15_top_flashlight_black_l: cup_acc_anpeq_15_top_flashlight_tan_l
			{
				gjb_itn_interface[]=
				{
					"peq_15_combo",
					"Rsc_gjb_itn_peq15_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_b",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_b"
				};
			};
			class cup_acc_anpeq_15_top_flashlight_black_f: cup_acc_anpeq_15_top_flashlight_black_l{};
			class cup_acc_anpeq_15_top_flashlight_black_v: cup_acc_anpeq_15_top_flashlight_black_l{};
			class cup_acc_anpeq_15_top_flashlight_od_l: cup_acc_anpeq_15_top_flashlight_tan_l
			{
				gjb_itn_interface[]=
				{
					"peq_15_combo",
					"Rsc_gjb_itn_peq15_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq15_g",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_g"
				};
			};
			class cup_acc_anpeq_15_top_flashlight_od_f: cup_acc_anpeq_15_top_flashlight_od_l{};
			class cup_acc_anpeq_15_top_flashlight_od_v: cup_acc_anpeq_15_top_flashlight_od_l{};
		//peq2
			class cup_acc_anpeq_2_grey: deviceBase_peq2
			{
				gjb_itn_interface[]=
				{
					"peq_2",
					"Rsc_gjb_itn_peq2_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2"
				};
			};
			class cup_acc_anpeq_2: cup_acc_anpeq_2_grey{};
			class cup_acc_anpeq_2_desert: cup_acc_anpeq_2_grey
			{
				gjb_itn_interface[]=
				{
					"peq_2",
					"Rsc_gjb_itn_peq2_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2_t"
				};
			};
			class cup_acc_anpeq_2_camo: cup_acc_anpeq_2_grey
			{
				gjb_itn_interface[]=
				{
					"peq_2",
					"Rsc_gjb_itn_peq2_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2_g"
				};
			};
			class cup_acc_anpeq_2_black_top: cup_acc_anpeq_2_grey
			{
				gjb_itn_interface[]=
				{
					"peq_2",
					"Rsc_gjb_itn_peq2_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2"
				};
			};
			class cup_acc_anpeq_2_coyote_top: cup_acc_anpeq_2_black_top
			{
				gjb_itn_interface[]=
				{
					"peq_2",
					"Rsc_gjb_itn_peq2_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2_t"
				};
			};
			class cup_acc_anpeq_2_od_top: cup_acc_anpeq_2_black_top
			{
				gjb_itn_interface[]=
				{
					"peq_2",
					"Rsc_gjb_itn_peq2_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2_g"
				};
			};
		//peq2 + m952v
			class cup_acc_anpeq_2_flashlight_black_l: deviceBase_peq2_comboVIR
			{
				gjb_itn_memoryPoints[]=
				{
					{0.00198064,0.0235857,-0.0113381},
					{0.00198064,0.0235857,-0.0113381},
					{-0.062963,-0.0122202,0.036748}
				};
				gjb_itn_interface[]=
				{
					"peq_2_combo",
					"Rsc_gjb_itn_peq2_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_b"
				};
			};
			class CUP_acc_ANPEQ_2_Flashlight_Black_F: cup_acc_anpeq_2_flashlight_black_l{};
			class cup_acc_anpeq_2_flashlight_od_l: cup_acc_anpeq_2_flashlight_black_l
			{
				gjb_itn_interface[]=
				{
					"peq_2_combo",
					"Rsc_gjb_itn_peq2_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2_g",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_g"
				};
			};
			class CUP_acc_ANPEQ_2_Flashlight_OD_F: cup_acc_anpeq_2_flashlight_od_l{};
			class cup_acc_anpeq_2_flashlight_coyote_l: cup_acc_anpeq_2_flashlight_black_l
			{
				gjb_itn_interface[]=
				{
					"peq_2_combo",
					"Rsc_gjb_itn_peq2_combo_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\peq2_t",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952"
				};
			};
			class CUP_acc_ANPEQ_2_Flashlight_Coyote_F: cup_acc_anpeq_2_flashlight_coyote_l{};
		//m952v
			class cup_acc_flashlight: deviceBase_m952
			{
				gjb_itn_interface[]=
				{
					"m952",
					"Rsc_gjb_itn_m952v_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_b"
				};
			};
			class cup_acc_flashlight_desert: cup_acc_flashlight
			{
				gjb_itn_interface[]=
				{
					"m952",
					"Rsc_gjb_itn_m952v_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952"
				};
			};
			class cup_acc_flashlight_wdl: cup_acc_flashlight
			{
				gjb_itn_interface[]=
				{
					"m952",
					"Rsc_gjb_itn_m952v_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m952_g"
				};
			};
		//llm01
			class cup_acc_llm01_l
			{
				gjb_itn_interface[]=
				{
					"llm_01",
					"Rsc_gjb_itn_llm01_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm"
				};
			};
			class cup_acc_llm01_f: cup_acc_llm01_l{};
			class cup_acc_llm01_v: cup_acc_llm01_l{};
			class cup_acc_llm01_coyote_l: cup_acc_llm01_l
			{
				gjb_itn_interface[]=
				{
					"llm_01",
					"Rsc_gjb_itn_llm01_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm_t"
				};
			};
			class cup_acc_llm01_coyote_f: cup_acc_llm01_coyote_l{};
			class cup_acc_llm01_coyote_v: cup_acc_llm01_coyote_l{};
			class cup_acc_llm01_desert_l: cup_acc_llm01_l
			{
				gjb_itn_interface[]=
				{
					"llm_01",
					"Rsc_gjb_itn_llm01_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm_d"
				};
			};
			class cup_acc_llm01_desert_f: cup_acc_llm01_desert_l{};
			class cup_acc_llm01_desert_v: cup_acc_llm01_desert_l{};
			class cup_acc_llm01_hex_l: cup_acc_llm01_l
			{
				gjb_itn_interface[]=
				{
					"llm_01",
					"Rsc_gjb_itn_llm01_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm_h"
				};
			};
			class cup_acc_llm01_hex_f: cup_acc_llm01_hex_l{};
			class cup_acc_llm01_hex_v: cup_acc_llm01_hex_l{};
			class cup_acc_llm01_od_l: cup_acc_llm01_l
			{
				gjb_itn_interface[]=
				{
					"llm_01",
					"Rsc_gjb_itn_llm01_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm_g"
				};
			};
			class cup_acc_llm01_od_f: cup_acc_llm01_od_l{};
			class cup_acc_llm01_od_v: cup_acc_llm01_od_l{};
		//llmmk3
			class cup_acc_llm
			{
				gjb_itn_controls[]=
				{
					{33,34},
					{33,22},
					{1,1,9}
				};
				gjb_itn_interface[]=
				{
					"llm_mk3",
					"Rsc_gjb_itn_llmMk3_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm3"
				};
				gjb_itn_deviceModes[]=
				{
					{4,0,9,"IR Marker 1 + Lamp 1"},
					{5,0,9,"IR Marker 2 + Lamp 1"},
					{6,0,9,"IR Marker 3 + Lamp 1"},
					{4,0,10,"IR Marker 1 + Lamp 2"},
					{5,0,10,"IR Marker 2 + Lamp 2"},
					{6,0,10,"IR Marker 3 + Lamp 2"},
					{0,7,9,"IR Illuminator 1 + Lamp 1"},
					{0,8,9,"IR Illuminator 2 + Lamp 1"},
					{0,7,10,"IR Illuminator 1 + Lamp 2"},
					{0,8,10,"IR Illuminator 2 + Lamp 2"},
					{4,7,9,"IR Marker 1 + Illuminator 1  + Lamp 1"},
					{5,7,9,"IR Marker 2 + Illuminator 1 + Lamp 1"},
					{6,7,9,"IR Marker 3 + Illuminator 1 + Lamp 1"},
					{4,8,9,"IR Marker 1 + Illuminator 2 + Lamp 1"},
					{5,8,9,"IR Marker 2 + Illuminator 2 + Lamp 1"},
					{6,8,9,"IR Marker 3 + Illuminator 2 + Lamp 1"},
					{4,7,10,"IR Marker 1 + Illuminator 1  + Lamp 2"},
					{5,7,10,"IR Marker 2 + Illuminator 1 + Lamp 2"},
					{6,7,10,"IR Marker 3 + Illuminator 1 + Lamp 2"},
					{4,8,10,"IR Marker 1 + Illuminator 2 + Lamp 2"},
					{5,8,10,"IR Marker 2 + Illuminator 2 + Lamp 2"},
					{6,8,10,"IR Marker 3 + Illuminator 2 + Lamp 2"},
					//
					{3,0,10,"VIS Marker 3 + Lamp 2"},
					{2,0,10,"VIS Marker 2 + Lamp 2"},
					{1,0,10,"VIS Marker 1 + Lamp 2"},
					{3,0,9,"VIS Marker 3 + Lamp 1"},
					{2,0,9,"VIS Marker 2 + Lamp 1"},
					{1,0,9,"VIS Marker 1 + Lamp 1"},
					{0,0,10,"VIS Lamp 2"},
					{0,0,9,"VIS Lamp 1"},
					{3,0,0,"VIS Marker 3"},
					{2,0,0,"VIS Marker 2"},
					{1,0,0,"VIS Marker 1"},
					{0,0,0,"OFF"},
					{4,0,0,"IR Marker 1"},
					{5,0,0,"IR Marker 2"},
					{6,0,0,"IR Marker 3"},
					{0,7,0,"IR Illuminator 1"},
					{0,8,0,"IR Illuminator 2"},
					{4,7,0,"IR Marker 1 + Illuminator 1"},
					{5,7,0,"IR Marker 2 + Illuminator 1"},
					{6,7,0,"IR Marker 3 + Illuminator 1"},
					{4,8,0,"IR Marker 1 + Illuminator 2"},
					{5,8,0,"IR Marker 2 + Illuminator 2"},
					{6,8,0,"IR Marker 3 + Illuminator 2"}
				};
				gjb_itn_deviceSpecs[]=
				{
					"MT/LT",
					{{2500,0,0},{50,0,0},0.08,0.00001,300,0},
					{{25000,0,0},{50,0,0},0.12,0.00003,500,0},
					{{250000,0,0},{50,0,0},0.2,0.00006,800,0},
					{{100,0,0},{5,0,0},0.4,0.00001,400,1},
					{{1000,0,0},{4,0,0},1,0.0008,9000,1},
					{{10000,0,0},{6,0,0},1.5,0.001,1200,1},
					"gjb_itn_illum_dbal_a2_10_Lo",
					"gjb_itn_illum_dbal_a2_10_Hi",
					"gjb_itn_flash_m952_lo_vis",
					"gjb_itn_flash_m952_vis"
				};
			};
			class cup_acc_llm_black: cup_acc_llm
			{
				gjb_itn_interface[]=
				{
					"llm_mk3",
					"Rsc_gjb_itn_llmMk3_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm3_b"
				};
			};
			class cup_acc_llm_od: cup_acc_llm
			{
				gjb_itn_interface[]=
				{
					"llm_mk3",
					"Rsc_gjb_itn_llmMk3_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\llm3_g"
				};
			};
		//glockLLM
			class cup_acc_glock17_flashlight: acc_flashlight_pistol
			{
				gjb_itn_interface[]=
				{
					"gtl_21",
					"Rsc_gjb_itn_gtl21_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\gtl21"
				};
			};
			class cup_acc_glock17_l: cup_acc_glock17_flashlight
			{};
			class cup_acc_glock17_v: cup_acc_glock17_flashlight
			{};
		//czM3x
			class cup_acc_cz_m3x: cup_acc_glock17_flashlight
			{
				gjb_itn_interface[]=
				{
					"gtl_21",
					"Rsc_gjb_itn_m6x_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\m6x"
				};
			};
			class cup_acc_cz_m3x_l: cup_acc_cz_m3x
			{};
		//mk23llm
			class cup_acc_mk23_lam_f: cup_acc_glock17_flashlight
			{
				gjb_itn_interface[]=
				{
					"mk23",
					"Rsc_gjb_itn_mk23lam_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\mk23"
				};
			gjb_itn_deviceModes[]=
			{
				{1,0,4,"VIS LASER AND IR ILLUM"},
				{2,0,3,"IR LASER AND VIS ILLUM"},
				//
				{1,0,3,"VIS LASER AND ILLUM"},
				{1,0,0,"VIS LASER"},
				{0,0,0,"OFF"},
				{2,0,0,"IR LASER"},
				{2,0,4,"IR LASER AND ILLUM"}
			};
			};
			class cup_acc_mk23_lam_v: cup_acc_mk23_lam_f
			{};
			class cup_acc_mk23_lam_l: cup_acc_mk23_lam_f
			{};
		//mpls
			class cup_acc_mlpls_laser: acc_flashlight
			{
				gjb_itn_interface[]=
				{
					"utg",
					"Rsc_gjb_itn_mlpls_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\mlpls"
				};
			};
		//Random lights
			class cup_acc_xm8_light_module: acc_flashlight
			{
				gjb_itn_interface[]=
				{
					"xm8",
					"Rsc_gjb_itn_xm8_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\xm8"
				};
			};
			class cup_acc_zenit_2ds: acc_flashlight
			{
				gjb_itn_interface[]=
				{
					"utg",
					"Rsc_gjb_itn_zenit2ds_cup",
					"\gjb_itn\addons\gjb_itn_compat_cup\ui\2ds"
				};
			};
	};
//Weapons
	class weapons
	{
	/*	
		class 
		{
			gjb_itn_memoryPoints[]=
			{
				{}
			};
		};
	*/
	//AA12		!!! x1
		class CUP_sgun_AA12; //check  model
	//ACR
		//-C
		class CUP_arifle_ACRC_blk_556
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.121657,0.0444267,0.0950174}
			};
		};
		class CUP_arifle_ACRC_blk_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_snw_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_snw_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_tan_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_tan_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_wdl_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_wdl_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_blk_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_blk_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_snw_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_snw_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_tan_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_tan_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_wdl_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACRC_EGLM_wdl_68: CUP_arifle_ACRC_blk_556 {};
		//-R
		class CUP_arifle_ACR_blk_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_blk_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_snw_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_snw_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_tan_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_tan_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_wdl_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_wdl_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_blk_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_blk_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_snw_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_snw_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_tan_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_tan_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_wdl_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_EGLM_wdl_68: CUP_arifle_ACRC_blk_556 {};
		//DMR
		class CUP_arifle_ACR_DMR_blk_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_DMR_blk_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_DMR_snw_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_DMR_snw_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_DMR_tan_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_DMR_tan_68: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_DMR_wdl_556: CUP_arifle_ACRC_blk_556 {};
		class CUP_arifle_ACR_DMR_wdl_68: CUP_arifle_ACRC_blk_556 {};
	//AK
		class CUP_arifle_AK47_Early
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.304664,0.0290286,0.120658}
			};
		};
		class CUP_arifle_AK47_GL_Early
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.412819,0.0290286,0.120658}
			};
		};
		//-101
		class CUP_arifle_AK101:  CUP_arifle_AK47_Early {};
		class CUP_arifle_AK101_top_rail:  CUP_arifle_AK47_Early {};
		class CUP_arifle_AK101_railed
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.210752,0.0403868,0.12334}
			};
		};
		class CUP_arifle_AK101_GL_railed: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK101_GL: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK101_GL_top_rail: CUP_arifle_AK47_GL_Early {};
		//-102
		class CUP_arifle_AK102: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK102_top_rail: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK102_railed: CUP_arifle_AK101_railed {};
		//-103
		class CUP_arifle_AK103:  CUP_arifle_AK47_Early {};
		class CUP_arifle_AK103_top_rail:  CUP_arifle_AK47_Early {};
		class CUP_arifle_AK103_railed: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK103_GL_railed: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK103_GL: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK103_GL_top_rail: CUP_arifle_AK47_GL_Early {};
		//-104
		class CUP_arifle_AK104: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK104_top_rail: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK104_railed: CUP_arifle_AK101_railed {};
		//-105
		class CUP_arifle_AK105: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK105_top_rail: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK105_railed: CUP_arifle_AK101_railed {};
		//-107
		class CUP_arifle_AK107
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.305119,0.0290286,0.118085}
			};
		};
		class CUP_arifle_AK107_top_rail:  CUP_arifle_AK107 {};
		class CUP_arifle_AK107_railed
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.211207,0.0403868,0.120767}
			};
		};
		class CUP_arifle_AK107_GL_railed: CUP_arifle_AK107_railed {};
		class CUP_arifle_AK107_GL
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.413274,0.0290286,0.118085}
			};
		};
		class CUP_arifle_AK107_GL_top_rail: CUP_arifle_AK107_GL {};
		//-108
		class CUP_arifle_AK108: CUP_arifle_AK107 {};
		class CUP_arifle_AK108_top_rail:  CUP_arifle_AK107 {};
		class CUP_arifle_AK108_railed: CUP_arifle_AK107_railed {};
		class CUP_arifle_AK108_GL_railed: CUP_arifle_AK107_railed {};
		class CUP_arifle_AK108_GL: CUP_arifle_AK107_GL {};
		class CUP_arifle_AK108_GL_top_rail: CUP_arifle_AK107_GL {};
		//-109
		class CUP_arifle_AK109: CUP_arifle_AK107 {};
		class CUP_arifle_AK109_top_rail:  CUP_arifle_AK107 {};
		class CUP_arifle_AK109_railed: CUP_arifle_AK107_railed {};
		class CUP_arifle_AK109_GL_railed: CUP_arifle_AK107_railed {};
		class CUP_arifle_AK109_GL: CUP_arifle_AK107_GL {};
		class CUP_arifle_AK109_GL_top_rail: CUP_arifle_AK107_GL {};
		//-12
		class CUP_arifle_AK12_AFG_arid
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.204309,0.0387425,0.14287}
			};
		};
		class CUP_arifle_AK12_AFG_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_AFG_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_AFG_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_AFG_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_AFG_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_AFG_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_AFG_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_AFG_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_VG_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK12_GP34_arid
		{
			gjb_itn_nonStdRailFix="leftRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.204309,-0.0388197,0.0691374}
			};
		};
		class CUP_arifle_AK12_GP34_black: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK12_GP34_lush: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK12_GP34_tan: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK12_GP34_snowtiger: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK12_GP34_tiger: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK12_GP34_bicolor: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK12_GP34_winter: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK12_GP34_wood: CUP_arifle_AK12_GP34_arid {};
		//-15
		class CUP_arifle_AK15_AFG_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_AFG_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_VG_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK15_GP34_arid: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_black: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_lush: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_tan: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_snowtiger: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_tiger: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_bicolor: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_winter: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK15_GP34_wood: CUP_arifle_AK12_GP34_arid {};
		//-19
		class CUP_arifle_AK19_AFG_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_AFG_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_VG_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_arid: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_black: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_lush: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_tan: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_snowtiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_tiger: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_bicolor: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_winter: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_wood: CUP_arifle_AK12_AFG_arid {};
		class CUP_arifle_AK19_GP34_arid: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_black: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_lush: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_tan: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_snowtiger: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_tiger: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_bicolor: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_winter: CUP_arifle_AK12_GP34_arid {};
		class CUP_arifle_AK19_GP34_wood: CUP_arifle_AK12_GP34_arid {};
		//-74
		class CUP_arifle_AK74_Early: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74_GL_Early: CUP_arifle_AK47_GL_Early {};
		//-74M
		class CUP_arifle_AK74M: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74M_top_rail: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74M_desert: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74M_top_rail_desert: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74M_camo: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74M_top_rail_camo: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74M_railed: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_railed_afg: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_railed_desert: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_railed_afg_desert: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_railed_camo: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_railed_afg_camo: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_GL: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK74M_GL_top_rail: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK74M_GL_desert: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK74M_GL_top_rail_desert: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK74M_GL_camo: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK74M_GL_top_rail_camo: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK74M_GL_railed: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_GL_railed_desert: CUP_arifle_AK101_railed {};
		class CUP_arifle_AK74M_GL_railed_camo: CUP_arifle_AK101_railed {};
		//-74N
		class CUP_arifle_AK74: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74_top_rail: CUP_arifle_AK47_Early {};
		class CUP_arifle_AK74_GL: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AK74_GL_top_rail: CUP_arifle_AK47_GL_Early {};
		//M
		class CUP_arifle_AKM_Early: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKM: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKM_tiop_rail: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKM_railed: CUP_arifle_AK101_railed {};
		class CUP_arifle_AKM_railed_afg: CUP_arifle_AK101_railed {};
		class CUP_arifle_AKM_railed_desert: CUP_arifle_AK101_railed {};
		class CUP_arifle_AKM_railed_afg_desert: CUP_arifle_AK101_railed {};
		class CUP_arifle_AKM_GL_Early: CUP_arifle_AK47_GL_Early{};
		class CUP_arifle_AKM_GL: CUP_arifle_AK47_GL_Early{};
		class CUP_arifle_AKM_GL_top_rail: CUP_arifle_AK47_GL_Early{};
		//MS
		class CUP_arifle_AKMS_Early: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKMS: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKMS_tiop_rail: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKMS_GL_Early: CUP_arifle_AK47_GL_Early{};
		class CUP_arifle_AKMS_GL: CUP_arifle_AK47_GL_Early{};
		class CUP_arifle_AKMS_GL_top_rail: CUP_arifle_AK47_GL_Early{};
		//N
		class CUP_arifle_AK47: CUP_arifle_AK47_Early{};
		class CUP_arifle_AK47_tiop_rail: CUP_arifle_AK47_Early{};
		class CUP_arifle_AK47_GL: CUP_arifle_AK47_GL_Early{};
		class CUP_arifle_AK47_GL_top_rail: CUP_arifle_AK47_GL_Early{};
		//S
		class CUP_arifle_AKS: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKS_Gold: CUP_arifle_AK47_Early{};
		class CUP_arifle_AKS_top_rail: CUP_arifle_AK47_Early{};
		//S-74
		class CUP_arifle_AKS74_Early: CUP_arifle_AK47_Early {};
		class CUP_arifle_AKS74_GL_Early: CUP_arifle_AK47_GL_Early {};
		//S-74N
		class CUP_arifle_AKS74: CUP_arifle_AK47_Early {};
		class CUP_arifle_AKS74_top_rail: CUP_arifle_AK47_Early {};
		class CUP_arifle_AKS74_GL: CUP_arifle_AK47_GL_Early {};
		class CUP_arifle_AKS74_GL_top_rail: CUP_arifle_AK47_GL_Early {};
		//S-74U
		class CUP_arifle_AKS74U_railed
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.158278,0.0367539,0.118649}
			};
		};
	//AS Val
		class CUP_arifle_AS_VAL
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.223345,0.0441175,0.113872}
			};
		};
		class CUP_arifle_AS_VAL_top_rail: CUP_arifle_AS_VAL {};
		class CUP_arifle_AS_VAL_VFG: CUP_arifle_AS_VAL {};
		class CUP_arifle_AS_VAL_VFG_top_rail: CUP_arifle_AS_VAL {};
	//AS-50
		class CUP_srifle_AS50
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.341449,0.045642,0.104356}
			};
		};
	//Ballistic Shields		!!! x5
		class CUP_hgun_BallisticShield_Armed_M9 //check  model
		{
			gjb_itn_nonStdRailFix="PistolRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{}
			};
		};
		class CUP_smg_BallisticShield_MP7 //check  model
		{
			gjb_itn_memoryPoints[]=
			{
				{}
			};
		};
		class CUP_hgun_BallisticShield_PMM //check  model
		{
			gjb_itn_nonStdRailFix="PistolRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{}
			};
		};
		class CUP_smg_BallisticShield_PP19 //check  model
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{}
			};
		};
		class CUP_smg_BallisticShield_Sa61 //check  model
		{
			gjb_itn_nonStdRailFix="PistolRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{}
			};
		};
	//CZ 805 BREN
		class CUP_arifle_CZ805_A1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.154125,0.0415553,0.0965667}
			};
		};
		class CUP_arifle_CZ805_A1_blk: CUP_arifle_CZ805_A1 {};
		class CUP_arifle_CZ805_A1_coyote: CUP_arifle_CZ805_A1 {};
		class CUP_arifle_CZ805_A1_GL: CUP_arifle_CZ805_A1 {};
		class CUP_arifle_CZ805_A1_GL_blk: CUP_arifle_CZ805_A1 {};
		class CUP_arifle_CZ805_A1_GL_coyote: CUP_arifle_CZ805_A1 {};
		class CUP_arifle_CZ805_A2: CUP_arifle_CZ805_A1 {}; 
		class CUP_arifle_CZ805_A2_blk: CUP_arifle_CZ805_A1 {};
		class CUP_arifle_CZ805_A2_coyote: CUP_arifle_CZ805_A1 {};
	//CZ 807 BREN
		class CUP_CZ_BREN2_762_14
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.143573,0.0369699,0.101123}
			};
		};
		class CUP_CZ_BREN2_762_14_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_762_14_Tan: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_762_14_GL: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_762_14_GL_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_762_14_GL_Tan: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_762_8: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_762_8_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_762_8_Tan: CUP_CZ_BREN2_762_14 {};
	//CZ BREN 2
		class CUP_CZ_BREN2_556_11: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_11_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_11_Tan: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_11_GL: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_11_GL_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_11_GL_Tan: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_14: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_14_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_14_Tan: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_14_GL: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_14_GL_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_14_GL_Tan: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_8: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_8_Grn: CUP_CZ_BREN2_762_14 {};
		class CUP_CZ_BREN2_556_8_Tan: CUP_CZ_BREN2_762_14 {};
	//CZ Skorpion EVO
		class CUP_smg_EVO
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.126534,0.0395005,0.0973419}
			};
		};
	//FN FAL		!!! x2
		//50.00
		class CUP_arifle_FNFAL5060
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.455788,0.0362261,0.0347714}
			};
		};
		class CUP_arifle_FNFAL5060_rhodesian: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5060_railed: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5060_desert: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5060_railed_desert: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5060_sand: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5060_railed_sand: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5060_woodland: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5060_railed_woodland: CUP_arifle_FNFAL5060 {};
		//50.61
		class CUP_arifle_FNFAL5061: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5061_rhodesian: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5061_railed: CUP_arifle_FNFAL5060 {};
		//50.62
		class CUP_arifle_FNFAL5062_: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5062_railed: CUP_arifle_FNFAL5060 {};
		//50.63
		class CUP_arifle_FNFAL
		{
			gjb_itn_nonStdRailFix="AngleXXRailOnly";	//Needs special help!
			gjb_itn_memoryPoints[]=
			{
				{-0.289515,0.0159688,0.128267}
			};
		};
		class CUP_arifle_FNFAL_railed: CUP_arifle_FNFAL {};
		class CUP_arifle_FNFAL_desert: CUP_arifle_FNFAL {};
		class CUP_arifle_FNFAL_railed_desert: CUP_arifle_FNFAL {};
		class CUP_arifle_FNFAL_sand: CUP_arifle_FNFAL {};
		class CUP_arifle_FNFAL_railed_sand: CUP_arifle_FNFAL {};
		class CUP_arifle_FNFAL_woodland: CUP_arifle_FNFAL {};
		class CUP_arifle_FNFAL_railed_woodland: CUP_arifle_FNFAL {};
		//G
		class CUP_arifle_FNFAL5061_wooden: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_FNFAL5061_wooden_railed: CUP_arifle_FNFAL5060 {};
		//OSW
		class CUP_arifle_FNFAL_OSW
		{
			gjb_itn_nonStdRailFix="AngleXXRailOnly";	//Needs special help!
			gjb_itn_memoryPoints[]=
			{
				{-0.289515,0.0159688,0.128267}
			};
		};
		class CUP_arifle_FNFAL_OSW_railed: CUP_arifle_FNFAL_OSW {};
	//FAMAS
		class CUP_Famas_F1_Rail
		{
			gjb_itn_nonStdRailFix="leftRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.151031,-0.0360333,0.118617}
			};
		};
		class CUP_Famas_F1_Rail_Arid: CUP_Famas_F1_Rail {};
		class CUP_Famas_F1_Rail_Wood: CUP_Famas_F1_Rail {};
	//Fort
		class CUP_arifle_Fort221
		{
			gjb_itn_nonStdRailFix="AngleXXRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.0981154,0.0378849,0.124945}
			};
		};
		class CUP_arifle_Fort222: CUP_arifle_Fort221 {};
		class CUP_arifle_Fort224
		{
			gjb_itn_nonStdRailFix="TopRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.0769273,-0.0370239,0.123327}
			};
		};
		class CUP_arifle_Fort224_Grippod: CUP_arifle_Fort221 {};
	//G1
		class CUP_arifle_Gewehr1: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_Gewehr1_railed: CUP_arifle_FNFAL5060 {};
	//G36
		class CUP_arifle_G36A
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.303132,0.0466169,0.101535}
			};
		};
		class CUP_arifle_G36A_camo: CUP_arifle_G36A {};
		class CUP_arifle_G36A_wdl: CUP_arifle_G36A {};
		class CUP_arifle_G36A_RIS: CUP_arifle_G36A {};
		class CUP_arifle_G36A_RIS_camo: CUP_arifle_G36A {};
		class CUP_arifle_G36A_RIS_wdl: CUP_arifle_G36A {};
		class CUP_arifle_AG36: CUP_arifle_G36A {};
		class CUP_arifle_AG36_camo: CUP_arifle_G36A {};
		class CUP_arifle_AG36_wdl: CUP_arifle_G36A {};
		class CUP_arifle_G36A_AG36_RIS: CUP_arifle_G36A {};
		class CUP_arifle_G36A_AG36_RIS_camo: CUP_arifle_G36A {};
		class CUP_arifle_G36A_AG36_RIS_wdl: CUP_arifle_G36A {};
		//A3
		class CUP_arifle_G36A3
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.334767,0.0466169,0.101535}
			};
		};
		class CUP_arifle_G36A3_grip: CUP_arifle_G36A3 {};
		class CUP_arifle_G36A3_camo: CUP_arifle_G36A3 {};
		class CUP_arifle_G36A3_grip_camo: CUP_arifle_G36A3 {};
		class CUP_arifle_G36A3_hex: CUP_arifle_G36A3 {};
		class CUP_arifle_G36A3_grip_hex: CUP_arifle_G36A3 {};
		class CUP_arifle_G36A3_wdl: CUP_arifle_G36A3 {};
		class CUP_arifle_G36A3_grip_wdl: CUP_arifle_G36A3 {};
		class CUP_arifle_G36A3_AG36: CUP_arifle_G36A {};
		class CUP_arifle_G36A3_AG36_camo: CUP_arifle_G36A {};
		class CUP_arifle_G36A3_AG36_hex: CUP_arifle_G36A {};
		class CUP_arifle_G36A3_AG36_wdl: CUP_arifle_G36A {};
		//C
		class CUP_arifle_G36C
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.21796,0.0466169,0.101535}
			};
		};
		class CUP_arifle_G36C_VFG: CUP_arifle_G36C {};
		class CUP_arifle_G36C_VFG_Carry: CUP_arifle_G36C {};
		class CUP_arifle_G36C_camo: CUP_arifle_G36C {};
		class CUP_arifle_G36C_VFG_camo: CUP_arifle_G36C {};
		class CUP_arifle_G36C_hex: CUP_arifle_G36C {};
		class CUP_arifle_G36C_VFG_hex: CUP_arifle_G36C {};
		class CUP_arifle_G36C_wdl: CUP_arifle_G36C {};
		class CUP_arifle_G36C_VFG_wdl: CUP_arifle_G36C {};
		//CA3
		class CUP_arifle_G36CA3: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_afg: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_grip: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_camo: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_afg_camo: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_grip_camo: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_hex: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_afg_hex: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_grip_hex: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_wdl: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_afg_wdl: CUP_arifle_G36C {};
		class CUP_arifle_G36CA3_grip_wdl: CUP_arifle_G36C {};
		//E
		class CUP_arifle_G36E: CUP_arifle_G36A {};
		class CUP_arifle_G36E_camo: CUP_arifle_G36A {};
		class CUP_arifle_G36E_wdl: CUP_arifle_G36A {};
		//K
		class CUP_arifle_G36K
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.21796,0.0466169,0.101535}
			};
		};
		class CUP_arifle_G36K_VFG: CUP_arifle_G36K {};
		class CUP_arifle_G36K_VFG_Carry: CUP_arifle_G36K {};
		class CUP_arifle_G36K_camo: CUP_arifle_G36K {};
		class CUP_arifle_G36K_VFG_camo: CUP_arifle_G36K {};
		class CUP_arifle_G36K_wdl: CUP_arifle_G36K {};
		class CUP_arifle_G36K_VFG_wdl: CUP_arifle_G36K {};
		class CUP_arifle_G36K_RIS: CUP_arifle_G36K {};
		class CUP_arifle_G36K_RIS_camo: CUP_arifle_G36K {};
		class CUP_arifle_G36K_RIS_hex: CUP_arifle_G36K {};
		class CUP_arifle_G36K_RIS_wdl: CUP_arifle_G36K {};
		class CUP_arifle_G36K_AG36: CUP_arifle_G36A {};
		class CUP_arifle_G36K_AG36_camo: CUP_arifle_G36A {};
		class CUP_arifle_G36K_AG36_wdl: CUP_arifle_G36A {};
		class CUP_arifle_G36K_RIS_AG36: CUP_arifle_G36A {};
		class CUP_arifle_G36K_RIS_AG36_camo: CUP_arifle_G36A {};
		class CUP_arifle_G36K_RIS_AG36_hex: CUP_arifle_G36A {};
		class CUP_arifle_G36K_RIS_AG36_wdl: CUP_arifle_G36A {};
		//KA3
		class CUP_arifle_G36KA3
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.2764,0.0466169,0.101535}
			};
		};
		class CUP_arifle_G36KA3_camo: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_hex: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_wdl: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_afg: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_afg_camo: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_afg_hex: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_afg_wdl: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_grip: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_grip_camo: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_grip_hex: CUP_arifle_G36KA3 {};
		class CUP_arifle_G36KA3_grip_wdl: CUP_arifle_G36KA3 {};
	//G3A3
		class CUP_arifle_G3A3_ris
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.49656,0.0348801,0.0584785}
			};
		};
		class CUP_arifle_G3A3_ris_black: CUP_arifle_G3A3_ris {};
		class CUP_arifle_G3A3_modern_ris: CUP_arifle_G3A3_ris {};
		class CUP_arifle_G3A3_modern_ris_black: CUP_arifle_G3A3_ris {};
		class CUP_arifle_G3A3_ris_vfg
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.368033,0.0348801,0.0478181}
			};
		};
		class CUP_arifle_G3A3_ris_vfg_black: CUP_arifle_G3A3_ris_vfg {};
	//HK416
		class CUP_arifle_HK416_Black
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.19833,0.0435037,0.117031}
			};
		};
		class CUP_arifle_HK416_Desert: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_Wood: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_M203_Black: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_M203_Desert: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_M203_Wood: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_AGL_Black: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_AGL_Desert: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_AGL_Wood: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_Black: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_Desert: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_Wood: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_M203_Black: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_M203_Desert: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_M203_Wood: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_AG36_Black: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_AG36_Desert: CUP_arifle_HK416_Black {};
		class CUP_arifle_HK416_CQB_AG36_Wood: CUP_arifle_HK416_Black {};
	//HK417
		class CUP_arifle_HK417_12
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.151662,0.0435037,0.119489}
			};
		};
		class CUP_arifle_HK417_12_Desert: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_12_Wood: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_12_M203: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_12_M203_Desert: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_12_M203_Wood: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_12_AG36: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_12_AG36_Desert: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_12_AG36_Wood: CUP_arifle_HK417_12 {};
		class CUP_arifle_HK417_20
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.279356,0.0435037,0.119489}
			};
		};
		class CUP_arifle_HK417_20_Desert: CUP_arifle_HK417_20 {};
		class CUP_arifle_HK417_20_Wood: CUP_arifle_HK417_20 {};
	//Sa vz.58 Klec
		class CUP_arifle_Sa58_Klec
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.309652,0.0305687,0.115784}
			};
		};
		class CUP_arifle_Sa58_Klec_rearris: CUP_arifle_Sa58_Klec {};
		class CUP_arifle_Sa58_Klec_frontris: CUP_arifle_Sa58_Klec {};
		class CUP_arifle_Sa58_Klec_ris
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.178624,0.0440728,0.113221}
			};
		};
	//L110A2
		class CUP_lmg_L110A1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0455477,0.0594115}
			};
		};
	//L129A1
		class CUP_srifle_L129A1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.310161,0.0410671,0.10622}
			};
		};
		class CUP_srifle_L129A1_ctrg: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_ctrgt: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_d: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_w: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_HG: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_HG_ctrg: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_HG_ctrgt: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_HG_d: CUP_srifle_L129A1 {};
		class CUP_srifle_L129A1_HG_w: CUP_srifle_L129A1 {};
	//L85A2
		class CUP_arifle_L85A2_NG
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.14635,0.0369301,0.0968272}
			};
		};
		class CUP_arifle_L85A2_G: CUP_arifle_L85A2_NG {};
		class CUP_arifle_L85A2_GL
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.213726,0.0502099,0.098752}
			};
		};
	//M1014
		class CUP_sgun_M1014
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.354601,0.0367161,0.0370784}
			};
		};
		class CUP_sgun_M1014_vfg: CUP_sgun_M1014 {};
		class CUP_sgun_M1014_solidstock: CUP_sgun_M1014 {};
		class CUP_sgun_M1014_Entry: CUP_sgun_M1014 {};
		class CUP_sgun_M1014_Entry_vfg: CUP_sgun_M1014 {};
	//M110
		class CUP_srifle_m110_kac_black
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.27329,0.0459272,0.118408}
			};
		};
		class CUP_srifle_m110_black: CUP_srifle_m110_kac_black {};
		class CUP_srifle_m110_kac: CUP_srifle_m110_kac_black {};
		class CUP_srifle_m110: CUP_srifle_m110_kac_black {};
		class CUP_srifle_m110_kac_woodland: CUP_srifle_m110_kac_black {};
		class CUP_srifle_m110_woodland: CUP_srifle_m110_kac_black {};
	//M14
		class CUP_srifle_M14
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.464652,0.0316177,0.11729}
			};
		};
		class CUP_srifle_M14_DMR: CUP_srifle_M14 {};
	//M16
		//A1
		class CUP_arifle_M16A1
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.481552,0.0366639,0.0481424}
			};
		};
		class CUP_arifle_M16A1E1: CUP_arifle_M16A1 {};
		class CUP_arifle_XM16E1: CUP_arifle_M16A1 {};
		//A2
		class CUP_arifle_M16A2
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.464228,0.0366639,0.0462491}
			};
		};
		class CUP_arifle_Colt727
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.329652,0.0366639,0.0450424}
			};
		};
		//A4
		class CUP_arifle_M16A4_Base
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.285558,0.0408208,0.111822}
			};
		};
		class CUP_arifle_M16A4_Grip: CUP_arifle_M16A4_Base {};
		class CUP_arifle_M16A4_GL
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.265558,0.0408208,0.111822}
			};
		};
	//M2010
		class CUP_srifle_M2010_blk
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.487054,0.0489426,0.086934}
			};
		};
		class CUP_srifle_M2010_ctrgt: CUP_srifle_M2010_blk {};
		class CUP_srifle_M2010_ctrg: CUP_srifle_M2010_blk {};
		class CUP_srifle_M2010_dsrt: CUP_srifle_M2010_blk {};
		class CUP_srifle_M2010_hex: CUP_srifle_M2010_blk {};
		class CUP_srifle_M2010_winter: CUP_srifle_M2010_blk {};
		class CUP_srifle_M2010_wdl: CUP_srifle_M2010_blk {};
	//M21 DMR
		class CUP_srifle_M21
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.464652,0.0316177,0.11729}
			};
		};
		class CUP_srifle_M21_ris: CUP_srifle_M21 {};
	//M240
		class CUP_lmg_M240_B
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.430653,0.0491726,0.104438}
			};
		};
	//M249
		class CUP_lmg_m249_SQuantoon
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0455477,0.0610948}
			};
		};
		class CUP_lmg_m249_pip4: CUP_lmg_m249_SQuantoon {};
		class CUP_lmg_m249_para_gl
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0455477,0.0594115}
			};
		};
	//M27 IAR
		class CUP_arifle_HK_M27
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.237614,0.0435037,0.117031}
			};
		};
		class CUP_arifle_HK_M27_VFG: CUP_arifle_HK_M27 {};
		class CUP_arifle_HK_M27_AG36: CUP_arifle_HK_M27 {};
	//M32 RGL
		class CUP_glaunch_M32
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.233155,0.0331741,0.03177}
			};
		};
	//M4		!!! x1
		class CUP_arifle_M4_MOE_BW
		{
			gjb_itn_nonStdRailFix="AngleXXRailOnly";	//Needs special help!
			gjb_itn_memoryPoints[]=
			{
				{-0.134819,0.0266831,0.12697}
			};
		};
		class CUP_arifle_SBR_od
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.16739,0.0431745,0.125006}
			};
		};
		class CUP_arifle_SBR_black: CUP_arifle_SBR_od {};
	//M4A1
		class CUP_arifle_M4A1_black
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.20058,0.0430701,0.10599}
			};
		};
		class CUP_arifle_M4A1: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A3_black: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A1_desert: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A1_desert_carryhandle: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A3_desert: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A1_camo: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A1_camo_carryhandle: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A3_camo: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A1_BUIS_GL: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A1_BUIS_desert_GL: CUP_arifle_M4A1_black {};
		class CUP_arifle_M4A1_BUIS_camo_GL: CUP_arifle_M4A1_black {};
		//Block I
		class CUP_arifle_M4A1_standard_black
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.128302,0.0419374,0.110374}
			};
		};
		class CUP_arifle_M4A1_standard_dsrt: CUP_arifle_M4A1_standard_black {};
		class CUP_arifle_M4A1_standard_winter: CUP_arifle_M4A1_standard_black {};
		class CUP_arifle_M4A1_standard_wdl: CUP_arifle_M4A1_standard_black {};
		class CUP_arifle_M4A1_standard_short_black: CUP_arifle_M4A1_standard_black {};
		class CUP_arifle_M4A1_standard_short_dsrt: CUP_arifle_M4A1_standard_black {};
		class CUP_arifle_M4A1_standard_short_winter: CUP_arifle_M4A1_standard_black {};
		class CUP_arifle_M4A1_standard_short_wdl: CUP_arifle_M4A1_standard_black {};
		//MOE
		class CUP_arifle_M4A1_MOE_black: CUP_arifle_M4_MOE_BW {};
		class CUP_arifle_M4A1_MOE_desert: CUP_arifle_M4_MOE_BW {};
		class CUP_arifle_M4A1_MOE_winter: CUP_arifle_M4_MOE_BW {};
		class CUP_arifle_M4A1_MOE_wdl: CUP_arifle_M4_MOE_BW {};
		class CUP_arifle_M4A1_MOE_short_black: CUP_arifle_M4_MOE_BW {};
		class CUP_arifle_M4A1_MOE_short_desert: CUP_arifle_M4_MOE_BW {};
		class CUP_arifle_M4A1_MOE_short_winter: CUP_arifle_M4_MOE_BW {};
		class CUP_arifle_M4A1_MOE_short_wdl: CUP_arifle_M4_MOE_BW {};
		//Block II
		class CUP_arifle_M4A1_SOMMOD_black
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.251116,0.0419374,0.115374}
			};
		};
		class CUP_arifle_M4A1_SOMMOD_ctrgt: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_ctrg: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_tan: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_hex: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_snow: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_green: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_Grip_black: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_Grip_ctrgt: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_Grip_ctrg: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_Grip_tan: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_Grip_hex: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_Grip_snow: CUP_arifle_M4A1_SOMMOD_black {};
		class CUP_arifle_M4A1_SOMMOD_Grip_green: CUP_arifle_M4A1_SOMMOD_black {};
	//M60E4
		class CUP_lmg_M60E4_jungle
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.219741,0.0482473,0.111309}
			};
		};
		class CUP_lmg_M60E4: CUP_lmg_M60E4_jungle {};
		class CUP_lmg_M60E4_desert: CUP_lmg_M60E4_jungle {};
		class CUP_lmg_M60E4_wood: CUP_lmg_M60E4_jungle {};
	//MG3
		class CUP_lmg_MG3_rail
		{
			gjb_itn_nonStdRailFix="leftRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.560401,-0.0431809,0.0343019}
			};
		};
	//MG36
		class CUP_arifle_MG36
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.303132,0.0466169,0.101535}
			};
		};
		class CUP_arifle_MG36_camo: CUP_arifle_MG36 {};
		class CUP_arifle_MG36_hex: CUP_arifle_MG36 {};
		class CUP_arifle_MG36_wdl: CUP_arifle_MG36 {};
	//Mk12 SPR
		class CUP_srifle_Mk12SPR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.326779,0.0413645,0.0978396}
			};
		};
	//Mk13
		class CUP_glaunch_Mk13
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.106998,0.035399,0.12958}
			};
		};
	//Mk16
		//CQC
		class CUP_arifle_Mk16_CQC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.205628,0.0386856,0.123338}
			};
		};
		class CUP_arifle_Mk16_CQC_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_AFG: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_AFG_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_AFG_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_FG: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_FG_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_FG_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_SFG: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_SFG_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_SFG_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_EGLM: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_EGLM_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_CQC_EGLM_woodland: CUP_arifle_Mk16_CQC {};
		//STD
		class CUP_arifle_Mk16_STD: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_AFG: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_AFG_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_AFG_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_FG: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_FG_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_FG_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_SFG: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_SFG_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_SFG_woodland: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_EGLM: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_EGLM_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_STD_EGLM_woodland: CUP_arifle_Mk16_CQC {};
		//SV
		class CUP_arifle_Mk16_SV: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_SV_black: CUP_arifle_Mk16_CQC {};
		class CUP_arifle_Mk16_SV_woodland: CUP_arifle_Mk16_CQC {};
	//Mk17
		//CQC
		class CUP_arifle_Mk17_CQC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.229098,0.0384146,0.123131}
			};
		};
		class CUP_arifle_Mk17_CQC_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_AFG: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_AFG_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_AFG_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_FG: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_FG_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_FG_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_SFG: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_SFG_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_SFG_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_EGLM: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_EGLM_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_CQC_EGLM_woodland: CUP_arifle_Mk17_CQC {};
		//STD
		class CUP_arifle_Mk17_STD: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_AFG: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_AFG_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_AFG_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_FG: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_FG_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_FG_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_SFG: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_SFG_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_SFG_woodland: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_EGLM: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_EGLM_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_STD_EGLM_woodland: CUP_arifle_Mk17_CQC {};
		//SV
		class CUP_arifle_Mk17_SV: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_SV_black: CUP_arifle_Mk17_CQC {};
		class CUP_arifle_Mk17_SV_woodland: CUP_arifle_Mk17_CQC {};
	//Mk18
		class CUP_arifle_mk18_black
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.25094,0.0355745,0.117704}
			};
		};
		class CUP_arifle_mk18_m203_black
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.251814,0.0355745,0.117704}
			};
		};
	//Mk48
		class CUP_lmg_Mk48
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.230269,0.0473275,0.0903269}
			};
		};
		class CUP_lmg_Mk48_des: CUP_lmg_Mk48 {};
		class CUP_lmg_Mk48_od: CUP_lmg_Mk48 {};
		class CUP_lmg_Mk48_tan: CUP_lmg_Mk48 {};
		class CUP_lmg_Mk48_wdl: CUP_lmg_Mk48 {};
		class CUP_lmg_Mk48_nohg
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.167573,0.0473275,0.0598782}
			};
		};
		class CUP_lmg_Mk48_nohg_des: CUP_lmg_Mk48 {};
		class CUP_lmg_Mk48_nohg_od: CUP_lmg_Mk48 {};
		class CUP_lmg_Mk48_nohg_tan: CUP_lmg_Mk48 {};
		class CUP_lmg_Mk48_nohg_wdl: CUP_lmg_Mk48 {};
	//Mk14 Mod 0
		class CUP_srifle_Mk18_blk
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.269205,0.0343084,0.116786}
			};
		};
		class CUP_srifle_Mk18_des: CUP_srifle_Mk18_blk {};
		class CUP_srifle_Mk18_wdl: CUP_srifle_Mk18_blk {};
	//MP5
		//A5
		class CUP_smg_MP5A5_Rail
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.110579,0.0399012,0.111635}
			};
		};
		class CUP_smg_MP5A5_Rail_VFG: CUP_smg_MP5A5_Rail {};
		class CUP_smg_MP5A5_Rail_AFG
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.130579,0.0399012,0.111635}
			};
		};
		//SD6
		class CUP_smg_MP5SD6
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.231947,0.0369752,0.0363624}
			};
		};
	//MP7
		class CUP_smg_MP7
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0116456,0.0379673,0.08889}
			};
		};
		class CUP_smg_MP7_desert: CUP_smg_MP7 {};
		class CUP_smg_MP7_woodland: CUP_smg_MP7 {};
	//P90
		class CUP_smg_P90
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.187988,0.0388868,0.11834}
			};
		};
	//PK
		//M
		class CUP_lmg_PKM_B50_vfg
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.369077,0.0391977,0.0897814}
			};
		};
		class CUP_lmg_PKM_front_rail_B50_vfg: CUP_lmg_PKM_B50_vfg {};
		class CUP_lmg_PKM_top_rail_B50_vfg: CUP_lmg_PKM_B50_vfg {};
		//P
		class CUP_lmg_Pecheneg_B50_vfg: CUP_lmg_PKM_B50_vfg {};
		class CUP_lmg_Pecheneg_top_rail_B50_vfg: CUP_lmg_PKM_B50_vfg {};
	//PP-19-01 Vityaz
		class CUP_smg_vityaz_vfg_top_rail
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.187988,0.0388868,0.11834}
			};
		};
		class CUP_smg_vityaz_vfg: CUP_smg_vityaz_vfg_top_rail {};
		class CUP_smg_vityaz_vfg_front_rail: CUP_smg_vityaz_vfg_top_rail {};
	//PS90 w/ Shroud
		class CUP_smg_PS90_olive
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.120421,0.029247,0.0710984}
			};
		};
	//RSASS
		class CUP_srifle_RSASS_Black
		{
			gjb_itn_nonStdRailFix="leftRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.234809,-0.0447769,0.0129802}
			};
		};
		class CUP_srifle_RSASS_Dazzle: CUP_srifle_RSASS_Black {};
		class CUP_srifle_RSASS_Jungle: CUP_srifle_RSASS_Black {};
		class CUP_srifle_RSASS_Sand: CUP_srifle_RSASS_Black {};
		class CUP_srifle_RSASS_Winter: CUP_srifle_RSASS_Black {};
		class CUP_srifle_RSASS_WDLNet: CUP_srifle_RSASS_Black {};
		class CUP_srifle_RSASS_WDL: CUP_srifle_RSASS_Black {};
	//Romat
		class CUP_arifle_IMI_Romat
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.455788,0.0362261,0.0347714}
			};
		};
		class CUP_arifle_IMI_Romat_railed: CUP_arifle_IMI_Romat {};
	//RPK
		class CUP_arifle_RPK74
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.309269,0.0290286,0.121105}
			};
		};
		class CUP_arifle_RPK74_top_rail: CUP_arifle_RPK74 {};
		//-74
		class CUP_arifle_RPK74_45: CUP_arifle_RPK74 {};
		class CUP_arifle_RPK74_45_top_rail: CUP_arifle_RPK74 {};
		//-74M
		class CUP_arifle_RPK74M: CUP_arifle_RPK74 {};
		class CUP_arifle_RPK74M_top_rail: CUP_arifle_RPK74 {};
		class CUP_arifle_RPK74M_railed
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.21087,0.0403868,0.12111}
			};
		};
	//Sa vz.58
		//P
		class CUP_arifle_Sa58P
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.309652,0.0302008,0.115636}
			};
		};
		class CUP_arifle_Sa58P_des: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58P_wood: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58P_woodland: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58P_rearris: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58P_frontris: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58P_frontris_desert: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58P_frontris_woodland: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58Pi: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58P_RIS1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.178624,0.0440728,0.113221}
			};
		};
		//V
		class CUP_arifle_Sa58V: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58V_camo: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58V_wood: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58V_woodland: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58V_rearris: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58V_frontris: CUP_arifle_Sa58P {};
		//V RIS
		class CUP_arifle_Sa58RIS1: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS1_des: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS1_wood: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS2: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS2_camo: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS2_woodland: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS2_gl: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS2_gl_desert: CUP_arifle_Sa58P {};
		class CUP_arifle_Sa58RIS2_gl_woodland: CUP_arifle_Sa58P {};
		//Carbine
		class CUP_arifle_Sa58_Carbine_RIS_AFG: CUP_arifle_Sa58P_RIS1 {};
		class CUP_arifle_Sa58_Carbine_RIS_AFG_desert: CUP_arifle_Sa58_Carbine_RIS_AFG {};
		class CUP_arifle_Sa58_Carbine_RIS_AFG_woodland: CUP_arifle_Sa58_Carbine_RIS_AFG {};
		class CUP_arifle_Sa58_Carbine_RIS_VFG: CUP_arifle_Sa58_Carbine_RIS_AFG {};
		class CUP_arifle_Sa58_Carbine_RIS_VFG_desert: CUP_arifle_Sa58_Carbine_RIS_AFG {};
		class CUP_arifle_Sa58_Carbine_RIS_VFG_woodland: CUP_arifle_Sa58_Carbine_RIS_AFG {};
	//Sa.61
		class CUP_smg_SA61_RIS
		{
			gjb_itn_nonStdRailFix="PistolRailOnly";	//but uses "weapon_slots\side.001"
			gjb_itn_memoryPoints[]=
			{
				{-0.0882309,-0.000450918,0.0617978}
			};
		};
	//SA58
		class CUP_arifle_DSA_SA58
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.267543,0.036213,0.112372}
			};
		};
		class CUP_arifle_DSA_SA58_DMR: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_Desert: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_Sand: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_Woodland: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_VFG: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_VFG_Desert: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_VFG_Sand: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_VFG_Woodland: CUP_arifle_DSA_SA58 {};
		class CUP_arifle_DSA_SA58_OSW_M203: CUP_arifle_DSA_SA58 {};
	//Saiga Mk03
		class CUP_arifle_SAIGA_MK03
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.304145,0.0290286,0.120658}
			};
		};
		class CUP_arifle_SAIGA_MK03_top_rail: CUP_arifle_SAIGA_MK03 {};
		class CUP_arifle_SAIGA_MK03_wood: CUP_arifle_SAIGA_MK03 {};
		class CUP_arifle_SAIGA_MK03_wood_top_rail: CUP_arifle_SAIGA_MK03 {};
	//SR-3M
		class CUP_arifle_SR3M_Vikhr_VFG
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.304145,0.0290286,0.120658}
			};
		};
		class CUP_arifle_SR3M_Vikhr_VFG_top_rail: CUP_arifle_SR3M_Vikhr_VFG {};
	//StG 58
		class CUP_arifle_Steyr_Stg58: CUP_arifle_FNFAL5060 {};
		class CUP_arifle_Steyr_Stg58_railed: CUP_arifle_FNFAL5060 {};
	//Type-56-2
		class CUP_arifle_TYPE_56_2_Early
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.304304,0.0290286,0.120658}
			};
		};
		class CUP_arifle_TYPE_56_2: CUP_arifle_TYPE_56_2_Early {};
		class CUP_arifle_TYPE_56_2_top_rail: CUP_arifle_TYPE_56_2_Early {};
	//VSS Vintorez
		class CUP_srifle_VSSVintorez: CUP_arifle_AS_VAL {};
		class CUP_srifle_VSSVintorez_VFG: CUP_arifle_AS_VAL {};
		class CUP_srifle_VSSVintorez_top_rail: CUP_arifle_AS_VAL {};
		class CUP_srifle_VSSVintorez_VFG_top_rail: CUP_arifle_AS_VAL {};
	//Tavor X-95
		class CUP_arifle_X95: CUP_arifle_Fort224 {};
		class CUP_arifle_X95_Grippod: CUP_arifle_Fort224 {};
	//XM8
		class CUP_arifle_XM8_Carbine
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.259102,0.0398958,0.114901}
			};
		};
		class CUP_arifle_XM8_Carbine_FG
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.259102,0.0390445,0.111838}
			};
		};
		class CUP_arifle_XM8_Railed
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.255368,0.0395005,0.112606}
			};
		};
		class CUP_arifle_XM8_Compact
		{
			gjb_itn_nonStdRailFix="BottomRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.197533,0.0347295,0.0185492}
			};
		};
		class CUP_arifle_XM8_Compact_Rail: CUP_arifle_XM8_Compact {};
		class CUP_arifle_xm8_SAW: CUP_arifle_XM8_Carbine_FG {};
		class CUP_arifle_xm8_sharpshooter
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.25917,0.0390445,0.111871}
			};
		};
	};
};