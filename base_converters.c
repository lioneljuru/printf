#include "main.h"
/**
 * convert_sbase - converts a signed long to an inputed base
 * @output: struct containing a character array
 * @num: signed long to convert
 * @flags:flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int size;
	char digit, pad = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;
	if (num >= size || num <= -size)
		ret += convert_sbase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		for (; prec > 1; prec--, wid--)
			ret += _memcpy(output, &pad, 1);
		if (NEG_FLAG == 0)
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
	}
	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(ouptut, &digit, 1);

	return (ret);
}
/**
 * convert_ubase- converts unsigned long to an inputter base
 * @output: buffer_t struct containing character array
 * @num: unsigned long to convert
 * @base: pointer to the string containing the base to convert to
 * @flags: flag modofiers
 * @wid: width modifier
 * @prec: precision modifier
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int size, ret = 1;
	char digit, pad = '0', *lead = "0x";

	for (size = o; *(base + size);)
		size++;
	if (num >= size)
		ret += convert_ubase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--)
			ret += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0)
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
		if ((flags >> 5) & 1)
			ret += _memcpy(output, lead, 2);
	}
	digit = base[(num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
