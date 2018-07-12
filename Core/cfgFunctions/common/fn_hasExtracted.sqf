/*
 * Author: BlackHawk
 *
 * Checks if given part of team has extracted to set area.
 * This function accounts for team starting in extraction area.
 *
 * Arguments:
 * 0: team name <string>
 * 1: extraction area marker <string>
 * 2: part of team that has to extract (0.8 - 80%, etc.) <number> (OPTIONAL)
 *
 * Return Value:
 * has team extracted <bool>
 *
 * Public: Yes
 */

params [["_team", "", [""]],
	["_marker", "", [""]],
	["_ratio", 1, [0]]
];
private _side = [_team, 1] call UO_FW_fnc_getTeamVariable;
private _count = {
	side _x == _side && [_x, _marker] call UO_FW_fnc_inArea
} count allUnits;

private _result = false;
if (_count >= _ratio * ([_team, 4] call UO_FW_fnc_getTeamVariable)) then {
<<<<<<< HEAD:Core/cfgFunctions/common/fn_hasExtracted.sqf
	if (!isNil "FW_hasDeparted" && {FW_hasDeparted}) then {
=======
	if (!isNil "UO_FW_hasDeparted" && {UO_FW_hasDeparted}) then {
>>>>>>> f75aeeae1c4f987e0e243f43ae618bbedbe3dec7:Core/cfgFunctions/common/fn_hasExtracted.sqf
		_result = true;
	};
}
else {
	UO_FW_hasDeparted = true;
};
_result