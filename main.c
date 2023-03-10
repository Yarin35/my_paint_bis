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
    sfRenderWindow *window = sfRenderWindow_create(video, "test", sfClose | sfResize, NULL);
    sfEvent event;
    framebuffer_t *framebuffer = my_framebuffer_create(framebuffer);
    mouse_t *mouse = my_calloc(sizeof(mouse_t), 1);

    while(sfRenderWindow_isOpen(window)) {
        position = sfMouse_getPosition(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            position = sfMouse_getPosition(window);
            if (event.type == sfEvtMouseButtonPressed)
                pencil_paint(framebuffer, mouse, &event);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed) {
                if (sfKeyboard_isKeyPressed(sfKeyEscape))
                    sfRenderWindow_close(window);
                if (sfKeyboard_isKeyPressed(sfKeySpace)) {
                    my_reset_framebuffer(framebuffer);
                    sfRenderWindow_clear(window, sfWhite);
                    square_print(framebuffer, 5, 980, 1050, sfRed);
                    sfRenderWindow_display(window);
                }
            }
        }
    }
    sfRenderWindow_destroy(window);
    return 0;
}
