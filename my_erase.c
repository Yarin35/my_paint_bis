/*
** EPITECH PROJECT, 2023
** my_erase.c
** File description:
** eraser
*/

#include "pixel.h"

int my_erase(framebuffer_t *framebuffer, mouse_t *mouse)
{
    my_square_fade(framebuffer, 5, mouse->position.x, mouse->position.y);
    return 0;
}
