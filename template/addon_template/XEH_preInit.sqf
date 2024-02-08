#include "script_component.hpp"
ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

ADDON = true;

// included here instead of client or server preInit so they both have access to the settings and server can override settings
#include "initSettings.inc.sqf"
