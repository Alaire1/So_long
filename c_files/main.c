/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 04:42:46 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/19 04:42:46 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		error_message(RED"Error: No map file\n"RESET, NULL);
	if (argc > 2)
		error_message(RED"Error: Too many arguments\n"RESET, NULL);
	ft_window_size(&game, argv[1]);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y,
			"Wolf_in_Wolfsburg");
	initialize_game_struct(&game);
	create_map_line(&game, argv);
	map_items_check(&game);
	preparing_map_copy(&game);
	mlx_hook(game.window, 17, 1L << 2, destroy_window, &game);
	mlx_key_hook(game.window, key_check, &game);
	mlx_loop(game.mlx);
	return (0);
}
