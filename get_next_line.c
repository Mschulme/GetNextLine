/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:12:56 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/27 14:06:56 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*newsave;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	newsave = malloc(ft_strlen(save) - i + 1);
	if (!newsave)
	{
		free(save);
		return (NULL);
	}
	j = 0;
	i++;
	while (save[i])
		newsave[j++] = save[i++];
	newsave[j] = '\0';
	free(save);
	return (newsave);
}

char	*ft_create_line(char *save)
{
	int		i;
	char	*line;

	if (save[0] == '\0')
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *save)
{
	int		bytes_read;
	char	*buffer;
	char	*join;

	join = NULL;
	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(save, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		save = ft_strjoin(save, buffer, join);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = read_file(fd, save);
	if (save == NULL)
		return (NULL);
	line = ft_create_line(save);
	save = ft_save(save);
	return (line);
}

/*
int main(void)
{
	int		fd;
	char	*buff;
	char	path[] = "/Users/mschulme/Desktop/pokemon.txt";
	int		i = 0;

	fd = open(path, O_RDONLY);
	while(i == 0)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			i = -1;
		else 
			printf("%s", buff);
		free(buff);
	}
	close(fd);
}
*/
