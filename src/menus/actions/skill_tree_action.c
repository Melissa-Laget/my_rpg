/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** skill_tree_action
*/

#include "my.h"
#include "draw.h"
#include "event.h"
#include "free.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

void launch_skill(hud_button_t *button __attribute__((unused)), void *param)
{
    game_t *game = ((game_t *)param);
    game->status = SKILL_TREE;
}
