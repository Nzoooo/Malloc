/*
** EPITECH PROJECT, 2022
** node.c
** File description:
** node.c
*/

#include "../include/malloc.h"

malloc_t *push_node(malloc_t *tmp, malloc_t *newNode)
{
    if (firstNode == NULL) {
        firstNode = newNode;
        return (firstNode);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newNode;
    tmp->next->previous = tmp;
    return (tmp->next);
}

malloc_t *split_node(size_t size, malloc_t *node)
{
    malloc_t *newNode;

    newNode = (malloc_t *)((char *)node + (size + sizeof(struct malloc_s)));
    newNode->previous = node;
    newNode->next = node->next;
    newNode->size = node->size - size;
    newNode->address = newNode + 1;
    newNode->free = true;
    return (newNode);
}

malloc_t *fill_free_node(size_t size, malloc_t *freeNode)
{
    size_t realSize = make_size_power_of_2(size);

    if (freeNode->size > realSize) {
        freeNode->next = split_node(realSize, freeNode);
        freeNode->size = realSize;
    }
    freeNode->free = false;
    return (freeNode);
}

malloc_t *create_node(size_t size)
{
    size_t realSize = make_size_power_of_2(size);
    malloc_t *newNode;

    if ((newNode = sbrk(realSize + sizeof(struct malloc_s))) == (void *)-1)
        return (NULL);
    newNode->next = NULL;
    newNode->previous = lastNode;
    newNode->size = realSize;
    newNode->address = newNode + 1;
    newNode->free = false;
    return (newNode);
}