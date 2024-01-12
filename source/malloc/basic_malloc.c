#include <sys/mman.h>
#include <stddef.h>

#include <stdio.h> // remove after debugging


#ifndef MAP_ANONYMOUS
    #define MAP_ANONYMOUS 0x20 // cant find MAP_ANONYMOUS in sys/mman.h in this system
#endif

// version to save [size][allocatedmemory]
void *malloc(size_t size) {
	size_t *ptr = mmap(NULL, size + sizeof(size_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED) {
		return NULL;
	}
	(*ptr) = size;
	return (void *)(ptr + 1);
}

// takes [size] and frees [allocatedmemory]
void free(void *ptr) {
	size_t *realptr = (size_t *)ptr - 1;
	printf("freeing %p with size %ld\n", realptr, *realptr);
	munmap(realptr, *realptr + sizeof(size_t));
}

int main(void) {
	/**
	 * Allocation Test
	*/
	void *ptr = malloc(10);
	if (ptr == NULL) {
		return (1);
	}
	printf("ptr = %p\n", ptr);

	/**
	 * Accessing allocated memory Test
	*/
	int i = 0;
	while (i < 10) {
		((char *)ptr)[i] = i + '0';
		i++;
	}
	i = 0;
	while (i < 10) {
		printf("%c\n", ((char *)ptr)[i]);
		i++;
	}

	/**
	 * Free Test
	*/
	free(ptr);
	//free(ptr); // free error
	return (0);
}