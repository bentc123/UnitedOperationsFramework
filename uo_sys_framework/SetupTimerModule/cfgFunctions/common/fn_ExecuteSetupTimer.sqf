#include "\x\UO_FW\addons\main\HeadlessAIModule\module_macros.hpp"
UO_FW_EXEC_CHECK(ALL)

//[_logic,_area,_selectedSide,_time] passed array
params ["_logic","_area","_selectedSide","_waittime"];
private _varname = format ["SetupTimer_%1",_logic];

if(!(_this call UO_FW_fnc_ValidateSetupTimer)) exitWith {
	UO_FW_DEBUG("","Setup timer failed to Validate")
};

["Setup Timer", "Allows the mission maker to restrict the AO of a side for a set amount of time.", "Olsen & Sacher & PiZZADOX"] call UO_FW_FNC_RegisterModule;

if (!isDedicated) then {

	_this spawn {

		waitUntil {!isNull player};
		waitUntil {!isNil "UO_FW_START_TIME"};
		waitUntil {!isNil "UO_FW_ELAPSED_TIME"};

		params ["_logic","_area","_selectedSide","_waittime"];
		private ["_run","_pos","_startTime","_displayed"];

		if ((round(0 + _waittime - UO_FW_ELAPSED_TIME)) < 1) exitwith {};

		if (!((side player) isEqualto _selectedSide) || !((vehicle player) inArea _area)) exitwith {};

		//if (isMultiplayer) then {
		////we are checking for a bug described on serverTime wiki page
		////bugged value is usually around 400 000
		//if (abs (UO_FW_setup_start_time - serverTime) > 100000) then {
		//	_startTime = serverTime;
		//	UO_FW_setup_start_time = serverTime; //client time is used instead, according to wiki it's always correct
		//	//we send it across network. Possible issue: multiple clients send it at the same time
		//	//and increase network traffic. Shouldn't be too bad because data is small.
		//	publicVariable "UO_FW_setup_start_time";
		//	UO_FW_DEBUG("","Setup Timer: Detected desynchronized server and client clock, using client's time instead.")
		//};

		UO_FW_DEBUG("","Starting Setup Timer")
		_alreadyInATimer = MissionNameSpace getvariable ["UO_FW_InSetupTimer",false];
		if (_alreadyInATimer) exitwith {};
		if !(_alreadyInATimer) then {UO_FW_InSetupTimer = true;};

		_displayed = false;
		_run = true;

		while {_run} do {

			if ((vehicle player) inArea _area) then {
				_pos = getPosATL (vehicle player);
			} else {
				private _reldir = (vehicle player) getdir _logic;
				(vehicle player) setVelocity [0,0,0];
				(vehicle player) setPos _pos;
				//_backpos = _pos getPos [2,_reldir];
				//(vehicle player) setPos _backpos;
			};

			_timeLeft = round(_waittime - UO_FW_ELAPSED_TIME);

			diag_log format ["_timeLeft: %1",_timeLeft];

			if (_timeLeft < 0) then {
				_timeLeft = 0;
			};

			if (_timeLeft > 0 && !_displayed) then {
				_displayed = true;
				missionNamespace setVariable ["UO_FW_ST_TimeLeft", _timeLeft];
				("UO_FW_SetupTimer_Layer" call BIS_fnc_rscLayer) cutRsc ["UO_FW_RscSetupTimer", "PLAIN", 0.5, false];
			};

			if (_timeLeft isEqualto 0) then {
				_run = false;
			};

			sleep(0.1);
			};
	};
};
