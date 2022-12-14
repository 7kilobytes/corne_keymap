#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define TAPPING_TOGGLE 2

// how quickly all combo keys must be pressed in succession to trigger
#define COMBO_TERM 25

// if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_MUST_HOLD_MODS

// how long at least one of the combo keys must be held to trigger
#define COMBO_HOLD_TERM 175

// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL 15
// The default is 19. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
// #undef MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX 39
// The default is 299. Let's try and make this as low as possible while keeping the cursor responsive
// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY 99

// Mouse setting
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1

#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED 1

#undef MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED 12

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 22
#define USB_SUSPEND_WAKEUP_DELAY 0

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3
// #define COMBO_ONLY_FROM_LAYER 0

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
