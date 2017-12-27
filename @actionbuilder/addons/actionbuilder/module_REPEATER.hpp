class RHNET_ab_moduleREPEATER_F: Module_F {
	author = "Raunhofer";
	_generalMacro = "RHNET_ab_moduleREPEATER_F";
	scope = public;
	displayName = "Repeater";
	category = "RHNET_Actionbuilder";
	icon = "\RHNET\rhnet_actionbuilder\data\iconAP_ca.paa";
	function = "Actionbuilder_fnc_moduleRepeater";
	isGlobal = 0;
	isTriggerActivated = 1;
	functionPriority = 4;
	isDisposable = 0;

	class Attributes: AttributesBase {
		class ActivationMethod: Combo {
			property = "RHNET_ab_moduleREPEATER_F_ActivationMethod";
			displayName = "Activated by";
			tooltip = "How is the repeating triggered.";
			typeName = "STRING";
			defaultValue = """VARIABLE""";
			class Values {
				class RP_AT_VARIABLE {
					name = "Boolean variable";
					value = "VARIABLE"
					default = 1;
				};
                class RP_AT_VALUE {
					name = "Value";
					value = "VALUE"
				};
			};
		};

        class BooleanDescription: Edit {
			property = "RHNET_ab_moduleREPEATER_F_BooleanDescription";
            description = "Boolean variable activator activates the repeater every time the given boolean switches to TRUE. If the variable is toggled, the variable will switch back to FALSE after a successful repeat.";
			displayName = "";
			tooltip = "";
			control = "SubCategoryNoHeader2";
            data = "AttributeSystemSubcategory"
		};

        class BooleanVariable: Edit {
			property = "RHNET_ab_moduleREPEATER_F_BooleanVariable";
			displayName = "Boolean variable";
			tooltip = "Boolean variable to be monitored.";
			typeName = "STRING";
			control = "EditShort";
		};

        class ToggleVariable: Checkbox {
			property = "RHNET_ab_moduleREPEATER_F_ToggleVariable";
			displayName = "Toggle variable";
			tooltip = "Whether to switch Varible to FALSE after execution.";
			typeName = "BOOL";
            defaultValue = "true";
		};

        class ValueDescription: Edit {
			property = "RHNET_ab_moduleREPEATER_F_ValueDescription";
            description = "Value activator activates the repeater every time the given value condition is true.";
			displayName = "";
			tooltip = "";
			control = "SubCategoryNoHeader2";
            data = "AttributeSystemSubcategory"
		};

        class ValueCondition: Combo {
			property = "RHNET_ab_moduleREPEATER_F_ValueCondition";
			displayName = "Value condition";
			tooltip = "What is the value limiter for the repeater to activate.";
			typeName = "STRING";
			defaultValue = """VARIABLE""";
			class Values {
                class RP_VT_MOREPLAYERS {
					name = "More players alive than Value";
					value = "PLAYERS"
				};
				class RP_VT_LESSUNITS {
					name = "Fewer units alive than Value";
					value = "UNITS"
				};
                class RP_VT_LESSTHANWEST {
                    name = "Fewer BLUFOR units alive than Value";
					value = "WEST"
                };
                class RP_VT_LESSTHANEAST {
                    name = "Fewer OPFOR units alive than Value";
					value = "EAST"
					default = 1;
                };
                class RP_VT_LESSTHANINDEPENDENT {
                    name = "Fewer INDEPENDENT units alive than Value";
					value = "INDEPENDENT"
                };
                class RP_VT_LESSTHANCIVILIAN {
                    name = "Fewer CIVILIAN units alive than Value";
					value = "CIVILIAN"
                };
			};
		};

        class Value: Edit {
			property = "RHNET_ab_moduleREPEATER_F_Value";
			displayName = "Value";
			tooltip = "Value to be monitored.";
			typeName = "NUMBER";
            defaultValue = "0";
			control = "EditShort";
		};

        class OptionsDescription: Edit {
			property = "RHNET_ab_moduleREPEATER_F_OptionsDescription";
            description = "With options below you can further adjust this repeater, no matter which activator you selected.";
			displayName = "";
			tooltip = "";
			control = "SubCategoryNoHeader2";
            data = "AttributeSystemSubcategory"
		};

        class RepeatInterval: Edit {
			property = "RHNET_ab_moduleREPEATER_F_DelayBetweenRepeats";
			displayName = "Repeat interval";
			tooltip = "Delay between repeats in seconds (1: minimum allowed).";
			typeName = "NUMBER";
            defaultValue = "1";
			control = "EditShort";
		};

        class MaximumRepeats: Edit {
			property = "RHNET_ab_moduleREPEATER_F_MaximumRepeats";
			displayName = "Maximum repeats";
			tooltip = "How many times can this repeater trigger (-1: no limit).";
			typeName = "NUMBER";
            defaultValue = "0";
			control = "EditShort";
		};

        class MonitorFPS: Checkbox {
			property = "RHNET_ab_moduleREPEATER_F_MonitorFPS";
			displayName = "Monitor FPS";
			tooltip = "If enabled, the execution will halt until the server FPS is higher than 20.";
			typeName = "BOOL";
            defaultValue = "true";
		};
	};
};
