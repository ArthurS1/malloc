/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-arthur1.soulie
** File description:
** main.c
*/

#include <unistd.h>
#include <stddef.h>

void *malloc(size_t size)
{
    write(1, "test\n", 5);
    return ((void *)1);
}
