/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** struct
*/

#include "hud.h"

static hud_button_t *hud_button_init_2(hud_button_t *button)
{
    button->toggleable = false;
    button->toggle = false;
    button->hover = false;
    button->text = NULL;
    button->font = NULL;
    button->key = -1;
    return button;
}

hud_button_t *hud_button_init(void)
{
    hud_button_t *button = malloc(sizeof(hud_button_t));

    if (button == NULL)
        return NULL;
    button->name = NULL;
    button->pos = ((sfIntRect){.left = 0, .top = 0,
    .width = 100, .height = 100});
    button->hidden = false;
    button->border = true;
    button->borderWidth = ((sfFloatRect){.left = 5, .top = 5,
    .width = 5, .height = 5});
    button->borderColor = sfBlack;
    button->color = sfWhite;
    button->action = NULL;
    button->texture = NULL;
    button->actionBorderColor = sfWhite;
    button->actionColor = sfWhite;
    return hud_button_init_2(button);
}
