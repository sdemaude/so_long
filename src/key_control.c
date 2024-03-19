/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:25:24 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:19:55 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	special_key_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_4)
		&& mlx_is_key_down(game->mlx, MLX_KEY_2)
		&& mlx_is_key_down(game->mlx, MLX_KEY_ENTER)
		&& game->player.x == game->exit.x
		&& game->player.y == game->exit.y)
		exit_valid(game, true);
}

bool	key_up_down(t_game	*game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		return (true);
	else
		return (false);
}

bool	key_down_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		return (true);
	else
		return (false);
}

bool	key_left_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		return (true);
	else
		return (false);
}

bool	key_right_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		return (true);
	else
		return (false);
}
