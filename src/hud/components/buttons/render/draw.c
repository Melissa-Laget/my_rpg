/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** draw
*/

#include "hud.h"

static void hud_button_render_border(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos)
{
    sfColor color;

    if ((button->toggle == true) ^ (button->hover == true)) {
        color = button->actionBorderColor;
    } else
        color = button->borderColor;
    hud_draw_rect(win, ((sfFloatRect){.left = button->pos.left,
    .top = button->pos.top, .width = button->pos.width,
    .height = button->pos.height}), color, view_pos);
}

void hud_button_render_texture(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos, sfColor color)
{
    sfVertexArray *rect = NULL;
    sfRenderStates states;

    if (button->texture == NULL)
        return;
    rect = hud_create_rect(((sfFloatRect){.left = button->pos.left,
    .top = button->pos.top, .width = button->pos.width,
    .height = button->pos.height}), color, view_pos, button->texture);
    states.shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = button->texture;
    sfRenderWindow_drawVertexArray(win, rect, &states);
    sfVertexArray_destroy(rect);
}

static sfColor hud_button_get_color(hud_button_t *button)
{
    static sfColor color;

    if ((button->toggle == true) ^ (button->hover == true)) {
        color = button->actionColor;
    } else
        color = button->color;
    return color;
}

void hud_button_render_text(sfRenderWindow *win, hud_button_t *button,
sfFloatRect pos, sfVector2f view_pos)
{
    sfFloatRect size;

    if (button->text == NULL)
        return;
    size = sfText_getLocalBounds(button->text);
    sfText_setOrigin(button->text, ((sfVector2f){
    size.left + (size.width / 2), size.top + (size.height / 2)}));
    sfText_setPosition(button->text, ((sfVector2f){
    pos.left + (pos.width / 2) + view_pos.x,
    pos.top + (pos.height / 2) + view_pos.y}));
    sfRenderWindow_drawText(win, button->text, NULL);
}

void hud_button_render(sfRenderWindow *win, hud_button_t *button,
sfVector2f view_pos)
{
    sfColor color = hud_button_get_color(button);
    sfFloatRect pos;

    if (button->hidden == true)
        return;
    if (button->border == true) {
        pos = ((sfFloatRect){.left = button->pos.left +
        button->borderWidth.left, .top = button->pos.top +
        button->borderWidth.top, .width = (button->pos.width -
        button->borderWidth.left) - button->borderWidth.width,
        .height = (button->pos.height - button->borderWidth.top) -
        button->borderWidth.height});
        hud_button_render_border(win, button, view_pos);
    } else
        pos = ((sfFloatRect){.left = button->pos.left, .top = button->pos.top,
        .width = button->pos.width, .height = button->pos.height});
    if (button->texture == NULL)
        hud_draw_rect(win, pos, color, view_pos);
    hud_button_render_texture(win, button, view_pos, color);
    hud_button_render_text(win, button, pos, view_pos);
}
