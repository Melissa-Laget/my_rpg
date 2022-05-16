/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** player
*/

#include "draw.h"

sfFloatRect sword_collision_direction(game_t *game, sfFloatRect rect)
{
    if (game->all_spt.sword->attack_direction == RIGHT_ATK) {
        rect.width = 75;
        rect.height = 86;
    }
    if (game->all_spt.sword->attack_direction == LEFT_ATK) {
        rect.width = 66;
        rect.height = 86;
    }
    if (game->all_spt.sword->attack_direction == UP_ATK) {
        rect.width = 64;
        rect.height = 60;
    }
    if (game->all_spt.sword->attack_direction == DOWN_ATK) {
        rect.width = 80;
        rect.height = 76;
    }
    return rect;
}

void sword_direction(attack_t *sword, player_t *player)
{
    if (player->direction == DOWN_STATIC) {
        sword->attack_direction = DOWN_ATK;
        sfSprite_setPosition(sword->sprite,
        ((sfVector2f){player->pos.x - 48, player->pos.y - 28}));
    }
    if (player->direction == UP_STATIC) {
        sword->attack_direction = UP_ATK;
        sfSprite_setPosition(sword->sprite,
        ((sfVector2f){player->pos.x - 54, player->pos.y - 96}));
    }
    if (player->direction == LEFT_STATIC) {
        sword->attack_direction = LEFT_ATK;
        sfSprite_setPosition(sword->sprite,
        ((sfVector2f){player->pos.x - 96, player->pos.y - 54}));
    }
    if (player->direction == RIGHT_STATIC) {
        sword->attack_direction = RIGHT_ATK;
        sfSprite_setPosition(sword->sprite,
        ((sfVector2f){player->pos.x - 12, player->pos.y - 54}));
    }
}
