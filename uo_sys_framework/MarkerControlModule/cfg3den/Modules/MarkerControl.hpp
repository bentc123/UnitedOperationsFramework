class EGVAR(MarkerControl,Category) {
    displayName = "Marker Control Settings";
    collapsed = 1;
    class Attributes {
        class EGVAR(MarkerControl,Enabled) {
            property = QEGVAR(MarkerControl,Enabled);
            displayName = "Marker Control";
            tooltip = "Enables Marker Control";
            control = "CheckboxState";
            expression = UO_FW_SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class EGVAR(MarkerControl,BluforMarkers) {
            displayName = "Blufor Markers";
            tooltip = "Markers which are only visible by Blufor. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,BluforMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,BluforBriefingMarkers) {
            displayName = "Blufor briefing Markers";
            tooltip = "Markers which are only visible by Blufor during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,BluforBriefingMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,OpforMarkers) {
            displayName = "Opfor Markers";
            tooltip = "Markers which are only visible by Opfor. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,OpforMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,OpforBriefingMarkers) {
            displayName = "Opfor briefing Markers";
            tooltip = "Markers which are only visible by Opfor during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,OpforBriefingMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,IndforMarkers) {
            displayName = "Independent Markers";
            tooltip = "Markers which are only visible by Independent. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,IndforMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,IndforBriefingMarkers) {
            displayName = "Independent briefing Markers";
            tooltip = "Markers which are only visible by Independent during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,IndforBriefingMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,CIVMarkers) {
            displayName = "Civilian Markers";
            tooltip = "Markers which are only visible by Civilian. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,CIVMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,CIVBriefingMarkers) {
            displayName = "Civilian briefing Markers";
            tooltip = "Markers which are only visible by Civilian during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,CIVBriefingMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class EGVAR(MarkerControl,SystemMarkers) {
            displayName = "System Markers";
            tooltip = "Markers which are not visible. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QEGVAR(MarkerControl,SystemMarkers);
            expression = UO_FW_SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
    };
};
