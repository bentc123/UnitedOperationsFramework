
class UO_FW_CaptureZoneModule: OlsenModule
{

	displayName = "Capture Zone (Circle)"; // Name displayed in the menu

	// Name of function triggered once conditions are met
	function = "UO_FW_fnc_CaptureZone";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 0;
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	isGlobal = 1;
	isTriggerActivated = 0;
	isDisposable = 0;
	is3DEN = 1;
	curatorInfoType = "RscDisplayAttributeModuleNuke";
	canSetArea = 1;
	canSetAreaHeight = 0;
	canSetAreaShape = 0;

	class AttributeValues {
    size2[] = {100,100};
		IsRectangle = 0;
  };

	class Attributes
	{
		class UO_FW_CaptureZone_ZoneName
		{
			displayName = "Zone name";
			tooltip = "Name of CaptureZone used in End Conditions reference and in automated message mode. Also a variable that gets set to true once the CaptureZone is captured.";
			property = "UO_FW_CaptureZone_ZoneName";
			control = "Edit";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "''";
			typeName = "STRING";
			validate = "none";
		};
		class UO_FW_CaptureZone_RadiusX {
			displayName = "Activation Radius X";
			tooltip = "The size of the X value of the capture zone. Default: 100";
			property = "UO_FW_CaptureZone_RadiusX";
			control = "UO_FW_moduleradiusControl";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "100";
			typeName = "NUMBER";
			validate = "number";
		};
		class UO_FW_CaptureZone_RadiusY {
			displayName = "Activation Radius Y";
			tooltip = "The size of the Y value of the capture zone. Default: 100";
			property = "UO_FW_CaptureZone_RadiusY";
			control = "UO_FW_moduleradiusControl2";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "100";
			typeName = "NUMBER";
			validate = "number";
		};
		class UO_FW_CaptureZone_RatioNeeded
		{
			displayName = "Ratio Needed";
			tooltip = "Ratio needed to capture the zone. Larger team / team in second place. Set to 0 to make any majority capture. Default: 0.75";
			property = "UO_FW_CaptureZone_RatioNeeded";
			control = "EditShort";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "0.75";
			validate = "NUMBER";
			typeName = "number";
		};
		class UO_FW_CaptureZone_BluforCap
		{
			displayName = "Blufor";
			tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
			property = "UO_FW_CaptureZone_BluforCap";
			control = "UO_FW_CAPTUREZONE_TEAMATTRIBUTE_BLU";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "0";
			typeName = "number";
		};
		class UO_FW_CaptureZone_BluforTime
		{
			displayName = "Blufor Time";
			tooltip = "Time needed for Blufor to capture the zone in seconds. Set to 0 for instant capture";
			property = "UO_FW_CaptureZone_BluforTime";
			control = "EditShort";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "30";
			typeName = "NUMBER";
			validate = "number";
		};
		class UO_FW_CaptureZone_BluforMessage
		{
			displayName = "Blufor Message";
			tooltip = "Message to display when Blufor is capturing the zone and when they capture the zone. Leave empty to disable this hint";
			property = "UO_FW_CaptureZone_BluforMessage";
			control = "EditStringArray";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "['BLUFOR is capturing the zone!','BLUFOR has captured the zone!']";
			validate = "none";
		};
		class UO_FW_CaptureZone_OpforCap
		{
			displayName = "Opfor";
			tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
			property = "UO_FW_CaptureZone_OpforCap";
			control = "UO_FW_CAPTUREZONE_TEAMATTRIBUTE_OPF";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "0";
			typeName = "number";
		};
		class UO_FW_CaptureZone_OpforTime
		{
			displayName = "Opfor Time";
			tooltip = "Time needed for Opfor to capture the zone in seconds. Set to 0 for instant capture";
			property = "UO_FW_CaptureZone_OpforTime";
			control = "EditShort";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "30";
			typeName = "NUMBER";
			validate = "number";
		};
		class UO_FW_CaptureZone_OpforMessage
		{
			displayName = "Opfor Message";
			tooltip = "Message to display when Opfor is capturing the zone and when they capture the zone. Leave empty to disable this hint";
			property = "UO_FW_CaptureZone_OpforMessage";
			control = "EditStringArray";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "['OPFOR is capturing the zone!','OPFOR has captured the zone!']";
			validate = "none";
		};
		class UO_FW_CaptureZone_IndependentCap
		{
			displayName = "Independent";
			tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
			property = "UO_FW_CaptureZone_IndependentCap";
			control = "UO_FW_CAPTUREZONE_TEAMATTRIBUTE_IND";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "0";
			typeName = "number";
		};
		class UO_FW_CaptureZone_IndependentTime
		{
			displayName = "Independent Time";
			tooltip = "Time needed for Independent to capture the zone in seconds. Set to 0 for instant capture";
			property = "UO_FW_CaptureZone_IndependentTime";
			control = "EditShort";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "30";
			typeName = "NUMBER";
			validate = "number";
		};
		class UO_FW_CaptureZone_IndependentMessage
		{
			displayName = "Independent Message";
			tooltip = "Message to display when Independent is capturing the zone and when they capture the zone. Leave empty to disable this hint";
			property = "UO_FW_CaptureZone_IndependentMessage";
			control = "EditStringArray";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "['Independent is capturing the zone!','Independent has captured the zone!']";
			validate = "none";
		};
		class UO_FW_CaptureZone_CivilianCap
		{
			displayName = "Civilian";
			tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
			property = "UO_FW_CaptureZone_CivilianCap";
			control = "UO_FW_CAPTUREZONE_TEAMATTRIBUTE_CIV";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "0";
			typeName = "number";
		};
		class UO_FW_CaptureZone_CivilianTime
		{
			displayName = "Civilian Time";
			tooltip = "Time needed for Civilian to capture the zone in seconds. Set to 0 for instant capture";
			property = "UO_FW_CaptureZone_CivilianTime";
			control = "EditShort";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "30";
			typeName = "NUMBER";
			validate = "number";
		};
		class UO_FW_CaptureZone_CivilianMessage
		{
			displayName = "Civilian Message";
			tooltip = "Message to display when Civilian is capturing the zone and when they capture the zone. Leave empty to disable this hint";
			property = "UO_FW_CaptureZone_CivilianMessage";
			control = "EditStringArray";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "['Civilian is capturing the zone!','Civilian has captured the zone!']";
			validate = "none";
		};
		class UO_FW_CaptureZone_ContestedMessage
		{
			displayName = "Contested Message";
			tooltip = "Message to display when the zone is contested. Leave empty to disable this hint";
			property = "UO_FW_CaptureZone_ContestedMessage";
			control = "Edit";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "'The zone is contested!'";
			typeName = "STRING";
			validate = "none";
		};
		class UO_FW_CaptureZone_UncontestedMessage
		{
			displayName = "Uncontested Message";
			tooltip = "Message to display when the zone is uncontested. Leave empty to disable this hint";
			property = "UO_FW_CaptureZone_UncontestedMessage";
			control = "Edit";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "'The zone is uncontested!'";
			typeName = "STRING";
			validate = "none";
		};
		class UO_FW_CaptureZone_AutoMessages
		{
			displayName = "Automated Messages";
			tooltip = "Enables automated messages based off of zone name. eg. For a zone named 'Everon' and a team called 'USMC', message would be 'USMC is capturing Everon!'";
			property = "UO_FW_CaptureZone_AutoMessages";
			control = "CheckBox";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "false";
			typeName = "BOOL";
			validate = "none";
		};
		class UO_FW_CaptureZone_Colours
		{
			displayName = "Colours";
			tooltip = "Array of colours used for the map markers when zone status changes. Colours are respective with BLUFOR, OPFOR, INDFOR, Civilian, Uncontrolled, and Contested.";
			property = "UO_FW_CaptureZone_Colours";
			control = "EditStringArray";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "['ColorBlue','ColorRed','ColorGreen','ColorYellow','ColorWhite','ColorKhaki']";
			typeName = "STRING";
			validate = "none";
		};
		class UO_FW_CaptureZone_Hidden
		{
			displayName = "Hidden";
			tooltip = "Hides the CaptureZone on the map. No markers are displayed if setting is enabled.";
			property = "UO_FW_CaptureZone_Hidden";
			control = "CheckBox";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "false";
			typeName = "BOOL";
			validate = "none";
		};
		class UO_FW_CaptureZone_Silent
		{
			displayName = "Silent";
			tooltip = "Does not show CaptureZone hints to players. No hints are displayed if this setting is enabled.";
			property = "UO_FW_CaptureZone_Silent";
			control = "CheckBox";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "false";
			typeName = "BOOL";
			validate = "none";
		};
		class UO_FW_CaptureZone_Repeatable
		{
			displayName = "Recapture";
			tooltip = "Can this area be recaptured? If disabled, zone will deactivate once a CaptureZone team captures it.";
			property = "UO_FW_CaptureZone_Repeatable";
			control = "CheckBox";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "true";
			typeName = "BOOL";
			validate = "none";
		};
		class UO_FW_CaptureZone_SleepInterval {
			displayName = "Sleep Interval";
			tooltip = "Time between checking the CaptureZone if no one is in it";
			property = "UO_FW_CaptureZone_SleepInterval";
			control = "EditShort";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "15";
			typeName = "NUMBER";
			validate = "number";
		};
		class UO_FW_CaptureZone_Condition {
			displayName = "Custom Condition";
			tooltip = "Enter a custom condition that must be met for this zone to be captured. Default: true";
			property = "UO_FW_CaptureZone_Condition";
			control = "UO_FW_codeControl";
			expression = "_this setVariable ['%s',_value,true];";
			defaultValue = "''";
		};
	};
};

class UO_FW_CaptureZoneModule_R : UO_FW_CaptureZoneModule {
	displayName = "Capture Zone (Rectangle)";
	class AttributeValues {
      size2[] = {100,100};
			IsRectangle = 1;
    };
};
