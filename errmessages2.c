#include "shell.h"

/**
 * _erratoi - converts a string to a number
 * @p: the string to be converted
 * Return: return 0 if no numbers are found, convert number otherwise
 * -1 on error
 */
int _erratoi(char *p)
{
	int a = 0;
	unsigned long int result = 0;

	if (*p == '+')
		p++;  /* it is what its always going to be */
	for (a = 0;  p[a] != '\0'; a++)
	{
		if (p[a] >= '0' && p[a] <= '9')
		{
			result *= 10;
			result += (p[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Will print an error message
 * @info: return info structure
 * @estr: string contains specified type of error
 * Return: return 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number
 * @input: the input
 * @fd: the filedescriptor
 *
 * Return: number of chars displayed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @flags: argument flags
 * @base: base
 * @num: number
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * @buf: address of the string to modify
 *remove_comments - function replaces first instance of '#' with '\0'
 * Return: Will Always return 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}