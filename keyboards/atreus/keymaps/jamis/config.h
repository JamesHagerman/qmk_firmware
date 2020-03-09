#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// This assumes you've hooked your ws2812 leds to the pololu A-Star pin 15/PB1 on the programmer header:
#define RGB_DI_PIN B1    // The pin the LED strip is connected to (avr names)

#define RGBLIGHT_ANIMATIONS
// This assumes you have two LED's for status...
#define RGBLED_NUM 2     // Number of LEDs in your strip

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Make the hold timeout be shorter...
#define TAPPING_TERM 200

// Make mouse stuff better
#define MOUSEKEY_DELAY 10 // default 300
#define MOUSEKEY_INTERVAL 20 // default 50

// Fix for chattering cherry switches
#undef DEBOUNCE
#define DEBOUNCE 15

#endif

