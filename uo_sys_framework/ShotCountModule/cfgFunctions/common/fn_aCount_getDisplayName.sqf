/*    Description: Gets Magazine Displayname for Ammo Count
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        TinfoilHate
 */

#define COMPONENT ShotCount
#include "\x\UO_FW\addons\Main\script_macros.hpp"
UO_FW_EXEC_CHECK(SERVER);

//IGNORE_PRIVATE_WARNING ["_x"];
params ["_className"];
private _ret = "Error";
if (isNil "UO_FW_ShotCount_classNames") then {UO_FW_ShotCount_classNames = [];};
private _foundClass = UO_FW_ShotCount_classNames findIf {(_x select 0) isEqualto _className};
if (_foundClass isEqualto -1) then {
    private _cfg = (configFile >> "CfgMagazines" >> _className);
    _ret = getText(_cfg >> "displayName");
    UO_FW_ShotCount_classNames pushBack [_className,_ret];
} else {
    _ret = ((UO_FW_ShotCount_classNames select _foundClass) select 1);
};

_ret
