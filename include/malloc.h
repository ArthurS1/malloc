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

typedef struct meta_s {
    bool free;
    size_t length;
    size_t offset;
    struct meta_s *next;
} meta_t;

void *malloc(size_t size);

#endif /* !MALLOC_H_ */
