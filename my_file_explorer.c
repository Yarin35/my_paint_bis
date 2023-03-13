/*
** EPITECH PROJECT, 2023
** my_file_explorer.c
** File description:
** to open the assets/ 
*/

#include "pixel.h"

void my_file_explorer(int option, framebuffer_t *buff, sfEvent *event)
{
    switch (option) {
    case 1: my_new_file(buff, event); break;
    case 2: my_open_file(buff, event); break;
    case 3: my_save_file(buff, event); break;
    }
    return;
}
