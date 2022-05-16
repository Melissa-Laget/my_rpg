/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** collision
*/

#include "rpg.h"
#include "draw.h"

bool check_collision(game_t *game, int x, int y)
{
    sfColor color = sfImage_getPixel(game->background.collision_image,
    x, y);

    if (color.a == 0 || color.r == 0 || color.g == 0 || color.b == 0)
        return false;
    return true;
}
