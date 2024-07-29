#include "script_component.hpp"

//*****************************************************************************//
//
//	gjb_itn_fnc_emissionCombined
//
//	computes final position of emitter and draws laser
//	is called from inside a mission event handler 
//	(EachFrame, to cut visible lag) when device is active
//
//	parameters =	_unit being drawn for
//
//					gjb_itn_deviceOffset of unit being drawn for
//					gjb_itn_lasSpec of unit being drawn for
//
//*****************************************************************************//

params ["_unit","_deviceState","_humidity","_dayModArray"];

private _illumObject = _unit getVariable ["gjb_itn_illumObject",objNull];
private _flashObject = _unit getVariable ["gjb_itn_flashObject",objNull];
private _lightObjects = _unit getVariable ["gjb_itn_lightObjects",["",""]];

//Prep check variables
private _mode = _deviceState #0;
private _laser = _deviceState #1;
private _illum = _deviceState #2;
private _flash = _deviceState #3;

//Retrieve common position data
private _posData = _unit getVariable ["gjb_itn_deviceOffset",[[],[],[],[],""]];
private _proxy = _posData #4;

//Random USP Uniform fix
private _uspFix = allLODs _unit;

//Compute proxy location without weapon-accessory offset
_unit selectionVectorDirAndUp [_proxy, 1] params ["_vy", "_vz"];
private _pos = selectionPosition [_unit,_proxy,0,true,"FirstPoint"];
private _posDir = +_pos;
private _vx = _vy vectorCrossProduct _vz;
private _mat = matrixTranspose [_vx, _vy, _vz];

//Prep for debug reporting
private _debug = missionNamespace getVariable ["gjb_itn_setting_debug",false];

//Prep for vehicle checks
private _carrier = vehicle _unit;
private _isMounted = _carrier != _unit;
private _isFFV = count (_carrier unitTurret _unit) > 0;
private _isAim = "aim" in (animationState _unit);

//is player aircrew check
private _me = call CBA_fnc_currentUnit;
private _myCarrier = vehicle _me;
private  _iAmMounted = _myCarrier != _me;
private _inAC = (typeOf _myCarrier) isKindOf "Air";

//Conversion tool
_numBool = {
	if(_this #0 == 1)then{true}else{false};
};

//==================================================
//Draw laser if device is on and set to a laser mode
	if (_laser > 0 && (_mode == 1 || _mode == 2)) then{
		private _lasData = _unit getVariable ["gjb_itn_lasSpec",[[0,0,0],[],0,0,0,false]];

		private _lasColor = _lasData #0;
		private _lasColorDot = _lasData #1;
		private _lasDot = _lasData #2;
		private _lasBeam = _lasData #3;
		private _lasLength = _lasData #4;
		private _lasIR = _lasData #5;

		//Adjust beam visibility according to humidity
		if(_humidity != -1)then{
			private _beamCoef = 1;
			switch(true)do{
				case (_lasIR && _lasBeam < 0.0001):{
					_beamCoef = 750;
				};
				case (_lasIR && _lasBeam >= 0.0001 && _lasBeam < 0.01):{
					_beamCoef = 10;
				};
				case (!_lasIR && _lasBeam > 0):{
					_beamCoef = 50;
				};
			};
			private _humExp = 18;
			if(_debug)then{
				_humExp = player getVariable ["gjb_itn_debugHumExpon",_humExp];
			};
			_lasBeamMin = _lasBeam /10;
			_lasBeamMax = _lasBeam * _beamCoef;
			_lasBeam = (_lasBeamMax - _lasBeamMin) * (_humidity  ^ _humExp) + _lasBeamMin;
		};
		//Adjust laser visibility for daytime use OR adjusts for visibility to aircrew at night
		if(sunOrMoon == 1)then{
			//Unpack daylight mod variables
			private _dayDotColorMod = _dayModArray #0;
			private _dayDotSizeMod = _dayModArray #1;
			private _dayBeamColorMod = _dayModArray #2;
			private _dayBeamSizeMod = _dayModArray #3;
			private _dayBeamLengthMod = _dayModArray #4;
			//adjust dot color intensity
			_lasColorDot params ["_dr","_dg","_db"];
			_dr = _dr + (_dr *_dayDotColorMod);
			_dg = _dg + (_dg *_dayDotColorMod);
			_db = _db + (_db *_dayDotColorMod);
			_lasColorDot = [_dr,_dg,_db];
			//adjust dot size
			private _smallestDot = 0.02;
			if((_lasDot *0.15) > _smallestDot)then{
				_smallestDot = _lasDot *0.15;
			};
			_lasDot = ((_lasDot - _smallestDot) * _dayDotSizeMod) + _smallestDot;
			//adjust beam color intensity
			_lasColor params ["_br","_bg","_bb"];
			_br = _br * _dayBeamColorMod;
			_bg = _bg * _dayBeamColorMod;
			_bb = _bb * _dayBeamColorMod;
			_lasColor = [_br,_bg,_bb];
			//adjust beam size
			_lasBeam = _lasBeam * _dayBeamSizeMod;
			//adjust beam length/dot draw distance
			if(_lasLength == -1)then{
				_lasLength = 2000;
			};
			private _cutOff = 100;
			if((_lasLength / 3) > _cutOff)then{
				_cutOff = _lasLength / 3;
			};
			_lasLength = ((_lasLength -_cutOff) * _dayBeamLengthMod ) + _cutOff;
		}else{
			if(_iAmMounted && _inAC && _unit != _me)then{
				private _range = _me distance _unit;
				private _acAdjust = 0.001;
				switch(true)do{
					case (_range > 0 && _range <= 6000):{
						private _A = (_range / 6000) /* - 0.17 */;
						_acAdjust = (6 *( (_A ^ 2.5) - ((0.95 * _A) ^ 2.9))) + 0.001; //range is [ 0.001 , 0.83 ]
						//_acAdjust = (2 * ((_A ^3) - (_A^9))) + 0.01;
					};
					case (_range > 6000 && _range <= 8000):{
						_acAdjust = (1 - ((_range - 6000) / 2000)) * 0.83;
					};
				};
				_lasBeam = _lasBeam * (1 + (1200 * _acAdjust)); //((1-_lasBeam) * _acAdjust) + _lasBeam
			};
		};

		//Retrieve position data
		private _offsetLa = _posData #0;
		private _directionLa = +_offsetLa;

		//Potentially report fault if emitting from hand
		if(_debug && _offsetLa #0#0 == 0 && _offsetLa #1#0 == 0 && _offsetLa #2#0 == 0)then{
			systemChat "Laser offset failed to load";
			private _check = _unit getVariable ["gjb_itn_checker",false];
			if(!_check)then{
				_unit setVariable ["gjb_itn_checker",true];
				[_unit,_deviceState] spawn {[_this #0,_this #1] call gjb_itn_fnc_getWeaponOffset;};
			};
		};

		//Compute position of memory point
		private _posOffLa = +(_pos vectorAdd flatten(_mat matrixMultiply _offsetLa));
		private _p1La = _unit modelToWorldVisualWorld _posOffLa;

		//Compute direction point and vector
		private _directionTLa = _directionLa #0 #0;
		_directionTLa = _directionTLa - 10;
		(_directionLa #0) set [0,_directionTLa];
		private _posDirLa = +(_posDir vectorAdd flatten(_mat matrixMultiply _directionLa));

		private _p2La = _unit modelToWorldVisualWorld _posDirLa;
		private _v2La = _p1La vectorFromTo _p2La;

		//Draw the laser
		drawLaser [_p1La, _v2La, _lasColor,_lasColorDot, _lasDot, _lasBeam, _lasLength, _lasIR];
	};

//==================================================
//Create and position illuminator if device is on and set to an illuminator mode,
//	otherwise clean up illuminator object
	private _illumSpec = _unit getVariable ["gjb_itn_illumSpec",""];
	private _illumOn = _illum > 0 && (_mode == 1 || _mode == 2);
	switch(true)do{
		case (_illumOn && !(_isMounted && _isFFV && _isAim)):{	//was B
			//if the illuminator is the wrong type, delete it
			if((_lightObjects #0) != _illumSpec)then{
				deleteVehicle _illumObject;
				_illumObject = objNull;
			};
			//If the illuminator does not already exist, create it
			if(isNull _illumObject)then{
				_illumObject = _illumSpec createVehicleLocal [0,0,0];
				_unit setVariable ["gjb_itn_illumObject",_illumObject];
				_lightObjects set [0,_illumSpec];
				_unit setVariable ["gjb_itn_lightObjects",_lightObjects];
			};

			private _offsetIl = _posData #1;
			private _directionIl = +_offsetIl;
			
			//Compute position of memory point
			private _posOffIl= +(_pos vectorAdd flatten(_mat matrixMultiply _offsetIl));
			private _p1Il = _unit modelToWorldVisualWorld _posOffIl;
			
			//Compute direction point and vector
			private _directionTIl = _directionIl #0 #0;
			_directionTIl = _directionTIl - 10;
			(_directionIl #0) set [0,_directionTIl];
			private _posDirIl = +(_posDir vectorAdd flatten(_mat matrixMultiply _directionIl));
			private _p2Il = _unit modelToWorldVisualWorld _posDirIl;
			private _v2Il = _p1Il vectorFromTo _p2Il;
			
			//position and point illuminator
			_illumObject setPosASL _p1Il;
			_illumObject setVectorDirAndUp [_v2Il,[0,1,0]];
		};
		case (_illumOn && _isMounted && _isFFV && _isAim): {
			//if the illuminator is the wrong type, delete it
			if((_lightObjects #0) != _illumSpec)then{
				deleteVehicle _illumObject;
				_illumObject = objNull;
			};
			if(isNull _illumObject)then{
				//create and attach light
				_illumObject = "#lightreflector" createVehicleLocal [0,0,0];
				_illumObject attachTo [_unit,[0,0.8,0.1],"proxy:\a3\characters_f\proxies\weapon.001",true];

				//gather specs
				private _lightCfg = configFile >> "CfgVehicles" >> _illumSpec >> "Reflectors" >> "Light_1";

				_illumObject setLightColor getArray (_lightCfg >> "color");
				_illumObject setLightAmbient getArray (_lightCfg >> "ambient");
				_illumObject setLightIntensity  getNumber (_lightCfg >> "intensity");
				_illumObject setLightConePars [
					getNumber (_lightCfg >> "outerAngle"),
					getNumber (_lightCfg >> "innerAngle"),
					getNumber (_lightCfg >> "coneFadeCoef")
				];
				_illumObject setLightUseFlare  ([getNumber (_lightCfg >> "useFlare")] call _numBool);
				_illumObject setLightFlareSize getNumber (_lightCfg >> "flareSize");
				_illumObject setLightFlareMaxDistance getNumber (_lightCfg >> "flareMaxDistance");
				_illumObject setLightIR ([getNumber (_lightCfg >> "irLight")] call _numBool); 
				_illumObject setLightAttenuation [
					getNumber (_lightCfg >> "Attenuation" >> "start"),
					getNumber (_lightCfg >> "Attenuation" >> "constant"),
					getNumber (_lightCfg >> "Attenuation" >> "linear"),
					getNumber (_lightCfg >> "Attenuation" >> "quadratic"),
					getNumber (_lightCfg >> "Attenuation" >> "hardLimitStart"),
					getNumber (_lightCfg >> "Attenuation" >> "hardLimitEnd")
				];

				//save object
				_unit setVariable ["gjb_itn_illumObject",_illumObject];
				_lightObjects set [0,_illumSpec];
				_unit setVariable ["gjb_itn_lightObjects",_lightObjects];
			};
		};
		default {	//was  A
			deleteVehicle _illumObject;
			_unit setVariable ["gjb_itn_illumObject",objNull];
		};
	};/*
	if () then{//B
		
	}else{	//A
	};*/

//==================================================
//Create and position flashlight if device is on and set to an flashlight mode,
//	otherwise clean up flashlight object
	private _flashSpec = _unit getVariable ["gjb_itn_flashSpec",""];
	private _flashOn = _flash > 0 && (_mode == 1 || _mode == 3);
	switch(true)do{
		case (_flashOn && !(_isMounted && _isFFV && _isAim)): {
			//if the flashlight is the wrong type, delete it
			if((_lightObjects #1) != _flashSpec)then{
				deleteVehicle _flashObject;
				_flashObject = objNull;
			};
			//If the flashlight does not already exist, create it
			if(isNull _flashObject)then{
				_flashObject = _flashSpec createVehicleLocal [0,0,0];
				_unit setVariable ["gjb_itn_flashObject",_flashObject];
				_lightObjects set [1,_flashSpec];
				_unit setVariable ["gjb_itn_lightObjects",_lightObjects];
			};

			private _offsetLi = _posData #2;
			private _directionLi = +_offsetLi;

			//Compute position of memory point
			private _posOffLi = +(_pos vectorAdd flatten(_mat matrixMultiply _offsetLi));
			private _p1Li = _unit modelToWorldVisualWorld _posOffLi;

			//Compute direction point and vector
			private _directionTLi = _directionLi #0 #0;
			_directionTLi = _directionTLi - 10;
			(_directionLi #0) set [0,_directionTLi];
			private _posDirLi = +(_posDir vectorAdd flatten(_mat matrixMultiply _directionLi));
			private _p2Li = _unit modelToWorldVisualWorld _posDirLi;
			private _v2Li = _p1Li vectorFromTo _p2Li;

			//position and point illuminator
			_flashObject setPosASL _p1Li;
			_flashObject setVectorDirAndUp [_v2Li,[0,1,0]];
		};
		case (_flashOn && _isMounted && _isFFV && _isAim): {
			//if the illuminator is the wrong type, delete it
			if((_lightObjects #0) != _flashSpec)then{
				deleteVehicle _flashObject;
				_flashObject = objNull;
			};
			if(isNull _flashObject)then{
				//create and attach light
				_flashObject = "#lightreflector" createVehicleLocal [0,0,0];
				_flashObject attachTo [_unit,[0,0.8,0.1],"proxy:\a3\characters_f\proxies\weapon.001",true];

				//gather specs
				private _lightCfgT = configFile >> "CfgVehicles" >> _flashSpec >> "Reflectors" >> "Light_T";
				private _lightCfgW = configFile >> "CfgVehicles" >> _flashSpec >> "Reflectors" >> "Light_W";

				_flashObject setLightColor getArray (_lightCfgT >> "color");
				_flashObject setLightAmbient getArray (_lightCfgT >> "ambient");
				_flashObject setLightIntensity  getNumber (_lightCfgT >> "intensity");
				_flashObject setLightConePars [
					getNumber (_lightCfgW >> "outerAngle"),
					getNumber (_lightCfgT >> "innerAngle"),
					getNumber (_lightCfgT >> "coneFadeCoef")
				];
				_flashObject setLightUseFlare  ([getNumber (_lightCfgW >> "useFlare")] call _numBool);
				_flashObject setLightFlareSize getNumber (_lightCfgW >> "flareSize");
				_flashObject setLightFlareMaxDistance getNumber (_lightCfgW >> "flareMaxDistance");
				_flashObject setLightIR ([getNumber (_lightCfgT >> "irLight")] call _numBool); 
				_flashObject setLightAttenuation [
					getNumber (_lightCfgT >> "Attenuation" >> "start"),
					getNumber (_lightCfgT >> "Attenuation" >> "constant"),
					getNumber (_lightCfgT >> "Attenuation" >> "linear"),
					getNumber (_lightCfgT >> "Attenuation" >> "quadratic"),
					getNumber (_lightCfgT >> "Attenuation" >> "hardLimitStart"),
					getNumber (_lightCfgT >> "Attenuation" >> "hardLimitEnd")
				];

				//save object
				_unit setVariable ["gjb_itn_illumObject",_flashObject];
				_lightObjects set [0,_flashSpec];
				_unit setVariable ["gjb_itn_lightObjects",_lightObjects];
			};
		};
		default {
			deleteVehicle _flashObject;
			_unit setVariable ["gjb_itn_flashObject",objNull];
		};
	};

/*
private _debug = missionNamespace getVariable ["gjb_itn_setting_debug",false];
if(_debug)then{
	systemChat str _unit;
};*/