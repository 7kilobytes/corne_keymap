#pragma once

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    SYM_LAYER,
    NUM_LAYER,
    NAV_LAYER,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);
void sym_layer_finished(qk_tap_dance_state_t *state, void *user_data);
void sym_layer_reset(qk_tap_dance_state_t *state, void *user_data);
void num_layer_finished(qk_tap_dance_state_t *state, void *user_data);
void num_layer_reset(qk_tap_dance_state_t *state, void *user_data);
    

