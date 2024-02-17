class CfgFactionClasses {
    class NO_CATEGORY;
    class GVAR(category_base) : NO_CATEGORY {
        displayName = CSTRING(3den_Category_Name_Base);
        priority = 2;
        side = 7;
    };

    class  GVAR(category_general): GVAR(category_base) {
        displayName =  CSTRING(3den_Category_Name_General);
    };

    class GVAR(category_example): GVAR(category_base) {
        displayName =  CSTRING(3den_Category_Name_Example);
    };
};
