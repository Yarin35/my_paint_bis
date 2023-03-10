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
    framebuffer_t *framebuffer = my_calloc(sizeof(framebuffer_t), 1);
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfSprite *sprite = sfSprite_create();
    sfVector2i position;
    sfVector2u size;
    
    sfSprite_setTexture(sprite, texture, sfTrue);
    framebuffer->pixel = my_calloc(sizeof(sfUint8), (1920 * 1080 * 4));
    while(sfRenderWindow_isOpen(window)) {
        size = sfRenderWindow_getSize(window);
        position = sfMouse_getPosition(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            position = sfMouse_getPosition(window);
            if (event.type == sfEvtMouseButtonPressed) {
                square_print(framebuffer, 5, event.mouseButton.x, event.mouseButton.y, sfRed);
                
//                framebuffer->pixel[(event.mouseButton.x + event.mouseButton.y) * 4] = sfRed.r;
//                framebuffer->pixel[(event.mouseButton.x + event.mouseButton.y) * 4 + 1] = sfRed.g;
//                framebuffer->pixel[(event.mouseButton.x + event.mouseButton.y) * 4 + 2] = sfRed.b;
//                framebuffer->pixel[(event.mouseButton.x + event.mouseButton.y) * 4 + 3] = sfRed.a;
                sfTexture_updateFromPixels(texture, framebuffer->pixel, 1920, 1080, 0, 0);
                sfRenderWindow_drawSprite(window, sprite, NULL);
                sfRenderWindow_display(window);
            }
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
