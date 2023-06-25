#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - To sort an array in ascending order
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int a, b;
	int tmp;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
