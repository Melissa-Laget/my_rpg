/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** draw_boss
*/

#include "draw.h"

int draw_npc(game_t *game)
{
    for (list_t *tmp = game->npc; tmp != NULL; tmp = tmp->next) {
        npc_animation(game->all_spt.player, tmp->data);
        player_animation(tmp->data);
        sfSprite_setPosition(((player_t *)tmp->data)->sprite,
        ((player_t *)tmp->data)->pos);
        if (((player_t *)tmp->data)->hp <= 0) {
            sfSprite_setColor(((player_t *)tmp->data)->sprite,
            sfColor_fromRGBA(0, 0, 0, 0));
        }
        sfRenderWindow_drawSprite(game->win, ((player_t *)tmp->data)->sprite,
        NULL);
    }
    return 0;
}
