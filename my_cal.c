#include "shell.h"
#include <stdlib.h>

/**
 * my_calloc - Allocates memory for an array and initializes it to zero
 * @num_elem: Number of elements in an array
 * @elem_size: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory, or NULL if unsuccessful
 */

void *my_calloc(unsigned int num_elem, unsigned int elem_size)
{
	unsigned int x;
	void *ptr = NULL;

	if (num_elem == 0 || elem_size == 0)
	{
	return (NULL);
	}

	ptr = malloc(num_elem * elem_size);
	if (ptr == NULL)
	{
	return (NULL);
	}

	for (x = 0; x < (num_elem * elem_size); x++)
	{
	*((char *)(ptr) + x) = 0;
	}
	return (ptr);
}
