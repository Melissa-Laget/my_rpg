/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** game
*/

#include "rpg.h"
#include "draw.h"
#include "event.h"

void init_all(game_t *game)
{
    create_game_music(game);
    game->talk_text = sfText_create();
    create_all_sprite(game);
    game->draw_clock = sfClock_create();
    game->event_clock = sfClock_create();
    game->text_clock = sfClock_create();
    create_skill_tree(game);
    game->damage_clock = sfClock_create();
    game->font = sfFont_createFromFile("assets/font/Optimus.ttf");
    launch_music(game->sound.village_music, game->sound.muted);
    game->sound.village_b = true;
    init_map(game);
    init_hud_value();
}

int init_entities(game_t *game)
{
    if ((game->boss = boss_list()) == NULL)
        return -1;
    if ((game->npc = villager_list()) == NULL)
        return -2;
    if (create_particles(game) < 0)
        return -3;
    text_list(game->npc);
    ((boss_t *)game->boss->next->data)->hp = 1.0f;
    sfView_setCenter(game->view, ((sfVector2f){
    game->all_spt.player->pos.x + game->all_spt.player->rect.width / 2,
    game->all_spt.player->pos.y + game->all_spt.player->rect.height / 2}));
    return 0;
}

static void init_npc(game_t *game)
{
    game->npc_death.dead_orc = 0;
    game->npc_death.log = 0;
    game->npc_death.dead_villager = 0;
    game->npc_death.dead_guard = 0;
    game->npc_death.dead_lumberjack = 0;
    game->npc_death.dead_morshu = 0;
    game->npc_death.dead_old_man = 0;
    game->npc_death.talked_orc = 0;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->mode = ((sfVideoMode){1280, 720, 32});
    game->win = sfRenderWindow_create(game->mode, "RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->win, 240);
    game->view = sfView_createFromRect(((sfFloatRect){0, 0, 650, 400}));
    game->win_view = sfView_createFromRect(((sfFloatRect){0, 0, 800, 600}));
    sfRenderWindow_setView(game->win, game->view);
    if (game == NULL)
        return NULL;
    init_all(game);
    if (game->font == NULL)
        return NULL;
    if (init_huds(game) != 0)
        return NULL;
    game->status = MAIN_MENU;
    if (init_entities(game) < 0)
        return NULL;
    init_npc(game);
    return game;
}
