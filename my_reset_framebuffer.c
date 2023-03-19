/*
** EPITECH PROJECT, 2023
** to reset the pixels of the framebuffer
** File description:
** gh
*/
#include "pixel.h"

void my_reset_framebuffer(framebuffer_t *framebuffer)
{
    int len = (1920 * 1080 * 4);

    for (int i = 0; i <= len; i ++)
        framebuffer->pixel[i] = 0;
    sfTexture_updateFromPixels(framebuffer->texture, framebuffer->pixel, 1920, 1080, 0, 0);
    return;
}
