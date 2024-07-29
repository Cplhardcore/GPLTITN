class Rsc_gjb_itn_BackPicture;
class Rsc_gjb_itn_HiddenButton;
class Rsc_gjb_itn_ctrlsHolder_base;
class Rsc_gjb_itn_autoOn_base;
class Rsc_gjb_itn_acc_flashlight;
class Rsc_gjb_itn_acc_flashlight_pistol;
class Rsc_gjb_itn_acc_dbalPl_nia: Rsc_gjb_itn_acc_flashlight
{
	idd= 314016;
	controlsBackground[]=
	{
		"device"
	};
	controls[]=
	{
		"ctrls_holder",
		//"overlay",
		"fire_menu"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_core\ui\utg\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.37890625;
		y = safeZoneY + safeZoneH * 0.61111112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button1: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x = 0.50178397;//safeZoneX + safeZoneW *0.45214844;
				y = 0.727033;//safeZoneY + safeZoneH * 0.72222223;
				w = safeZoneW * 0.02148438;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceDbalPl";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceDbalPl";
				tooltip="$STR_GJB_ITN_NIA_DBALPLVIS";
			};
			class button2: Rsc_gjb_itn_HiddenButton
			{
				idc=1102;
				x = 0.60131005;//safeZoneX + safeZoneW * 0.49316407;
				y = 0.80298236;//safeZoneY + safeZoneH * 0.76388889;
				w = safeZoneW * 0.02148438;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_deviceDbalPl";
				tooltip="$STR_GJB_ITN_NIA_DBALPLIR";
			};
		};
	};
};