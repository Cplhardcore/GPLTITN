class CfgHints
{
	class gjb_itn
	{
		displayName="Illuminate The Night";
		class overview
		{
			displayName="Overview";
			displayNameShort="";
			description="<t color='#00FF7F'>Illuminate the Night</t> is a mod for Arma 3 which intends to increase the capabilities of night-fighters by replicating the real-world functions of popular weapon mounted laser aiming devices such as the PEQ-15. While every device has its quirks, they all share a core set of features.%1    %2Coaligned visible and IR aiming lasers,%1    %2Adjustable focus IR laser illuminators with beam diffusor caps,%1    %2Selectable operating modes including dual laser-illuminator modes,%1    %2Low- and high-powered operating modes,%1    %2Momentary- and toggle-on activation. %1%1%3Lasers, Illuminators, and Lights%4%1Unlike the laser pointer available in Arma 3, the lasers included in <t color='#00FF7F'>ITN</t> come in a wide variety of styles suitable for a variety of different situations: visible or IR, subtle low-power or high-power lightsaber.%1%1<t color='#00FF7F'>ITN</t> also adds IR illuminators to Arma 3. Acting like an IR spot light, illuminators frequently have an adjustable focus allowing them to throw their light significantly farther than regular flashlights. The narrower the beam, the longer it will reach. Most devices with an IR illuminator also have a diffused mode, either an LED or a diffusor cap, which acts as an IR flood light, spreading its power over a wider arc at the cost of a significantly reduced range.%1%1As a bonus, <t color='#00FF7F'>ITN</t> also improves flashlights, giving them a more realistic pattern with a “hot spot” that can illuminate a target out to a moderate range, while also having a wide “spill” to improve navigation and situational awareness. %1%1%3Controls%4%1<t color='#00FF7F'>ITN</t> brings all of these features into Arma 3. This is a lot of new functionality and keyboard real estate is at a premium, so along with a few keybinds <t color='#00FF7F'>ITN</t> adds in a graphic interface for interacting with laser devices. There is a generic interface for all laser devices, but devices from mods that have a compatibility patch have customized interfaces. %1%1%3Settings%4%1Along with this added functionality <t color='#00FF7F'>ITN</t> allows for some customization of the end-user experience. Draw distance for <t color='#00FF7F'>ITN</t> lights, lasers, and illuminators can be adjusted; a lower draw distance may help with performance. To account for some devices not having obvious controls, there are optional overlays which highlight device controls and indicate what type of interactions are available. Finally, there is an optional simplified controls option, which smooths over most of the individual quirks of devices and gives them a more uniform user experience, while also removing the lock-out “OFF” positions from devices which have them.";
			tip="";
			arguments[]={};
			logicalOrder = 1;
			//image = "";
			noImage = true;
		};
		class controls
		{
			displayName="Controls";
			displayNameShort="";
			description="%3Keys%4%1The following keybinds have been added by <t color='#00FF7F'>ITN</t> to interact with rail-mounted laser and illumination devices. %1    %2%3Activate Rail Device:%4 operates the primary function of the device mounted in the accessory position of the currently active weapon and will behave in accordance with the device’s particular operation.%1    %2%3Open Rail Device Interface:%4 opens the device interface menu or graphic interface while pressed and closes the interface when released.%1    %2%3Previous Rail Device Mode:%4 cycles through the device’s operating modes. By convention visible modes are found using this key. Mode selection is linear; this key will not select IR modes after moving through visible modes. %1    %2%3Next Rail Device Mode:%4 cycles through the device’s operating modes. By convention IR modes are found using this key. Mode selection is linear; this key will not select visible modes after moving through IR modes.%1    %2%3Rail Device Illuminator Beam – Narrower:%4 adjusts the width of the IR illuminator beam, making it narrower, if the device supports focusing the illuminator.%1    %2%3Rail Device Illuminator Beam – Wider:%4 adjusts the width of the IR illuminator beam, making it wider, if the device supports focusing the illuminator.%1    %2%3Rail Device Illuminator Diffusor Toggle:%4 toggles the diffused illuminator mode if the device supports diffusing the illuminator.%1    %2%3Reset ITN:%4 clears local variables, resetting the mode and position of <t color='#00FF7F'>ITN</t> devices. Only use this if your device is not operating as expected.%1%1%3Interfaces%4%1There are two types of device interfaces in <t color='#00FF7F'>ITN</t>: generic and graphic. If a device is fully supported by <t color='#00FF7F'>ITN</t> it will have a graphical interface, otherwise it will use the generic interface.%1%1The generic interface displays a list of all available modes for the device, buttons for selecting the previous and next modes, an activation button, buttons for adjusting the IR illuminator (if available), and an on indicator. Clicking the previous mode button will select the next higher mode on the list, while clicking the next mode button will select the next lower mode on the list. Mode can also be selected by directly clicking on an entry in the list. The activation button will toggle the device on or off in the selected mode, and while the device is on the on indicator will be illuminated. If the device supports adjusting the IR illuminator, then the narrow, widen, and diffuse buttons will be available, otherwise they will be disabled.%1%1Graphic interfaces will display an interactable view of the currently equipped device. Interactions with the graphic interfaces have been designed to mimic the real-world switchology of the particular devices; with very few exceptions using the device’s TM as a reference sheet here will work. A rule of thumb for the graphical interfaces is that, if it looks like a button, it is clickable with either left- or right-mouse button, and if it looks like it twists, it is twistable with either the left- or right-mouse buttons or by scrolling the mouse wheel. There is an optional overlay in the settings menu which will highlight controls.";
			tip="";
			arguments[]={};
			logicalOrder = 2;
			//image = "";
			noImage = true;
		};
		class device_dbala2
		{
			displayName="Device: DBAL-A2";
			displayNameShort="";
			description="The Steiner Dual Beam Aiming Laser (DBAL-A2), also known as the AN/PEQ-15A, is a multifunction weapon aiming laser and infrared illumination device. It combines an adjustable focus 30mW Infrared Illuminator with co-aligned 30mW Infrared and 4.4mW red Visible Laser Pointers into a single device, providing the user with an active aiming solution for their weapon system and an IR illuminator for use with night-vision devices.%1%1The DBAL-A2 has the following controls:%1    %2%3Activation Mode Selector Switch%4%1    %2%3Laser Mode Selector Switch%4%1    %2%3Integrated Momentary Activation Switch%4%1    %2%3I/R ILLUM Focus Knob%4%1<img size='15' shadow='0' image='\gjb_itn\addons\gjb_itn_core\ui\fm\fm_dbal.paa' />%1The %3Activation Mode Selector Switch%4 is located on the left rear of the device housing. It is used to select between the HI PWR and LO PWR modes of operation when activated. It can also be used to turn the DBAL-A2 ON continuously. The %3Activate Mode Selector Switch%4 has 5 positions:%1    %2ON LO PWR: Activates the selected laser function in LO PWR continuously.%1    %2MOM LO PWR: Activates the selected laser function in LO PWR while the %3Activate Rail Device%4 key is depressed. Pressing the %3Integrated Momentary Activation Switch%4 in the interface once or the %3Activate Rail Device%4 key twice in rapid succession will activate the DBAL-A2 continuously for 5 minutes.%1    %2OFF%1    %2MOM HI PWR: Activates the selected laser function in HI PWR while the %3Activate Rail Device%4 key is depressed. Pressing the %3Integrated Momentary Activation Switch%4 in the interface once or the %3Activate Rail Device%4 key twice in rapid succession will activate the DBAL-A2 continuously for 5 minutes.%1    %2ON HI PWR: Activates the selected laser function in HI PWR continuously.%1%1The %3Laser Mode Selector Switch%4 is located to the right of the %3Activation Mode Selector Switch%4 on the back of the device housing. It is used to select between the laser functions. The Laser Mode Selector Switch has 4 positions:%1    %2VIS POINT: Selects only the Visible Laser Pointer for activation.%1    %2I/R ILLUM: Selects only the Infrared Illuminator for activation.%1    %2I/R POINT AND ILLUM: Selects both Infrared Pointer and Illuminator for simultaneous activation.%1    %2I/R POINT: Selects only the Infrared Pointer for activation.%1%1Once the mode of operation has been selected, the device may be used by activating the system with either the %3Integrated Momentary Activation Switch%4, found on the top of the housing above the Activation Mode Selector Switch, or the %3Activate Rail Device%4 key. Pressing and holding the %3Activate Rail Device%4 key activates the laser function selected by the %3Laser Mode Selector Switch%4. When the key is released, the device turns off. Pressing the %3Activate Rail Device%4 key twice in rapid succession (double-tap), or pressing the %3Integrated Momentary Activation Key%4 in the interface once, will activate the device in a continuous ON mode for 5 minutes. Pressing either again will return the unit to momentary mode.%1%1The Infrared Illumination beam may be varied from flood to spot by rotating the %3I/R ILLUM Focus Knob%4, which is located on the front left of the device housing. %3Right-clicking%4 the %3Focus Knob%4 will narrow the beam, while %3Left-clicking%4 the %3Focus Knob%4 will widen the beam. The %3Scroll Wheel%4 will also adjust the beam size while hovering the mouse over the %3Focus Knob%4 in the interface. The DBAL-A2 comes with a %3Diffusor Cover%4 for the Infrared Illuminator which turns the Illuminator into a short-ranged, wide-angle flood. The %3Diffusor Cover%4 can be applied or removed by pressing and holding %3Left-Mouse%4 on the %3Focus Knob%4 for half a second, or by pressing the %3Rail Device Illuminator Diffusor Toggle%4 key.";
			tip="";
			arguments[]={};
			logicalOrder = 3;
			//image = "";
			noImage = true;
		};
		class device_peq15
		{
			displayName="Device: PEQ-15";
			displayNameShort="";
			description="The L3/Insight Advanced Target Pointer Illuminator Aiming Light (ATPIAL), also known as the AN/PEQ-15, is a multifunction weapon aiming laser and infrared illumination device. It combines an adjustable focus 30mW Infrared Illuminator with co-aligned 25mW Infrared and 4mW red Visible Laser Pointers into a single device, providing the user with an active aiming solution for their weapon system and an IR illuminator for use with night-vision devices.%1%1The PEQ-15 has the following controls:%1    %2%3Mode Selector%4%1    %2%3FIRE Button%4%1    %2%3Infrared Illuminator Focus Ring%4%1<img size='15' shadow='0' image='\gjb_itn\addons\gjb_itn_core\ui\fm\fm_peq15.paa' />%1The %3Mode Selector%4 is located on top of the device housing towards the rear. It allows the user to select the desired mode of operation for the PEQ-15. The %3Mode Selector%4 has 8 positions.%1    %2VIS AL – VISIBLE AIM: Visible Aim Laser is selected.%1    %2O – Off: The PEQ-15 will not operate. Prevents inadvertent emission of laser energy.%1    %2P – PROGRAM: Programming mode is selected to set the desired IR Illuminator pulse rate. (Future feature, this position is not currently selectable.)%1    %2AL – AIM LOW: IR Aim Laser is selected at low power.%1    %2DL – DUAL LOW: IR Aim Laser and IR Illuminator are both selected at low power.%1    %2AH – AIM HIGH: IR Aim Laser is selected at high power.%1    %2IH – ILLUMINATOR HIGH: IR Illuminator is selected at high power.%1    %2DH – DUAL HIGH: IR Aim Laser and IR Illuminator are both selected at high power.%1%1Once the mode of operation has been selected, the PEQ-15 may be used in that mode by activating the system in either Momentary or Continuous Operations modes. Pressing and holding the %3Activate Rail Device%4 key operates the PEQ-15 in the selected mode. The selected laser(s) will remain on until the %3Activate Rail Device%4 key is released. Pressing the %3FIRE Button%4 once or pressing the %3Activate Rail Device%4 key twice in rapid succession (double-tap) operates the PEQ-15 in the selected mode. The selected laser(s) will remain on until the %3FIRE Button%4 is pressed again, the %3Activate Rail Device%4 key is pressed a third time (single tap), or after five minutes of continuous operation, whichever comes first.%1%1The Infrared Illuminator is located on the front left of the device housing and is used with night vision devices to provide IR illumination of the intended target area. The %3Focus Ring%4 is rotated to vary the illumination beam spread from flood to spot, based on the range and size of the area to be illuminated. %3Right-clicking%4 the Focus Ring will narrow the beam, while %3Left-clicking%4 the %3Focus Ring%4 will widen the beam. The %3Scroll Wheel%4 will also adjust the beam size while hovering the mouse over the %3Focus Ring%4 in the interface. The PEQ-15 comes with a %3Diffusor Lens Cap%4 which spreads the laser energy over an angle of at least 45 degrees, allowing for the illumination of a wider area. The %3Diffuser Lens Cap%4 cane be used by pressing and holding %3Left-Mouse%4 on the %3Focus Ring%4 for half a second, or by pressing the %3Rail Device Illuminator Diffusor Toggle%4 key.";
			tip="";
			arguments[]={};
			logicalOrder = 4;
			//image = "";
			noImage = true;
		};/*
		class device_peq16
		{
			displayName="Device: DBAL-A2";
			displayNameShort="Features and Operations of the Steiner DBAL-A2 / PEQ-15A";
			description="";
			tip="";
			arguments[]={};
			logicalOrder = 5;
			//image = "";
			noImage = true;
		};
		class device_peq2
		{
			displayName="Device: PEQ-2";
			displayNameShort="";
			description="";
			tip="";
			arguments[]={};
			logicalOrder = 6;
			//image = "";
			noImage = true;
		};
		class device_perst3
		{
			displayName="Device: Perst 3";
			displayNameShort="";
			description="";
			tip="";
			arguments[]={};
			logicalOrder = 7;
			//image = "";
			noImage = true;
		};
		class device_llm01
		{
			displayName="Device: LLM-01";
			displayNameShort="";
			description="";
			tip="";
			arguments[]={};
			logicalOrder = 8;
			//image = "";
			noImage = true;
		};
		class device_llm3
		{
			displayName="Device: LLM Mk.3";
			displayNameShort="";
			description="";
			tip="";
			arguments[]={};
			logicalOrder = 9;
			//image = "";
			noImage = true;
		};
		class device_mfpistols
		{
			displayName="Device: Multifunction Pistol Lasers";
			displayNameShort="";
			description="";
			tip="";
			arguments[]={};
			logicalOrder = 10;
			//image = "";
			noImage = true;
		};*/
	};
};

/*
{{""}} assigned key
%1 - small empty line
    %2 - bullet (for item in list)
%3 - highlight start
%4 - highlight end
%5 - warning color formated for using in structured text tag
%6 - BLUFOR color attribute
%7 - OPFOR color attribute
%8 - Independent color attribute
%9 - Civilian color attribute
%10 - Unknown side color attribute
*/