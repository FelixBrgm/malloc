#include "malloc.h"

char get_type_from_size(size_t size)
{
	char type = 0;

	if (size == 1)
		type = ZONE_TYPE_BLOCK_1;
	else if (size == 2)
		type = ZONE_TYPE_BLOCK_2;
	else if (size <= 4)
		type = ZONE_TYPE_BLOCK_4;
	else if (size <= 8)
		type = ZONE_TYPE_BLOCK_8;
	else if (size < storage.page_size)
		type = ZONE_TYPE_DYNAMIC;
	else
		type = ZONE_TYPE_WHOLE;

	return type;
}

void write_short_as_chars(char *ptr, short s)
{
	if (ptr == NULL)
		return;
	ptr[0] = s >> 8;
	ptr[1] = s & 0xFF;
}
short read_chars_as_short(char *ptr)
{
	if (ptr == NULL)
		return 0;
	short res = 0;
	res = res | ptr[0] << 8;
	res = res | ptr[1];

	return (res);
}

void create_dynamic_alloc_header(char *ptr, short nxt, short count)
{
	if (ptr == NULL)
		return;
	write_short_as_chars(ptr, nxt);
	write_short_as_chars(ptr + 2, count);
}

void *create_dynamic_zone_alloc(size_t needed_size)
{
	// First fit practice
	void *res = NULL;

	// Check if there is some space
	needed_size = needed_size + 4; // 4 Bytes is the size of the next pointer and the counter 2 + 2
	int i = 0;
	while (i < storage.index)
	{
		short best_gap = 0;
		t_zone *zone = storage.zones + i;
		i++;

		if (storage.zones[i].type != ZONE_TYPE_DYNAMIC)
			continue;

		printf("HERE index: %i| %p \n",i, zone->mem);
		short nxt = 0;
		nxt = zone->mem[0];
		nxt = (nxt << 8) | zone->mem[1];

		// Check to the first allocation if enough
		if (nxt == 0 || (nxt > 0 && (nxt - 2) > needed_size))
		{
			write_short_as_chars(zone->mem, 2); // Set old start ptr to new allocation
			create_dynamic_alloc_header(zone->mem + 2, nxt, needed_size - 4);
			res = zone->mem + 2 + 4;
			break;
		}
		// loop till nxt is 0 again

		// check till the end of the range
	}

	// Create some new zones
	return res;
}