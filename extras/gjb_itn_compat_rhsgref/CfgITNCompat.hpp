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
	//M21
		class rhs_weap_m21a
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.30075,2.10833e-005,0.0705458}
			};
		};
		class rhs_weap_m21a_pr: rhs_weap_m21a
		{};
		class rhs_weap_m21s: rhs_weap_m21a
		{};
		class rhs_weap_m21s_pr: rhs_weap_m21a
		{};
	//M70
		class rhs_weap_m70ab2
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.394918,1.54937e-006,0.0709924}
			};
		};
		class rhs_weap_m70b1: rhs_weap_m70ab2
		{};
	//M76
		class rhs_weap_m76
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.173591,0.0405726,0.101101}
			};
		};
	//M92
		class rhs_weap_m92
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.173591,0.0405726,0.101101}
			};
		};
	//Vz58
		class rhs_weap_savz58v_ris
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.186624,0.0440728,0.103221}
			};
		};
	//VHS-2
		class rhs_weap_vhsd2 
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.121395,0.051246,0.0769876}
			};
		};
		class rhs_weap_vhsd2_ct15x: rhs_weap_vhsd2
		{};
		class rhs_weap_vhsk2: rhs_weap_vhsd2
		{};
		class rhs_weap_vhsd2_bg
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.121395,0.044126,0.0856876}
			};
		};
		class rhs_weap_vhsd2_bg_ct15x: rhs_weap_vhsd2_bg
		{};
	};
};