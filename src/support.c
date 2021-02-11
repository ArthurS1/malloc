/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** support functions for allocation
*/

#include "malloc.h"

size_t get_offset(void *addrs, size_t size)
{
    size_t i = 3;
    size_t data_units[4] = {1, 2, 4, 8};

    for (; size < data_units[i]; i--);
    if (data_units[i] == 1)
        return (0);
    else
        return (data_units[i] - ((size_t)addrs % data_units[i]) % \
        data_units[i]);
}
