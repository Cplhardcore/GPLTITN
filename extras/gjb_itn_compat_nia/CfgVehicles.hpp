//Base classes
class gjb_itn_lampBase;
//

class CfgVehicles
{
	//NIA: DBAL-PL
	class gjb_itn_flash_dbal_pl_vis: gjb_itn_lampBase
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
				intensity=3;
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
				color[]={400,400,450};
				ambient[]={1,1,1};
				intensity=3;
				size=1;
				innerAngle=5;
				outerAngle=40;
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
	class gjb_itn_flash_dbal_pl_ir: gjb_itn_lampBase
	{
		scope=1;
		scopeCurator=1;
		displayName="ITN Vis Lamp Spot";
		class Reflectors
		{
			class Light_T
			{
				irLight=1;
				color[]={500,500,550};
				ambient[]={1,1,1};
				intensity=1;
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
					hardLimitStart=100;
					hardLimitEnd=200;
				};
			};
			class Light_W
			{
				irLight=1;
				color[]={400,400,450};
				ambient[]={1,1,1};
				intensity=2;
				size=1;
				innerAngle=5;
				outerAngle=40;
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
					quadratic=0.01;
					hardLimitStart=100;
					hardLimitEnd=200;
				};
			};
		};
		aggregateReflectors[]=
		{
			"Light_T",
			"Light_W"
		};
	};
};