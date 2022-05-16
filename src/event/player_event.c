/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** player_event
*/

#include "draw.h"
#include "event.h"

void player_mouvement(game_t *game)
{
    sfVector2f pos = game->all_spt.player->pos;

    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        pos.x += 2;
        game->all_spt.player->direction = RIGHT_WALK;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        pos.x -= 2;
        game->all_spt.player->direction = LEFT_WALK;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        pos.y -= 2;
        game->all_spt.player->direction = UP_WALK;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        pos.y += 2;
        game->all_spt.player->direction = DOWN_WALK;
    }
    if (check_collision(game, pos.x, pos.y) == true)
        game->all_spt.player->pos = pos;
}

int player_no_mouvement(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyZ) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyS) == sfFalse) {
        if (player->direction > UP_STATIC) {
            player->direction -= 4;
        }
        return 1;
    }
    return 0;
}

void trigger_boss(game_t *game)
{
    list_t *tmp = game->boss;

    if (game->all_spt.player->pos.x >= 192 && game->all_spt.player->pos.x <=
        224 && game->all_spt.player->pos.y <= 441 &&
        game->all_spt.player->pos.y >= 416) {
        sfMusic_stop(game->sound.village_music);
        game->sound.village_b = false;
        ((boss_t *)tmp->data)->is_trigger = 1;
        launch_music(game->sound.morshu_fight, game->sound.muted);
        game->sound.morshu_f_b = true;
    }
    if (game->all_spt.player->pos.x >= 1142 && game->all_spt.player->pos.x <=
        1168 && game->all_spt.player->pos.y <= 783 &&
        game->all_spt.player->pos.y >= 752) {
        sfMusic_stop(game->sound.village_music);
        game->sound.village_b = false;
        ((boss_t *)tmp->next->data)->is_trigger = 1;
        launch_music(game->sound.old_man_fight, game->sound.muted);
        game->sound.old_man_f_b = true;
    }
}

void trigger_music(game_t *game)
{
    if (game->all_spt.player->pos.x <= 1141 && game->all_spt.player->pos.x >=
        1120 && game->all_spt.player->pos.y <= 783 &&
        game->all_spt.player->pos.y >= 752) {
        sfMusic_stop(game->sound.old_man_fight);
        game->sound.old_man_f_b = false;
        launch_music(game->sound.village_music, game->sound.muted);
        game->sound.village_b = true;
    }
    if (game->all_spt.player->pos.x >= 192 && game->all_spt.player->pos.x <=
        224 && game->all_spt.player->pos.y <= 462 &&
        game->all_spt.player->pos.y >= 442) {
        sfMusic_stop(game->sound.morshu_fight);
        game->sound.morshu_f_b = false;
        launch_music(game->sound.village_music, game->sound.muted);
        game->sound.village_b = true;
    }
}

void player_event(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)
        && game->all_spt.player->direction < DOWN_WALK)
        game->all_spt.sword->attack = 1;
    spell_event(game);
    player_died(game);
    trigger_boss(game);
    trigger_music(game);
    set_hud_player_hp(game, game->all_spt.player->hp);
}
