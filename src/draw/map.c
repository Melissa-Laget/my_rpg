/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** map
*/

#include "event.h"
#include "rpg.h"

void draw_map(game_t *game)
{
    sfVertexArray *rect = NULL;
    sfRenderStates states;

    if (game->background.texture == NULL)
        return;
    rect = hud_create_rect(((sfFloatRect){.left = 0, .top = 0,
    .width = game->background.background_size.x,
    .height = game->background.background_size.y}),
    sfWhite, ((sfVector2f){0, 0}), game->background.texture);
    states.shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = game->background.texture;
    sfRenderWindow_drawVertexArray(game->win, rect, &states);
    sfVertexArray_destroy(rect);
}

void draw_map_depth(game_t *game)
{
    sfVertexArray *rect = NULL;
    sfRenderStates states;

    if (game->background.depth == NULL)
        return;
    rect = hud_create_rect(((sfFloatRect){.left = 0, .top = 0,
    .width = game->background.depth_size.x,
    .height = game->background.depth_size.y}),
    sfWhite, ((sfVector2f){0, 0}), game->background.depth);
    states.shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = game->background.depth;
    sfRenderWindow_drawVertexArray(game->win, rect, &states);
    sfVertexArray_destroy(rect);
}
