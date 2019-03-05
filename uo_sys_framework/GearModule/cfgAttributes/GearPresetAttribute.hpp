class UO_FW_Gear_PresetsCombo_BLUFOR: ComboPreview {
    //save the lbData from the selected entry upon exit
    attributeSave = "\
        private _control = (_this controlsGroupCtrl 100);\
        private _value = ((_this controlsGroupCtrl 100) lbData lbCurSel (_this controlsGroupCtrl 100));\
        _value\
    ";
    //_this - config, _value - saved value
    attributeLoad= QUOTE(_this call EFUNC(Gear,GearPresetAttribute_AttrLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc=100;
        };
        class Preview: Preview {
            idc=101;
            onMouseButtonClick= QUOTE([ARR_2(_this,'BLUFOR')] call EFUNC(Gear,GearPresetAttribute_onMouseClick));
        };
    };
};

class UO_FW_Gear_PresetsCombo_OPFOR: UO_FW_Gear_PresetsCombo_BLUFOR {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc=100;
        };
        class Preview: Preview {
            idc=101;
            onMouseButtonClick= QUOTE([ARR_2(_this,'OPFOR')] call EFUNC(Gear,GearPresetAttribute_onMouseClick));
        };
    };
};

class UO_FW_Gear_PresetsCombo_Indfor: UO_FW_Gear_PresetsCombo_BLUFOR {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc=100;
        };
        class Preview: Preview {
            idc=101;
            onMouseButtonClick= QUOTE([ARR_2(_this,'INDFOR')] call EFUNC(Gear,GearPresetAttribute_onMouseClick));
        };
    };
};

class UO_FW_Gear_PresetsCombo_CIVILIAN: UO_FW_Gear_PresetsCombo_BLUFOR {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc=100;
        };
        class Preview: Preview {
            idc=101;
            onMouseButtonClick= QUOTE([ARR_2(_this,'CIVILIAN')] call EFUNC(Gear,GearPresetAttribute_onMouseClick));
        };
    };
};
