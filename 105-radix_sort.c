#include "sort.h"
<<<<<<< HEAD
#include <stdlib.h>

/**
 * init_bucket_count - resets bucket_count values to 0
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void init_bucket_count(int *bucket_count)
{
	int i;

	for (i = 0; i < 10; i++)
		bucket_count[i] = 0;
}

/**
 * build_buckets - allocates space for arrays to be held in `buckets`
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void build_buckets(int *bucket_count, int **buckets)
{
	int *bucket;
	int i;

	for (i = 0; i < 10; i++)
	{
		bucket = malloc(sizeof(int) * bucket_count[i]);
		if (!bucket)
		{
			for (; i > -1; i--)
				free(buckets[i]);
			free(buckets);
			exit(EXIT_FAILURE);
		}
		buckets[i] = bucket;
	}
	init_bucket_count(bucket_count);
}

/**
 * find_max - searches array of integers for highest value
 * @array: array of values to be searched
 * @size: number of elements in array
 * Return: largest integer stored in array
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * into_array - flattens buckets into array sorted by current digit place,
 * then prints results and frees current buckets for next pass
 * @array: array of values to be printed
 * @size: number of elements in array
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
	int i, j, k;

	/* flatten bucket members in order into array sorted by place */
	for (k = 0, i = 0; k < 10; k++)
	{
		for (j = 0; j < bucket_count[k]; j++, i++)
			array[i] = buckets[k][j];
	}
	/* print results */
	print_array(array, size);
	/* free buckets from current pass */
	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

/**
 * radix_sort - Sorts array of integers in ascending order using a Radix sort
 * alogrithm starting with the LSD, the 'least significant (1s place) digit',
 * and sorting by next digit to left. Size of `bucket_count` here determined
 * by max range of key variance (digits 0-9), other solutions may be needed for
 * much larger ranges.
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucket_count[10];
	int max, max_digits, pass, divisor, digit;
	size_t i;

	if (!array || size < 2)
		return;
	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		exit(1);
	/* find amount of places in largest element */
	max = find_max(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;
	/* one sorting pass for each place in max_digits */
	for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
	{
		init_bucket_count(bucket_count);
		/* find amount of members in each bucket */
		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			bucket_count[digit]++;
		}
		build_buckets(bucket_count, buckets);
		/* fill buckets sorting by digit at current power of 10 */
		for (i = 0; i < size; i++)
		{
			/* find digit of source element at that power of 10 */
			digit = (array[i] / divisor) % 10;
			/* place member of source array in digit's bucket */
			buckets[digit][bucket_count[digit]] = array[i];
			/* record increase in bucket fill level */
			bucket_count[digit]++;
		}
		into_array(array, size, buckets, bucket_count);
	}
	free(buckets);
=======

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
>>>>>>> aeff7afad3435b2cf2074437012bfd09269dcdbd
}
