/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:42:39 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:18:08 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_counter(t_game *game)
{
	char	*str;
	char	*nb;

	nb = ft_itoa(game->moves_count);
	str = ft_strjoin("Moves counter : ", nb);
	free(nb);
	if (game->print_count)
		mlx_delete_image(game->mlx, game->print_count);
	game->print_count = mlx_put_string(game->mlx, str, 8, 3);
	free(str);
}

void	move_img_player(t_game *game, int direction, int frame)
{
	int			i;
	int			j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (direction == 0)
				game->img.player[i][j]->instances[0].x
					= game->player_img.x + (frame * 2);
			else if (direction == 1)
				game->img.player[i][j]->instances[0].x
					= game->player_img.x - (frame * 2);
			else if (direction == 2)
				game->img.player[i][j]->instances[0].y
					= game->player_img.y - (frame * 2);
			else if (direction == 3)
				game->img.player[i][j]->instances[0].y
					= game->player_img.y + (frame * 2);
			j++;
		}
		i++;
	}
}

void	move_player(t_game *game)
{
	game->player_img.x = game->player.x * 32;
	game->player_img.y = game->player.y * 32;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_down(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_right(game);
}

void	move_img_ennemy(t_game *game, int direction, int frame)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 1)
	{
		j = 0;
		while (j <= 3)
		{
			if (direction == 0)
				game->img.ennemy[i][j]->instances[0].x
					= game->ennemy_img.x + (frame * 2);
			else if (direction == 1)
				game->img.ennemy[i][j]->instances[0].x
					= game->ennemy_img.x - (frame * 2);
			j++;
		}
		i++;
	}
}

void	move_ennemy(t_game *game)
{
	if (game->map[game->ennemy.y][game->ennemy.x - 1] == '1'
		|| game->map[game->ennemy.y][game->ennemy.x - 1] == 'C')
		game->direction_ennemy = 0;
	else if (game->map[game->ennemy.y][game->ennemy.x + 1] == '1'
		|| game->map[game->ennemy.y][game->ennemy.x + 1] == 'C')
		game->direction_ennemy = 1;
	else
		game->direction_ennemy = ft_rand() % 2;
	game->ennemy_img.x = game->ennemy.x * 32;
	if (game->direction_ennemy == 0)
	{
		game->map[game->ennemy.y][game->ennemy.x] = '0';
		game->map[game->ennemy.y][game->ennemy.x + 1] = 'R';
		game->ennemy.x += 1;
	}
	else
	{
		game->map[game->ennemy.y][game->ennemy.x] = '0';
		game->map[game->ennemy.y][game->ennemy.x - 1] = 'R';
		game->ennemy.x -= 1;
	}
	if (game->ennemy.x == game->player.x
		&& game->ennemy.y == game->player.y)
		death(game);
}
