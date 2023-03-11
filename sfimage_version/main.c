/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

int main(void)
{
    sfVideoMode video = { 1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video, "test", sfFullscreen | sfClose, NULL);
    sfImage *image = sfImage_create(1920, 1080);
    sfEvent event;
    sfVector2f pos = {0, 0};
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed)
                if (sfKeyboard_isKeyPressed(sfKeyEscape))
                    sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) {
                pos.x = event.mouseButton.x;
                pos.y = event.mouseButton.y;
                sfImage_setPixel(image, pos.x, pos.y, sfRed);
                sfTexture_updateFromImage(texture, image, 0, 0);
            }
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfImage_destroy(image);
    sfRenderWindow_destroy(window);
    return 0;
}
