#include "shell.h"
/**
 * main - beggining point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 1 on error, 0 on success
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int bd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (bd)
			: "r" (bd));

	if (ac == 2)
	{
		bd = open(av[1], O_RDONLY);
		if (bd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = bd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
