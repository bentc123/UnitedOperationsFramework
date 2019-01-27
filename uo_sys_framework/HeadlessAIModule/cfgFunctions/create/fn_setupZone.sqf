/*    Description: Sets up a zone and any units, objects or modules linked to the zone once activated.
 *    Arguments:
 *         OBJECT    - Zone Module (name, _logic)
 *        NUMBER    - Zone Activation Delay
 *        STRING    - Code as String to Execute on Activation
 *        BOOL    - Initial/PreInit Spawn
 *     Return Value:
 *         BOOL    - True
 *    Author
 *        suits & PiZZADOX
 */
#include "\x\UO_FW\addons\Main\HeadlessAIModule\module_macros.hpp"
UO_FW_AI_EXEC_CHECK(SERVERHC);

params ["_logic",["_delay",0,[0]],["_code",{},[{}]],"",["_initial",false],["_entitiesArray",[],[[]]]];
private ["_entities"];
if !(_initial) then {
    if ((tolower(typeOf _logic)) in ["uo_fw_ai_controlmodule", "uo_fw_ai_controlmodule_r"]) then {
        [_logic] spawn {
            params ["_logic"];
            switch (_logic getVariable ["UO_FW_AI_ControlAction",0]) do {
                case 0 : {
                    // Enable Linked Zones
                    [([_logic,["UO_FW_AI_ZoneModule","UO_FW_AI_ZoneModule_R"]] call UO_FW_AI_fnc_getSyncedModules),0] call UO_FW_AI_fnc_setZone;
                };
                case 1 : {
                    // Disable Linked Zones
                    [([_logic,["UO_FW_AI_ZoneModule","UO_FW_AI_ZoneModule_R"]] call UO_FW_AI_fnc_getSyncedModules),1] call UO_FW_AI_fnc_setZone;
                };
                case 2 : {
                    // Toggle Linked Zones
                    [([_logic,["UO_FW_AI_ZoneModule","UO_FW_AI_ZoneModule_R"]] call UO_FW_AI_fnc_getSyncedModules),2] call UO_FW_AI_fnc_setZone;
                };
            };
        };
    };
};
//TODO
//private _syncedFunctions = [_logic,UO_FW_AI_functions] call UO_FW_AI_fnc_getSyncedModules;
//if (count _syncedFunctions > 0) then {
//    [_syncedFunctions,_delay] spawn UO_FW_AI_fnc_createFunctions;
//};
if (_initial) then {
    _entities = _entitiesArray
} else {
    _entities = (([_logic,UO_FW_AI_entities] call UO_FW_AI_fnc_getDetails) select 1);
};
if !(_entities isEqualto []) then {
    if (!isMultiplayer) then {
        LOG("!isMultiplayer, createZone function executed");
        [_logic,_entities,_delay,_code,_initial] call UO_FW_AI_fnc_createZone;
    } else {
        [{!isNil "UO_FW_var_HC_ID"},{
            params ["_logic","_entities","_delay","_code","_initial"];
            LOG_1("sending createZone function to clientid %1",UO_FW_var_HC_ID);
            [[_logic,_entities,_delay,_code,_initial], {if (UO_FW_var_isHC) then {_this call UO_FW_AI_fnc_createZone;};}] remoteExec ["bis_fnc_call", UO_FW_var_HC_ID];
        }, [_logic,_entities,_delay,_code,_initial]] call CBA_fnc_waitUntilAndExecute;
    };
};

//private _entities = (([_logic,UO_FW_AI_entities] call UO_FW_AI_fnc_getDetails) select 1);
//if (count _entities > 0) then {
//    if (_initial) then {
//        [_logic,_entities,_code] call UO_FW_AI_fnc_createZoneInit;
//        _logic setvariable ["initiallyspawned",true];
//    } else {
//        [_logic,_entities,_delay,_code] call UO_FW_AI_fnc_createZone;
//    };
//};

{
    {
        [_x,(_x getVariable "UO_FW_AI_Template"),_delay,{}] spawn UO_FW_AI_fnc_createZone;
    } foreach [_x,["UO_FW_AI_TemplateModule"]] call UO_FW_AI_fnc_getSyncedModules;
} foreach [_logic,["UO_FW_AI_PositionModule"]] call UO_FW_AI_fnc_getSyncedModules;
//for "_p" from 0 to (count _posModules) step 1 do {
//    private _tempModules = [(_posModules select _p),["UO_FW_AI_TemplateModule"]] call UO_FW_AI_fnc_getSyncedModules;
//    for "_t" from 0 to (count _tempModules) step 1 do {
//        [(_tempModules select _t),((_tempModules select _t) getVariable "UO_FW_AI_Template"),_delay,{}] spawn UO_FW_AI_fnc_createZone;
//    };
//};
{
    _x spawn UO_FW_AI_fnc_setRespawn;
} forEach ([_logic,["UO_FW_AI_RespawnModule"]] call UO_FW_AI_fnc_getSyncedModules);
true
