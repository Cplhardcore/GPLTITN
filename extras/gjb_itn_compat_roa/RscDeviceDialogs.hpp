class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_ctrlsHolder_base;
class Rsc_gjb_itn_dbala2;
class Rsc_gjb_itn_peq15_combo;
class Rsc_gjb_itn_mawl_roa: Rsc_gjb_itn_dbala2
{
	idd=314029;
};
class Rsc_gjb_itn_ngal_roa: Rsc_gjb_itn_peq15_combo
{
	idd=314030;
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
		text="\gjb_itn\addons\gjb_itn_compat_roa\ui\ngal\base_doff_co.paa";
	};
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_compat_roa\ui\m300\base_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.3725;
		y = safeZoneY + safeZoneH * 0.46;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.44744316;//safeZoneX + safeZoneW * 0.4296875;
				y = 0.62601011;//safeZoneY + safeZoneH * 0.66666667;
				w = safeZoneW * 0.0390625;
				h = safeZoneH * 0.0625;
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
				x = 0.48058711;//safeZoneX + safeZoneW * 0.44335938;
				y = 0.47133841;//safeZoneY + safeZoneH * 0.58159723;
				w = safeZoneW * 0.02539063;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x = 0.38115528;//safeZoneX + safeZoneW * 0.40234375;
				y = 0.39873738;//safeZoneY + safeZoneH * 0.54166667;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['illumDiff',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDF";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x = 0.39299242;//safeZoneX + safeZoneW * 0.40722657;
				y = 0.77121212;//safeZoneY + safeZoneH * 0.74652778;
				w = safeZoneW * 0.03125;
				h = safeZoneH * 0.06944445;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="$STR_GJB_ITN_CORE_DEVIRFO";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.66761363;//safeZoneX + safeZoneW * 0.52050782;
				y = 0.82171718;//safeZoneY + safeZoneH * 0.77430556;
				w = safeZoneW * 0.03125;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['fire2.5',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
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
		text="\gjb_itn\addons\gjb_itn_compat_roa\ui\ngal_onIndicator_co.paa";
	};
};