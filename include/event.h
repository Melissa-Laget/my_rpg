/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include "rpg.h"

void all_event(game_t *game);

void player_event(game_t *game);
void player_died(game_t *game);
void player_mouvement(game_t *game);
int player_no_mouvement(player_t *player);

void set_hud_player_hp(game_t *game, int hp);

void spell_event(game_t *game);
void spell_movement(attack_t *spell);
void move_spell(game_t *game);

int can_talk(game_t *game, player_t *npc);

/* huds */
void event_main_menu(game_t *game);
void event_inventory(game_t *game, sfEvent *event);
void event_pause(game_t *game);
void event_stats(game_t *game);
void event_skill(game_t *game);
void event_dead(game_t *game);

/* boss_fight */
void boss_deplacement(game_t *game);
void dead_old_man(game_t *game, boss_t *boss);
void old_man_knife(game_t *game, boss_t *boss);

bool check_collision(game_t *game, int x, int y);

#endif
