/*
** EPITECH PROJECT, 2023
** my_new_file.c
** File description:
** my_new_file
*/

#include "pixel.h"

static void get_char(framebuffer_t *buff, sfEvent *evt, char *name)
{
    if (evt->text.unicode >= 48 && evt->text.unicode <= 122)
        name[buff->namelen ++] = (char)evt->text.unicode;
    if (evt->text.unicode == 8 && buff->namelen > 0)
        name[-- buff->namelen] = '\0';
}

char *enter_name(framebuffer_t *buffer, sfEvent *event)
{
    char *name = my_calloc(sizeof(unsigned char), 10);
    if (buffer->namelen < 9 && event->type == sfEvtTextEntered)
        get_char(buffer, event, name);
    name[buffer->namelen] = '\0';
    buffer->namelen = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        buffer->name = my_strcat(buffer->name, name);
        sfText_setString(buffer->text, buffer->name);
        if (buffer->option == 1) {
            my_save_buffer(buffer);
            buffer->name = my_calloc(1, 10);
        } //else if (buffer->option == 2) {
          //  my_load_buffer(buffer, event);
          //  buffer->name = my_calloc(1, 10);
//        }
        buffer->option = 0;
        if (!buffer->namefull)
            buffer->namefull = true;
        else
            buffer->namefull = false;
    }
    return name;
}

void my_new_file(framebuffer_t *buff, sfEvent *event)
{
    char *filename = enter_name(buff, event);

    if (filename) {
        buff->name = my_strcat(buff->name, filename);
        sfText_setString(buff->text, buff->name);
        free(filename);
    }
    return;
}
