/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:04:30 by maurodri          #+#    #+#             */
/*   Updated: 2025/04/22 00:21:34 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memlib.h"
#include "ft_string.h"
#include "infrastructure/config/config.h"
#include "ft_stdio.h"
#include "test_suite.h"
#include "core/game.h"
#include "core/game_init_internal.h"

void test_invalid_mapline()
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1, \
					(char *[]){\
						"./test/maps/invalid_non_blank_snd_separator.cub", \
						NULL}, \
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/invalid_non_blank_snd_separator.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(result == false,
				"when filename == \"./test/maps/invalid_non_blank_snd_separator.cub\" "
				"expected "
				"result == false");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	ft_printf("%s: END\n", __FUNCTION__);
}

void test_player_direction(void)
{
	// TODO: Ensure clean game on valid cases
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_player_north.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_north.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.angle - ANGLE_NORTH < 0.0001,
				"when filename == \"./test/maps/trivial_player_north.cub\" "
				"expected "
				"game.manager.player.loc.angle == ANGLE_NORTH");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_player_east.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_east.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.angle - ANGLE_EAST < 0.0001,
				"when filename == \"./test/maps/trivial_player_east.cub\" "
				"expected "
				"game.manager.player.loc.angle == ANGLE_EAST");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_player_south.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_south.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.angle - ANGLE_SOUTH < 0.0001,
				"when filename == \"./test/maps/trivial_player_south.cub\" "
				"expected "
				"game.manager.player.loc.angle == ANGLE_SOUTH");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_player_west.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_west.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.angle - ANGLE_WEST < 0.0001,
				"when filename == \"./test/maps/trivial_player_west.cub\" "
				"expected "
				"game.manager.player.loc.angle == ANGLE_WEST");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	ft_printf("%s: END\n", __FUNCTION__);
}

void test_player_pos(void)
{
	// TODO: Ensure clean game on valid cases
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_player_pos_1_1.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_pos_1_1.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.pos.x == 1.5f,
				"when filename == \"./test/maps/trivial_player_pos_1_1.cub\" "
				"expected "
				"game.manager.player.loc.pos.x == 1.5f");
		FT_TEST(game.manager.player.loc.pos.y == 1.5f,
				"when filename == \"./test/maps/trivial_player_pos_1_1.cub\" "
				"expected "
				"game.manager.player.loc.pos.y == 1.5f");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	{
		t_config_file	conf;
		int res_config =  config_init(1,
					(char *[]){ "./test/maps/trivial_player_pos_1_2.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_pos_1_2.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.pos.x == 1.5f,
				"when filename == \"./test/maps/trivial_player_pos_1_2.cub\" "
				"expected "
				"game.manager.player.loc.pos.x == 1.5f");
		FT_TEST(game.manager.player.loc.pos.y == 2.5f,
				"when filename == \"./test/maps/trivial_player_pos_1_2.cub\" "
				"expected "
				"game.manager.player.loc.pos.y == 2.5f");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_player_pos_2_1.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_pos_2_1.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.pos.x == 2.5f,
				"when filename == \"./test/maps/trivial_player_pos_2_1.cub\" "
				"expected "
				"game.manager.player.loc.pos.x == 2.5f");
		FT_TEST(game.manager.player.loc.pos.y == 1.5f,
				"when filename == \"./test/maps/trivial_player_pos_2_1.cub\" "
				"expected "
				"game.manager.player.loc.pos.y == 1.5f");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	{
		t_config_file	conf;
		int res_config =  config_init(1,
					(char *[]){ "./test/maps/trivial_player_pos_2_2.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_player_pos_2_2.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.player.loc.pos.x == 2.5f,
				"when filename == \"./test/maps/trivial_player_pos_2_2.cub\" "
				"expected "
				"game.manager.player.loc.pos.x == 2.5f");
		FT_TEST(game.manager.player.loc.pos.y == 2.5f,
				"when filename == \"./test/maps/trivial_player_pos_2_2.cub\" "
				"expected "
				"game.manager.player.loc.pos.y == 2.5f");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	ft_printf("%s: END\n", __FUNCTION__);
}

void test_chart_trivial(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.chart.dimen.x == 5,
				"when filename == \"./test/maps/trivial.cub\" "
				"expected "
				"game.manager.chart.dimen.x == 5");
		FT_TEST(game.manager.chart.dimen.y == 5,
				"when filename == \"./test/maps/trivial.cub\" "
				"expected "
				"game.manager.chart.dimen.y == 5");
		FT_TEST(ft_strncmp(game.manager.chart.buffer,
							"11111"
							"10001"
							"10001"
							"10001"
							"11111"
						   ,(5 * 5)) == 0,
				"when filename == \"./test/maps/trivial.cub\" "
				"expected "
				"ft_strncmp(game.manager.chart.buffer,"
							"11111"
							"10001"
							"10001"
							"10001"
							"11111"
							",(5 * 5) == 0)");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}

	ft_printf("%s: END\n", __FUNCTION__);
}

void test_chart_trivial_left_pad(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_left_pad.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_left_pad.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.chart.dimen.x == 5,
				"when filename == \"./test/maps/trivial_left_pad.cub\" "
				"expected "
				"game.manager.chart.dimen.x == 5");
		FT_TEST(game.manager.chart.dimen.y == 5,
				"when filename == \"./test/maps/trivial_left_pad.cub\" "
				"expected "
				"game.manager.chart.dimen.y == 5");
		FT_TEST(ft_strncmp(game.manager.chart.buffer,
							"11111"
							"10001"
							"10001"
							"10001"
							"11111"
							,(5 * 5)) == 0,
				"when filename == \"./test/maps/trivial_left_pad.cub\" "
				"expected "
				"ft_strncmp(game.manager.chart.buffer,"
							"11111"
							"10001"
							"10001"
							"10001"
							"11111"
							",(5 * 5) == 0)");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}

	ft_printf("%s: END\n", __FUNCTION__);
}

void test_chart_trivial_trailing_spaces(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/trivial_trailing_spaces.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/trivial_trailing_spaces.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.chart.dimen.x == 5,
				"when filename == \"./test/maps/trivial_trailing_spaces.cub\" "
				"expected "
				"game.manager.chart.dimen.x == 5");
		FT_TEST(game.manager.chart.dimen.y == 5,
				"when filename == \"./test/maps/trivial_trailing_spaces.cub\" "
				"expected "
				"game.manager.chart.dimen.y == 5");
		FT_TEST(ft_strncmp(game.manager.chart.buffer,
							"11111"
							"10001"
							"10001"
							"10001"
							"11111"
							,(5 * 5)) == 0,
				"when filename == \"./test/maps/trivial_trailing_spaces.cub\" "
				"expected "
				"ft_strncmp(game.manager.chart.buffer,"
							"11111"
							"10001"
							"10001"
							"10001"
							"11111"
							",(5 * 5) == 0)");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}

	ft_printf("%s: END\n", __FUNCTION__);
}

void test_chart_diamond(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/diamond.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/diamond.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.chart.dimen.x == 7,
				"when filename == \"./test/maps/diamond.cub\" "
				"expected "
				"game.manager.chart.dimen.x == 7");
		FT_TEST(game.manager.chart.dimen.y == 11,
				"when filename == \"./test/maps/diamond.cub\" "
				"expected "
				"game.manager.chart.dimen.y == 11");
		FT_TEST(ft_strncmp(game.manager.chart.buffer,
								"   1   "
								"  101  "
								" 10001 "
								"1000001"
								"1000001"
								"1010101"
								"1001001"
								"1010101"
								" 10001 "
								"  101  "
								"   1   "
							,(7 * 11)) == 0,
				"when filename == \"./test/maps/diamond.cub\" "
				"expected "
				"ft_strncmp(game.manager.chart.buffer,"
								"   1   "
								"  101  "
								" 10001 "
								"1000001"
								"1000001"
								"1010101"
								"1001001"
								"1010101"
								" 10001 "
								"  101  "
								"   1   "
							",(7 * 11)) == 0");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}

	ft_printf("%s: END\n", __FUNCTION__);
}

void test_chart_diamond_leftpad(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/diamond_leftpad.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/diamond_leftpad.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.chart.dimen.x == 7,
				"when filename == \"./test/maps/diamond_leftpad.cub\" "
				"expected "
				"game.manager.chart.dimen.x == 7");
		FT_TEST(game.manager.chart.dimen.y == 11,
				"when filename == \"./test/maps/diamond_leftpad.cub\" "
				"expected "
				"game.manager.chart.dimen.y == 11");
		FT_TEST(ft_strncmp(game.manager.chart.buffer,
								"   1   "
								"  101  "
								" 10001 "
								"1000001"
								"1000001"
								"1010101"
								"1001001"
								"1010101"
								" 10001 "
								"  101  "
								"   1   "
							,(7 * 11)) == 0,
				"when filename == \"./test/maps/diamond_leftpad.cub\" "
				"expected "
				"ft_strncmp(game.manager.chart.buffer,"
								"   1   "
								"  101  "
								" 10001 "
								"1000001"
								"1000001"
								"1010101"
								"1001001"
								"1010101"
								" 10001 "
								"  101  "
								"   1   "
							",(7 * 11)) == 0");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}

	ft_printf("%s: END\n", __FUNCTION__);
}

void test_chart_diamond_trailing_spaces(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/diamond_trailing_spaces.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/diamond_trailing_spaces.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(game.manager.chart.dimen.x == 7,
				"when filename == \"./test/maps/diamond_trailing_spaces.cub\" "
				"expected "
				"game.manager.chart.dimen.x == 7");
		FT_TEST(game.manager.chart.dimen.y == 11,
				"when filename == \"./test/maps/diamond_trailing_spaces.cub\" "
				"expected "
				"game.manager.chart.dimen.y == 11");
		FT_TEST(ft_strncmp(game.manager.chart.buffer,
								"   1   "
								"  101  "
								" 10001 "
								"1000001"
								"1000001"
								"1010101"
								"1001001"
								"1010101"
								" 10001 "
								"  101  "
								"   1   "
							,(7 * 11)) == 0,
				"when filename == \"./test/maps/diamond_trailing_spaces.cub\" "
				"expected "
				"ft_strncmp(game.manager.chart.buffer,"
								"   1   "
								"  101  "
								" 10001 "
								"1000001"
								"1000001"
								"1010101"
								"1001001"
								"1010101"
								" 10001 "
								"  101  "
								"   1   "
							",(7 * 11)) == 0");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}

	ft_printf("%s: END\n", __FUNCTION__);
}

void test_valid_with_hole(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/valid_with_hole.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/valid_with_hole.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(result == true,
				"when filename == \"./test/maps/valid_with_hole.cub\" "
				"expected "
				"result == true");
		FT_TEST(game.manager.chart.dimen.x == 7,
				"when filename == \"./test/maps/valid_with_hole.cub\" "
				"expected "
				"game.manager.chart.dimen.x == 7");
		FT_TEST(game.manager.chart.dimen.y == 7,
				"when filename == \"./test/maps/valid_with_hole.cub\" "
				"expected "
				"game.manager.chart.dimen.y == 7");
		FT_TEST(ft_strncmp(game.manager.chart.buffer,
									"1111111"
									"1000001"
									"1011101"
									"101 101"
									"1011101"
									"1000001"
									"1111111"
							,(7 * 7)) == 0,
				"when filename == \"./test/maps/valid_with_hole.cub\" "
				"expected "
				"ft_strncmp(game.manager.chart.buffer,"
									"1111111"
									"1000001"
									"1011101"
									"101 101"
									"1011101"
									"1000001"
									"1111111"
							",(7 * 7)) == 0");
		if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	ft_printf("%s: END\n", __FUNCTION__);
}

void test_invalid_open_map_with_player_in_closed_room(void)
{
	ft_printf("\n%s: START\n", __FUNCTION__);
	{
		t_config_file	conf;
		int res_config = config_init(1,
					(char *[]){ "./test/maps/invalid_open_map_with_player_in_closed_room.cub", NULL},
					&conf);
		FT_TEST(res_config == true,
				"when filename == \"./test/maps/invalid_open_map_with_player_in_closed_room.cub\" "
				"expected "
				"res_config == true");
		t_game game;
		ft_bzero(&game, sizeof(t_game));
		int result = map_init(&game, &conf);
		FT_TEST(result == false,
				"when filename == \"./test/maps/invalid_open_map_with_player_in_closed_room.cub\" "
				"expected "
				"result == false");
				if (res_config)
			config_clean(&conf);
		if (result)
			game_clean(&game);
	}
	ft_printf("%s: END\n", __FUNCTION__);
}


void test_map_init(void)
{
	ft_printf("\n%s: START", __FUNCTION__);
	test_invalid_mapline();
	test_player_direction();
	test_player_pos();
	test_chart_trivial();
	/* test_chart_trivial_left_pad(); */
	/* test_chart_trivial_trailing_spaces(); */
	test_chart_diamond();
	/* test_chart_diamond_leftpad(); */
	/* test_chart_diamond_trailing_spaces(); */
	test_valid_with_hole();
	test_invalid_open_map_with_player_in_closed_room();
	ft_printf("%s: END\n", __FUNCTION__);
}
