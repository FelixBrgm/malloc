#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h> // DEBUG

#include <stddef.h>	  // size_t
#include <sys/mman.h> // mmap + FLAGS
#include <unistd.h>	  // getpageSize()
#include <stdint.h>	  //  uint8_t

// CONFIG
#define INITIAL_ZONE_LEN 10
#define ZONE_DIV_TINY 16
#define ZONE_DIV_SMALL 4

// Enums
enum e_zone_type
{
	ZONE_TYPE_DYNAMIC = (unsigned char)0,
	ZONE_TYPE_BLOCK_1 = (unsigned char)1,
	ZONE_TYPE_BLOCK_2 = (unsigned char)2,
	ZONE_TYPE_BLOCK_4 = (unsigned char)4,
	ZONE_TYPE_BLOCK_8 = (unsigned char)8,
	ZONE_TYPE_WHOLE = (unsigned char)255
};

typedef struct s_zone
{
	uint8_t *mem;
	uint8_t type;
	short widest_gap;
	short size;
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

void show_alloc_mem(void);

// Malloc helpers
void *alloc(size_t size);
uint8_t get_type_from_size(size_t);
void *create_dynamic_zone_alloc(size_t size);

void write_short_as_chars(uint8_t *ptr, short s);
short read_chars_as_short(uint8_t *ptr);

#endif