/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** support functions for allocation
*/

#include "malloc.h"

size_t get_offset(size_t size)
{
    size_t res = 2;
    while (res < size) {
        res *= 2;
    }
    return (res);
}
