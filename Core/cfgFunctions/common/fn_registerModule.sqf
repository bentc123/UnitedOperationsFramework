/*
 * Author: Olsen
 *
 * Add module to list.
 *
 * Arguments:
 * 0: name <string>
 * 1: description <string>
 * 2: author <string>
 *
 * Return Value:
 * nothing
 *
 * Public: Yes
 */

params ["_name", "_description", "_author"];
private ["_modules", "_module"];
player createDiaryRecord ["UO_FW_Modules", [_name,"<font size='16'>" + _name + "</font><br/>Description: " + _description + "<br/>by " + _author]];
