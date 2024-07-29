class RscStatic;
class RscEdit;
class RscText;
class RscButton;
class RscButtonMenu;
class RscListBox;
class RscCombo;
class RscControlsGroup;
class Rsc_gjb_itn_BackPicture
{
	type=0;
	idc=-1;
	x = safeZoneX + safeZoneW * 0.24511719;
	y = safeZoneY + safeZoneH * 0.32291667;
	w = safeZoneW * 0.50976563;
	h = safeZoneH * 0.79166667;
	style=48+2048;
	text="";
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	font="PuristaMedium";
	sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
};
class Rsc_gjb_itn_HiddenButton
{
	type=1;
	idc=-1;
	text="";
	x=0;
	y=0;
	w=0.1;
	h=0.1;
	style=2;
	colorText[]={0,0,0,1};
	colorDisabled[]={0,0,0,0};
	colorBackground[]={0,0,0,0};
	colorBackgroundDisabled[]={0,0,0,0};
	colorBackgroundActive[]={0,0,0,0};
	colorFocused[]={0,0,0,0};
	colorShadow[]={0,0,0,0};
	colorBorder[]={0,0,0,0};
	shadow=2;
	font="PuristaMedium";
	sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
	offsetX=0.1;
	offsetY=0.1;
	offsetPressedX=0.1;
	offsetPressedY=0.1;
	borderSize=0;
	soundEnter[]={"\A3\ui_f\data\sound\RscButton\soundEnter",0.0001,1};
	soundPush[]= {"\A3\ui_f\data\sound\RscButton\soundPush",0.0001,1};
	soundClick[]={"\A3\ui_f\data\sound\RscButton\soundClick",0.0001,1};
	soundEscape[]={"\A3\ui_f\data\sound\RscButton\soundEscape",0.0001,1};
};
class Rsc_gjb_itn_ShownButton: RscButton
{
	type = 41;
	idc = -1;
	text="";
	x=0;
	y=0;
	w=0.1;
	h=0.1;
	style = 2+12;
	blinkingPeriod = 0;
	color[] = {
			"(profileNamespace getVariable ['igui_text_rgb_r',0.13])",
			"(profileNamespace getVariable ['igui_text_rgb_g',0.54])",
			"(profileNamespace getVariable ['igui_text_rgb_b',0.21])",
			"(profileNamespace getVariable ['igui_text_rgb_a',0.8])"
	};
	colorActive[] = {
			"(profileNamespace getVariable ['igui_text_rgb_r',0.13])",
			"(profileNamespace getVariable ['igui_text_rgb_g',0.54])",
			"(profileNamespace getVariable ['igui_text_rgb_b',0.21])",
			"(profileNamespace getVariable ['igui_text_rgb_a',0.8])"
	};
	colorActive2[] = {
			"(profileNamespace getVariable ['igui_text_rgb_r',0.13])",
			"(profileNamespace getVariable ['igui_text_rgb_g',0.54])",
			"(profileNamespace getVariable ['igui_text_rgb_b',0.21])",
			"(profileNamespace getVariable ['igui_text_rgb_a',0.8])"
	};
	colorBackgroundActive[]= {
			"(profileNamespace getVariable ['igui_bcg_rgb_r',0.13])",
			"(profileNamespace getVariable ['igui_bcg_rgb_g',0.54])",
			"(profileNamespace getVariable ['igui_bcg_rgb_b',0.21])",
			"(profileNamespace getVariable ['igui_bcg_rgb_a',0.8])"
	};
	colorActiveBackground[] = {
			"(profileNamespace getVariable ['igui_bcg_rgb_r',0.13])",
			"(profileNamespace getVariable ['igui_bcg_rgb_g',0.54])",
			"(profileNamespace getVariable ['igui_bcg_rgb_b',0.21])",
			"(profileNamespace getVariable ['igui_bcg_rgb_a',0.8])"
	};
	colorActiveBackground2[] = {
			"(profileNamespace getVariable ['igui_bcg_rgb_r',0.13])",
			"(profileNamespace getVariable ['igui_bcg_rgb_g',0.54])",
			"(profileNamespace getVariable ['igui_bcg_rgb_b',0.21])",
			"(profileNamespace getVariable ['igui_bcg_rgb_a',0.8])"
	};
	colorFocused[] = {
			"(profileNamespace getVariable ['igui_bcg_rgb_r',0.13])",
			"(profileNamespace getVariable ['igui_bcg_rgb_g',0.54])",
			"(profileNamespace getVariable ['igui_bcg_rgb_b',0.21])",
			"(profileNamespace getVariable ['igui_bcg_rgb_a',0.8])"
	};
	font = "PuristaMedium";
	size = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2); // ... *1
	sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2); // ...*1
	soundEnter[]={"\A3\ui_f\data\sound\RscButton\soundEnter",0.0001,1};
	soundPush[]= {"\A3\ui_f\data\sound\RscButton\soundPush",0.0001,1};
	soundClick[]={"\A3\ui_f\data\sound\RscButton\soundClick",0.0001,1};
	soundEscape[]={"\A3\ui_f\data\sound\RscButton\soundEscape",0.0001,1};
};
class Rsc_gjb_itn_HiddenRotator;
class Rsc_gjb_itn_HiddenFlip;
//Generic Interface
class Rsc_gjb_itn_generic_deviceclass
{
	idd=314000;
	movingEnable=1;
	enableSimulation=1;
	onLoad="";
	onUnload="";
	controlsBackground[]=
	{
		"container",
		"modes"
	};
	controls[]=
	{
		"button_prev",
		"button_next",
		"button_on",
		"graphic_prev",
		"graphic_next",
		"graphic_on",
		"button_illumW",
		"button_illumT",
		"button_illumDiff",
		"graphic_illumW",
		"graphic_illumT",
		"graphic_illumDiff"
	};
	class container: RscStatic
	{
		type = 0;
		idc = -1;
		x = safeZoneX + safeZoneW * 0.34277344;
		y = safeZoneY + safeZoneH * 0.36111112;
		w = safeZoneW * 0.31445313;
		h = safeZoneH * 0.4375;
		style = 0;
		text = "";
		colorBackground[]={0,0,0,0.69999999};
		colorText[] = {0.0902,0.6902,0.698,1};
		font = "PuristaMedium";
		sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
	};
	class modes: RscListBox
	{
		type = 5;
		idc = 1000;
		x = safeZoneX + safeZoneW * 0.3671875;
		y = safeZoneY + safeZoneH * 0.46875;
		w = safeZoneW * 0.14355469;
		h = safeZoneH * 0.29513889;
		style = 0;
		font = "PuristaMedium";
		size = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		onLBSelChanged = "['list',_this #1,'k'] call gjb_itn_fnc_deviceGeneric;";
	};

	class button_prev: Rsc_gjb_itn_ShownButton
	{
		idc = 977;
		x = safeZoneX + safeZoneW * 0.3671875;
		y = safeZoneY + safeZoneH * 0.39583334;
		w = safeZoneW * 0.0703125;
		h = safeZoneH * 0.03819445;
		onMouseButtonDown="['mode',1.1,'k'] call gjb_itn_fnc_deviceGeneric;";
	};
	class graphic_prev: Rsc_gjb_itn_BackPicture
	{
		idc = 987;
		x = safeZoneX + safeZoneW * 0.3671875;
		y = safeZoneY + safeZoneH * 0.39583334;
		w = safeZoneW * 0.0703125;
		h = safeZoneH * 0.03819445;
		style=48+2048;
		text = "\gjb_itn\addons\gjb_itn_core\ui\genericPrev.paa";
	};
	class button_next: Rsc_gjb_itn_ShownButton
	{
		idc = 978;
		x = safeZoneX + safeZoneW * 0.44042969;
		y = safeZoneY + safeZoneH * 0.39583334;
		w = safeZoneW * 0.0703125;
		h = safeZoneH * 0.03819445;
		onMouseButtonDown="['mode',0.1,'k'] call gjb_itn_fnc_deviceGeneric;";
	};
	class graphic_next: Rsc_gjb_itn_BackPicture
	{
		idc = 988;
		x = safeZoneX + safeZoneW * 0.44042969;
		y = safeZoneY + safeZoneH * 0.39583334;
		w = safeZoneW * 0.0703125;
		h = safeZoneH * 0.03819445;
		style=48+2048;
		text = "\gjb_itn\addons\gjb_itn_core\ui\genericNext.paa";
	};
	class button_on: Rsc_gjb_itn_ShownButton
	{
		idc = 979;
		x = safeZoneX + safeZoneW * 0.53808594;
		y = safeZoneY + safeZoneH * 0.54166667;
		w = safeZoneW * 0.09472657;
		h = safeZoneH * 0.0625;
		onMouseButtonDown="['fire',0,'k'] call gjb_itn_fnc_deviceGeneric;";
	};
	class graphic_on: Rsc_gjb_itn_BackPicture
	{
		idc = 989;
		x = safeZoneX + safeZoneW * 0.53808594;
		y = safeZoneY + safeZoneH * 0.54166667;
		w = safeZoneW * 0.09472657;
		h = safeZoneH * 0.0625;
		style=48+2048;
		text = "\gjb_itn\addons\gjb_itn_core\ui\genericFire.paa";
	};
	class button_illumW: Rsc_gjb_itn_HiddenButton
	{
		idc = -1;
		x = safeZoneX + safeZoneW * 0.53808594;
		y = safeZoneY + safeZoneH * 0.6875;
		w = safeZoneW * 0.04589844;
		h = safeZoneH * 0.0625;
		colorText[]={0,0,0,1};
		colorDisabled[]={0,0,0,0};
		colorBackground[]={0,0,0,0};
		colorBackgroundDisabled[]={0,0,0,0};
		colorBackgroundActive[]={0,0,0,0};
		colorFocused[]={0,0,0,0};
		colorShadow[]={0,0,0,0};
		colorBorder[]={0,0,0,0};
		text = "";
		onMouseButtonDown="['illum',0,'k'] call gjb_itn_fnc_deviceGeneric;";
	};
	class graphic_illumW: Rsc_gjb_itn_BackPicture
	{
		idc = 1001;
		x = safeZoneX + safeZoneW * 0.53808594;
		y = safeZoneY + safeZoneH * 0.6875;
		w = safeZoneW * 0.04589844;
		h = safeZoneH * 0.0625;
		style=48+2048;
		text="\gjb_itn\addons\gjb_itn_core\ui\wiFoc_ca.paa";
	};
	class button_illumT: button_illumW
	{
		idc = -1;
		x = safeZoneX + safeZoneW * 0.58691407;
		y = safeZoneY + safeZoneH * 0.6875;
		w = safeZoneW * 0.04589844;
		h = safeZoneH * 0.0625;
		text = "";
		onMouseButtonDown="['illum',1,'k'] call gjb_itn_fnc_deviceGeneric;";
	};
	class graphic_illumT: Rsc_gjb_itn_BackPicture
	{
		idc = 1002;
		x = safeZoneX + safeZoneW * 0.58691407;
		y = safeZoneY + safeZoneH * 0.6875;
		w = safeZoneW * 0.04589844;
		h = safeZoneH * 0.0625;
		style=48+2048;
		text="\gjb_itn\addons\gjb_itn_core\ui\naFoc_ca.paa";
	};
	class button_illumDiff: button_illumW
	{
		idc = -1;
		x = safeZoneX + safeZoneW * 0.5625;
		y = safeZoneY + safeZoneH * 0.61458334;
		w = safeZoneW * 0.04589844;
		h = safeZoneH * 0.0625;
		text = "";
		onMouseButtonDown="['illum',2,'k'] call gjb_itn_fnc_deviceGeneric;";
	};
	class graphic_illumDiff: Rsc_gjb_itn_BackPicture
	{
		idc = 1003;
		x = safeZoneX + safeZoneW * 0.5625;
		y = safeZoneY + safeZoneH * 0.61458334;
		w = safeZoneW * 0.04589844;
		h = safeZoneH * 0.0625;
		style=48+2048;
		text="\gjb_itn\addons\gjb_itn_core\ui\enDif_ca.paa";
	};
};
//Zeus Interface
class Rsc_gjb_itn_zm_interface
{
	idd=314001;
};
//Control group bases
class Rsc_gjb_itn_ctrlsHolder_base: RscControlsGroup
{
	type=15;
	idc=-1;
	x = safeZoneX + safeZoneW * 0.24511719;
	y = safeZoneY + safeZoneH * 0.32291667;
	w = safeZoneW * 0.50976563;
	h = safeZoneH * 0.79166667;
	style = 16;
	class Controls
	{};
};
class Rsc_gjb_itn_autoOn_base: RscControlsGroup
{
	type=15;
	idc=-1;
	w = safeZoneW * 0.17089844;
	h = safeZoneH * 0.22916667;
	style = 16;
	class Controls
	{
		class menu_0: Rsc_gjb_itn_BackPicture
		{
			idc=1051;
			x = 0;
			y =  0;
			w = safeZoneW * 0.17089844;
			h = safeZoneH * 0.22916667;
			style=48+2048;
			text="\gjb_itn\addons\gjb_itn_core\ui\autoOn\iconsBack0.paa";
		};
		class menu_1: menu_0
		{
			idc=1052;
			text="\gjb_itn\addons\gjb_itn_core\ui\autoOn\iconsBack1.paa";
		};
		class menu_2: menu_0
		{
			idc=1053;
			text="\gjb_itn\addons\gjb_itn_core\ui\autoOn\iconsBack2.paa";
		};
		class menu_3: menu_0
		{
			idc=1054;
			text="\gjb_itn\addons\gjb_itn_core\ui\autoOn\iconsBack3.paa";
		};
		class menu_4: menu_0
		{
			idc=1055;
			text="\gjb_itn\addons\gjb_itn_core\ui\autoOn\iconsBack4.paa";
		};
		class menu_icons: menu_0
		{
			idc=-1;
			text="\gjb_itn\addons\gjb_itn_core\ui\autoOn\iconsGUI.paa";
		};
		class button_t0: Rsc_gjb_itn_HiddenButton
		{
			idc=-1;
			x = 0.16035356;
			y = 0.29629632;
			w = safeZoneW * 0.0375;
			h = safeZoneH * 0.06388889;
			onMouseEnter="[0] call gjb_itn_fnc_autoPwr";
		};
		class button_t0a: button_t0
		{
			x = 0.12373739;
			y = 0.32323233;
			w = safeZoneW * 0.06822917;
			h = safeZoneH * 0.04444445;
		};
		class button_t1: button_t0
		{
			x = 0.05555557;
			y = 0.20538722;
			h = safeZoneH * 0.05833334;
			onMouseEnter="[1] call gjb_itn_fnc_autoPwr";
		};
		class button_t1a: button_t1
		{
			x = 0.11111113;
			y = 0.23400675;
			w = safeZoneW * 0.02604167;
			h = safeZoneH * 0.03148149;
		};
		class button_t1b: button_t1
		{
			x = 0.06060607;
			y = 0.16666668;
			w = safeZoneW * 0.0171875;
			h = safeZoneH * 0.10277778;
		};
		class button_t2: button_t0
		{
			x = 0.10921715;
			y = 0.08080806;
			onMouseEnter="[2] call gjb_itn_fnc_autoPwr";
		};
		class button_t2a: button_t2
		{
			x = 0.0823233;
			y = 0.10900677;
			w = safeZoneW * 0.02604167;
			h = safeZoneH * 0.03148149;
		};
		class button_t2b: button_t2
		{
			x = 0.15909091;
			y = 0.04040406;
			w = safeZoneW * 0.0171875;
			h = safeZoneH * 0.10277778;
		};
		class button_t3: button_t0
		{
			x = 0.21212122;
			y = 0.08080806;
			onMouseEnter="[3] call gjb_itn_fnc_autoPwr";
		};
		class button_t3a: button_t3
		{
			x = 0.24212122;
			y = 0.10900677;
			w = safeZoneW * 0.02604167;
			h = safeZoneH * 0.03148149;
		};
		class button_t3b: button_t3
		{
			x = 0.20833334;
			y = 0.04040406;
			w = safeZoneW * 0.0171875;
			h = safeZoneH * 0.10277778;
		};
		class button_t4: button_t0
		{
			x = 0.26237376;
			y = 0.19570705;
			h = safeZoneH * 0.05833334;
			onMouseEnter="[4] call gjb_itn_fnc_autoPwr";
		};
		class button_t4a: button_t4
		{
			x = 0.23232326;
			y = 0.23400675;
			w = safeZoneW * 0.02604167;
			h = safeZoneH * 0.03148149;
		};
		class button_t4b: button_t4
		{
			x = 0.3156566;
			y = 0.16666668;
			w = safeZoneW * 0.0171875;
			h = safeZoneH * 0.10277778;
		};
	};
};
//DBAL-A2
class Rsc_gjb_itn_dbala2
{
	idd=314002;
	movingEnable=1;
	enableSimulation=1;
	onLoad="";
	onUnload="";
	controlsBackground[]=
	{
		"device",
		"knob_pwr",
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
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\base_doff_co.paa";
	};
	class knob_pwr: device
	{
		idc=1001;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\OFF_co.paa";
	};
	class knob_mode: knob_pwr
	{
		idc=1002;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\OL_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.37890625;
		y = safeZoneY + safeZoneH * 0.48611112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_pwr: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.47348484;//safeZoneX + safeZoneW * 0.44042969;
				y = 0.71022728;//safeZoneY + safeZoneH * 0.71354167;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceDbalA2";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceDbalA2";
				tooltip="$STR_GJB_ITN_CORE_DBALACT";
			};
			class button_mode: button_pwr
			{
				idc=1101;
				x = 0.59185607;//safeZoneX + safeZoneW * 0.48925782;
				y = 0.71022728;//safeZoneY + safeZoneH * 0.71354167;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_deviceDbalA2"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_deviceDbalA2";
				tooltip="$STR_GJB_ITN_CORE_DBALMODE";
			};
			class button_on: button_pwr
			{
				idc=1102;
				x = 0.49005681;//safeZoneX + safeZoneW * 0.44726563;
				y = 0.53345961;//safeZoneY + safeZoneH * 0.61631945;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.03819445;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceDbalA2";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceDbalA2";
				tooltip="$STR_GJB_ITN_CORE_DBALPWR";
			};
			class button_illumFocus: button_pwr
			{
				idc=1103;
				x = 0.46385733;//safeZoneX + safeZoneW * 0.43652344;
				y = 0.33543771;//safeZoneY + safeZoneH * 0.50694445;
				w = safeZoneW * 0.03958334;
				h = safeZoneH * 0.05208334;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_deviceDbalA2";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_deviceDbalA2";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_deviceDbalA2";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_core\ui\PEQ15A_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_core\ui\PEQ15A_onIndicator_co.paa";
	};
};
//UTG Flashlight
class Rsc_gjb_itn_acc_flashlight: Rsc_gjb_itn_dbala2
{
	idd=314003;
	controlsBackground[]=
	{
		"device"
	};
	controls[]=
	{
		"overlay",
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_core\ui\utg\base_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_core\ui\UTG_overlay_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.411875;
		y = safeZoneY + safeZoneH * 0.68;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.54924241;//safeZoneX + safeZoneW * 0.47167969;
				y = 0.86590911;//safeZoneY + safeZoneH * 0.79861112;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.05208334;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
				tooltip="$STR_GJB_ITN_CORE_FLPWR";
			};
		};
	};
};
//TLS
class Rsc_gjb_itn_acc_flashlight_pistol: Rsc_gjb_itn_acc_flashlight
{
	idd=314004;
	controls[]=
	{
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_core\ui\tls\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.39125;
		y = safeZoneY + safeZoneH * 0.59777778;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.49005681;//safeZoneX + safeZoneW * 0.44726563;
				y = 0.70808081;//safeZoneY + safeZoneH * 0.71180556;
				w = safeZoneW * 0.05664063;
				h = safeZoneH * 0.06597223;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
				tooltip="$STR_GJB_ITN_CORE_FLPWRALT";
			};
		};
	};
};
//PEQ-15
class Rsc_gjb_itn_peq15
{
	idd=314005;
	movingEnable=1;
	enableSimulation=1;
	onLoad="";
	onUnload="";
	controlsBackground[]=
	{
		"device",
		"knob_mode"
	};
	controls[]=
	{
		"onIndicator",
		"overlay",
		"fire_menu",/*
		"button_mode",
		"button_on",
		"button_illumFocus"*/
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\base_doff_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
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
				x = 0.45529573;//safeZoneX + safeZoneW * 0.43261719;
				y = 0.68531883;//safeZoneY + safeZoneH * 0.69965278;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePeq15"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_devicePeq15";
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.4102767;//safeZoneX + safeZoneW * 0.4140625;
				y = 0.5620961;//safeZoneY + safeZoneH * 0.63194445;
				w = safeZoneW * 0.0390625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_devicePeq15";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_devicePeq15";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.35104117;//safeZoneX + safeZoneW * 0.38964844;
				y = 0.34092705;//safeZoneY + safeZoneH * 0.51041667;
				w = safeZoneW * 0.02832032;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePeq15";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePeq15";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePeq15";
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\PEQ15_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\PEQ15_onIndicator_co.paa";
	};
};
//PEQ-15 Combo
class Rsc_gjb_itn_peq15_combo: Rsc_gjb_itn_peq15
{
	idd=314006;
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
		"fire_menu",/*
		"button_mode",
		"button_modeL",
		"button_on",
		"button_onL",
		"button_illumFocus"*/
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\base_doff_co.paa";
	};
	class deviceL: device
	{
		idc=1003;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\base_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
		text="";
	};
	class knob_modeL: knob_mode
	{
		idc=1002;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.34765625;
		y = safeZoneY + safeZoneH * 0.51736112;/*
		x = safeZoneX + safeZoneW * 0.34699854;
		y = safeZoneY + safeZoneH * 0.51953125;*/
	};
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
				tooltip="$STR_GJB_ITN_CORE_DEVMODE";
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
				tooltip="$STR_GJB_ITN_CORE_PEQ15PWR";
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
				tooltip="$STR_GJB_ITN_CORE_DEVIRDFFO";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x = 0.68512961;//safeZoneX + safeZoneW * 0.52734375;
				y = 0.41359688;//safeZoneY + safeZoneH * 0.55034723;
				w = safeZoneW * 0.05957032;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_devicePeq15Combo";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.68512962;//safeZoneX + safeZoneW * 0.52734375;
				y = 1.07710398;//safeZoneY + safeZoneH * 0.91493056;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\M952_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\PEQ15_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\PEQ15_onIndicator_co.paa";
	};
};
//VIS/IR Flashlight
class Rsc_gjb_itn_m952v: Rsc_gjb_itn_peq15
{
	idd=314009;
	controlsBackground[]=
	{
		"device",
		"knob_mode"
	};
	controls[]=
	{
		"overlay",
		"fire_menu",/*
		"button_mode",
		"button_on"*/
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\m952v\base_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.46679688;
		y = safeZoneY + safeZoneH * 0.796875;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.68512961;//safeZoneX + safeZoneW * 0.52734375;
				y = 0.41359688;//safeZoneY + safeZoneH * 0.55034723;
				w = safeZoneW * 0.05957032;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceM952"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceM952";
				tooltip="$STR_GJB_ITN_CORE_DEVMODEALT";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.68512962;//safeZoneX + safeZoneW * 0.52734375;
				y = 1.07710398;//safeZoneY + safeZoneH * 0.91493056;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceM952";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceM952";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_rhsusaf\ui\M952_overlay_co.paa";
	};
};


/* IDD register
314000	Generic Interface
314001	Zeus Interface
314002	DBAL-A2
314003	UTG
314004	TLS
314005	PEQ-15 (rhs)
314006	PEQ-15 Combo (rhs, m952)
314007	PEQ-15 Combo (rhs, wmx)
314008	PEQ-16 (rhs)
314009	Vis/IR flashlight
314010	WMX (rhs)
314011	PEQ-2 (cup)
314012 Perst1 (rhs)
314013 Klesh2 (rhs)
314014 Perst3 (rhs)
314015 Perst3 Combo (rhs)
314016 DBAL-PL (nia)
314017	PEQ-2 Combo (cup)
314018	PEQ-15 (cup)
314019	PEQ-15 Combo (cup)
314020 M952V (cup)
314021 GTL21 (cup)
314022 M6x (cup)
314023 Mk23 LAM (cup)
314024 Zenit2DS (cup)
314025 XM8 Flashlight (cup)
314026 MLPLS (cup)
314027 LLM01 (cup)
314028 LLM Mk3 (cup)
314029 MAWL (roa)
314030 NGAL (roa)
314031 LA5B (t1)
314032 LA5B + M300 (t1)
314033 LA5B + M600 (t1)
314034 NGAL (t1)
314035 NGAL + M300 (t1)
314036 NGAL + M600 (t1)
314037 M300 (t1)
314038 M600 (t1)
314039 NGAL (avalon)
314040
314041
314042
314043
314044
314045
314046
314047
314048
314049
*/