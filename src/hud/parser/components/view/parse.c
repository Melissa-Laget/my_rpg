/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** parse
*/

#include "hud.h"

const char *hud_parser_view_parser(char *schemat, hud_t *hud,
list_t **container)
{
    hud_view_t *view = hud_view_init();
    char **keys = NULL;
    char *keystr = str_dup_from_to(schemat, '@', '@');

    if (keystr == NULL)
        return schemat;
    for (schemat++; *schemat != '\0' && *schemat != '@'; ++schemat);
    keys = hud_parser_get_keys(keystr);
    if (schemat == NULL)
        return NULL;
    if (schemat[0] != '\0')
        schemat++;
    hud_parser_view_get_value(view, keys);
    hud_parser_view_get_other(hud, view, keys);
    free_arr((void **)keys);
    *container = list_append(*container, view);
    hud->all_views = list_append(hud->all_views, view);
    free(keystr);
    return schemat;
}
