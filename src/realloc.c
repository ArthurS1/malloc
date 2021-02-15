/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** realloc
*/

#include "malloc.h"
#include <unistd.h>
#include <string.h>

void *realloc(void *ptr, size_t size)
{
    void *new = NULL;
    meta_t *meta = NULL;

    if (!ptr)
        return malloc(size);
    meta = (meta_t *)(ptr - sizeof(meta_t));
    new = malloc(size);
    if (!new)
        return (NULL);
    memcpy(new, ptr, ptr - (ptr + meta->size));
    free(ptr);
    return (new);
}
