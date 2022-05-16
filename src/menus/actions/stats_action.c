/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** pause_action
*/

#include "draw.h"
#include "actions.h"

void launch_stats(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);

    game->status = STATS_MENU;
    sfText_setString(game->stat_text.text_strenght,
    nbr_to_str(game->skill_tree.strength));
    sfText_setString(game->stat_text.text_defense,
    nbr_to_str(game->skill_tree.defense));
    sfText_setString(game->stat_text.text_magic,
    nbr_to_str(game->skill_tree.unlock_magic));
    sfText_setString(game->stat_text.text_health,
    nbr_to_str(((int)game->all_spt.player->hp)));
    sfText_setString(game->stat_text.text_fire,
    nbr_to_str(((int)game->skill_tree.fire_ball)));
    sfText_setString(game->stat_text.text_ice,
    nbr_to_str(((int)game->skill_tree.ice_ball)));
    sfText_setString(game->stat_text.text_poison,
    nbr_to_str(((int)game->skill_tree.poison_ball)));
}
