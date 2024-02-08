#include "script_component.hpp"

// Q denotes a QUOTED version of a macro. We set the name of the variable as first argument
//   and the actual variable (or her value) as second argument
systemChat format ["Setting (%1) is %2", QGVAR(enableAddon), GVAR(enableAddon)];
