/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors_ter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:56:06 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:41 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void static	set_point(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		game->player.x = x;
		game->player.y = y;
	}
	else if (c == 'E')
	{
		game->exit.x = x;
		game->exit.y = y;
	}
	else if (c == 'R')
	{
		game->ennemy.x = x;
		game->ennemy.y = y;
	}
}

void	set_object(t_game *game)
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
				set_point(game, 'P', j, i);
			else if (game->map[i][j] == 'E')
				set_point(game, 'E', j, i);
			else if (game->map[i][j] == 'R')
				set_point(game, 'R', j, i);
			j++;
		}
		i++;
	}
}

static void	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'P'
		&& tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

static char	**map_dup(t_game *game)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (game->map_height + 1));
	while (game->map[i])
	{
		tab[i] = ft_strdup(game->map[i]);
		i++;
	}
	tab[game->map_height] = NULL;
	return (tab);
}

void	valid_path(t_game *game)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = map_dup(game);
	game->map_size.y = game->map_height;
	game->map_size.x = game->map_width;
	fill(tmp, game->map_size, game->player);
	while (tmp[i])
	{
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'P' || tmp[i][j] == 'C' || tmp[i][j] == 'E')
			{
				free_tab(tmp);
				error_message(game->map, 8);
			}
			j++;
		}
		j = 0;
		i++;
	}
	free_tab(tmp);
}
