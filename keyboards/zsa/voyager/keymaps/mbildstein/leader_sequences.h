void leader_end_user(void) {
    if (leader_sequence_one_key(KC_A)) {
        SEND_STRING("and");
    } else if (leader_sequence_one_key(KC_B)) {
        SEND_STRING("but");
    } else if (leader_sequence_one_key(KC_F)) {
        SEND_STRING("for");
    } else if (leader_sequence_one_key(KC_H)) {
        SEND_STRING("here");
    } else if (leader_sequence_one_key(KC_N)) {
        SEND_STRING("not");
    } else if (leader_sequence_one_key(KC_R)) {
        SEND_STRING("are");
    } else if (leader_sequence_one_key(KC_T)) {
        SEND_STRING("the");
    } else if (leader_sequence_one_key(KC_U)) {
        SEND_STRING("you");
    } else if (leader_sequence_one_key(KC_V)) {
        SEND_STRING("very");
    } else if (leader_sequence_one_key(KC_W)) {
        SEND_STRING("with");
    } else if (leader_sequence_two_keys(KC_D, KC_N)) {
        SEND_STRING("don't");
    } else if (leader_sequence_two_keys(KC_E, KC_V)) {
        SEND_STRING("every");
    } else if (leader_sequence_two_keys(KC_I, KC_T)) {
        SEND_STRING("in the");
    } else if (leader_sequence_two_keys(KC_O, KC_T)) {
        SEND_STRING("of the");
    } else if (leader_sequence_two_keys(KC_T, KC_A)) {
        SEND_STRING("that");
    } else if (leader_sequence_two_keys(KC_T, KC_S)) {
        SEND_STRING("this");
    } else if (leader_sequence_two_keys(KC_W, KC_H)) {
        SEND_STRING("which");
    }
}