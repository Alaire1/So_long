/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:13:28 by akaraban          #+#    #+#             */
/*   Updated: 2023/08/23 17:16:04 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_map_too_big(t_game *game)
{
	if (game->map_width > 50 || game->map_height > 29)
		error_message(RED"Error: Map too big\n"RESET, game);
}

void	map_copying(t_game *game, t_map *copy)
{
	int	i;

	i = -1;
	copy->map = (char **)ft_calloc(sizeof(char *), game->map_height + 1);
	if (!copy->map)
		error_message(RED"Error: map not copied\n"RESET, game);
	while (++i < game->map_height)
		copy->map[i] = ft_strdup(game->map[i]);
	copy->map[i] = NULL;
}

void	flood(t_game *game, t_map *copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (copy->map[y][x] == '1')
		return ;
	if (copy->map[y][x] == 'E')
	{
		copy->exit++;
		return;
	}
	if (game->map[y][x] == 'C')
		copy->collectibles++;
	copy->map[y][x] = '1';
	flood(game, copy, x - 1, y);
	flood(game, copy, x + 1, y);
	flood(game, copy, x, y - 1);
	flood(game, copy, x, y + 1);
}

void	preparing_map_copy(t_game *game)
{
	t_map	*copy;

	copy = (t_map *)malloc(sizeof(t_map));
	if (copy == NULL)
		return ;
	get_map_dimensions(game);
	if_map_too_big(game);
	find_player_pos(game);
	map_copying(game, copy);
	int i = 0;
	while (copy->map[i])
	{
		printf("%s\n", copy->map[i]);
		i++;
	}
	copy->collectibles = 0;
	copy->exit = 0;
	flood(game, copy, game->player.start_x, game->player.start_y);
	i = 0;
	printf("copy\n");
	while (copy->map[i])
	{
		printf("%s\n", copy->map[i]);
		i++;
	}
	printf("%i", copy->exit);
	if (copy->collectibles != game->all_coins || copy->exit < 1)
		error_message(RED"Error: Map not possible to play with \n"RESET, game);
	ft_free_map_copy(copy);
}
