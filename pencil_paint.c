/*
** EPITECH PROJECT, 2023
** pencil_paint.c
** File description:
** pencil-paint function
*/

#include "pixel.h"

int pencil_paint(framebuffer_t *b, mouse_t *m, sfRenderWindow *w, sfEvent *evt)
{
    b->col = m->color;
    square_print(b, 5, evt->mouseButton.x, evt->mouseButton.y);
    sfTexture_updateFromPixels(b->texture, b->pixel, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(w, b->sprite, NULL);
    sfRenderWindow_display(w);
    return 0;
}
