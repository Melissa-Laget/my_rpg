/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** rpg
*/

#include "my.h"
#include "draw.h"
#include "event.h"
#include "free.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static const void (*render_funcs[])(game_t *) = {
    NULL,
    &draw_main_menu,
    &draw_all,
    &draw_pause,
    &draw_stats,
    &draw_skill,
    &draw_dead,
    NULL
};

static const void (*event_funcs[])(game_t *) = {
    NULL,
    &event_main_menu,
    &all_event,
    &event_pause,
    &event_stats,
    &event_skill,
    &event_dead,
    NULL
};

static const void (*poll_event_funcs[])(game_t *, sfEvent *) = {
    NULL,
    NULL,
    &event_inventory,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

void window_close_event(game_t *game, sfEvent *event)
{
    if (game->status > 0 && (event->type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyW))) {
        sfRenderWindow_close(game->win);
    }
}

void loop_switch(game_t *game, sfEvent *evt)
{
    if (game->status > 0 &&
        sfRenderWindow_pollEvent(game->win, evt)) {
        if (poll_event_funcs[game->status] != NULL)
            poll_event_funcs[game->status](game, evt);
        window_close_event(game, evt);
    }
    if (game->status > 0 &&
        sfClock_getElapsedTime(game->event_clock).microseconds > 10000) {
        if (event_funcs[game->status] != NULL)
            event_funcs[game->status](game);
        sfClock_restart(game->event_clock);
    }
    if (game->status > 0 && render_funcs[game->status] != NULL && true) {
        sfRenderWindow_clear(game->win, sfBlack);
        render_funcs[game->status](game);
    }
}

int rpg(void)
{
    game_t *game = NULL;
    sfEvent event;

    if ((game = init_game()) == NULL)
        return 84;
    while (game->status > 0 && sfRenderWindow_isOpen(game->win)) {
        sfRenderWindow_display(game->win);
        if (game->all_spt.cutscene.status_cutscene <= 1) {
            if (sfRenderWindow_pollEvent(game->win, &event))
                window_close_event(game, &event);
            cutscene(game);
            continue;
        }
        loop_switch(game, &event);
        sfSprite_setColor(game->all_spt.player->sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
    }
    free_all(game->all_spt.player, game);
    return 0;
}
