#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h> // DEBUG

#include <stddef.h>	  // size_t
#include <sys/mman.h> // mmap + FLAGS
#include <unistd.h>	  // getpageSize()
#include <stdint.h>	  //  uint8_t

#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS 0x20 // cant find MAP_ANONYMOUS in sys/mman.h when running on 42MacOs
#endif

#define BLOCK_SIZES_LEN 1
#define BLOCK_SIZES \
	{               \
		32          \
	} // This have to be in ascending order to function effeciently

#define MIN_BLOCKS_IN_ZONE 100

// Zone types
#define ZONE_TYPE_SINGLE (uint8_t)0
#define ZONE_TYPE_BLOCK (uint8_t)1

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
	uint32_t page_size;
	uint16_t block_sizes[BLOCK_SIZES_LEN];
} t_storage;

extern t_storage storage;

void *malloc(size_t size);
void free(void *ptr);

void *alloc(size_t size);
void dealloc(void *ptr, size_t size);

void *get_memory(size_t size, uint8_t block_type);

int add_zone(size_t size);

// Helper
void write_u32_to_array(uint8_t array[], uint32_t value);

#endif