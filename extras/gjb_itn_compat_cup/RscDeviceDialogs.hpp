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
class Rsc_gjb_itn_peq2_cup: Rsc_gjb_itn_peq15
{
	idd=314011;
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\base_doff_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.36383602;
		y = safeZoneY + safeZoneH * 0.52864584;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.42121526;//safeZoneX + safeZoneW * 0.41894532;
				y = 0.82829881;//safeZoneY + safeZoneH * 0.77777778;
				w = safeZoneW * 0.05566407;
				h = safeZoneH * 0.07638889;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePeq2"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_devicePeq2";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.44728159;//safeZoneX + safeZoneW * 0.4296875;
				y = 0.58146338;//safeZoneY + safeZoneH * 0.64236112;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_devicePeq2";
				onMouseZChanged="";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.3359072;//safeZoneX + safeZoneW * 0.38378907;
				y = 0.34064059;//safeZoneY + safeZoneH * 0.49652778;
				w = safeZoneW * 0.05566407;
				h = safeZoneH * 0.05208334;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePeq2";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePeq2";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePeq2";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ2_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ2_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_peq2_combo_cup: Rsc_gjb_itn_peq15_combo
{
	idd=314017;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.36383602;
		y = safeZoneY + safeZoneH * 0.52864584;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.42121526;//safeZoneX + safeZoneW * 0.41894532;
				y = 0.82829881;//safeZoneY + safeZoneH * 0.77777778;
				w = safeZoneW * 0.05566407;
				h = safeZoneH * 0.07638889;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePeq2Combo"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_devicePeq2Combo";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.44728159;//safeZoneX + safeZoneW * 0.4296875;
				y = 0.58146338;//safeZoneY + safeZoneH * 0.64236112;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_devicePeq2Combo";
				onMouseZChanged="";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.3359072;//safeZoneX + safeZoneW * 0.38378907;
				y = 0.31564059;//safeZoneY + safeZoneH * 0.49652778;
				w = safeZoneW * 0.05566407;
				h = safeZoneH * 0.05208334;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePeq2Combo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePeq2Combo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePeq2Combo";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x = 0.67713943;//safeZoneX + safeZoneW *0.52441407;
				y = 0.46753933;//safeZoneY + safeZoneH * 0.57986112;
				w = safeZoneW * 0.04980469;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_devicePeq2Combo"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_devicePeq2Combo";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.66766076;//safeZoneX + safeZoneW * 0.52050782;
				y = 0.99602033;//safeZoneY + safeZoneH * 0.86979167;
				w = safeZoneW * 0.04101563;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_devicePeq2Combo";
				onMouseZChanged="";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ2_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ2_onIndicator_co.paa";
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\M952_overlay_co.paa";
	};
};
class Rsc_gjb_itn_peq15_cup: Rsc_gjb_itn_peq15
{
	idd=314018;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.35871157;
		y = safeZoneY + safeZoneH * 0.51953125;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.52311098;//safeZoneX + safeZoneW *0.4609375;
				y = 0.68589375;//safeZoneY + safeZoneH * 0.69965278;
				w = safeZoneW * 0.04101563;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePeq15"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_devicePeq15";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.44728159;//safeZoneX + safeZoneW * 0.4296875;
				y = 0.58462794;//safeZoneY + safeZoneH * 0.64409723;
				w = safeZoneW * 0.02929688;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_devicePeq15";
				onMouseZChanged="";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.34775554;//safeZoneX + safeZoneW * 0.38867188;
				y = 0.30931148;//safeZoneY + safeZoneH * 0.49305556;
				w = safeZoneW * 0.04980469;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePeq15";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePeq15";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePeq15";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ15_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ15_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_peq15_combo_cup: Rsc_gjb_itn_peq15_combo
{
	idd=314019;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.35871157;
		y = safeZoneY + safeZoneH * 0.51953125;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.52311098;//safeZoneX + safeZoneW *0.4609375;
				y = 0.68589375;//safeZoneY + safeZoneH * 0.69965278;
				w = safeZoneW * 0.04101563;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_devicePeq15Combo";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.44728159;//safeZoneX + safeZoneW * 0.4296875;
				y = 0.58462794;//safeZoneY + safeZoneH * 0.64409723;
				w = safeZoneW * 0.02929688;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="";
			};
			class button_illumFocus: button_mode
			{
				idc=1110;
				x = 0.34775554;//safeZoneX + safeZoneW * 0.38867188;
				y = 0.30931148;//safeZoneY + safeZoneH * 0.49305556;
				w = safeZoneW * 0.04980469;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['illumD',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseButtonUp="['illumU',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="['illumW',_this #1,'w'] call gjb_itn_fnc_devicePeq15Combo";
			};
			class button_modeL: button_mode
			{
				idc=1120;
				x = 0.67713943;//safeZoneX + safeZoneW *0.52441407;
				y = 0.46753933;//safeZoneY + safeZoneH * 0.57986112;
				w = safeZoneW * 0.04980469;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['mode2',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo"; 
				onMouseZChanged="['mode2',_this #1,'w'] call gjb_itn_fnc_devicePeq15Combo";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.66766076;//safeZoneX + safeZoneW * 0.52050782;
				y = 0.99602033;//safeZoneY + safeZoneH * 0.86979167;
				w = safeZoneW * 0.04101563;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_devicePeq15Combo";
				onMouseZChanged="";
			};
		};
	};
	class overlayL: device
	{
		idc=997;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\M952_overlay_co.paa";
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ15_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\PEQ15_onIndicator_co.paa";
	};
};
class Rsc_gjb_itn_m952v_cup: Rsc_gjb_itn_m952v
{
	idd=314020;
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\m952\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.45875;
		y = safeZoneY + safeZoneH * 0.77555556;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.67713943;//safeZoneX + safeZoneW *0.52441407;
				y = 0.46753933;//safeZoneY + safeZoneH * 0.57986112;
				w = safeZoneW * 0.04980469;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceM952"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceM952";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.66766076;//safeZoneX + safeZoneW * 0.52050782;
				y = 0.99602033;//safeZoneY + safeZoneH * 0.86979167;
				w = safeZoneW * 0.04101563;
				h = safeZoneH * 0.05555556;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceM952";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceM952";
				onMouseZChanged="";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\M952_overlay_co.paa";
	};
};
class Rsc_gjb_itn_gtl21_cup: Rsc_gjb_itn_m952v
{
	idd=314021;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.39238654;
		y = safeZoneY + safeZoneH * 0.64973959;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.47334795;//safeZoneX + safeZoneW * 0.44042969;
				y = 0.83146337;//safeZoneY + safeZoneH * 0.77951389;
				w = safeZoneW * 0.02929688;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceGTL21"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceGTL21";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.50048066;//safeZoneX + safeZoneW * 0.46191407;
				y = 0.75234946;//safeZoneY + safeZoneH * 0.73611112;
				w = safeZoneW * 0.03613282;
				h = safeZoneH * 0.06597223;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceGTL21";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceGTL21";
				onMouseZChanged="";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\GTL21_overlay_co.paa";
	};
};
class Rsc_gjb_itn_m6x_cup: Rsc_gjb_itn_m952v
{
	idd=314022;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.39625;
		y = safeZoneY + safeZoneH * 0.60222223;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.4994143;//safeZoneX + safeZoneW * 0.45117188;
				y = 0.74285577;//safeZoneY + safeZoneH * 0.73090278;
				w = safeZoneW * 0.02929688;
				h = safeZoneH * 0.03472223;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceGTL21"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceGTL21";
			};
			class button_onA: button_mode
			{
				idc=1101;
				x = 0.4994143;//safeZoneX + safeZoneW * 0.45117188;
				y = 0.67007097;//safeZoneY + safeZoneH * 0.69097223;
				w = safeZoneW * 0.03613282;
				h = safeZoneH * 0.03819445;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceGTL21";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceGTL21";
				onMouseZChanged="";
			};
			class button_onB: button_onA
			{
				idc=1102;
				x = 0.57524369;//safeZoneX + safeZoneW * 0.48242188;
				y = 0.67007097;//safeZoneY + safeZoneH * 0.69097223;
				w = safeZoneW * 0.02539063;
				h = safeZoneH * 0.06597223;
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\M6x_overlay_co.paa";
	};
};
class Rsc_gjb_itn_mk23lam_cup: Rsc_gjb_itn_m952v
{
	idd=314023;
	controlsBackground[]=
	{
		"device",
		"knob_mode",
		"irFilter"
	};
	class device;
	class irFilter: device
	{
		idc=1002;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.363125;
		y = safeZoneY + safeZoneH * 0.69666667;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.40482954;//safeZoneX + safeZoneW * 0.41210938;
				y = 0.68282829;//safeZoneY + safeZoneH * 0.69791667;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceMk23"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceMk23";
				tooltip="Device Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on: button_mode
			{
				idc=1101;
				x = 0.4543906;//safeZoneX + safeZoneW * 0.43261719;
				y = 0.88209628;//safeZoneY + safeZoneH * 0.80729167;
				w = safeZoneW * 0.02441407;
				h = safeZoneH * 0.03472223;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceMk23";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceMk23";
				onMouseZChanged="";
				tooltip="Activation Switch: Left-Click to toggle power";
			};
			class button_irFilter1: button_mode
			{
				idc=1110;
				x = 0.53969866;//safeZoneX + safeZoneW * 0.46777344;
				y = 0.42640008;//safeZoneY + safeZoneH * 0.55729167;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.04513889;
				onMouseButtonDown="['filter',_this #1,'b'] call gjb_itn_fnc_deviceMk23";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CUP_MK23FILTEROFF";
			};
			class button_irFilter2: button_mode
			{
				idc=1111;
				x = 0.56576502;//safeZoneX + safeZoneW * 0.47851563;
				y = 0.57513425;//safeZoneY + safeZoneH * 0.63888889;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.08680556;
				onMouseButtonDown="['filter',_this #1,'b'] call gjb_itn_fnc_deviceMk23";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CUP_MK23FILTERON";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\Mk23_overlay_co.paa";
	};
};
class Rsc_gjb_itn_zenit2ds_cup: Rsc_gjb_itn_acc_flashlight
{
	idd=314024;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.379375;
		y = safeZoneY + safeZoneH * 0.69555556;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x = 0.4994143;//safeZoneX + safeZoneW * 0.45117188;
				y = 0.90741275;//safeZoneY + safeZoneH * 0.82118056;
				w = safeZoneW * 0.02441407;
				h = safeZoneH * 0.03125;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
				tooltip="$STR_GJB_ITN_CORE_DEVPWR";
			};
		};
	};
};
class Rsc_gjb_itn_xm8_cup: Rsc_gjb_itn_acc_flashlight
{
	idd=314025;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.400625;
		y = safeZoneY + safeZoneH * 0.71555556;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x = 0.4994143;//safeZoneX + safeZoneW * 0.45117188;
				y = 0.86310894;//safeZoneY + safeZoneH * 0.796875;
				w = safeZoneW * 0.0625;
				h = safeZoneH * 0.09027778;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
				tooltip="$STR_GJB_ITN_CORE_FLPWRALT";
			};
		};
	};
};
class Rsc_gjb_itn_mlpls_cup: Rsc_gjb_itn_acc_flashlight
{
	idd=314026;
	class device;
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.3997;
		y = safeZoneY + safeZoneH * 0.54111112;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_on: Rsc_gjb_itn_HiddenButton
			{
				idc=1101;
				x = 0.54206832;//safeZoneX + safeZoneW * 0.46875;
				y = 0.5719697;//safeZoneY + safeZoneH * 0.63715278;
				w = safeZoneW * 0.03125;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire',_this #1,'b'] call gjb_itn_fnc_deviceUTG";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceUTG";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\MLPLS_overlay_co.paa";
	};
};
class Rsc_gjb_itn_llm01_cup: Rsc_gjb_itn_m952v
{
	idd=314027;
	controls[]=
	{
		"overlay",
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\llm\base_co.paa";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.378125;
		y = safeZoneY + safeZoneH * 0.57888889;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.61552804;//safeZoneX + safeZoneW * 0.49902344;
				y = 0.62893172;//safeZoneY + safeZoneH * 0.66840278;
				w = safeZoneW * 0.02148438;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLLM01"; 
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLLM01";
				tooltip="Device Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_on1: button_mode
			{
				idc=1101;
				x = 0.56576502;//safeZoneX + safeZoneW * 0.47851563;
				y = 0.55298237;//safeZoneY + safeZoneH * 0.62673612;
				w = safeZoneW * 0.02148438;
				h = safeZoneH * 0.0625;
				onMouseButtonDown="['fire1',_this #1,'b'] call gjb_itn_fnc_deviceLLM01";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceLLM01";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CUP_LLM01SIDEPWR";
			};
			class button_on2: button_mode
			{
				idc=1102;
				x = 0.48993563;//safeZoneX + safeZoneW * 0.44726563;
				y = 0.65424818;//safeZoneY + safeZoneH * 0.68229167;
				w = safeZoneW * 0.03222657;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire2',_this #1,'b'] call gjb_itn_fnc_deviceLLM01";
				onMouseButtonUp="['fire',_this #1,'bu'] call gjb_itn_fnc_deviceLLM01";
				onMouseZChanged="";
				tooltip="$STR_GJB_ITN_CUP_LLM01BACKPWR";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\LLM01_overlay_co.paa";
	};
};
class Rsc_gjb_itn_llmMk3_cup: Rsc_gjb_itn_peq15_combo
{
	idd=314028;
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
		"fire_menu",
		"ctrls_holder"
	};
	class device: Rsc_gjb_itn_BackPicture
	{
		idc=1000;
		text="\gjb_itn\addons\gjb_itn_core\ui\peq15a\base_co.paa";
	};
	class knob_mode: device
	{
		idc=1001;
		text="";
	};
	class fire_menu: Rsc_gjb_itn_autoOn_base
	{
		idc=1050;
		x = safeZoneX + safeZoneW * 0.379375;
		y = safeZoneY + safeZoneH * 0.52666667;
	};
	class ctrls_holder: Rsc_gjb_itn_ctrlsHolder_base
	{
		idc=1060;
		class Controls
		{
			class button_mode: Rsc_gjb_itn_HiddenButton
			{
				idc=1100;
				x = 0.53258965;//safeZoneX + safeZoneW * 0.46484375;
				y = 0.70171654;//safeZoneY + safeZoneH * 0.70833334;
				w = safeZoneW * 0.03515625;
				h = safeZoneH * 0.0625;
				text="";
				colorBackground[]={0,0,0,0};
				colorText[]={0,0,0,0};
				font="PuristaMedium";
				sizeEx=(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				onMouseButtonDown="['mode1',_this #1,'b'] call gjb_itn_fnc_deviceLLMmk3";
				onMouseButtonUp="";
				onMouseZChanged="['mode1',_this #1,'w'] call gjb_itn_fnc_deviceLLMmk3";
				tooltip="Mode Select: Left-click for NEXT, Right-click for PREV, or scroll with Mouse-wheel";
			};
			class button_onA: button_mode
			{
				idc=1101;
				x = 0.50889298;//safeZoneX + safeZoneW * 0.45507813;
				y = 0.60045071;//safeZoneY + safeZoneH * 0.65277778;
				w = safeZoneW * 0.02539063;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire1',_this #1,'bd'] call gjb_itn_fnc_deviceLLMmk3";
				onMouseButtonUp="['fire1',_this #1,'bu'] call gjb_itn_fnc_deviceLLMmk3";
				onMouseZChanged="";
				tooltip="Fire Button 1: Left-click to toggle Target Marker, hold to cycle power level";
			};
			class button_onI: button_mode
			{
				idc=1111;
				x = 0.57761335;//safeZoneX + safeZoneW * 0.48339844;
				y = 0.60045071;//safeZoneY + safeZoneH * 0.65277778;
				w = safeZoneW * 0.02539063;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire2',_this #1,'bd'] call gjb_itn_fnc_deviceLLMmk3";
				onMouseButtonUp="['fire2',_this #1,'bu'] call gjb_itn_fnc_deviceLLMmk3";
				onMouseZChanged="";
				tooltip="Fire Button 2: Left-click to toggle Target Illuminator (IR), hold to cycle power level";
			};
			class button_onL: button_mode
			{
				idc=1121;
				x = 0.64870341;//safeZoneX + safeZoneW * 0.51269532;
				y = 0.77450134;//safeZoneY + safeZoneH * 0.74826389;
				w = safeZoneW * 0.04589844;
				h = safeZoneH * 0.04861112;
				onMouseButtonDown="['fire3',_this #1,'bd'] call gjb_itn_fnc_deviceLLMmk3";
				onMouseButtonUp="['fire3',_this #1,'bu'] call gjb_itn_fnc_deviceLLMmk3";
				onMouseZChanged="";
				tooltip="Fire Button 3: Left-click to toggle Target Illuminator (Vis)";
			};
		};
	};
	class overlay: device
	{
		idc=998;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\LLM3_overlay_co.paa";
	};
	class onIndicator: overlay
	{
		idc=999;
		text="\gjb_itn\addons\gjb_itn_compat_cup\ui\LLM3_onIndicator_co.paa";
	};
};