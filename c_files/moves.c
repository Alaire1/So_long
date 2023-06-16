/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 04:43:03 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/19 04:43:03 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_move_state(t_game *game, int axis_x, int axis_y)
{
	t_image	image;

	image.relative_path = "./img/floor.xpm";
	image.wlx = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, axis_x, axis_y);
}

void	move_right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	int		moves;

	image.relative_path = "./img/player.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + TILE_SIZE;
	if ((move_check(game, (i / TILE_SIZE), (j / TILE_SIZE)) != 1))
	{
		game->player.moves++;
		moves = game->player.moves;
		ft_putnbr_col_fd(moves, 1);
		ft_putendl_fd(GREEN" Moves\n"RESET, 1);
		update_move_state(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	move_left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	int		moves;

	image.relative_path = "./img/player.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - TILE_SIZE;
	if ((move_check(game, (i / TILE_SIZE), (j / TILE_SIZE)) != 1))
	{
		game->player.moves++;
		moves = game->player.moves;
		ft_putnbr_col_fd(moves, 1);
		ft_putendl_fd(GREEN" Moves\n"RESET, 1);
		update_move_state(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	move_up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	int		moves;

	image.relative_path = "./img/player.xpm";
	image.wlx = *game;
	i = game->player.y - TILE_SIZE;
	j = game->player.x;
	if ((move_check(game, (i / TILE_SIZE), (j / TILE_SIZE)) != 1))
	{
		game->player.moves++;
		moves = game->player.moves;
		ft_putnbr_col_fd(moves, 1);
		ft_putendl_fd(GREEN" Moves\n"RESET, 1);
		update_move_state(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	move_down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	int		moves;

	image.relative_path = "./img/player.xpm";
	image.wlx = *game;
	i = game->player.y + TILE_SIZE;
	j = game->player.x;
	if ((move_check(game, (i / TILE_SIZE), (j / TILE_SIZE)) != 1))
	{
		game->player.moves++;
		moves = game->player.moves;
		ft_putnbr_col_fd(moves, 1);
		ft_putendl_fd(GREEN" Moves\n"RESET, 1);
		update_move_state(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
