#include "main.h"
/**
 * convert_c - converts an argument to unsigned char
 * @args: va_list pointing to the argument to be converted
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * @len: length modifier
 * @output: bufer_t struct containing a character array
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int ret = 0;

	(void)prec;
	(void)len;

	c = va_arg(args, int);

	ret += print_width(output, ret, flags, wid);
	ret += _memcpy( output, &c, 1);
	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
/**
 * convert_percent - stores a percent sign to a buffer in a struct
 * @args: va_list pointing to the argument to be converted
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * @len: length precision
 * @output: buffer_t struct containing character arrat
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int ret = 0;

	(void)args;
	(void)prec;
	(void)len;

	ret += print_width(output, ret, flags, wid);
	ret += _memcpy(output, &percent, 1);
	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
/**
 * convert_p - converts the address for an argument to hex
 * @args: va_list pointing to the argument to be converted
 * @flags: flag modifiers
 * @wid: width modifier
 * @prec: precision modifier
 * @len: length precision
 * @output: buffer_t struct containing character arrat
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));
	flags |= 32;
	ret += convert_ubase(output, address, "0123456789abcdef",
			flags, wid, prec);
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}
