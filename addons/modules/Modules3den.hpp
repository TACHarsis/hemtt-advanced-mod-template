class ATAG_3den_Module_Base: ATAG_Module_Base {
    //subCategory = "$STR_AMAE_ZEUS";       // not sure if this does anything
    //Category = "Curator";                 // not sure if this does anything
    category = QGVAR(category_general);     // as defined in CfgFactionClasses
    class Attributes3denModuleBase : AttributesModuleBase {
        //Arguments shared by specific module type (have to be mentioned in order to be present)
        class Units: Units {
            property = "ATAG_TEST_Units";
        };
    };
};

class ATAG_3den_Module_Test: ATAG_3den_Module_Base {
    scope = 2;
    scopeCurator = 1; // Zeus visibility; 2 will show it in the menu, 1 will hide it.

    displayName = "ATAG 3den Example!";                                 // Name displayed in the menu
    function = QFUNC(3denExample);                                      // Name of function triggered once conditions are met (aka all connected triggers are active or the mission starts, depending on your settings, also run in 3den if set up that way)
    icon = "\a3\Modules_F_Curator\Data\portraitFlareRed_ca.paa";      // displayed in tab and 3D view for 3den modules
    functionPriority = 1;                                               // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
    isGlobal = 1;                                                       // 0 for server only execution, 1 for global execution, 2 for persistent global execution (no clue what persistent means in this context)
    isTriggerActivated = 0;                                             // 1 for module waiting until all synced triggers are activated

    //Module attributes, uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific
    class Attributes: Attributes3denModuleBase {

        //Module specific arguments
        class Yield: Combo {
            // Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
            property = QGVAR(ATAG_TEST_Yield);
            displayName = "Nuclear weapon yield"; // Argument label
            tooltip = "How strong will the explosion be"; // Tooltip description
            typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
            defaultValue = "50"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
            class Values {
                class 50Mt    {name = "50 megatons";    value = 50;}; // Listbox item
                class 100Mt    {name = "100 megatons"; value = 100;};
            };
        };
        class Yield2: Combo {
            // Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
            property = "ATAG_TEST2_Yield";
            displayName = "Nuclear weapon yield2"; // Argument label
            tooltip = "How strong will the explosion be"; // Tooltip description
            typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
            defaultValue = "5"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
            class Values {
                class 50Mt    {name = "5130 megatons";    value = 5;}; // Listbox item
                class 100Mt    {name = "11300 megatons"; value = 10;};
            };
        };
        class Names: Edit {
            displayName = "Namess";
            tooltip = "Name of the device";
            property = "ATAG_TEST2_Name";
            // Default text filled in the input box
            // Because it is an expression, to return a String one must have a string within a string
            defaultValue = """DAT Bomba""";
        };
        // this is the actual entry that will show the information from the ModuleDescription below
        class ModuleDescription: ModuleDescription{}; // Module description should be shown last
    };

    // Module description. Must inherit from base class, otherwise pre-defined entities won't be available.
    // Only holds information, display is in the attributes!
    // Note that none of the settings below have any effect beyond adding/changing/removing information shown.
    // E.g. whether you set duplicate to 1 or 0 has no effect ingame except the module description saying one thing or another
    class ModuleDescription: ModuleDescription {
        description = "Short ATAG_Module_3den_Test module description"; // Short description, will be formatted as structured text

        sync[] = {"LocationArea_F"};                // Array of synced entities (can contain base classes)

        class LocationArea_F {
            description[] = {                       // Multi-line descriptions are supported
                "First line",
                "Second line"
            };
            position = 1;                           // Position is taken into effect
            direction = 1;                          // Direction is taken into effect
            optional = 1;                           // Synced entity is optional
            duplicate = 1;                          // Multiple entities of this type can be synced
            synced[] = {"BLUFORunit", "AnyBrain"};  // Pre-define entities like "AnyBrain" can be used. See the list below
        };
        class BLUFORunit {
            description = "Short description";
            displayName = "Any BLUFOR unit";        // Custom name
            icon = "iconMan";                       // Custom icon (can be file path or CfgVehicleIcons entry)
            side = 1;                               // Custom side (will determine icon color)
        };
    };
};
