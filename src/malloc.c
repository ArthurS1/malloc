/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-arthur1.soulie
** File description:
** main.c
*/

#include <unistd.h>
#include "malloc.h"

size_t get_offset(void *addrs, size_t size)
{
    size_t i = 3;
    size_t data_units[4] = {1, 2, 4, 8};

    for (; size < data_units[i]; i--);
    if (data_units[i] == 1)
        return (0);
    else
        return (data_units[i] - ((size_t)addrs % data_units[i]) %
        data_units[i]);
}

void *allocate(void *addrs, size_t size)
{
    meta_t *meta = addrs;
    meta->free = false;
    meta->length = size;
    meta->offset = get_offset(addrs, size);
    meta->next = NULL;
    return (addrs + sizeof(meta_t) + meta->offset);
}

void *get_needed_pages(void *start, void *end)
{
    int double_page_size = getpagesize() * 2;
    unsigned int i = 0;

    for (; start < end; i++) {
        start += double_page_size;
    }
    if (sbrk(i * PAGE_SIZE * 2) == (void *) -1)
        return ((void *) -1);
    return (sbrk(0));
}

void *append_alloc(size_t size, void *brk)
{
    meta_t *current_node = (meta_t *)brk_start;

    while (current_node->next) {
        current_node = current_node->next;
    }
    current_node->next = (void *)current_node + current_node->offset + current_node->length + sizeof(meta_t);
    if (((void*)current_node->next + get_offset((meta_t *)current_node->next, size) + size) > brk) {
        brk = get_needed_pages(current_node->next, ((void*)current_node->next + get_offset((meta_t *)current_node->next, size) + size));
    }
    return allocate(current_node->next, size);
}

void *find_best_fit(size_t size, void *brk)
{
    meta_t *current_node = (meta_t *)brk_start;
meta_t *result = current_node;
    bool found_free_space = false;

    while (current_node) {
        if (current_node->free && current_node->length < result->length &&
        current_node->length >= size + get_offset(current_node, size)) {
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

    if (!brk_start) {
        brk_start = sbrk(0);
        if (sbrk(PAGE_SIZE * 2) == (void *)-1)
            return (NULL);
        brk = sbrk(0);
        return (allocate(brk_start, size));
    }
    return (find_best_fit(size, brk));
}
