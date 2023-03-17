/*
** EPITECH PROJECT, 2023
** my_load_buffer.c
** File description:
** to load a file
*/

#include "pixel.h"

int my_load_buffer(framebuffer_t *buff, sfEvent *event)
{
    char *filename = my_strcat("assets/", my_strcat(buff->name, ".jpg"));
    sfImage *picture;
    sfTexture *texture;
    size_t size = 0;
    sfUint8 const *pixel = my_calloc(1, (1920 * 1080 * 4));

    if (open(filename, O_RDONLY) == -1)
        return 84;
    picture = sfImage_createFromFile(filename);
    pixel = sfImage_getPixelsPtr(picture);
    for (size_t i = 0; i <= (1920 * 1080 * 4); i ++)
        buff->pixel[i] = pixel[i];
    sfTexture_updateFromPixels(buff->texture, buff->pixel, 1920, 1080, 0, 0);
    sfSprite_setTexture(buff->sprite, buff->texture, sfTrue);
    return 0;
}
