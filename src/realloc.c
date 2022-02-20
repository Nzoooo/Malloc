/*
** EPITECH PROJECT, 2022
** realloc.c
** File description:
** realloc.c
*/

#include "../include/malloc.h"

void *realloc(void *ptr, size_t size)
{
    size_t realSize = make_size_power_of_2(size);
    malloc_t *tmp;
    void *newPtr = NULL;

    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (malloc(size));
    tmp = (malloc_t *)ptr - 1;
    if (realSize <= tmp->size)
        return (ptr);
    if ((newPtr = malloc(size)) != NULL) {
        memcpy(newPtr, ptr, tmp->size);
        free(ptr);
    }
    return (NULL);
}