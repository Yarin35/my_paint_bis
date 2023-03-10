/*
** EPITECH PROJECT, 2023
** my_create_framebuffer.c
** File description:
** to create the framebuffer
*/

#include "pixel.h"

framebuffer_t *my_framebuffer_create(framebuffer_t *framebuffer, sfTexture *texture)
{
    framebuffer = my_calloc(sizeof(framebuffer_t), 1);
    framebuffer->pixel = my_calloc(sizeof(sfUint8), (4 * 1920 * 1080));
    framebuffer->texture = texture;
    return framebuffer;
}
