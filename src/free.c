/*
** EPITECH PROJECT, 2022
** free.C
** File description:
** free.c
*/

#include "../include/malloc.h"

malloc_t *merge_free_node(malloc_t *node)
{
    malloc_t *nextNode = node->next;
    node->size += nextNode->size + sizeof(struct malloc_s);
    if (nextNode->next != NULL)
        nextNode->next->previous = node;
    nextNode = nextNode->next;
    return (node);
}

void free(void *ptr)
{
    malloc_t *tmp;

    if (ptr == NULL || ptr < firstNode->address || ptr > sbrk(0))
        return;
    tmp = (malloc_t *)ptr - 1;
    tmp->free = true;
    if (tmp->next != NULL && tmp->next->free == true)
        tmp = merge_free_node(tmp);
    if (tmp->previous != NULL && tmp->previous->free == true)
        tmp = merge_free_node(tmp->previous);
    if (tmp->next == NULL) {
        tmp->previous->next = NULL;
        sbrk(-(tmp->size + sizeof(struct malloc_s)));
    }
}