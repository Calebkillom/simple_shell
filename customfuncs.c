#include <stdio.h>
/**
 * strLen - calculates the length of a given string
 * @str: epresents the string variable whose length we have to find
 * Description: function that calculates length of a given string
 *
 * Return: the length of the string
 */

size_t strLen(const char *str)
{
	size_t length;

	length = 0;

	while (str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}
