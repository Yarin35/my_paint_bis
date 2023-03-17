/*
** EPITECH PROJECT, 2023
** my_file_explorer.c
** File description:
** to open the assets/
*/

#include "pixel.h"

void my_file_explorer(framebuffer_t *buff, sfEvent *event)
{
    switch (buff->option) {
    case 1: my_new_file(buff, event); break;
    case 2: my_new_file(buff, event); break;
    case 3: my_save_buffer(buff); break;
    }
    return;
}
