/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:43:32 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:51 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	disable_img_player(t_game	*game)
{
	game->img.player[0][0]->enabled = false;
	game->img.player[0][1]->enabled = false;
	game->img.player[0][2]->enabled = false;
	game->img.player[0][3]->enabled = false;
	game->img.player[1][0]->enabled = false;
	game->img.player[1][1]->enabled = false;
	game->img.player[1][2]->enabled = false;
	game->img.player[1][3]->enabled = false;
	game->img.player[2][0]->enabled = false;
	game->img.player[2][1]->enabled = false;
	game->img.player[2][2]->enabled = false;
	game->img.player[2][3]->enabled = false;
	game->img.player[3][0]->enabled = false;
	game->img.player[3][1]->enabled = false;
	game->img.player[3][2]->enabled = false;
	game->img.player[3][3]->enabled = false;
}

void	disable_img_ennemy(t_game *game)
{
	game->img.ennemy[0][0]->enabled = false;
	game->img.ennemy[0][1]->enabled = false;
	game->img.ennemy[0][2]->enabled = false;
	game->img.ennemy[0][3]->enabled = false;
	game->img.ennemy[1][0]->enabled = false;
	game->img.ennemy[1][1]->enabled = false;
	game->img.ennemy[1][2]->enabled = false;
	game->img.ennemy[1][3]->enabled = false;
}

int	ft_rand(void)
{
	static unsigned long	seed = (unsigned long)ft_rand;

	seed = seed * 1103515245 + 12345;
	return ((unsigned int)(seed / 65536) % 32768);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

bool	find_extension(char *str, char *extension)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (extension[j] != '\0')
		j++;
	if (i < j)
		return (false);
	while (j >= 0)
	{
		if (str[i] != extension[j])
			return (false);
		i--;
		j--;
	}
	return (true);
}
