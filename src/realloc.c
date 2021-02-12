/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** realloc
*/

#include "malloc.h"
#include <unistd.h>
#include <string.h>

/*
void *realloc(void *ptr, size_t size)
{
    void *new = malloc(size);
    meta_t *meta = ptr - sizeof(meta_t);

    if (!ptr || !new || !size)
        return (NULL);
    memcpy(new, ptr, meta->size);
    return (new);
}
*/
