/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:15:11 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:18:19 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	death(t_game *game)
{
	free_tab(game->map);
	ft_printf("\x1B[31;5mYou died...\n\x1B[0m");
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

void	exit_valid(t_game *game, bool cheat)
{
	if ((game->map[game->player.y][game->player.x] == 'E'
		&& game->c_counter == 0) || cheat == true)
	{
		free_tab(game->map);
		ft_printf("\x1B[33;5mCongrats, you won !\n\x1B[0m");
		if (cheat == true || game->moves_count == 42)
			ft_printf("\x1B[36;5mTotal moves : 42 !\n\x1B[0m");
		else
			ft_printf("\x1B[34mTotal moves : %d\n\x1B[0m", game->moves_count);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	find_collectible(t_game *game)
{
	int	i;
	int	j;
	int	inst;

	i = 0;
	inst = 0;
	while (i <= game->player.y)
	{
		j = 0;
		while (game->map[i][j] && (i != game->player.y || j != game->player.x))
		{
			if (game->map[i][j] == 'C' || game->map[i][j] == 'G')
				inst++;
			j++;
		}
		i++;
	}
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->c_counter--;
		game->map[game->player.y][game->player.x] = 'G';
		ft_printf("\x1B[35;3mYou got jam !\n\x1B[0m");
		game->img.collect->instances[inst].enabled = false;
	}
}
