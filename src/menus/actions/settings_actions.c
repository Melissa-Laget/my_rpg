/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** settings_actions
*/

#include "draw.h"
#include "actions.h"

static const sfVector2u res[] = {
    {800, 600},
    {1280, 720},
    {1920, 1080}
};

static const char *res_str[] = {
    "800",
    "720",
    "1080",
    NULL
};

void launch_settings(hud_button_t *button, void *param)
{
    hud_view_get(((game_t *)param)->menus.main_menu, "settings_view"
    )->hidden = false;
    button->toggle = true;
}

void resolution_setting(hud_button_t *button,
void *param)
{
    game_t *game = (game_t *)param;
    int select = 0;

    for (; my_strcmp(button->name, res_str[select]) != 0; select++);
    sfRenderWindow_setSize(game->win, res[select]);
    game->mode.width = res[select].x;
    game->mode.height = res[select].y;
}

void sound_setting(hud_button_t *button __attribute__((unused)),
void *param)
{
    game_t *game = (game_t *)param;
    void (*func_arr[])(sfMusic *) = {
        &sfMusic_pause, &sfMusic_play
    };
    game->sound.muted = !(game->sound.muted);
    if (game->sound.muted) {
        sfMusic_pause(game->sound.morshu_music);
        sfMusic_pause(game->sound.died_music);
        sfMusic_pause(game->sound.village_music);
        sfMusic_pause(game->sound.morshu_fight);
        sfMusic_pause(game->sound.old_man_fight);
        return;
    }
    func_arr[game->sound.died_b](game->sound.died_music);
    func_arr[game->sound.village_b](game->sound.village_music);
    func_arr[game->sound.morshu_f_b](game->sound.morshu_fight);
    func_arr[game->sound.old_man_f_b](game->sound.old_man_fight);
}
