/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:21:24 by maurodri          #+#    #+#             */
/*   Updated: 2025/03/08 18:45:04 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"
#include <math.h>

t_vec2i	vec2i_scale(t_vec2i vec, int scalar)
{
	return ((t_vec2i){vec.x * scalar, vec.y * scalar});
}

t_vec2f	vec2f_scalei(t_vec2f vec, int scalar)
{
	return ((t_vec2f){vec.x * scalar, vec.y * scalar});
}

t_vec2f	vec2f_scale(t_vec2f vec, float scalar)
{
	return ((t_vec2f){vec.x * scalar, vec.y * scalar});
}

t_vec2i	vec2i_add(t_vec2i vec_a, t_vec2i vec_b)
{
	return ((t_vec2i){vec_a.x + vec_b.x, vec_a.y + vec_b.y});
}

t_vec2f	vec2i_tof(t_vec2i vec_a)
{
	return ((t_vec2f){vec_a.x, vec_a.y});
}

t_vec2i	vec2i_addf(t_vec2i vec_a, t_vec2f vec_b)
{
	return ((t_vec2i){vec_a.x + (int) vec_b.x, vec_a.y + (int) vec_b.y});
}

t_vec2f	vec2f_add(t_vec2f vec_a, t_vec2f vec_b)
{
	return ((t_vec2f){vec_a.x + vec_b.x, vec_a.y + vec_b.y});
}

t_vec2f vec2f_sub(t_vec2f vec_a, t_vec2f vec_b)
{
	return ((t_vec2f){vec_a.x - vec_b.x, vec_a.y - vec_b.y});
}

t_vec2f	vec2f_addi(t_vec2f vec_a, t_vec2i vec_b)
{
	return ((t_vec2f){vec_a.x + vec_b.x, vec_a.y + vec_b.y});
}

t_vec2i	vec2i_offset(t_vec2i vec_a, int scalar)
{
	return ((t_vec2i){vec_a.x + scalar, vec_a.y + scalar});
}

t_vec2f	vec2f_offset(t_vec2f vec_a, float scalar)
{
	return ((t_vec2f){vec_a.x + scalar, vec_a.y + scalar});
}

float	vec2f_magnitude2(t_vec2f vec_a)
{
	return ((vec_a.x * vec_a.x) + (vec_a.y * vec_a.y));
}

float	vec2f_magnitude(t_vec2f vec_a)
{
	return sqrt(vec2f_magnitude2(vec_a));
}

t_vec2f	vec2f_unit_vector(float angle)
{
	return ((t_vec2f){1.f * cosf(angle), 1.f * sinf(angle)});
}

t_vec2f	vec2f_to_unit(t_vec2f vec_a)
{
	const float	mag = vec2f_magnitude(vec_a);
	if (mag < 0.00000001f)
		return (t_vec2f){0,0};
	return (t_vec2f){vec_a.x / mag, vec_a.y / mag};
}

float vec2f_dot_product(t_vec2f vec_a, t_vec2f vec_b)
{
	return ((vec_a.x * vec_b.x) + (vec_a.y * vec_b.y));
}
