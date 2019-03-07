/*
 * Author: Olsen
 *
 * Adds new team.
 *
 * Arguments:
 * 0: side of new team <side>
 * 1: name of new team <string>
 * 2: type of new team: "ai"/"player"/"both" <string>
 *
 * Return Value:
 * nothing
 *
 * Public: Yes
 */

#define COMPONENT Core
#include "\x\UO_FW\addons\Main\script_macros.hpp"
UO_FW_EXEC_CHECK(SERVER);

params [["_side", sideUnknown, [sideUnknown]],["_name", "Unknown", [""]],["_Type", "both", [""]]];

if (isMultiplayer) then {
    MGVAR(Teams) set [count MGVAR(Teams), [_name, _side, _Type,  0, 0, [], []]];
} else {
    MGVAR(Teams) set [count MGVAR(Teams), [_name, _side, "both",  0, 0, [], []]];
};
