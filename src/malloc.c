/*
** EPITECH PROJECT, 2022
** malloc.c
** File description:
** malloc.c
*/

#include "../include/malloc.h"

malloc_t *firstNode = NULL;
malloc_t *lastNode = NULL;

size_t make_size_power_of_2(size_t size)
{
    size_t realSize = 2;

    while (realSize <= size)
        realSize *= 2;
    return (realSize);
}

malloc_t *find_nearest_size(malloc_t *tmp, size_t *nearestSize,
                            malloc_t *actualNode)
{
    if (*nearestSize == 0) {
        *nearestSize = tmp->size;
        return (tmp);
    }
    if (*nearestSize < tmp->size)
        return (actualNode);
    *nearestSize = tmp->size;
    return (tmp);
}

malloc_t *search_free_node(size_t size, malloc_t *tmp, malloc_t *tmp2)
{
    size_t realSize = make_size_power_of_2(size);
    size_t nearestSize = 0;
    malloc_t *findNode = NULL;

    while (tmp != NULL && tmp2 != NULL && tmp <= tmp2) {
        if (tmp->size == realSize && tmp->free == true)
            return (tmp);
        if (tmp2->size == realSize && tmp2->free == true)
            return (tmp2);
        if (tmp->size >= realSize && tmp->free == true)
            findNode = find_nearest_size(tmp, &nearestSize, findNode);
        if (tmp2->size >= realSize && tmp2->free == true)
            findNode = find_nearest_size(tmp2, &nearestSize, findNode);
        tmp = tmp->next;
        tmp2 = tmp2->previous;
    }
    return (findNode);
}

void *malloc(size_t size)
{
    malloc_t *node;

    if (size == 0)
        return (NULL);
    if ((node = search_free_node(size, firstNode, lastNode)) != NULL) {
        node = fill_free_node(size, node);
        return (node->address);
    }
    if ((node = create_node(size)) == NULL)
        return (NULL);
    lastNode = push_node(firstNode, node);
    return (node->address);
}