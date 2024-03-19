/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:38:55 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:19:27 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_grass(t_game *game, int i, int j)
{
	int	r;

	r = ft_rand() % 8;
	if (r == 1)
		mlx_image_to_window(game->mlx, game->img.ground[0], j * 32, i * 32);
	else if (r == 2)
		mlx_image_to_window(game->mlx, game->img.ground[1], j * 32, i * 32);
	else if (r == 3)
		mlx_image_to_window(game->mlx, game->img.ground[2], j * 32, i * 32);
	else if (r == 4)
		mlx_image_to_window(game->mlx, game->img.ground[3], j * 32, i * 32);
	else if (r == 5)
		mlx_image_to_window(game->mlx, game->img.ground[4], j * 32, i * 32);
	else if (r == 6)
		mlx_image_to_window(game->mlx, game->img.ground[5], j * 32, i * 32);
	else if (r == 7)
		mlx_image_to_window(game->mlx, game->img.ground[6], j * 32, i * 32);
	else if (r == 0)
		mlx_image_to_window(game->mlx, game->img.ground[7], j * 32, i * 32);
}

static void	players_to_window_bis(t_game *game)
{
	mlx_image_to_window(game->mlx, game->img.player[2][0], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[2][1], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[2][2], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[2][3], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[3][0], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[3][1], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[3][2], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[3][3], game->player.x * 32,
		game->player.y * 32);
}

static void	players_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->img.player[0][0], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[0][1], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[0][2], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[0][3], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[1][0], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[1][1], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[1][2], game->player.x * 32,
		game->player.y * 32);
	mlx_image_to_window(game->mlx, game->img.player[1][3], game->player.x * 32,
		game->player.y * 32);
	players_to_window_bis(game);
	disable_img_player(game);
	game->img.player[0][0]->enabled = true;
}

static void	ennemy_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->img.ennemy[0][0],
		game->ennemy.x * 32, game->ennemy.y * 32);
	mlx_image_to_window(game->mlx, game->img.ennemy[0][1],
		game->ennemy.x * 32, game->ennemy.y * 32);
	mlx_image_to_window(game->mlx, game->img.ennemy[0][2],
		game->ennemy.x * 32, game->ennemy.y * 32);
	mlx_image_to_window(game->mlx, game->img.ennemy[0][3],
		game->ennemy.x * 32, game->ennemy.y * 32);
	mlx_image_to_window(game->mlx, game->img.ennemy[1][0],
		game->ennemy.x * 32, game->ennemy.y * 32);
	mlx_image_to_window(game->mlx, game->img.ennemy[1][1],
		game->ennemy.x * 32, game->ennemy.y * 32);
	mlx_image_to_window(game->mlx, game->img.ennemy[1][2],
		game->ennemy.x * 32, game->ennemy.y * 32);
	mlx_image_to_window(game->mlx, game->img.ennemy[1][3],
		game->ennemy.x * 32, game->ennemy.y * 32);
	disable_img_ennemy(game);
	game->img.ennemy[0][0]->enabled = true;
}

void	init_map(mlx_t *mlx, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		put_grass(game, i, j);
		while (game->map[i][j])
		{
			put_grass(game, i, j);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img.wall, j * 32, i * 32);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img.collect, j * 32,
					i * 32);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, game->img.exit, game->exit.x * 32,
		game->exit.y * 32);
	players_to_window(game);
	if (game->ennemy.x != 0 && game->ennemy.y != 0)
		ennemy_to_window(game);
}
