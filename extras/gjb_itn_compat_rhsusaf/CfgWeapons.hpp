class CfgWeapons
{
	class ItemCore;
	class acc_pointer_IR;
	class rhsusf_acc_anpeq15A: acc_pointer_IR
	{
		displayName="AN/PEQ-15A DBAL-A2";
	};
	class rhsusf_acc_anpeq15: acc_pointer_IR
	{
		displayName="AN/PEQ-15 ATPIAL-TN w/ M952V";
	};
	class rhsusf_acc_anpeq15_bk: rhsusf_acc_anpeq15
	{
		displayName="AN/PEQ-15 ATPIAL-BK w/ M952V";
	};
	class rhsusf_acc_anpeq15_light: rhsusf_acc_anpeq15
	{
		scope=1;
		scopeArsenal=1;
	};
	class rhsusf_acc_anpeq15_wmx: rhsusf_acc_anpeq15
	{
		displayName="AN/PEQ-15 ATPIAL-TN w/ WMX";
	};
	class rhsusf_acc_anpeq15_top: rhsusf_acc_anpeq15A
	{
		displayName="AN/PEQ-15 ATPIAL-TN (Top)";
	};
	class rhsusf_acc_anpeq15_bk_top: rhsusf_acc_anpeq15_top
	{
		displayName="AN/PEQ-15 ATPIAL-BK (Top)";
	};
	class rhsusf_acc_anpeq15side: acc_pointer_IR
	{
		displayName="AN/PEQ-15 ATPIAL-TN";
	};
	class rhsusf_acc_anpeq15side_bk: rhsusf_acc_anpeq15side
	{
		displayName="AN/PEQ-15 ATPIAL-BK";
	};
	class rhsusf_acc_anpeq16a: rhsusf_acc_anpeq15
	{
		displayName="AN/PEQ-16B MIPIM";
	};
	class rhsusf_acc_anpeq16a_top: rhsusf_acc_anpeq16a
	{
		displayName="AN/PEQ-16B MIPIM (Top)";
	};
	class rhsusf_acc_M952V: rhsusf_acc_anpeq15_light
	{
		scope=2;
		scopeArsenal=2;
		displayName="M952V";
	};
	class rhsusf_acc_wmx: rhsusf_acc_M952V
	{
		displayName="WMX-200";
	};
	class rhsusf_acc_wmx_bk: rhsusf_acc_M952V
	{
		displayName="WMX-200-BK";
	};
	//weapons
	class rhs_weap_m4_Base;
	class rhs_weap_m4: rhs_weap_m4_Base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.046036,0.119991}
		};
	};
	class rhs_weap_m4_carryhandle: rhs_weap_m4
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0460483,0.119975}
		};
	};
	class rhs_weap_m4_carryhandle_mstock: rhs_weap_m4_carryhandle
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0461727,0.119972}
		};
	};
	class rhs_weap_m4_m320: rhs_weap_m4
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0460868,0.119997}
		};
	};
	class rhs_weap_m4_m203;
	class rhs_weap_m4_carryhandle_m203: rhs_weap_m4_m203
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0458647,0.119877}
		};
	};
	class rhs_weap_m4a1: rhs_weap_m4_Base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.046036,0.119991}
		};
	};
	class rhs_weap_hk416d10: rhs_weap_m4a1
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.207272,0.0437459,0.114046}
		};
	};
	class rhs_weap_m4a1_blockII: rhs_weap_m4a1
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.241762,0.046036,0.119991}
		};
	};
	class rhs_weap_mk18: rhs_weap_m4a1_blockII
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.186951,0.046036,0.119991}
		};
	};
	class rhs_weap_m4a1_carryhandle: rhs_weap_m4a1
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0460483,0.119975}
		};
	};
	class rhs_weap_m4a1_carryhandle_mstock: rhs_weap_m4a1_carryhandle
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0461727,0.119972}
		};
	};
	class rhs_weap_m4a1_m203: rhs_weap_m4a1
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0460868,0.119997}
		};
	};
	class rhs_weap_m4a1_carryhandle_m203: rhs_weap_m4a1_m203
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0458647,0.119877}
		};
	};
	class rhs_weap_m4a1_d;
	class rhs_weap_m4a1_d_mstock: rhs_weap_m4a1_d
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,0.0460722,0.119938}
		};
	};
	class rhs_weap_m16a4: rhs_weap_m4_Base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.299294,0.0460483,0.119975}
		};
	};
	class rhs_weap_m14_ris_base;
	class rhs_weap_m14_ris: rhs_weap_m14_ris_base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.301526,0.0364198,0.118989}
		};
	};
	class rhs_weap_m14_socom_rail_base;
	class rhs_weap_m14_socom_rail: rhs_weap_m14_socom_rail_base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.196749,-0.0368327,0.118092}
		};
	};
	class rhs_weap_m14ebrri_base;
	class rhs_weap_m14ebrri: rhs_weap_m14ebrri_base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.342535,0.0379324,0.114975}
		};
	};
	class rhs_weap_sr25: rhs_weap_m14ebrri
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.291157,-0.0401642,0.0568923}
		};
	};
	class rhs_weap_sr25_ec: rhs_weap_sr25
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.291324,-0.0401473,0.0569897}
		};
	};
	class rhs_weap_XM2010_Base_F;
	class rhs_weap_XM2010: rhs_weap_XM2010_Base_F
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.440735,0.0486465,0.115309}
		};
	};
	class rhs_weap_m40a5: rhs_weap_XM2010_Base_F
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.365925,0.0536639,0.114528}
		};
	};
	class rhs_weap_m240_base;
	class rhs_weap_m240B: rhs_weap_m240_base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.436769,0.0569553,0.079886}
		};
	};
	class rhs_weap_lmg_minimi_railed;
	class rhs_weap_m249_pip_L: rhs_weap_lmg_minimi_railed
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216951,0.0455477,0.0594115}
		};
	};
	class rhs_weap_m249_pip_S: rhs_weap_lmg_minimi_railed
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216951,0.0455477,0.0594115}
		};
	};
	class rhs_weap_SCAR_Base;
	class rhs_weap_SCAR_H_Base: rhs_weap_SCAR_Base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.219578,0.0403256,0.0886029}
		};
	};
	class rhsusf_weap_MP7A1_base_f;
	class rhsusf_weap_MP7A2: rhsusf_weap_MP7A1_base_f
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.137893,0.0363496,0.112804}
		};
	};
	class rhsusf_weap_MP7A2_folded: rhsusf_weap_MP7A2
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.0898929,0.00634957,0.0498044}
		};
	};
};