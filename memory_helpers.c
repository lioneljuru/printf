#include "main.h"
/**
 * _memcpy - copies n bytes from memory area src to the buffer
 * contained in a buffer_t struct
 * @output: buffer_t struct
 * @src: pointer to the memory area to copy
 * @n: number of bytes to copy
 *
 * Return: number of bytes copied
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
			(output->buffer)++;
	}
	return (n);
}
/**
 * free_buffer - frees a buffer_t struct
 * @output: the struct to free
 *
 * Return: void
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}
/**
 * init_buffer -initializes a variable of struct type buffer_t
 *
 * Return: pointer to the initialized buffer_t
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;
	
	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);
	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}
	output->start = output->buffer;
	output->len = 0;
	return (output);
}
