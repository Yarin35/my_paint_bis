/*
** EPITECH PROJECT, 2023
** my_create_framebuffer.c
** File description:
** to create the framebuffer
*/

#include "pixel.h"

void my_framebuffer_destroy(framebuffer_t *buffer)
{
    free(buffer->pixel);
    sfSprite_destroy(buffer->sprite);
    sfTexture_destroy(buffer->texture);
    sfText_destroy(buffer->text);
    sfFont_destroy(buffer->font);
    sfRectangleShape_destroy(buffer->rect);
    if (buffer->namefull)
        fclose(buffer->fd);
    free(buffer);
    return;
}

static void set_to_white(framebuffer_t *framebuffer, size_t len)
{
    framebuffer->namefull = false;
    for (size_t i = 0; i <= len; i ++)
        framebuffer->pixel[i] = 255;
    for (size_t i = 3; i <= len; i += 4)
        framebuffer->pixel[i] = 0;
    return;
}

framebuffer_t *my_framebuffer_create(framebuffer_t *framebuffer)
{
    sfVector2f position = {1920 / 2, 1080 / 2};

    framebuffer = my_calloc(sizeof(framebuffer_t), 1);
    framebuffer->namelen = 0;
    framebuffer->pixel = my_calloc(sizeof(sfUint8), (4 * 1920 * 1080));
    framebuffer->sprite = sfSprite_create();
    framebuffer->texture = sfTexture_create(1920, 1080);
    framebuffer->font = sfFont_createFromFile("Ambra-Sans-Italic-trial.ttf");
    framebuffer->text = sfText_create();
    framebuffer->name = my_calloc(sizeof(unsigned char), 10);
    framebuffer->rect = my_rect_create((sfVector2f){100, 40},
                                       (sfVector2f){960, 540});
    sfText_setFont(framebuffer->text, framebuffer->font);
    sfText_setCharacterSize(framebuffer->text, 20);
    sfText_setFillColor(framebuffer->text, sfBlack);
    sfText_setPosition(framebuffer->text, position);
    sfText_setString(framebuffer->text, "");
    sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
    set_to_white(framebuffer, (1920 * 1080 * 4));
    return framebuffer;
}
