/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:54:43 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 19:03:28 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	mlx_image_t		*player[4][4];
	mlx_image_t		*ennemy[2][4];
	mlx_image_t		*ground[8];
	mlx_texture_t	*collect_tex;
	mlx_image_t		*collect;
	mlx_image_t		*exit;
	mlx_image_t		*wall;
}	t_image;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				map_width;
	int				map_height;
	t_point			map_size;
	t_point			player;
	t_point			player_img;
	t_point			ennemy;
	t_point			ennemy_img;
	t_point			exit;
	t_image			img;
	int				nbr_collect;
	int				p_counter;
	int				c_counter;
	int				e_counter;
	int				r_counter;
	int				direction_player;
	int				direction_ennemy;
	bool			is_moving;
	int				moves_count;
	mlx_image_t		*print_count;
}	t_game;

//GAME UTILS (UTILS)
int		ft_rand(void);
void	free_tab(char **tab);
bool	find_extension(char *str, char *extension);
void	disable_img_player(t_game *game);
void	disable_img_ennemy(t_game *game);

//PARSE THE MAP AND CHECK FOR MAP ERRORS (PARSING_ERRORS)
void	error_message(char **map, int code);
void	valid_map(t_game *game);

void	rectangular_map(t_game *game);
void	wall_surrounded(t_game *game);
void	invalid_char(t_game *game);
void	doubles_char(t_game *game);
void	mult_collectibles(t_game *game);

void	set_object(t_game *game);
void	valid_path(t_game *game);

//MAP & TEXTURE INITIALIZATION (INIT_MAP + INIT_TEXTURE)
void	init_map(mlx_t *mlx, t_game *game);

void	init_texture(t_game	*game);

//CHECK DOWN KEYS (KEY_CONTROL)
bool	key_up_down(t_game	*game);
bool	key_down_down(t_game *game);
bool	key_left_down(t_game *game);
bool	key_right_down(t_game *game);
void	special_key_down(t_game *game);

//PLAYERS MOVEMENTS (MOVES)
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//EVENTS (EVENT)
void	find_collectible(t_game *game);
void	exit_valid(t_game *game, bool cheat);
void	death(t_game *game);

//ANIMATIONS + COUNTER (ANIM)
void	print_counter(t_game *game);
void	move_player(t_game *game);
void	move_ennemy(t_game *game);
void	move_img_ennemy(t_game *game, int direction, int frame);
void	move_img_player(t_game *game, int direction, int frame);

#endif
