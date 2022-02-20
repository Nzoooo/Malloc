/*
** EPITECH PROJECT, 2022
** malloc.h
** File description:
** malloc.h
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct malloc_s {
    struct malloc_s *next;
    struct malloc_s *previous;
    size_t size;
    void *address;
    bool free;
} malloc_t;

extern malloc_t *firstNode;
extern malloc_t *lastNode;

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

malloc_t *create_node(size_t size);
malloc_t *fill_free_node(size_t size, malloc_t *freeNode);
void push_node(malloc_t *tmp, malloc_t *newNode);

size_t make_size_power_of_2(size_t size);