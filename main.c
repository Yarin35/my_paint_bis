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
    int option = 0;

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
                    option = 1;
//                    my_file_explorer(option, framebuffer, &event);
                    sfRenderWindow_clear(window, sfWhite);
                    sfRenderWindow_display(window);
                }
            }
            if (option != 0)
                my_file_explorer(option, framebuffer, &event);
        }
        sfRenderWindow_clear(window, sfWhite);
        if (option == 1) {
            sfRenderWindow_drawRectangleShape(window, framebuffer->rect, NULL);
            sfRenderWindow_drawText(window, framebuffer->text, NULL);
        }
        sfRenderWindow_drawSprite(window, framebuffer->sprite, NULL);
        sfRenderWindow_display(window);
    }
    my_framebuffer_destroy(framebuffer);
    sfRenderWindow_destroy(window);
    return 0;
}
