#include "main.h"

/**
 * flip_bits - returns the number of bits to flip to get from n to m
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bits_to_flip;
	unsigned int count;

	bits_to_flip = n ^ m;
	count = 0;

	while (bits_to_flip > 0)
	{
		if ((bits_to_flip & 1) == 1)
			count++;

		bits_to_flip = bits_to_flip >> 1;
	}

	return (count);
}

