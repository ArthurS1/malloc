/*
** EPITECH PROJECT, 2021
** my_malloc
** File description:
** functions needed to append allocations
*/

#include "malloc.h"

extern void *brk_start;

static void *get_last_node(void)
{
    meta_t *current_node = (meta_t *)brk_start;

    while (current_node->next) {
        current_node = current_node->next;
    }
    return (current_node);
}

static void *append_alloc_to_existing(size_t size, void *brk)
{
    meta_t *last_node = get_last_node();
    void *end_of_alloc = NULL;

    last_node->next = (void *)last_node + sizeof(meta_t) + last_node->size;
    end_of_alloc = (void*)last_node->next + sizeof(meta_t) + size;
    if (end_of_alloc > brk) {
        brk = get_needed_pages(last_node->next, ((void *)last_node->next \
        + sizeof(meta_t) + size));
        if (!brk)
            return (NULL);
    }
    return allocate(last_node->next, size);
}

static void *append_alloc_to_empty(size_t size, void *brk)
{
    brk = get_needed_pages(brk_start, (brk_start + sizeof(meta_t) + size));
    if (!brk)
        return (NULL);
    return allocate(brk_start, size);
}

void *append_alloc(size_t size, void *brk)
{
    static bool first_append = true;

    if (!first_append) {
        return append_alloc_to_existing(size, brk);
    }
    first_append = false;
    return append_alloc_to_empty(size, brk);
}
