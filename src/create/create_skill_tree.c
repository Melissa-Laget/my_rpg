/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** skill_tree
*/

#include "event.h"

void create_skill_tree(game_t *game)
{
    game->skill_tree.strength = 0;
    game->skill_tree.defense = 0;
    game->skill_tree.unlock_magic = 0;
    game->skill_tree.fire_ball = 0;
    game->skill_tree.ice_ball = 0;
    game->skill_tree.poison_ball = 0;
}
