#include "shell.h"

/**
 * @str: String to be displayed
 *_eputs - Will print an input string
 * Return: Absolutely Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - displays the char c to stderr
 * @e: The char to be displayed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char e)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = e;
	return (1);
}

/**
 * _putfd - writes the character ce to given fd
 * @e: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char e, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (e == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (e != BUF_FLUSH)
		buf[i++] = e;
	return (1);
}

/**
 * _putsfd - shows an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of characters put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
