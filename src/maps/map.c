/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** map
*/

#include "event.h"
#include "rpg.h"

int init_map(game_t *game)
{
    if ((game->background.colors = sfImage_createFromFile(
        "assets/background/map.png")) == NULL)
        return -1;
    if ((game->background.texture = sfTexture_createFromImage(
        game->background.colors, NULL)) == NULL)
        return -2;
    if ((game->background.collision_image = sfImage_createFromFile(
        "assets/background/map_collision.png")) == NULL)
        return -3;
    game->background.background_size = sfTexture_getSize(
    game->background.texture);
    if ((game->background.depth = sfTexture_createFromFile(
        "assets/background/3d_depth.png", NULL)) == NULL)
        return -4;
    game->background.depth_size = sfTexture_getSize(
    game->background.depth);
    return 0;
}
