/*
** EPITECH PROJECT, 2022
** realloc.c
** File description:
** realloc.c
*/

#include "malloc.h"

void copy_memory(void *ptr, void *newPtr, malloc_t *node, size_t size)
{
    if (newPtr) {
        if (node->size < make_size_power_of_2(size))
            memcpy(newPtr, ptr, node->size);
        else
            memcpy(newPtr, ptr, make_size_power_of_2(size));
        free(ptr);
    }
}

void *realloc(void *ptr, size_t size)
{
    malloc_t *tmp;
    void *newPtr = NULL;

    if (!ptr)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    tmp = (malloc_t *)ptr - 1;
    if (make_size_power_of_2(size) == tmp->size || size == tmp->size ||
        tmp->address != ptr)
        return (ptr);
    newPtr = malloc(size);
    copy_memory(ptr, newPtr, tmp, size);
    return (newPtr);
}
