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
        for (int y = y; y <= y + size; y ++)
            my_put_pixel(buff, i, y, buff->col);
    return;
}
