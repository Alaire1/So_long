/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:28:17 by akaraban          #+#    #+#             */
/*   Updated: 2023/06/14 20:11:53 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_end(t_game *game)
{
	ft_putendl_fd("-----------------------------------------------\n", 1);
	ft_putendl_fd("|    🎉🎉🎉  Congratulations!!!!!  🎉🎉🎉     |\n", 1);
	ft_putendl_fd("|    You found all collectibles and exit.     |\n", 1);
	ft_putendl_fd("|        ✓✓✓✓✓✓✓✓ You won! ✓✓✓✓✓✓✓✓           |\n", 1);
	ft_putendl_fd("-----------------------------------------------\n", 1);
	error_message("", game);
}

int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.coins++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coins != game->all_coins)
		{
			ft_putendl_fd(RED"You must collect all the coins!\n"RESET, 1);
			return (1);
		}
		game_end(game);
		return (0);
	}
	return (0);
}
