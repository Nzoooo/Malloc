/*
** EPITECH PROJECT, 2022
** free.C
** File description:
** free.c
*/

#include "../include/malloc.h"

void free(void *ptr)
{
    malloc_t *tmp = allNode;

    while (tmp->allocate != ptr && tmp != NULL)
        tmp = tmp->next;
    if (tmp == NULL || tmp->free)
        return;
    tmp->free = true;
    sbrk(tmp->size * -1);
}