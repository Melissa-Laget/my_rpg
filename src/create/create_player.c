/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** create
*/

#include "draw.h"
#include "list.h"
#include <stdlib.h>

sfIntRect create_rect_player(player_t *player)
{
    player->rect.top = 0;
    player->rect.left = 0;
    player->rect.width = 48;
    player->rect.height = 48;
    return player->rect;
}

player_t *create_player(char *filepath, float pos_x, float pos_y)
{
    player_t *player = malloc(sizeof(player_t));

    player->direction = DOWN_STATIC;
    player->pos.x = pos_x;
    player->pos.y = pos_y;
    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile(filepath, NULL);
    player->rect = create_rect_player(player);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, ((sfVector2f){
    player->rect.width / 2, player->rect.height - 5
    }));
    player->clock = sfClock_create();
    player->hp = 10.0f;
    return player;
}
