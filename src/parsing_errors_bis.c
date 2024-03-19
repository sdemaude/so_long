/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:04:42 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:31 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	rectangular_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map[0])
		error_message(game->map, 6);
	game->map_width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (game->map_width != (int)ft_strlen(game->map[i]))
			error_message(game->map, 7);
		i++;
	}
}

void	wall_surrounded(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			error_message(game->map, 6);
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			error_message(game->map, 6);
		i++;
	}
	game->map_height = i;
	i = 0;
	while (game->map[game->map_height - 1][i])
	{
		if (game->map[game->map_height - 1][i] != '1')
			error_message(game->map, 6);
		i++;
	}
}

void	invalid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'R')
				error_message(game->map, 5);
			j++;
		}
		j = 0;
		i++;
	}
}

void	doubles_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->p_counter++;
			else if (game->map[i][j] == 'E')
				game->e_counter++;
			else if (game->map[i][j] == 'R')
				game->r_counter++;
			j++;
		}
		i++;
	}
	if (game->p_counter != 1)
		error_message(game->map, 2);
	else if (game->e_counter != 1)
		error_message(game->map, 4);
	else if (game->r_counter > 1)
		error_message(game->map, 9);
}

void	mult_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->c_counter++;
			j++;
		}
		i++;
	}
	if (game->c_counter < 1)
		error_message(game->map, 3);
}
