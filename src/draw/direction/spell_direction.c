/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** spell_direction
*/

#include "draw.h"

void vertical_direction(attack_t *spell, int direction, sfVector2f pos)
{
    if (direction == UP_WALK || direction == UP_STATIC) {
        spell->attack_direction = UP_ATK;
        sfSprite_setRotation(spell->sprite, 270);
        spell->pos = ((sfVector2f){pos.x - 16, pos.y - 24});
        sfSprite_setPosition(spell->sprite, spell->pos);
    }
    if (direction == DOWN_WALK || direction == DOWN_STATIC) {
        spell->attack_direction = DOWN_ATK;
        sfSprite_setRotation(spell->sprite, 90);
        spell->pos = ((sfVector2f){pos.x + 16, pos.y - 25});
        sfSprite_setPosition(spell->sprite, spell->pos);
    }
}

void spell_direction(attack_t *spell, int direction, sfVector2f pos)
{
    vertical_direction(spell, direction, pos);
    if (direction == LEFT_WALK || direction == LEFT_STATIC) {
        spell->attack_direction = LEFT_ATK;
        sfSprite_setRotation(spell->sprite, 180);
        spell->pos = ((sfVector2f){pos.x, pos.y});
        sfSprite_setPosition(spell->sprite, spell->pos);
    }
    if (direction == RIGHT_WALK || direction == RIGHT_STATIC) {
        spell->attack_direction = RIGHT_ATK;
        sfSprite_setRotation(spell->sprite, 0);
        spell->pos = ((sfVector2f){pos.x, pos.y - 24});
        sfSprite_setPosition(spell->sprite, spell->pos);
    }
}

void spell_movement(attack_t *spell)
{
    if (spell->attack_direction == RIGHT_ATK) {
        spell->pos.x += 5;
    }
    if (spell->attack_direction == LEFT_ATK) {
        spell->pos.x -= 5;
    }
    if (spell->attack_direction == UP_ATK) {
        spell->pos.y -= 5;
    }
    if (spell->attack_direction == DOWN_ATK) {
        spell->pos.y += 5;
    }
    sfSprite_setPosition(spell->sprite, spell->pos);
    sfClock_restart(spell->anim_clock);
}

void move_spell(game_t *game)
{
    if (game->all_spt.fire->attack == 1)
        spell_movement(game->all_spt.fire);
    if (game->all_spt.ice->attack == 1)
        spell_movement(game->all_spt.ice);
    if (game->all_spt.poison->attack == 1)
        spell_movement(game->all_spt.poison);
}
