/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:09:05 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:21 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(char **map, int code)
{
	ft_putstr_fd("Map not valid : ", 2);
	if (code == 2)
		ft_putstr_fd("It must contain one player position\n", 2);
	else if (code == 3)
		ft_putstr_fd("It must contain at least one collectible\n", 2);
	else if (code == 4)
		ft_putstr_fd("It must contain one exit postion\n", 2);
	else if (code == 5)
		ft_putstr_fd("It contains a forbidden character\n", 2);
	else if (code == 6)
		ft_putstr_fd("It must be surrounded by walls\n", 2);
	else if (code == 7)
		ft_putstr_fd("It must be rectangular\n", 2);
	else if (code == 8)
		ft_putstr_fd("There is no valid path\n", 2);
	else if (code == 9)
		ft_putstr_fd("There is too much ennemies\n", 2);
	else
		ft_putstr_fd("Please try again\n", 2);
	if (map)
		free_tab(map);
	exit(EXIT_FAILURE);
}

void	valid_map(t_game *game)
{
	rectangular_map(game);
	wall_surrounded(game);
	invalid_char(game);
	doubles_char(game);
	mult_collectibles(game);
	set_object(game);
	valid_path(game);
}
