/*
** EPITECH PROJECT, 2023
** my_put_rectangle.c
** File description:
** to put a rectangle
*/

#include "pixel.h"

int my_put_rectangle(framebuffer_t *buff, int size, int x, int y)
{
    int lim = size * 3;

    for (int i = x; i <= x + lim; i ++)
        for (int j = y; j <= y + size; j ++)
            my_put_pixel(buff, i, j, buff->col);
    sfTexture_updateFromPixels(buff->texture, buff->pixel, 1920, 1080, 0, 0);
    return 0;
}
