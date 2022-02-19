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

    while (tmp->address != ptr && tmp != NULL)
        tmp = tmp->next;
    if (tmp == NULL || tmp->free == true)
        return;
    tmp->free = true;
    if (tmp->next == NULL) {
        sbrk(tmp->size * -1);
        tmp = NULL;
    }
}