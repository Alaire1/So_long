/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 04:42:10 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/19 04:42:10 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//colors
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define RESET	"\033[0m"

//keys
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53

// header files
# include "../minilibx/mlx.h"

//includes
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

// vars
# define BUFFER_SIZE 1
# define TILE_SIZE 48

typedef struct s_map
{
	int			x;
	int			y;
	int			collectibles;
	int			exit;
	char		**map;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		coins;
	int		moves;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**map;
	int			all_coins;
	int			all_players;
	int			all_exits;
	int			size_x;
	int			size_y;
	int			map_width;
	int			map_height;
	int			exit_x_val;
	int			exit_y_val;
	t_player	player;
}				t_game;

typedef struct s_image
{
	char				*relative_path;
	struct s_game		wlx;
	void				*img;
	int					img_height;
	int					img_width;
}						t_image;

typedef struct s_block
{
	char	*name;
	char	*relative_path;
}	t_block;

//color_utils.c
void	ft_putnbr_col_fd(unsigned int n, int fd);

//check_map_content.c
void	wall_check(t_game *game);
void	counting_content(t_game *game, int i, int j);
void	check_for_error(t_game *game);
void	map_items_check(t_game *game);

//path_checking.c
void	if_map_too_big(t_game *game);
void	check_spot(t_game *game, t_map *copy, int x, int y);
void	map_copying(t_game *game, t_map *copy);
void	flood(t_game *game, t_map *copy, int x, int y);
void	preparing_map_copy(t_game *game);

//path_checking_utils.c
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_map_copy(t_map *copy);
void	get_map_dimensions(t_game *game);
void	find_player_pos(t_game *game);

//game_utils.c
void	error_message(char *msg, t_game *game);
void	map_destroy(t_game	*game);
void	initialize_game_struct(t_game *game);

//get_next_line.c
int		ft_line_size(int fd);
int		ft_count_lines(int fd);
char	*get_next_line(int fd);

//image.c
void	*put_image(t_image image, int x, int y);
t_block	set_block(char name);

//key_handlers.c
int		key_check(int key_code, t_game *game);

//maps.c
void	check_map_dimensions(t_game game, int line_nbr);
void	create_map(t_game *game, int i);
void	create_floor(t_game game, int b);
void	create_map_length(char *area, t_game *game, int i);
void	create_map_line(t_game *game, char **argv);

// moves.c
void	update_move_state(t_game *game, int x, int y);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);

//moves2.c
void	game_end(t_game *game);
int		move_check(t_game *game, int i, int j);

//moving.c
int		move_check(t_game *game, int i, int j);

//utils.c
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

//utils1.c
int		ft_strlen(const char *str);

//window.c
int		destroy_window(t_game *game);
void	ft_window_size(t_game *game, char *arg);

#endif
