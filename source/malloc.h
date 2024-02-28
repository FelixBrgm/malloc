#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h> // DEBUG

#include <stddef.h>	  // size_t
#include <sys/mman.h> // mmap + FLAGS
#include <unistd.h>	  // getpageSize()
#include <stdint.h>	  //  uint8_t

// CONFIG
#define INITIAL_ZONE_LEN 10

#define TINY_TYPE 1
#define TINY_ALLOC_SIZE 32
#define TINY_ZONE_PAGE_MLTPLR 1

#define SMALL_TYPE 2
#define SMALL_ALLOC_SIZE 128
#define SMALL_ZONE_PAGE_MLTPLR 4

#define LARGE_TYPE_FREE 254
#define LARGE_TYPE_USED 255

typedef struct s_zone
{
	uint8_t *mem;
	uint8_t type;
	size_t size;
} t_zone;

typedef struct s_storage
{
	t_zone *zones;
	size_t capacity;
	size_t index;
	int page_size;
} t_storage;

extern t_storage storage;

void *malloc(size_t size);
void free(void *ptr);

void *alloc(size_t size);
void dealloc(void *ptr, size_t size);

// Visualizer
void show_alloc_mem(void);

int add_zone(size_t size);
void *get_tiny_mem(size_t size);
void *get_large_mem(size_t size);

// Helper
uint16_t read_uint8_ts_as_uint16_t(uint8_t *ptr);
void write_uint16_t_as_uint8_ts(uint8_t *ptr, uint16_t s);

#endif