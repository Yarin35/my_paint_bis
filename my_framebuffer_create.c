/*
** EPITECH PROJECT, 2023
** my_create_framebuffer.c
** File description:
** to create the framebuffer
*/

#include "pixel.h"

framebuffer_t *my_framebuffer_create(framebuffer_t *framebuffer)
{
    sfVector2f origin = {3, 3};

    framebuffer = my_calloc(sizeof(framebuffer_t), 1);
    framebuffer->pixel = my_calloc(sizeof(sfUint8), (4 * 1920 * 1080));
    framebuffer->sprite = sfSprite_create();
    framebuffer->texture = sfTexture_create(1920, 1080);
    sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
    sfSprite_setOrigin(framebuffer->sprite, origin);
    framebuffer->pixel = my_calloc(sizeof(sfUint8), (1920 * 1080 * 4));
    return framebuffer;
}
