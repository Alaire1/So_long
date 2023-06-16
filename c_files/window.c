/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 04:43:30 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/19 04:43:30 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	error_message("The game has been closed\n", game);
	map_destroy(game);
	exit(0);
}

void	ft_window_size(t_game *game, char *arg)
{
	int	fd;

	if (ft_strnstr(arg, ".ber", ft_strlen(arg)) == NULL)
		error_message(RED"Error: Invalid map file\n"RESET, NULL);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		error_message(RED"Error: File cannot be opened\n"RESET, NULL);
		game->size_x = (ft_line_size(fd) * TILE_SIZE);
		game->size_y = (ft_count_lines(fd) * TILE_SIZE);
}
