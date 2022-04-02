/*
** EPITECH PROJECT, 2022
** free.C
** File description:
** free.c
*/

#include "../include/malloc.h"

malloc_t *merge_free_node(malloc_t *node)
{
    node->size += node->next->size + sizeof(struct malloc_s);
    node->next = node->next->next;
    if (node->next != NULL)
        node->next->previous = node;
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
        if (firstNode->next == NULL) {
            sbrk(-(firstNode->size + sizeof(struct malloc_s)));
            firstNode = NULL;
        } else {
            tmp->previous->next = NULL;
            sbrk(-(tmp->size + sizeof(struct malloc_s)));
        }
    }
}