#include "malloc.h"

void *alloc(size_t size)
{
    size_t *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
        return NULL;
    return ptr;
}

void dealloc(void *ptr, size_t size)
{
    if (ptr != NULL && size > 0)
    {
        munmap(ptr, size);
    }
}

void write_u32_to_array(uint8_t array[], uint32_t value)
{
    array[0] = (value >> 24) & 0xFF; // Most significant byte
    array[1] = (value >> 16) & 0xFF;
    array[2] = (value >> 8) & 0xFF;
    array[3] = value & 0xFF; // Least significant byte
}

uint32_t read_u32_from_array(const uint8_t array[])
{
    uint32_t value = 0;
    value |= (uint32_t)array[0] << 24; // Most significant byte
    value |= (uint32_t)array[1] << 16;
    value |= (uint32_t)array[2] << 8;
    value |= (uint32_t)array[3]; // Least significant byte
    return value;
}

uint8_t get_bit(uint8_t value, uint8_t pos)
{
    return ((value & (1 << (7 - pos))) != 0);
}

void activate_bit(uint8_t *ptr, uint8_t index)
{
    *ptr = *ptr | (0x1 << (0x7 - index));
}

void clear_bit(uint8_t *ptr, int bit)
{
    if (ptr == NULL)
    {
        return;
    }

    if (bit < 0 || bit > 7)
    {
        return;
    }

    uint8_t mask = ~(1 << bit);
    *ptr &= mask;
}