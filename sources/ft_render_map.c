/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:35:27 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 15:43:10 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_render_mapping(t_game *game, int line, int column)
{
	if (game->map.full[line][column] == WALL)
		ft_render_sprite(game, game->wall, line, column);
	else if (game->map.full[line][column] == FLOOR)
		ft_render_sprite(game, game->floor, line, column);
	else if (game->map.full[line][column] == COINS)
		ft_render_sprite(game, game->coin, line, column);
	else if (game->map.full[line][column] == PLAYER)
		ft_render_player(game, line, column);
	else if (game->map.full[line][column] == ENEMY)
		ft_render_sprite(game, game->enemy, line, column);
	else if (game->map.full[line][column] == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite(game, game->exit_open, line, column);
		else if (game->map.coins <= game->map.temp_coins / 2)
			ft_render_sprite(game, game->exit_construct, line, column);
		else
			ft_render_sprite(game, game->exit, line, column);
	}
}

int	ft_render_map(t_game *game)
{
	int	line;
	int	column;

	line = 0;
	while (line < game->map.rows)
	{
		column = 0;
		while (column < game->map.columns)
		{
			ft_render_mapping(game, line, column);
			column++;
		}
		line++;
	}
	ft_print_movement(game);
	return (0);
}

void	ft_render_player(t_game *game, int line, int column)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite(game, game->player_front, line, column);
	else if (game->player_sprite == BACK)
		ft_render_sprite(game, game->player_back, line, column);
	else if (game->player_sprite == LEFT)
		ft_render_sprite(game, game->player_left, line, column);
	else if (game->player_sprite == RIGHT)
		ft_render_sprite(game, game->player_right, line, column);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, column
		* sprite.x, line * sprite.y);
}

void	ft_print_movement(t_game *game)
{
	char	*movement;
	char	*phrase;

	movement = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements: ", movement);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 00000, phrase);
	free(movement);
	free(phrase);
}
