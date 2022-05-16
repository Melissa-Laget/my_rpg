/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** spell_event
*/

#include "draw.h"
#include "event.h"

void launch_spell(int key, int direction, attack_t *spell)
{
    if (sfKeyboard_isKeyPressed(key)
        && direction < DOWN_WALK && spell->attack != 1 && spell->status == 0) {
        sfClock_restart(spell->clock);
        spell->attack = 1;
        spell->status = 0;
    }
}

void spell_event(game_t *game)
{
    int nb_spells = 3;
    int spell_keys[] = {sfKeyNum1, sfKeyNum2, sfKeyNum3};
    attack_t *spells[] = {game->all_spt.fire, game->all_spt.ice,
    game->all_spt.poison};
    int *status[] = {&game->skill_tree.fire_ball, &game->skill_tree.ice_ball,
    &game->skill_tree.poison_ball};

    for (int i = 0; i < nb_spells; i++) {
        if (*status[i] == 0)
            continue;
        launch_spell(spell_keys[i], game->all_spt.player->direction,
        spells[i]);
    }
}
