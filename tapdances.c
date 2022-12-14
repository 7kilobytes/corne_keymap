#include "tapdances.h"

static td_tap_t sym_layer_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t num_layer_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [SYM_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_layer_finished, sym_layer_reset),
    [NUM_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_layer_finished, num_layer_reset),
//    [NAV_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_layer_finished, nav_layer_reset),
};

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (! state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted) {
            return TD_DOUBLE_SINGLE_TAP;
        } else if (state->pressed) {
            return TD_DOUBLE_HOLD;
        } else {
            return TD_DOUBLE_TAP;
        }
    } else {
        return TD_UNKNOWN;
    }
}

void sym_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
    sym_layer_tap_state.state = cur_dance(state);
    switch (sym_layer_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_BSPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_SYM);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_SYM)) {
                // If already set, then switch it off
                layer_off(_SYM);
            } else {
                // If not already set, then switch the layer on
                layer_on(_SYM);
            }
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_BSPC);
            break;
        default:
            break;
    }
}

void sym_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (sym_layer_tap_state.state) {
            case TD_SINGLE_HOLD:
        if (sym_layer_tap_state.state == TD_SINGLE_HOLD) {
            layer_off(_SYM);
        }
        break;
    case TD_SINGLE_TAP:
    case TD_DOUBLE_HOLD:
        unregister_code(KC_BSPC);
        break;

    default:
        break;
    }
    // If the key was held down and now is released then switch off the layer
    // if (sym_layer_tap_state.state == TD_SINGLE_HOLD) {
    //     layer_off(_SYM);
    // }
    sym_layer_tap_state.state = TD_NONE;
}

void num_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
    num_layer_tap_state.state = cur_dance(state);
    switch (num_layer_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NUM);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_NUM)) {
                // If already set, then switch it off
                layer_off(_NUM);
            } else {
                // If not already set, then switch the layer on
                layer_on(_NUM);
            }
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_ESC);
            break;
        default:
            break;
    }
}

void num_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (num_layer_tap_state.state) {
    case TD_SINGLE_HOLD:
        if (num_layer_tap_state.state == TD_SINGLE_HOLD) {
            layer_off(_NUM);
        }
        break;
    case TD_SINGLE_TAP:
    case TD_DOUBLE_HOLD:
        unregister_code(KC_ESC);
        break;

    default:
        break;
    }
    // If the key was held down and now is released then switch off the layer
    // if (num_layer_tap_state.state == TD_SINGLE_HOLD) {
    //     layer_off(_NUM);
    // }
    num_layer_tap_state.state = TD_NONE;
}

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}
