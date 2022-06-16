/*
** EPITECH PROJECT, 2022
** free.C
** File description:
** free.c
*/

#include "malloc.h"

malloc_t *merge_frees_node(malloc_t *node)
{
    if (node->next && node->next->free) {
        node->size += node->next->size + sizeof(malloc_t);
        node->next = node->next->next;
        if (node->next)
            node->next->previous = node;
    }
    if (node->previous && node->previous->free) {
        node->previous->size += node->previous->next->size + sizeof(malloc_t);
        node->previous->next = node->previous->next->next;
        if (node->previous->next)
            node->previous->next->previous = node->previous;
        return (node->previous);
    }
    return (node);
}

void free(void *ptr)
{
    malloc_t *tmp;

    if (ptr && ptr >= (void *)firstNode && ptr <= sbrk(0)) {
        tmp = (malloc_t *)ptr - 1;
        if (tmp->address != ptr)
            return;
        tmp->free = true;
        tmp = merge_frees_node(tmp);
        if (!tmp->next) {
            tmp->previous->next = NULL;
            sbrk(-make_size_page_multiple(tmp->size + sizeof(malloc_t)));
        }
    }
}
