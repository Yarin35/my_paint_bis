/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "pixel.h"

int main(void)
{
    sfVideoMode video = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video, "test", sfClose | sfFullscreen, NULL);
    sfEvent event;
    framebuffer_t *framebuffer = my_framebuffer_create(framebuffer);
    mouse_t *mouse = my_calloc(sizeof(mouse_t), 1);
    mouse->color = sfCyan;

    while(sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtMouseButtonPressed) {
                mouse->position.x = event.mouseButton.x;
                mouse->position.y = event.mouseButton.y;
//                square_print(framebuffer, 6, event.mouseButton.x, event.mouseButton.y, sfCyan);
//                my_erase(framebuffer, mouse);
//                fill_color(framebuffer, window, &event, mouse);
                pencil_paint(framebuffer, mouse, window, &event);
            }
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed) {
                if (sfKeyboard_isKeyPressed(sfKeyEscape))
                    sfRenderWindow_close(window);
                if (sfKeyboard_isKeyPressed(sfKeySpace)) {
                    my_reset_framebuffer(framebuffer);
                    sfRenderWindow_clear(window, sfWhite);
                    sfRenderWindow_display(window);
                }
            }
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, framebuffer->sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
