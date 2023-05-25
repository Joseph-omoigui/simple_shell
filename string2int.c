#include "shell.h"
/**
 * responsive - returns true if in a responsive mode
 * @info: struct address
 *
 * Return: 1 if on a responsive mode, 0 if not
 */
int responsive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * demlimitter - checks if character is a delimeter
 * @delimmitter: the delimeter string
 * @f: the char to check
 * Return: 1 if true, 0 if false
 */
int delimitter(char f, char *delimitter)
{
	while (*delimitter)
		if (*delimitter++ == f)
			return (1);
	return (0);
}
/**
 * _isalpha - checks for alphabetic character
 * @f: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int alpha1(int f)
{
	if ((f >= 'a' && f <= 'z') || (f >= 'A' && f <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * string2int - will convert any string to an int
 * @g: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int string2int(char *g)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; g[i] != '\0' && flag != 2; i++)
	{
		if (g[i] == '-')
			sign *= -1;

		if (g[i] >= '0' && g[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (g[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
