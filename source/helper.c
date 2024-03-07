#include <stdint.h>
#include <stdio.h>
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