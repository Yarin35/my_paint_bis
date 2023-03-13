/*
** EPITECH PROJECT, 2023
** my_rectangle_create.c
** File description:
** to create a rectangle
*/

#include "pixel.h"

sfRectangleShape *my_rect_create(sfVector2f size, sfVector2f position)
{
    sfVector2f origin = {size.x / 2, size.y / 2};
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfColor color = {10, 10, 10, 20};

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOrigin(rectangle, origin);
    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setOutlineColor(rectangle, sfBlack);
    sfRectangleShape_setFillColor(rectangle, color);
    return rectangle;
}
