////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Sacher, v1.063, #Dyroxu)
////////////////////////////////////////////////////////

#include "..\..\Global\defs.hpp"
class UO_FW_DIA_POLARSPOTTINGFIREMission
{
	idd = PSFM_DIA_IDD_DISPLAY;
	movingEnable = false;
	enableSimulation = true;
	 scriptName = "Dialog_PolarSpottingFiremission";
	controlsBackground[] = {};
	objects[] = {};
	controls[] = {PSFM_BACKGROUND,PSFM_DESCRIPTIONTEXT,PSFM_SELECTEDGUNTEXT,PSFM_SELECTEDSHELLTEXT,PSFM_GRIDTEXT,PSFM_MILSTEXT,PSFM_DISTANCETEXT,PSFM_SELECTEDGUNEDIT,PSFM_SELECTEDSHELLEDIT,PSFM_GRIDEDIT,PSFM_MILSEDIT,PSFM_DISTANCEEDIT,PSFM_FIREBUTTON,PSFM_CANCELBUTTON};
		class PSFM_BACKGROUND: UO_FW_RscText
		{
			idc = -1;
			x = ARTIWIDTHMainSPACE * safezoneW + safezoneX - ARTIBORDERTHICKNESS;
			y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 0) * safezoneH + safezoneY - ARTIBORDERTHICKNESS;
			w =  ( ARTILAYOUTWIDTH +  ARTILAYOUTWIDTHSPACE) *  safezoneW  + ARTIBORDERTHICKNESS * 2 ;
			h = ARTILAYOUTHEIGHTSPACE * 7 * safezoneH + ARTIBORDERTHICKNESS * 2 ;
				shadow = 0;
			colorBackground[] = {0.65,0.65,0.65,0.7};
		};
		class PSFM_DESCRIPTIONTEXT: UO_FW_RscText
		{
			idc = -1;
			text = "Polar Spotting Round"; //--- ToDo: Localize;

			x = ARTIWIDTHMainSPACE * safezoneW + safezoneX;
			y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 0) * safezoneH + safezoneY;
			w = ARTILAYOUTWIDTH * safezoneW;
			h = ARTILAYOUTHEIGHT * safezoneH;
			colorText[] = {0,0,0,1};

	shadow = 0;

		};
	class PSFM_SELECTEDGUNTEXT: UO_FW_RscText
	{
		idc = -1;
		text = "Selected gun:"; //--- ToDo: Localize;

		x = ARTIWIDTHMainSPACE * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 1) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;

		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

	shadow = 0;

	};
	class PSFM_SELECTEDSHELLTEXT: UO_FW_RscText
	{
		idc = -1;
		text = "Aviable ammunition:"; //--- ToDo: Localize;
		x = ARTIWIDTHMainSPACE * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 2) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

		shadow = 0;
	};
	class PSFM_GRIDTEXT: UO_FW_RscText
	{
		idc = -1;
		text = "Caller Grid:"; //--- ToDo: Localize;
		x = ARTIWIDTHMainSPACE * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 3) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

	shadow = 0;
	};
	class PSFM_MILSTEXT: UO_FW_RscText
	{
		idc = -1;
		text = "Mils:"; //--- ToDo: Localize;
		x = ARTIWIDTHMainSPACE * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 4) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

	shadow = 0;
	};
	class PSFM_DISTANCETEXT: UO_FW_RscText
	{
		idc = -1;
		text = "Distance:"; //--- ToDo: Localize;
		x = ARTIWIDTHMainSPACE * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 5) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

	shadow = 0;
	};
	class PSFM_FIREBUTTON: UO_FW_RscButton
	{
		idc = 1430;
		text = "Fire Artillery"; //--- ToDo: Localize;
		x = ARTIWIDTHMainSPACE * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 6) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
	shadow = 0;
			onMouseButtonDown = "[] call UO_FW_FNC_DIA_PolarSpottingFiremissionFire;";
	};
	class PSFM_SELECTEDGUNEDIT: UO_FW_RscListbox
	{
		idc = PSFM_DIA_IDC_GUNSELECT;
		text = ""; //--- ToDo: Localize;
		x = (ARTIWIDTHMainSPACE + ARTILAYOUTWIDTHSPACE) * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 1) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		//colorText[] = {0,1,1,1};
		//
		shadow = 0;
		onLBSelChanged = "(_this select 1) call UO_FW_FNC_DIA_PolarSpottingFiremissionSetArtillery;";
	};
	class PSFM_SELECTEDSHELLEDIT: UO_FW_RscListbox
	{
		idc = PSFM_DIA_IDC_SHELLSELECT;
		text = ""; //--- ToDo: Localize;
		x = (ARTIWIDTHMainSPACE + ARTILAYOUTWIDTHSPACE) * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 2) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
			shadow = 0;
	};
	class PSFM_GRIDEDIT: UO_FW_RscEdit
	{
		idc = PSFM_DIA_IDC_GRID;
		text = ""; //--- ToDo: Localize;
		x = (ARTIWIDTHMainSPACE + ARTILAYOUTWIDTHSPACE) * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 3) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

	shadow = 0;
	};
	class PSFM_MILSEDIT: UO_FW_RscEdit
	{
		idc = PSFM_DIA_IDC_MILS;
		text = ""; //--- ToDo: Localize;
		x = (ARTIWIDTHMainSPACE + ARTILAYOUTWIDTHSPACE) * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 4) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

	shadow = 0;
	};
	class PSFM_DISTANCEEDIT: UO_FW_RscEdit
	{
		idc = PSFM_DIA_IDC_DISTANCE;
		text = ""; //--- ToDo: Localize;
		x = (ARTIWIDTHMainSPACE + ARTILAYOUTWIDTHSPACE) * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 5) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
		colorText[] = {0,0,0,1};

	shadow = 0;
	};
	class PSFM_CANCELBUTTON: UO_FW_RscButton
	{
		idc = 1600;
		text = "Cancel"; //--- ToDo: Localize;
		x = (ARTIWIDTHMainSPACE + ARTILAYOUTWIDTHSPACE) * safezoneW + safezoneX;
		y = (ARTIHEIGHTMainSPACE + ARTILAYOUTHEIGHTSPACE * 6) * safezoneH + safezoneY;
		w = ARTILAYOUTWIDTH * safezoneW;
		h = ARTILAYOUTHEIGHT * safezoneH;
	shadow = 0;
			onMouseButtonDown = "[] call UO_FW_FNC_DIA_PolarSpottingFiremissionCloseDialog;";
	};
};

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////
