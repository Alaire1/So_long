/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 03:01:43 by akaraban          #+#    #+#             */
/*   Updated: 2023/06/06 04:42:40 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game_struct(t_game *game)
{
	game->all_coins = 0;
	game->all_exits = 0;
	game->player.coins = 0;
	game->player.moves = 0;
	game->all_players = 0;
}

void	error_message(char *message, t_game *game)
{
	ft_putendl_fd(message, 1);
	if (game)
		map_destroy(game);
	exit(0);
}

void	map_destroy(t_game	*game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	if (game->map)
		free(game->map);
	game->map = NULL;
}
