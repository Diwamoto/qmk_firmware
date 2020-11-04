#include "ownly.h"

#ifdef SSD1306OLED
void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    //led_set_user(usb_led);
}
#endif

/*
* The following settings are for rgb matrix.
* They have not been enabled because rgb matrix
* cannot be applied to a split keyboard at this time.
*/

// Logical Layout
  // Columns
  // Left
  // 0  1  2  3  4  5
  //                   ROWS
  // 24 23 15 14 05 04   0
  // 25 22 16 13 06 03   1
  // 26 21 17 12 07 02   2
  // 27 20 18 11 08 01   3
  // 28    19 10 09      4
  //
  // Right
  // 0  1  2  3  4  5
  //                   ROWS
  // 26 25 16 15 06 05   5
  // 27 24 17 14 07 04   6
  // 28 23 18 13 08 03   7
  // 29 22 19 12 09 02   8
  //    21 20 11 10 01   9
  //
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                               ROWS
  // 24 23 15 14 05 04       26 25 16 15 06 05     0
  //  25 22 16 13 06 03       27 24 17 14 07 04    1
  //  26  21 17 12 07 02       28 23 18 13 08 03   2
  // 27    20 18 11 08 01       29 22 19 12 09 02  3
  // 28       19   10  09       21   20  11 10 01  4
  //



// led_config_t g_led_config = { {
//     {  23, 22, 14, 13, 4, 3 },
//     {  24, 21, 15, 12, 5, 2 },
//     {  25, 20, 16, 11, 6, 1 },
//     {  26, 19, 17, 10, 7, 0 },
//     {  27, NO_LED, 18, 9, 8,NO_LED},
//     {  53, 52, 43, 42, 33, 32},
//     {  54, 51, 44, 41, 34, 31 },
//     {  55, 50, 45, 40, 35, 30 },
//     {  56, 49, 46, 39, 36, 29 },
//     {  NO_LED,  48, 47, 38, 37, 28}
// }, {
//     {   0,  0  }, {  36,  0  }, {  54,  0  }, {  72,  0  }, {  90,  0  }, { 108,  0  },
//     {   0,  16 }, {  36,  16 }, {  54,  16 }, {  72,  16 }, {  90,  16 }, { 108,  16 },
//     {   0,  32 }, {  36,  32 }, {  54,  32 }, {  72,  32 }, {  90,  32 }, { 108,  32 },
//     {   0,  48 }, {  36,  48 }, {  54,  48 }, {  72,  48 }, {  90,  48 }, { 108,  48 },
//     {   0,  64 },               {  54,  64 }, {  72,  64 }, {  90,  64 },

//     { 126,  0  }, { 144,  0  }, { 162,  0  }, { 180,  0  }, { 198,  0  }, { 216,  0  },
//     { 126,  16 }, { 144,  16 }, { 162,  16 }, { 180,  16 }, { 198,  16 }, { 216,  16 },
//     { 126,  32 }, { 144,  32 }, { 162,  32 }, { 180,  32 }, { 198,  32 }, { 216,  32 },
//     { 126,  48 }, { 144,  48 }, { 162,  48 }, { 180,  48 }, { 198,  48 }, { 216,  48 },
//     { 126,  64 },      { 144,  64 },          { 180,  64 }, { 198,  64 }, { 216,  64 }
// }, {
//     4,4,4,4,4,4,
//     4,4,4,4,4,4,
//     4,4,4,4,4,4,
//     4,4,4,4,4,4,
//     4,    4,4,4,
//     4,4,4,4,4,4,
//     4,4,4,4,4,4,
//     4,4,4,4,4,4,
//     4,4,4,4,4,4,
//     4,  4,4,4,4
// } };
