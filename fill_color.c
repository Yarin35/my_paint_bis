/*
** EPITECH PROJECT, 2023
** fill_color.c
** File description:
** to fill with a color
*/

#include "pixel.h"

static void recursive_check(framebuffer_t *buff, int x, int y, sfColor color)
{
    while (x <= 1920 && y <= 1080) {
        if (buff->pixel[(1920 * x + (y + 1)) * 4] == color.r &&
            buff->pixel[(1920 * x + (y + 1)) * 4 + 1] == color.g &&
            buff->pixel[(1920 * x + (y + 1)) * 4 + 2] == color.b &&
            buff->pixel[(1920 * x + (y + 1)) * 4 + 3] == color.a)
            my_put_pixel(buff, x, y ++, color);
        if (buff->pixel[(1920 * x + (y - 1)) * 4] == color.r &&
            buff->pixel[(1920 * x + (y - 1)) * 4 + 1] == color.g &&
            buff->pixel[(1920 * x + (y - 1)) * 4 + 2] == color.b &&
            buff->pixel[(1920 * x + (y - 1)) * 4 + 3] == color.a)
            my_put_pixel(buff, x, y --, color);
        if (buff->pixel[(1920 * (x + 1) + y) * 4] == color.r &&
            buff->pixel[(1920 * (x + 1) + y) * 4 + 1] == color.g &&
            buff->pixel[(1920 * (x + 1) + y) * 4 + 2] == color.b &&
            buff->pixel[(1920 * (x + 1) + y) * 4 + 3] == color.a)
            my_put_pixel(buff, x ++, y, color);
        if (buff->pixel[(1920 * (x - 1) + y) * 4] == color.r &&
            buff->pixel[(1920 * (x - 1) + y) * 4 + 1] == color.g &&
            buff->pixel[(1920 * (x - 1) + y) * 4 + 2] == color.b &&
            buff->pixel[(1920 * (x - 1) + y) * 4 + 3] == color.a)
            my_put_pixel(buff, x --, y, color);
    }
}
int fill_color(framebuffer_t *buff, sfRenderWindow *w, sfEvent *e, mouse_t *m)
{
    sfUint8 co = (1920 * e->mouseButton.x + e->mouseButton.y) * 4;

    while (is_same_color(co, buff, e->mouseButton.x + 1, e->mouseButton.y) ||
        is_same_color(co, buff, e->mouseButton.x - 1, e->mouseButton.y) ||
        is_same_color(co, buff, e->mouseButton.x, e->mouseButton.y + 1) ||
        is_same_color(co, buff, e->mouseButton.x, e->mouseButton.y - 1))
        recursive_check(buff, e->mouseButton.x, e->mouseButton.y, m->color);
    sfTexture_updateFromPixels(buff->texture, buff->pixel, 1920, 1080, 0, 0);
    return 0;
}
