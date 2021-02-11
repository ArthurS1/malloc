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
    void *new = malloc(size);
    meta_t *old_meta = ptr - sizeof(meta_t);

    if (!ptr || !new || !size)
        return (NULL);
    memcpy(new, ptr + old_meta->offset, old_meta->length);
    free(ptr);
    return (new);
}
