#include "sort.h"

void merge_subarray(int *subarr, int *buffr, size_t front, size_t middle,
		size_t back);
void merge_sort_recursive(int *subarr, int *buffr, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buffr: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @middle: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarray(int *subarray, int *buffr, size_t front, size_t middle,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + front, middle - front);

	printf("[right]: ");
	print_array(subarray + middle, back - middle);

	for (i = front, j = middle; i < middle && j < back; k++)
		buffr[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < middle; i++)
		buffr[k++] = subarray[i];
	for (; j < back; j++)
		buffr[k++] = subarray[j];
	for (i = front, k = 0; i < back; i++)
		subarray[i] = buffr[k++];

	printf("[Done]: ");
	print_array(subarray + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buffr: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffr, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(subarray, buffr, front, middle);
		merge_sort_recursive(subarray, buffr, middle, back);
		merge_subarray(subarray, buffr, front, middle, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffr;

	if (array == NULL || size < 2)
		return;

	buffr = malloc(sizeof(int) * size);
	if (buffr == NULL)
		return;

	merge_sort_recursive(array, buffr, 0, size);

	free(buffr);
}
