/*
** EPITECH PROJECT, 2023
** my_save_buffer.c
** File description:
** to save the picture
*/

#include "pixel.h"

int my_save_buffer(framebuffer_t *buff)
{
    buff->fd = open(buff->name, O_CREAT | O_RDWR, 00666);
    write(buff->fd, buff->pixel, (1920 * 1080 * 4));
    return 0;
}
