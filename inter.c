/*
	Write a program that takes two strings and displays, without doubles, the
	characters that appear in both strings, in the order they appear in the first
	one.
	The display will be followed by a \n.
	If the number of arguments is not 2, the program displays \n.
 */

#include <unistd.h>

int	main(int argments, char **inter)
{
	int	i;
	int	j;
	int	used[255];

	if (argments == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (inter[i][j])
			{
				if (i == 2)
					used[inter[i][j]] = 1;
				else if (i == 1 && used[inter[i][j]] == 1)
				{
					used[inter[i][j]] = 2;
					write(1, &inter[i][j], 1);
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
