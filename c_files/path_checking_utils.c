/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checking_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:06:06 by akaraban          #+#    #+#             */
/*   Updated: 2023/08/24 14:26:37 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;
	char	*ptr;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (ptr[len] != '\0')
		len++;
	dest = (char *)malloc(len + 1);
	if (!(dest))
		return (NULL);
	while (ptr[i] != '\0' && ptr[i] != '\n')
	{
		dest[i] = ptr[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = (char *)malloc(nmemb * size);
	if (memory == NULL)
		return (0);
	while (i < nmemb * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

void	ft_free_map_copy(t_map *copy)
{
	int	i;

	if (copy == NULL)
		return ;
	if (copy->map != NULL)
	{
		i = 0;
		while (copy->map[i] != NULL)
		{
			free(copy->map[i]);
			i++;
		}
		free(copy->map);
	}
	free(copy);
}

void	get_map_dimensions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != 0)
	{
		while (game->map[i][j] != 0)
		{
			j++;
		}
		i++;
	}
	game->map_width = j ;
	game->map_height = i - 1;
}

void	find_player_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != 0)
	{
		x = 0;
		while (game->map[y][x] != 0)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.start_x = x;
				game->player.start_y = y;
			}
			x++;
		}
		y++;
	}
}
