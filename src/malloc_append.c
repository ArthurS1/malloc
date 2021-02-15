/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** functions needed to append allocations
*/

#include "malloc.h"

extern void *brk_start;

void *append_alloc_full(size_t size, void *brk)
{
    meta_t *current_node = (meta_t *)brk_start;

    while (current_node->next) {
        current_node = current_node->next;
    }
    current_node->next = (void *)current_node + sizeof(meta_t) + \
    current_node->size;
    if ((void*)(current_node->next + current_node->size + size) \
    > brk)
        brk = get_needed_pages(current_node->next, ((void*)current_node->next \
        + size));
    if (!brk)
        return (NULL);
    return allocate(current_node->next, size);
}

void *append_alloc(size_t size, void *brk)
{
    if (brk != brk_start) {
        return append_alloc_full(size, brk);
    }
    brk = get_needed_pages(brk_start, (brk_start + size));
    if (!brk)
        return (NULL);
    return allocate(brk_start, size);
}
