#define COMPONENT Hostage
#include "\x\UO_FW\addons\Main\script_macros.hpp"
UO_FW_EXEC_CHECK(ALL);

if (!UO_FW_Server_HostageModule_Allowed) exitWith {};
["UO_FW_RegisterModuleEvent", ["Hostage Control", "Allows the mission maker to easily add hostages to their missions.", "Starfox64, TrainDoctor and PiZZADOX"]] call CBA_fnc_globalEventJiP;

params ["_unit"];

private _marker = (UO_FW_GETVAR(_unit,Hostage_Rescue_Location,"hostage_rescue"));

if (getMarkerColor _marker isEqualto "") exitwith {
    ERROR_1("hostage _marker: %1 does not exist!",_marker);
};

_marker setMarkerAlpha 0;

["UO_FW_Hostage_ACEActions_GlobalEvent", [_unit], "HostageJiPID"] call CBA_fnc_globalEventJiP;

_unit setBehaviour "CARELESS";
_unit allowFleeing 0;
_unit setCaptive true;
_unit playMoveNow "Acts_AidlPsitMstpSsurWnonDnon04";

private _EhAnimDone = _unit addEventHandler ["AnimDone", {
    if (!alive _unit) exitWith {
        _unit removeEventHandler ["AnimDone", {(UO_FW_SETVAR(_unit,EhAnimDone,nil));}];
    };
    _unit playMoveNow "Acts_AidlPsitMstpSsurWnonDnon04";
}];

(UO_FW_SETVAR(_unit,EhAnimDone,_EhAnimDone));

[{
    params ["_argNested", "_idPFH"];
    _argNested params ["_unit","_marker","_lastCheckedTime"];
    private _timeDifference = (CBA_missionTime - _lastCheckedTime);
    if (_timeDifference < 5) exitwith {};
    _argNested set [2,(CBA_missionTime)];
    if (!(animationState _unit isEqualto "acts_aidlpsitmstpssurwnondnon04") && {(_unit inArea _marker)}) exitwith {
        if ((vehicle _unit) isEqualto _unit) then {
            [_unit] joinSilent grpNull;
            _unit disableAI "MOVE";
            [{
                _this playMoveNow "AmovPsitMstpSnonWnonDnon_ground";
            }, _unit, 1] call CBA_fnc_waitAndExecute;
        };
        (UO_FW_SETPVAR(_this,Hostage_IsRescued,true));
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
}, 5, [_unit,_marker,CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
