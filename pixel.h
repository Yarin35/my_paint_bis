/*
** EPITECH PROJECT, 2023
** pixel.h
** File description:
** pixel.h
*/

#ifndef PIXEL_H
    #define PIXEL_H
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Config.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <time.h>
    #include <fcntl.h>

typedef struct mouse_s{

    sfColor color;
    sfVector2i position;

} mouse_t;

typedef struct index_s {

    int size;
    int i;
    int j;
    sfColor color;
    sfTexture *text;
    sfSprite *sprite;
    sfTime time;
    sfClock *clock;

} index_t;

typedef struct framebuffer_s {

    unsigned int x;
    unsigned int y;
    sfUint8 *pixel;
    sfTexture *texture;
    sfSprite *sprite;

} framebuffer_t;

framebuffer_t *my_framebuffer_create(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int height,
                  unsigned int width, sfColor color);
void *my_calloc(size_t type, size_t size);
void my_put_square(framebuffer_t *framebuffer, index_t *i);
void my_pixel_fade(framebuffer_t *framebuffer, unsigned int x, unsigned int y);
void my_square_fade(framebuffer_t *framebuffer, unsigned int size,
                    unsigned int startx, unsigned int starty);
void switch_screen_transition(sfRenderWindow *window, sfColor color);
void print(framebuffer_t *buff, index_t *i, sfRenderWindow *window);
void fade(framebuffer_t *buff, index_t *i, sfRenderWindow *window);
void square_print(framebuffer_t *framebuffer, unsigned int size, unsigned int
                  startx, unsigned int starty, sfColor color);
void my_reset_framebuffer(framebuffer_t *framebuffer);
int pencil_paint(framebuffer_t *buff, mouse_t *m, sfRenderWindow *window, sfEvent *event);
int fill_color(framebuffer_t *buff, sfRenderWindow *win, sfEvent *e, mouse_t *m);
bool is_same_color(sfUint8 co, framebuffer_t *buff, int x, int y);
bool is_same(sfUint8 pix, sfUint8 pixel);
int my_erase(framebuffer_t *framebuffer, mouse_t *mouse);
char *my_convert_buff(sfUint8 *pixel, int length);
int save_png_file(char *buff);
#endif