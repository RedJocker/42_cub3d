/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:06:57 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/10 19:43:32 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ft_ctype.h"
#include "ft_memlib.h"
#include "ft_stdio.h"
#include <stdlib.h>
#include "color.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "ft_extensions.h"
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	is_invalid_args(int argc, char **argv)
{
	//TODO: validade argc and filename on arg[0] 
	return (EXIT_SUCCESS);
}

typedef struct s_config_file
{
	// TODO: include textures fields
	t_color	ceil;
	t_color	floor;

	// TODO: ? map
} t_config_file;

int parse_textures(int file_fd, t_config_file *config)
{
	char	*line;

	while (1)
	{
		line = get_next_line(file_fd);
		if (line == 0)
			return (EXIT_FAILURE);
		if (ft_is_blank(line))
		{
			// TODO: ? support multiple blank lines
			free(line);
			break ;
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

int	parse_color(char *color_line, t_color *color, bool *has_set_color)
{
	char	**split_line;
	int		has_parse_error;
	
	// andar
	color_line++;
		// assuming line does not contain \n
	while (ft_isspace(*color_line))
		color_line++;
	// split
	split_line = ft_split(color_line, ',');
	if (ft_strarr_len(split_line) != 3)
		return ((int)((long)ft_free_retnull(split_line)) + EXIT_FAILURE);
	// parseInt
	color->a = 255;
	color->r = ft_atoi_strict(&has_parse_error, split_line[0]);
	if (has_parse_error)
		return (EXIT_FAILURE);
	color->g = ft_atoi_strict(&has_parse_error, split_line[1]);
	if (has_parse_error)
		return (EXIT_FAILURE);
	color->b = ft_atoi_strict(&has_parse_error, split_line[2]);
	if (has_parse_error)
		return (EXIT_FAILURE);
	// check >=0 && <= 255
	if ((color->r < 0 || color->r > 255) \
		|| (color->g < 0 || color->g > 255) \
		|| (color->b < 0 || color->b > 255))
		return (EXIT_FAILURE);
	// set color && has_set_color
	*has_set_color = true;
	return (EXIT_SUCCESS);
}

int parse_colors(int file_fd, t_config_file *config)
{
	char	*line;
	bool	has_set_color[2];

	has_set_color[0] = false;
	has_set_color[1] = false;
	while (!has_set_color[0] || !has_set_color[1])
	{
		line = ft_chomp(get_next_line(file_fd));
		if (line == 0)
			return (EXIT_FAILURE);
		if (ft_is_blank(line))
		{
			free(line);
			break ;
		}
		if (*line == 'F' && parse_color(line, &config->floor, has_set_color))
			return (EXIT_FAILURE);
		else if (*line == 'C' && parse_color(line, &config->ceil, has_set_color + 1))
			return (EXIT_FAILURE);
		free(line);
	}
	if (!has_set_color[0] || !has_set_color[1])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_file(char *filename, t_config_file *config)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0666);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (parse_textures(fd, config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (parse_colors(fd, config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// TODO: parse_map;
	return (EXIT_SUCCESS);
}

void	config_clean(t_config_file *config)
{
	
	// TODO: clean texture filenames

}

int	config_init(int argc, char **argv, t_config_file *config)
{
	
	if (is_invalid_args(argc, argv))
		return (EXIT_FAILURE);
	if (parse_file(*argv, config))
	    return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_config_file 	config;

	if (config_init(--argc, ++argv, &config) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	mlx = mlx_init(1920, 995, "cub3d", false);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_printf("cub3d");

	config_clean(&config);
	return (EXIT_SUCCESS);
}
