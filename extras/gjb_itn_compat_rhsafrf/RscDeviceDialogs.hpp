class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_ctrlsHolder_base;
class Rsc_gjb_itn_dbala2;
class Rsc_gjb_itn_acc_flashlight;
class Rsc_gjb_itn_acc_flashlight_pistol;
class Rsc_gjb_itn_perst1_rhs: Rsc_gjb_itn_acc_flashlight
{
	idd=314012;
	controlsBackground[]=
	{
		"device"
	};
	controls[]=
	{
		"overlay",
		"onIndicator",
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst1\base_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\Perst1_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\Perst1_onIndicator_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.39648438;
		y = safeZoneY + safeZoneH * 0.47743056;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x = 0.51600199;//safeZoneX + safeZoneW * 0.45800782;
				y = 0.48652666;//safeZoneY + safeZoneH * 0.59027778;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
};
class Rsc_gjb_itn_klesh2_rhs: Rsc_gjb_itn_acc_flashlight
{
	idd=314013;
	controlsBackground[]=
	{
		"device"
	};
	controls[]=
	{
		"overlay",
		"fire_menu",/*
		"button_on"*/
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\klesh2\base_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\Klesh2_overlay_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.48535157;
		y = safeZoneY + safeZoneH * 0.61284723;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x = 0.75296881;//safeZoneX + safeZoneW * 0.55566407;
				y = 0.73336211;//safeZoneY + safeZoneH * 0.72569445;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
};
class Rsc_gjb_perst3_rhs: Rsc_gjb_itn_dbala2
{
	idd=314014;
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
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst3\base_doff_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\OFF_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.37695313;
		y = safeZoneY + safeZoneH * 0.50347223;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.63211573;//safeZoneX + safeZoneW * 0.50585938;
				y = 0.58779249;//safeZoneY + safeZoneH * 0.64583334;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.09027778;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_devicePerst3"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_devicePerst3";
				tooltip="Activation Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on1: button_mode
			{
				idc=1101;
				x = 0.48282662;//safeZoneX + safeZoneW * 0.44433594;
				y = 0.53715958;//safeZoneY + safeZoneH *0.61805556;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_devicePerst3";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_devicePerst3";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for on";
			};
			class button_on2: button_on1
			{
				idc=1102;
				x = 0.40699724;//safeZoneX + safeZoneW * 0.41308594;
				y = 0.71121021;//safeZoneY + safeZoneH * 0.71354167;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.04861112;
			};
			class button_pwr: button_mode
			{
				idc=1105;
				x = 0.35723421;//safeZoneX + safeZoneW * 0.39257813;
				y = 0.51184312;//safeZoneY + safeZoneH * 0.60416667;
				w = safeZoneW * 0.02539063;
				h = safeZoneH * 0.09027778;
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePerst3";
				onMouseZChanged="";
				tooltip="Power Level Select: Left-click for higher power, Right-click for lower power";
			};
			class button_illumFocus: button_pwr
			{
				idc=1110;
				x = 0.38093088;//safeZoneX + safeZoneW * 0.40234375;
				y = 0.08779248;//safeZoneY + safeZoneH * 0.37152778;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePerst3";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePerst3";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePerst3";
				tooltip="Adjust Illuminator Focus: Left-click to narrow, Right-click to widen, or scroll with Mouse-wheel, Hold to toggle diffusor cap";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\Perst3_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\Perst3_onIndicator_co.paa";
	};
};
class Rsc_gjb_perst3_combo_rhs: Rsc_gjb_perst3_rhs
{
	idd=314015;
	controlsBackground[]=
	{
		"device",
		"deviceL",
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
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\perst3\base_doff_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
		text="";
	};
	class deviceL: device
	{
		idc=1002;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\klesh2\base_co.paa";
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_rhsafrf\ui\Klesh2_overlay_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.37695313;
		y = safeZoneY + safeZoneH * 0.50347223;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.63211573;//safeZoneX + safeZoneW * 0.50585938;
				y = 0.58779249;//safeZoneY + safeZoneH * 0.64583334;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.09027778;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_devicePerst3Combo"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_devicePerst3Combo";
				tooltip="Activation Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on1: button_mode
			{
				idc=1101;
				x = 0.48282662;//safeZoneX + safeZoneW * 0.44433594;
				y = 0.53715958;//safeZoneY + safeZoneH *0.61805556;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_devicePerst3Combo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_devicePerst3Combo";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for on";
			};
			class button_on2: button_on1
			{
				idc=1102;
				x = 0.40699724;//safeZoneX + safeZoneW * 0.41308594;
				y = 0.71121021;//safeZoneY + safeZoneH * 0.71354167;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.04861112;
			};
			class button_pwr: button_mode
			{
				idc=1105;
				x = 0.35723421;//safeZoneX + safeZoneW * 0.39257813;
				y = 0.51184312;//safeZoneY + safeZoneH * 0.60416667;
				w = safeZoneW * 0.02539063;
				h = safeZoneH * 0.09027778;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePerst3Combo";
				onMouseZChanged="";
				tooltip="Power Level Select: Left-click for higher power, Right-click for lower power";
			};
			class button_illumFocus: button_pwr
			{
				idc=1110;
				x = 0.38093088;//safeZoneX + safeZoneW * 0.40234375;
				y = 0.08779248;//safeZoneY + safeZoneH * 0.37152778;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePerst3Combo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePerst3Combo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePerst3Combo";
				tooltip="Adjust Illuminator Focus: Left-click to narrow, Right-click to widen, or scroll with Mouse-wheel, Hold to toggle diffusor cap";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.75296881;//safeZoneX + safeZoneW * 0.55566407;
				y = 0.73336211;//safeZoneY + safeZoneH * 0.72569445;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_devicePerst3Combo";
				onMouseZChanged="";
				tooltip="Activation Switch: Click for continuous on";
			};
		};
	};
};