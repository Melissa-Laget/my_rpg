/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** create_sound
*/

#include "rpg.h"

sfMusic *create_music(char *soundpath)
{
    sfMusic *music;

    music = sfMusic_createFromFile(soundpath);
    return music;
}

void launch_music(sfMusic *music, bool muted)
{
    if (muted)
        return;
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}

void create_game_music(game_t *game)
{
    game->sound.dead = 0;
    game->sound.muted = false;
    game->sound.died_b = false;
    game->sound.village_b = false;
    game->sound.morshu_f_b = false;
    game->sound.old_man_f_b = false;
    game->sound.morshu_music = create_music("assets/audio/morshu_sound.ogg");
    game->sound.died_music = create_music("assets/audio/died_sound.ogg");
    game->sound.village_music = create_music("assets/audio/village.ogg");
    game->sound.morshu_fight = create_music("assets/audio/morshu_fight.ogg");
    game->sound.old_man_fight = create_music("assets/audio/old_man_fight.ogg");
}
