/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-arthur1.soulie
** File description:
** main.c
*/

#include <unistd.h>
#include "malloc.h"

void *brk_start = NULL;

void *allocate(void *addrs, size_t size)
{
    meta_t *meta = addrs;
    meta->free = false;
    meta->size = get_offset(size);
    meta->next = NULL;
    return (addrs + sizeof(meta_t));
}

void *get_needed_pages(void *start, void *end)
{
    int double_page_size = getpagesize() * 2;
    unsigned int i = 0;

    for (; start < end; i++) {
        start += double_page_size;
    }
    if (sbrk(i * PAGE_SIZE * 2) == (void *) -1)
        return (NULL);
    return (sbrk(0));
}

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

void *find_best_fit(size_t size, void *brk)
{
    meta_t *current_node = (meta_t *)brk_start;
    meta_t *result = current_node;
    bool found_free_space = false;

    while (current_node) {
        if (current_node->free && current_node->size < result->size && \
        current_node->size >= get_offset(size)) {
            result = current_node;
            found_free_space = true;
        }
        current_node = current_node->next;
    }
    if (found_free_space)
        return ((void*)result + sizeof(meta_t));
    return (append_alloc(size, brk));
}

void *malloc(size_t size)
{
    void *brk = sbrk(0);

    if (!size)
        return (NULL);
    if (!brk_start) {
        brk_start = sbrk(0);
        return (append_alloc(size, brk));
    }
    return (find_best_fit(size, brk));
}
