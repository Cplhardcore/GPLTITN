class CfgPatches
{
	class gjb_itn_compat_gplt
	{
		units[]={};
		weapons[]={};
		requiredAddons[]=
		{
			"gjb_itn_core"
		};
		name="Illuminate The Night - GPLT Compat Patch";
		authors="GhostJB";
	};
};
class CfgITNCompat
{
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
		class GPLT_SideFSP3_LASER: deviceBase_la5b
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.124116,0.034205802,-0.0504326},
				{-0.124116,0.034205802,-0.0504326},
				{0,0,0}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideFSP3_Vis_Laser: GPLT_SideFSP3_LASER
		{
		};
		class GPLT_SideFSP3_FLASH: GPLT_SideFSP3_LASER
		{
		};
		class GPLT_SideLima_LASER: GPLT_SideFSP3_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.032523699,-0.031719901,0.021718301},
				{-0.032523699,-0.031719901,0.021718301},
				{0,0,0}
			};
		};
		class GPLT_SideLima_Vis_Laser: GPLT_SideLima_LASER
		{
		};
		class GPLT_SideLima_FLASH: GPLT_SideLima_LASER
		{
		};
		class GPLT_SideMonsoor_LASER: GPLT_SideFSP3_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0268072,0.042443901,-0.020848},
				{-0.0268072,0.042443901,-0.020848},
				{0,0,0}
			};
		};
		class GPLT_SideMonsoor_Vis_Laser: GPLT_SideMonsoor_LASER
		{
		};
		class GPLT_SideMonsoor_FLASH: GPLT_SideMonsoor_LASER
		{
		};
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
		{
		};
		class GPLT_SideMRAD_FLASH: GPLT_SideMRAD_LASER
		{
		};
		class GPLT_SideSASS_LASER: GPLT_SideFSP3_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0182602,0.034270499,-0.053282499},
				{-0.0182602,0.034270499,-0.053282499},
				{0,0,0}
			};
		};
		class GPLT_SideSASS_Vis_Laser: GPLT_SideSASS_LASER
		{
		};
		class GPLT_SideSASS_FLASH: GPLT_SideSASS_LASER
		{
		};
		class GPLT_SideSCAR2_LASER: GPLT_SideFSP3_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.066580601,0.034992501,-0.066153303},
				{-0.066580601,0.034992501,-0.066153303},
				{0,0,0}
			};
		};
		class GPLT_SideSCAR2_Vis_Laser: GPLT_SideSCAR2_LASER
		{
		};
		class GPLT_SideSCAR2_FLASH: GPLT_SideSCAR2_LASER
		{
		};
		class GPLT_SideBlock_LASER: deviceBase_la5b_comboGenVIR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.104871,0.0226421,0.0096418103},
				{-0.104871,0.0226421,0.0096418103},
				{-0.15838601,0.044000801,-0.024522301}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideBlock_Vis_Laser: GPLT_SideBlock_LASER
		{
		};
		class GPLT_SideBlock_FLASH: GPLT_SideBlock_LASER
		{
		};
		class GPLT_SideFSP_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.153753,0.0220119,0.0092258397},
				{-0.153753,0.0220119,0.0092258397},
				{-0.18692601,0.043370601,-0.0249383}
			};
		};
		class GPLT_SideFSP_Vis_Laser: GPLT_SideFSP_LASER
		{
		};
		class GPLT_SideFSP_FLASH: GPLT_SideFSP_LASER
		{
		};
		class GPLT_SideFSP2_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0158161,0.021350199,0.0090979896},
				{-0.0158161,0.021350199,0.0090979896},
				{-0.16004799,0.0432247,-0.021922801}
			};
		};
		class GPLT_SideFSP2_Vis_Laser: GPLT_SideFSP2_LASER
		{
		};
		class GPLT_SideFSP2_FLASH: GPLT_SideFSP2_LASER
		{
		};
		class GPLT_SideHound_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.10025,0.0229773,0.0098369103},
				{-0.10025,0.0229773,0.0098369103},
				{-0.095398098,0.0418601,-0.028206199}
			};
		};
		class GPLT_SideHound_Vis_Laser: GPLT_SideHound_LASER
		{
		};
		class GPLT_SideHound_FLASH: GPLT_SideHound_LASER
		{
		};
		class GPLT_SideHound2_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.071581602,0.033209398,-0.055318899},
				{-0.071581602,0.033209398,-0.055318899},
				{-0.092780001,-0.0422672,-0.034586102}
			};
		};
		class GPLT_SideHound2_Vis_Laser: GPLT_SideHound2_LASER
		{
		};
		class GPLT_SideHound2_FLASH: GPLT_SideHound2_LASER
		{
		};
		class GPLT_SideLURGI_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.084608801,0.023225799,0.0102457},
				{-0.084608801,0.023225799,0.0102457},
				{-0.117782,0.044584502,-0.0239184}
			};
		};
		class GPLT_SideLURGI_Vis_Laser: GPLT_SideLURGI_LASER
		{
		};
		class GPLT_SideLURGI_FLASH: GPLT_SideLURGI_LASER
		{
		};
		class GPLT_SideLURGI2_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{0.089553699,0.023328699,0.0098566497},
				{0.089553699,0.023328699,0.0098566497},
				{-0.117782,0.044687402,-0.024307501}
			};
		};
		class GPLT_SideLURGI2_Vis_Laser: GPLT_SideLURGI2_LASER
		{
		};
		class GPLT_SideLURGI2_FLASH: GPLT_SideLURGI2_LASER
		{
		};
		class GPLT_SideMod_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0372351,0.021966301,0.0091725904},
				{-0.0372351,0.021966301,0.0091725904},
				{-0.097114198,0.0433705,-0.0229798}
			};
		};
		class GPLT_SideMod_Vis_Laser: GPLT_SideMod_LASER
		{
		};
		class GPLT_SideMod_FLASH: GPLT_SideMod_LASER
		{
		};
		class GPLT_SideSCAR_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.060116898,0.0221503,0.0103575},
				{-0.060116898,0.0221503,0.0103575},
				{-0.074056096,0.041339599,-0.0183965}
			};
		};
		class GPLT_SideSCAR_Vis_Laser: GPLT_SideSCAR_LASER
		{
		};
		class GPLT_SideSCAR_FLASH: GPLT_SideSCAR_LASER
		{
		};
		class GPLT_SideSURGI_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{0.084936999,0.023742599,0.0095561203},
				{0.084936999,0.023742599,0.0095561203},
				{-0.0103059,0.044142999,-0.024780599}
			};
		};
		class GPLT_SideSURGI_Vis_Laser: GPLT_SideSURGI_LASER
		{
		};
		class GPLT_SideSURGI_FLASH: GPLT_SideSURGI_LASER
		{
		};
		class GPLT_SideSURGI3_LASER: GPLT_SideBlock_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{0.024903599,0.024660699,0.0099041099},
				{0.024903599,0.024660699,0.0099041099},
				{-0.0082692103,0.046019401,-0.024259999}
			};
		};
		class GPLT_SideSURGI3_Vis_Laser: GPLT_SideSURGI3_LASER
		{
		};
		class GPLT_SideSURGI3_FLASH: GPLT_SideSURGI3_LASER
		{
		};
		class GPLT_SideBlock2_LASER: deviceBase_la5b_comboGenVIR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.104871,0.0226421,0.0096418103},
				{-0.104871,0.0226421,0.0096418103},
				{-0.15345,0.044000801,-0.0265665}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideBlock2_Vis_Laser: GPLT_SideBlock2_LASER
		{
		};
		class GPLT_SideBlock2_FLASH: GPLT_SideBlock2_LASER
		{
		};
		class GPLT_SideMod2_LASER: GPLT_SideBlock2_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0372351,0.022552099,0.0097486898},
				{-0.0372351,0.022552099,0.0097486898},
				{-0.085988998,0.043956298,-0.0261443}
			};
		};
		class GPLT_SideMod2_Vis_Laser: GPLT_SideMod2_LASER
		{
		};
		class GPLT_SideMod2_FLASH: GPLT_SideMod2_LASER
		{
		};
		class GPLT_SideFSP4_LASER: deviceBase_ngal_comboGenVIR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.147461,0.0178189,0.018033201},
				{-0.147461,0.0178189,0.018033201},
				{-0.184714,-0.041121799,-0.00274943}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideFSP4_Vis_Laser: GPLT_SideFSP4_LASER
		{
		};
		class GPLT_SideFSP4_FLASH: GPLT_SideFSP4_LASER
		{
		};
		class GPLT_SideLURGI3_LASER: GPLT_SideFSP4_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.096818902,0.0194645,0.00674649},
				{-0.096818902,0.0194645,0.00674649},
				{-0.15672,-0.040618401,-0.00160074}
			};
		};
		class GPLT_SideLURGI3_Vis_Laser: GPLT_SideLURGI3_LASER
		{
		};
		class GPLT_SideLURGI3_FLASH: GPLT_SideLURGI3_LASER
		{
		};
		class GPLT_SideLURGI4_LASER: GPLT_SideFSP4_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.087363802,0.034164399,-0.044454101},
				{-0.087363802,0.034164399,-0.044454101},
				{-0.120299,-0.037625,-0.0033277001}
			};
		};
		class GPLT_SideLURGI4_Vis_Laser: GPLT_SideLURGI4_LASER
		{
		};
		class GPLT_SideLURGI4_FLASH: GPLT_SideLURGI4_LASER
		{
		};
		class GPLT_SideMod3_LASER: GPLT_SideFSP4_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.047085699,0.0156678,0.0066940701},
				{-0.047085699,0.0156678,0.0066940701},
				{-0.108367,0.040513098,-0.00295485}
			};
		};
		class GPLT_SideMod3_Vis_Laser: GPLT_SideMod3_LASER
		{
		};
		class GPLT_SideMod3_FLASH: GPLT_SideMod3_LASER
		{
		};
		class GPLT_SideSURGI4_LASER: GPLT_SideFSP4_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{0.0064189099,0.016909899,0.0068879798},
				{0.0064189099,0.016909899,0.0068879798},
				{-0.0241515,0.042762998,-0.00210545}
			};
		};
		class GPLT_SideSURGI4_Vis_Laser: GPLT_SideSURGI4_LASER
		{
		};
		class GPLT_SideSURGI4_FLASH: GPLT_SideSURGI4_LASER
		{
		};
		class GPLT_SideSCAR3_LASER: deviceBase_ngal_comboGenVIR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.052767899,0.0159203,0.0074865902},
				{-0.052767899,0.0159203,0.0074865902},
				{-0.055342302,0.044484101,-0.0438607}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideSCAR3_Vis_Laser: GPLT_SideSCAR3_LASER
		{
		};
		class GPLT_SideSCAR3_FLASH: GPLT_SideSCAR3_LASER
		{
		};
		class GPLT_SideSURGI2_LASER: GPLT_SideSCAR3_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{0.088118397,0.016816299,0.0066575701},
				{0.088118397,0.016816299,0.0066575701},
				{-0.032999001,0.046268702,-0.027107401}
			};
		};
		class GPLT_SideSURGI2_Vis_Laser: GPLT_SideSURGI2_LASER
		{
		};
		class GPLT_SideSURGI2_FLASH: GPLT_SideSURGI2_LASER
		{
		};
		class GPLT_SideLT_LASER: deviceBase_ngal_comboGenWO
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.091873899,0.015958,0.0118999},
				{-0.091873899,0.015958,0.0118999},
				{-0.15457501,0.0308994,-0.0051638298}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideLT_Vis_Laser: GPLT_SideLT_LASER
		{
		};
		class GPLT_SideLT_FLASH: GPLT_SideLT_LASER
		{
		};
		class GPLT_SideLT2_LASER: GPLT_SideLT_LASER
		{
			gjb_itn_memoryPoints[]=
			{
				{0.045621701,0.015958,0.0118999},
				{0.045621701,0.015958,0.0118999},
				{-0.121484,0.0308994,-0.0051638298}
			};
		};
		class GPLT_SideLT2_Vis_Laser: GPLT_SideLT2_LASER
		{
		};
		class GPLT_SideLT2_FLASH: GPLT_SideLT2_LASER
		{
		};
		class GPLT_SideLT4_LASER: deviceBase_ngal_comboGenVIR
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.103569,0.040864199,0.0160881},
				{-0.103569,0.040864199,0.0160881},
				{-0.120531,0.0445017,-0.031977098}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideLT4_Vis_Laser: GPLT_SideLT4_LASER
		{
		};
		class GPLT_SideLT4_FLASH: GPLT_SideLT4_LASER
		{
		};
		class GPLT_SideLT3_LASER: deviceBase_ngal_comboGenWO
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.0889901,4.0663701e-005,0.0227054},
				{-0.0889901,4.0663701e-005,0.0227054},
				{-0.111995,-0.038795602,-0.0108937}
			};
			gjb_itn_interface[]=
			{
				"generic",
				"Rsc_gjb_itn_generic_deviceclass"
			};
		};
		class GPLT_SideLT3_Vis_Laser: GPLT_SideLT3_LASER
		{
		};
		class GPLT_SideLT3_FLASH: GPLT_SideLT3_LASER
		{
		};
	};
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
				{-0.18799999,0,0.098999999}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_FSP_Base
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.18799999,0,0.098999999}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_MK17
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.17200001,0,0.119}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_MK18
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.18799999,0,0.098999999}
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
			gjb_itn_beltFedFix=0.18000001;
		};
		class GPLT_MK48_S
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.242,0,0.037}
			};
			gjb_itn_nonStdRailFix="rawPos";
			gjb_itn_beltFedFix=0.18000001;
		};
		class GPLT_MRAD
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.32100001,0,0.107}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_SPEAR_LT
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.18799999,0,0.098999999}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_URGI_10
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.234,0.001,0.097999997}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
		class GPLT_URGI_14
		{
			gjb_itn_memoryPoints[]=
			{
				{-0.234,0.001,0.097999997}
			};
			gjb_itn_nonStdRailFix="rawPos";
		};
	};
};
class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_ctrlsHolder_base;
class RscCombo;
class Rsc_gjb_itn_dbala2;
class Rsc_gjb_itn_peq15_combo;
class Rsc_gjb_itn_ngal_GPLT: Rsc_gjb_itn_peq15_combo
{
	idd=314039;
	movingEnable=1;
	enableSimulation=1;
	onLoad="";
	onUnload="";
	controlsBackground[]=
	{
		"deviceL",
		"device",
		"knob_mode"
	};
	controls[]=
	{
		"onIndicator",
		"overlay",
		"overlayL",
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
	};
	class deviceL: device
	{
		idc=1003;
	};
	class knob_mode: device
	{
		idc=1001;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		type=4;
		idc=1050;
		style=0;
		font="PuristaMedium";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x="safeZoneX + safeZoneW * 0.4296875";
				y="safeZoneY + safeZoneH * 0.66666667";
				w="safeZoneW * 0.0390625";
				h="safeZoneH * 0.0625";
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="Activation Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on: button_mode
			{
				idc=1101;
				x="safeZoneX + safeZoneW * 0.44335938";
				y="safeZoneY + safeZoneH * 0.58159723";
				w="safeZoneW * 0.02539063";
				h="safeZoneH * 0.04861112";
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for continuous on for 5 minutes";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x="safeZoneX + safeZoneW * 0.40234375";
				y="safeZoneY + safeZoneH * 0.54166667";
				w="safeZoneW * 0.03515625";
				h="safeZoneH * 0.0625";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="Toggle diffusor cap: Left-click";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x="safeZoneX + safeZoneW * 0.40722657";
				y="safeZoneY + safeZoneH * 0.74652778";
				w="safeZoneW * 0.03125";
				h="safeZoneH * 0.06944445";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="Adjust Illuminator Focus: Left-click to narrow, Right-click to widen, or scroll with Mouse-wheel";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x="safeZoneX + safeZoneW * 0.52050782";
				y="safeZoneY + safeZoneH * 0.77430556";
				w="safeZoneW * 0.03125";
				h="safeZoneH * 0.05555556";
				onMouseButtonDown="['fire2.5',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for continuous on for 5 minutes";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="";
	};
	class overlay: device
	{
		idc=998;
		text="";
	};
	class onIndicator: overlay
	{
		idc=999;
	};
};
