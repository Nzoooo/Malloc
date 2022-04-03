/*
** EPITECH PROJECT, 2022
** realloc.c
** File description:
** realloc.c
*/

#include "../include/malloc.h"

void *realloc(void *ptr, size_t size)
{
    malloc_t *tmp;
    void *newPtr = NULL;

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    tmp = (malloc_t *)ptr - 1;
    if (make_size_power_of_2(size) == tmp->size || size == tmp->size)
        return (ptr);
    if ((newPtr = malloc(size)) != NULL) {
        if (tmp->size < make_size_power_of_2(size))
            memcpy(newPtr, ptr, tmp->size);
        else
            memcpy(newPtr, ptr, make_size_power_of_2(size));
        free(ptr);
    }
    return (newPtr);
}