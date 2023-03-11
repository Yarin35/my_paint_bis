/*
** EPITECH PROJECT, 2023
** is_same_color.c
** File description:
** is_same_color checker
*/

#include "pixel.h"

bool is_same(sfUint8 pix, sfUint8 pixel)
{
    if (pix != pixel)
        return false;
    return true;
}

bool is_same_color(sfUint8 co, framebuffer_t *buff, int x, int y)
{
    if (!is_same(buff->pixel[co], buff->pixel[(1920 * x + y) * 4]) ||
        !is_same(buff->pixel[co + 1], buff->pixel[(1920 * x + y) * 4 + 1]) ||
        !is_same(buff->pixel[co + 2], buff->pixel[(1920 * x + y) * 4 + 2]) ||
        !is_same(buff->pixel[co + 3], buff->pixel[(1920 * x + y) * 4 + 3]))
        return false;
    return true;
}
