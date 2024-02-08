class CfgHintCategories {
    // our own test category
    class GVAR(Examples) {
        // CSTRING is the LLSTRING of the config
        displayName = CSTRING(Hints_Category_Examples);
        // lower numer = higher order
        logicalOrder = 1; // could do 0, maybe even negative if you'd want to.
    };
    // Ace's field manual. Has no logicalOrder set, but due to alphanumeric sorting
    // it is usually the topmost entry. By setting it's order lower, we can make ours
    // float to the top.
    class ACE_FieldManual: ACE_FieldManual {
        logicalOrder = 2;
    };
    // analog with Arma's vanilla entry
    class Arma: Arma {
        logicalOrder = 3;
    };
};
