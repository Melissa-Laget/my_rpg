/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** player_died
*/

#include "rpg.h"
#include "actions.h"

void player_died(game_t *game)
{
    bool muted = false;

    if (game->all_spt.player->hp <= 0 && game->sound.dead == 0) {
        game->status = DEAD_MENU;
        game->all_spt.player->pos = ((sfVector2f){240, 1020});
        game->all_spt.player->hp = 10.1f;
        muted = game->sound.muted;
        sound_setting(NULL, game);
        if (muted == false)
            sfMusic_play(game->sound.died_music);
        game->sound.muted = muted;
        game->sound.died_b = true;
        game->sound.dead = 1;
    }
}
