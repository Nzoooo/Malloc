/*
** EPITECH PROJECT, 2022
** reallocarray.c
** File description:
** reallocarray.c
*/

#include "../include/malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    ptr = realloc(ptr, nmemb * size);
    return (ptr);
}