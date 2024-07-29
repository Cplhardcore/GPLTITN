class Extended_PreInit_EventHandlers
{
    class gjb_itn
	{
        init = "call compile preprocessFileLineNumbers '\gjb_itn\addons\gjb_itn_core\XEH_preInit.sqf'";
    };
};
class CfgFunctions
{
    class gjb_itn
	{
		class functions
		{ 
			//Initialization scripts
			class postInit
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\postInit.sqf";
				postInit=1;
			};
			class settings
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_settings.sqf";
			};
			class keys
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_keys.sqf";
			};
			class initMode
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_initMode.sqf";
			};
			//Per-Frame scripts
			class bucketEH
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_bucketEH.sqf";
			};
			class checkBucket
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_checkBucket.sqf";
			};
			//Controls scripts
			class autoPwr
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_autoPwr.sqf";
			};
			class ctrlPwr
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_ctrlPwr.sqf";
			};
			class ctrlMode
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_ctrlMode.sqf";
			};
			class ctrlOpenInterface
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_ctrlOpenInterface.sqf";
			};
			//Position and Mode composition scripts
			class getDeviceOffset
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_getDeviceOffset.sqf";
			};
			class getWeaponOffset
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_getWeaponOffset.sqf";
			};
			class modeSpec
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_modeSpec.sqf";
			};
			class hasCompat
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_hasCompat.sqf";
			};
			//Visual effects scripts
			class emissionCombined
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_emissionCombined.sqf";
			};
			//Dialog Interface scipts
			/*class getInterfaceKnobs
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_getInterfaceKnobs.sqf";
			};
			class interfaceChangeMode
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_interfaceChangeMode.sqf";
			};
			class dualDeviceActivate
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_dualDeviceActivate.sqf";
			};*/
			class illumFocus
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_illumFocus.sqf";
			};
			//Device Control scripts
			class deviceDbalA2
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceDbalA2.sqf";
			};
			class deviceDbalPl
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceDbalPl.sqf";
			};
			class deviceGeneric
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceGeneric.sqf";
			};
			class deviceM952
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceM952.sqf";
			};
			class devicePeq2
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_devicePeq2.sqf";
			};
			class devicePeq2Combo
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_devicePeq2Combo.sqf";
			};
			class devicePeq15
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_devicePeq15.sqf";
			};
			class devicePeq15Combo
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_devicePeq15Combo.sqf";
			};
			class devicePeq16
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_devicePeq16.sqf";
			};
			class devicePerst3
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_devicePerst3.sqf";
			};
			class devicePerst3Combo
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_devicePerst3Combo.sqf";
			};
			class deviceUTG
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceUTG.sqf";
			};
			class deviceGTL21
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceGTL21.sqf";
			};
			class deviceMk23
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceMk23.sqf";
			};
			class deviceLLM01
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceLLM01.sqf";
			};
			class deviceLLMmk3
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceLLMmk3.sqf";
			};
			class deviceLA5B
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceLA5B.sqf";
			};
			class deviceLA5BCombo
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceLA5BCombo.sqf";
			};
			/*class deviceLA5BComboVis
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceLA5BComboVis.sqf";
			};*/
			class deviceNGAL
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceNGAL.sqf";
			};
			class deviceNGALCombo
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_deviceNGALCombo.sqf";
			};
			//Zeus Modules
			class zm_toggleLaser
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_toggleLaser.sqf";
				class gjb_itn_toggleLaser {};
			};
			//Debug script
			class debugCmd
			{
				file = "\gjb_itn\addons\gjb_itn_core\functions\gjb_itn_debugCmd.sqf";
			};
		};
	};
};