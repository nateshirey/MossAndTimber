// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

namespace imageColors{
  typedef struct
  {
    int Red;
    int Green;
    int Blue; 
  } vector3;
  
}

//copy outputImage data here
imageColors:: vector3 colorsArray [] = {(36, 0, 254), (38, 0, 253), (39, 0, 252), (39, 0, 251), (41, 0, 249), (41, 0, 248), (42, 0, 247), (44, 0, 246), (45, 0, 245), (46, 0, 244), (47, 0, 242), (48, 0, 241), (49, 0, 240), (51, 0, 237), (52, 0, 236), (53, 0, 234), (55, 0, 233), (56, 0, 232), (57, 0, 230), (59, 0, 229), (60, 0, 227), (62, 0, 225), (63, 0, 223), (65, 0, 221), (67, 0, 219), (68, 0, 218), (69, 0, 216), (72, 0, 214), (73, 0, 212), (75, 0, 210), (77, 0, 208), (77, 0, 206), (80, 0, 204), (82, 0, 202), (83, 0, 200), (84, 0, 198), (87, 0, 196), (88, 0, 194), (91, 0, 192), (92, 0, 190), (94, 0, 188), (96, 0, 186), (97, 0, 183), (100, 0, 180), (102, 0, 179), (104, 0, 177), (106, 0, 174), (107, 0, 172), (110, 0, 169), (111, 0, 167), (113, 1, 166), (116, 0, 163), (117, 0, 161), (119, 0, 158), (121, 0, 156), (124, 0, 153), (125, 0, 151), (127, 0, 148), (129, 0, 147), (132, 0, 144), (134, 0, 142), (136, 0, 139), (137, 0, 137), (139, 0, 134), (142, 0, 132), (144, 0, 130), (146, 0, 128), (148, 0, 125), (150, 0, 122), (152, 0, 120), (153, 0, 118), (156, 0, 115), (158, 0, 113), (160, 0, 111), (162, 0, 108), (164, 0, 106), (166, 0, 104), (168, 0, 101), (170, 0, 99), (172, 0, 97), (174, 0, 95), (176, 0, 92), (178, 0, 90), (180, 0, 88), (182, 0, 85), (184, 0, 83), (185, 0, 81), (188, 0, 79), (189, 0, 76), (191, 0, 74), (193, 0, 72), (195, 0, 69), (197, 0, 68), (199, 0, 65), (200, 0, 64), (203, 1, 61), (205, 0, 59), (206, 0, 57), (208, 0, 55), (210, 0, 53), (211, 0, 51), (213, 0, 49), (214, 0, 47), (216, 0, 45), (218, 0, 43), (219, 0, 41), (222, 0, 39), (223, 1, 37), (225, 0, 36), (226, 0, 34), (228, 0, 32), (229, 0, 30), (231, 0, 28), (232, 0, 26), (233, 0, 25), (235, 0, 24), (236, 0, 22), (238, 0, 20), (238, 0, 18), (241, 0, 17), (242, 0, 16), (242, 0, 14), (244, 0, 12), (245, 0, 11), (246, 0, 10), (247, 0, 9), (248, 0, 8), (249, 0, 6), (250, 0, 6), (251, 0, 4), (253, 0, 3), (254, 0, 2), (255, 0, 1), (255, 0, 0), (255, 0, 0), (254, 0, 1), (254, 0, 2), (253, 0, 3), (251, 0, 4), (250, 0, 5), (250, 0, 6), (248, 0, 8), (247, 0, 9), (246, 0, 10), (245, 0, 12), (244, 0, 13), (243, 0, 15), (242, 0, 15), (240, 0, 17), (239, 0, 18), (238, 0, 20), (236, 0, 22), (235, 0, 23), (233, 0, 25), (232, 1, 27), (231, 0, 28), (229, 0, 30), (228, 0, 32), (226, 0, 33), (224, 0, 36), (223, 0, 37), (221, 0, 39), (220, 0, 41), (218, 0, 43), (216, 0, 45), (214, 0, 46), (213, 0, 49), (212, 0, 51), (210, 0, 53), (208, 0, 55), (206, 0, 57), (204, 0, 59), (203, 0, 61), (200, 0, 63), (199, 0, 66), (197, 0, 68), (195, 0, 70), (193, 0, 72), (192, 0, 74), (190, 0, 76), (188, 0, 78), (186, 0, 81), (184, 0, 83), (181, 0, 85), (180, 0, 87), (178, 0, 89), (176, 0, 92), (174, 0, 95), (172, 0, 97), (170, 0, 100), (168, 0, 102), (166, 0, 104), (164, 0, 107), (162, 0, 109), (160, 0, 111), (157, 0, 113), (156, 0, 116), (154, 0, 118), (151, 0, 121), (150, 0, 123), (148, 0, 125), (146, 0, 128), (143, 0, 130), (141, 0, 133), (139, 0, 135), (138, 0, 137), (135, 0, 140), (134, 0, 141), (131, 0, 144), (129, 0, 146), (127, 0, 149), (125, 0, 151), (124, 0, 153), (122, 0, 156), (119, 0, 158), (117, 0, 161), (115, 0, 163), (113, 0, 166), (112, 0, 167), (109, 0, 170), (107, 0, 172), (105, 0, 174), (103, 0, 177), (101, 0, 179), (99, 0, 181), (98, 0, 183), (96, 0, 185), (94, 0, 188), (92, 0, 189), (91, 0, 192), (89, 0, 193), (87, 0, 196), (85, 0, 198), (84, 0, 200), (82, 0, 203), (80, 0, 205), (78, 0, 206), (76, 0, 208), (75, 0, 210), (72, 0, 213), (71, 0, 214), (69, 0, 216), (68, 0, 218), (67, 0, 220), (65, 0, 221), (64, 0, 223), (61, 0, 224), (61, 0, 226), (59, 0, 228), (58, 0, 230), (56, 0, 231), (55, 0, 233), (54, 0, 234), (52, 0, 237), (51, 0, 238), (50, 0, 239), (48, 0, 241), (47, 1, 242), (46, 0, 244), (45, 0, 245), (43, 0, 246), (37, 0, 254), (37, 0, 253), (39, 0, 252), (39, 0, 251), (40, 0, 249), (42, 0, 249), (43, 0, 248), (44, 0, 246), (45, 0, 245), (46, 0, 243), (47, 0, 242), (48, 0, 240), (49, 0, 239), (51, 0, 238), (53, 0, 236), (54, 0, 235), (55, 0, 233), (56, 0, 231), (58, 0, 230), (59, 0, 228), (60, 0, 226), (62, 0, 225), (64, 0, 223), (65, 0, 221), (67, 0, 219), (68, 0, 218), (70, 0, 216), (71, 0, 214), (72, 0, 212), (75, 0, 210), (77, 0, 208), (78, 0, 207), (79, 0, 204), (81, 0, 202), (83, 0, 200), (85, 0, 198), (87, 0, 196), (88, 0, 194), (91, 0, 192), (92, 0, 190), (94, 0, 188), (95, 0, 185), (98, 0, 183), (100, 0, 181), (102, 0, 178), (104, 0, 177), (105, 0, 175), (108, 1, 172), (109, 0, 170), (111, 0, 168), (113, 0, 165), (115, 0, 162), (117, 0, 161), (119, 0, 158), (121, 0, 156), (123, 0, 153), (126, 0, 151), (127, 0, 149), (129, 0, 146), (131, 0, 144), (134, 0, 142), (136, 0, 140), (137, 0, 137), (140, 0, 135), (142, 0, 133), (144, 0, 130), (145, 0, 127), (148, 0, 125), (150, 0, 123), (152, 0, 121), (153, 0, 118), (156, 0, 116), (158, 0, 113), (160, 0, 110), (162, 0, 109), (163, 0, 106), (166, 0, 104), (168, 0, 102), (170, 0, 99), (172, 0, 97), (174, 0, 94), (176, 0, 92), (178, 0, 90), (179, 0, 87), (182, 0, 86), (183, 0, 83), (186, 0, 81), (187, 0, 79), (190, 0, 76), (191, 0, 74), (193, 0, 72), (195, 0, 70), (197, 0, 68), (199, 0, 65), (201, 0, 64), (202, 0, 61), (205, 0, 59), (206, 0, 57), (208, 0, 55), (210, 0, 53), (212, 0, 51), (213, 0, 49), (215, 0, 46), (216, 0, 45), (218, 0, 43), (219, 0, 41), (221, 0, 39), (223, 0, 37), (224, 0, 35), (226, 0, 34), (228, 0, 32), (229, 0, 30), (231, 0, 28), (232, 0, 26), (234, 0, 25), (235, 0, 24), (236, 0, 22), (237, 0, 20), (239, 0, 18), (240, 0, 17), (241, 0, 16), (243, 0, 14), (244, 0, 13), (245, 0, 11), (246, 0, 11), (247, 0, 9), (248, 0, 7), (249, 0, 6), (250, 0, 5), (252, 0, 4), (253, 0, 3), (253, 0, 2), (254, 0, 1), (255, 0, 0), (255, 0, 0), (254, 0, 1), (254, 0, 2), (253, 0, 4), (252, 0, 4), (251, 0, 5), (250, 0, 7), (249, 0, 8), (247, 0, 8), (246, 0, 10), (245, 0, 12), (244, 0, 13), (242, 0, 14), (241, 0, 16), (240, 0, 17), (239, 0, 18), (237, 0, 20), (236, 0, 22), (235, 0, 23), (234, 0, 25), (232, 0, 27), (231, 0, 29), (230, 0, 30), (228, 0, 32), (226, 0, 34), (225, 0, 35), (223, 0, 38), (222, 0, 39), (219, 0, 41), (218, 0, 43), (216, 0, 45), (215, 0, 47), (213, 0, 49), (211, 0, 51), (209, 0, 53), (208, 0, 55), (206, 0, 57), (205, 0, 59), (203, 0, 61), (201, 0, 63), (198, 0, 65), (197, 0, 68), (195, 0, 69), (193, 0, 72), (191, 0, 75), (189, 0, 77), (187, 0, 79), (186, 0, 81), (183, 1, 83), (182, 0, 86), (180, 0, 88), (178, 0, 90), (175, 0, 92), (173, 0, 94), (172, 0, 97), (170, 0, 99), (168, 0, 102), (166, 0, 104), (163, 0, 107), (162, 0, 109), (160, 0, 111), (158, 0, 113), (155, 0, 115), (154, 0, 118), (151, 0, 121), (150, 0, 123), (148, 0, 125), (146, 0, 127), (143, 0, 130), (142, 0, 132), (139, 0, 135), (137, 0, 137), (136, 0, 139), (133, 0, 142), (131, 0, 145), (129, 0, 147), (127, 0, 149), (125, 0, 151), (123, 0, 153), (121, 0, 156), (120, 0, 158), (117, 0, 161), (115, 0, 163), (113, 0, 165), (111, 0, 168), (110, 0, 170), (107, 0, 172), (105, 0, 174), (104, 0, 177), (101, 0, 179), (100, 0, 181), (97, 0, 184), (95, 0, 185), (94, 0, 188), (92, 0, 189), (91, 0, 192), (88, 0, 194), (87, 0, 196), (85, 0, 198), (83, 0, 201), (81, 0, 202), (80, 0, 204), (77, 0, 206), (76, 0, 208), (75, 0, 210), (73, 0, 213), (71, 0, 214), (70, 0, 216), (68, 0, 218), (67, 0, 220), (65, 0, 221), (63, 0, 223), (61, 0, 225), (61, 0, 227), (59, 0, 228), (58, 0, 229), (56, 0, 232), (55, 0, 233), (53, 0, 235), (52, 0, 236), (51, 0, 238), (49, 0, 239), (49, 0, 241), (47, 0, 242), (46, 0, 243), (45, 0, 244), (44, 0, 246), (37, 0, 254), (37, 0, 253), (39, 0, 252), (40, 0, 251), (40, 0, 249), (41, 0, 248), (42, 0, 247), (44, 0, 246), (45, 0, 245), (46, 0, 243), (47, 0, 242), (49, 0, 240), (50, 0, 239), (51, 0, 238), (52, 0, 236), (53, 0, 235), (54, 0, 233), (56, 0, 232), (58, 0, 230), (58, 0, 229), (61, 0, 226), (61, 0, 225), (63, 0, 223), (65, 0, 222), (66, 0, 219), (68, 0, 218), (69, 0, 215), (71, 0, 214), (73, 0, 212), (74, 0, 210), (76, 0, 208), (78, 0, 206), (80, 0, 204), (81, 0, 202), (83, 1, 201), (84, 0, 198), (87, 0, 196), (88, 0, 194), (90, 0, 192), (92, 0, 190), (94, 1, 187), (96, 0, 186), (97, 0, 183), (100, 0, 181), (102, 0, 179), (104, 0, 177), (105, 0, 174), (108, 0, 172), (109, 0, 170), (111, 0, 167), (114, 0, 166), (115, 0, 163), (117, 0, 160), (119, 0, 158), (121, 0, 156), (123, 0, 154), (125, 0, 151), (127, 0, 149), (129, 0, 147), (131, 0, 144), (134, 0, 141), (135, 0, 140), (138, 0, 137), (139, 0, 135), (141, 0, 132), (144, 0, 130), (146, 0, 127), (147, 0, 125), (150, 0, 123), (152, 0, 120), (154, 0, 118), (155, 0, 116), (158, 0, 113), (160, 0, 111), (161, 0, 108), (164, 0, 107), (166, 0, 103), (168, 0, 101), (170, 0, 99), (172, 0, 97), (174, 0, 95), (176, 0, 92), (178, 0, 90), (180, 0, 87), (182, 0, 85), (183, 0, 83), (186, 0, 81), (188, 0, 79), (189, 0, 77), (192, 0, 74), (194, 0, 72), (195, 0, 69), (197, 0, 68), (199, 0, 65), (201, 0, 63), (203, 0, 61), (204, 0, 59), (206, 0, 57), (207, 0, 55), (210, 0, 53), (212, 0, 51), (214, 0, 49), (215, 0, 47), (217, 0, 45), (219, 0, 43), (220, 0, 41), (222, 0, 39), (223, 0, 38), (225, 0, 35), (226, 0, 33), (227, 0, 32), (229, 0, 30), (231, 0, 28), (232, 0, 27), (234, 0, 25), (235, 0, 23), (236, 0, 21), (237, 0, 20), (238, 0, 19), (241, 0, 17), (242, 0, 16), (243, 0, 14), (244, 0, 12), (245, 0, 12), (246, 0, 10), (247, 0, 9), (248, 0, 8), (250, 0, 6), (250, 0, 5), (251, 0, 4), (252, 0, 3), (253, 0, 2), (254, 0, 1), (255, 0, 0), (255, 0, 0), (254, 0, 1), (253, 0, 2), (252, 0, 3), (251, 0, 4), (251, 0, 5), (250, 0, 7), (248, 0, 8), (247, 0, 9), (247, 0, 10), (245, 0, 11), (244, 0, 13), (243, 0, 15), (241, 0, 16), (240, 0, 17), (239, 0, 19), (237, 0, 20), (236, 0, 22), (235, 0, 23), (233, 0, 25), (232, 0, 27), (230, 0, 29), (230, 0, 30), (227, 0, 32), (226, 0, 34), (225, 0, 36), (223, 0, 37), (222, 0, 39), (220, 0, 41), (218, 0, 43), (217, 0, 45), (214, 0, 47), (213, 0, 49), (211, 0, 50), (210, 0, 53), (208, 0, 54), (206, 0, 56), (204, 0, 59), (202, 0, 61), (201, 0, 63), (199, 0, 65), (197, 0, 67), (195, 0, 69), (193, 0, 72), (191, 0, 75), (189, 0, 76), (187, 0, 79), (186, 0, 81), (184, 0, 83), (182, 0, 86), (180, 0, 88), (177, 0, 90), (176, 0, 93), (173, 0, 94), (172, 0, 97), (170, 0, 99), (168, 0, 102), (166, 0, 104), (164, 0, 106), (162, 0, 109), (159, 0, 111), (158, 0, 113), (156, 0, 115), (154, 0, 118), (152, 0, 120), (150, 0, 122), (148, 0, 125), (145, 0, 128), (143, 0, 130), (142, 0, 132), (139, 0, 134), (137, 0, 137), (135, 0, 140), (133, 0, 142), (131, 0, 144), (130, 0, 147), (127, 0, 149), (125, 0, 152), (123, 0, 153), (121, 0, 156), (119, 0, 158), (117, 0, 160), (116, 0, 163), (113, 0, 165), (111, 0, 167), (109, 0, 170), (108, 0, 172), (105, 0, 175), (103, 0, 176), (102, 0, 179), (100, 0, 181), (97, 0, 183), (96, 0, 185), (94, 0, 187), (92, 0, 189), (90, 0, 192), (88, 0, 194), (87, 0, 196), (85, 0, 198), (83, 0, 201), (82, 0, 202), (80, 0, 204), (78, 0, 206), (76, 0, 208), (75, 0, 210), (73, 0, 212), (71, 0, 214), (69, 0, 216), (68, 0, 218), (66, 0, 220), (65, 0, 221), (64, 0, 223), (62, 0, 225), (60, 0, 226), (59, 0, 228), (58, 0, 230), (56, 0, 231), (54, 0, 233), (54, 0, 234), (52, 0, 236), (50, 0, 237), (50, 0, 239), (48, 0, 240), (47, 0, 242), (46, 0, 243), (45, 0, 245), (44, 0, 246), (37, 0, 254), (38, 0, 253), (39, 0, 252), (40, 0, 251), (41, 0, 250), (41, 0, 248), (42, 0, 247), (43, 0, 246), (45, 0, 245), (46, 0, 243), (47, 0, 242), (48, 0, 241), (49, 0, 239), (51, 0, 238), (52, 0, 236), (53, 0, 235), (55, 0, 233), (56, 0, 232), (57, 0, 230), (59, 0, 229), (61, 0, 227), (62, 0, 225), (64, 0, 224), (65, 0, 221), (66, 0, 220), (68, 0, 218), (70, 0, 216), (71, 0, 214), (73, 0, 212), (74, 0, 210), (77, 0, 208), (78, 0, 206), (79, 0, 205), (81, 0, 202), (84, 1, 200), (84, 0, 198), (87, 0, 196), (88, 0, 194), (90, 0, 191), (92, 0, 189), (94, 0, 188), (96, 0, 185), (97, 0, 183), (100, 0, 181), (101, 0, 178), (104, 0, 176), (105, 0, 175), (107, 0, 172), (109, 0, 169), (111, 0, 168), (114, 0, 165), (116, 0, 163), (118, 0, 160), (119, 0, 159), (121, 0, 156), (123, 0, 154), (125, 0, 151), (127, 0, 149), (129, 0, 146), (132, 0, 144), (133, 0, 142), (136, 0, 139), (138, 0, 137), (140, 0, 134), (141, 0, 132), (143, 0, 130), (145, 0, 128), (148, 0, 125), (150, 0, 123), (152, 0, 120), (154, 0, 118), (156, 0, 115), (158, 0, 113), (160, 0, 111), (162, 0, 108), (163, 0, 106), (166, 0, 104), (168, 0, 102), (170, 0, 99), (172, 0, 96), (174, 0, 94), (176, 0, 92), (178, 0, 90), (179, 0, 88), (182, 0, 85), (183, 0, 83), (186, 0, 81), (187, 0, 79), (190, 0, 76), (191, 0, 74), (194, 0, 72), (196, 0, 70), (197, 0, 67), (198, 0, 66), (200, 0, 64), (203, 0, 61), (204, 0, 59), (206, 0, 57), (208, 0, 55), (210, 0, 53), (211, 0, 51), (213, 0, 48), (215, 0, 47), (216, 0, 44), (218, 0, 42), (220, 0, 41), (221, 0, 39), (223, 0, 37), (224, 0, 36), (226, 0, 34), (228, 0, 32), (229, 0, 30), (231, 0, 28), (233, 0, 27), (233, 0, 25), (235, 0, 24), (236, 0, 22), (237, 0, 20), (239, 0, 19), (240, 0, 17), (242, 0, 15), (242, 0, 14), (243, 0, 13), (245, 0, 12), (246, 0, 10), (247, 0, 9), (249, 0, 7), (250, 0, 6), (251, 0, 5), (251, 0, 4), (253, 0, 3), (253, 0, 2), (254, 0, 1), (255, 0, 0), (255, 0, 0), (254, 0, 1), (254, 0, 2), (253, 0, 3), (251, 0, 5), (250, 0, 6), (249, 0, 6), (249, 0, 8), (248, 0, 9), (246, 0, 10), (245, 0, 12), (244, 0, 13), (242, 0, 14), (241, 0, 16), (240, 0, 17), (239, 0, 19), (238, 0, 20), (236, 0, 22), (235, 0, 23), (234, 0, 25), (232, 0, 27), (231, 0, 28), (229, 0, 30), (227, 0, 32), (226, 0, 34), (224, 0, 35), (223, 0, 38), (221, 0, 40), (220, 0, 41), (218, 0, 43), (217, 0, 45), (215, 0, 46), (213, 0, 49), (211, 0, 51), (210, 0, 53), (208, 0, 55), (206, 0, 57), (204, 0, 59), (202, 0, 61), (201, 0, 64), (199, 0, 65), (197, 0, 68), (195, 0, 70), (193, 0, 72), (192, 0, 74), (190, 0, 77), (188, 0, 78), (186, 0, 81), (184, 0, 83), (182, 0, 86), (180, 0, 88), (178, 0, 90), (176, 0, 92), (174, 0, 95), (172, 0, 97), (170, 0, 99), (168, 0, 101), (166, 0, 103), (164, 0, 106), (162, 0, 109), (160, 0, 111), (158, 0, 113), (156, 0, 115), (154, 0, 118), (151, 0, 120), (149, 0, 122), (148, 0, 125), (146, 0, 127), (143, 0, 130), (141, 0, 132), (139, 0, 134), (138, 0, 137), (136, 0, 140), (133, 1, 142), (131, 0, 144), (129, 0, 146), (127, 0, 149), (126, 0, 152), (123, 0, 154), (121, 0, 155), (119, 0, 158), (117, 0, 160), (115, 0, 163), (114, 0, 165), (111, 0, 167), (109, 0, 170), (107, 0, 172), (106, 0, 174), (103, 0, 177), (101, 0, 179), (100, 0, 181), (97, 0, 184), (96, 1, 185), (94, 0, 188), (92, 0, 189), (90, 0, 192), (89, 0, 194), (86, 0, 196), (85, 0, 198), (83, 0, 200), (81, 0, 202), (79, 0, 204), (77, 0, 207), (77, 0, 208), (74, 0, 210), (73, 0, 212), (71, 0, 214), (70, 0, 216), (68, 0, 218), (66, 0, 219), (65, 0, 221), (63, 0, 223), (62, 0, 225), (60, 0, 226), (59, 0, 229), (58, 0, 230), (56, 0, 232), (55, 0, 233), (54, 0, 234), (52, 0, 236), (51, 0, 238), (50, 0, 239), (49, 0, 241), (47, 0, 242), (46, 0, 244), (44, 0, 245), (44, 0, 246)};
//long strands have 134 pixels, short strands have 127
#define lightsNum 1043

uint8_t reds [] = {60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 54, 38, 18, 0, 0, 0, 32, 86, 144, 170, 195, 217, 235, 247, 254, 251, 230, 193, 147, 87, 34, 1, 0, 24, 54, 58, 46, 28, 9, 0, 0, 13, 56, 115, 161, 196, 224, 244, 255, 252, 238, 217, 188, 155, 99, 34, 0, 0, 11, 35, 55, 59, 47, 26, 7, 0, 0, 33, 97, 145, 177, 208, 233, 251, 243, 222, 194, 163, 130, 65, 11, 0, 0, 15, 37, 54, 60, 47, 24, 1, 0, 10, 63, 134, 172, 202, 228, 246, 255, 251, 237, 212, 180, 145, 87, 34, 1, 0, 1, 18, 37, 54, 60, 42, 10, 0, 13, 58, 117, 170, 211, 242, 255, 252, 242, 227, 207, 184, 158, 120, 59, 13, 0, 0, 1, 0, 0, 31, 85, 143, 170, 195, 216, 234, 247, 255, 252, 230, 193, 148, 89, 35, 1, 0, 24, 54, 59, 47, 29, 9, 0, 0, 12, 55, 114, 161, 195, 223, 244, 255, 252, 239, 217, 188, 156, 102, 36, 0, 0, 10, 34, 55, 59, 47, 27, 7, 0, 0, 32, 96, 144, 176, 207, 232, 251, 244, 222, 194, 163, 130, 67, 12, 0, 0, 15, 36, 54, 60, 47, 24, 2, 0, 9, 61, 133, 170, 201, 228, 246, 255, 251, 237, 212, 181, 146, 88, 34, 1, 0, 0, 17, 37, 53, 60, 42, 10, 0, 13, 57, 115, 168, 211, 242, 255, 252, 243, 228, 208, 184, 159, 121, 60, 13, 0, 0, 8, 26, 46, 59, 60, 60, 60, 60, 60, 60, 60, 60, 61, 60, 60, 53, 35, 16, 0, 0, 1, 37, 93, 147, 173, 198, 219, 236, 248, 254, 251, 227, 188, 142, 82, 30, 0, 0, 29, 56, 58, 45, 26, 8, 0, 0, 16, 62, 122, 165, 199, 226, 246, 255, 251, 236, 214, 185, 152, 92, 30, 0, 0, 13, 38, 56, 58, 45, 25, 5, 0, 0, 38, 106, 148, 181, 209, 235, 252, 242, 218, 191, 159, 126, 59, 8, 0, 0, 17, 39, 56, 59, 45, 22, 0, 0, 15, 70, 140, 174, 204, 230, 248, 255, 250, 234, 208, 177, 141, 81, 29, 0, 0, 3, 20, 39, 55, 59, 39, 6, 0, 17, 64, 122, 174, 215, 244, 255, 251, 241, 225, 205, 181, 156, 114, 53, 10, 0, 0, 10, 20, 3, 0, 0, 26, 79, 141, 167, 192, 215, 233, 246, 254, 253, 233, 198, 153, 95, 40, 4, 0, 20, 51, 59, 48, 31, 11, 0, 0, 9, 50, 108, 158, 192, 221, 243, 253, 253, 241, 220, 191, 159, 109, 42, 1, 0, 8, 32, 53, 60, 49, 29, 9, 0, 0, 27, 89, 141, 174, 204, 230, 249, 246, 224, 197, 167, 134, 73, 17, 0, 0, 13, 34, 52, 60, 49, 26, 4, 0, 6, 55, 125, 168, 198, 225, 244, 254, 253, 239, 215, 185, 150, 94, 39, 3, 0, 0, 15, 35, 52, 60, 46, 14, 0, 9, 51, 109, 164, 207, 240, 254, 252, 243, 229, 210, 187, 161, 128, 66, 18, 0, 0, 6, 25, 45, 58, 60, 60, 60, 60, 60, 60, 60, 60, 60, 52, 34, 13, 0, 0, 3, 42, 99, 149, 176, 200, 220, 237, 250, 255, 249, 223, 184, 135, 75, 26, 0, 1, 31, 58, 57, 43, 24, 6, 0, 0, 20, 68, 128, 169, 202, 229, 247, 255, 250, 234, 211, 182, 148, 85, 24, 0, 0, 15, 40, 58, 58, 43, 22, 3, 0, 1, 44, 112, 152, 184, 213, 237, 254, 239, 216, 188, 156, 121, 52, 4, 0, 2, 20, 40, 56, 58, 43, 19, 0, 0, 18, 77, 144, 178, 208, 232, 248, 255, 249, 232, 205, 173, 136, 75, 25, 0, 0, 4, 22, 41, 56, 59, 35, 4, 0, 21, 68, 129, 178, 219, 247, 255, 251, 240, 223, 202, 178, 153, 107, 48, 7, 0, 0, 12, 32, 42, 22, 4, 0, 0, 23, 73, 136, 164, 189, 212, 231, 246, 253, 253, 236, 202, 158, 101, 45, 6, 0, 17, 49, 59, 50, 33, 13, 0, 0, 6, 45, 102, 153, 188, 218, 240, 253, 254, 243, 222, 195, 163, 116, 47, 3, 0, 7, 30, 51, 60, 50, 32, 10, 0, 0, 22, 82, 138, 171, 201, 227, 247, 247, 226, 200, 170, 137, 81, 21, 0, 0, 11, 32, 51, 60, 51, 29, 6, 0, 3, 49, 117, 164, 195, 222, 242, 254, 253, 240, 218, 188, 153, 101, 44, 6, 0, 0, 14, 33, 50, 60, 48, 16, 0, 7, 46, 102, 158, 202, 236, 254, 254, 245, 231, 212, 190, 165, 135, 71, 22, 0, 0, 4, 22, 43, 57, 60, 60, 60, 60, 60, 60, 60, 50, 32, 12, 0, 0, 6, 47, 106, 152, 178, 202, 223, 239, 250, 255, 246, 219, 179, 130, 70, 22, 0, 4, 35, 58, 56, 42, 22, 4, 0, 0, 23, 74, 135, 173, 205, 231, 248, 255, 249, 233, 208, 178, 145, 79, 19, 0, 0, 18, 42, 58, 57, 41, 20, 2, 0, 4, 51, 120, 156, 187, 215, 239, 254, 237, 214, 185, 153, 114, 46, 2, 0, 3, 22, 43, 57, 58, 40, 17, 0, 0, 23, 84, 148, 181, 211, 234, 250, 255, 247, 229, 202, 170, 130, 70, 20, 0, 0, 6, 23, 42, 57, 58, 32, 1, 0, 24, 74, 135, 183, 222, 248, 255, 250, 238, 221, 200, 177, 150, 102, 42, 5, 0, 0, 13, 33, 51, 58, 44, 24, 6, 0, 0, 18, 67, 129, 162, 188, 211, 230, 244, 252, 254, 238, 206, 162, 107, 50, 9, 0, 13, 46, 60, 52, 34, 14, 0, 0, 3, 40, 95, 150, 185, 216, 238, 252, 254, 244, 225, 198, 166, 124, 53, 5, 0, 4, 27, 49, 61, 52, 33, 13, 0, 0, 17, 74, 135, 167, 198, 225, 246, 249, 230, 203, 173, 141, 87, 26, 0, 0, 9, 30, 49, 59, 53, 31, 8, 0, 1, 42, 111, 161, 193, 220, 241, 253, 254, 242, 220, 191, 156, 106, 49, 8, 0, 0, 11, 31, 49, 60, 51, 20, 0, 4, 41, 97, 154, 199, 234, 253, 253, 246, 233, 214, 192, 166, 140, 78, 26, 0, 0, 3, 20, 40};

uint8_t greens [] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 237, 193, 138, 83, 33, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 164, 241, 251, 222, 173, 115, 58, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 51, 122, 192, 242, 253, 223, 170, 106, 46, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 73, 137, 198, 241, 255, 222, 160, 88, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 84, 142, 198, 239, 255, 210, 116, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 55, 85, 36, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 162, 241, 251, 224, 175, 117, 59, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 51, 120, 191, 243, 253, 225, 171, 108, 47, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 72, 135, 196, 241, 255, 225, 161, 89, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 83, 141, 197, 238, 255, 212, 118, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 54, 108, 164, 214, 252, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 233, 187, 133, 78, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 75, 173, 246, 250, 218, 168, 109, 54, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 58, 130, 199, 246, 252, 219, 165, 100, 41, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 79, 143, 203, 244, 254, 217, 154, 81, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 38, 90, 149, 204, 242, 254, 203, 105, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 61, 115, 145, 90, 39, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53, 151, 234, 253, 227, 180, 122, 65, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44, 113, 184, 238, 254, 229, 177, 114, 53, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 65, 128, 191, 238, 255, 229, 169, 96, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 77, 136, 193, 235, 254, 220, 129, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 49, 102, 158, 210, 248, 255, 255, 255, 255, 255, 255, 255, 255, 255, 230, 182, 127, 71, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 83, 182, 249, 248, 214, 161, 103, 48, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 65, 137, 205, 249, 250, 214, 158, 93, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 85, 149, 208, 247, 251, 212, 146, 74, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 41, 95, 155, 208, 245, 253, 194, 95, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 65, 121, 176, 204, 152, 95, 44, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 141, 228, 254, 232, 185, 129, 70, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 105, 178, 235, 255, 233, 184, 121, 58, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 60, 122, 185, 233, 255, 233, 177, 103, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 72, 130, 187, 232, 254, 227, 139, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 45, 96, 152, 205, 245, 255, 255, 255, 255, 255, 255, 255, 225, 177, 122, 67, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 94, 193, 252, 245, 210, 156, 97, 43, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 72, 144, 211, 251, 248, 210, 152, 86, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 92, 156, 213, 250, 249, 206, 139, 66, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 47, 102, 161, 213, 247, 250, 185, 85, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 71, 126, 182, 228, 248, 209, 157, 100, 49, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 131, 221, 255, 234, 191, 134, 76, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 97, 170, 230, 255, 237, 189, 127, 64, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 54, 116, 178, 230, 254, 238, 183, 111, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 65, 123, 182, 228, 253, 234, 150, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 39, 91, 147, 200};

uint8_t blues [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(lightsNum, PIN, NEO_GRB + NEO_KHZ800);

long waitTime = 5;
long startTime = 0;

void setup() {
  startTime = millis();

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();
}

void loop() {
  for(int i=0; i<lightsNum; i++) { // For each pixel...
    uint32_t color = pixels.Color(reds[i], greens[i], blues[i]);
    pixels.setPixelColor(i, color);
  }
  pixels.show();   // Send the updated pixel colors to the hardware.

}
