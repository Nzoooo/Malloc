/*
** EPITECH PROJECT, 2022
** malloc.h
** File description:
** malloc.h
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>

typedef struct malloc_s {
    malloc_t *next;
    malloc_t *previous;
    size_t size;
    void *allocate;
    int index;
    bool free;
} malloc_t;

extern malloc_t *allNode;

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

void *fill_first_node(size_t size);
void *fill_node(size_t size, malloc_t *tmp);
void *fill_free_node(size_t size, int index, malloc_t *tmp);