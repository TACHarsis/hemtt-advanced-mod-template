
class CBA_Extended_EventHandlers_base;

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class ModuleDescription {
            class AnyPlayer;
            class AnyBrain;
            class EmptyDetector;
        };

        class AttributesBase {
            class Default;
            class Edit;                     // Default edit box (i.e., text input field)
            class Combo;                    // Default combo box (i.e., drop-down menu)
            class ModuleDescription;        // Module description
            class Units;                    // Selection of units on which the module is applied
            class Checkbox;
            class CheckboxNumber;
        };
    };

    class ATAG_Module_Base : Module_F {
        mapSize = 1;                        // size of icon in map screen?
        author = "Your Name";
        vehicleClass = "Modules";           // so it shows up in the right tab
        category = QGVAR(category_base);    // as defined in CfgFactionClasses
        side = 7;                           // ?

        scope = 1;                          // Editor visibility; 2 will show it in the menu, 1 will hide it.
        scopeCurator = 1;                   // Curator visibility; 2 will show it in the menu, 1 will hide it.

        displayName = "ATAG Module Base";    // Name displayed in the menu
        //icon = "";                // Map icon. If defined it will replace the default icon
        // properties "picture" and "portrait" might or might not get used, idk

        function = "";                      // Name of function triggered once conditions are met
        functionPriority = 1;               // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
        isGlobal = 1;                       // 0 for server only execution, 1 for remote execution on all clients upon mission start, 2 for persistent execution
        isTriggerActivated = 0;             // 1 for module waiting until all synced triggers are activated
        isDisposable = 0;                   // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)

        curatorInfoType = "";               // Menu displayed when the module is placed or double-clicked on by Zeus, defined in RscTitles

        // 3DEN Attributes Menu Options
        canSetArea = 1;                     // Allows for setting the area values in the Attributes menu in 3DEN
        canSetAreaShape = 1;                // Allows for setting "Rectangle" or "Ellipse" in Attributes menu in 3DEN
        canSetAreaHeight = 1;               // Allows for setting height or Z value in Attributes menu in 3DEN

        //dlc = "ATAG";                     // Don't think this does anything

        class Arguments {};

        class AttributesModuleBase : AttributesBase {
            // for an attribute to properly be set as a variable on the module during runtime it needs to have:
            // * a displayName that is not empty
            // * a property name that is not empty
            // * a default value that is not nil
            // We are not inhering here from anything, since we define everything ourselves as an (invisible) example,
            // but usually you would inherit from a class as defined in AttributesBase above.
            // For predefined calsses variable name on the object is *not* the property name, no matter what the wiki says, but the *class name* itself by default
            // if you want to change that, you need to change the expression property
            class DummyAttribute {
                control = "Title";                                      // Title doesn't show anything by default, for other controls see https://community.bohemia.net/wiki/Eden_Editor:_Configuring_Attributes:_Controls
                property = QGVAR(ATAG_Dummy_Attribute);                 // see notes above
                displayName = "A human readable name";                  // Argument label in editor
                tooltip = "A human readable tooltip";                   // Tooltip description in editor
                defaultValue = """""";                                  // Default attribute value. WARNING: This is an expression, and its returned value will be used.
                // sextuple quotes will become "" in editor, only way to make empty string default value
                expression = "_this setVariable ['%s', _value];";       // default expression, will use class name (%s gets replaced by class name) as variable name
            };
        };

        // Description base classes. It holds the information only, it is not a display or ctrl in itself!
        class ModuleDescription: ModuleDescription {
            description = "ATAG Module Base";
            class Anything;
            class AnyPerson;
            class AnyVehicle;
            class AnyStaticObject;
            class AnyBrain;
            class AnyAI;
            class AnyPlayer;
            class Curator_F;
            class EmptyDetector;
        };

        class EventHandlers {
              init = QUOTE(_this call bis_fnc_moduleInit;);
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
    };
    #include "Modules3den.hpp"
    #include "ModulesZeus.hpp"
};
