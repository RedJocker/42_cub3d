/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:16:09 by maurodri          #+#    #+#             */
/*   Updated: 2025/03/08 21:26:16 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MINI_H
# define DRAW_MINI_H

# include "core/game.h"
# include "graphic/grid.h"

typedef struct s_mini_args
{
	t_vec2f	grid_pos;
	int		block_size;
	t_vec2f	offset;
}	t_mini_args;

void	draw_mini_map(t_game *game, int block_size, t_vec2f offset);
void	draw_mini_ray_dotgrid(t_game *game, t_mini_args m, float angle);
#endif
