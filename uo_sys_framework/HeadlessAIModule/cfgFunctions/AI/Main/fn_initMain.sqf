#include "\x\UO_FW\addons\main\HeadlessAIModule\module_macros.hpp"
UO_FW_EXEC_CHECK(HC)

if (!(getMissionConfigValue ["UO_FW_AI_DEBUG",false])) then {
	diag_log "running fn_initMain";
};

if (!(getMissionConfigValue ["UO_FW_AI_Enabled",false])) exitWith {};

UO_FW_AI_MARKERARRAY = [];
UO_FW_AI_UnitQueue = [];
UO_FW_AI_ActiveList = [];
UO_FW_AI_TrackedUnits = [];
UO_FW_AI_BasicCheckCurrent = 0;
UO_FW_AI_LeaderExecuteCurrent = 0;

////Settings to be put in 3den AI settings menu
//Will AI garrison static weapons nearby?
UO_FW_AI_STATICGARRISON = 1;
//Should we let AI use flanking manuevers? false means they can flank
UO_FW_AI_REINFORCE = false;
//Should AI use smoke grenades? Besides default A3 behavior?
UO_FW_AI_USESMOKE = true;
//Chance of AI using grenades
UO_FW_AI_GRENADECHANCE = 35;
//AI will automatically disembark from vehicles when in combat.
UO_FW_AI_AIDisembark = true;
//How low should an AI's mag count be for them to consider finding more ammo? This DOES NOT include the mag loaded in the gun already.
UO_FW_AI_AIMagLimit = 2;
//Should the rain impact accuracy of AI? DEFAULT = true;
UO_FW_AI_RainImpact = true;
//How much should rain impact the accuracy of AI? Default = 3. Default formula is -> _WeatherCheck = (rain)/3; "rain" is on a scale from 0 to 1. 1 Being very intense rain.
UO_FW_AI_RainPercent = 3;
//Should AI and players have an additional layer of suppression that decreases aiming when suppressed? Default = true;
UO_FW_AI_Suppression = false;
//How much should suppression impact both AI and player aiming? Default is 5. Normal ArmA is 1.
UO_FW_AI_SuppressionVar = 5;
//Should AI/players be impacted by adrenaline? This provides players and AI with a small speed boost to animations to assist with cover seeking and positioning for a short time. Default = true;
UO_FW_AI_Adrenaline = false;
//How much of a speed boost should players/AI recieve? Default = 1.35; (1 is ArmA's normal speed).
UO_FW_AI_AdrenalineVar = 1.35;
//How many AI UNITS can be calculating cover positions at once?
UO_FW_AI_CurrentlyMovingLimit = 24;
//How many AI UNITS can be suppressing others at once?
UO_FW_AI_CurrentlySuppressingLimit = 40;
//How many AI can be checking roles/equipment/additional commands at once? This will impact FPS of AI in and out of battle. The goal is to limit how many benign commands are being run at once and bogging down a server with over a couple HUNDRED AI.
UO_FW_AI_BasicCheckLimit = 40;
//How many squad leaders can be executing advanced code at once.
UO_FW_AI_LeaderExecuteLimit = 20;
//How low should the FPS be, before Vcom pauses simulation. This will not disable simulation on AI - they will run default Bohemia AI.
UO_FW_AI_FPSFreeze = 10;
//Should the AI notice IR lasers?
UO_FW_AI_IRLaser = true;
//The longer an AI's target stays in 1 location, the more accurate and aware of the target the AI becomes.DEFAULT = [WEST,EAST,CIVILIAN,RESISTANCE];
UO_FW_AI_IncreasingAccuracy = true;
//UO_FW_AI_SideBasedMovement- Remove sides from the array below to force that specific AI side to not execute any advance movement code. (I.E. Moving to reinforce allies, being alerted by distant gunshots and etc). AI with this will still react normally in combat. DEFAULT = [WEST,EAST,CIVILIAN,RESISTANCE];
UO_FW_AI_SideBasedMovement = [WEST,EAST,RESISTANCE,CIVILIAN];
//UO_FW_AI_SideBasedExecution- Remove sides from the array below to remove that specific AI side from executing any of the VCOMAI scripts at all. DEFAULT = [WEST,EAST,CIVILIAN,RESISTANCE];
UO_FW_AI_SideBasedExecution = [WEST,EAST,RESISTANCE,CIVILIAN];
//Whether the AI will set up campfires at night if they are set to "DISMISS" waypoint
UO_FW_AI_Campfires = true;
//Distance the AI will attempt to flank around the enemy. I.E. How far off a waypoint, or around the enemy squad, the AI are willing to go in combat.
UO_FW_AI_WaypointDistance = 300;
//The distance a unit needs to be away for PZAI scripts to temporary disable itself upon the unit? The AI unit will also need to be out of combat.
UO_FW_AI_DisableDistance = 3000;
//Aid to the AI spotting distance and time
UO_FW_AI_SIGHTAID_ENABLED = true;
//Distance at which the AI will start seeings enemies in LOS of them
UO_FW_AI_SightAid_Distance = 800;
//Minimum reveal value per increase +n reveal value per check every 5 seconds of targets in LOS of enemies.
UO_FW_AI_SightAid_MinIncrease = 2;
//Distance at which the AI will force engage the enemies
UO_FW_AI_SightAid_EngageDistance = 400;
//How far can the AI hear gunshots from?
UO_FW_AI_HearingDistance = 1400;
//How revealed an enemy is from a gunshot report
UO_FW_AI_HearingMinIncrease = 1;
//Distance a bunker enemy can see/engage the enemy
UO_FW_AI_Bunker_Enabled = true;
//Distance a bunker enemy can see/engage the enemy
UO_FW_AI_Bunker_Distance = 900;
//Whether Bunker AI get released and act normally/free to move if enemies get too close
UO_FW_AI_Bunker_Release = true;
//Sensitivity/Sightlevel needed for Bunker AI to engage - lower is more sensitive.
UO_FW_AI_Bunker_Sightlevel = 0.25;
//Distance at which AI are released from bunker
UO_FW_AI_Bunker_Release_Dist = 25;
//Distance AI will respond to call of help from each other
UO_FW_AI_Radio_Distance = 1200;
//Whether or not AI need ACRE radios to broadcast info to other groups
UO_FW_AI_Radio_NeedRadio = false;
//Distance the AI will patrol to by default when set to "GUARD" waypoint
UO_FW_AI_PatrolDistance = 200;
//Whether the AI will patrol between garrison positions. Pretty buggy, but nice for 'mersion
UO_FW_AI_GarrisonPatrol = true;
UO_FW_AI_FORCETIME_ENABLED = false;
UO_FW_AI_FORCETIME_TIME = 12;

//Lets gets the queue handler going
[] spawn UO_FW_AI_fnc_QueueHandle;
[] spawn UO_FW_AI_fnc_ActiveHandler;
[] spawn UO_FW_AI_fnc_GroupHandler;

//leader/group behavior handling loop
//[] spawn UO_FW_AI_fnc_MainLoop;

//marker function
if (UO_FW_AI_MARKERS_ENABLED) then {
	[] spawn UO_FW_AI_fnc_MapMarkers;
};

if ((!hasinterface) && (!isDedicated)) then {
	setViewDistance (missionNamespace getvariable ["UO_FW_AI_ViewDistance",2500]);

	if (UO_FW_AI_FORCETIME_ENABLED) then {
		[] spawn {
			waituntil {time > 1};
			while {true} do {
				sleep 2;
				skiptime ((missionnamespace getvariable ["UO_FW_AI_FORCETIME_TIME",daytime]) / 3600) - daytime;
			};
		};
	};
};
