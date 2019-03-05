/*	Description: Gives actions to vehicles with AI Driver enabled
 *	Arguments:
 * 		N/A
 *	Return Value:
 * 		ARRAY
 *	Author
 *		PiZZADOX
 */


#define COMPONENT AIDrivers
#include "\x\UO_FW\addons\Main\script_macros.hpp"
UO_FW_EXEC_CHECK(CLIENT);

["UO_FW_AIDrivers_Enabled_Event", {
	params ["_vehicle","_allowNV","_allowFlip"];
	[_vehicle,_allowNV,_allowFlip] call FUNC(EnableAIDriver);
}] call CBA_fnc_addEventHandler;
