/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** draw
*/

#include "hud.h"

static void hud_view_render_border(sfRenderWindow *win, hud_view_t *view,
sfVector2f view_pos)
{
    sfColor color = view->borderColor;
    hud_draw_rect(win, ((sfFloatRect){.left = view->pos.left,
    .top = view->pos.top, .width = view->pos.width,
    .height = view->pos.height}), color, view_pos);
}

void hud_view_render_texture(sfRenderWindow *win, hud_view_t *view,
sfVector2f view_pos)
{
    sfVertexArray *rect = NULL;
    sfRenderStates states;

    if (view->texture == NULL)
        return;
    rect = hud_create_rect(((sfFloatRect){.left = view->pos.left,
    .top = view->pos.top, .width = view->pos.width,
    .height = view->pos.height}), sfWhite, view_pos, view->texture);
    states.shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = view->texture;
    sfRenderWindow_drawVertexArray(win, rect, &states);
    sfVertexArray_destroy(rect);
}

void hud_view_render(sfRenderWindow *win, hud_view_t *view,
sfVector2f view_pos)
{
    if (view->hidden == true)
        return;
    if (view->border == true) {
        hud_view_render_border(win, view, view_pos);
        hud_draw_rect(win, ((sfFloatRect){.left = view->pos.left +
        view->borderWidth.left, .top = view->pos.top +
        view->borderWidth.top, .width = (view->pos.width -
        view->borderWidth.left) - view->borderWidth.width,
        .height = (view->pos.height - view->borderWidth.top) -
        view->borderWidth.height}), view->color, view_pos);
        return;
    }
    hud_draw_rect(win, ((sfFloatRect){.left = view->pos.left,
    .top = view->pos.top, .width = view->pos.width,
    .height = view->pos.height}), view->color, view_pos);
    hud_view_render_texture(win, view, view_pos);
}
