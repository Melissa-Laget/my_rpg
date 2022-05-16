/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** text_anim
*/

#include "draw.h"
#include "my.h"
#include <stdio.h>

void player_text(game_t *game, const char *str, sfVector2f pos, int text_size)
{
    char *text = NULL;

    if (sfClock_getElapsedTime(game->text_clock).microseconds > 100000) {
        if (game->text_size < my_strlen(str)) {
            game->text_size++;
        }
        sfClock_restart(game->text_clock);
    }
    text = my_strndup(str, game->text_size);
    sfText_setString(game->talk_text, (text != NULL) ? text : str);
    free(text);
    sfText_setFont(game->talk_text, game->font);
    sfText_setPosition(game->talk_text, ((sfVector2f){pos.x, pos.y}));
    sfText_setColor(game->talk_text, sfColor_fromRGBA(255, 255, 255, 255));
    sfText_setCharacterSize(game->talk_text, text_size);
    sfRenderWindow_drawText(game->win, game->talk_text, NULL);
}

void which_text(game_t *game, text_t *text)
{
    sfSprite *box = ((game->can_talk) ?
    game->all_spt.text : game->all_spt.textbox);

    sfSprite_setColor(game->all_spt.text,
    sfColor_fromRGBA(255, 255, 255, 255));
    sfRenderWindow_setView(game->win, game->win_view);
    sfRenderWindow_drawSprite(game->win, box, NULL);
    player_text(game, text->dialog[text->status], text->pos[text->status],
    text->text_size[text->status]);
    game->can_talk = 1;
    sfRenderWindow_setView(game->win, game->view);
}
