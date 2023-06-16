/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:13:27 by akaraban          #+#    #+#             */
/*   Updated: 2023/06/13 16:27:34 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->size_y / TILE_SIZE))
	{
		x = 0;
		while (x < (game->size_x / TILE_SIZE))
		{
			if ((y == (game->size_y / TILE_SIZE - 1)
					|| x == (game->size_x / TILE_SIZE - 1))
				&& game->map[y][x] != '1')
				error_message(RED"Error: Invalid walls\n"RESET, game);
			else if ((y == 0 || x == 0) && game->map[y][x] != '1')
				error_message(RED"Error: Invalid walls\n"RESET, game);
			x++;
		}
		y++;
	}
}

void	counting_content(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
		game->all_coins++;
	if (game->map[i][j] == 'P')
	{
		game->player.x = j * TILE_SIZE;
		game->player.y = i * TILE_SIZE;
		game->all_players++;
	}
	if (game->map[i][j] == 'E')
		game->all_exits++;
}

void	check_for_error(t_game *game)
{
	if (game->all_players > 1)
		error_message(RED"Error: Only one character allowed\n"RESET, game);
	if (game->all_players == 0)
		error_message(RED"Error: No player on the map\n"RESET, game);
	if (game->all_coins == 0)
		error_message(RED"Error: No coins on the map\n"RESET, game);
	if (game->all_exits > 1)
		error_message(RED"Error: Too many exits\n"RESET, game);
	if (game->all_exits == 0)
		error_message(RED"Error: No exit on the map\n"RESET, game);
}

void	map_items_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			counting_content(game, i, j);
			j++;
		}
		i++;
	}
	check_for_error(game);
	wall_check(game);
}
