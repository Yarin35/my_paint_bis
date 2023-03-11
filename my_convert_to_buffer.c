/*
** EPITECH PROJECT, 2023
** my_convert_to_buffer.c
** File description:
** to convert to a char * from a sfUint8 *
*/

#include "pixel.h"

char *my_convert_buff(sfUint8 *pixel, int length)
{
    char *buff = my_calloc(1, (length + 1));

    for (int i = 0; i <= length; i ++)
        buff[i] = pixel[i];
    buff[length] = '\0';
    return buff;
}
