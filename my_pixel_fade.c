/*
** EPITECH PROJECT, 2023
** my_pixel_fade.c
** File description:
** my_pixel_fade
*/

#include "pixel.h"

void my_pixel_fade(framebuffer_t *framebuffer, unsigned int x, unsigned int y)
{
    sfColor color = sfTransparent;

    if (x <= 1920 && y <= 1080) {
        framebuffer->pixel[(1920 * y + x) + 4] = color.r;
        framebuffer->pixel[(1920 * y + x) + 4 + 1] = color.g;
        framebuffer->pixel[(1920 * y + x) + 4 + 2] = color.b;
        framebuffer->pixel[(1920 * y + x) + 4 + 3] = color.a;
    }
    return;
}
