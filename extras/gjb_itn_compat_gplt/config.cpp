class CfgPatches
{
	class gjb_itn_compat_t1
	{
		units[]={};
		weapons[]={};
		requiredAddons[]=
		{
			"gjb_itn_core"
		};
		name="Illuminate The Night - Tier One Weapons";
		authors="GhostJB";
	};
};
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
						"la_5b",
						"Rsc_gjb_itn_la5b_gplt",
						"\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b"
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
				};
				class GPLT_sidefoster_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.140517,0.022622,-0.00231253},
						{-0.140517,0.022622,-0.00231253},
						{-0.163857,0.000499235,0.0358282}
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
				};
				class Louetta_sidefsp2_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00316963,0.0228322,-0.00252764},
						{-0.00316963,0.0228322,-0.00252764},
						{-0.147873,-0.000896983,0.036923}
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
				};
				class GPLT_sidehotch_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.142712,0.0227977,-0.0026075},
						{-0.142712,0.0227977,-0.0026075},
						{-0.142149,0.09436,0.036764}
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
				};
				class GPLT_sidescar_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.013767,-0.0273162,-0.00982422},
						{-0.013767,-0.0273162,-0.00982422},
						{-0.0326958,0.0449866,0.046257}
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
				};
				class GPLT_sidetim3_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0161455,0.0294905,-0.00841968},
						{-0.0161455,0.0294905,-0.00841968},
						{-0.0370695,0.000982035,0.0350474}
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
				};
				class GPLT_sideurgi2_LASER: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0168677,0.0220702,-0.00206376},
						{-0.0168677,0.0220702,-0.00206376},
						{-0.0584723,0.091493,0.0367756}
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
				};
				class GPLT_sideurgi4_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0794153,0.029007,0.00108599},
						{0.0794153,0.029007,0.00108599},
						{-0.0385695,0.0138974,0.0166917}
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
				};
				class GPLT_sideurgi6_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0367541,0.0293591,0.00114851},
						{-0.0367541,0.0293591,0.00114851},
						{-0.0584723,-0.00133179,0.0367756}
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
				};
				class GPLT_sideurgi9_LASER: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0100276,0.0295701,0.001244},
						{0.0100276,0.0295701,0.001244},
						{-0.012445,0.00122349,0.0361895}
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
				};
				class GPLT_sidesass_p_LASER: deviceBase_la5b
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0489236,-0.0343846,0.0512323},
						{-0.0489236,-0.0343846,0.0512323},
						{0,0,0}
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
				};
	};
};
class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_ctrlsHolder_base;
class Rsc_gjb_itn_peq15;
class Rsc_gjb_itn_peq15_combo;
class Rsc_gjb_itn_acc_flashlight;
class Rsc_gjb_itn_m952v;
class Rsc_gjb_itn_ngal_m300_t1: Rsc_gjb_itn_peq15_combo
{
	idd=314035;
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
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal\base_doff_co.paa";
	};
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\m300\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.34765625";
		y="safeZoneY + safeZoneH * 0.51736112";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x=0.4269886;
				y=0.66035354;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x=0.45729163;
				y=0.50883842;
				w="safeZoneW * 0.030625";
				h="safeZoneH * 0.04555556";
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x=0.39365527;
				y=0.4320707;
				w="safeZoneW * 0.0275";
				h="safeZoneH * 0.03666667";
				onMouseButtonDown="['illumDiff',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDF";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x=0.37698862;
				y=0.80176771;
				w="safeZoneW * 0.0325";
				h="safeZoneH * 0.06666667";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRFO";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x=0.68456435;
				y=0.86439395;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.05666667";
				onMouseButtonDown="['fire2.5',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\M300_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\NGAL_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal_onIndicator.paa";
	};
};
class Rsc_gjb_itn_ngal_m600_t1: Rsc_gjb_itn_ngal_m300_t1
{
	idd=314036;
	controlsBackground[]=
	{
		"deviceL",
		"knob_modeL",
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
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\m600\base_co.paa";
	};
	class knob_modeL: device
	{
		idc=1002;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.34765625";
		y="safeZoneY + safeZoneH * 0.51736112";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x=0.4269886;
				y=0.66035354;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x=0.45729163;
				y=0.50883842;
				w="safeZoneW * 0.030625";
				h="safeZoneH * 0.04555556";
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x=0.39365527;
				y=0.4320707;
				w="safeZoneW * 0.0275";
				h="safeZoneH * 0.03666667";
				onMouseButtonDown="['illumDiff',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDF";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x=0.37698862;
				y=0.80176771;
				w="safeZoneW * 0.0325";
				h="safeZoneH * 0.06666667";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRFO";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x=0.66941285;
				y=0.31287879;
				w="safeZoneW * 0.04125";
				h="safeZoneH * 0.05555556";
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x=0.68456435;
				y=0.86439395;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.05666667";
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\M600_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\NGAL_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal_onIndicator.paa";
	};
};
class Rsc_gjb_itn_la5b_m300_t1: Rsc_gjb_itn_ngal_m300_t1
{
	idd=314032;
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
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\la5b\base_doff_co.paa";
	};
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\m300\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.34765625";
		y="safeZoneY + safeZoneH * 0.51736112";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x=0.49062499;
				y=0.83409095;
				w="safeZoneW * 0.045";
				h="safeZoneH * 0.06888889";
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x=0.41941285;
				y=0.7270202;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x=0.34062499;
				y=0.48257577;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x=0.68456435;
				y=0.86439395;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.05666667";
				onMouseButtonDown="['fire2.5',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\M300_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\LA5B_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\LA5B_onIndicator.paa";
	};
};
class Rsc_gjb_itn_la5b_m600_t1: Rsc_gjb_itn_la5b_m300_t1
{
	idd=314033;
	controlsBackground[]=
	{
		"deviceL",
		"knob_modeL",
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
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\m600\base_co.paa";
	};
	class knob_modeL: device
	{
		idc=1002;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.34765625";
		y="safeZoneY + safeZoneH * 0.51736112";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x=0.49062499;
				y=0.83409095;
				w="safeZoneW * 0.045";
				h="safeZoneH * 0.06888889";
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x=0.41941285;
				y=0.7270202;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x=0.34062499;
				y=0.48257577;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x=0.66941285;
				y=0.31287879;
				w="safeZoneW * 0.04125";
				h="safeZoneH * 0.05555556";
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x=0.68456435;
				y=0.86439395;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.05666667";
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\M600_overlay_co.paa";
	};
};
class Rsc_gjb_itn_ngal_t1: Rsc_gjb_itn_peq15
{
	idd=314034;
	controlsBackground[]=
	{
		"device",
		"knob_mode"
	};
	controls[]=
	{
		"onIndicator",
		"overlay",
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal\base_doff_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.36375";
		y="safeZoneY + safeZoneH * 0.48111112";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x=0.4269886;
				y=0.66035354;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGAL";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x=0.45729163;
				y=0.50883842;
				w="safeZoneW * 0.030625";
				h="safeZoneH * 0.04555556";
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceNGAL";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x=0.39365527;
				y=0.4320707;
				w="safeZoneW * 0.0275";
				h="safeZoneH * 0.03666667";
				onMouseButtonDown="['illumDiff',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseButtonUp="";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDF";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x=0.37698862;
				y=0.80176771;
				w="safeZoneW * 0.0325";
				h="safeZoneH * 0.06666667";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGAL";
				tooltip="$STR_GJB_ITN_CORE_DEVIRFO";
			};
		};
	};
	class overlay: device
	{
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\NGAL_overlay_co.paa";
	};
	idc=998;
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\NGAL_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_la5b_t1: Rsc_gjb_itn_peq15
{
	idd=314031;
	controlsBackground[]=
	{
		"device",
		"knob_mode"
	};
	controls[]=
	{
		"onIndicator",
		"overlay",
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\la5b\base_doff_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.35375";
		y="safeZoneY + safeZoneH * 0.61222223";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x=0.49062499;
				y=0.83409095;
				w="safeZoneW * 0.045";
				h="safeZoneH * 0.06888889";
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLA5B";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLA5B";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x=0.41941285;
				y=0.7270202;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceLA5B";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceLA5B";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x=0.34062499;
				y=0.48257577;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.06111112";
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceLA5B";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceLA5B";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceLA5B";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\LA5B_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\LA5B_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_m300_t1: Rsc_gjb_itn_acc_flashlight
{
	idd=314037;
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\m300\base_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\M300_overlay_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.46";
		y="safeZoneY + safeZoneH * 0.68666667";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x=0.68456435;
				y=0.86439395;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.05666667";
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
};
class Rsc_gjb_itn_m600_ti: Rsc_gjb_itn_m952v
{
	idd=314038;
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\m600\base_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_t1\ui\M600_overlay_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x="safeZoneX + safeZoneW * 0.46";
		y="safeZoneY + safeZoneH * 0.68666667";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x=0.66941285;
				y=0.31287879;
				w="safeZoneW * 0.04125";
				h="safeZoneH * 0.05555556";
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceM952";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceM952";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_on: button_mode
			{
				idc=1101;
				x=0.68456435;
				y=0.86439395;
				w="safeZoneW * 0.0375";
				h="safeZoneH * 0.05666667";
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceM952";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceM952";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
};
