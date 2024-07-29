class CfgWeapons
{
	class ItemCore;
	class acc_pointer_IR;
	class acc_flashlight;
	class rhs_acc_perst1ik;
	class rhs_acc_perst1ik_ris;
	//
	class rhs_acc_perst1_k: rhs_acc_perst1ik
	{
		displayName="Perst-1K";
	};
	class rhs_acc_perst1_k_ris: rhs_acc_perst1ik_ris
	{
		displayName="Perst-1K (RIS)";
	};
	//
	class rhs_acc_2dpZenit: acc_flashlight
	{
		displayName="Klesh-2DP";
	};
	class rhs_acc_2dpZenit_ris: rhs_acc_2dpZenit
	{
		displayName="Klesh-2DP (RIS)";
	};
	//
	class rhs_acc_perst3: rhs_acc_perst1ik
	{
		displayName="Perst-3";
	};
	class rhs_acc_perst3_top: rhs_acc_perst3
	{
		displayName="Perst-3 (Top)";
	};
	class rhs_acc_perst3_top_h: rhs_acc_perst3_top
	{};
	class rhs_acc_perst3_2dp: rhs_acc_perst3
	{
		displayName="Perst-3/Klesh-2DP";
	};
	class rhs_acc_perst3_2dp_light: rhs_acc_perst3_2dp
	{};
	class rhs_acc_perst3_2dp_h: rhs_acc_perst3_2dp
	{};
	class rhs_acc_perst3_2dp_light_h: rhs_acc_perst3_2dp_light
	{
		scope=1;
		scopeArsenal=1;
	};
	//
	class rhs_acc_perst3_g: rhs_acc_perst3
	{
		displayName="Perst-3 Green+";
		rhs_anpeq15_base="rhs_acc_perst3_g";
	};
	class rhs_acc_perst3_g_top: rhs_acc_perst3_top
	{
		displayName="Perst-3 Green+ (Top)";
		rhs_anpeq15_base="rhs_acc_perst3_g_top";
	};
	class rhs_acc_perst3_g_top_h: rhs_acc_perst3_top_h
	{
		displayName="Perst-3 Green+ (Top)";
		rhs_anpeq15_base="rhs_acc_perst3_g_top";
	};
	class rhs_acc_perst3_g_2dp: rhs_acc_perst3_2dp
	{
		displayName="Perst-3 Green+/Klesh-2DP";
		rhs_anpeq15_base="rhs_acc_perst3_g_2dp";
	};
	class rhs_acc_perst3_g_2dp_light: rhs_acc_perst3_2dp_light
	{
		displayName="Perst-3 Green+/Klesh-2DP";
		rhs_anpeq15_base="rhs_acc_perst3_g_2dp_light";
	};
	class rhs_acc_perst3_g_2dp_h: rhs_acc_perst3_2dp_h
	{
		displayName="Perst-3 Green+/Klesh-2DP";
		rhs_anpeq15_base="rhs_acc_perst3_g_2dp";
	};
	class rhs_acc_perst3_g_2dp_light_h: rhs_acc_perst3_2dp_light_h
	{
		displayName="Perst-3 Green+/Klesh-2DP";
		rhs_anpeq15_base="rhs_acc_perst3_g_2dp_light";
	};
	//weapons
	class rhs_weap_ak103_base;
	class rhs_weap_ak103: rhs_weap_ak103_base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.310862,0.000159584,0.073575}
		};
	};
	class rhs_weap_ak103_zenitco01: rhs_weap_ak103
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216837,0.038836,0.112894}
		};
	};
	class rhs_weap_ak74m_Base_F;
	class rhs_weap_ak74m: rhs_weap_ak74m_Base_F
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.310862,0.000159584,0.073575}
		};
	};
	class rhs_weap_ak74mr: rhs_weap_ak74m
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216837,0.045036,0.125094}
		};
	};
	class rhs_weap_ak74m_zenitco01: rhs_weap_ak74m
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216837,0.038836,0.112894}
		};
	};
	class rhs_weap_ak74: rhs_weap_ak74m
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.263646,0,0.0756}
		};
	};
	class rhs_weap_aks74: rhs_weap_ak74
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.302862,0,0.0756}
		};
	};
	class rhs_weap_ak104;
	class rhs_weap_ak104_zenitco01: rhs_weap_ak104
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216837,0.038836,0.112894}
		};
	};
	class rhs_weap_ak105;
	class rhs_weap_ak105_zenitco01: rhs_weap_ak105
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216837,0.038836,0.112894}
		};
	};
	class rhs_weap_akmn;
	class rhs_weap_akm_zenitco01_b33: rhs_weap_akmn
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.216837,0.038836,0.112894}
		};
	};
	class rhs_weap_asval;
	class rhs_weap_asval_grip: rhs_weap_asval
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.299315,0.0364596,0.00907064}
		};
	};
	class rhs_pkp_base;
	class rhs_weap_pkp: rhs_pkp_base
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.166951,-0.0169548,0.119975}
		};
	};
	class rhs_weap_rpk74n;
	class rhs_weap_rpk74m: rhs_weap_rpk74n
	{
		gjb_itn_nonStdRailFix="leftRailOnly";
		gjb_itn_memoryPoints[]=
		{
			{-0.305762,0.000159584,0.073575}
		};
	};
	class rhs_weap_vss;
	class rhs_weap_vss_grip: rhs_weap_vss
	{
		gjb_itn_memoryPoints[]=
		{
			{-0.299315,0.0364596,0.00907064}
		};
	};
};