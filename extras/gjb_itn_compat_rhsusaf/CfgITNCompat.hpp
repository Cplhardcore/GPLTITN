class CfgITNCompat
{
//Accessories
	class accessories
	{
		class deviceBase_peq15;
		class deviceBase_peq15_comboVIR;
		class deviceBase_m952;
		class acc_flashlight;
		class acc_pointer_IR;
		//
	//peq15
		class rhsusf_acc_anpeq15side: deviceBase_peq15
		{
			gjb_itn_interface[]=
			{
				"peq_15",
				"Rsc_gjb_itn_peq15",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15"
			};
		};
		class rhsusf_acc_anpeq15side_bk: rhsusf_acc_anpeq15side
		{
			gjb_itn_interface[]=
			{
				"peq_15",
				"Rsc_gjb_itn_peq15",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b"
			};
		};
		class rhsusf_acc_anpeq15_top;
		class rhsusf_acc_anpeq15_top_h;
		class rhsusf_acc_anpeq15_top_sc;
		class rhsusf_acc_anpeq15_bk_top: rhsusf_acc_anpeq15_top
		{
			gjb_itn_interface[]=
			{
				"peq_15",
				"Rsc_gjb_itn_peq15",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b"
			};
		};
		class rhsusf_acc_anpeq15_bk_top_h: rhsusf_acc_anpeq15_top_h
		{
			gjb_itn_interface[]=
			{
				"peq_15",
				"Rsc_gjb_itn_peq15",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b"
			};
		};
		class rhsusf_acc_anpeq15_bk_top_sc: rhsusf_acc_anpeq15_top_sc
		{
			gjb_itn_interface[]=
			{
				"peq_15",
				"Rsc_gjb_itn_peq15",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b"
			};
		};
	//peq15 w/ m952v
		class rhsusf_acc_anpeq15: deviceBase_peq15_comboVIR
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0379122,0.0361294,-0.0104568},
				{-0.0401166,0.0687026,-0.00147115},	//"ir_flash dir", DEV Branch
				{-0.0810881,-0.0168364,0.0363066}
			};
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
		class rhsusf_acc_anpeq15_bk: rhsusf_acc_anpeq15
		{
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
		class rhsusf_acc_anpeq15_h;
		class rhsusf_acc_anpeq15_sc;
		class rhsusf_acc_anpeq15_bk_h: rhsusf_acc_anpeq15_h
		{
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
		class rhsusf_acc_anpeq15_bk_sc: rhsusf_acc_anpeq15_sc
		{	
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
		class rhsusf_acc_anpeq15_bk_light: rhsusf_acc_anpeq15_bk
		{
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
		class rhsusf_acc_anpeq15_bk_light_h: rhsusf_acc_anpeq15_h
		{
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
		class rhsusf_acc_anpeq15_bk_light_sc: rhsusf_acc_anpeq15_sc
		{
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15_b",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
	//peq15 w/ wmx
		class rhsusf_acc_anpeq15_wmx: rhsusf_acc_anpeq15
		{
			gjb_itn_interface[]=
			{
				"peq_15_combo",
				"Rsc_gjb_itn_peq15_combo_rhs_wmx",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq15",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\wmx"
			};
		};
	//peq16
		class rhsusf_acc_anpeq16a: acc_pointer_IR
		{
			gjb_itn_interface[]=
			{
				"peq_16",
				"Rsc_gjb_itn_peq16_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\peq16"
			};
		};
	//Flashlights
		class rhsusf_acc_m952v: deviceBase_m952
		{
			gjb_itn_interface[]=
			{
				"m952",
				"Rsc_gjb_itn_m952v",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v"
			};
		};
		class rhsusf_acc_wmx: rhsusf_acc_m952v
		{
			gjb_itn_interface[]=
			{
				"m952",
				"Rsc_gjb_itn_wmx_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\wmx"
			};
		};
		class rhsusf_acc_wmx_bk: rhsusf_acc_wmx
		{
			gjb_itn_interface[]=
			{
				"m952",
				"Rsc_gjb_itn_wmx_rhs",
				"\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\wmx_b"
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
	//HK416
		/*class rhs_weap_hk416d10
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.207272,0.0437459,0.114046}
			};
		};
		class rhs_weap_hk416d10_m320: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d10_LMT: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d10_LMT_d: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d10_LMT_wd: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d145: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d145_d: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d145_d_2: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d145_m320: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d145_wd: rhs_weap_hk416d10
		{};
		class rhs_weap_hk416d145_wd_2: rhs_weap_hk416d10
		{};
		class rhs_weap_m27iar: rhs_weap_hk416d10
		{};
		class rhs_weap_m27iar_grip: rhs_weap_hk416d10
		{};*/
	//M14 has exception
		/*class rhs_weap_m14_ris 
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.301526,0.0364198,0.118989}
			};
		};
		class rhs_weap_m14_ris_d: rhs_weap_m14_ris
		{};
		class rhs_weap_m14_ris_fiberglass: rhs_weap_m14_ris
		{};
		class rhs_weap_m14_ris_wd: rhs_weap_m14_ris
		{};
		class rhs_weap_m14_socom: rhs_weap_m14_ris
		{};
		class rhs_weap_m14ebrri
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.342535,0.0379324,0.114975}
			};
		};*/
		class rhs_weap_m14_socom_rail
		{
			gjb_itn_nonStdRailFix="topRailOnly";
			/*gjb_itn_memoryPoints[]=
			{
				{-0.196749,-0.0368327,0.118092}
			};*/
		};
	//M16
		/*class rhs_weap_m16a4 
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.299294,0.0460483,0.119975}
			};
		};
		class rhs_weap_m16a4_carryhandle: rhs_weap_m16a4
		{};
		class rhs_weap_m16a4_carryhandle_M203: rhs_weap_m16a4
		{};
		class rhs_weap_m16a4_imod: rhs_weap_m16a4
		{};
		class rhs_weap_m16a4_imod_M203: rhs_weap_m16a4
		{};*/
	//M2010
		/*class rhs_weap_XM2010 
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.440735,0.0486465,0.115309}
			};
		};
		class rhs_weap_XM2010_wd: rhs_weap_XM2010
		{};
		class rhs_weap_XM2010_d: rhs_weap_XM2010
		{};
		class rhs_weap_XM2010_sa: rhs_weap_XM2010
		{};*/
	//M240
		/*class rhs_weap_m240B
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.436769,0.0569553,0.079886}
			};
		};*/
	//M249
		/*class rhs_weap_m249_light_L 
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.216951,0.0455477,0.0594115}
			};
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
		{};*/
	//M32		(Weird one!)
		class rhs_weap_m32 
		{
			//Has side slot proxy, it will return from selectionNames, but won't locate with selectionPosition?
		};
	//M4
		/*class rhs_weap_m4
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.046036,0.119991}
			};
		};
		class rhs_weap_m4_carryhandle
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0460483,0.119975}
			};
		};
		class rhs_weap_m4_carryhandle_m203
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0458647,0.119877}
			};
		};
		class rhs_weap_m4_carryhandle_m203S: rhs_weap_m4_carryhandle_m203
		{};
		class rhs_weap_m4_carryhandle_mstock
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0461727,0.119972}
			};
		};
		class rhs_weap_m4_m203
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0460868,0.119997}
			};
		};
		class rhs_weap_m4_m203S: rhs_weap_m4_m203
		{};
		class rhs_weap_m4_m320: rhs_weap_m4_m203
		{};
		class rhs_weap_m4_mstock
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0460722,0.119938}
			};
		};*/
	//M40A1
		/*class rhs_weap_m40a5
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.365925,0.0536639,0.114528}
			};
		};
		class rhs_weap_m40a5_d: rhs_weap_m40a5
		{};
		class rhs_weap_m40a5_wd: rhs_weap_m40a5
		{};*/
	//M4A1
		/*class rhs_weap_m4a1_carryhandle 
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0460483,0.119975}
			};
		};
		class rhs_weap_m4a1_carryhandle_m203
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0458647,0.119877}
			};
		};
		class rhs_weap_m4a1_carryhandle_m203S: rhs_weap_m4a1_carryhandle_m203
		{};
		class rhs_weap_m4a1_carryhandle_mstock
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0461727,0.119972}
			};
		};
		class rhs_weap_m4a1_blockII
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.241762,0.046036,0.119991}
			};
		};
		class rhs_weap_m4a1_blockII_bk: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_M203_bk: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_KAC_bk: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_d: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_M203_d: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_KAC_d: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_M203: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_KAC: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_wd: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_M203_wd: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1_blockII_KAC_wd: rhs_weap_m4a1_blockII
		{};
		class rhs_weap_m4a1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.046036,0.119991}
			};
		};
		class rhs_weap_m4a1_d: rhs_weap_m4a1
		{};
		class rhs_weap_m4a1_wd: rhs_weap_m4a1
		{};
		class rhs_weap_m4a1_m203s_d
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0460868,0.119997}
			};
		};
		class rhs_weap_m4a1_m203: rhs_weap_m4a1_m203s_d
		{};
		class rhs_weap_m4a1_m203s: rhs_weap_m4a1_m203s_d
		{};
		class rhs_weap_m4a1_m320: rhs_weap_m4a1_m203s_d
		{};
		class rhs_weap_m4a1_m203s_wd: rhs_weap_m4a1_m203s_d
		{};
		class rhs_weap_m4a1_d_mstock
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166951,0.0460722,0.119938}
			};
		};
		class rhs_weap_m4a1_mstock: rhs_weap_m4a1_d_mstock
		{};
		class rhs_weap_m4a1_wd_mstock: rhs_weap_m4a1_d_mstock
		{};*/
	//Mk11 Has exception
		class rhs_weap_sr25
		{
			gjb_itn_nonStdRailFix="leftRailOnly";
			/*gjb_itn_memoryPoints[]=
			{
				{-0.291157,-0.0401642,0.0568923}
			};*/
		};/*
		class rhs_weap_sr25_d: rhs_weap_sr25
		{};
		class rhs_weap_sr25_wd: rhs_weap_sr25
		{};
		class rhs_weap_sr25_ec
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.291324,-0.0401473,0.0569897}
			};
		};
		class rhs_weap_sr25_ec_d: rhs_weap_sr25_ec
		{};
		class rhs_weap_sr25_ec_wd: rhs_weap_sr25_ec
		{};*/
	//Mk17
		/*class rhs_weap_mk17_CQC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.219578,0.0403256,0.0886029}
			};
		};
		class rhs_weap_mk17_LB: rhs_weap_mk17_CQC
		{};
		class rhs_weap_mk17_STD: rhs_weap_mk17_CQC
		{};
		class rhs_weap_SCARH_USA_CQC: rhs_weap_mk17_CQC
		{};
		class rhs_weap_SCARH_USA_LB: rhs_weap_mk17_CQC
		{};
		class rhs_weap_SCARH_USA_STD: rhs_weap_mk17_CQC
		{};*/
	//Mk18
		/*class rhs_weap_mk18
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.186951,0.046036,0.119991}
			};
		};
		class rhs_weap_mk18_bk: rhs_weap_mk18
		{};
		class rhs_weap_mk18_KAC_bk: rhs_weap_mk18
		{};
		class rhs_weap_mk18_d: rhs_weap_mk18
		{};
		class rhs_weap_mk18_KAC_d: rhs_weap_mk18
		{};
		class rhs_weap_mk18_m320: rhs_weap_mk18
		{};
		class rhs_weap_mk18_KAC: rhs_weap_mk18
		{};
		class rhs_weap_mk18_wd: rhs_weap_mk18
		{};
		class rhs_weap_mk18_KAC_wd: rhs_weap_mk18
		{};*/
	//MP7 Has exception
		/*class rhsusf_weap_MP7A2
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.137893,0.0363496,0.112804}
			};
		};
		class rhsusf_weap_MP7A2_aor1: rhsusf_weap_MP7A2
		{};
		class rhsusf_weap_MP7A2_desert: rhsusf_weap_MP7A2
		{};
		class rhsusf_weap_MP7A2_winter: rhsusf_weap_MP7A2
		{};*/
		class rhsusf_weap_MP7A2_folded
		{
			gjb_itn_nonStdRailFix="rifleNotPistol";
			/*gjb_itn_memoryPoints[]=
			{
				{-0.0898929,0.00634957,0.0498044}
			};*/
		};
		/*class rhsusf_weap_MP7A2_folded_winter: rhsusf_weap_MP7A2_folded
		{};
		class rhsusf_weap_MP7A2_folded_aor1: rhsusf_weap_MP7A2_folded
		{};
		class rhsusf_weap_MP7A2_folded_desert: rhsusf_weap_MP7A2_folded
		{};*/
	//
	};
};