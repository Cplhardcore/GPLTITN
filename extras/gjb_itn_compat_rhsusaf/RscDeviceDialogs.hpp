class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_ctrlsHolder_base;
class Rsc_gjb_itn_dbala2;
class Rsc_gjb_itn_acc_flashlight;
class Rsc_gjb_itn_acc_flashlight_pistol;
class Rsc_gjb_itn_peq15;
class Rsc_gjb_itn_peq15_combo;
class Rsc_gjb_itn_m952v;
class Rsc_gjb_itn_peq15_combo_rhs_wmx: Rsc_gjb_itn_peq15_combo
{
	idd=314007;
	class device;
	class button_mode;
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.45529573;//safeZoneX + safeZoneW * 0.43261719;
				y = 0.68531883;//safeZoneY + safeZoneH * 0.69965278;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.0625;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_devicePeq15Combo";
				tooltip="Activation Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.4102767;//safeZoneX + safeZoneW * 0.4140625;
				y = 0.5620961;//safeZoneY + safeZoneH * 0.63194445;
				w = safeZoneW * 0.0390625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for continuous on for 5 minutes";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.35104117;//safeZoneX + safeZoneW * 0.38964844;
				y = 0.34092705;//safeZoneY + safeZoneH * 0.51041667;
				w = safeZoneW * 0.02832032;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePeq15Combo";
				tooltip="Adjust Illuminator Focus: Left-click to narrow, Right-click to widen, or scroll with Mouse-wheel, Hold to toggle diffusor cap";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x = 0.63448539;//safeZoneX + safeZoneW * 0.50683594;
				y = 0.3884254;//safeZoneY + safeZoneH * 0.53645834;
				w = safeZoneW * 0.05957032;
				h = safeZoneH * 0.07638889;
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_devicePeq15Combo";
				tooltip="Laser Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.65818208;//safeZoneX + safeZoneW * 0.51660157;
				y = 0.97070388;//safeZoneY + safeZoneH * 0.85590278;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for continuous on for 5 minutes";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\WMX_overlay_co.paa";
	};
};
class Rsc_gjb_itn_peq16_rhs: Rsc_gjb_itn_peq15
{
	idd=314008;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.34707969;
		y = safeZoneY + safeZoneH * 0.51909723;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.40462757;//safeZoneX + safeZoneW * 0.41210938;
				y = 0.43905832;//safeZoneY + safeZoneH * 0.56423612;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePeq16"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_devicePeq16";
				tooltip="Device Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.4093669;//safeZoneX + safeZoneW * 0.4140625;
				y = 0.56247603;//safeZoneY + safeZoneH * 0.63194445;
				w = safeZoneW * 0.02832032;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_devicePeq16";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_devicePeq16";
				onMouseZChanged="";
				tooltip="Momentary Activation Switch: Click for continuous on for 5 minutes";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.32405884;//safeZoneX + safeZoneW * 0.37890625;
				y = 0.33462793;//safeZoneY + safeZoneH * 0.50694445;
				w = safeZoneW * 0.04882813;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePeq16";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePeq16";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePeq16";
				tooltip="Adjust Illuminator Focus: Left-click to narrow, Right-click to widen, or scroll with Mouse-wheel, Hold to toggle diffusor cap";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\PEQ16_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\PEQ16_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_wmx_rhs: Rsc_gjb_itn_m952v
{
	idd=314010;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.45507813;
		y = safeZoneY + safeZoneH * 0.76215278;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.63448539;//safeZoneX + safeZoneW * 0.50683594;
				y = 0.3884254;//safeZoneY + safeZoneH * 0.53645834;
				w = safeZoneW * 0.05957032;
				h = safeZoneH * 0.07638889;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceM952"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceM952";
				tooltip="Device Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.65818208;//safeZoneX + safeZoneW * 0.51660157;
				y = 0.97070389;//safeZoneY + safeZoneH * 0.85590278;
				w = safeZoneW * 0.04589844;
				h = safeZoneH *0.0625;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceM952";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceM952";
				onMouseZChanged="";
				tooltip="Tailcap Power Button: Left-Click to toggle power";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\WMX_overlay_co.paa";
	};
};
