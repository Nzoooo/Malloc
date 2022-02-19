/*
** EPITECH PROJECT, 2022
** calloc.c
** File description:
** calloc.c
*/

#include "../include/malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *allocate = malloc(nmemb * size);
    
    if (allocate == NULL)
        return (NULL);
    allocate = memset(allocate, 0, nmemb * size);
    return (allocate);
}