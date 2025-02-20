/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:31:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/20 11:55:33 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/config/config.h"
#include "collection/ft_arraylist.h"
#include "infrastructure/config/config_internal.h"
#include "infrastructure/config/parse/parse_file.h"
#include "ft_string.h"
#include "utils/output.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_memlib.h"

bool	config_init(int argc, char **argv, t_config_file *config)
{
	ft_bzero(config, sizeof(t_config_file));
	if (!is_invalid_args(argc, *argv))
		return (false);
	if (!parse_file(*argv, config))
		return (false);
	return (true);
}

void	config_clean(t_config_file *config)
{
	if (config->texture_north)
		free(config->texture_north);
	if (config->texture_east)
		free(config->texture_east);
	if (config->texture_south)
		free(config->texture_south);
	if (config->texture_west)
		free(config->texture_west);
	if (config->map)
		ft_arraylist_destroy(config->map);
}

bool	is_invalid_args(int argc, char *filename)
{
	if (argc != MAX_ARG)
		return (output_ret("Error: invalid number of arguments", false));
	if (!is_invalid_extension(filename, ft_strlen(filename)))
		return (output_ret("Error: invalid extension must be .cub", false));
	// if (!is_invalid_file(filename))
	// 	return (output_ret("Error: invalid file", EXIT_FAILURE));
	return (true);
}

bool	is_invalid_extension(char *filename, size_t filename_len)
{
	const char		*ext = ".cub";
	const size_t	ext_len = ft_strlen(ext);

	if (filename_len < ext_len)
		return (false);
	if (ft_strncmp(&filename[filename_len - ext_len], ext, ext_len))
		return (false);
	return (true);
}

bool	is_invalid_file(char *filename)
{
	int32_t	fd;
	int32_t	file;
	char	buf[BUF_SIZE];
	bool	ret;

	ret = true;
	fd = open(filename, O_RDONLY, CHMOD_PERMISSION);
	if (fd <= FD_FAIL)
		ret = false;
	file = read(fd, buf, BUF_SIZE);
	close(fd);
	if (ret && \
		(!file || !(*buf == 'N' || *buf == 'S' || *buf == 'W' || *buf == 'E')))
		ret = false;
	return (ret);
}
