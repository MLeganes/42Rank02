#include "get_next_line.h"

static int	ft_check_eol(char *buff_res)
{
	int	i;

	i = 0;
	if (buff_res != NULL)
	{
		while (buff_res[i] != '\0')
		{
			if (buff_res[i] == '\n')
				return (i);
			i++;
		}
		if (buff_res[i] == '\n')
			return (i);
	}
	return (-1);
}

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len] != '\0')
			len++;
	}
	return (len);
}

static char	*ft_strjoin(char *buff_res, char *buff)
{
	char	*new_buff;
	int		i;
	int		j;

	new_buff = malloc(ft_strlen(buff_res) + ft_strlen(buff) + 1);
	if (new_buff == NULL)
		return (NULL);
	i = 0;
	if (buff_res != NULL)
	{
		while (buff_res[i] != '\0')
		{
			new_buff[i] = buff_res[i];
			i++;
		}
		free(buff_res);
	}
	j = 0;
	while (buff[j] != '\0')
	{
		new_buff[i + j] = buff[j];
		j++;
	}
	new_buff[i + j] = '\0';
	return (new_buff);
}

static char	*ft_cuttingline_updatebuff(char *bf)
{
	char	*line;
	int		i;
	int		linelen;
	int		j;
	int		len;

	/*
	 * Get new line.	
	 */
	linelen = ft_check_eol(bf);
	if (bf[linelen] == '\n')
		linelen++;
	line = malloc(linelen + 1); // +1 for \0
	if (line == NULL)
		return (NULL);
	i = 0;
	while (bf[i] != '\n')
	{
		line[i] = bf[i];
		i++;
	}
	if (bf[i] == '\n')
	{
		line[i] = bf[i]; //Keep the \n
		i++;
	}
	line[i] = '\0'; //Add the \0	
	/*
	 * Update buff_res. Only move data to the begining.
	 */	
	j = 0;
	len = ft_strlen(bf);
	while (i + j <= len)
	{
		bf[j] = bf[i + j];
		j++;
	}
	bf[i + j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff_res;
	char		buff[BUFFER_SIZE + 1];
	int			bytes_readed;
	char		*line;

	bytes_readed = 0;
	while (ft_check_eol(buff_res) == -1)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed <= 0)
		{
			if (buff_res != NULL && buff_res[0] == '\0')
			{
				free(buff_res);
				return (NULL);
			}
			line = buff_res;
			buff_res = NULL;
			return (line);
		}
		buff[bytes_readed] = '\0';
		//add the fresh read to buff_res
		buff_res = ft_strjoin(buff_res, buff);
	}
	//Theres is at least one line, cut it!!!! and update buffer_res.
	line = ft_cuttingline_updatebuff(buff_res);
	return (line);
}
