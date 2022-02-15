/*
** EPITECH PROJECT, 2022
** node.c
** File description:
** node.c
*/

#include "../include/malloc.h"

void *fill_first_node(size_t size)
{
    size_t realSize = 2;

    while (realSize < size + sizeof(malloc_t)) {
        realSize *= 2;
    }
    if (sbrk(realSize) == (void *)-1)
        return (NULL);
    allNode = sbrk(0);
    allNode->previous = NULL;
    allNode->next = NULL;
    allNode->index = 0;
    allNode->size = realSize;
    allNode->allocate = sbrk(0);
    allNode->free = false;
    return (allNode->allocate);
}

void *fill_free_node(size_t size, int index, malloc_t *tmp)
{
    size_t realSize = 2;

    while (realSize < size + sizeof(malloc_t)) {
        realSize *= 2;
    }
    while (tmp->index != index && tmp->next != NULL)
        tmp = tmp->next;
    if (sbrk(realSize) == (void *)-1)
        return (NULL);
    tmp->next = sbrk(0);
    tmp->next->index = 0;
    tmp->next->size = realSize;
    tmp->next->allocate = sbrk(0);
    tmp->next->free = false;
    return (tmp->next->allocate);
}

void *fill_node(size_t size, malloc_t *tmp)
{
    size_t realSize = 2;

    while (realSize < size + sizeof(malloc_t)) {
        realSize *= 2;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    if (sbrk(realSize) == (void *)-1)
        return (NULL);
    tmp->next = sbrk(0);
    tmp->next->previous = tmp;
    tmp->next->next = NULL;
    tmp->next->index = 0;
    tmp->next->size = realSize;
    tmp->next->allocate = sbrk(0);
    tmp->next->free = false;
    return (tmp->next->allocate);
}