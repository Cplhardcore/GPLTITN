class CfgITNCompat
{
//Accessories
	class accessories
	{};
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
	//FN Minimi
		class rhs_weap_minimi_para_railed
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.216951,0.0455477,0.0594115}
			};
		};
	//G36
		class rhs_weap_g36c
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.191399,0.0466169,0.0988179}
			};
		};
		class rhs_weap_g36kv
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.277032,0.0466169,0.0988179}
			};
		};
		class rhs_weap_g36kv_ag36: rhs_weap_g36kv
		{};
	//M21
		class rhs_weap_m21a_pbg40
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.36075,2.10833e-005,0.0705458}
			};
		};
		class rhs_weap_m21a_pr_pbg40: rhs_weap_m21a_pbg40
		{};
	//M70
		class rhs_weap_m70b1n
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.394918,1.54937e-006,0.0709924}
			};
		};
		class rhs_weap_m70b3n: rhs_weap_m70b1n
		{};
		class rhs_weap_m70b3n_pbg40: rhs_weap_m70b1n
		{};
	//SCAR-H
		class rhs_weap_SCARH_CQC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.219578,0.0403256,0.0886029}
			};
		};
		class rhs_weap_SCARH_FDE_CQC: rhs_weap_SCARH_CQC
		{};
		class rhs_weap_SCARH_LB: rhs_weap_SCARH_CQC
		{};
		class rhs_weap_SCARH_FDE_LB: rhs_weap_SCARH_CQC
		{};
		class rhs_weap_SCARH_STD: rhs_weap_SCARH_CQC
		{};
		class rhs_weap_SCARH_FDE_STD: rhs_weap_SCARH_CQC
		{};
	};
};