/*
** EPITECH PROJECT, 2023
** my_square_fade.c
** File description:
** to fade the square
*/

#include "pixel.h"

void my_square_fade(framebuffer_t *framebuffer, unsigned int size,
                    unsigned int startx, unsigned int starty)
{
    for (int i = startx; i <= startx + size && i + size <= 1920; i ++)
        for (int y = starty; y <= starty + size && y + size <= 1080; y ++)
            my_pixel_fade(framebuffer, i, y);    
    return;
}
