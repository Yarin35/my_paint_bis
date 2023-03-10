/*
** EPITECH PROJECT, 2023
** switch_screen.c
** File description:
** switch_screen transition
*/

#include"pixel.h"

void print(framebuffer_t *buff, index_t *i, sfRenderWindow *window)
{
    if (sfTime_asMicroseconds(i->time) > 0.001) {
        my_put_square(buff, i);
        sfTexture_updateFromPixels(i->text, buff->pixel, 1920, 1080, 0, 0);
        sfRenderWindow_drawSprite(window, i->sprite, NULL);
        sfRenderWindow_display(window);
        sfClock_restart(i->clock);
    }
    return;
}

void fade(framebuffer_t *buff, index_t *i, sfRenderWindow *window)
{
    i->color = sfBlack;
    if (sfTime_asMicroseconds(i->time) > 0.001) {
        my_put_square(buff, i);
        sfTexture_updateFromPixels(i->text, buff->pixel, 1920, 1080, 0, 0);
        sfRenderWindow_drawSprite(window, i->sprite, NULL);
        sfRenderWindow_display(window);
        sfClock_restart(i->clock);
    }
    return;
}

void switch_screen_transition(sfRenderWindow *window, sfColor color)
{
    index_t *i = my_calloc(sizeof(index_t), 1);
    framebuffer_t *buff = my_calloc(sizeof(framebuffer_t), 1);

    buff->pixel = my_calloc(sizeof(char), (1920 * 1080 * 4));
    i->clock = sfClock_create();
    i->time = sfClock_getElapsedTime(i->clock);
    i->sprite = sfSprite_create();
    i->text = sfTexture_create(1920, 1080);
    sfSprite_setTexture(i->sprite, i->text, sfTrue);
    i->size = 65;
    i->color = color;
    for (i->i = 0; i->i <= 1080; i->i += i->size)
        for (i->j = 0; i->j <= 1920; i->j += i->size)
            print(buff, i, window);
    sfClock_restart(i->clock);
    for (i->i = 0; i->i <= 1080; i->i += i->size)
        for (i->j = 0; i->j <= 1920; i->j += i->size)
            fade(buff, i, window);
    return;
}
