/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 04:49:32 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/25 04:49:32 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_game *game, int i)
{
	int		j;
	t_block	map;
	t_image	image;

	image.wlx = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = set_block(game->map[i][j]);
			image.relative_path = map.relative_path;
			put_image(image, (j * TILE_SIZE), (i * TILE_SIZE));
			j++;
		}
		i++;
	}
}

void	check_map_dimensions(t_game game, int line_nbr)
{
	if (ft_strlen(game.map[line_nbr]) != game.size_x / TILE_SIZE
		&& line_nbr != (game.size_y / TILE_SIZE))
		error_message(RED"Error: Map is not a rectangle\n"RESET, &game);
	if (game.map[(game.size_y / TILE_SIZE)]
		&& game.map[(game.size_y / TILE_SIZE)][0] != '\0')
		error_message(RED"Error: Map invalid\n"RESET, &game);
}

void	create_floor(t_game game, int line_nbr)
{
	int		j;
	t_image	image;
	int		exit;

	exit = 0;
	image.wlx = game;
	j = 0;
	check_map_dimensions(game, line_nbr);
	while (game.map[line_nbr])
	{
		j = 0;
		while (game.map[line_nbr][j])
		{
			if (!(ft_strchr("01CEP", game.map[line_nbr][j])))
				error_message(RED"Error: Invalid object on map\n"RESET, &game);
			image.relative_path = "./img/floor.xpm";
			put_image(image, (j * TILE_SIZE), (line_nbr * TILE_SIZE));
			j++;
		}
		line_nbr++;
	}
}

void	create_map_length(char *area, t_game *game, int i)
{
	int		j;
	t_image	image;

	image.wlx = *game;
	j = 0;
	game->map[i] = (char *)malloc(sizeof(char) * (9999));
	if (!game->map[i])
		return ;
	while (area[j])
	{
		if (area[j] == '\n')
			break ;
		game->map[i][j] = area[j];
		j++;
	}
	game->map[i][j] = '\0';
	create_floor(*game, i);
	create_map(game, i);
}

void	create_map_line(t_game *game, char **argv)
{
	int		fd;
	char	*area;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (9999));
	if (!game->map)
		return ;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i <= game->size_y / TILE_SIZE)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_length(area, game, i);
		free(area);
		i++;
	}
	close(fd);
}
