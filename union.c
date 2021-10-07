/*
	Write a program that takes two strings and displays, without doubles, the
	characters that appear in either one of the strings.
	The display will be in the order characters appear in the command line, and
	will be followed by a \n.
	If the number of arguments is not 2, the program displays \n.

*/

#include <unistd.h>

int	main(int argments, char **uni)
{
	int	i;
	int	j;
	int	used[255];

	if (argments == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (uni[i][j])
			{
				if (used[(int)uni[i][j]] == 0)
				{
					used[(int)uni[i][j]] = 1;
					write(1, &uni[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
