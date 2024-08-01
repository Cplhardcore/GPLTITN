class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_ctrlsHolder_base;
class Rsc_gjb_itn_peq15;
class Rsc_gjb_itn_peq15_combo;
class Rsc_gjb_itn_acc_flashlight;
class Rsc_gjb_itn_m952v;
class Rsc_gjb_itn_ngal_m300_gplt: Rsc_gjb_itn_peq15_combo
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal\base_doff_co.paa";
	};
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.34765625;
		y = safeZoneY + safeZoneH * 0.51736112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.42698861;
				y = 0.66035354;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.45729164;
				y = 0.5088384;
				w = safeZoneW * 0.030625;
				h = safeZoneH * 0.04555556;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x = 0.39365528;
				y = 0.43207071;
				w = safeZoneW * 0.0275;
				h = safeZoneH * 0.03666667;
				onMouseButtonDown="['illumDiff',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDF";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x = 0.37698861;
				y = 0.80176769;
				w = safeZoneW * 0.0325;
				h = safeZoneH * 0.06666667;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRFO";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.68456437;
				y = 0.86439394;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.05666667;
				onMouseButtonDown="['fire2.5',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\M300_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\NGAL_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal_onIndicator.paa";
	};
};
class Rsc_gjb_itn_ngal_m600_gplt: Rsc_gjb_itn_ngal_m300_gplt
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\m600\base_co.paa";
	};
	class knob_modeL: device
	{
		idc=1002;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.34765625;
		y = safeZoneY + safeZoneH * 0.51736112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.42698861;
				y = 0.66035354;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.45729164;
				y = 0.5088384;
				w = safeZoneW * 0.030625;
				h = safeZoneH * 0.04555556;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x = 0.39365528;
				y = 0.43207071;
				w = safeZoneW * 0.0275;
				h = safeZoneH * 0.03666667;
				onMouseButtonDown="['illumDiff',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDF";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x = 0.37698861;
				y = 0.80176769;
				w = safeZoneW * 0.0325;
				h = safeZoneH * 0.06666667;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRFO";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x = 0.66941286;
				y = 0.3128788;
				w = safeZoneW * 0.04125;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.68456437;
				y = 0.86439394;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.05666667;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\M600_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\NGAL_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal_onIndicator.paa";
	};
};
class Rsc_gjb_itn_la5b_m300_gplt: Rsc_gjb_itn_ngal_m300_gplt
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b\base_doff_co.paa";
	};
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.34765625;
		y = safeZoneY + safeZoneH * 0.51736112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.49062498;
				y = 0.83409092;
				w = safeZoneW * 0.045;
				h = safeZoneH * 0.06888889;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.41941286;
				y = 0.72702021;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.34062498;
				y = 0.48257576;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.68456437;
				y = 0.86439394;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.05666667;
				onMouseButtonDown="['fire2.5',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\M300_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\LA5B_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\LA5B_onIndicator.paa";
	};
};
class Rsc_gjb_itn_la5b_m600_gplt: Rsc_gjb_itn_la5b_m300_gplt
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\m600\base_co.paa";
	};
	class knob_modeL: device
	{
		idc=1002;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.34765625;
		y = safeZoneY + safeZoneH * 0.51736112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.49062498;
				y = 0.83409092;
				w = safeZoneW * 0.045;
				h = safeZoneH * 0.06888889;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.41941286;
				y = 0.72702021;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.34062498;
				y = 0.48257576;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x = 0.66941286;
				y = 0.3128788;
				w = safeZoneW * 0.04125;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_deviceLA5BCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.68456437;
				y = 0.86439394;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.05666667;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_deviceLA5BCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\M600_overlay_co.paa";
	};
};
class Rsc_gjb_itn_ngal_gplt: Rsc_gjb_itn_peq15
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal\base_doff_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.36375;
		y = safeZoneY + safeZoneH * 0.48111112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.42698861;
				y = 0.66035354;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGAL";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.45729164;
				y = 0.5088384;
				w = safeZoneW * 0.030625;
				h = safeZoneH * 0.04555556;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceNGAL";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x = 0.39365528;
				y = 0.43207071;
				w = safeZoneW * 0.0275;
				h = safeZoneH * 0.03666667;
				onMouseButtonDown="['illumDiff',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseButtonUp="";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDF";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x = 0.37698861;
				y = 0.80176769;
				w = safeZoneW * 0.0325;
				h = safeZoneH * 0.06666667;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGAL";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGAL";
				tooltip="$STR_GJB_ITN_CORE_DEVIRFO";
			};
		};
	};
	class overlay: device
	{
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\NGAL_overlay_co.paa";
	};
		idc=998;
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\NGAL_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_la5b_gplt: Rsc_gjb_itn_peq15
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\la5b\base_doff_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.35375;
		y = safeZoneY + safeZoneH * 0.61222223;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.49062498;
				y = 0.83409092;
				w = safeZoneW * 0.045;
				h = safeZoneH * 0.06888889;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLA5B";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLA5B";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.41941286;
				y = 0.72702021;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceLA5B";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceLA5B";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.34062498;
				y = 0.48257576;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.06111112;
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\LA5B_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\LA5B_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_m300_gplt: Rsc_gjb_itn_acc_flashlight
{
	idd=314037;
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300\base_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\M300_overlay_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.46;
		y = safeZoneY + safeZoneH * 0.68666667;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x = 0.68456437;
				y = 0.86439394;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.05666667;
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
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\m600\base_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\M600_overlay_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.46;
		y = safeZoneY + safeZoneH * 0.68666667;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.66941286;
				y = 0.3128788;
				w = safeZoneW * 0.04125;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceM952"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceM952";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.68456437;
				y = 0.86439394;
				w = safeZoneW * 0.0375;
				h = safeZoneH * 0.05666667;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceM952";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceM952";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
};