/*
** EPITECH PROJECT, 2023
** my_put_square.c
** File description:
** to put a square
*/

#include "pixel.h"

void square_print(framebuffer_t *buff, int size, int x, int y)
{
    for (int i = x; i <= x + size; i ++)
        for (int j = y; j <= y + size; j ++)
            my_put_pixel(buff, i, j, buff->col);
    sfTexture_updateFromPixels(buff->texture, buff->pixel, 1920, 1080, 0, 0);
    return;
}
