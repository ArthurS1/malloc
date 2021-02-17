/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** calloc function
*/

#include <string.h>
#include <limits.h>
#include <stddef.h>
#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *allocated = NULL;
    size_t alloc_size = nmemb * size;

    if (!nmemb || !size)
        return (NULL);
    if (nmemb && alloc_size / nmemb != size)
        return (NULL);
    allocated = malloc(alloc_size);
    if (!allocated)
        return (NULL);
    memset(allocated, 0, alloc_size);
    return (allocated);
}
