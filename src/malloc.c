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
    if (*nearestSize == 0) {
        *nearestSize = tmp->size;
        return (tmp->index);
    }
    if (*nearestSize < tmp->size)
        return (actualIndex);
    *nearestSize = tmp->size;
    return (tmp->index);
}

int search_free_position(size_t size, malloc_t *tmp)
{
    size_t nearestSize = 0;
    int findIndex = -1;

    while (tmp != NULL) {
        if (tmp->size >= size && tmp->free == true)
            findIndex = find_nearest_size(tmp, &nearestSize, findIndex);
        tmp = tmp->next;
    }
    return (findIndex);
}

void *malloc(size_t size)
{
    int freePosition = -1;
    malloc_t *tmp = allNode;

    if (size == 0)
        return (NULL);
    if (allNode == NULL) {
        if ((allNode = fill_node(size, NULL)) == NULL)
            return (NULL);
        return (allNode->address);
    }
    if ((freePosition = search_free_position(size, tmp)) != -1) {
        while (tmp->index != freePosition)
            tmp = tmp->next;
        fill_free_node(size, tmp);
        return (tmp->address);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    if ((tmp->next = fill_node(size, tmp)) == NULL)
        return (NULL);
    return (tmp->next->address);
}