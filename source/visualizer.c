#include "malloc.h"

#define ROW_LENGTH 8

int ft_strlen(char *str)
{
    if (str == NULL)
        return (0);
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void print_zone_block(t_zone zone, int id)
{
    t_metadata_block metadata = read_metadata_block_from_array(zone.mem);
    char buf[200] = {0};

    sprintf(buf, "BLOCK: %i\nsize:\t%i\nusage:\t%i/%i \n\n", id, metadata.size_of_each_block, metadata.nbr_of_used_blocks, metadata.max_nbr_of_blocks);
    write(1, buf, ft_strlen(buf));
    for (size_t b = 0; b < metadata.max_nbr_of_blocks; b++)
    {
        uint8_t new_line_needed = b != 0 && b % ROW_LENGTH == 0;
        if (new_line_needed)
            write(1, "\n", 1);
        uint32_t bit = b % 8;
        uint32_t byte = b / 8;

        const uint8_t isAlreadyUsed = get_bit(zone.mem[16 + byte], bit);
        if (isAlreadyUsed)
            write(1, "#", 1);
        else
            write(1, "_", 1);
    }
    write(1, "\n\n\n", 3);
}

void show_alloc_mem(void)
{
    write(1, "------ ALLOCATIONS ------\n", 26);
    for (int i = 0; i < storage.capacity; i++)
    {
        t_zone zone = storage.zones[i];
        if (zone.type == ZONE_TYPE_BLOCK)
            print_zone_block(zone, i);
    }
    write(1, "---------- DONE ---------\n", 26);
}