/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** actions
*/

#ifndef ACTIONS_H_
    #define ACTIONS_H_

    #include "hud.h"

hud_button_t **selected_slot(void);
int *resolution_status(void);

bool append_to_inventory(game_t *game, int item);
bool del_from_inventory(game_t *game, int item);

void launch_game(hud_button_t *button __attribute__((unused)), void *param);
void resume_game(hud_button_t *button __attribute__((unused)), void *param);
void launch_settings(hud_button_t *button __attribute__((unused)), void *param);
void quit_settings(hud_button_t *button __attribute__((unused)), void *param);
void quit_game(hud_button_t *button __attribute__((unused)), void *param);
void toggle_inventory(hud_button_t *button __attribute__((unused)),
void *param);
void inventory_slot_action(hud_button_t *button , void *param);
void resolution_setting(hud_button_t *button __attribute__((unused)),
void *param);
void sound_setting(hud_button_t *button __attribute__((unused)),
void *param);
void how_to_play(hud_button_t *button __attribute__((unused)), void *param);
void launch_menu(hud_button_t *button __attribute__((unused)), void *param);
void launch_pause(hud_button_t *button __attribute__((unused)), void *param);
void launch_stats(hud_button_t *button __attribute__((unused)), void *param);
void launch_skill(hud_button_t *button __attribute__((unused)), void *param);
void upgrade_strength(hud_button_t *button __attribute__((unused)),
void *param);
void upgrade_defense(hud_button_t *button __attribute__((unused)), void *param);
void unlock_magic(hud_button_t *button __attribute__((unused)), void *param);
void unlock_fire(hud_button_t *button __attribute__((unused)), void *param);
void unlock_ice(hud_button_t *button __attribute__((unused)), void *param);
void unlock_poison(hud_button_t *button __attribute__((unused)), void *param);

#endif
