/*
** EPITECH PROJECT, 2023
** my_new_file.c
** File description:
** my_new_file
*/

#include "pixel.h"

char *enter_name(framebuffer_t *buffer, sfEvent *event)
{
    char *name = my_calloc(1, 100);
//    bool enter = false;

//    while (!enter)
        if (event->type == sfEvtTextEntered) {
            if (event->text.unicode >= 32 && event->text.unicode < 127)
                name[buffer->namelen ++] = (char)event->text.unicode;
            if (event->text.unicode == 0 && buffer->namelen > 0)
                name[-- buffer->namelen] = '\0';
//            if (event->text.unicode == 13)
//                enter = true;
        }
    if (buffer->namelen != 0) {
        name[buffer->namelen] = '\0';
        buffer->namelen = 0;
        return name;
    }
    free(name);
    return NULL;
}

void my_new_file(framebuffer_t *buff, sfEvent *event)
{
    char *filename = enter_name(buff, event);

    if (filename) {
        my_strcat((char *)buff->text, filename);
        buff->fd = open(filename, O_CREAT | O_RDWR, 00666);
        sfText_setString(buff->text, filename);
        free(filename);
    }
    return;
}
