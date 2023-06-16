/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 03:36:27 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/25 05:08:17 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_check(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	if (key_code == UP)
		move_up(game);
	if (key_code == RIGHT)
		move_right(game);
	if (key_code == LEFT)
		move_left(game);
	if (key_code == DOWN)
		move_down(game);
	return (0);
}
