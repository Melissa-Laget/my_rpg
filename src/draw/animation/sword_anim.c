/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sword_anim
*/

#include "draw.h"
#include "my.h"

void sword_animation(attack_t *sword, player_t *player)
{
    player->direction += 8;
    if (sfClock_getElapsedTime(sword->clock).microseconds > 75000) {
        sword->rect.top = 96 * sword->attack_direction;
        if (sword->rect.left >= 0 && sword->rect.left < 96 * 3) {
            sword->rect.left += 96;
        } else {
            sword->rect.left = 0;
            sword->attack = 0;
        }
        sfSprite_setTextureRect(sword->sprite, sword->rect);
        sfClock_restart(sword->clock);
        sfSprite_setColor(sword->sprite, sfColor_fromRGBA(255, 255, 255, 255));
    }
}
