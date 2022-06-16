/*
** EPITECH PROJECT, 2022
** calloc.c
** File description:
** calloc.c
*/

#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *address = NULL;

    address = malloc(nmemb * size);
    if (!address)
        return (NULL);
    address = memset(address, 0, nmemb * size);
    return (address);
}