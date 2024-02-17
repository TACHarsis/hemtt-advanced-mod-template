
/*
    Preferred Image Size = 256x256
    Can Embed Images Into Description = 1024x512
        - Shadow = '0'
        - Size = '9'
*/
// Default arguments
//
// &lt;br/&gt; - linebreak
// %1 - small empty line
// %2 - bullet (for item in list)
// %3 - highlight start
// %4 - highlight end
// %5 - warning color formated for using in structured text tag
// %6 - BLUFOR color attribute
// %7 - OPFOR color attribute
// %8 - Independent color attribute
// %9 - Civilian color attribute
// %10 - Unknown side color attribute
// added:
// %11 - indent (4 spaces)
// %12 - linebreak

// in arguments:
// {{"getOver"}}, // Double nested array means assigned key (will be specially formatted)
// {"name"}, // Nested array means element (specially formatted part of text)
// "name player" // Simple string will be simply compiled and called, String can also link to localization database in case it starts by str_

#define DEFAULT_ARGUMENTS "'    '", "'<br/>'" // 11th and 12th argument -> %11 and %12

class CfgHints {
    class TestEntry {
        arguments[] = {DEFAULT_ARGUMENTS};
    };
    class Examples {
        displayName = CSTRING(Hints_Examples_Topic_Name);
        category = QGVAR(Examples);
        logicalOrder = 0;

        class Tags: TestEntry {
            logicalOrder = 1;
            arguments[] = {DEFAULT_ARGUMENTS, "'&lt;'", "'&gt;'"}; // adding 13th and 14th argument -> %13 and %14
            displayName = CSTRING(Hints_Examples_Tags_Title);
            displayNameShort = CSTRING(Hints_Examples_Tags_Short);
            description = CSTRING(Hints_Examples_Tags_Description);
        };
    };
    class GVAR(Base_Entry) {
        arguments[] = {DEFAULT_ARGUMENTS};
        image = QUOTE(\z\cTab\cTab_ico.paa);
        tip = "Just a tip: <a href='https://github.com/TACHarsis/catTab/'>GitHub</a>";
    };
};
