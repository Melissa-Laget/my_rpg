/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** constructor
*/

#include "hud.h"

sfIntRect hud_parser_int_rect(char *rect_constr)
{
    char **arr = str_to_array(rect_constr, ":");
    int nbrs[] = {0, 0, 0, 0};

    if (arr == NULL)
        return ((sfIntRect){.left = -1, .top = -1, .width = -1, .height = -1});
    for (int i = 0; i < 4; i++) {
        if (arr[i] == NULL) {
            free_arr((void **)arr);
            return ((sfIntRect) {.left = -1, .top = -1,
            .width = -1, .height = -1});
        }
        nbrs[i] = my_getnbr(arr[i]);
    }
    free_arr((void **)arr);
    return ((sfIntRect){.left = nbrs[0], .top = nbrs[1],
    .width = nbrs[2], .height = nbrs[3]});
}

sfFloatRect hud_parser_float_rect(char *rect_constr)
{
    char **arr = str_to_array(rect_constr, ":");
    float nbrs[] = {0, 0, 0, 0};

    if (arr == NULL)
        return ((sfFloatRect){.left = -1, .top = -1,
        .width = -1, .height = -1});
    for (int i = 0; i < 4; i++) {
        if (arr[i] == NULL)
            return ((sfFloatRect){.left = -1, .top = -1,
            .width = -1, .height = -1});
        nbrs[i] = (float)my_getnbr(arr[i]);
    }
    return ((sfFloatRect){.left = nbrs[0], .top = nbrs[1],
    .width = nbrs[2], .height = nbrs[3]});
}

sfColor hud_parser_sfcolor(char *color_constr)
{
    char **arr = str_to_array(color_constr, ":");
    int nbrs[] = {0, 0, 0, 0};

    if (arr == NULL)
        return ((sfColor){.r = 255, .g = 255, .b = 255, .a = 255});
    for (int i = 0; i < 4; i++) {
        if (arr[i] == NULL) {
            free_arr((void **)arr);
            return ((sfColor){.r = 255, .g = 255, .b = 255, .a = 255});
        }
        nbrs[i] = my_getnbr(arr[i]);
    }
    free_arr((void **)arr);
    return ((sfColor){.r = nbrs[0], .g = nbrs[1], .b = nbrs[2], .a = nbrs[3]});
}
