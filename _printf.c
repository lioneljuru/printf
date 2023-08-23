#include "main.h"
/**
 * cleanup - performs cleanup operations for _printf
 * @args: va_list of arguments provided to _printf
 * @output: buffer_t struct
 *
 * Return: void
 */
void cleanup(va_list args, buffer_t *output)
{
	va_ends(args);
	write(1, output->start, output->len);
	free_buffer(output);
}
/**
 * run_printf - reads through the format string for _printf
 * @format: character string to print
 * @output: buffer_t struct containing a buffer
 * @args: va_list of arguments
 *
 * Return: number of characters stored to output
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
	
	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + i + 1, &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1, &tmp);
			len = handle_length(format + i + tmp + 1, &tmp);
			f = handle_specifiers(format + i + tmp + 1, &tmp);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}
/**
 * _printf - prints a firmatted string
 * @format: character string to print
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);
	ret = run_printf(format, args, output);
	return (ret);
}
