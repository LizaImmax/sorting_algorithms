#include "sort.h"

/**
 * selection_sort - sorts an array by using selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int a, b, min;

	register int tmp;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min])
				min = b;
		}
		tmp = array[a];
		array[a] = array[min];
		array[min] = tmp;
		if (a != min)
			print_array(array, size);
	}
}
