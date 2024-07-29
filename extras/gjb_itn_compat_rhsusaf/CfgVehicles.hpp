//Base classes
class gjb_itn_lampBase;
//

class CfgVehicles
{
	//RHS: M952V
		class gjb_itn_flash_m952_vis: gjb_itn_lampBase
		{
			scope=1;
			scopeCurator=1;
			displayName="ITN Vis Lamp Spot";
			class Reflectors
			{
				class Light_T
				{
					irLight=0;
					color[]={600,480,480};
					ambient[]={1,1,1};
					intensity=6;
					size=1;
					innerAngle=3;
					outerAngle=40;
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
					color[]={500,420,400};
					ambient[]={1,1,1};
					intensity=2;
					size=1;
					innerAngle=10;
					outerAngle=60;
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
		class gjb_itn_flash_m952_ir: gjb_itn_lampBase
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
					outerAngle=40;
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
					outerAngle=60;
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
	//RHS: WMX200
		class gjb_itn_flash_wmx200_vis: gjb_itn_lampBase
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
					outerAngle=20;
					coneFadeCoef=5;
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
					innerAngle=5;
					outerAngle=50;
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
		class gjb_itn_flash_wmx200_ir: gjb_itn_lampBase
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
					outerAngle=20;
					coneFadeCoef=5;
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
					innerAngle=5;
					outerAngle=50;
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
};