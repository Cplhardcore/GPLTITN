class CfgITNCompat
{
//Accessories
	class accessories
	{
		class acc_flashlight;
		class acc_pointer_IR;
	//DBAL-PL
		class hlc_acc_dbalpl: acc_pointer_IR
		{
			gjb_itn_interface[]=
			{
				"dbal_pl",
				"Rsc_gjb_itn_acc_dbalPl_nia",
				"\gjb_itn\addons\gjb_itn_compat_nia\ui\dbalpl"
			};
		};
		class hlc_acc_dbalpl_fl: hlc_acc_dbalpl
		{};
		class hlc_acc_dbalpl_g: hlc_acc_dbalpl
		{
			gjb_itn_deviceSpecs[]=
			{
				"MT/LT",						// 0 NULL entry to sidestep complicated fix
				{{0,25000,0},{0,50,0},0.12,0.00005,200,0},// 1 vis laser green
				{{100,0,0},{5,0,0},0.4,0.00001,400,1},	// 2 ir laser
				"gjb_itn_flash_dbal_pl_ir",	// 3 ir illuminator (18* Illum divergeance, LED)
				"gjb_itn_flash_dbal_pl_vis"		// 4 vis flashlight
			};
		};
		class hlc_acc_dbalpl_fl_g: hlc_acc_dbalpl_g
		{};
		class hlc_acc_dbalpl_side_g: hlc_acc_dbalpl_g
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0471006,0.00707642,0.0410124},
				{-0.0471006,0.00707642,0.0410124},
				{-0.0471006,0.00707642,0.0410124}
			};
		};
		class hlc_acc_dbalpl_side_fl_g: hlc_acc_dbalpl_side_g
		{};
	//TLR1
		class hlc_acc_tlr1: acc_flashlight
		{
			gjb_itn_interface[]=
			{
				"utg",
				"Rsc_gjb_itn_acc_flashlight_pistol",
				"\gjb_itn\addons\gjb_itn_compat_nia\ui\tlr"
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
	//AR-15		(Skipped classes without lasers)
		class hlc_rifle_honeybadger
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.30614,0.0402777,0.10814}
			};
		};
		class hlc_rifle_RU5562
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.241462,0.0401873,0.105765}
			};
		};
		class hlc_rifle_RU556: hlc_rifle_RU5562
		{};
		class hlc_rifle_bcmblackjack
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.27729,0.0444585,0.105046}
			};
		};
		class hlc_rifle_bcmjack: hlc_rifle_bcmblackjack
		{};
		class hlc_rifle_M4
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.197745,0.043956,0.103245}
			};
		};
		class hlc_rifle_M4a1carryhandle: hlc_rifle_M4
		{};
		class hlc_rifle_m4m203: hlc_rifle_M4
		{};
		class hlc_rifle_CQBR: hlc_rifle_M4
		{};
		class hlc_rifle_mk18mod0
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.204928,0.0438087,0.104874}
			};
		};
		class hlc_rifle_SAMR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.30613,0.044778,0.103396}
			};
		};
		class hlc_rifle_samr2: hlc_rifle_SAMR
		{};
	//AK
		class hlc_rifle_slr107u
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.136426,0.0416085,0.116053}
			};
		};
		class hlc_rifle_slr107u_MTK: hlc_rifle_slr107u
		{};
		class hlc_rifle_ak12
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.205108,0.0335113,0.113553}
			};
		};
		class hlc_rifle_aku12: hlc_rifle_ak12
		{};
		class hlc_rifle_RPK12: hlc_rifle_ak12
		{};
		class hlc_rifle_ak12GL
		{
			gjb_itn_nonStdRailFix="leftRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.205108,-0.0303743,0.0406698}
			};
		};
	//FALs		(Skipped classes without lasers)
		class hlc_rifle_falosw
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.214833,0.036916,0.105583}
			};
		};
		class hlc_rifle_osw_GL: hlc_rifle_falosw
		{};
	//FN30		(Skipped classes without lasers)
		class hlc_rifle_FN3011Tactical_green
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.124774,0.0622971,0.125919}
			};
		};
		class hlc_rifle_FN3011Tactical_grey: hlc_rifle_FN3011Tactical_green
		{};
		class hlc_rifle_FN3011Tactical: hlc_rifle_FN3011Tactical_green
		{};
	//G36		(Skipped classes without lasers)
		class hlc_rifle_G36MLIC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.327951,0.045839,0.0950381}
			};
		};
		class hlc_rifle_G36MLIAG36
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.262898,0.0446434,0.0998046}
			};
		};
		class hlc_rifle_G36VAG36: hlc_rifle_G36MLIAG36
		{};
		class hlc_rifle_G36C
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.212499,0.0446434,0.0998046}
			};
		};
		class hlc_rifle_G36CMLIC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.228636,0.045839,0.0950381}
			};
		};
		class hlc_rifle_G36CTac: hlc_rifle_G36CMLIC
		{};
		class hlc_rifle_G36CV
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.212005,0.0446434,0.0998046}
			};
		};
		class hlc_rifle_G36KA1KSK
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.287928,0.045839,0.0950381}
			};
		};
		class hlc_rifle_G36KMLIC: hlc_rifle_G36KA1KSK
		{};
		class hlc_rifle_g36KTac: hlc_rifle_G36KA1KSK
		{};
		class hlc_rifle_G36KV
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.271181,0.0446434,0.0998046}
			};
		};
		class hlc_rifle_G36V
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.302709,0.0466169,0.0988179}
			};
		};
		class hlc_rifle_G36TAC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.329433,0.045839,0.0950381}
			};
		};
	//G3
		class hlc_rifle_g3ka4
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.347922,0.0364734,0.124966}
			};
		};
		class HLC_Rifle_g3ka4_GL: hlc_rifle_g3ka4
		{};
	//HK33
		class hlc_rifle_hk33a2RIS
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.296592,0.0382272,0.125402}
			};
		};
		class hlc_rifle_hk33a2RIS_GL: hlc_rifle_hk33a2RIS
		{};
	//HK146
		class hlc_rifle_416D10
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.225882,0.042922,0.103306}
			};
		};
		class hlc_rifle_416D10_gl: hlc_rifle_416D10
		{};
		class hlc_rifle_416D10_geissele: hlc_rifle_416D10
		{};
		class hlc_rifle_416D10_tan: hlc_rifle_416D10
		{};
		class hlc_rifle_416D10_wdl: hlc_rifle_416D10
		{};
		class hlc_rifle_416D145: hlc_rifle_416D10
		{};
		class hlc_rifle_416D145_gl: hlc_rifle_416D10
		{};
		class hlc_rifle_416D145_tan: hlc_rifle_416D10
		{};
		class hlc_rifle_416D145_wdl: hlc_rifle_416D10
		{};
		class hlc_rifle_416D145C: hlc_rifle_416D10
		{};
		class hlc_rifle_416N: hlc_rifle_416D10
		{};
		class hlc_rifle_416N_gl: hlc_rifle_416D10
		{};
		class hlc_rifle_416D10_st6
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.247314,0.0443902,0.103847}
			};
		};
		class hlc_rifle_416D10_ptato: hlc_rifle_416D10_st6
		{};
		class hlc_rifle_416D10_RAHG: hlc_rifle_416D10_st6
		{};
		class hlc_rifle_416D145_CAG: hlc_rifle_416D10_st6
		{};
		class hlc_rifle_416D10C
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.176029,0.0427087,0.10446}
			};
		};
		class hlc_rifle_416D10C_PTC: hlc_rifle_416D10C
		{};
		class hlc_rifle_416D165
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.275778,0.0430217,0.103306}
			};
		};
		class hlc_rifle_416D165_gl: hlc_rifle_416D165
		{};
		class hlc_rifle_416D165_tan: hlc_rifle_416D165
		{};
		class hlc_rifle_416D165_wdl: hlc_rifle_416D165
		{};
		class hlc_rifle_416D20: hlc_rifle_416D165
		{};
		class hlc_rifle_416D20_tan: hlc_rifle_416D165
		{};
		class hlc_rifle_416D20_wdl: hlc_rifle_416D165
		{};
		class hlc_rifle_M27IAR: hlc_rifle_416D165
		{};
		class hlc_rifle_416C
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.176029,0.0427087,0.10446}
			};
		};
		class hlc_rifle_BAB: hlc_rifle_416C
		{};
	//HK53
		class hlc_rifle_hk53RAS
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.17367,0.0366789,0.117465}
			};
		};
	//MP5
		class hlc_mp510_tac
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.166869,0.0346902,0.0991666}
			};
		};
		class hlc_smg_mp5a2_tac
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.168943,0.0360876,0.0956863}
			};
		};
		class hlc_smg_mp5a3_tac: hlc_smg_mp5a2_tac
		{};
		class hlc_smg_mp5a4_tac: hlc_smg_mp5a2_tac
		{};
		class hlc_smg_mp5N_tac: hlc_smg_mp5a2_tac
		{};
	//M249
		/*class hlc_m249_SQuantoon
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.17556,0.047151,0.0603418}
			};
		};
		class hlc_m249_pip4: hlc_m249_SQuantoon
		{};*/
	//Mk46
		/*class hlc_lmg_mk46
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.22947,0.0502855,0.0903269}
			};
		};
		class hlc_lmg_mk46mod1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.227471,0.0508562,0.0839419}
			};
		};*/
	//Mk48
		/*class hlc_lmg_mk48
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.250428,0.0502855,0.0903269}
			};
		};
		class hlc_lmg_mk48mod1
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.19472,0.0508562,0.0839419}
			};
		};*/
	//ACR
		class hlc_rifle_ACR_SBR_cliffhanger
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.199756,0.0420176,0.102842}
			};
		};
		class hlc_rifle_ACR_Carb_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_Carb_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_Carb_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_SBR_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_SBR_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_SBR_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_SBR_cliffhanger: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_Carb_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_Carb_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_Carb_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_SBR_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_SBR_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_SBR_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_mid_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_mid_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_GL_mid_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_full_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_full_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_full_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_MID_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_MID_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR_MID_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_Carb_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_Carb_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_Carb_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_SBR_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_SBR_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_Squant: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_SBR_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_Carb_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_Carb_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_Carb_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_SBR_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_SBR_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_SBR_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_mid_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_mid_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_GL_mid_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_full_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_full_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_full_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_MID_black: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_MID_green: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_MID_tan: hlc_rifle_ACR_SBR_cliffhanger
		{};
		class hlc_rifle_ACR68_aron: hlc_rifle_ACR_SBR_cliffhanger
		{};
	//MG3
		/*class hlc_lmg_MG3KWS_b
		{
			gjb_itn_nonStdRailFix="leftRailOnly";
			gjb_itn_memoryPoints[]=
			{
				{-0.518157,-0.0483725,0.00838994}
			};
		};
		class hlc_lmg_MG3KWS_g: hlc_lmg_MG3KWS_b
		{};
		class hlc_lmg_MG3KWS: hlc_lmg_MG3KWS_b
		{};*/
	//MG42 (Can accept lasers, but can't find side slot?!) Look for "proxy:\hlc_core\mesh\nia_charm_proxy.001"?
	//SG55x
		class hlc_rifle_SG550_TAC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.375052,0.0434653,0.112569}
			};
		};
		class hlc_rifle_SG550_TAC_GL: hlc_rifle_SG550_TAC
		{};
		class hlc_rifle_SG551LB_TAC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.293636,0.0434653,0.112569}
			};
		};
		class hlc_rifle_SG551SB_TAC: hlc_rifle_SG551LB_TAC
		{};
		class hlc_rifle_SG551SB_TAC_GL: hlc_rifle_SG551LB_TAC
		{};
		class hlc_rifle_SG551LB_TAC_GL
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.196863,0.0466169,0.0988179}
			};
		};
		class hlc_rifle_SG553LB_TAC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.184835,0.0434653,0.112569}
			};
		};
		class hlc_rifle_sg553RLB_TAC: hlc_rifle_SG553LB_TAC
		{};
		class hlc_rifle_sg553RSB_TAC: hlc_rifle_SG553LB_TAC
		{};
		class hlc_rifle_SG553SB_TAC
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.197398,0.0466169,0.114409}
			};
		};
	//AUG
		class hlc_rifle_auga3_b 
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.222353,0.0425588,0.0976671}
			};
		};
		class hlc_rifle_auga3_bl: hlc_rifle_auga3_b
		{};
		class hlc_rifle_auga3: hlc_rifle_auga3_b
		{};
		class hlc_rifle_auga3_GL_B
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.222513,0.0425588,0.0976671}
			};
		};
		class hlc_rifle_auga3_GL_BL: hlc_rifle_auga3_GL_B
		{};
		class hlc_rifle_auga3_GL: hlc_rifle_auga3_GL_B
		{};
	//M14
		class hlc_rifle_m14sopmod
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.280558,0.0457496,0.0912758}
			};
		};
	//
	};
};