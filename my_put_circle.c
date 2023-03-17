/*
** EPITECH PROJECT, 2023
** my_put_circle.c
** File description:
** my_put_circle.c
*/

#include "pixel.h"
#include <math.h>

int my_put_circle(framebuffer_t *framebuffer, int width, int height, sfColor c)
{
    int radius = 20;
    int startx = width;
    int starty = height;
    int distance = 0;

    for (int i = startx - radius; i <= startx + radius; i ++)
        for (int j = starty - radius; j <= starty + radius; j ++) {
            distance = sqrt((i - startx) * (i - startx) + (j - starty) * (j - starty));
            if (distance <= radius)
                my_put_pixel(framebuffer, i, j, c);
        }
    return 0;
}
