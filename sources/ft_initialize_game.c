/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:27:09 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 15:33:36 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_initialize_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Mlx couldn't be initialized.", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "So Long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Window couldn't be initialized.", game);
	}
}

void	ft_initialize_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM, game);
	game->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM, game);
	game->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM, game);
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->coin = ft_new_sprite(mlx, COINS_XPM, game);
	game->exit = ft_new_sprite(mlx, EXIT_XPM, game);
	game->exit_construct = ft_new_sprite(mlx, EXIT_CONSTRUCT_XPM, game);
	game->exit_open = ft_new_sprite(mlx, EXIT_OPEN_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->enemy = ft_new_sprite(mlx, ENEMY_XPM, game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.x = IMG_WIDTH;
	sprite.y = IMG_HEIGHT;
	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't find a sprite. Does it exist?", game);
	}
	return (sprite);
}
