/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** cutscene
*/

#include "rpg.h"

void cutscene(game_t *game)
{
    game->all_spt.cutscene.status_cutscene = 1;
    if (sfClock_getElapsedTime(game->all_spt.cutscene.clock).microseconds <
        150000)
        return;
    sfClock_restart(game->all_spt.cutscene.clock);
    sfRenderWindow_drawSprite(game->win, game->all_spt.cutscene.sprite, NULL);
    sfSprite_setTextureRect(game->all_spt.cutscene.sprite,
    game->all_spt.cutscene.rect);
    game->all_spt.cutscene.rect.left += 710;
    if (game->all_spt.cutscene.rect.left > (710 * 4)) {
        game->all_spt.cutscene.rect.left = 0;
        game->all_spt.cutscene.rect.top += 400;
    }
    if (game->all_spt.cutscene.rect.top > (400 * 40) ||
        sfKeyboard_isKeyPressed(sfKeyU))
        game->all_spt.cutscene.status_cutscene = 2;
}
