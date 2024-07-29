class CfgITNCompat
{
//Accessories
	class accessories
	{
		class acc_flashlight;
		class deviceBase_m952;
		class deviceBase_la5b;
		class deviceBase_la5b_comboWO;
		class deviceBase_la5b_comboVIR;
		class deviceBase_ngal;
		class deviceBase_ngal_comboWO;
		class deviceBase_ngal_comboVIR;
		//LA-5B
			//416
				class tier1_416_la5_side: deviceBase_la5b
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0288655,-0.00269817,0.0465966},
						{-0.0288655,-0.00269817,0.0465966},
						{0,0,0}
					};
					gjb_itn_interface[]=
					{
						"la_5b",
						"Rsc_gjb_itn_la5b_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\la5b"
					};
				};
				class tier1_416_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0153599,0.0354076,-0.0188075},
						{-0.0153599,0.0354076,-0.0188075},
						{0,0,0}
					};
				};
				class tier1_10_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0232429,-0.00247033,0.0487397}.
						{-0.0232429,-0.00247033,0.0487397},
						{0,0,0}
					};
				};
				class tier1_10_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0120955,0.0351256,-0.0202553},
						{0.0120955,0.0351256,-0.0202553},
						{0,0,0}
					};
				};
				
				class tier1_145_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0085097,-0.0028017,0.047992},
						{0.0085097,-0.0028017,0.047992},
						{0,0,0}
					};
				};
				class tier1_145_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.111622,0.035112,-0.0194642},
						{0.111622,0.035112,-0.0194642},
						{0,0,0}
					};
				};
				
				class tier1_rahg_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0388346,-0.00576312,0.0476472},
						{-0.0388346,-0.00576312,0.0476472},
						{0,0,0}
					};
				};
				class tier1_rahg_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0403469,0.0362124,-0.0200315},
						{0.0403469,0.0362124,-0.0200315},
						{0,0,0}
					};
				};
				
				class tier1_mw_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0109913,-0.00092106,0.0455972},
						{-0.0109913,-0.00092106,0.0455972},
						{0,0,0}
					};
				};
				class tier1_mw_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0521589,0.0359349,-0.0204251},
						{0.0521589,0.0359349,-0.0204251},
						{0,0,0}
					};
				};
			//M110
				class tier1_m110_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{ 
						{-0.0475459,-0.00612781,0.0431996},
						{-0.0475459,-0.00612781,0.0431996},
						{0,0,0}
					};
				};
				class tier1_m110_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00387348,0.0282069,-0.021707},
						{-0.00387348,0.0282069,-0.021707},
						{0,0,0}
					};
				};
			//URX
				class tier1_urx4_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0722105,-0.00258108,0.0420705},
						{-0.0722105,-0.00258108,0.0420705},
						{0,0,0}
					};
				};
				class tier1_urx4_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0568034,0.0370322,-0.0195405},
						{-0.0568034,0.0370322,-0.0195405},
						{0,0,0}
					};
				};
			//Generic
				class tier1_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0213354,-0.00294031,0.0474081},
						{-0.0213354,-0.00294031,0.0474081},
						{0,0,0}
					};
				};
				class tier1_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0221278,0.0355818,-0.0115478},
						{-0.0221278,0.0355818,-0.0115478},
						{0,0,0}
					};
				};
			//MCX
				class tier1_mcx_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00743416,0.000272393,0.0485158},
						{0.00743416,0.000272393,0.0485158},
						{0,0,0}
					};
				};
				class tier1_mcx_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0308951,0.036559,-0.0203245},
						{0.0308951,0.036559,-0.0203245},
						{0,0,0}
					};
				};
			//Mk46
				class tier1_mk46mod0_la5: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.024712,-0.00974968,0.0477747},
						{-0.024712,-0.00974968,0.0477747},
						{0,0,0}
					};
				};
				class tier1_mk46mod1_la5: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00130568,-0.00920804,0.0481283},
						{0.00130568,-0.00920804,0.0481283},
						{0,0,0}
					};
				};
			//SR25
				class tier1_sr25_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.018968,0.0837085,0.0219315},
						{-0.018968,0.0837085,0.0219315},
						{0,0,0}
					};
				};
				class tier1_sr25_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0149772,0.0524675,0.0889821},
						{0.0149772,0.0524675,0.0889821},
						{0,0,0}
					};
				};
			//M249
				class tier1_m249_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0392644,-0.00801082,0.0463547},
						{-0.0392644,-0.00801082,0.0463547},
						{0,0,0}
					};
				};
			//M4BII
				class tier1_mrbii_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0839444,-0.00338984,0.0503175},
						{-0.0839444,-0.00338984,0.0503175},
						{0,0,0}
					};
				
				};
				class tier1_m4bii_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0282443,0.0348798,-0.0131033},
						{-0.0282443,0.0348798,-0.0131033},
						{0,0,0}
					};
				
				};
			//Mk18
				class tier1_mk18_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.108229,0.0945437,0.027817},
						{-0.108229,0.0945437,0.027817},
						{0,0,0}
					};
				};
				class tier1_mk18_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0444262,0.0348623,-0.0132009},
						{-0.0444262,0.0348623,-0.0132009},
						{0,0,0}
					};
				};
			//MP7
				class tier1_mp7_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0500136,-0.00296758,0.0469617},
						{-0.0500136,-0.00296758,0.0469617},
						{0,0,0}
					};
				};
			//SCAR
				class tier1_scar_la5_side: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0199136,-0.00322341,0.0481844},
						{-0.0199136,-0.00322341,0.0481844},
						{0,0,0}	
					};
				};
				class tier1_scar_la5_top: tier1_416_la5_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0076767,0.0290649,-0.0313735},
						{-0.0076767,0.0290649,-0.0313735},
						{0,0,0}
					};
				};
		//LA-5B + WLO
			//416
				class tier1_416_la5_m300c_black: deviceBase_la5b_comboWO
				{
					gjb_itn_memoryPoints[]=
					{
						{0.012756,0.0354205,-0.0187512},
						{0.012756,0.0354205,-0.0187512},
						{-0.060012,0.000150987,0.0359144}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m300_bk"
					};
				};
				class tier1_416_la5_m300c_black_fl: tier1_416_la5_m300c_black{};
				class tier1_416_la5_m300c: tier1_416_la5_m300c_black
				{
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m300_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m300"
					};
				};
				class tier1_416_la5_m300c_fl: tier1_416_la5_m300c{};
				class tier1_10_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0475248,0.035179,-0.0203215},
						{0.0475248,0.035179,-0.0203215},
						{-0.0509138,0.0226827,0.0608635}
					};
				};
				class tier1_10_la5_m300c_fl: tier1_416_la5_m300c{};
				class tier1_145_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0130425,0.0350106,-0.0194744},
						{0.0130425,0.0350106,-0.0194744},
						{-0.0412302,-0.000508511,0.0372936}
					};
				};
				class tier1_145_la5_m300c_fl: tier1_416_la5_m300c{};
				class tier1_rahg_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0403509,0.0362124,-0.0200315},
						{0.0403509,0.0362124,-0.0200315},
						{-0.0314662,0.0185965,0.00887133}
					};
				};
				class tier1_rahg_la5_m300c_black_fl: tier1_416_la5_m300c_black{};
				class tier1_rahg_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0403509,0.0362124,-0.0200315},
						{0.0403509,0.0362124,-0.0200315},
						{-0.0314662,0.0185965,0.00887133}
					};
				};
				class tier1_rahg_la5_m300c_fl: tier1_416_la5_m300c{};
				class tier1_mw_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0518333,0.0359349,-0.0204251},
						{0.0518333,0.0359349,-0.0204251},
						{-0.00693307,0.0719587,0.011324}
					};
				};
				class tier1_mw_la5_m300c_black_fl: tier1_416_la5_m300c_black{};
				class tier1_mw_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0518333,0.0359349,-0.0204251},
						{0.0518333,0.0359349,-0.0204251},
						{-0.00693307,0.0719587,0.011324}
					};
				};
				class tier1_mw_la5_m300c_fl: tier1_416_la5_m300c{};
			//URX
				class tier1_urx4_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0606438,0.0370792,-0.0195224},
						{-0.0606438,0.0370792,-0.0195224},
						{-0.0549042,0.0212685,0.0565947}
					};
				};
				class tier1_urx4_la5_m300c_black_fl: tier1_urx4_la5_m300c_black{};
				class tier1_urx4_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0606438,0.0370792,-0.0195224},
						{-0.0606438,0.0370792,-0.0195224},
						{-0.0549042,0.0212685,0.0565947}
					};
				};
				class tier1_urx4_la5_m300c_fl: tier1_urx4_la5_m300c{};
			//MCX
				class tier1_mcx_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00115768,0.036559,-0.0203245},
						{0.00115768,0.036559,-0.0203245},
						{-0.0788808,0.091773,0.0371695}
					};
				};
				class tier1_mcx_la5_m300c_black_fl: tier1_mcx_la5_m300c_black{};
				class tier1_mcx_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00115768,0.036559,-0.0203245},
						{0.00115768,0.036559,-0.0203245},
						{-0.0788808,0.091773,0.0371695}
					};
				};
				class tier1_mcx_la5_m300c_fl: tier1_mcx_la5_m300c{};
			//M4BII
				class tier1_m4bii_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0177866,0.0348347,-0.0130905},
						{-0.0177866,0.0348347,-0.0130905},
						{-0.104678,0.0191135,0.0128317}
					};
				};
				class tier1_m4bii_la5_m300c_black_fl: tier1_m4bii_la5_m300c_black{};
				class tier1_m4bii_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0177866,0.0348347,-0.0130905},
						{-0.0177866,0.0348347,-0.0130905},
						{-0.104678,0.0191135,0.0128317}
					};
				};
				class tier1_m4bii_la5_m300c_fl: tier1_m4bii_la5_m300c{};
			//Mk18
				class tier1_mk18_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0177866,0.0348347,-0.0130905},
						{-0.0177866,0.0348347,-0.0130905},
						{-0.104678,0.0191135,0.0128317}
					};
				};
				class tier1_mk18_la5_m300c_black_fl: tier1_mk18_la5_m300c_black{};
				class tier1_mk18_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0177866,0.0348347,-0.0130905},
						{-0.0177866,0.0348347,-0.0130905},
						{-0.104678,0.0191135,0.0128317}
					};
				};
				class tier1_mk18_la5_m300c_fl: tier1_mk18_la5_m300c{};
			//MP7
				class tier1_mp7_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0501736,-0.00308584,0.0470613},
						{-0.0501736,-0.00308584,0.0470613},
						{-0.0618781,0.0762627,0.0357726}
					};
				};
				class tier1_mp7_la5_m300c_black_fl: tier1_mp7_la5_m300c_black{};
				class tier1_mp7_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0501736,-0.00308584,0.0470613},
						{-0.0501736,-0.00308584,0.0470613},
						{-0.0618781,0.0762627,0.0357726}
					};
				};
				class tier1_mp7_la5_m300c_fl: tier1_mp7_la5_m300c{};
			//SCAR
				class tier1_scar_la5_m300c_black: tier1_416_la5_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00861876,0.0290461,-0.0314313},
						{-0.00861876,0.0290461,-0.0314313},
						{-0.0369802,-0.000734123,0.0366561}
					};
				};
				class tier1_scar_la5_m300c_black_fl: tier1_scar_la5_m300c_black{};
				class tier1_scar_la5_m300c: tier1_416_la5_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00861876,0.0290461,-0.0314313},
						{-0.00861876,0.0290461,-0.0314313},
						{-0.0369802,-0.000734123,0.0366561}
					};
				};
				class tier1_scar_la5_m300c_fl: tier1_scar_la5_m300c{};
		//LA-5B + VIR
			//416
				class tier1_416_la5_m600v_black: deviceBase_la5b_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0521813,0.0354595,-0.0187664},
						{0.0521813,0.0354595,-0.0187664},
						{-0.0785466,0.00847028,0.00878875}
					};
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m600_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m600_bk"
					};
				};
				class tier1_416_la5_m600v_black_fl: tier1_416_la5_m600v_black{};
				class tier1_416_la5_m600v_alt_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0288655,-0.00269817,0.0465966},
						{-0.0288655,-0.00269817,0.0465966},
						{-0.0655765,0.0926146,0.0356674}
					};
				};
				class tier1_416_la5_m600v_alt_black_fl: tier1_416_la5_m600v_alt_black{};
				class tier1_416_la5_m600v: tier1_416_la5_m600v_black
				{
					gjb_itn_interface[]=
					{
						"la_5b_combo",
						"Rsc_gjb_itn_la5b_m600_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\la5b",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m600"
					};
				};
				class tier1_416_la5_m600v_fl: tier1_416_la5_m600v{};
				class tier1_416_la5_m600v_alt: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0288655,-0.00269817,0.0465966},
						{-0.0288655,-0.00269817,0.0465966},
						{-0.0655765,0.0926146,0.0356674}
					};
				};
				class tier1_416_la5_m600v_alt_fl: tier1_416_la5_m600v_alt{};
				class tier1_416_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0268231,0.0353894,-0.0187},
						{0.0268231,0.0353894,-0.0187},
						{-0.0509244,0.0217628,0.0598447}
					};
				};
				class tier1_416_la5_m603v_fl: tier1_416_la5_m603v{};
				class tier1_10_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0204557,0.0351977,-0.020273},
						{0.0204557,0.0351977,-0.020273},
						{-0.029433,0.0215844,0.0143973}
					};
				};
				class tier1_10_la5_m600v_fl: tier1_10_la5_m600v{};
				class tier1_10_la5_m600v_alt: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0132132,0.0352492,-0.0203854},
						{-0.0132132,0.0352492,-0.0203854},
						{-0.0834876,0.093397,0.0371483}
					};
				};
				class tier1_10_la5_m600v_alt_fl: tier1_10_la5_m600v_alt{};
				class tier1_10_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0144366,0.0351981,-0.0204464},
						{0.0144366,0.0351981,-0.0204464},
						{-0.0305696,0.0710305,0.0140885}
					};
				};
				class tier1_10_la5_m603v_fl: tier1_10_la5_m603v{};
				class tier1_145_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0879421,0.0350615,-0.0193985},
						{0.0879421,0.0350615,-0.0193985},
						{-0.0132468,0.00787314,0.0106148}
					};
				};
				class tier1_145_la5_m600v_fl: tier1_145_la5_m600v{};
				class tier1_145_la5_m600v_alt: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0595627,0.0351254,-0.0194651},
						{0.0595627,0.0351254,-0.0194651},
						{-0.0273267,0.0702756,0.060079}
					};
				};
				class tier1_145_la5_m600v_alt_fl: tier1_145_la5_m600v_alt{};
				class tier1_145_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0971043,0.0350984,-0.0195252},
						{0.0971043,0.0350984,-0.0195252},
						{-0.0168056,0.0226721,0.060939}
					};
				};
				class tier1_145_la5_m603v_fl: tier1_145_la5_m603v{};
				class tier1_rahg_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00826948,0.0362124,-0.0200315},
						{0.00826948,0.0362124,-0.0200315},
						{-0.00897654,0.0193821,0.0637837}
					};
				};
				class tier1_rahg_la5_m600v_black_fl: tier1_rahg_la5_m600v_black{};
				class tier1_rahg_la5_m600v_alt_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.024174,0.0362124,-0.0200315},
						{0.024174,0.0362124,-0.0200315},
						{-0.0564661,-0.00313045,0.0360382}
					};
				};
				class tier1_rahg_la5_m600v_alt_black_fl: tier1_rahg_la5_m600v_alt_black{};
				class tier1_rahg_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00826948,0.0362124,-0.0200315},
						{0.00826948,0.0362124,-0.0200315},
						{-0.00897654,0.0193821,0.0637837}
					};
				};
				class tier1_rahg_la5_m600v_fl: tier1_rahg_la5_m600v{};
				class tier1_rahg_la5_m600v_alt: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.024174,0.0362124,-0.0200315},
						{0.024174,0.0362124,-0.0200315},
						{-0.0564661,-0.00313045,0.0360382}
					};
				};
				class tier1_rahg_la5_m600v_alt_fl: tier1_rahg_la5_m600v_alt{};
				class tier1_rahg_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0452686,0.0362124,-0.0200315},
						{0.0452686,0.0362124,-0.0200315},
						{-0.0677667,0.072479,0.0118945}
					};
				};
				class tier1_rahg_la5_m603v_fl: tier1_rahg_la5_m603v{};
				class tier1_mw_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0518333,0.0359349,-0.0204251},
						{0.0518333,0.0359349,-0.0204251},
						{-0.00693307,0.0719587,0.011324}
					};
				};
				class tier1_mw_la5_m600v_black_fl: tier1_mw_la5_m600v_black{};
				class tier1_mw_la5_m600v_alt_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00845858,0.0359349,-0.0204251},
						{-0.00845858,0.0359349,-0.0204251},
						{-0.0395113,0.00122928,0.0342505}
					};
				};
				class tier1_mw_la5_m600v_alt_black_fl: tier1_mw_la5_m600v_alt_black{};
				class tier1_mw_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0518333,0.0359349,-0.0204251},
						{0.0518333,0.0359349,-0.0204251},
						{-0.00693307,0.0719587,0.011324}
					};
				};
				class tier1_mw_la5_m600v_fl: tier1_mw_la5_m600v{};
				class tier1_mw_la5_m600v_alt: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00845858,0.0359349,-0.0204251},
						{-0.00845858,0.0359349,-0.0204251},
						{-0.0395113,0.00122928,0.0342505}
					};
				};
				class tier1_mw_la5_m600v_alt_fl: tier1_mw_la5_m600v_alt{};
				class tier1_mw_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0516855,0.0359349,-0.0204251},
						{0.0516855,0.0359349,-0.0204251},
						{-0.00982604,0.0209097,0.0110778}
					};
				};
				class tier1_mw_la5_m603v_fl: tier1_mw_la5_m603v{};
			//URX
				class tier1_urx4_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.035224,0.0370707,-0.0195783},
						{0.035224,0.0370707,-0.0195783},
						{-0.0728377,0.0736394,0.00928361}
					};
				};
				class tier1_urx4_la5_m600v_black_fl: tier1_urx4_la5_m600v_black{};
				class tier1_urx4_la5_m600v_alt_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0539806,0.0370914,-0.019606},
						{0.0539806,0.0370914,-0.019606},
						{-0.064435,0.0209798,0.00547014}
					};
				};
				class tier1_urx4_la5_m600v_alt_black_fl: tier1_urx4_la5_m600v_alt_black{};
				class tier1_urx4_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.035224,0.0370707,-0.0195783},
						{0.035224,0.0370707,-0.0195783},
						{-0.0728377,0.0736394,0.00928361}
					};
				};
				class tier1_urx4_la5_m600v_fl: tier1_urx4_la5_m600v{};
				class tier1_urx4_la5_m600v_alt: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0539806,0.0370914,-0.019606},
						{0.0539806,0.0370914,-0.019606},
						{-0.064435,0.0209798,0.00547014}
					};
				};
				class tier1_urx4_la5_m600v_alt_fl: tier1_urx4_la5_m600v_alt{};
				class tier1_urx4_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0237956,0.0370485,-0.0195562},
						{-0.0237956,0.0370485,-0.0195562},
						{-0.0736651,-0.000867062,0.0309868}
					};
				};
				class tier1_urx4_la5_m603v_fl: tier1_urx4_la5_m603v{};
			//MCX
				class tier1_mcx_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0326394,0.036559,-0.0203245},
						{-0.0326394,0.036559,-0.0203245},
						{-0.0593496,0.0105116,0.0107884}
					};
				};
				class tier1_mcx_la5_m600v_black_fl: tier1_mcx_la5_m600v_black{};
				class tier1_mcx_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0326394,0.036559,-0.0203245},
						{-0.0326394,0.036559,-0.0203245},
						{-0.0593496,0.0105116,0.0107884}
					};
				};
				class tier1_mcx_la5_m600v_fl: tier1_mcx_la5_m600v{};
				class tier1_mcx_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0793478,0.036559,-0.0203245},
						{0.0793478,0.036559,-0.0203245},
						{-0.0408045,0.00228633,0.0371629}
					};
				};
				class tier1_mcx_la5_m603v_fl: tier1_mcx_la5_m603v{};
			//Mk46
				class tier1_mk46mod0_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.044617,-0.00976438,0.0476685},
						{-0.044617,-0.00976438,0.0476685},
						{-0.0939369,0.101238,0.0365416}
					};
				};
				class tier1_mk46mod0_la5_m600v_black_fl: tier1_mk46mod0_la5_m600v_black{};
				class tier1_mk46mod0_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.044617,-0.00976438,0.0476685},
						{-0.044617,-0.00976438,0.0476685},
						{-0.0939369,0.101238,0.0365416}
					};
				};
				class tier1_mk46mod0_la5_m600v_fl: tier1_mk46mod0_la5_m600v{};
				class tier1_mk46mod0_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0454325,0.103275,0.0251436},
						{-0.0454325,0.103275,0.0251436},
						{-0.0826398,-0.00736044,0.0366674}
					};
				};
				class tier1_mk46mod0_la5_m603v_fl: tier1_mk46mod0_la5_m603v{};
				class tier1_mk46mod1_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0144236,-0.00929693,0.0481779},
						{-0.0144236,-0.00929693,0.0481779},
						{-0.0830047,0.100735,0.0373067}
					};
				};
				class tier1_mk46mod1_la5_m600v_black_fl: tier1_mk46mod1_la5_m600v_black{};
				class tier1_mk46mod1_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0144236,-0.00929693,0.0481779},
						{-0.0144236,-0.00929693,0.0481779},
						{-0.0830047,0.100735,0.0373067}
					};
				};
				class tier1_mk46mod1_la5_m600v_fl: tier1_mk46mod1_la5_m600v{};
				class tier1_mk46mod1_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00341121,-0.00920683,0.0481594},
						{0.00341121,-0.00920683,0.0481594},
						{-0.0756435,0.100784,0.0361412}
					};
				};
				class tier1_mk46mod1_la5_m603v_fl: tier1_mk46mod1_la5_m603v{};
			//M249
				class tier1_m249_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0393765,-0.00798172,0.046351},
						{-0.0393765,-0.00798172,0.046351},
						{-0.0606253,0.0959808,0.0356036}
					};
				};
				class tier1_m249_la5_m600v_black_fl: tier1_m249_la5_m600v_black{};
				class tier1_m249_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0393765,-0.00798172,0.046351},
						{-0.0393765,-0.00798172,0.046351},
						{-0.0606253,0.0959808,0.0356036}
					};
				};
				class tier1_m249_la5_m600v_fl: tier1_m249_la5_m600v{};
				class tier1_m249_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0391247,0.0989647,0.0240936},
						{-0.0391247,0.0989647,0.0240936},
						{-0.0734171,-0.00590394,0.0357323}
					};
				};
				class tier1_m249_la5_m603v_fl: tier1_m249_la5_m603v{};
			//M4BII
				class tier1_m4bii_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0274617,0.0348925,-0.0131077},
						{-0.0274617,0.0348925,-0.0131077},
						{-0.101735,0.021206,0.0650218}
					};
				};
				class tier1_m4bii_la5_m600v_black_fl: tier1_m4bii_la5_m600v_black{};
				class tier1_m4bii_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0274617,0.0348925,-0.0131077},
						{-0.0274617,0.0348925,-0.0131077},
						{-0.101735,0.021206,0.0650218}
					};
				};
				class tier1_m4bii_la5_m600v_fl: tier1_m4bii_la5_m600v{};
				class tier1_m4bii_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0582405,0.0348403,-0.013153},
						{0.0582405,0.0348403,-0.013153},
						{-0.112448,0.0922458,0.0396592}
					};
				};
				class tier1_m4bii_la5_m603v_fl: tier1_m4bii_la5_m603v{};
			//Mk18
				class tier1_mk18_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0440359,0.0348925,-0.0131652},
						{-0.0440359,0.0348925,-0.0131652},
						{-0.140559,0.021206,0.0650218}
					};
				};
				class tier1_mk18_la5_m600v_black_fl: tier1_mk18_la5_m600v_black{};
				class tier1_mk18_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0440359,0.0348925,-0.0131652},
						{-0.0440359,0.0348925,-0.0131652},
						{-0.140559,0.021206,0.0650218}
					};
				};
				class tier1_mk18_la5_m600v_fl: tier1_mk18_la5_m600v{};
				class tier1_mk18_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.10879,0.0945622,0.0277884},
						{-0.10879,0.0945622,0.0277884},
						{-0.117232,0.0185277,0.0139112}
					};
				};
				class tier1_mk18_la5_m603v_fl: tier1_mk18_la5_m603v{};
			//SCAR
				class tier1_scar_la5_m600v_black: tier1_416_la5_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0144691,0.0290659,-0.031452},
						{0.0144691,0.0290659,-0.031452},
						{-0.0675734,0.00706632,0.00969443}
					};
				};
				class tier1_scar_la5_m600v_black_fl: tier1_scar_la5_m600v_black{};
				class tier1_scar_la5_m600v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0144691,0.0290659,-0.031452},
						{0.0144691,0.0290659,-0.031452},
						{-0.0675734,0.00706632,0.00969443}
					};
				};
				class tier1_scar_la5_m600v_fl: tier1_scar_la5_m600v{};
				class tier1_scar_la5_m603v: tier1_416_la5_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0511745,0.0290492,-0.0315015},
						{0.0511745,0.0290492,-0.0315015},
						{-0.0480705,0.0818438,0.0367109}
					};
				};
				class tier1_scar_la5_m603v_fl: tier1_scar_la5_m603v{};
		//NGAL
			//URX
				class tier1_urx4_ngal_side: deviceBase_ngal
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0572441,0.00167982,0.0469005},
						{-0.0572441,0.00167982,0.0469005},
						{0,0,0}
					};
					gjb_itn_interface[]=
					{
						"ngal",
						"Rsc_gjb_itn_ngal_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal"
					};
				};
				class tier1_urx4_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0517288,0.0308318,-0.0155181},
						{-0.0517288,0.0308318,-0.0155181},
						{0,0,0}
					};
				};
			//416
				class tier1_10_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0193995,0.000944191,0.0533609},
						{-0.0193995,0.000944191,0.0533609},
						{0,0,0}
					};
				};
				class tier1_10_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0253539,0.0299531,-0.0152328},
						{0.0253539,0.0299531,-0.0152328},
						{0,0,0}
					};
				};
				
				class tier1_145_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0164937,0.0013558,0.0527423},
						{0.0164937,0.0013558,0.0527423},
						{0,0,0}
					};
				};
				class tier1_145_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.118238,0.0306533,-0.0156015},
						{0.118238,0.0306533,-0.0156015},
						{0,0,0}
					};
				};
				class tier1_rahg_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0241293,-0.00094636,0.0522262},
						{-0.0241293,-0.00094636,0.0522262},
						{0,0,0}
					};
				};
				class tier1_rahg_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0430981,0.0304633,-0.0154429},
						{0.0430981,0.0304633,-0.0154429},
						{0,0,0}
					};
				};
				class tier1_mw_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0061742,0.00309694,0.050495},
						{-0.0061742,0.00309694,0.050495},
						{0,0,0}
					};
				};
				class tier1_mw_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0628886,0.0306538,-0.0159605},
						{0.0628886,0.0306538,-0.0159605},
						{0,0,0}
					};
				};
			//MCX
				class tier1_mcx_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.01731,0.00444287,0.0532575},
						{0.01731,0.00444287,0.0532575},
						{0,0,0}
					};
				};
				class tier1_mcx_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0459238,0.0312579,-0.0156926},
						{0.0459238,0.0312579,-0.0156926},
						{0,0,0}
					};
				};
			//M4BII
				class tier1_m4bii_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0678952,0.0015218,0.054902},
						{-0.0678952,0.0015218,0.054902},
						{0,0,0}
					};
				};
				class tier1_m4bii_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0125513,0.0300782,-0.00850804},
						{-0.0125513,0.0300782,-0.00850804},
						{0,0,0}
					};
				};
			//Mk18
				class tier1_mk18_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.10819,0.00153461,0.0548294},
						{-0.10819,0.00153461,0.0548294},
						{0,0,0}
					};
				};
				class tier1_mk18_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0283153,0.0300335,-0.00854522},
						{-0.0283153,0.0300335,-0.00854522},
						{0,0,0}
					};
				};
			//MP7
				class tier1_mp7_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0446099,0.00108545,0.0520079},
						{-0.0446099,0.00108545,0.0520079},
						{0,0,0}
					};
				};
			//Generic
				class tier1_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.019092,0.00105236,0.0523028},
						{-0.019092,0.00105236,0.0523028},
						{0,0,0}
					};
				};
				class tier1_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0133816,0.0299939,-0.00844199},
						{-0.0133816,0.0299939,-0.00844199},
						{0,0,0}
					};
				};
			//SCAR
				class tier1_scar_ngal_side: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00556123,0.00110042,0.052819},
						{-0.00556123,0.00110042,0.052819},
						{0,0,0}
					};
				};
				class tier1_scar_ngal_top: tier1_urx4_ngal_side
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00556865,0.0245738,-0.0270121},
						{0.00556865,0.0245738,-0.0270121},
						{0,0,0}
					};
				};
		//NGAL + WLO
			//URX
				class tier1_urx4_ngal_m300c_black: deviceBase_ngal_comboWO
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0510026,0.0308318,-0.0155181},
						{-0.0510026,0.0308318,-0.0155181},
						{-0.0549042,0.0212685,0.0565947}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m300_bk"
					};
				};
				class tier1_urx4_ngal_m300c_black_fl: tier1_urx4_ngal_m300c_black{};
				class tier1_urx4_ngal_m300c: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m300_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m300"
					};
				};
				class tier1_urx4_ngal_m300c_fl: tier1_urx4_ngal_m300c{};
			//416
				class tier1_10_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0665275,0.0300521,-0.0152539},
						{0.0665275,0.0300521,-0.0152539},
						{-0.0509138,0.0226827,0.0608635}
					};
				};
				class tier1_10_ngal_m300c_fl: tier1_10_ngal_m300c{};
				class tier1_145_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0208925,0.0306997,-0.0156266},
						{0.0208925,0.0306997,-0.0156266},
						{-0.0412302,-0.000508511,0.0372936}
					};
				};
				class tier1_145_ngal_m300c_fl: tier1_10_ngal_m300c{};
				class tier1_rahg_ngal_m300c_black: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0519476,0.0304834,-0.0154291},
						{0.0519476,0.0304834,-0.0154291},
						{-0.0314662,0.0185965,0.00887133}
					};
				};
				class tier1_rahg_ngal_m300c_black_fl: tier1_rahg_ngal_m300c_black{};
				class tier1_rahg_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0519476,0.0304834,-0.0154291},
						{0.0519476,0.0304834,-0.0154291},
						{-0.0314662,0.0185965,0.00887133}
					};
				};
				class tier1_rahg_ngal_m300c_fl: tier1_rahg_ngal_m300c{};
				class tier1_mw_ngal_m300c_black: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0593581,0.0306251,-0.0159578},
						{0.0593581,0.0306251,-0.0159578},
						{-0.00693307,0.0719587,0.011324}
					};
				};
				class tier1_mw_ngal_m300c_black_fl: tier1_mw_ngal_m300c_black{};
				class tier1_mw_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0593581,0.0306251,-0.0159578},
						{0.0593581,0.0306251,-0.0159578},
						{-0.00693307,0.0719587,0.011324}
					};
				};
				class tier1_mw_ngal_m300c_fl: tier1_mw_ngal_m300c{};
			//MCX
				class tier1_mcx_ngal_m300c_black: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00615625,0.0312579,-0.0156926},
						{0.00615625,0.0312579,-0.0156926},
						{-0.0788808,0.091773,0.0371695}
					};
				};
				class tier1_mcx_ngal_m300c_black_fl: tier1_urx4_ngal_m300c_black{};
				class tier1_mcx_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{0.00615625,0.0312579,-0.0156926},
						{0.00615625,0.0312579,-0.0156926},
						{-0.0788808,0.091773,0.0371695}
					};
				};
				class tier1_mcx_ngal_m300c_fl: tier1_mcx_ngal_m300c{};
			//M4BII
				class tier1_m4bii_ngal_m300c_black: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0249764,0.0300334,-0.00849086},
						{-0.0249764,0.0300334,-0.00849086},
						{-0.104678,0.0191135,0.0128317}
					};
				};
				class tier1_m4bii_ngal_m300c_black_fl: tier1_m4bii_ngal_m300c_black{};
				class tier1_m4bii_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0249764,0.0300334,-0.00849086},
						{-0.0249764,0.0300334,-0.00849086},
						{-0.104678,0.0191135,0.0128317}
					};
				};
				class tier1_m4bii_ngal_m300c_fl: tier1_m4bii_ngal_m300c{};
			//Mk18
				class tier1_mk18_ngal_m300c_black: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0491978,0.0300605,-0.00847237},
						{-0.0491978,0.0300605,-0.00847237},
						{-0.124295,-0.000789752,0.0391851}
					};
				};
				class tier1_mk18_ngal_m300c_black_fl: tier1_mk18_ngal_m300c_black{};
				class tier1_mk18_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0491978,0.0300605,-0.00847237},
						{-0.0491978,0.0300605,-0.00847237},
						{-0.124295,-0.000789752,0.0391851}
					};
				};
				class tier1_mk18_ngal_m300c_fl: tier1_mk18_ngal_m300c{};
			//MP7
				class tier1_mp7_ngal_m300c_black: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0446585,0.0010463,0.0519823},
						{-0.0446585,0.0010463,0.0519823},
						{-0.0618781,0.0762627,0.0357726}
					};
				};
				class tier1_mp7_ngal_m300c_black_fl: tier1_mp7_ngal_m300c_black{};
				class tier1_mp7_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0446585,0.0010463,0.0519823},
						{-0.0446585,0.0010463,0.0519823},
						{-0.0618781,0.0762627,0.0357726}
					};
				};
				class tier1_mp7_ngal_m300c_fl: tier1_mp7_ngal_m300c{};
			//SCAR
				class tier1_scar_ngal_m300c_black: tier1_urx4_ngal_m300c_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00460956,0.0245651,-0.0270029},
						{-0.00460956,0.0245651,-0.0270029},
						{-0.0369802,-0.000734123,0.0366561}
					};
				};
				class tier1_scar_ngal_m300c_black_fl: tier1_scar_ngal_m300c_black{};
				class tier1_scar_ngal_m300c: tier1_urx4_ngal_m300c
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00460956,0.0245651,-0.0270029},
						{-0.00460956,0.0245651,-0.0270029},
						{-0.0369802,-0.000734123,0.0366561}
					};
				};
				class tier1_scar_ngal_m300c_fl: tier1_scar_ngal_m300c{};
		//NGAL + VIR
			//URX
				class tier1_urx4_ngal_m600v_black: deviceBase_ngal_comboVIR
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0401073,0.0308318,-0.0155181},
						{0.0401073,0.0308318,-0.0155181},
						{-0.0728377,0.0736394,0.00928361}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m600_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m600_bk"
					};
				};
				class tier1_urx4_ngal_m600v_black_fl: tier1_urx4_ngal_m600v_black{};
				class tier1_urx4_ngal_m600v_alt_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0973445,0.0308318,-0.0155181},
						{0.0973445,0.0308318,-0.0155181},
						{-0.064435,0.0209798,0.00547014}
					};
				};
				class tier1_urx4_ngal_m600v_alt_black_fl: tier1_urx4_ngal_m600v_alt_black{};
				class tier1_urx4_ngal_m600v: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0401073,0.0308318,-0.0155181},
						{0.0401073,0.0308318,-0.0155181},
						{-0.0728377,0.0736394,0.00928361}
					};
					gjb_itn_interface[]=
					{
						"ngal_combo",
						"Rsc_gjb_itn_ngal_m600_t1",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\ngal",
						"\gjb_itn\addons\gjb_itn_compat_t1\ui\m600"
					};
				};
				class tier1_urx4_ngal_m600v_fl: tier1_urx4_ngal_m600v{};
				class tier1_urx4_ngal_m600v_alt: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0973445,0.0308318,-0.0155181},
						{0.0973445,0.0308318,-0.0155181},
						{-0.064435,0.0209798,0.00547014}
					};
				};
				class tier1_urx4_ngal_m600v_alt_fl: tier1_urx4_ngal_m600v_alt{};
				class tier1_urx4_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.00920408,0.0308318,-0.0155181},
						{-0.00920408,0.0308318,-0.0155181},
						{-0.0736651,-0.000867062,0.0309868}
					};
				};
				class tier1_urx4_ngal_m603v_fl: tier1_urx4_ngal_m603v{};
			//416
				class tier1_10_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0379181,0.0300516,-0.0152308},
						{0.0379181,0.0300516,-0.0152308},
						{-0.029433,0.0215844,0.0143973}
					};
				};
				class tier1_10_ngal_m600v_fl: tier1_urx4_ngal_m600v{};
				class tier1_10_ngal_m600v_alt: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.000563978,0.0300494,-0.0152503},
						{-0.000563978,0.0300494,-0.0152503},
						{-0.0834876,0.093397,0.0371483}
					};
				};
				class tier1_10_ngal_m600v_alt_fl: tier1_urx4_ngal_m600v_alt{};
				class tier1_10_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0297284,0.0299599,-0.015243},
						{0.0297284,0.0299599,-0.015243},
						{-0.0308148,0.0710305,0.0140885}
					};
				};
				class tier1_10_ngal_m603v_fl: tier1_urx4_ngal_m603v{};
				class tier1_145_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.119171,0.0306634,-0.0156027},
						{0.119171,0.0306634,-0.0156027},
						{-0.0132468,0.00787314,0.0106148}
					};
				};
				class tier1_145_ngal_m600v_fl: tier1_urx4_ngal_m600v{};
				class tier1_145_ngal_m600v_alt: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0730331,0.0306415,-0.0156401},
						{0.0730331,0.0306415,-0.0156401},
						{-0.0273267,0.0702756,0.060079}
					};
				};
				class tier1_145_ngal_m600v_alt_fl: tier1_urx4_ngal_m600v_alt{};
				class tier1_145_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0928999,0.0305963,-0.0155659},
						{0.0928999,0.0305963,-0.0155659},
						{-0.0165923,0.0226721,0.060939}
					};
				};
				class tier1_145_ngal_m603v_fl: tier1_urx4_ngal_m603v{};
				class tier1_rahg_ngal_m600v_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.026046,0.0304361,-0.0154133},
						{0.026046,0.0304361,-0.0154133},
						{-0.00897654,0.0193821,0.0637837}
					};
				};
				class tier1_rahg_ngal_m600v_black_fl: tier1_rahg_ngal_m600v_black{};
				class tier1_rahg_ngal_m600v_alt_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0349339,0.0305365,-0.0154338},
						{0.0349339,0.0305365,-0.0154338},
						{-0.0564661,-0.00313045,0.0360382}
					};
				};
				class tier1_rahg_ngal_m600v_alt_black_fl: tier1_rahg_ngal_m600v_alt_black{};
				class tier1_rahg_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.026046,0.0304361,-0.0154133},
						{0.026046,0.0304361,-0.0154133},
						{-0.00897654,0.0193821,0.0637837}
					};
				};
				class tier1_rahg_ngal_m600v_fl: tier1_rahg_ngal_m600v{};
				class tier1_rahg_ngal_m600v_alt: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0349339,0.0305365,-0.0154338},
						{0.0349339,0.0305365,-0.0154338},
						{-0.0564661,-0.00313045,0.0360382}
					};
				};
				class tier1_rahg_ngal_m600v_alt_fl: tier1_rahg_ngal_m600v_alt{};
				class tier1_rahg_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0503029,0.0304379,-0.0153683},
						{0.0503029,0.0304379,-0.0153683},
						{-0.0677667,0.072479,0.0118945}
					};
				};
				class tier1_rahg_ngal_m603v_fl: tier1_rahg_ngal_m603v{};
				class tier1_mw_ngal_m600v_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0592224,0.0305931,-0.0160287},
						{0.0592224,0.0305931,-0.0160287},
						{-0.0223059,0.0214533,0.0574472}
					};
				};
				class tier1_mw_ngal_m600v_black_fl: tier1_mw_ngal_m600v_black{};
				class tier1_mw_ngal_m600v_alt_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.000342596,0.0306039,-0.0159329},
						{0.000342596,0.0306039,-0.0159329},
						{-0.0395113,0.00122928,0.0342505}
					};
				};
				class tier1_mw_ngal_m600v_alt_black_fl: tier1_mw_ngal_m600v_alt_black{};
				class tier1_mw_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0592224,0.0305931,-0.0160287},
						{0.0592224,0.0305931,-0.0160287},
						{-0.0223059,0.0214533,0.0574472}
					};
				};
				class tier1_mw_ngal_m600v_fl: tier1_mw_ngal_m600v{};
				class tier1_mw_ngal_m600v_alt: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.000342596,0.0306039,-0.0159329},
						{0.000342596,0.0306039,-0.0159329},
						{-0.0395113,0.00122928,0.0342505}
					};
				};
				class tier1_mw_ngal_m600v_alt_fl: tier1_mw_ngal_m600v_alt{};
				class tier1_mw_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0631228,0.0306386,-0.0159274},
						{0.0631228,0.0306386,-0.0159274},
						{-0.00982604,0.0209097,0.0110778}
					};
				};
				class tier1_mw_ngal_m603v_fl: tier1_mw_ngal_m603v{};
			//MCX
				class tier1_mcx_ngal_m600v_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.020742,0.0312579,-0.0156926},
						{-0.020742,0.0312579,-0.0156926},
						{-0.0591031,0.0105222,0.0107852}
					};
				};
				class tier1_mcx_ngal_m600v_black_fl: tier1_urx4_ngal_m600v_black{};
				class tier1_mcx_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.020742,0.0312579,-0.0156926},
						{-0.020742,0.0312579,-0.0156926},
						{-0.0591031,0.0105222,0.0107852}
					};
				};
				class tier1_mcx_ngal_m600v_fl: tier1_urx4_ngal_m600v{};
				class tier1_mcx_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0742222,0.0312579,-0.0156926},
						{0.0742222,0.0312579,-0.0156926},
						{-0.0404222,0.00226324,0.0371946}
					};
				};
				class tier1_mcx_ngal_m603v_fl: tier1_mcx_ngal_m603v{};
			//M4BII
				class tier1_m4bii_ngal_m600v_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0198028,0.0300817,-0.00851769},
						{-0.0198028,0.0300817,-0.00851769},
						{-0.101735,0.021206,0.0650218}
					};
				};
				class tier1_m4bii_ngal_m600v_black_fl: tier1_m4bii_ngal_m600v_black{};
				class tier1_m4bii_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0198028,0.0300817,-0.00851769},
						{-0.0198028,0.0300817,-0.00851769},
						{-0.101735,0.021206,0.0650218}
					};
				};
				class tier1_m4bii_ngal_m600v_fl: tier1_m4bii_ngal_m600v{};
				class tier1_m4bii_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0732204,0.0299759,-0.00844315},
						{0.0732204,0.0299759,-0.00844315},
						{-0.112448,0.0922458,0.0396592}
					};
				};
				class tier1_m4bii_ngal_m603v_fl: tier1_m4bii_ngal_m603v{};
			//Mk18
				class tier1_mk18_ngal_m600v_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0224435,0.0300376,-0.00852329},
						{-0.0224435,0.0300376,-0.00852329},
						{-0.140647,0.021206,0.0650218}
					};
				};
				class tier1_mk18_ngal_m600v_black_fl: tier1_mk18_ngal_m600v_black{};
				class tier1_mk18_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0224435,0.0300376,-0.00852329},
						{-0.0224435,0.0300376,-0.00852329},
						{-0.140647,0.021206,0.0650218}
					};
				};
				class tier1_mk18_ngal_m600v_fl: tier1_mk18_ngal_m600v{};
				class tier1_mk18_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{-0.0600206,0.0908081,0.023282},
						{-0.0600206,0.0908081,0.023282},
						{-0.117666,0.0184714,0.014013}
					};
				};
				class tier1_mk18_ngal_m603v_fl: tier1_mk18_ngal_m603v{};
			//SCAR
				class tier1_scar_ngal_m600v_black: tier1_urx4_ngal_m600v_black
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0214728,0.0245453,-0.0270006},
						{0.0214728,0.0245453,-0.0270006},
						{-0.0675734,0.00706632,0.00969443}
					};
				};
				class tier1_scar_ngal_m600v_black_fl: tier1_scar_ngal_m600v_black{};
				class tier1_scar_ngal_m600v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.0214728,0.0245453,-0.0270006},
						{0.0214728,0.0245453,-0.0270006},
						{-0.0675734,0.00706632,0.00969443}
					};
				};
				class tier1_scar_ngal_m600v_fl: tier1_scar_ngal_m600v{};
				class tier1_scar_ngal_m603v: tier1_urx4_ngal_m600v
				{
					gjb_itn_memoryPoints[]=
					{
						{0.063871,0.0245044,-0.027077},
						{0.063871,0.0245044,-0.027077},
						{-0.0480705,0.0818438,0.0367109}
					};
				};
				class tier1_scar_ngal_m603v_fl: tier1_scar_ngal_m603v{};
		//WLO
			class tier1_m300c_black: acc_flashlight
			{
				gjb_itn_memoryPoints[]=
				{
					{0,0,0},
					{0,0,0},
					{-0.0457503,-0.000177877,0.0362947}
				};
				gjb_itn_interface[]=
				{
					"utg",
					"Rsc_gjb_itn_m300_ti",
					"\gjb_itn\addons\gjb_itn_compat_t1\ui\m300_bk"
				};
			};
			class tier1_m300c: tier1_m300c_black
			{
				gjb_itn_interface[]=
				{
					"utg",
					"Rsc_gjb_itn_m300_ti",
					"\gjb_itn\addons\gjb_itn_compat_t1\ui\m300"
				};
			};
		//VIR
			class tier1_m600v_black: deviceBase_m952
			{
				gjb_itn_memoryPoints[]=
				{
					{0,0,0},
					{0,0,0},
					{-0.0717894,-0.000325499,0.0361969}
				};
				gjb_itn_interface[]=
				{
					"m952",
					"Rsc_gjb_itn_m600_ti",
					"\gjb_itn\addons\gjb_itn_compat_t1\ui\m600_bk"
				};
			};
			class tier1_m600v: tier1_m600v_black
			{
				gjb_itn_interface[]=
				{
					"m952",
					"Rsc_gjb_itn_m600_ti",
					"\gjb_itn\addons\gjb_itn_compat_t1\ui\m600"
				};
			};
	};
//Weapons
	class weapons
	{
		//HK416 D10
			class Tier1_HK416D10_LMT
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.21045,0.0466169,0.103306}
				};
			};
			class Tier1_HK416D10_LMT_Desert: Tier1_HK416D10_LMT{};
			class Tier1_HK416D10_CTR: Tier1_HK416D10_LMT{};
			class Tier1_HK416D10_CTR_Desert: Tier1_HK416D10_LMT{};

			class Tier1_HK416D10_SMR_LMT
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.238182,0.0466169,0.103306}
				};
			};
			class Tier1_HK416D10_SMR_LMT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_LMT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_CTR: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_CTR_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_CTR_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_IMOD: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_IMOD_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_IMOD_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_MFT: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_MFT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_SMR_MFT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_LMT: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_LMT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_LMT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_CTR: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_CTR_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_CTR_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_IMOD: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_IMOD_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_IMOD_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_MFT: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_MFT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_RAHG_MFT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_LMT: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_LMT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_LMT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_CTR: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_CTR_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_CTR_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_IMOD: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_IMOD_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_IMOD_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_MFT: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_MFT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D10_MW9_MFT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
		//HK416 D14.5
			class Tier1_HK416D145_lmt: Tier1_HK416D10_LMT{};
			class Tier1_HK416D145_LMT_Desert: Tier1_HK416D10_LMT{};
			class Tier1_HK416D145_CTR: Tier1_HK416D10_LMT{};
			class Tier1_HK416D145_CTR_Desert: Tier1_HK416D10_LMT{};
			class Tier1_HK416D145_SMR_LMT
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.348182,0.0466169,0.103306}
				};
			};
			class Tier1_HK416D145_SMR_LMT_Desert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_LMT_BlackDesert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_CTR: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_CTR_Desert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_CTR_BlackDesert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_IMOD: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_IMOD_Desert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_IMOD_BlackDesert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_MFT: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_MFT_Desert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_SMR_MFT_BlackDesert: Tier1_HK416D145_SMR_LMT{};
			class Tier1_HK416D145_RAHG_LMT: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_LMT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_LMT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_CTR: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_CTR_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_CTR_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_IMOD: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_IMOD_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_IMOD_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_MFT: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_MFT_Desert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_RAHG_MFT_BlackDesert: Tier1_HK416D10_SMR_LMT{};
			class Tier1_HK416D145_MW13_LMT
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.359499,0.0466169,0.103306}
				};
			};
			class Tier1_HK416D145_MW13_LMT_Desert: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_LMT_BlackDesert: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_CTR: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_CTR_Desert: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_CTR_BlackDesert: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_IMOD: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_IMOD_Desert: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_IMOD_BlackDesert: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_MFT: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_MFT_Desert: Tier1_HK416D145_MW13_LMT{};
			class Tier1_HK416D145_MW13_MFT_BlackDesert: Tier1_HK416D145_MW13_LMT{};
		//M110
			class Tier1_M110k1
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.353534,0.0388199,0.0848821}
				};
			};
			class Tier1_M110k1_CTR: Tier1_M110k1{};
			class Tier1_M110k5
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.364297,0.0466169,0.087125}
				};
			};
			class Tier1_M110k5_65mm: Tier1_M110k5{};
			class Tier1_M110k5_ACS: Tier1_M110k5{};
			class Tier1_M110k5_ACS_65mm: Tier1_M110k5{};
		//M249
			class tier1_m249_light_s_desert
			{
				gjb_itn_memoryPoints[]=
				{};
				gjb_itn_beltFedFix=0.22;
			};
		//Sig MCX
			class Tier1_SIG_MCX_115_Virtus
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.243182,0.0466169,0.103026}
				};
			};
			class Tier1_SIG_MCX_115_Virtus_300BLK: Tier1_SIG_MCX_115_Virtus{};
			class Tier1_SIG_MCX_115_Virtus_300BLK_Black: Tier1_SIG_MCX_115_Virtus{};
			class Tier1_SIG_MCX_115_Virtus_300BLK_Desert: Tier1_SIG_MCX_115_Virtus{};
			class Tier1_SIG_MCX_115_Virtus_300BLK_FDE: Tier1_SIG_MCX_115_Virtus{};
			class Tier1_SIG_MCX_115_Virtus_Black: Tier1_SIG_MCX_115_Virtus{};
			class Tier1_SIG_MCX_115_Virtus_Desert: Tier1_SIG_MCX_115_Virtus{};
			class Tier1_SIG_MCX_115_Virtus_FDE: Tier1_SIG_MCX_115_Virtus{};
		//Mk46
			class Tier1_MK46_Mod0
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.209522,0.0473275,0.0903269}
				};
			};
			class Tier1_MK46_Mod0_Desert: Tier1_MK46_Mod0{};
			class Tier1_MK46_Mod0_Para: Tier1_MK46_Mod0{};
			class Tier1_MK46_Mod0_Para_Desert: Tier1_MK46_Mod0{};
			class Tier1_MK46_Mod1
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.219584,0.0473275,0.0849421}
				};
			};
			class Tier1_MK46_Mod1_Desert: Tier1_MK46_Mod1{};
			class Tier1_MK46_Mod1_Savit: Tier1_MK46_Mod1{};
			class Tier1_MK46_Mod1_Savit_Desert: Tier1_MK46_Mod1{};
		//Mk48
			class Tier1_MK48_Mod0
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.230269,0.0473275,0.0903269}
				};
			};
			class Tier1_MK48_Mod0_Desert: Tier1_MK48_Mod0{};
			class Tier1_MK48_Mod0_Para: Tier1_MK48_Mod0{};
			class Tier1_MK48_Mod0_Para_Desert: Tier1_MK48_Mod0{};
			class Tier1_MK48_Mod1
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.186704,0.0473275,0.0849421}
				};
			};
			class Tier1_MK48_Mod1_Desert: Tier1_MK48_Mod1{};
		//SR-16
			class Tier1_SR16_Carbine_Mod2_CTR_Black
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.299701,0.0466169,0.0962062}
				};
			};
			class Tier1_SR16_Carbine_Mod2_CTR_FDE: Tier1_SR16_Carbine_Mod2_CTR_Black{};
			class Tier1_SR16_Carbine_Mod2_IMOD_Black: Tier1_SR16_Carbine_Mod2_CTR_Black{};
			class Tier1_SR16_Carbine_Mod2_IMOD_FDE: Tier1_SR16_Carbine_Mod2_CTR_Black{};
			class Tier1_SR16_Carbine_Mod2_LMT_Black: Tier1_SR16_Carbine_Mod2_CTR_Black{};
			class Tier1_SR16_Carbine_Mod2_LMT_FDE: Tier1_SR16_Carbine_Mod2_CTR_Black{};
			class Tier1_SR16_Carbine_Mod2_MFT_Black: Tier1_SR16_Carbine_Mod2_CTR_Black{};
			class Tier1_SR16_Carbine_Mod2_MFT_FDE: Tier1_SR16_Carbine_Mod2_CTR_Black{};
			class Tier1_SR16_CQB_Mod2_CTR_Black
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.238182,0.0466169,0.0962062}
				};
			};
			class Tier1_SR16_CQB_Mod2_CTR_FDE: Tier1_SR16_CQB_Mod2_CTR_Black{};
			class Tier1_SR16_CQB_Mod2_IMOD_Black: Tier1_SR16_CQB_Mod2_CTR_Black{};
			class Tier1_SR16_CQB_Mod2_IMOD_FDE: Tier1_SR16_CQB_Mod2_CTR_Black{};
			class Tier1_SR16_CQB_Mod2_Black: Tier1_SR16_CQB_Mod2_CTR_Black{};
			class Tier1_SR16_CQB_Mod2_LMT_FDE: Tier1_SR16_CQB_Mod2_CTR_Black{};
			class Tier1_SR16_CQB_Mod2_MFT_Black: Tier1_SR16_CQB_Mod2_CTR_Black{};
			class Tier1_SR16_CQB_Mod2_MFT_FDE: Tier1_SR16_CQB_Mod2_CTR_Black{};
		//SR-25
			class Tier1_SR25
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.291157,-0.0401642,0.0568923}
				};
				gjb_itn_nonStdRailFix="leftRailOnly";
			};
			class Tier1_SR25_Tan: Tier1_SR25{};
			class Tier1_SR25_EC: Tier1_SR25
			{
				gjb_itn_memoryPoints[]=
				{
					{-0.291324,-0.0401473,0.0569897}
				};
				gjb_itn_nonStdRailFix="leftRailOnly";
			};
			class Tier1_SR25_EC_Tan: Tier1_SR25_EC{};
	};
};