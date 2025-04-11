/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:04:30 by maurodri          #+#    #+#             */
/*   Updated: 2025/04/10 20:17:50 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "collection/ft_arraylist.h"
#include "ft_string.h"
#include "infrastructure/config/config.h"
#include "ft_stdio.h"
#include "test_suite.h"
#include "core/game.h"
#include "core/game_init_internal.h"

/* void test_player_direction(void) */
/* { */
/* 	ft_printf("\n%s: START\n", __FUNCTION__); */

/* 	{ */
/* 		t_config_file	conf; */
/* 		config_init(1, */
/* 						(char *[]){ "./test/maps/trivial_player_north.cub", NULL}, */
/* 						&conf); */
/* 		t_game game; */
/* 		bool result = map_init(&game, &conf); */
/* 		FT_TEST(game.player. != NULL			   \ */
/* 			&& ft_arraylist_len(conf.map) == 5 \ */
/* 			&& ft_strncmp(ft_arraylist_get(conf.map, 4), "11111", sizeof("11111")) \ */
/* 					== 0, */
/* 				"when argc == 1 and filename == \"./test/maps/trivial.cub\" " */
/* 				"and the file exists expected " */
/* 				"conf.map [4] == \"11111\""); */
/* 		config_clean(&conf); */
/* 	} */
/* 	ft_printf("%s: END\n", __FUNCTION__); */
/* } */

void test_map_init(void)
{
	ft_printf("\n%s: START", __FUNCTION__);
	test_player_direction();
	ft_printf("%s: END\n", __FUNCTION__);
}
