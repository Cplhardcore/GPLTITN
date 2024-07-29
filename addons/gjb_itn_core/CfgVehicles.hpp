//Base classes --- illuminators
class gjb_itn_irIllum_lo_base
{
	irLight=1;
	color[]={4,4,4};
	ambient[]={0,0,0};
	intensity=3500;		//intensity is calculated by illuminators output in mW * 1000.
	size=1;
	innerAngle=8;
	outerAngle=10;
	coneFadeCoef=1;
	position="light_pos";
	direction="light_dir";
	hitpoint="";
	selection="";
	useFlare=1;
	flareSize=0.2;
	flareMaxDistance=2000;
};
class gjb_itn_irIllum_lo_attenuationBase
{
	start=1;
	constant=3.14159*0.031091;
	linear=0;
	quadratic=1;
	hardLimitStart=400;
	hardLimitEnd=700;
};
class gjb_itn_irIllum_hi_attenuationBase: gjb_itn_irIllum_lo_attenuationBase
{
	hardLimitStart=1000;
	hardLimitEnd=1600;
};
class gjb_itn_irIllum_lo_10 : gjb_itn_irIllum_lo_base
{
	intensity=3500*1;
	innerAngle=8.5;
	outerAngle=10;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{};
};
class gjb_itn_irIllum_lo_09 : gjb_itn_irIllum_lo_base
{
	intensity=3500*1.234567901;
	innerAngle=7.65;
	outerAngle=9;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.025086;
	};
};
class gjb_itn_irIllum_lo_08 : gjb_itn_irIllum_lo_base
{
	intensity=3500*1.5625;
	innerAngle=6.8;
	outerAngle=8;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.019752;
	};
};
class gjb_itn_irIllum_lo_07 : gjb_itn_irIllum_lo_base
{
	intensity=3500*2.040816327;
	innerAngle=5.95;
	outerAngle=7;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.015076;
	};
};
class gjb_itn_irIllum_lo_06 : gjb_itn_irIllum_lo_base
{
	intensity=3500*2.777777778;
	innerAngle=5.1;
	outerAngle=6;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.011047;
	};
};
class gjb_itn_irIllum_lo_05 : gjb_itn_irIllum_lo_base
{
	intensity=3500*4;
	innerAngle=4.25;
	outerAngle=5;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.007654;
	};
};
class gjb_itn_irIllum_lo_04 : gjb_itn_irIllum_lo_base
{
	intensity=3500*6.25;
	innerAngle=3.4;
	outerAngle=4;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.004890;
	};
};
class gjb_itn_irIllum_lo_03 : gjb_itn_irIllum_lo_base
{
	intensity=3500*11.11111111;
	innerAngle=2.55;
	outerAngle=3;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.002747;
	};
};
class gjb_itn_irIllum_lo_02 : gjb_itn_irIllum_lo_base
{
	intensity=3500*25;
	innerAngle=1.7;
	outerAngle=2;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.001219;
	};
};
class gjb_itn_irIllum_lo_01 : gjb_itn_irIllum_lo_base
{
	intensity=3500*100;
	innerAngle=0.85;
	outerAngle=1;
	coneFadeCoef=1;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*0.000305;
	};
};
class gjb_itn_irIllum_lo_60 : gjb_itn_irIllum_lo_base
{
	intensity=3500*0.027777778;
	innerAngle=3;
	outerAngle=60;
	coneFadeCoef=3;
	class Attenuation: gjb_itn_irIllum_lo_attenuationBase
	{
		constant=3.14159*3;
		hardLimitStart=1;
		hardLimitEnd=100;
	};
};
class gjb_itn_irIllum_hi_10 : gjb_itn_irIllum_lo_10
{
	intensity=30000*1;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{};
};
class gjb_itn_irIllum_hi_09 : gjb_itn_irIllum_lo_09
{
	intensity=30000*1.234567901;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.025086;
	};
};
class gjb_itn_irIllum_hi_08 : gjb_itn_irIllum_lo_08
{
	intensity=30000*1.5625;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.019752;
	};
};
class gjb_itn_irIllum_hi_07 : gjb_itn_irIllum_lo_07
{
	intensity=30000*2.040816327;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.015076;
	};
};
class gjb_itn_irIllum_hi_06 : gjb_itn_irIllum_lo_06
{
	intensity=30000*2.777777778;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.011047;
	};
};
class gjb_itn_irIllum_hi_05 : gjb_itn_irIllum_lo_05
{
	intensity=30000*4;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.007654;
	};
};
class gjb_itn_irIllum_hi_04 : gjb_itn_irIllum_lo_04
{
	intensity=30000*6.25;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.004890;
	};
};
class gjb_itn_irIllum_hi_03 : gjb_itn_irIllum_lo_03
{
	intensity=30000*11.11111111;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.002747;
	};
};
class gjb_itn_irIllum_hi_02 : gjb_itn_irIllum_lo_02
{
	intensity=30000*25;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.001219;
	};
};
class gjb_itn_irIllum_hi_01 : gjb_itn_irIllum_lo_01
{
	intensity=30000*100;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*0.000305;
	};
};
class gjb_itn_irIllum_hi_60 : gjb_itn_irIllum_lo_60
{
	intensity=30000*0.027777778;
	class Attenuation: gjb_itn_irIllum_hi_attenuationBase
	{
		constant=3.14159*3;
		hardLimitStart=1;
		hardLimitEnd=100;
	};
};
//

class CfgVehicles
{
//Light Objects
	class Lamps_base_F;
	class gjb_itn_lampBase: Lamps_base_F
	{
		scope=1;
		scopeCurator=1;
		displayName="ITN Lamp Base";
		model="\gjb_itn\addons\gjb_itn_core\data\light.p3d";
		/*maxDetectRange=0.001;
		spotableDarkNightLightsOff=0.001;
		spotableNightLightsOff=0.001;
		spotableNightLightsOn=0.001;*/
		class Hitpoints
		{
		};
		class AnimationSources
		{
		};
		class Reflectors
		{
		};
       /* class ACE_Actions
		{
			class gjb_itn_interactTest
			{
				displayName = "Test PWr ON";
				position = "";
				selection = "light_pos";
				distance = 1.5;
				condition = "";
				exceptions[] = {};
				statement = "systemChat 'test worked'";
				icon = "\a3\ui_f_data\IGUI\Cfg\Actions\eject_ca.paa";
			};
		};*/
	};
	//BIS: DBAL-A2
		class gjb_itn_illum_dbal_a2_10_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 10 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_10
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_09_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 09 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_09
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_08_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 08 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_08
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_07_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 07 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_07
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_06_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 06 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_06
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_05_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 05 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_05
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_04_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 04 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_04
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_03_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 03 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_03
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_02_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 02 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_02
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_01_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 01 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_01
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_60_Lo: gjb_itn_lampBase
		{
			displayName="ITN Lamp 60 LO";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_lo_60
				{};
			};
		};
		//
		class gjb_itn_illum_dbal_a2_10_Hi: gjb_itn_illum_dbal_a2_10_Lo
		{
			displayName="ITN Lamp 10 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_10
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_09_Hi: gjb_itn_illum_dbal_a2_09_Lo
		{
			displayName="ITN Lamp 09 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_09
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_08_Hi: gjb_itn_illum_dbal_a2_08_Lo
		{
			displayName="ITN Lamp 08 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_08
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_07_Hi: gjb_itn_illum_dbal_a2_07_Lo
		{
			displayName="ITN Lamp 07 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_07
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_06_Hi: gjb_itn_illum_dbal_a2_06_Lo
		{
			displayName="ITN Lamp 06 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_06
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_05_Hi: gjb_itn_illum_dbal_a2_05_Lo
		{
			displayName="ITN Lamp 05 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_05
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_04_Hi: gjb_itn_illum_dbal_a2_04_Lo
		{
			displayName="ITN Lamp 04 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_04
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_03_Hi: gjb_itn_illum_dbal_a2_03_Lo
		{
			displayName="ITN Lamp 03 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_03
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_02_Hi: gjb_itn_illum_dbal_a2_02_Lo
		{
			displayName="ITN Lamp 02 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_02
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_01_Hi: gjb_itn_illum_dbal_a2_01_Lo
		{
			displayName="ITN Lamp 01 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_01
				{};
			};
		};
		class gjb_itn_illum_dbal_a2_60_Hi: gjb_itn_illum_dbal_a2_60_Lo
		{
			displayName="ITN Lamp 60 HI";
			class Reflectors
			{
				class Light_1: gjb_itn_irIllum_hi_60
				{};
			};
		};
	/*Flashlights========================================================
	===================================================================*/
	//Generic Weapon Light
		class gjb_itn_flash_gen_vis: gjb_itn_lampBase
		{
			scope=1;
			scopeCurator=1;
			displayName="ITN Vis Lamp Spot";
			class Reflectors
			{
				class Light_T
				{
					irLight=0;
					color[]={500,500,600};
					ambient[]={1,1,1};
					intensity=6;
					size=1;
					innerAngle=3;
					outerAngle=30;
					coneFadeCoef=10;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=0;
					dayLight=1;
					flareSize=0;
					flareMaxDistance=0;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.001;
						hardLimitStart=200;
						hardLimitEnd=300;
					};
				};
				class Light_W
				{
					irLight=0;
					color[]={400,400,450};
					ambient[]={1,1,1};
					intensity=2;
					size=1;
					innerAngle=10;
					outerAngle=80;
					coneFadeCoef=4;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=1;
					flareSize=1;
					flareMaxDistance=500;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.03;
						hardLimitStart=100;
						hardLimitEnd=150;
					};
				};
			};
			aggregateReflectors[]=
			{
				"Light_T",
				"Light_W"
			};
		};
		class gjb_itn_flash_gen_ir: gjb_itn_lampBase
		{
			scope=1;
			scopeCurator=1;
			displayName="ITN Vis Lamp Spot";
			class Reflectors
			{
				class Light_T
				{
					irLight=1;
					color[]={500,500,600};
					ambient[]={1,1,1};
					intensity=2;
					size=1;
					innerAngle=3;
					outerAngle=30;
					coneFadeCoef=10;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=0;
					flareSize=0;
					flareMaxDistance=0;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.001;
						hardLimitStart=200;
						hardLimitEnd=300;
					};
				};
				class Light_W
				{
					irLight=1;
					color[]={400,400,450};
					ambient[]={1,1,1};
					intensity=1;
					size=1;
					innerAngle=10;
					outerAngle=80;
					coneFadeCoef=4;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=1;
					flareSize=1;
					flareMaxDistance=500;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.03;
						hardLimitStart=200;
						hardLimitEnd=300;
					};
				};
			};
			aggregateReflectors[]=
			{
				"Light_T",
				"Light_W"
			};
		};
	//Generic Pistol Light
		class gjb_itn_flash_pistol_vis: gjb_itn_lampBase
		{
			scope=1;
			scopeCurator=1;
			displayName="ITN Vis Lamp Spot";
			class Reflectors
			{
				class Light_T
				{
					irLight=0;
					color[]={500,500,600};
					ambient[]={1,1,1};
					intensity=5;
					size=1;
					innerAngle=3;
					outerAngle=20;
					coneFadeCoef=10;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=0;
					dayLight=1;
					flareSize=0;
					flareMaxDistance=0;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.01;
						hardLimitStart=200;
						hardLimitEnd=300;
					};
				};
				class Light_W
				{
					irLight=0;
					color[]={300,300,350};
					ambient[]={1,1,1};
					intensity=2;
					size=1;
					innerAngle=5;
					outerAngle=70;
					coneFadeCoef=4;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=1;
					flareSize=1;
					flareMaxDistance=400;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.01;
						hardLimitStart=100;
						hardLimitEnd=150;
					};
				};
			};
			aggregateReflectors[]=
			{
				"Light_T",
				"Light_W"
			};
		};
		class gjb_itn_flash_pistol_ir: gjb_itn_lampBase
		{
			scope=1;
			scopeCurator=1;
			displayName="ITN Vis Lamp Spot";
			class Reflectors
			{
				class Light_T
				{
					irLight=1;
					color[]={500,500,600};
					ambient[]={1,1,1};
					intensity=4;
					size=1;
					innerAngle=3;
					outerAngle=20;
					coneFadeCoef=10;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=0;
					dayLight=1;
					flareSize=0;
					flareMaxDistance=0;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.01;
						hardLimitStart=200;
						hardLimitEnd=300;
					};
				};
				class Light_W
				{
					irLight=1;
					color[]={300,300,350};
					ambient[]={1,1,1};
					intensity=1.7;
					size=1;
					innerAngle=5;
					outerAngle=70;
					coneFadeCoef=4;
					position="light_pos";
					direction="light_dir";
					hitpoint="";
					selection="";
					useFlare=1;
					flareSize=1;
					flareMaxDistance=400;
					class Attenuation
					{
						start=1;
						constant=1;
						linear=1;
						quadratic=0.01;
						hardLimitStart=100;
						hardLimitEnd=150;
					};
				};
			};
			aggregateReflectors[]=
			{
				"Light_T",
				"Light_W"
			};
		};
//Zeus Modules
	class Module_F;
	class gjb_itn_baseModule: Module_F
	{
		author = "GhostJB";
		scope = 1;
		scopeCurator = 2;
		//icon = "";
		category = "gjb_itn_zeusMods";
        functionPriority = 1;
        curatorCanAttach = 1;
		isGlobal = 1;
        isTriggerActivated = 0;
		is3DEN = 0;
	};
	class gjb_itn_toggleLaser: gjb_itn_baseModule
	{
		displayName = "Toggle Laser";
		function = "gjb_itn_fnc_zm_toggleLaser";
	};
};