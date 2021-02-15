/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** free function
*/

#include "malloc.h"

void free(void *addrs)
{
    meta_t *meta = NULL;

    if (addrs) {
        meta = (meta_t *)(addrs - sizeof(meta_t));
        meta->free = true;
    }
}
