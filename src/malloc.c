/*
** EPITECH PROJECT, 2022
** malloc.c
** File description:
** malloc.c
*/

#include "malloc.h"

void split_node(size_t size, malloc_t *node);

malloc_t *firstNode = NULL;

size_t make_size_page_multiple(size_t size)
{
    size_t pageMultipleSize = 2 * getpagesize();

    while (pageMultipleSize <= size)
        pageMultipleSize *= 2;
    return (pageMultipleSize);
}

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

malloc_t *search_free_node(size_t size, malloc_t *tmp)
{
    size_t realSize = make_size_power_of_2(size);
    size_t nearestSize = 0;
    malloc_t *findNode = NULL;

    while (tmp) {
        if (tmp->size == realSize && tmp->free == true)
            return (tmp);
        if (tmp->size >= realSize && tmp->free == true)
            findNode = find_nearest_size(tmp, &nearestSize, findNode);
        tmp = tmp->next;
    }
    return (findNode);
}

void *malloc(size_t size)
{
    malloc_t *node;

    node = search_free_node(size, firstNode);
    if (node) {
        node = fill_free_node(node, size);
        return (node->address);
    }
    node = create_node(size);
    if (!node)
        return (NULL);
    push_node(node);
    return (node->address);
}