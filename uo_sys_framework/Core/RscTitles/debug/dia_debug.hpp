//Do not edit unless you know what you are doing
//because you are on the highway to the danger zone!

class EGVAR(DIA,DEBUG) {
    idd = 400;
    fadeout = 0;
    fadein = 0;
    duration = 360;
    onLoad = QUOTE(uiNamespace setVariable [QN(EGVAR(Debug,Control)), _this select 0];);
    class controlsBackground {
        class SOME_TEXT:  UO_FW_RscStructuredText {
            idc = 4001;
            x = 0 * safezoneW + safezoneX;
            y = 0 * safezoneH + safezoneY;
            w = 0.5 * safezoneW;
            h = 1 * safezoneH;
        };
    };
};
