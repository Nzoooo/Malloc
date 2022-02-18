/*
** EPITECH PROJECT, 2022
** node.c
** File description:
** node.c
*/

#include "../include/malloc.h"

void *split_node(size_t size, malloc_t *tmp)
{
    malloc_t *newNode;

    newNode = (malloc_t *)((char*)tmp + size);
    newNode->previous = tmp;
    newNode->next = tmp->next;
    newNode->size = size;
    newNode->allocate = (malloc_t *)((char*)tmp + size);
    newNode->free = false;
    tmp->size -= size;
    tmp->next = newNode;
    return (newNode->allocate);
}

void *fill_first_node(size_t size)
{
    size_t realSize = 2;

    while (realSize < size + sizeof(struct malloc_s)) {
        realSize *= 2;
    }
    if (sbrk(realSize) == (void *)-1)
        return (NULL);
    allNode = sbrk(0);
    allNode->index = 0;
    allNode->size = realSize;
    allNode->allocate = sbrk(0);
    allNode->free = false;
    allNode->next = NULL;
    allNode->previous = NULL;
    return (allNode->allocate);
}

void *fill_free_node(size_t size, int index, malloc_t *tmp)
{
    while (tmp->index != index && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp->size != size + sizeof(struct malloc_s)) {
        return (split_node(size + sizeof(struct malloc_s), tmp));
    }
    tmp->free = false;
    return (tmp->allocate);
}

void *fill_node(size_t size, malloc_t *tmp)
{
    size_t realSize = 2;

    while (realSize < size + sizeof(struct malloc_s)) {
        realSize *= 2;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    if (sbrk(realSize) == (void *)-1)
        return (NULL);
    tmp->next = sbrk(0);
    tmp->next->next = NULL;
    tmp->next->previous = tmp;
    tmp->next->index = tmp->index + 1;
    tmp->next->size = realSize;
    tmp->next->allocate = sbrk(0);
    tmp->next->free = false;
    return (tmp->next->allocate);
}