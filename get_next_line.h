/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:13:39 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/24 20:03:05 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

/* get_next_line_utils.c */

size_t	ft_strlen(char	*str);
char	*ft_strjoin(char *save, char *buff, char *join);
char	*ft_strchr(char *str, int c);

/* get_next_line.c*/

char	*ft_save(char *save);
char	*ft_create_line(char *start);
char	*read_file(int fd, char *save);
char	*get_next_line(int fd);

#endif