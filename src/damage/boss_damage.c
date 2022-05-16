/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** player_damage
*/

#include "draw.h"

int damage_sword_player(game_t *game)
{
    sfFloatRect rect1 =
    sfSprite_getGlobalBounds(game->all_spt.player->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(game->all_spt.knife->sprite);

    if (((boss_t *)game->boss->next->data)->hp > 0 &&
        sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue) {
        sfSprite_setColor(game->all_spt.player->sprite,
        sfColor_fromRGBA(150, 0, 0, 255));
        game->all_spt.player->hp -= game->all_spt.player->hp;
        return 1;
    }
    return 0;
}

int damage_player(game_t *game, boss_t *boss)
{
    sfFloatRect rect1 =
    sfSprite_getGlobalBounds(game->all_spt.player->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(boss->sprite);

    if (boss->hp > 0 &&
        sfFloatRect_intersects(&rect1, &rect2, NULL) == sfTrue) {
        sfSprite_setColor(game->all_spt.player->sprite,
        sfColor_fromRGBA(150, 0, 0, 255));
        game->all_spt.player->hp -= (0.025 * (-game->skill_tree.defense +
        (game->skill_tree.defense == 0)));
        if ((sfMusic_getStatus(game->sound.morshu_music) != sfPlaying ||
            sfMusic_getPlayingOffset(game->sound.morshu_music
            ).microseconds > 500000) && game->sound.muted == false)
            sfMusic_play(game->sound.morshu_music);
        return 1;
    } else
        sfMusic_stop(game->sound.morshu_music);
    return 0;
}
