/*
** EPITECH PROJECT, 2022
** malloc.c
** File description:
** malloc.c
*/

#include "../include/malloc.h"

malloc_t *allNode = NULL;

int search_free_position(size_t size, malloc_t *tmp)
{
    while (tmp->next != NULL) {
        if (tmp->size >= size && tmp->free == true)
            break;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return (-1);
    return (tmp->index);
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