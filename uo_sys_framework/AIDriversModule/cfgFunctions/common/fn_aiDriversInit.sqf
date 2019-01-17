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
UO_FW_EXEC_CHECK(ALL);

if !(UO_FW_Server_AIDRIVERSMODULE_Allowed) exitwith {};
if ((UO_FW_AIDrivers_VehClasses isEqualto "") && {!UO_FW_AIDrivers_AllVehs}) exitwith {};
["AI Drivers", "Module for adding AI Drivers to vehicles", "BlackHawk, PiZZADOX and Sacher"] call UO_FW_fnc_RegisterModule;
private _allowNV = UO_FW_AIDrivers_NVEnabled;
private _allowFlip = UO_FW_AIDrivers_FlipEnabled;

if (UO_FW_AIDrivers_AllVehs) then {
	[{time > 1},{
		{
			[_x,_allowNV,_allowFlip] call UO_FW_fnc_aiDriversEnableAIDriver;
		} foreach vehicles;
	}] call CBA_fnc_WaitUntilAndExecute;
} else {
	if !(UO_FW_AIDrivers_VehClasses isEqualto "") then {
		[{time > 1},{
			{
				if ((typeOf _x) in (UO_FW_AIDrivers_VehClasses)) then {[_x,_allowNV,_allowFlip] call UO_FW_fnc_aiDriversEnableAIDriver;};
			} foreach vehicles;
		}] call CBA_fnc_WaitUntilAndExecute;
	};
};
