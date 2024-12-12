/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:39:21 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 15:27:22 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_free_all_allocated_memory(t_game *game)
{
	ft_kill_image(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	ft_kill_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coin.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_open.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_construct.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy.xpm_ptr);
}

void	ft_free_map(t_game *game)
{
	int	string;

	string = 0;
	while (string < game->map.rows)
		free(game->map.full[string++]);
	free(game->map.full);
}
