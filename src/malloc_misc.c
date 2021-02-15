/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** support functions for allocations
*/

#include <unistd.h>
#include "malloc.h"

void *get_needed_pages(void *start, void *end)
{
    int double_page_size = getpagesize() * 2;
    unsigned int i = 0;

    for (; start <= end; i++) {
        start += double_page_size;
    }
    if (sbrk(i * PAGE_SIZE * 2) == (void *) -1)
        return (NULL);
    return (sbrk(0));
}

void *allocate(void *addrs, size_t size)
{
    meta_t *meta = addrs;
    meta->free = false;
    meta->size = size;
    meta->next = NULL;
    return (addrs + sizeof(meta_t));
}
