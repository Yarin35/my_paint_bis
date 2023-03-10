/*
** EPITECH PROJECT, 2023
** my_calloc
** File description:
** calloc function
*/

#include "pixel.h"

void *my_calloc(size_t type, size_t size)
{
    void *data = malloc(type * size);

    unsigned char * data_ptr = (unsigned char *) data;
    if (!(data))
        return NULL;
    while (size --)
        *data_ptr ++ = (unsigned char)0;
    return data;
}
