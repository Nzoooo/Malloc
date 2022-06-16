/*
** EPITECH PROJECT, 2022
** malloc.h
** File description:
** malloc.h
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
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

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

malloc_t *create_node(size_t size);
malloc_t *fill_free_node(malloc_t *freeNode, size_t size);
malloc_t *push_node(malloc_t *newNode);
size_t search_highest_free_size(malloc_t *tmp);

size_t make_size_power_of_2(size_t size);
size_t make_size_page_multiple(size_t size);