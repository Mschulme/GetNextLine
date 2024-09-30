/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:13:07 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/24 20:04:04 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (NULL);
	if (c == 0)
		return (&str[ft_strlen(str)]);
	while (*str)
	{
		if (*str++ == (char) c)
			return (str);
	}
	return (NULL);
}

char	*ft_strjoin(char *save, char *buff, char *join)
{
	int	i;
	int	j;

	if (!save)
	{
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	join = malloc(ft_strlen(save) + ft_strlen(buff) + 1);
	if (!join)
	{
		free(save);
		return (NULL);
	}
	i = -1;
	while (save[i++ + 1] != 0)
		join[i] = save[i];
	j = 0;
	while (buff[j] != 0)
		join[i++] = buff[j++];
	join[i] = 0;
	free(save);
	return (join);
}
