/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** reallocarray function
*/

#include <stddef.h>
#include "malloc.h"

void *reallocarray(void *ptr, size_t nmemb,size_t size)
{
    size_t alloc_size = nmemb * size;

    if (!nmemb || !size || ptr)
        return (NULL);
    if (nmemb && alloc_size / nmemb != size)
        return (NULL);
    realloc(ptr, alloc_size);
    return (NULL);
}
