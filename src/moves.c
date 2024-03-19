/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:07:40 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:10 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	int	tmp_y;

	tmp_y = game->player.y - 1;
	if (game->map[tmp_y][game->player.x] == '1')
		return ;
	else if (game->map[tmp_y][game->player.x] == 'R')
		death(game);
	game->moves_count++;
	ft_printf("Moves counter : %d\n", game->moves_count);
	game->is_moving = true;
	game->direction_player = 2;
	game->player.y--;
	exit_valid(game, false);
}

void	move_down(t_game *game)
{
	int	tmp_y;

	tmp_y = game->player.y + 1;
	if (game->map[tmp_y][game->player.x] == '1')
		return ;
	else if (game->map[tmp_y][game->player.x] == 'R')
		death(game);
	game->moves_count++;
	ft_printf("Moves counter : %d\n", game->moves_count);
	game->is_moving = true;
	game->direction_player = 3;
	game->player.y++;
	exit_valid(game, false);
}

void	move_left(t_game *game)
{
	int	tmp_x;

	tmp_x = game->player.x - 1;
	if (game->map[game->player.y][tmp_x] == '1')
		return ;
	else if (game->map[game->player.y][tmp_x] == 'R')
		death(game);
	game->moves_count++;
	ft_printf("Moves counter : %d\n", game->moves_count);
	game->is_moving = true;
	game->direction_player = 1;
	game->player.x--;
	exit_valid(game, false);
}

void	move_right(t_game *game)
{
	int	tmp_x;

	tmp_x = game->player.x + 1;
	if (game->map[game->player.y][tmp_x] == '1')
		return ;
	else if (game->map[game->player.y][tmp_x] == 'R')
		death(game);
	game->moves_count++;
	ft_printf("Moves counter : %d\n", game->moves_count);
	game->is_moving = true;
	game->direction_player = 0;
	game->player.x++;
	exit_valid(game, false);
}
