#ifndef BOOTMAGIC_H
#define BOOTMAGIC_H


/* bootmagic salt key */
#ifndef BOOTMAGIC_KEY_SALT
#define BOOTMAGIC_KEY_SALT              KC_SPACE
#endif

/* skip bootmagic and eeconfig */
#ifndef BOOTMAGIC_KEY_SKIP
#define BOOTMAGIC_KEY_SKIP              KC_ESC
#endif

/* eeprom clear */
#ifndef BOOTMAGIC_KEY_EEPROM_CLEAR
#define BOOTMAGIC_KEY_EEPROM_CLEAR      KC_BSPACE
#endif

/* kick up bootloader */
#ifndef BOOTMAGIC_KEY_BOOTLOADER
#define BOOTMAGIC_KEY_BOOTLOADER        KC_B
#endif

/* debug enable */
#ifndef BOOTMAGIC_KEY_DEBUG_ENABLE
#define BOOTMAGIC_KEY_DEBUG_ENABLE      KC_D
#endif
#ifndef BOOTMAGIC_KEY_DEBUG_MATRIX
#define BOOTMAGIC_KEY_DEBUG_MATRIX      KC_X
#endif
#ifndef BOOTMAGIC_KEY_DEBUG_KEYBOARD
#define BOOTMAGIC_KEY_DEBUG_KEYBOARD    KC_K
#endif
#ifndef BOOTMAGIC_KEY_DEBUG_MOUSE
#define BOOTMAGIC_KEY_DEBUG_MOUSE       KC_M
#endif

/*
 * keymap config
 */
#ifndef BOOTMAGIC_KEY_SWAP_CONTROL_CAPSLOCK
#define BOOTMAGIC_KEY_SWAP_CONTROL_CAPSLOCK     KC_LCTRL
#endif
#ifndef BOOTMAGIC_KEY_CAPSLOCK_TO_CONTROL
#define BOOTMAGIC_KEY_CAPSLOCK_TO_CONTROL       KC_CAPSLOCK
#endif
#ifndef BOOTMAGIC_KEY_SWAP_LALT_LGUI
#define BOOTMAGIC_KEY_SWAP_LALT_LGUI            KC_LALT
#endif
#ifndef BOOTMAGIC_KEY_SWAP_RALT_RGUI
#define BOOTMAGIC_KEY_SWAP_RALT_RGUI            KC_RALT
#endif
#ifndef BOOTMAGIC_KEY_NO_GUI
#define BOOTMAGIC_KEY_NO_GUI                    KC_LGUI
#endif
#ifndef BOOTMAGIC_KEY_SWAP_GRAVE_ESC
#define BOOTMAGIC_KEY_SWAP_GRAVE_ESC            KC_GRAVE
#endif
#ifndef BOOTMAGIC_KEY_SWAP_BACKSLASH_BACKSPACE
#define BOOTMAGIC_KEY_SWAP_BACKSLASH_BACKSPACE  KC_BSLASH
#endif
#ifndef BOOTMAGIC_HOST_NKRO
#define BOOTMAGIC_HOST_NKRO              KC_N
#endif


/*
 * change default layer
 */
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_0
#define BOOTMAGIC_KEY_DEFAULT_LAYER_0   KC_0
#endif
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_1
#define BOOTMAGIC_KEY_DEFAULT_LAYER_1   KC_1
#endif
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_2
#define BOOTMAGIC_KEY_DEFAULT_LAYER_2   KC_2
#endif
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_3
#define BOOTMAGIC_KEY_DEFAULT_LAYER_3   KC_3
#endif
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_4
#define BOOTMAGIC_KEY_DEFAULT_LAYER_4   KC_4
#endif
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_5
#define BOOTMAGIC_KEY_DEFAULT_LAYER_5   KC_5
#endif
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_6
#define BOOTMAGIC_KEY_DEFAULT_LAYER_6   KC_6
#endif
#ifndef BOOTMAGIC_KEY_DEFAULT_LAYER_7
#define BOOTMAGIC_KEY_DEFAULT_LAYER_7   KC_7
#endif


void bootmagic(void);
bool bootmagic_scan_keycode(uint8_t keycode);

#endif
