/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** to contcatenate a string on another
*/

#include "pixel.h"

static int my_stringlen(char const *str)
{
    int nb = 0;

    while (str[nb])
        nb ++;
    return nb;
}

char *my_strncat(char *dest, char *src, int nb)
{
    int i = 0;
    int len = my_stringlen(dest);
    int biglen = len + nb + 1;
    char *str = my_calloc(sizeof(char), biglen);

    while (i < len)
        str[i ++] = dest[i];
    while (i < biglen)
        str[i ++] = src[i - len];
    str[biglen] = '\0';
    return str;
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int len = my_stringlen(dest);
    int biglen = len + my_stringlen(src);
    char *str = my_calloc(sizeof(char), biglen + 1);

    while (i < len) {
        str[i] = dest[i];
        i ++;
    }
    while (i < biglen) {
        str[i] = src[i - len];
        i ++;
    }
    str[biglen] = '\0';
    return str;
}
