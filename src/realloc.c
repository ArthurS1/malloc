/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** realloc function
*/

#include "malloc.h"
#include <unistd.h>
#include <string.h>

static void *allocate_of_size(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);
    meta_t *meta = (meta_t *)(ptr - sizeof(meta_t));

    if (!new_ptr)
        return (NULL);
    memcpy(new_ptr, ptr, (ptr + meta->size) - ptr);
    free(ptr);
    return (new_ptr);
}

void *realloc(void *ptr, size_t size)
{
    if (!ptr && size)
        return malloc(size);
    if (ptr && !size) {
        free(ptr);
        return (NULL);
    }
    if (!ptr && !size)
        return (NULL);
    return (allocate_of_size(ptr, size));
}
