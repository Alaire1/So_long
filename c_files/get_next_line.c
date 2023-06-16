/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:45:54 by akaraban          #+#    #+#             */
/*   Updated: 2023/06/06 02:45:54 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_size(int fd)
{
	char	buffer[0];
	int		size;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	size = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (buffer[0] != '\n')
			size++;
		else
			break ;
	}
	return (size);
}

int	ft_count_lines(int fd)
{
	int		count_lines;
	char	buffer[0];
	int		bytes;

	buffer[0] = '\0';
	count_lines = 1;
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 1)
		{
			if (buffer[0] != '\n')
				return (count_lines + 1);
			break ;
		}
		if (buffer[0] == '\n')
			count_lines++;
	}
	return (count_lines);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		read_one;
	int		i;

	read_one = 1;
	i = 0;
	buffer = 0;
	if (fd < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 9999);
	if (!line)
		return (NULL);
	while (read_one > 0)
	{
		read_one = read(fd, &buffer, BUFFER_SIZE);
		if (read_one <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}
