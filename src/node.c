/*
** EPITECH PROJECT, 2022
** node.c
** File description:
** node.c
*/

#include "malloc.h"

malloc_t *push_node(malloc_t *newNode)
{
    malloc_t *tmp = NULL;

    if (!firstNode)
        firstNode = create_node(0);
    tmp = firstNode;
    while (tmp->next)
        tmp = tmp->next;
    newNode->previous = tmp;
    tmp->next = newNode;
    return (tmp->next);
}

void split_node(size_t size, malloc_t *node)
{
    malloc_t *newNode = (malloc_t *)((char *)node + size + sizeof(malloc_t));

    newNode->next = node->next;
    newNode->previous = node;
    newNode->size = node->size - (size + sizeof(malloc_t));
    newNode->address = newNode + 1;
    newNode->free = true;
    if (node->next)
        node->next->previous = newNode;
    node->next = newNode;
    node->size = size;
}

malloc_t *fill_free_node(malloc_t *freeNode, size_t size)
{
    size_t realSize = make_size_power_of_2(size);

    if (freeNode->size > (realSize + sizeof(malloc_t)))
        split_node(realSize, freeNode);
    freeNode->free = false;
    return (freeNode);
}

malloc_t *create_node(size_t size)
{
    size_t realSize = make_size_power_of_2(size);
    malloc_t *newNode;

    newNode = sbrk(make_size_page_multiple(realSize + sizeof(malloc_t)));
    if (newNode == (void *)-1)
        return (NULL);
    newNode->next = NULL;
    newNode->previous = NULL;
    newNode->size = realSize;
    newNode->address = newNode + 1;
    newNode->free = false;
    return (newNode);
}