/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:19:30 by sdemaude          #+#    #+#             */
/*   Updated: 2024/03/02 18:19:45 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	mlx_image_t	*png_img(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		free_tab(game->map);
		ft_putstr_fd("Asset not found\n", 2);
		mlx_delete_texture(game->img.collect_tex);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

static void	init_player_texture(t_game *game)
{
	game->img.player[0][0] = png_img(game, "assets/bear/bear_r1.png");
	game->img.player[0][1] = png_img(game, "assets/bear/bear_r2.png");
	game->img.player[0][2] = png_img(game, "assets/bear/bear_r3.png");
	game->img.player[0][3] = png_img(game, "assets/bear/bear_r4.png");
	game->img.player[1][0] = png_img(game, "assets/bear/bear_l1.png");
	game->img.player[1][1] = png_img(game, "assets/bear/bear_l2.png");
	game->img.player[1][2] = png_img(game, "assets/bear/bear_l3.png");
	game->img.player[1][3] = png_img(game, "assets/bear/bear_l4.png");
	game->img.player[2][0] = png_img(game, "assets/bear/bear_t1.png");
	game->img.player[2][1] = png_img(game, "assets/bear/bear_t2.png");
	game->img.player[2][2] = png_img(game, "assets/bear/bear_t3.png");
	game->img.player[2][3] = png_img(game, "assets/bear/bear_t4.png");
	game->img.player[3][0] = png_img(game, "assets/bear/bear_d1.png");
	game->img.player[3][1] = png_img(game, "assets/bear/bear_d2.png");
	game->img.player[3][2] = png_img(game, "assets/bear/bear_d3.png");
	game->img.player[3][3] = png_img(game, "assets/bear/bear_d4.png");
}

static void	init_grass_texture(t_game *game)
{
	game->img.ground[0] = png_img(game, "assets/grass/grass_1.png");
	game->img.ground[1] = png_img(game, "assets/grass/grass_2.png");
	game->img.ground[2] = png_img(game, "assets/grass/grass_3.png");
	game->img.ground[3] = png_img(game, "assets/grass/grass_4.png");
	game->img.ground[4] = png_img(game, "assets/grass/grass_5.png");
	game->img.ground[5] = png_img(game, "assets/grass/grass_6.png");
	game->img.ground[6] = png_img(game, "assets/grass/grass_7.png");
	game->img.ground[7] = png_img(game, "assets/grass/grass_8.png");
}

static void	init_ennemy_texture(t_game *game)
{
	game->img.ennemy[0][0] = png_img(game, "assets/seagull/seagull_r1.png");
	game->img.ennemy[0][1] = png_img(game, "assets/seagull/seagull_r2.png");
	game->img.ennemy[0][2] = png_img(game, "assets/seagull/seagull_r3.png");
	game->img.ennemy[0][3] = png_img(game, "assets/seagull/seagull_r4.png");
	game->img.ennemy[1][0] = png_img(game, "assets/seagull/seagull_l1.png");
	game->img.ennemy[1][1] = png_img(game, "assets/seagull/seagull_l2.png");
	game->img.ennemy[1][2] = png_img(game, "assets/seagull/seagull_l3.png");
	game->img.ennemy[1][3] = png_img(game, "assets/seagull/seagull_l4.png");
}

void	init_texture(t_game	*game)
{
	game->img.collect_tex = mlx_load_png("assets/jam.png");
	if (!game->img.collect_tex)
	{
		free_tab(game->map);
		ft_putstr_fd("Asset not found\n", 2);
		mlx_terminate(game->mlx);
		exit(EXIT_FAILURE);
	}
	game->img.collect = mlx_texture_to_image(game->mlx, game->img.collect_tex);
	game->img.exit = png_img(game, "assets/bear_house.png");
	game->img.wall = png_img(game, "assets/tree.png");
	init_player_texture(game);
	init_grass_texture(game);
	init_ennemy_texture(game);
}
