/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** create_all
*/

#include "draw.h"

void create_text(sfSprite **sprite, sfTexture **texture, char *filepath)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setColor(*sprite, sfColor_fromRGBA(255, 255, 255, 0));
    sfSprite_setPosition(*sprite, ((sfVector2f){0, 527}));
    sfSprite_setScale(*sprite, ((sfVector2f){1, 0.8}));
}

void create_rect_cutscene(game_t *game)
{
    game->all_spt.cutscene.rect.top = 0;
    game->all_spt.cutscene.rect.left = 0;
    game->all_spt.cutscene.rect.width = 710;
    game->all_spt.cutscene.rect.height = 400;
}

void create_cutscene(game_t *game, char *filepath)
{
    game->all_spt.cutscene.status_cutscene = 0;
    game->all_spt.cutscene.sprite = sfSprite_create();
    game->all_spt.cutscene.texture = sfTexture_createFromFile(filepath, NULL);
    create_rect_cutscene(game);
    sfSprite_setTexture(game->all_spt.cutscene.sprite,
    game->all_spt.cutscene.texture, sfTrue);
    sfSprite_setTextureRect(game->all_spt.cutscene.sprite,
    game->all_spt.cutscene.rect);
    game->all_spt.cutscene.clock = sfClock_create();
}

void create_all_sprite(game_t *game)
{
    game->all_spt.player = create_player("assets/character/toucan.png",
    240, 1020);
    game->all_spt.sword =
    create_sword("assets/weapon/evil_sword_lvl1.png", 96, 96);
    game->all_spt.knife = create_sword("assets/weapon/knife.png", 7, 24);
    sfSprite_setColor(game->all_spt.knife->sprite,
    sfColor_fromRGBA(255, 255, 255, 255));
    sfSprite_setScale(game->all_spt.knife->sprite, ((sfVector2f){2, 2}));
    game->all_spt.ice = create_ice_poison("assets/skill_tree/iceball.png");
    game->all_spt.poison = create_ice_poison("assets/skill_tree/poisball.png");
    game->all_spt.fire = create_fire("assets/skill_tree/fireball.png");
    game->all_spt.explosion = create_player("assets/boss/explosion.png", 0, 0);
    create_cutscene(game, "assets/background/cutscene.png");
    create_text(&game->all_spt.text, &game->all_spt.text_texture,
    "assets/ui/textbox.png");
    create_text(&game->all_spt.textbox, &game->all_spt.textbox_texture,
    "assets/ui/text_box.png");
}
