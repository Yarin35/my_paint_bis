/*
** EPITECH PROJECT, 2023
** my_save_picture.c
** File description:
** to save a picture as a .png file
*/

#include "pixel.h"

static int my_strlen(char *str)
{
    int nb = 0;
    while (str[nb ++]);
    return nb;
}

int save_png_file(char *buff)
{
    int fd = open("picture.png", O_CREAT | O_RDWR, 00700);
    char *header = "\xFF\xD8\xFF\xE0\x00\x10""JFIF\x00\x01\x01\x00\x00\x01\x00\x01\x00\x00";
    char *trailer = "\xFF\xD9";

    if (write(fd, header, my_strlen(header)) == -1) {
        close(fd);
        return 84;
    }
    if (write(fd, buff, my_strlen(buff)) == -1) {
        close(fd);
        return 84;
    }
    if (write(fd, trailer, my_strlen(trailer)) == -1) {
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}
