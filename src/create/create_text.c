/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** create_text
*/

#include "draw.h"

static const int nb_dialogs[] = {2, 2, 2, 2, -1};

static char ***dialogs_array(void)
{
    char ***dialogs = malloc(sizeof(char **) * 5);

    dialogs[0] = malloc(sizeof(char *) * 3);
    dialogs[0][0] = ((char *){"Talk to the orc"});
    dialogs[0][1] = ((char *){"\tThere is some lumberjack in the woods\n\
    you must kill them and take their wood log"});
    dialogs[0][2] = ((char *){"Would you like to convert your logs into xp?"});
    dialogs[1] = malloc(sizeof(char *) * 2);
    dialogs[1][0] = ((char *){"Talk to the lumberjack",});
    dialogs[1][1] = ((char *){"I'm a nice lumberjack, please don't kill me\n"});
    dialogs[2] = malloc(sizeof(char *) * 2);
    dialogs[2][0] = ((char *){"Talk to the guard"});
    dialogs[2][1] = ((char *){"Be nice to all vilagers, I'm the Kanoe"});
    dialogs[3] = malloc(sizeof(char *) * 2);
    dialogs[3][0] = ((char *){"Talk to the villager"});
    dialogs[3][1] = ((char *){"Hello, it's nice to meet you, I'm Kayak!"});
    dialogs[4] = NULL;
    return dialogs;
}

static sfVector2f **positions_array(void)
{
    sfVector2f **positions = malloc(sizeof(sfVector2f *) * 5);

    positions[0] = malloc(sizeof(sfVector2f) * 2);
    positions[0][0] = ((sfVector2f){270, 545});
    positions[0][1] = ((sfVector2f){270, 545});
    positions[1] = malloc(sizeof(sfVector2f) * 3);
    positions[1][0] = ((sfVector2f){270, 545});
    positions[1][1] = ((sfVector2f){270, 545});
    positions[1][2] = ((sfVector2f){260, 545});
    positions[2] = malloc(sizeof(sfVector2f) * 2);
    positions[2][0] = ((sfVector2f){270, 545});
    positions[2][1] = ((sfVector2f){270, 545});
    positions[3] = malloc(sizeof(sfVector2f) * 2);
    positions[3][0] = ((sfVector2f){270, 545});
    positions[3][1] = ((sfVector2f){270, 545});
    positions[4] = NULL;
    return positions;
}

static int **text_size_array(void)
{
    int **text_size = malloc(sizeof(int *) * 5);

    text_size[0] = malloc(sizeof(int) * 2);
    text_size[0][0] = 28;
    text_size[0][1] = 20;
    text_size[1] = malloc(sizeof(int) * 3);
    text_size[1][0] = 28;
    text_size[1][1] = 28;
    text_size[1][2] = 25;
    text_size[2] = malloc(sizeof(int) * 2);
    text_size[2][0] = 28;
    text_size[2][1] = 28;
    text_size[3] = malloc(sizeof(int) * 2);
    text_size[3][0] = 28;
    text_size[3][1] = 28;
    text_size[4] = NULL;
    return text_size;
}

void text_list(list_t *npc)
{
    int i = 0;
    sfVector2f **positions = positions_array();
    char ***dialogs = dialogs_array();
    int **text_size = text_size_array();

    for (list_t *tmp = npc; tmp != NULL; tmp = tmp->next, i++) {
        ((player_t *)tmp->data)->text = malloc(sizeof(text_t));
        ((player_t *)tmp->data)->text->dialog = dialogs[i];
        ((player_t *)tmp->data)->text->pos = positions[i];
        ((player_t *)tmp->data)->text->nb_dialogs = nb_dialogs[i];
        ((player_t *)tmp->data)->text->skippable = false;
        ((player_t *)tmp->data)->text->status = 0;
        ((player_t *)tmp->data)->text->text_size = text_size[i];
        ((player_t *)tmp->data)->text->clock = sfClock_create();
    }
}
