class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_ctrlsHolder_base;
class RscCombo;
class Rsc_gjb_itn_dbala2;
class Rsc_gjb_itn_peq15_combo;
class Rsc_gjb_itn_ngal_avalon: Rsc_gjb_itn_peq15_combo
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
		//text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal\base_doff_co.paa";
	};
	class deviceL: device
	{
		idc=1003;
		//text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\m300\base_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		type= 4;
		idc=1050;
		style = 0;
		font = "PuristaMedium";
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = safeZoneX + safeZoneW * 0.4296875;
				y = safeZoneY + safeZoneH * 0.66666667;
				w = safeZoneW * 0.0390625;
				h = safeZoneH * 0.0625;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="Activation Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = safeZoneX + safeZoneW * 0.44335938;
				y = safeZoneY + safeZoneH * 0.58159723;
				w = safeZoneW * 0.02539063;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for continuous on for 5 minutes";
			};
			class button_illumDiffuse: button_mode
			{
				idc=1111;
				x = safeZoneX + safeZoneW * 0.40234375;
				y = safeZoneY + safeZoneH * 0.54166667;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";	//set up still
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";	//set up still
				onMouseZChanged="";
				tooltip="Toggle diffusor cap: Left-click";
			};
			class button_illumFocus: button_mode
			{
				idc=1112;
				x = safeZoneX + safeZoneW * 0.40722657;
				y = safeZoneY + safeZoneH * 0.74652778;
				w = safeZoneW * 0.03125;
				h = safeZoneH * 0.06944445;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceNGALCombo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceNGALCombo";
				tooltip="Adjust Illuminator Focus: Left-click to narrow, Right-click to widen, or scroll with Mouse-wheel";	//remove diffusor toggle from this control
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = safeZoneX + safeZoneW * 0.52050782;
				y = safeZoneY + safeZoneH * 0.77430556;
				w = safeZoneW * 0.03125;
				h = safeZoneH * 0.05555556;
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
		//text="\gjb_itn\addons\gjb_itn_compat_gplt\ui\ngal_onIndicator.paa";
	};
};