/*
** EPITECH PROJECT, 2022
** node.c
** File description:
** node.c
*/

#include "../include/malloc.h"

malloc_t *push_node(malloc_t *newNode)
{
    malloc_t *tmp = NULL;

    if (firstNode == NULL)
        firstNode = create_node(0);
    tmp = firstNode;
    while (tmp->next != NULL)
        tmp = tmp->next;
    newNode->previous = tmp;
    tmp->next = newNode;
    return (tmp->next);
}

malloc_t *split_node(size_t size, malloc_t *node)
{
    malloc_t *newNode;

    newNode = (malloc_t *)((char *)node + (size + sizeof(struct malloc_s)));
    newNode->previous = node;
    newNode->next = node->next;
    if (node->next != NULL)
        newNode->next->previous = newNode;
    newNode->size = node->size - (size + sizeof(struct malloc_s));
    newNode->address = newNode + 1;
    newNode->free = true;
    return (newNode);
}

malloc_t *fill_free_node(malloc_t *freeNode)
{
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
    newNode->previous = NULL;
    newNode->size = realSize;
    newNode->address = newNode + 1;
    newNode->free = false;
    return (newNode);
}