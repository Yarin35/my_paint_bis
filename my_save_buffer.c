/*
** EPITECH PROJECT, 2023
** my_save_buffer.c
** File description:
** to save the picture
*/

#include "pixel.h"

int my_save_buffer(framebuffer_t *buff)
{
    sfImage *picture = sfTexture_copyToImage(buff->texture);
    sfVector2u size = sfImage_getSize(picture);
    size_t len = size.x * size.y * 4;

    buff->name = my_strcat("assets/", buff->name);
    buff->name = my_strcat(buff->name, ".jpg");
    buff->fd = fopen(buff->name, "wb");
    if (buff->fd == NULL)
        return 84;
    sfImage_saveToFile(picture, buff->name);
    return 0;
}
