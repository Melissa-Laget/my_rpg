/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** npc_anim
*/

#include "draw.h"

void npc_animation(player_t *player, player_t *npc)
{
    npc->direction = DOWN_STATIC;

    if (player->pos.x < npc->pos.x && player->pos.x > npc->pos.x - 100 &&
        player->pos.y - 50 < npc->pos.y && player->pos.y + 50 > npc->pos.y)
        npc->direction = LEFT_STATIC;
    if (player->pos.x > npc->pos.x && player->pos.x < npc->pos.x + 100 &&
        player->pos.y - 50 < npc->pos.y && player->pos.y + 50 > npc->pos.y)
        npc->direction = RIGHT_STATIC;
    if (player->pos.y > npc->pos.y && player->pos.y < npc->pos.y + 100 &&
        player->pos.x - 50 < npc->pos.x && player->pos.x + 50 > npc->pos.x)
        npc->direction = DOWN_STATIC;
    if (player->pos.y < npc->pos.y && player->pos.y > npc->pos.y - 100 &&
        player->pos.x - 50 < npc->pos.x && player->pos.x + 50 > npc->pos.x)
        npc->direction = UP_STATIC;
}
