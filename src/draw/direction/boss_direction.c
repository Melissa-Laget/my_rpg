/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** boss_direction
*/

#include "draw.h"

void boss_direction(player_t *player, boss_t *boss)
{
    if (player->pos.x - 5 < boss->pos.x
        && (player->pos.y - 5 < boss->pos.y
        && player->pos.y + 5 > boss->pos.y)) {
        boss->direction = LEFT_STATIC;
    }
    if (player->pos.x > boss->pos.x
        && (player->pos.y - 5 < boss->pos.y
        && player->pos.y + 5 > boss->pos.y)) {
        boss->direction = RIGHT_STATIC;
    }
    if (player->pos.y > boss->pos.y
        && (player->pos.x - 5 < boss->pos.x
        && player->pos.x + 5 > boss->pos.x)) {
        boss->direction = DOWN_STATIC;
    }
    if (player->pos.y < boss->pos.y
        && (player->pos.x - 5 < boss->pos.x
        && player->pos.x + 5 > boss->pos.x)) {
        boss->direction = UP_STATIC;
    }
}
