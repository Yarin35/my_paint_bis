/*
** EPITECH PROJECT, 2023
** pencil_paint.c
** File description:
** pencil-paint function
*/

#include "pixel.h"

int pencil_paint(framebuffer_t *buff, mouse_t *m, sfRenderWindow *window, sfEvent *event)
{
    square_print(buff, 5, event->mouseButton.x, event->mouseButton.y, m->color);
    sfTexture_updateFromPixels(buff->texture, buff->pixel, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(window, buff->sprite, NULL);
    sfRenderWindow_display(window);
    return 0;
}
