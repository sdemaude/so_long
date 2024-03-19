/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:46:06 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 19:11:49 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_parser(char *path, t_game *game)
{
	int		fd;
	char	*map;
	char	*tmp;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_message(NULL, 10);
	map = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(map, line);
		free(line);
		free(map);
		map = tmp;
	}
	if (map)
		game->map = ft_split(map, '\n');
	free(map);
	close(fd);
	if (!game->map)
		error_message(NULL, 10);
}

void	ft_hook(void *param)
{
	static int		frame;
	static float	timer;
	t_game			*game;

	game = param;
	special_key_down(game);
	if (!game->is_moving)
		move_player(game);
	else
	{
		disable_img_player(game);
		game->img.player[game->direction_player][frame / 4]->enabled = true;
		move_img_player(game, game->direction_player, frame);
		timer += game->mlx->delta_time;
		frame = timer * 32;
		if (frame >= 16)
		{
			find_collectible(game);
			move_img_player(game, game->direction_player, 16);
			game->is_moving = false;
			timer = 0;
			frame = 0;
		}
	}
	print_counter(game);
}

void	ft_hook_ennemy(void *param)
{
	static int		frame;
	static float	timer_frame;
	static float	timer_move;
	t_game			*game;

	game = param;
	timer_move += game->mlx->delta_time;
	if (timer_move > 0.5)
	{
		disable_img_ennemy(game);
		if (timer_frame == 0)
			move_ennemy(game);
		game->img.ennemy[game->direction_ennemy][frame / 4]->enabled = true;
		move_img_ennemy(game, game->direction_ennemy, frame);
		timer_frame += game->mlx->delta_time;
		frame = timer_frame * 32;
		if (frame >= 16)
		{
			move_img_ennemy(game, game->direction_ennemy, 16);
			timer_frame = 0;
			frame = 0;
			timer_move = 0;
		}
	}
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width * 32, game->map_height * 32,
			"so_long", 0);
	init_texture(game);
	init_map(game->mlx, game);
	mlx_set_icon(game->mlx, game->img.collect_tex);
	mlx_delete_texture(game->img.collect_tex);
	mlx_loop_hook(game->mlx, ft_hook, game);
	if (game->r_counter != 0
		&& ((game->map[game->ennemy.y][game->ennemy.x + 1] != '1'
			&& game->map[game->ennemy.y][game->ennemy.x + 1] != 'C')
		|| (game->map[game->ennemy.y][game->ennemy.x - 1] != '1'
		&& game->map[game->ennemy.y][game->ennemy.x - 1] != 'C')))
		mlx_loop_hook(game->mlx, ft_hook_ennemy, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2 || !find_extension(argv[1], ".ber"))
	{
		ft_putstr_fd("The program needs a .ber file as parameter\n", 2);
		return (1);
	}
	map_parser(argv[1], &game);
	valid_map(&game);
	init_game(&game);
	free_tab(game.map);
	return (0);
}
