#include <fcntl.h>		// [man 2 open]
#include <unistd.h>		// [man 2 read]
#include <stdio.h>		// [man 3 printf]
#include <stdlib.h>	// [man free]

# define BUFFER_SIZE 2

int ft_check_eol(char *buff_res)
{
	int i;

	i = 0;
	if(buff_res != NULL){
		while(buff_res[i])
		{
			if(buff_res[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

int ft_strlen(char *s)
{
	int len;

	len = 0;
	if( s != NULL)
	{
		while(s[len] != '\0')
			len++;
	}
	return (len);
}

char *ft_strjoin(char *buff_res, char *buff)
{
	char	*new_buff;
	int		i;
	int		j;

	new_buff = malloc((ft_strlen(buff_res) + ft_strlen(buff) + 1) * sizeof(char));
	if (new_buff == NULL)
		return (NULL);
	i = 0;
	if( buff_res != NULL)
	{
		while(buff_res[i])
		{
			new_buff[i] = buff_res[i];
			i++;
		}
		free(buff_res);
	}
	j = 0;
	while(buff[j])
	{
		new_buff[i + j] = buff[j];
		j++;
	}
	new_buff[i + j] = '\0';
	return (new_buff);
}

char *ft_cuttingline_updatebuff(char *bf)
{
	char	*line;
	int		i;
	int		j;

	line = malloc( (ft_check_eol(bf) + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while(bf[i] != '\n')
	{
		line[i] = bf[i];
		i++;
	}
	j = 0;
	while(bf[i] != '\0')
	{
		bf[j] = bf[i + j + 1]; //I do not want to copy \n, j + 1.
		j++;
	}
	return (line);	
}

char *get_next_line(int fd)
{
	//static for rest
	static char	*buff_res;
	char buff	[BUFFER_SIZE + 1];
	int			bytes_readed;
	char		*line = NULL;

	bytes_readed = 0;	
	while( ft_check_eol(buff_res) == -1)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if(bytes_readed <= 0)
		{
			if(buff_res != NULL && buff_res[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			line = buff_res;
			buff_res = NULL;
			return (line);			
		}
		buff[bytes_readed] = '\0';
		//add buff to buff_res
		buff_res = ft_strjoin(buff_res, buff);
	}
	//Theres is at least one line, cut it!!!! and update buffer_res.
	line = ft_cuttingline_updatebuff(buff_res);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY, 1);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
