//Base classes
class gjb_itn_lampBase;
class gjb_itn_irIllum_lo_10;
class gjb_itn_irIllum_lo_09;
class gjb_itn_irIllum_lo_08;
class gjb_itn_irIllum_lo_07;
class gjb_itn_irIllum_lo_06;
class gjb_itn_irIllum_lo_05;
class gjb_itn_irIllum_lo_04;
class gjb_itn_irIllum_lo_03;
class gjb_itn_irIllum_lo_02;
class gjb_itn_irIllum_lo_01;
class gjb_itn_irIllum_lo_60;
class gjb_itn_irIllum_hi_10;
class gjb_itn_irIllum_hi_09;
class gjb_itn_irIllum_hi_08;
class gjb_itn_irIllum_hi_07;
class gjb_itn_irIllum_hi_06;
class gjb_itn_irIllum_hi_05;
class gjb_itn_irIllum_hi_04;
class gjb_itn_irIllum_hi_03;
class gjb_itn_irIllum_hi_02;
class gjb_itn_irIllum_hi_01;
class gjb_itn_irIllum_hi_60;
//

class CfgVehicles
{
	class gjb_itn_illum_dbal_a2_10_Lo;
	class gjb_itn_illum_dbal_a2_09_Lo;
	class gjb_itn_illum_dbal_a2_08_Lo;
	class gjb_itn_illum_dbal_a2_07_Lo;
	class gjb_itn_illum_dbal_a2_06_Lo;
	class gjb_itn_illum_dbal_a2_05_Lo;
	class gjb_itn_illum_dbal_a2_04_Lo;
	class gjb_itn_illum_dbal_a2_03_Lo;
	class gjb_itn_illum_dbal_a2_02_Lo;
	class gjb_itn_illum_dbal_a2_01_Lo;
	class gjb_itn_illum_dbal_a2_60_Lo;
	class gjb_itn_illum_dbal_a2_10_Hi;
	class gjb_itn_illum_dbal_a2_09_Hi;
	class gjb_itn_illum_dbal_a2_08_Hi;
	class gjb_itn_illum_dbal_a2_07_Hi;
	class gjb_itn_illum_dbal_a2_06_Hi;
	class gjb_itn_illum_dbal_a2_05_Hi;
	class gjb_itn_illum_dbal_a2_04_Hi;
	class gjb_itn_illum_dbal_a2_03_Hi;
	class gjb_itn_illum_dbal_a2_02_Hi;
	class gjb_itn_illum_dbal_a2_01_Hi;
	class gjb_itn_illum_dbal_a2_60_Hi;
	// Perst-3 ()
	class gjb_itn_illum_perst3_10_Lo: gjb_itn_illum_dbal_a2_10_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_10
			{
				intensity=3500*1;
			};
		};
	};
	class gjb_itn_illum_perst3_09_Lo: gjb_itn_illum_dbal_a2_09_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_09
			{
				intensity=3500*1.234567901;
			};
		};
	};
	class gjb_itn_illum_perst3_08_Lo: gjb_itn_illum_dbal_a2_08_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_08
			{
				intensity=3500*1.5625;
			};
		};
	};
	class gjb_itn_illum_perst3_07_Lo: gjb_itn_illum_dbal_a2_07_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_07
			{
				intensity=3500*2.040816327;
			};
		};
	};
	class gjb_itn_illum_perst3_06_Lo: gjb_itn_illum_dbal_a2_06_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_06
			{
				intensity=3500*2.777777778;
			};
		};
	};
	class gjb_itn_illum_perst3_05_Lo: gjb_itn_illum_dbal_a2_05_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_05
			{
				intensity=3500*4;
			};
		};
	};
	class gjb_itn_illum_perst3_04_Lo: gjb_itn_illum_dbal_a2_04_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_04
			{
				intensity=3500*6.25;
			};
		};
	};
	class gjb_itn_illum_perst3_03_Lo: gjb_itn_illum_dbal_a2_03_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_03
			{
				intensity=3500*11.11111111;
			};
		};
	};
	class gjb_itn_illum_perst3_02_Lo: gjb_itn_illum_dbal_a2_02_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_02
			{
				intensity=3500*25;
			};
		};
	};
	class gjb_itn_illum_perst3_01_Lo: gjb_itn_illum_dbal_a2_01_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_01
			{
				intensity=3500*100;
			};
		};
	};
	class gjb_itn_illum_perst3_60_Lo: gjb_itn_illum_dbal_a2_60_Lo
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_lo_60
			{
				intensity=3500*0.027777778;
			};
		};
	};
	//
	class gjb_itn_illum_perst3_10_Hi: gjb_itn_illum_dbal_a2_10_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_10
			{
				intensity=30000*1;
			};
		};
	};
	class gjb_itn_illum_perst3_09_Hi: gjb_itn_illum_dbal_a2_09_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_09
			{
				intensity=30000*1.234567901;
			};
		};
	};
	class gjb_itn_illum_perst3_08_Hi: gjb_itn_illum_dbal_a2_08_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_08
			{
				intensity=30000*1.5625;
			};
		};
	};
	class gjb_itn_illum_perst3_07_Hi: gjb_itn_illum_dbal_a2_07_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_07
			{
				intensity=30000*2.040816327;
			};
		};
	};
	class gjb_itn_illum_perst3_06_Hi: gjb_itn_illum_dbal_a2_06_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_06
			{
				intensity=30000*2.777777778;
			};
		};
	};
	class gjb_itn_illum_perst3_05_Hi: gjb_itn_illum_dbal_a2_05_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_05
			{
				intensity=30000*4;
			};
		};
	};
	class gjb_itn_illum_perst3_04_Hi: gjb_itn_illum_dbal_a2_04_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_04
			{
				intensity=30000*6.25;
			};
		};
	};
	class gjb_itn_illum_perst3_03_Hi: gjb_itn_illum_dbal_a2_03_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_03
			{
				intensity=30000*11.11111111;
			};
		};
	};
	class gjb_itn_illum_perst3_02_Hi: gjb_itn_illum_dbal_a2_02_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_02
			{
				intensity=30000*25;
			};
		};
	};
	class gjb_itn_illum_perst3_01_Hi: gjb_itn_illum_dbal_a2_01_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_01
			{
				intensity=30000*100;
			};
		};
	};
	class gjb_itn_illum_perst3_60_Hi: gjb_itn_illum_dbal_a2_60_Hi
	{
		class Reflectors
		{
			class Light_1: gjb_itn_irIllum_hi_60
			{
				intensity=30000*0.027777778;
			};
		};
	};
};