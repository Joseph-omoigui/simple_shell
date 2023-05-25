#include "shell.h"
/**
 * _strcpy - the copies a string
 * @dest: destination
 * @src: source
 *
 * Return: pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[i] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);
}

/**
 * _strdup - multiply a string
 * @str: the string to multiply
 *
 * Return: pointer to the multiplied string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
/**
 * _puts - to prints an input string
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
}
/**
 * _putchar - writes the char c to stdout
 * @c: The char to print
 *
 * Return: 1 on success .
 * On error -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
