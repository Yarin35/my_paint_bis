/*
** EPITECH PROJECT, 2023
** my_put_square.c
** File description:
** to put a square
*/

#include "pixel.h"

void my_put_square(framebuffer_t *framebuffer, index_t *i)
{
    for (int k = i->i; k <= i->i + i->size; k ++)
        for (int y = i->j; y <= i->j + i->size; y ++)
            my_put_pixel(framebuffer, y, k, i->color);
    return;
}
