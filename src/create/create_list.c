/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** create_list
*/

#include "draw.h"
#include "list.h"
#include <stdlib.h>

list_t *villager_list(void)
{
    list_t *npc = NULL;

    npc = list_append(npc, create_player("assets/character/orc.png", 182, 962));
    npc = list_append(npc, create_player("assets/character/smt.png", 413, 822));
    npc = list_append(npc, create_player("assets/character/knt.png", 792, 496));
    npc = list_append(npc, create_player("assets/character/pnj.png", 1033,
    105));
    return npc;
}

list_t *boss_list(void)
{
    list_t *bosses = NULL;
    char *morshu_textures[] = {
        "assets/boss/morshu_walk.png",
        "assets/boss/morshu_throw.png",
        "assets/boss/morshu_phase.png",
        "assets/boss/morshu_dead.png",
    };
    sfVector2i morshu_size[] = {
        ((sfVector2i){57, 79}),
        ((sfVector2i){72, 82}),
        ((sfVector2i){58, 72}),
        ((sfVector2i){78, 72}),
    };
    char *man_textures[] = {"assets/boss/old_man.png"};
    sfVector2i man_size[] = {((sfVector2i){16, 23})};
    bosses = list_append(bosses, create_bosses(morshu_textures, 4, morshu_size,
    ((sfVector2f){50, 50})));
    list_append(bosses, create_bosses(man_textures, 1, man_size,
    ((sfVector2f){1800, 750})));
    return bosses;
}
