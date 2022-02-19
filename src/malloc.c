/*
** EPITECH PROJECT, 2022
** malloc.c
** File description:
** malloc.c
*/

#include "../include/malloc.h"

malloc_t *allNode = NULL;

int find_nearest_size(malloc_t *tmp, size_t *nearestSize, int actualIndex)
{
    if (nearestSize == 0) {
        *nearestSize = tmp->size;
        return (tmp->index);
    }
    if (nearestSize < tmp->size)
        return (actualIndex);
    *nearestSize = tmp->size;
    return (tmp->index);
}

int search_free_position(size_t size, malloc_t *tmp)
{
    size_t nearestSize = 0;
    int findIndex = -1;

    while (tmp->next != NULL) {
        if (tmp->size >= (size + sizeof(struct malloc_s))
            && tmp->free == true)
            findIndex = find_nearest_size(tmp, &nearestSize, findIndex);
        tmp = tmp->next;
    }
    return (findIndex);
}

void *malloc(size_t size)
{
    int freePosition = -1;

    if (size == 0)
        return (NULL);
    if (allNode == NULL) {
        allNode = fill_first_node(size);
        if (allNode == NULL)
            return (NULL);
        return (allNode->allocate);
    }
    freePosition = search_free_position(size, allNode);
    if (freePosition != -1) {
        return (fill_free_node(size, freePosition, allNode));
    }
    return (fill_node(size, allNode));
}