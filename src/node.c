/*
** EPITECH PROJECT, 2022
** node.c
** File description:
** node.c
*/

#include "../include/malloc.h"

void set_all_node_index()
{
    malloc_t *tmp = allNode;

    for (int newIndex = 0; tmp != NULL; newIndex++) {
        tmp->index = newIndex;
        tmp = tmp->next;
    }
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
    set_all_node_index();
    write(1, "a", 1);
    return (newNode);
}

void fill_free_node(size_t size, malloc_t *freeNode)
{
    if (freeNode->size != size) {
        freeNode->next = split_node(size, freeNode);
        freeNode->size = size;
    }
    freeNode->free = false;
}

malloc_t *fill_node(size_t size, malloc_t *lastNode)
{
    size_t realSize = 2;
    malloc_t *currentNode = NULL;

    while (realSize < size)
        realSize *= 2;
    if ((currentNode = sbrk(realSize + sizeof(struct malloc_s))) == (void *)-1)
        return (NULL);
    currentNode->next = NULL;
    currentNode->previous = lastNode;
    if (lastNode != NULL)
        currentNode->index = lastNode->index + 1;
    else
        currentNode->index = 0;
    currentNode->size = realSize;
    currentNode->address = currentNode + 1;
    currentNode->free = false;
    return (currentNode);
}