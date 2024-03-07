#include <stdint.h>

void write_u32_to_array(uint8_t array[], uint32_t value)
{
    array[0] = (value >> 24) & 0xFF; // Most significant byte
    array[1] = (value >> 16) & 0xFF;
    array[2] = (value >> 8) & 0xFF;
    array[3] = value & 0xFF; // Least significant byte
}