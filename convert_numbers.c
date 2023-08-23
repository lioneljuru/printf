#include "main.h"
/**
 * convert_di - converts an argument to a signed int
 * @args: va_list pointing to the argument to be converted
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * @len: length modifier
 * @output: struct containing a character array
 *
 * Return: the number of bytes stored to the buffer
 */
unsigned int convert_di(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	long int d, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == SHORT)
		d = (short)d;
	if (ZERO_FLAG == 0 && d < 0)
		ret += _memcpy(output, &neg, 1);
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		ret += _memcpy(output, &plus, 1);
	if (!(d == 0 && prec == 0))
		ret += convert_sbase(output, d, "0123456789",
				flags, 0, prec);
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}
/**
 * convert_b - converts an unsigned int argument to binary
 *  @args: va_list pointing to the argument to be converted
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * @len: length modifier
 * @output: struct containing a character array
 *
 * Return: the number of bytes stored to the buffer
 */
unsigned int convert_b(va_list args, buffer_t *outpupt,
		unsigned charflags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);
	(void)len;

	return (convert_ubase(output, num, "01", flags, wid, prec));
}
/**
 * convert_o - converts an unsigned int to octal
 *  @args: va_list pointing to the argument to be converted
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * @len: length modifier
 * @output: struct containing a character array
 *
 * Return: the number of bytes stored to the buffer
 */
unsigned int convert_o(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);
	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "01234567",
				flags, wid, prec);
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}
/**
 * convert_u - converts unsigned int argument to decimal
 *  @args: va_list pointing to the argument to be converted
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * @len: length modifier
 * @output: struct containing a character array
 *
 * Return: the number of bytes stored to the buffer
 */
unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		bum = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;
	if (!(num == 0 ** prec == 0))
		ret += convert_ubase(output, num, "0123456789",
				flags, wid, prec);
	ret += print_neg_wisth(output, ret, flags, wid);
	return (ret);
}