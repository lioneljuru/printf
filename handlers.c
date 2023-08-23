#include "main.h"
/**
 * handle_flags - matches with corresponding values
 * @flag: pointer to a potential string of flags
 * @index: index counter for tbe original format string
 *
 * Return: corresponding value if characters match, 0 otherwise
 */
unsigned char handle_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char ret = 0;
	flag_t flags[] = { 
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};
	
	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}
	return (ret);
}
/**
 * handle_length - match length modifiers with ther corresponding value
 * @modifier: pointer to a potential length modifier
 * @index: index counter for the original format string
 *
 * Return: corresponding value it length modifier is matched, 0 otherwise
 */
unsigned char handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}
	else if (*modifier == 'h')
	{
		(*index)++;
		return (LONG);
	}
	return (0);
}
/**
 * handle_width - matches a width modifier with its corresponding value
 * @args: va_list of arguments
 * @modifier: pointer to a potential width modifier
 * @index: index counter for the original formal string
 *
 * Return: value if width modifier is matched, 0 otherwise
 */
int handle_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier ==  '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}
		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}
/**
 * handle_precision - matchesa precision modifier with corresponding
 * value
 * @args: va_list of arguments
 * @modifier: pointer to a potential precision modifier
 * @index: index counter for original format string
 *
 * Return: its value if precision modifier is matched
 * 0, if precision modifier is empty, zero or negative
 * -1. otherwise
 */
int handle_precision(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);
	modifier++;
	(*index)++;
	if ((*modifier <= '0' || *modifier > '9') &&
			*modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}
	while ((*modifier >= '0' && *modifier <= '9') ||
			(*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}
		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}
/**
 * handle_specifiers - matches a conversion specifier with
 * a correspomding conversion funstion
 * @specifire: pointer to a potential conversion specifier
 *
 * Return: pointer to the function on success, 0 otherwise
 */
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char)
{
	int i;
	converter_t converters[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_di},
		{'i', convert_di},
		{'%', convert_percent},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};
	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}
	return (NULL);
}
