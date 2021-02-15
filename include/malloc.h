/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-arthur1.soulie
** File description:
** malloc.h
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdbool.h>
#include <stddef.h>

#define PAGE_SIZE getpagesize()

typedef struct meta_s {
    bool free;
    size_t size;
    struct meta_s *next;
} meta_t;

size_t get_offset(size_t size);
void *get_needed_pages(void *start, void *end);
void *allocate(void *addrs, size_t size);
void *append_alloc(size_t size, void *brk);

void *malloc(size_t size);
void free(void *addrs);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb,size_t size);

#endif /* !MALLOC_H_ */
