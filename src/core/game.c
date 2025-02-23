/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:32:41 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/24 15:24:21 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ft_memlib.h"
#include "graphic/render.h"
#include "infrastructure/config/config.h"
#include "utils/vec2.h"
#include <stdlib.h>
#include "game.h"
#include "ft_assert.h"

void	window_init(t_game *game)
{
	game->ctx.window.height = DEFAULT_HEIGHT;
	game->ctx.window.width = DEFAULT_WIDTH;
}

void	draw_background( \
	mlx_image_t *bg, t_color *ceil, t_color *floor, t_vec2i size)
{
	const int	height = size.y;
	const int	width = size.x;
	int			y;
	int			x;

	y = -1;
	while (++y < height / 2)
	{
		x = -1;
		while (++x < width)
			set_pixel(x, y, bg, ceil);
	}
	y--;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			set_pixel(x, y, bg, floor);
	}
}

bool	imgs_init(t_game *game, t_config_file *config)
{
	const int	width = game->ctx.window.width;
	const int	height = game->ctx.window.height;

	game->ctx.imgs.bg = mlx_new_image(game->mlx, width, height);
	if (game->ctx.imgs.bg == NULL)
		return (false);
	draw_background(game->ctx.imgs.bg, &config->ceil, &config->floor, \
		(t_vec2i){width, height});
	return (true);
}

bool	imgs_display_static(t_game *game)
{
	ft_assert(game->ctx.imgs.bg != NULL, "expected bg to not be null");
	if (mlx_image_to_window(game->mlx, game->ctx.imgs.bg, 0, 0) < 0)
		return (false);
	return (true);
}

bool	map_init(t_game *game, t_config_file *config)
{
	// TODO:
	(void) game;
	(void) config;
	return (true);
}

bool	textures_init(t_game *game, t_config_file *config)
{
	// TODO:
	(void) game;
	(void) config;
	return (true);
}

// TODO: move above functions to some other file

void	game_loop(t_game *game)
{
	// TODO:
	// get input
	// calculate new position
	// check colisions
	// resolve colisions
	// update positions of entities
	// render new game state
	(void) game;
}

int	game_init(t_config_file *config, t_game *out_game)
{
	ft_bzero(out_game, sizeof(t_game));
	window_init(out_game);
	out_game->mlx = mlx_init(out_game->ctx.window.width, \
		out_game->ctx.window.height, "cub3d", false);
	if (out_game->mlx == NULL)
		return (false);
	if (!map_init(out_game, config))
		return (false);
	if (!textures_init(out_game, config))
		return (false);
	if (!imgs_init(out_game, config))
		return (false);
	if (!imgs_display_static(out_game))
		return (false);
	return (true);
}

void	game_clean(t_game *game)
{
	// TODO:
	// clear textures
	// clear map
	mlx_terminate(game->mlx);
}
