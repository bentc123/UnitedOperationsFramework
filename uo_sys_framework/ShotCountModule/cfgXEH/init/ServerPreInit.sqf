#define COMPONENT ShotCount
#include "\x\UO_FW\addons\Main\script_macros.hpp"
UO_FW_EXEC_CHECK(SERVER);

[QGVAR(EH_Event), {
    if !(UO_FW_Server_ShotCountModule_Allowed) exitwith {};
    if !(MGETMVAR(ShotCount_Enabled,false)) exitwith {};
    params [["_side",sideUnknown,[sideUnknown]],["_className","",[""]]];
    private _classDisplay = [_className] call UO_FW_fnc_ShotCount_getDisplayName;
    [_side,_classDisplay] call UO_FW_fnc_ShotCount_shotCount;
}] call CBA_fnc_addEventHandler;

["UO_FW_SettingsLoaded", {
    if !(UO_FW_Server_ShotCountModule_Allowed) exitwith {};
    if !(MGETMVAR(ShotCount_Enabled,false)) exitwith {};
    GVAR(ExpendedAmmunition_BLUFOR) = [];
    GVAR(ExpendedAmmunition_Indfor) = [];
    GVAR(ExpendedAmmunition_OPFOR) = [];
    GVAR(ExpendedAmmunition_Civilian) = [];
    GVAR(classNames) = [];
}] call CBA_fnc_addEventHandler;
