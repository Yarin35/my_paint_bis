/*
** EPITECH PROJECT, 2023
** my_put_square.c
** File description:
** to put a square
*/

#include "pixel.h"

void square_print(framebuffer_t *framebuffer, unsigned int size, unsigned int
                   startx, unsigned int starty, sfColor color)
{
    for (int i = startx; i <= startx + size; i ++)
        for (int y = starty; y <= starty + size; y ++)
            my_put_pixel(framebuffer, i, y, color);
    return;
}
