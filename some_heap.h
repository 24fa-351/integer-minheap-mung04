
#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>

// a min heap

typedef unsigned long long heap_key_t;
// typedef void* heap_value_t;
#define HEAP_KEY_FORMAT "%llu"

typedef union heap_val {
    unsigned long long as_int;
    void *as_ptr;
} heap_value_t;

typedef struct {
    heap_key_t key;
    heap_value_t value;
} heap_node_t;

typedef struct {
    heap_node_t *data;
    int size;
    int capacity;
} heap_t;

heap_t *heap_create(int capacity) {
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->capacity = capacity;
    heap->size = 0;
    heap->data = (heap_node_t*)malloc(sizeof(heap_node_t) * capacity);
    return heap;
};

void heap_free(heap_t *heap) {
    free(heap);
};

unsigned int heap_size(heap_t *heap) {
    return heap->size;
};

void heap_insert(heap_t *heap, heap_key_t key, heap_value_t data) {
    if (heap->size == heap->capacity) {
        printf("Heap is full.\n");
        return;
    }

    heap->size++;
};

heap_value_t heap_remove_min(heap_t *heap) {
    heap->size--;
    heap_node_t root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    return heap->data[0].value;
};

void heap_print(heap_t *heap) {
    FILE *output_file = fopen("int_minheap_output.txt", "w");

    for (int idx = 0; idx < heap->size; idx++) {
        fprintf(output_file, "%llu ", heap->data[idx].value.as_int);
    }

    fclose(output_file);
};

#endif
