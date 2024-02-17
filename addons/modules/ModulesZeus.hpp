class EGVAR(Zeus,Module_Base) : ATAG_Module_Base {
    //subCategory = "$STR_AMAE_ZEUS";       // not sure if this does anything
    //Category = "Curator";                 // not sure if this does anything
    category = QGVAR(category_general);
    functionPriority = 1;                   // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
    isGlobal = 1;                           // 0 for server only execution, 1 for global execution, 2 for persistent global execution
    isTriggerActivated = 0;                 // 1 for module waiting until all synced triggers are activated
    curatorCanAttach = 1;                   // this determines whether or not the unit under the cursor is recognized as a mouse over. If 0 or not present the mouseover will instead detect the logic itself

    class AttributesZeusModuleBase : AttributesModuleBase {};
};

class EGVAR(Zeus,Module_Example) : EGVAR(Zeus,Module_Base) {
    scope = 1; // Editor visibility; 2 will show it in the menu, 1 will hide it.
    scopeCurator = 1; // Zeus visibility; 2 will show it in the menu, 1 will hide it.

    // Name displayed in the menu
    displayName = "ATAG Zeus Example!";

    function = QFUNC(ZeusExample);                                      // Name of function triggered once conditions are met (aka you use the zeus ability)
    portrait = "\a3\Modules_F_Curator\Data\portraitFlareGreen_ca.paa";  // displayed in tab and 3D view for zeus modules
};
