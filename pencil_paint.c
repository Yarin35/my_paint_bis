/*
** EPITECH PROJECT, 2023
** pencil_paint.c
** File description:
** pencil-paint function
*/

#include "pixel.h"

int pencil_paint(framebuffer_t *buff, mouse_t *m, general_t *all)
{
    square_print(buff, 5, WIN->event->mouseButon.x, WIN->event->mouseButton.y, m->c);
    sfTexture_updateFromPixels(buff->texture, buff->pixel, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(WIN, buff->sprite, NULL);
    sfRenderWindow_display(WIN);
    return 0;
}
