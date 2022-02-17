/*
** EPITECH PROJECT, 2022
** realloc.c
** File description:
** realloc.c
*/

#include "../include/malloc.h"

void *realloc(void *ptr, size_t size)
{
    malloc_t *tmp = allNode;
    void *newPtr = NULL;

    if (size == 0)
        return (NULL);
    while (tmp->allocate != ptr && tmp != NULL)
        tmp = tmp->next;
    if (tmp == NULL)
        return (malloc(size));
    if (size <= tmp->size)
        return (ptr);
    if ((newPtr = malloc(size)) != NULL) {
        memcpy(newPtr, ptr, tmp->size);
        free(ptr);
    }
    return (NULL);
}