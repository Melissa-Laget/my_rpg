/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** main_menus_action
*/

#include "my.h"
#include "draw.h"
#include "event.h"
#include "free.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void launch_game(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = (game_t *)param;

    game->status = GAME_LOOP;
    sfMusic_stop(game->sound.village_music);
    launch_music(game->sound.village_music,
    game->sound.muted);
    sfView_setCenter(game->view, ((sfVector2f){
    game->all_spt.player->pos.x + game->all_spt.player->rect.width / 2,
    game->all_spt.player->pos.y + game->all_spt.player->rect.height / 2}));
    game->sound.died_b = false;
    game->sound.dead = 0;
    sfMusic_stop(game->sound.died_music);
}

void resume_game(hud_button_t *button __attribute__((unused)), void *param)
{
    ((game_t *)param)->status = GAME_LOOP;
}

void quit_settings(hud_button_t *button __attribute__((unused)), void *param)
{
    hud_view_get(((game_t *)param)->menus.main_menu, "settings_view"
    )->hidden = true;
    hud_button_get(((game_t *)param)->menus.main_menu, "settings"
    )->toggle = false;
}

void quit_game(hud_button_t *button __attribute__((unused)), void *param)
{
    ((game_t *)param)->status = EXIT_GAME;
    sfRenderWindow_close(((game_t*)param)->win);
}

void how_to_play(hud_button_t *button __attribute__((unused)), void *param)
{
    hud_view_t *main_menu_view = hud_view_get(
    ((game_t *)param)->menus.main_menu, "main_menu");

    if (!main_menu_view)
        return;
    if (main_menu_view->hidden == false) {
        main_menu_view->hidden = true;
        hud_view_get(
        ((game_t *)param)->menus.main_menu, "settings_view")->hidden = true;
        hud_button_get(
        ((game_t *)param)->menus.main_menu, "how_to_play")->hidden = false;
        return;
    }
    main_menu_view->hidden = false;
    hud_view_get(
    ((game_t *)param)->menus.main_menu, "settings_view")->hidden = true;
    hud_button_get(
    ((game_t *)param)->menus.main_menu, "how_to_play")->hidden = true;
}
