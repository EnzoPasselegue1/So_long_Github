/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:40:40 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 15:26:48 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
		{
			ft_error_msg("There's a Wall missing from the first row", game);
			exit(1);
		}
		else if (game->map.full[i][game->map.columns - 1] != WALL)
		{
			ft_error_msg("There's a Wall missing from the last row", game);
			exit(1);
		}
		i++;
	}
	ft_printf("all the rows are good\n");
}

void	ft_check_colomuns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
		{
			ft_error_msg("There's a Wall missing from the first columns", game);
			exit(1);
		}
		else if (game->map.full[game->map.rows - 1][i] != WALL)
		{
			ft_error_msg("There's a Wall missing from the last columns", game);
			exit(1);
		}
		i++;
	}
	ft_printf("all the columns are good\n");
}

void	ft_check_map_parameters(t_game *game)
{
	game->y = 0;
	while (game->y < game->map.rows)
	{
		game->x = 0;
		while (game->x < game->map.columns)
		{
			if (!ft_strchr("CEP01X", game->map.full[game->y][game->x]))
				ft_error_msg("Invalid Map. Not expected map parameter.", game);
			else if (game->map.full[game->y][game->x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = game->x;
				game->map.player.y = game->y;
			}
			else if (game->map.full[game->y][game->x] == COINS)
				game->map.coins++;
			else if (game->map.full[game->y][game->x] == MAP_EXIT)
				game->map.exit++;
			else if (game->map.full[game->y][game->x] == ENEMY)
				game->map.enemy++;
			game->x++;
		}
		game->y++;
	}
}

void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.players != 1)
	{
		ft_error_msg("There's no player or more than one player", game);
		exit(1);
	}
	else if (game->map.coins == 0)
	{
		ft_error_msg("There's no coins", game);
		exit(1);
	}
	else if (game->map.exit != 1)
	{
		ft_error_msg("There's no exit or more then one exit", game);
		exit(1);
	}
	else
		ft_printf("Map parameters and players are good\n");
}

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_colomuns(game);
	ft_check_map_parameters(game);
	ft_verify_map_parameters(game);
	game->map.temp_exit = 1;
	game->map.temp_coins = game->map.coins;
	ft_player_position(game);
	ft_flood_fill(game, game->map.parsing_player.y, game->map.parsing_player.x);
	if (game->map.temp_coins != 0)
	{
		ft_error_msg("There's a coin or more that is not reachable", game);
		ft_close_game(game);
	}
	if (game->map.temp_exit != 0)
	{
		ft_error_msg("The exit is not reachable", game);
		ft_close_game(game);
	}
	game->map.temp_coins = game->map.coins;
}
