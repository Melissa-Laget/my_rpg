/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** values
*/

#include "hud.h"

static void hud_parser_button_get_value_3(hud_button_t *button,
char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "color=")) != NULL) {
        button->color = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "borderColor=")) != NULL) {
        button->borderColor = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "actionColor=")) != NULL) {
        button->actionColor = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "actionBorderColor=")) != NULL) {
        button->actionBorderColor = hud_parser_sfcolor(key);
        free(key);
    }
}

static void hud_parser_button_get_value_2(hud_button_t *button,
char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "border=")) != NULL) {
        button->border = hud_parser_bool(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "toggleable=")) != NULL) {
        button->toggleable = hud_parser_bool(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "toggle=")) != NULL) {
        button->toggle = hud_parser_bool(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "hidden=")) != NULL) {
        button->hidden = hud_parser_bool(key);
        free(key);
    }
    hud_parser_button_get_value_3(button, keys);
}

void hud_parser_button_get_value(hud_button_t *button, char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "name=")) != NULL) {
        button->name = hud_parser_str(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "pos=")) != NULL) {
        button->pos = hud_parser_int_rect(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "borderWidth=")) != NULL) {
        button->borderWidth = hud_parser_float_rect(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "key=")) != NULL) {
        button->key = hud_parser_int(key);
        free(key);
    }
    hud_parser_button_get_value_2(button, keys);
}
