#include "main.h"
/**
 * print_width - stored leading spaces to a buffer for a width modifier
 * @output: struct containing character array
 * @printed: current number of characters already printed to output
 * @flags: flag modifiers
 * @wid: width modifier
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}
	return (ret);
}
/**
 * print_string_width - stores leading spces to abuffer for width modifier
 * @output: struct containing a character array
 * @flags: flag modifiers
 * @wid: width modifiers
 * @pre: precision modifiers
 * @size: the size of the string
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}
	return (ret);
}
/**
 * print_neg_width - stores trailing spaces to a buffer for a '-' flag
 * @output: struct containing character array
 * @printed: current number of bytes stored to output
 * for a given specifier
 * @flags: flag modifiers
 * @wid: width modifier
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}
	return (ret);
}
