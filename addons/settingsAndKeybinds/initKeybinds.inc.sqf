
// CBA_fnc_addKeybind Parameters:
//  _modName           Name of the registering mod [String]
//  _actionId          Id of the key action. [String]
//  _displayName       Pretty name, or an array of strings for the pretty name and a tool tip [String]
//  _downCode          Code for down event, empty string for no code. [Code]
//  _upCode            Code for up event, empty string for no code. [Code]

//  Optional:
//  _defaultKeybind    The keybinding data in the format [DIK, [shift, ctrl, alt]] [Array]
//  _holdKey           Will the key fire every frame while down [Bool]
//  _holdDelay         How long after keydown will the key event fire, in seconds. [Float]
//  _overwrite         Overwrite any previously stored default keybind [Bool]

// Returns:
//  Returns the current keybind for the action [Array]

// including this file for readable keycodes
#include "\a3\ui_f\hpp\defineDIKCodes.inc"

// Additional DIK codes usable with addKeybind
//      0xFA    :   Custom user action 1            0x104   :  Custom user action 11        0xF0    :   Left mouse button
//      0xFB    :   Custom user action 2            0x105   :  Custom user action 12        0xF1    :   Right mouse button
//      0xFC    :   Custom user action 3            0x106   :  Custom user action 13        0xF2    :   Middle mouse button
//      0xFD    :   Custom user action 4            0x107   :  Custom user action 14        0xF3    :   Mouse #4
//      0xFE    :   Custom user action 5            0x108   :  Custom user action 15        0xF4    :   Mouse #5
//      0xFF    :   Custom user action 6            0x109   :  Custom user action 16        0xF5    :   Mouse #6
//      0x100   :  Custom user action 7             0x10A   :  Custom user action 17        0xF6    :   Mouse #7
//      0x101   :  Custom user action 8             0x10B   :  Custom user action 18        0xF7    :   Mouse #8
//      0x102   :  Custom user action 9             0x10C   :  Custom user action 19        0xF8    :   Mouse wheel up
//      0x103   :  Custom user action 10            0x10D   :  Custom user action 20        0xF9    :   Mouse wheel down


#define KEYBIND_NULL [0, [false, false, false]] // [keyCode, [shift, ctrl, alt]]

private _modCategory = LLSTRING(Name_Mod);
private _addonCategory = LLSTRING(Name_Addon);

[
    _modCategory, // category this keybind will appear in (under Controls -> Addons)
    QGVAR(exampleKey), // string identifier of keybind
    [LLSTRING(Keybind_Example_Key), LLSTRING(Keybind_Example_Key_Hint)], // display name and optional hit of keybind
    {   // action to call when key(combo) is pressed
        systemChat "Example Keybind was pressed (Key Down Event)";
    },
    {   // action to call when key(combo) is released
        systemChat "Example Keybind was released (Key UP Event)";
    },
    [DIK_SPACE, [false, false, false]], // default keybind [keyCode, [shift, ctrl, alt]]
    false,      // hold key - whether or not it fires each frame while held down
    0,          // delay - how long to wait when pressed before firing - in (fractions of) seconds
    true        // overwrite preexisting default/stored keybind
] call cba_fnc_addKeybind;

[
    _modCategory,
    QGVAR(enabledTestKey),
    [LLSTRING(Keybind_Addon_Enabled), LLSTRING(Keybind_Addon_Enabled_Hint)],
    {
        if(GVAR(enableAddon)) then {
            systemChat QUOTE(ADDON enabled); // using QUOTE macro so we can make use of the
        } else {
            systemChat QUOTE(ADDON disabled); // ADDON macro, which would not work in double quotes
        };
    },
    "", // no key up code
    [DIK_HOME, [false, false, false]]
] call cba_fnc_addKeybind;
