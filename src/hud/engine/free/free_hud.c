/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** free_hud
*/

#include "hud.h"

void free_button(hud_button_t *button)
{
    free(button->name);
    if (button->texture)
        sfTexture_destroy(button->texture);
    if (button->text)
        sfText_destroy(button->text);
    if (button->font)
        sfFont_destroy(button->font);
}

void free_view(hud_view_t *view)
{
    free(view->name);
    if (view->texture)
        sfTexture_destroy(view->texture);
    list_free(view->views, false);
    list_free(view->buttons, false);
}

void free_hud(hud_t *hud)
{
    list_free(hud->views, false);
    list_free(hud->buttons, false);
    for (list_t *tmp = hud->actions; tmp; tmp = tmp->next)
        free(((hud_action_t *)tmp->data)->name);
    list_free(hud->actions, true);
    sfClock_destroy(hud->clock);
    for (list_t *tmp = hud->buttons; tmp; tmp = tmp->next)
        free_button(tmp->data);
    list_free(hud->all_buttons, true);
    for (list_t *tmp = hud->views; tmp; tmp = tmp->next)
        free_view(tmp->data);
    list_free(hud->all_views, true);
    free(hud);
}
