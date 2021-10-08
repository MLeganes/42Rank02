#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("gnl-files/nl", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
