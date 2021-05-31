// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 

//paste colors here
uint8_t neighbors [1072][16] = { {1,2,3,4,5,6,7}, {2,0,3,4,5,6,7,8}, {3,1,4,0,5,6,7,8,9}, {4,2,5,1,6,0,7,8,9,10}, {5,3,6,2,7,1,8,0,9,10,11}, {6,4,7,3,8,2,9,1,10,0,11,12}, {7,5,8,4,9,3,10,2,11,1,12,0,13}, {8,6,9,5,10,4,11,3,12,2,13,1,14,0}, {9,7,10,6,11,5,12,4,13,3,14,2,15,1}, {10,8,11,7,12,6,13,5,14,4,15,3,16,2}, {11,9,12,8,13,7,14,6,15,5,16,4,17,3}, {12,10,13,9,14,8,15,7,16,6,17,5,18,4}, {13,11,14,10,15,9,16,8,17,7,18,6,19,5}, {14,12,15,11,16,10,17,9,18,8,19,7,20,6}, {15,13,16,12,17,11,18,10,19,9,20,8,21,7}, {16,14,17,13,18,12,19,11,20,10,21,9,22,8}, {17,15,18,14,19,13,20,12,21,11,22,10,23,9}, {18,16,19,15,20,14,21,13,22,12,23,11,24,10}, {19,17,20,16,21,15,22,14,23,13,24,12,25,11}, {20,18,21,17,22,16,23,15,24,14,25,13,26,12}, {21,19,22,18,23,17,24,16,25,15,26,14,27,13}, {22,20,23,19,24,18,25,17,26,16,27,15,28,14}, {23,21,24,20,25,19,26,18,27,17,28,16,29,15}, {24,22,25,21,26,20,27,19,28,18,29,17,30,16}, {25,23,26,22,27,21,28,20,29,19,30,18,31,17}, {26,24,27,23,28,22,29,21,30,20,31,19,32,18}, {27,25,28,24,29,23,30,22,31,21,32,20,33,19}, {28,26,29,25,30,24,31,23,32,22,33,21,34,20}, {29,27,30,26,31,25,32,24,33,23,34,22,35,21}, {30,28,31,27,32,26,33,25,34,24,35,23,36,22}, {31,29,32,28,33,27,34,26,35,25,36,24,37,23}, {32,30,33,29,34,28,35,27,36,26,37,25,38,24}, {33,31,34,30,35,29,36,28,37,27,38,26,39,25}, {34,32,35,31,36,30,37,29,38,28,39,27,40,26}, {35,33,36,32,37,31,38,30,39,29,40,28,41,27}, {36,34,37,33,38,32,39,31,40,30,41,29,42,28}, {37,35,38,34,39,33,40,32,41,31,42,30,43,29}, {38,36,39,35,40,34,41,33,42,32,43,31,44,30}, {39,37,40,36,41,35,42,34,43,33,44,32,45,31}, {40,38,41,37,42,36,43,35,44,34,45,33,46,32}, {41,39,42,38,43,37,44,36,45,35,46,34,47,33}, {42,40,43,39,44,38,45,37,46,36,47,35,48,34}, {43,41,44,40,45,39,46,38,47,37,48,36,49,35}, {44,42,45,41,46,40,47,39,48,38,49,37,50,36}, {45,43,46,42,47,41,48,40,49,39,50,38,51,37}, {46,44,47,43,48,42,49,41,50,40,51,39,52,38}, {47,45,48,44,49,43,50,42,51,41,52,40,53,39}, {48,46,49,45,50,44,51,43,52,42,53,41,54,40}, {49,47,50,46,51,45,52,44,53,43,54,42,55,41}, {50,48,51,47,52,46,53,45,54,44,55,43,56,42}, {51,49,52,48,53,47,54,46,55,45,56,44,57,43}, {52,50,53,49,54,48,55,47,56,46,57,45,58,44}, {53,51,54,50,55,49,56,48,57,47,58,46,59,45}, {54,52,55,51,56,50,57,49,58,48,59,47,60,46}, {55,53,56,52,57,51,58,50,59,49,60,48,61,47}, {56,54,57,53,58,52,59,51,60,50,61,49,62,48}, {57,55,58,54,59,53,60,52,61,51,62,50,63,49}, {58,56,59,55,60,54,61,53,62,52,63,51,64,50}, {59,57,60,56,61,55,62,54,63,53,64,52,65,51}, {60,58,61,57,62,56,63,55,64,54,65,53,66,52}, {61,59,62,58,63,57,64,56,65,55,66,54,67,53}, {62,60,63,59,64,58,65,57,66,56,67,55,68,54}, {63,61,64,60,65,59,66,58,67,57,68,56,69,55}, {64,62,65,61,66,60,67,59,68,58,69,57,70,56}, {65,63,66,62,67,61,68,60,69,59,70,58,71,57}, {66,64,67,63,68,62,69,61,70,60,71,59,72,58}, {67,65,68,64,69,63,70,62,71,61,72,60,73,59}, {68,66,69,65,70,64,71,63,72,62,73,61,74,60}, {69,67,70,66,71,65,72,64,73,63,74,62,75,61}, {70,68,71,67,72,66,73,65,74,64,75,63,76,62}, {71,69,72,68,73,67,74,66,75,65,76,64,77,63}, {72,70,73,69,74,68,75,67,76,66,77,65,78,64}, {73,71,74,70,75,69,76,68,77,67,78,66,79,65}, {74,72,75,71,76,70,77,69,78,68,79,67,80,66}, {75,73,76,72,77,71,78,70,79,69,80,68,81,67}, {76,74,77,73,78,72,79,71,80,70,81,69,82,68}, {77,75,78,74,79,73,80,72,81,71,82,70,83,69}, {78,76,79,75,80,74,81,73,82,72,83,71,84,70}, {79,77,80,76,81,75,82,74,83,73,84,72,85,71}, {80,78,81,77,82,76,83,75,84,74,85,73,86,72}, {81,79,82,78,83,77,84,76,85,75,86,74,87,73}, {82,80,83,79,84,78,85,77,86,76,87,75,88,74}, {83,81,84,80,85,79,86,78,87,77,88,76,89,75}, {84,82,85,81,86,80,87,79,88,78,89,77,90,76}, {85,83,86,82,87,81,88,80,89,79,90,78,91,77}, {86,84,87,83,88,82,89,81,90,80,91,79,92,78}, {87,85,88,84,89,83,90,82,91,81,92,80,93,79}, {88,86,89,85,90,84,91,83,92,82,93,81,94,80}, {89,87,90,86,91,85,92,84,93,83,94,82,95,81}, {90,88,91,87,92,86,93,85,94,84,95,83,96,82}, {91,89,92,88,93,87,94,86,95,85,96,84,97,83}, {92,90,93,89,94,88,95,87,96,86,97,85,98,84}, {93,91,94,90,95,89,96,88,97,87,98,86,99,85}, {94,92,95,91,96,90,97,89,98,88,99,87,100,86}, {95,93,96,92,97,91,98,90,99,89,100,88,101,87}, {96,94,97,93,98,92,99,91,100,90,101,89,102,88}, {97,95,98,94,99,93,100,92,101,91,102,90,103,89}, {98,96,99,95,100,94,101,93,102,92,103,91,104,90}, {99,97,100,96,101,95,102,94,103,93,104,92,105,91}, {100,98,101,97,102,96,103,95,104,94,105,93,106,92}, {101,99,102,98,103,97,104,96,105,95,106,94,107,93}, {102,100,103,99,104,98,105,97,106,96,107,95,108,94}, {103,101,104,100,105,99,106,98,107,97,108,96,109,95}, {104,102,105,101,106,100,107,99,108,98,109,97,110,96}, {105,103,106,102,107,101,108,100,109,99,110,98,111,97}, {106,104,107,103,108,102,109,101,110,100,111,99,112,98}, {107,105,108,104,109,103,110,102,111,101,112,100,113,99}, {108,106,109,105,110,104,111,103,112,102,113,101,114,100}, {109,107,110,106,111,105,112,104,113,103,114,102,115,101}, {110,108,111,107,112,106,113,105,114,104,115,103,116,102}, {111,109,112,108,113,107,114,106,115,105,116,104,117,103}, {112,110,113,109,114,108,115,107,116,106,117,105,118,104}, {113,111,114,110,115,109,116,108,117,107,118,106,119,105}, {114,112,115,111,116,110,117,109,118,108,119,107,120,106}, {115,113,116,112,117,111,118,110,119,109,120,108,121,107}, {116,114,117,113,118,112,119,111,120,110,121,109,122,108}, {117,115,118,114,119,113,120,112,121,111,122,110,123,109}, {118,116,119,115,120,114,121,113,122,112,123,111,124,110}, {119,117,120,116,121,115,122,114,123,113,124,112,125,111}, {120,118,121,117,122,116,123,115,124,114,125,113,126,112}, {121,119,122,118,123,117,124,116,125,115,126,114,127,113}, {122,120,123,119,124,118,125,117,126,116,127,115,128,114}, {123,121,124,120,125,119,126,118,127,117,128,116,129,115}, {124,122,125,121,126,120,127,119,128,118,129,117,130,116}, {125,123,126,122,127,121,128,120,129,119,130,118,131,117}, {126,124,127,123,128,122,129,121,130,120,131,119,132,118}, {127,125,128,124,129,123,130,122,131,121,132,120,133,119}, {128,126,129,125,130,124,131,123,132,122,133,121,134,120}, {129,127,130,126,131,125,132,124,133,123,134,122,121}, {130,128,131,127,132,126,133,125,134,124,123,122}, {131,129,132,128,133,127,134,126,125,124,123}, {132,130,133,129,134,128,127,126,125,124}, {133,131,134,130,129,128,127,126,125}, {134,132,131,130,129,128,127,126}, {133,132,131,130,129,128,127}, {134,133,132,131,130,129,128}, {135,134,133,132,131,130,129}, {136,135,134,133,132,131,130}, {137,136,135,134,133,132,131}, {138,137,136,135,134,133,132}, {139,138,137,136,135,134,133}, {140,139,138,137,136,135,134}, {141,140,139,138,137,136,135}, {142,141,140,139,138,137,136}, {143,142,141,140,139,138,137}, {144,143,142,141,140,139,138}, {145,144,143,142,141,140,139}, {146,145,144,143,142,141,140}, {147,146,145,144,143,142,141}, {148,147,146,145,144,143,142}, {149,148,147,146,145,144,143}, {150,149,148,147,146,145,144}, {151,150,149,148,147,146,145}, {152,151,150,149,148,147,146}, {153,152,151,150,149,148,147}, {154,153,152,151,150,149,148}, {155,154,153,152,151,150,149}, {156,155,154,153,152,151,150}, {157,156,155,154,153,152,151}, {158,157,156,155,154,153,152}, {159,158,157,156,155,154,153}, {160,159,158,157,156,155,154}, {161,160,159,158,157,156,155}, {162,161,160,159,158,157,156}, {163,162,161,160,159,158,157}, {164,163,162,161,160,159,158}, {165,164,163,162,161,160,159}, {166,165,164,163,162,161,160}, {167,166,165,164,163,162,161}, {168,167,166,165,164,163,162}, {169,168,167,166,165,164,163}, {170,169,168,167,166,165,164}, {171,170,169,168,167,166,165}, {172,171,170,169,168,167,166}, {173,172,171,170,169,168,167}, {174,173,172,171,170,169,168}, {175,174,173,172,171,170,169}, {176,175,174,173,172,171,170}, {177,176,175,174,173,172,171}, {178,177,176,175,174,173,172}, {179,178,177,176,175,174,173}, {180,179,178,177,176,175,174}, {181,180,179,178,177,176,175}, {182,181,180,179,178,177,176}, {183,182,181,180,179,178,177}, {184,183,182,181,180,179,178}, {185,184,183,182,181,180,179}, {186,185,184,183,182,181,180}, {187,186,185,184,183,182,181}, {188,187,186,185,184,183,182}, {189,188,187,186,185,184,183}, {190,189,188,187,186,185,184}, {191,190,189,188,187,186,185}, {192,191,190,189,188,187,186}, {193,192,191,190,189,188,187}, {194,193,192,191,190,189,188}, {195,194,193,192,191,190,189}, {196,195,194,193,192,191,190}, {197,196,195,194,193,192,191}, {198,197,196,195,194,193,192}, {199,198,197,196,195,194,193}, {200,199,198,197,196,195,194}, {201,200,199,198,197,196,195}, {202,201,200,199,198,197,196}, {203,202,201,200,199,198,197}, {204,203,202,201,200,199,198}, {205,204,203,202,201,200,199}, {206,205,204,203,202,201,200}, {207,206,205,204,203,202,201}, {208,207,206,205,204,203,202}, {209,208,207,206,205,204,203}, {210,209,208,207,206,205,204}, {211,210,209,208,207,206,205}, {212,211,210,209,208,207,206}, {213,212,211,210,209,208,207}, {214,213,212,211,210,209,208}, {215,214,213,212,211,210,209}, {216,215,214,213,212,211,210}, {217,216,215,214,213,212,211}, {218,217,216,215,214,213,212}, {219,218,217,216,215,214,213}, {220,219,218,217,216,215,214}, {221,220,219,218,217,216,215}, {222,221,220,219,218,217,216}, {223,222,221,220,219,218,217}, {224,223,222,221,220,219,218}, {225,224,223,222,221,220,219}, {226,225,224,223,222,221,220}, {227,226,225,224,223,222,221}, {228,227,226,225,224,223,222}, {229,228,227,226,225,224,223}, {230,229,228,227,226,225,224}, {231,230,229,228,227,226,225}, {232,231,230,229,228,227,226}, {233,232,231,230,229,228,227}, {234,233,232,231,230,229,228}, {235,234,233,232,231,230,229}, {236,235,234,233,232,231,230}, {237,236,235,234,233,232,231}, {238,237,236,235,234,233,232}, {239,238,237,236,235,234,233}, {240,239,238,237,236,235,234}, {241,240,239,238,237,236,235}, {242,241,240,239,238,237,236}, {243,242,241,240,239,238,237}, {244,243,242,241,240,239,238}, {245,244,243,242,241,240,239}, {246,245,244,243,242,241,240}, {247,246,245,244,243,242,241}, {248,247,246,245,244,243,242}, {249,248,247,246,245,244,243}, {250,249,248,247,246,245,244}, {251,250,249,248,247,246,245}, {252,251,250,249,248,247,246}, {253,252,251,250,249,248,247}, {254,253,252,251,250,249,248}, {255,254,253,252,251,250,249}, {256,255,254,253,252,251,250}, {257,256,255,254,253,252,251}, {258,257,256,255,254,253,252}, {259,258,257,256,255,254,253}, {260,259,258,257,256,255,254}, {261,260,259,258,257,256,255}, {262,261,260,259,258,257,256}, {263,262,261,260,259,258,257}, {264,263,262,261,260,259,258}, {265,264,263,262,261,260,259}, {266,265,264,263,262,261,260}, {267,266,265,264,263,262,261}, {268,267,266,265,264,263,262}, {269,268,267,266,265,264,263}, {270,269,268,267,266,265,264}, {271,270,269,268,267,266,265}, {272,271,270,269,268,267,266}, {273,272,271,270,269,268,267}, {274,273,272,271,270,269,268}, {275,274,273,272,271,270,269}, {276,275,274,273,272,271,270}, {277,276,275,274,273,272,271}, {278,277,276,275,274,273,272}, {279,278,277,276,275,274,273}, {280,279,278,277,276,275,274}, {281,280,279,278,277,276,275}, {282,281,280,279,278,277,276}, {283,282,281,280,279,278,277}, {284,283,282,281,280,279,278}, {285,284,283,282,281,280,279}, {286,285,284,283,282,281,280}, {287,286,285,284,283,282,281}, {288,287,286,285,284,283,282}, {289,288,287,286,285,284,283}, {290,289,288,287,286,285,284}, {291,290,289,288,287,286,285}, {292,291,290,289,288,287,286}, {293,292,291,290,289,288,287}, {294,293,292,291,290,289,288}, {295,294,293,292,291,290,289}, {296,295,294,293,292,291,290}, {297,296,295,294,293,292,291}, {298,297,296,295,294,293,292}, {299,298,297,296,295,294,293}, {300,299,298,297,296,295,294}, {301,300,299,298,297,296,295}, {302,301,300,299,298,297,296}, {303,302,301,300,299,298,297}, {304,303,302,301,300,299,298}, {305,304,303,302,301,300,299}, {306,305,304,303,302,301,300}, {307,306,305,304,303,302,301}, {308,307,306,305,304,303,302}, {309,308,307,306,305,304,303}, {310,309,308,307,306,305,304}, {311,310,309,308,307,306,305}, {312,311,310,309,308,307,306}, {313,312,311,310,309,308,307}, {314,313,312,311,310,309,308}, {315,314,313,312,311,310,309}, {316,315,314,313,312,311,310}, {317,316,315,314,313,312,311}, {318,317,316,315,314,313,312}, {319,318,317,316,315,314,313}, {320,319,318,317,316,315,314}, {321,320,319,318,317,316,315}, {322,321,320,319,318,317,316}, {323,322,321,320,319,318,317}, {324,323,322,321,320,319,318}, {325,324,323,322,321,320,319}, {326,325,324,323,322,321,320}, {327,326,325,324,323,322,321}, {328,327,326,325,324,323,322}, {329,328,327,326,325,324,323}, {330,329,328,327,326,325,324}, {331,330,329,328,327,326,325}, {332,331,330,329,328,327,326}, {333,332,331,330,329,328,327}, {334,333,332,331,330,329,328}, {335,334,333,332,331,330,329}, {336,335,334,333,332,331,330}, {337,336,335,334,333,332,331}, {338,337,336,335,334,333,332}, {339,338,337,336,335,334,333}, {340,339,338,337,336,335,334}, {341,340,339,338,337,336,335}, {342,341,340,339,338,337,336}, {343,342,341,340,339,338,337}, {344,343,342,341,340,339,338}, {345,344,343,342,341,340,339}, {346,345,344,343,342,341,340}, {347,346,345,344,343,342,341}, {348,347,346,345,344,343,342}, {349,348,347,346,345,344,343}, {350,349,348,347,346,345,344}, {351,350,349,348,347,346,345}, {352,351,350,349,348,347,346}, {353,352,351,350,349,348,347}, {354,353,352,351,350,349,348}, {355,354,353,352,351,350,349}, {356,355,354,353,352,351,350}, {357,356,355,354,353,352,351}, {358,357,356,355,354,353,352}, {359,358,357,356,355,354,353}, {360,359,358,357,356,355,354}, {361,360,359,358,357,356,355}, {362,361,360,359,358,357,356}, {363,362,361,360,359,358,357}, {364,363,362,361,360,359,358}, {365,364,363,362,361,360,359}, {366,365,364,363,362,361,360}, {367,366,365,364,363,362,361}, {368,367,366,365,364,363,362}, {369,368,367,366,365,364,363}, {370,369,368,367,366,365,364}, {371,370,369,368,367,366,365}, {372,371,370,369,368,367,366}, {373,372,371,370,369,368,367}, {374,373,372,371,370,369,368}, {375,374,373,372,371,370,369}, {376,375,374,373,372,371,370}, {377,376,375,374,373,372,371}, {378,377,376,375,374,373,372}, {379,378,377,376,375,374,373}, {380,379,378,377,376,375,374}, {381,380,379,378,377,376,375}, {382,381,380,379,378,377,376}, {383,382,381,380,379,378,377}, {384,383,382,381,380,379,378}, {385,384,383,382,381,380,379}, {386,385,384,383,382,381,380}, {387,386,385,384,383,382,381}, {388,387,386,385,384,383,382}, {389,388,387,386,385,384,383}, {390,389,388,387,386,385,384}, {391,390,389,388,387,386,385}, {392,391,390,389,388,387,386}, {393,392,391,390,389,388,387}, {394,393,392,391,390,389,388}, {395,394,393,392,391,390,389}, {396,395,394,393,392,391,390}, {397,396,395,394,393,392,391}, {398,397,396,395,394,393,392}, {399,398,397,396,395,394,393}, {400,399,398,397,396,395,394}, {401,400,399,398,397,396,395}, {402,401,400,399,398,397,396}, {403,402,401,400,399,398,397}, {404,403,402,401,400,399,398}, {405,404,403,402,401,400,399}, {406,405,404,403,402,401,400}, {407,406,405,404,403,402,401}, {408,407,406,405,404,403,402}, {409,408,407,406,405,404,403}, {410,409,408,407,406,405,404}, {411,410,409,408,407,406,405}, {412,411,410,409,408,407,406}, {413,412,411,410,409,408,407}, {414,413,412,411,410,409,408}, {415,414,413,412,411,410,409}, {416,415,414,413,412,411,410}, {417,416,415,414,413,412,411}, {418,417,416,415,414,413,412}, {419,418,417,416,415,414,413}, {420,419,418,417,416,415,414}, {421,420,419,418,417,416,415}, {422,421,420,419,418,417,416}, {423,422,421,420,419,418,417}, {424,423,422,421,420,419,418}, {425,424,423,422,421,420,419}, {426,425,424,423,422,421,420}, {427,426,425,424,423,422,421}, {428,427,426,425,424,423,422}, {429,428,427,426,425,424,423}, {430,429,428,427,426,425,424}, {431,430,429,428,427,426,425}, {432,431,430,429,428,427,426}, {433,432,431,430,429,428,427}, {434,433,432,431,430,429,428}, {435,434,433,432,431,430,429}, {436,435,434,433,432,431,430}, {437,436,435,434,433,432,431}, {438,437,436,435,434,433,432}, {439,438,437,436,435,434,433}, {440,439,438,437,436,435,434}, {441,440,439,438,437,436,435}, {442,441,440,439,438,437,436}, {443,442,441,440,439,438,437}, {444,443,442,441,440,439,438}, {445,444,443,442,441,440,439}, {446,445,444,443,442,441,440}, {447,446,445,444,443,442,441}, {448,447,446,445,444,443,442}, {449,448,447,446,445,444,443}, {450,449,448,447,446,445,444}, {451,450,449,448,447,446,445}, {452,451,450,449,448,447,446}, {453,452,451,450,449,448,447}, {454,453,452,451,450,449,448}, {455,454,453,452,451,450,449}, {456,455,454,453,452,451,450}, {457,456,455,454,453,452,451}, {458,457,456,455,454,453,452}, {459,458,457,456,455,454,453}, {460,459,458,457,456,455,454}, {461,460,459,458,457,456,455}, {462,461,460,459,458,457,456}, {463,462,461,460,459,458,457}, {464,463,462,461,460,459,458}, {465,464,463,462,461,460,459}, {466,465,464,463,462,461,460}, {467,466,465,464,463,462,461}, {468,467,466,465,464,463,462}, {469,468,467,466,465,464,463}, {470,469,468,467,466,465,464}, {471,470,469,468,467,466,465}, {472,471,470,469,468,467,466}, {473,472,471,470,469,468,467}, {474,473,472,471,470,469,468}, {475,474,473,472,471,470,469}, {476,475,474,473,472,471,470}, {477,476,475,474,473,472,471}, {478,477,476,475,474,473,472}, {479,478,477,476,475,474,473}, {480,479,478,477,476,475,474}, {481,480,479,478,477,476,475}, {482,481,480,479,478,477,476}, {483,482,481,480,479,478,477}, {484,483,482,481,480,479,478}, {485,484,483,482,481,480,479}, {486,485,484,483,482,481,480}, {487,486,485,484,483,482,481}, {488,487,486,485,484,483,482}, {489,488,487,486,485,484,483}, {490,489,488,487,486,485,484}, {491,490,489,488,487,486,485}, {492,491,490,489,488,487,486}, {493,492,491,490,489,488,487}, {494,493,492,491,490,489,488}, {495,494,493,492,491,490,489}, {496,495,494,493,492,491,490}, {497,496,495,494,493,492,491}, {498,497,496,495,494,493,492}, {499,498,497,496,495,494,493}, {500,499,498,497,496,495,494}, {501,500,499,498,497,496,495}, {502,501,500,499,498,497,496}, {503,502,501,500,499,498,497}, {504,503,502,501,500,499,498}, {505,504,503,502,501,500,499}, {506,505,504,503,502,501,500}, {507,506,505,504,503,502,501}, {508,507,506,505,504,503,502}, {509,508,507,506,505,504,503}, {510,509,508,507,506,505,504}, {511,510,509,508,507,506,505}, {512,511,510,509,508,507,506}, {513,512,511,510,509,508,507}, {514,513,512,511,510,509,508}, {515,514,513,512,511,510,509}, {516,515,514,513,512,511,510}, {517,516,515,514,513,512,511}, {518,517,516,515,514,513,512}, {519,518,517,516,515,514,513}, {520,519,518,517,516,515,514}, {521,520,519,518,517,516,515}, {522,521,520,519,518,517,516}, {523,522,521,520,519,518,517}, {524,523,522,521,520,519,518}, {525,524,523,522,521,520,519}, {526,525,524,523,522,521,520}, {527,526,525,524,523,522,521}, {528,527,526,525,524,523,522}, {529,528,527,526,525,524,523}, {530,529,528,527,526,525,524}, {531,530,529,528,527,526,525}, {532,531,530,529,528,527,526}, {533,532,531,530,529,528,527}, {534,533,532,531,530,529,528}, {535,534,533,532,531,530,529}, {536,535,534,533,532,531,530}, {537,536,535,534,533,532,531}, {538,537,536,535,534,533,532}, {539,538,537,536,535,534,533}, {540,539,538,537,536,535,534}, {541,540,539,538,537,536,535}, {542,541,540,539,538,537,536}, {543,542,541,540,539,538,537}, {544,543,542,541,540,539,538}, {545,544,543,542,541,540,539}, {546,545,544,543,542,541,540}, {547,546,545,544,543,542,541}, {548,547,546,545,544,543,542}, {549,548,547,546,545,544,543}, {550,549,548,547,546,545,544}, {551,550,549,548,547,546,545}, {552,551,550,549,548,547,546}, {553,552,551,550,549,548,547}, {554,553,552,551,550,549,548}, {555,554,553,552,551,550,549}, {556,555,554,553,552,551,550}, {557,556,555,554,553,552,551}, {558,557,556,555,554,553,552}, {559,558,557,556,555,554,553}, {560,559,558,557,556,555,554}, {561,560,559,558,557,556,555}, {562,561,560,559,558,557,556}, {563,562,561,560,559,558,557}, {564,563,562,561,560,559,558}, {565,564,563,562,561,560,559}, {566,565,564,563,562,561,560}, {567,566,565,564,563,562,561}, {568,567,566,565,564,563,562}, {569,568,567,566,565,564,563}, {570,569,568,567,566,565,564}, {571,570,569,568,567,566,565}, {572,571,570,569,568,567,566}, {573,572,571,570,569,568,567}, {574,573,572,571,570,569,568}, {575,574,573,572,571,570,569}, {576,575,574,573,572,571,570}, {577,576,575,574,573,572,571}, {578,577,576,575,574,573,572}, {579,578,577,576,575,574,573}, {580,579,578,577,576,575,574}, {581,580,579,578,577,576,575}, {582,581,580,579,578,577,576}, {583,582,581,580,579,578,577}, {584,583,582,581,580,579,578}, {585,584,583,582,581,580,579}, {586,585,584,583,582,581,580}, {587,586,585,584,583,582,581}, {588,587,586,585,584,583,582}, {589,588,587,586,585,584,583}, {590,589,588,587,586,585,584}, {591,590,589,588,587,586,585}, {592,591,590,589,588,587,586}, {593,592,591,590,589,588,587}, {594,593,592,591,590,589,588}, {595,594,593,592,591,590,589}, {596,595,594,593,592,591,590}, {597,596,595,594,593,592,591}, {598,597,596,595,594,593,592}, {599,598,597,596,595,594,593}, {600,599,598,597,596,595,594}, {601,600,599,598,597,596,595}, {602,601,600,599,598,597,596}, {603,602,601,600,599,598,597}, {604,603,602,601,600,599,598}, {605,604,603,602,601,600,599}, {606,605,604,603,602,601,600}, {607,606,605,604,603,602,601}, {608,607,606,605,604,603,602}, {609,608,607,606,605,604,603}, {610,609,608,607,606,605,604}, {611,610,609,608,607,606,605}, {612,611,610,609,608,607,606}, {613,612,611,610,609,608,607}, {614,613,612,611,610,609,608}, {615,614,613,612,611,610,609}, {616,615,614,613,612,611,610}, {617,616,615,614,613,612,611}, {618,617,616,615,614,613,612}, {619,618,617,616,615,614,613}, {620,619,618,617,616,615,614}, {621,620,619,618,617,616,615}, {622,621,620,619,618,617,616}, {623,622,621,620,619,618,617}, {624,623,622,621,620,619,618}, {625,624,623,622,621,620,619}, {626,625,624,623,622,621,620}, {627,626,625,624,623,622,621}, {628,627,626,625,624,623,622}, {629,628,627,626,625,624,623}, {630,629,628,627,626,625,624}, {631,630,629,628,627,626,625}, {632,631,630,629,628,627,626}, {633,632,631,630,629,628,627}, {634,633,632,631,630,629,628}, {635,634,633,632,631,630,629}, {636,635,634,633,632,631,630}, {637,636,635,634,633,632,631}, {638,637,636,635,634,633,632}, {639,638,637,636,635,634,633}, {640,639,638,637,636,635,634}, {641,640,639,638,637,636,635}, {642,641,640,639,638,637,636}, {643,642,641,640,639,638,637}, {644,643,642,641,640,639,638}, {645,644,643,642,641,640,639}, {646,645,644,643,642,641,640}, {647,646,645,644,643,642,641}, {648,647,646,645,644,643,642}, {649,648,647,646,645,644,643}, {650,649,648,647,646,645,644}, {651,650,649,648,647,646,645}, {652,651,650,649,648,647,646}, {653,652,651,650,649,648,647}, {654,653,652,651,650,649,648}, {655,654,653,652,651,650,649}, {656,655,654,653,652,651,650}, {657,656,655,654,653,652,651}, {658,657,656,655,654,653,652}, {659,658,657,656,655,654,653}, {660,659,658,657,656,655,654}, {661,660,659,658,657,656,655}, {662,661,660,659,658,657,656}, {663,662,661,660,659,658,657}, {664,663,662,661,660,659,658}, {665,664,663,662,661,660,659}, {666,665,664,663,662,661,660}, {667,666,665,664,663,662,661}, {668,667,666,665,664,663,662}, {669,668,667,666,665,664,663}, {670,669,668,667,666,665,664}, {671,670,669,668,667,666,665}, {672,671,670,669,668,667,666}, {673,672,671,670,669,668,667}, {674,673,672,671,670,669,668}, {675,674,673,672,671,670,669}, {676,675,674,673,672,671,670}, {677,676,675,674,673,672,671}, {678,677,676,675,674,673,672}, {679,678,677,676,675,674,673}, {680,679,678,677,676,675,674}, {681,680,679,678,677,676,675}, {682,681,680,679,678,677,676}, {683,682,681,680,679,678,677}, {684,683,682,681,680,679,678}, {685,684,683,682,681,680,679}, {686,685,684,683,682,681,680}, {687,686,685,684,683,682,681}, {688,687,686,685,684,683,682}, {689,688,687,686,685,684,683}, {690,689,688,687,686,685,684}, {691,690,689,688,687,686,685}, {692,691,690,689,688,687,686}, {693,692,691,690,689,688,687}, {694,693,692,691,690,689,688}, {695,694,693,692,691,690,689}, {696,695,694,693,692,691,690}, {697,696,695,694,693,692,691}, {698,697,696,695,694,693,692}, {699,698,697,696,695,694,693}, {700,699,698,697,696,695,694}, {701,700,699,698,697,696,695}, {702,701,700,699,698,697,696}, {703,702,701,700,699,698,697}, {704,703,702,701,700,699,698}, {705,704,703,702,701,700,699}, {706,705,704,703,702,701,700}, {707,706,705,704,703,702,701}, {708,707,706,705,704,703,702}, {709,708,707,706,705,704,703}, {710,709,708,707,706,705,704}, {711,710,709,708,707,706,705}, {712,711,710,709,708,707,706}, {713,712,711,710,709,708,707}, {714,713,712,711,710,709,708}, {715,714,713,712,711,710,709}, {716,715,714,713,712,711,710}, {717,716,715,714,713,712,711}, {718,717,716,715,714,713,712}, {719,718,717,716,715,714,713}, {720,719,718,717,716,715,714}, {721,720,719,718,717,716,715}, {722,721,720,719,718,717,716}, {723,722,721,720,719,718,717}, {724,723,722,721,720,719,718}, {725,724,723,722,721,720,719}, {726,725,724,723,722,721,720}, {727,726,725,724,723,722,721}, {728,727,726,725,724,723,722}, {729,728,727,726,725,724,723}, {730,729,728,727,726,725,724}, {731,730,729,728,727,726,725}, {732,731,730,729,728,727,726}, {733,732,731,730,729,728,727}, {734,733,732,731,730,729,728}, {735,734,733,732,731,730,729}, {736,735,734,733,732,731,730}, {737,736,735,734,733,732,731}, {738,737,736,735,734,733,732}, {739,738,737,736,735,734,733}, {740,739,738,737,736,735,734}, {741,740,739,738,737,736,735}, {742,741,740,739,738,737,736}, {743,742,741,740,739,738,737}, {744,743,742,741,740,739,738}, {745,744,743,742,741,740,739}, {746,745,744,743,742,741,740}, {747,746,745,744,743,742,741}, {748,747,746,745,744,743,742}, {749,748,747,746,745,744,743}, {750,749,748,747,746,745,744}, {751,750,749,748,747,746,745}, {752,751,750,749,748,747,746}, {753,752,751,750,749,748,747}, {754,753,752,751,750,749,748}, {755,754,753,752,751,750,749}, {756,755,754,753,752,751,750}, {757,756,755,754,753,752,751}, {758,757,756,755,754,753,752}, {759,758,757,756,755,754,753}, {760,759,758,757,756,755,754}, {761,760,759,758,757,756,755}, {762,761,760,759,758,757,756}, {763,762,761,760,759,758,757}, {764,763,762,761,760,759,758}, {765,764,763,762,761,760,759}, {766,765,764,763,762,761,760}, {767,766,765,764,763,762,761}, {768,767,766,765,764,763,762}, {769,768,767,766,765,764,763}, {770,769,768,767,766,765,764}, {771,770,769,768,767,766,765}, {772,771,770,769,768,767,766}, {773,772,771,770,769,768,767}, {774,773,772,771,770,769,768}, {775,774,773,772,771,770,769}, {776,775,774,773,772,771,770}, {777,776,775,774,773,772,771}, {778,777,776,775,774,773,772}, {779,778,777,776,775,774,773}, {780,779,778,777,776,775,774}, {781,780,779,778,777,776,775}, {782,781,780,779,778,777,776}, {783,782,781,780,779,778,777}, {784,783,782,781,780,779,778}, {785,784,783,782,781,780,779}, {786,785,784,783,782,781,780}, {787,786,785,784,783,782,781}, {788,787,786,785,784,783,782}, {789,788,787,786,785,784,783}, {790,789,788,787,786,785,784}, {791,790,789,788,787,786,785}, {792,791,790,789,788,787,786}, {793,792,791,790,789,788,787}, {794,793,792,791,790,789,788}, {795,794,793,792,791,790,789}, {796,795,794,793,792,791,790}, {797,796,795,794,793,792,791}, {798,797,796,795,794,793,792}, {799,798,797,796,795,794,793}, {800,799,798,797,796,795,794}, {801,800,799,798,797,796,795}, {802,801,800,799,798,797,796}, {803,802,801,800,799,798,797}, {804,803,802,801,800,799,798}, {805,804,803,802,801,800,799}, {806,805,804,803,802,801,800}, {807,806,805,804,803,802,801}, {808,807,806,805,804,803,802}, {809,808,807,806,805,804,803}, {810,809,808,807,806,805,804}, {811,810,809,808,807,806,805}, {812,811,810,809,808,807,806}, {813,812,811,810,809,808,807}, {814,813,812,811,810,809,808}, {815,814,813,812,811,810,809}, {816,815,814,813,812,811,810}, {817,816,815,814,813,812,811}, {818,817,816,815,814,813,812}, {819,818,817,816,815,814,813}, {820,819,818,817,816,815,814}, {821,820,819,818,817,816,815}, {822,821,820,819,818,817,816}, {823,822,821,820,819,818,817}, {824,823,822,821,820,819,818}, {825,824,823,822,821,820,819}, {826,825,824,823,822,821,820}, {827,826,825,824,823,822,821}, {828,827,826,825,824,823,822}, {829,828,827,826,825,824,823}, {830,829,828,827,826,825,824}, {831,830,829,828,827,826,825}, {832,831,830,829,828,827,826}, {833,832,831,830,829,828,827}, {834,833,832,831,830,829,828}, {835,834,833,832,831,830,829}, {836,835,834,833,832,831,830}, {837,836,835,834,833,832,831}, {838,837,836,835,834,833,832}, {839,838,837,836,835,834,833}, {840,839,838,837,836,835,834}, {841,840,839,838,837,836,835}, {842,841,840,839,838,837,836}, {843,842,841,840,839,838,837}, {844,843,842,841,840,839,838}, {845,844,843,842,841,840,839}, {846,845,844,843,842,841,840}, {847,846,845,844,843,842,841}, {848,847,846,845,844,843,842}, {849,848,847,846,845,844,843}, {850,849,848,847,846,845,844}, {851,850,849,848,847,846,845}, {852,851,850,849,848,847,846}, {853,852,851,850,849,848,847}, {854,853,852,851,850,849,848}, {855,854,853,852,851,850,849}, {856,855,854,853,852,851,850}, {857,856,855,854,853,852,851}, {858,857,856,855,854,853,852}, {859,858,857,856,855,854,853}, {860,859,858,857,856,855,854}, {861,860,859,858,857,856,855}, {862,861,860,859,858,857,856}, {863,862,861,860,859,858,857}, {864,863,862,861,860,859,858}, {865,864,863,862,861,860,859}, {866,865,864,863,862,861,860}, {867,866,865,864,863,862,861}, {868,867,866,865,864,863,862}, {869,868,867,866,865,864,863}, {870,869,868,867,866,865,864}, {871,870,869,868,867,866,865}, {872,871,870,869,868,867,866}, {873,872,871,870,869,868,867}, {874,873,872,871,870,869,868}, {875,874,873,872,871,870,869}, {876,875,874,873,872,871,870}, {877,876,875,874,873,872,871}, {878,877,876,875,874,873,872}, {879,878,877,876,875,874,873}, {880,879,878,877,876,875,874}, {881,880,879,878,877,876,875}, {882,881,880,879,878,877,876}, {883,882,881,880,879,878,877}, {884,883,882,881,880,879,878}, {885,884,883,882,881,880,879}, {886,885,884,883,882,881,880}, {887,886,885,884,883,882,881}, {888,887,886,885,884,883,882}, {889,888,887,886,885,884,883}, {890,889,888,887,886,885,884}, {891,890,889,888,887,886,885}, {892,891,890,889,888,887,886}, {893,892,891,890,889,888,887}, {894,893,892,891,890,889,888}, {895,894,893,892,891,890,889}, {896,895,894,893,892,891,890}, {897,896,895,894,893,892,891}, {898,897,896,895,894,893,892}, {899,898,897,896,895,894,893}, {900,899,898,897,896,895,894}, {901,900,899,898,897,896,895}, {902,901,900,899,898,897,896}, {903,902,901,900,899,898,897}, {904,903,902,901,900,899,898}, {905,904,903,902,901,900,899}, {906,905,904,903,902,901,900}, {907,906,905,904,903,902,901}, {908,907,906,905,904,903,902}, {909,908,907,906,905,904,903}, {910,909,908,907,906,905,904}, {911,910,909,908,907,906,905}, {912,911,910,909,908,907,906}, {913,912,911,910,909,908,907}, {914,913,912,911,910,909,908}, {915,914,913,912,911,910,909}, {916,915,914,913,912,911,910}, {917,916,915,914,913,912,911}, {918,917,916,915,914,913,912}, {919,918,917,916,915,914,913}, {920,919,918,917,916,915,914}, {921,920,919,918,917,916,915}, {922,921,920,919,918,917,916}, {923,922,921,920,919,918,917}, {924,923,922,921,920,919,918}, {925,924,923,922,921,920,919}, {926,925,924,923,922,921,920}, {927,926,925,924,923,922,921}, {928,927,926,925,924,923,922}, {929,928,927,926,925,924,923}, {930,929,928,927,926,925,924}, {931,930,929,928,927,926,925}, {932,931,930,929,928,927,926}, {933,932,931,930,929,928,927}, {934,933,932,931,930,929,928}, {935,934,933,932,931,930,929}, {936,935,934,933,932,931,930}, {937,936,935,934,933,932,931}, {938,937,936,935,934,933,932}, {939,938,937,936,935,934,933}, {940,939,938,937,936,935,934}, {941,940,939,938,937,936,935}, {942,941,940,939,938,937,936}, {943,942,941,940,939,938,937}, {944,943,942,941,940,939,938}, {945,944,943,942,941,940,939}, {946,945,944,943,942,941,940}, {947,946,945,944,943,942,941}, {948,947,946,945,944,943,942}, {949,948,947,946,945,944,943}, {950,949,948,947,946,945,944}, {951,950,949,948,947,946,945}, {952,951,950,949,948,947,946}, {953,952,951,950,949,948,947}, {954,953,952,951,950,949,948}, {955,954,953,952,951,950,949}, {956,955,954,953,952,951,950}, {957,956,955,954,953,952,951}, {958,957,956,955,954,953,952}, {959,958,957,956,955,954,953}, {960,959,958,957,956,955,954}, {961,960,959,958,957,956,955}, {962,961,960,959,958,957,956}, {963,962,961,960,959,958,957}, {964,963,962,961,960,959,958}, {965,964,963,962,961,960,959}, {966,965,964,963,962,961,960}, {967,966,965,964,963,962,961}, {968,967,966,965,964,963,962}, {969,968,967,966,965,964,963}, {970,969,968,967,966,965,964}, {971,970,969,968,967,966,965}, {972,971,970,969,968,967,966}, {973,972,971,970,969,968,967}, {974,973,972,971,970,969,968}, {975,974,973,972,971,970,969}, {976,975,974,973,972,971,970}, {977,976,975,974,973,972,971}, {978,977,976,975,974,973,972}, {979,978,977,976,975,974,973}, {980,979,978,977,976,975,974}, {981,980,979,978,977,976,975}, {982,981,980,979,978,977,976}, {983,982,981,980,979,978,977}, {984,983,982,981,980,979,978}, {985,984,983,982,981,980,979}, {986,985,984,983,982,981,980}, {987,986,985,984,983,982,981}, {988,987,986,985,984,983,982}, {989,988,987,986,985,984,983}, {990,989,988,987,986,985,984}, {991,990,989,988,987,986,985}, {992,991,990,989,988,987,986}, {993,992,991,990,989,988,987}, {994,993,992,991,990,989,988}, {995,994,993,992,991,990,989}, {996,995,994,993,992,991,990}, {997,996,995,994,993,992,991}, {998,997,996,995,994,993,992}, {999,998,997,996,995,994,993}, {1000,999,998,997,996,995,994}, {1001,1000,999,998,997,996,995}, {1002,1001,1000,999,998,997,996}, {1003,1002,1001,1000,999,998,997}, {1004,1003,1002,1001,1000,999,998}, {1005,1004,1003,1002,1001,1000,999}, {1006,1005,1004,1003,1002,1001,1000}, {1007,1006,1005,1004,1003,1002,1001}, {1008,1007,1006,1005,1004,1003,1002}, {1009,1008,1007,1006,1005,1004,1003}, {1010,1009,1008,1007,1006,1005,1004}, {1011,1010,1009,1008,1007,1006,1005}, {1012,1011,1010,1009,1008,1007,1006}, {1013,1012,1011,1010,1009,1008,1007}, {1014,1013,1012,1011,1010,1009,1008}, {1015,1014,1013,1012,1011,1010,1009}, {1016,1015,1014,1013,1012,1011,1010}, {1017,1016,1015,1014,1013,1012,1011}, {1018,1017,1016,1015,1014,1013,1012}, {1019,1018,1017,1016,1015,1014,1013}, {1020,1019,1018,1017,1016,1015,1014}, {1021,1020,1019,1018,1017,1016,1015}, {1022,1021,1020,1019,1018,1017,1016}, {1023,1022,1021,1020,1019,1018,1017}, {1024,1023,1022,1021,1020,1019,1018}, {1025,1024,1023,1022,1021,1020,1019}, {1026,1025,1024,1023,1022,1021,1020}, {1027,1026,1025,1024,1023,1022,1021}, {1028,1027,1026,1025,1024,1023,1022}, {1029,1028,1027,1026,1025,1024,1023}, {1030,1029,1028,1027,1026,1025,1024}, {1031,1030,1029,1028,1027,1026,1025}, {1032,1031,1030,1029,1028,1027,1026}, {1033,1032,1031,1030,1029,1028,1027}, {1034,1033,1032,1031,1030,1029,1028}, {1035,1034,1033,1032,1031,1030,1029}, {1036,1035,1034,1033,1032,1031,1030}, {1037,1036,1035,1034,1033,1032,1031}, {1038,1037,1036,1035,1034,1033,1032}, {1039,1038,1037,1036,1035,1034,1033}, {1040,1039,1038,1037,1036,1035,1034}, {1041,1040,1039,1038,1037,1036,1035}, {1042,1041,1040,1039,1038,1037,1036}, {1043,1042,1041,1040,1039,1038,1037}, {1044,1043,1042,1041,1040,1039,1038}, {1045,1044,1043,1042,1041,1040,1039}, {1046,1045,1044,1043,1042,1041,1040}, {1047,1046,1045,1044,1043,1042,1041}, {1048,1047,1046,1045,1044,1043,1042}, {1049,1048,1047,1046,1045,1044,1043}, {1050,1049,1048,1047,1046,1045,1044}, {1051,1050,1049,1048,1047,1046,1045}, {1052,1051,1050,1049,1048,1047,1046}, {1053,1052,1051,1050,1049,1048,1047}, {1054,1053,1052,1051,1050,1049,1048}, {1055,1054,1053,1052,1051,1050,1049}, {1056,1055,1054,1053,1052,1051,1050}, {1057,1056,1055,1054,1053,1052,1051}, {1058,1057,1056,1055,1054,1053,1052}, {1059,1058,1057,1056,1055,1054,1053}, {1060,1059,1058,1057,1056,1055,1054}, {1061,1060,1059,1058,1057,1056,1055}, {1062,1061,1060,1059,1058,1057,1056}, {1063,1062,1061,1060,1059,1058,1057}, {1064,1063,1062,1061,1060,1059,1058}, {1065,1064,1063,1062,1061,1060,1059}, {1066,1065,1064,1063,1062,1061,1060}, {1067,1066,1065,1064,1063,1062,1061}, {1068,1067,1066,1065,1064,1063,1062}, {1069,1068,1067,1066,1065,1064,1063}, {1070,1069,1068,1067,1066,1065,1064}};
//end paste block

//long strands have 134 pixels, short strands have 127
#define lightsNum 1043

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(lightsNum, PIN, NEO_GRB + NEO_KHZ800);

long Time = 0;
long Speed = 20;
uint32_t currentLight = 1043;
long intensity = 1;

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(255);
  pixels.show();
}

void loop() {
  Time = Time + Speed;

  if(Time > 255) {
    Time = 0;
    currentLight = random(0, 1043);
  }
  int off = pixels.Color(0, 0, 0);
  for(int i = 0; i < lightsNum; i++){
    pixels.setPixelColor(i, off);

  }

  for(int i=0; i<lightsNum; i++) { // For each pixel...
      uint32_t on = pixels.Color(255, 0, 0);
      pixels.setPixelColor(currentLight, on);
      pixels.setPixelColor(currentLight+1, on);
      pixels.setPixelColor(currentLight+2, on);
      pixels.setPixelColor(currentLight+3, on);
      pixels.setPixelColor(currentLight+4, on);
      pixels.setPixelColor(currentLight+5, on);

    if( i == currentLight){

      uint32_t red = pixels.Color(0, 255, 0);
      int values = sizeof(neighbors[i])/sizeof(neighbors[i][i]);
      for(int j = 0; j < 8; j++){
        pixels.setPixelColor(neighbors[i][j], red);
      }
    }
  }
    
  pixels.show();   // Send the updated pixel colors to the hardware.
}
