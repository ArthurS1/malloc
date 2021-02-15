/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** malloc function
*/

#include <unistd.h>
#include "malloc.h"

void *brk_start = NULL;

static size_t get_aligned_size(size_t size)
{
    size_t res = 2;
    while (res < size) {
        res *= 2;
    }
    return (res);
}

static void *find_best_fit(size_t size, void *brk)
{
    /*meta_t *current_node = (meta_t *)brk_start;
    meta_t *result = current_node;
    bool found_free_space = false;

    while (current_node) {
        if (current_node->free && current_node->size < result->size && \
        current_node->size >= get_offset(size)) {
            result = current_node;
            found_free_space = true;
            break;
        }
        current_node = current_node->next;
    }
    if (found_free_space)
        return ((void*)result + sizeof(meta_t));*/
    return (append_alloc(size, brk));
}

void *malloc(size_t size)
{
    void *brk = sbrk(0);

    if (!size)
        return (NULL);
    size = get_aligned_size(size);
    if (!brk_start) {
        brk_start = sbrk(0);
        return (append_alloc(size, brk));
    }
    return (find_best_fit(size, brk));
}
