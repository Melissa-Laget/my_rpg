/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** player_anim
*/

#include "draw.h"

void player_animation(player_t *player)
{
    if (sfClock_getElapsedTime(player->clock).microseconds > (
        (player->direction < (direction_t)DOWN_ATK &&
        player->direction > UP_STATIC) ? 75000 : 150000)) {
        player->rect.top = 48 * player->direction;
        if (player->rect.left >= 0 && player->rect.left < 48 * 3) {
            player->rect.left += 48;
        } else {
            player->rect.left = 0;
        }
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->clock);
    }
}

void attack_animation(game_t *game)
{
    if (game->all_spt.fire->attack == 1)
        spell_animation(game->all_spt.fire, 12, 83);
    if (game->all_spt.ice->attack == 1)
        spell_animation(game->all_spt.ice, 6, 84);
    if (game->all_spt.poison->attack == 1)
        spell_animation(game->all_spt.poison, 6, 84);
    if (game->all_spt.sword->attack == 1) {
        sword_animation(game->all_spt.sword, game->all_spt.player);
    } else {
        sfSprite_setColor(game->all_spt.sword->sprite,
        sfColor_fromRGBA(255, 255, 255, 0));
    }
}
