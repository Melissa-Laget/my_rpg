/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** parse
*/

#include "hud.h"

const char *hud_parser_button_parser(char *schemat, hud_t *hud,
list_t **container)
{
    hud_button_t *button = hud_button_init();
    char **keys = NULL;
    char *keystr = str_dup_from_to(schemat, '@', '@');

    if (keystr == NULL)
        return schemat;
    keys = hud_parser_get_keys(keystr);
    schemat = hud_parser_skip_tag(schemat);
    if (schemat == NULL)
        return NULL;
    if (schemat[0] != '\0')
        schemat++;
    hud_parser_button_get_value(button, keys);
    hud_parser_button_get_other(hud, button, keys);
    hud_parser_button_get_text(button, keys);
    free_arr((void **)keys);
    *container = list_append(*container, button);
    hud->all_buttons = list_append(hud->all_buttons, button);
    free(keystr);
    return schemat;
}
