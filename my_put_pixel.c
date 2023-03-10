/*
** EPITECH PROJECT, 2023
** my_put_pixel.c
** File description:
** put pixel function
*/

#include "pixel.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned int height,
               unsigned int width, sfColor color)
{
    if (height <= 1920 && width <= 1080) {
        framebuffer->pixel[(1920 * width + height) * 4] = color.r;
        framebuffer->pixel[(1920 * width + height) * 4 + 1] = color.g;
        framebuffer->pixel[(1920 * width + height) * 4 + 2] = color.b;
        framebuffer->pixel[(1920 * width + height) * 4 + 3] = color.a;
    }
    return;
}
