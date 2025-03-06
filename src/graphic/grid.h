/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:55:19 by maurodri          #+#    #+#             */
/*   Updated: 2025/03/06 19:41:24 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include "core/game.h"
# include "utils/vec2.h"

typedef enum e_direction
{
	CENTER,
	NORTH,
	EAST,
	WEST,
	SOUTH
}	t_direction;

typedef struct s_grid_entity
{
	char		type;
	t_direction	direction;
}	t_grid_entity;

t_grid_entity	grid_entity(\
	const t_chart *chart, const t_vec2f *grid_pos, const t_vec2f *unity);
t_vec2f			grid_next_border(t_vec2f grid_pos, float angle, t_vec2f unity);
t_vec2f			grid_pos_to_screen_pos(\
	t_vec2f grid_pos, float block_size, t_vec2f offset);

#endif
