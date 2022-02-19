/*
** EPITECH PROJECT, 2022
** calloc.c
** File description:
** calloc.c
*/

#include "../include/malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *address = malloc(nmemb * size);
    
    if (address == NULL)
        return (NULL);
    address = memset(address, 0, nmemb * size);
    return (address);
}