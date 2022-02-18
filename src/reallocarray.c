/*
** EPITECH PROJECT, 2022
** reallocarray.c
** File description:
** reallocarray.c
*/

#include <unistd.h>

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb == size)
        return (NULL);
    return (ptr);
}