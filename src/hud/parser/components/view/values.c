/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** values
*/

#include "hud.h"

static void hud_parser_view_get_value_3(hud_view_t *view,
char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "color=")) != NULL) {
        view->color = hud_parser_sfcolor(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "borderColor=")) != NULL) {
        view->borderColor = hud_parser_sfcolor(key);
        free(key);
    }
}

static void hud_parser_view_get_value_2(hud_view_t *view,
char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "border=")) != NULL) {
        view->border = hud_parser_bool(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "hidden=")) != NULL) {
        view->hidden = hud_parser_bool(key);
        free(key);
    }
    hud_parser_view_get_value_3(view, keys);
}

void hud_parser_view_get_value(hud_view_t *view, char **keys)
{
    char *key = NULL;

    if ((key = hud_parser_get_key(keys, "name=")) != NULL) {
        view->name = hud_parser_str(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "pos=")) != NULL) {
        view->pos = hud_parser_int_rect(key);
        free(key);
    }
    if ((key = hud_parser_get_key(keys, "borderWidth=")) != NULL) {
        view->borderWidth = hud_parser_float_rect(key);
        free(key);
    }
    hud_parser_view_get_value_2(view, keys);
}
