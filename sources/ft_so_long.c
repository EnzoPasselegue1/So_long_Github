/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:11:57 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 14:33:03 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (ft_printf("Malloc failed"), 0);
	ft_check_command_line_arguments(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_initialize_vars(game);
	ft_check_map(game);
	ft_free_map(game);
	ft_init_map(game, argv[1]);
	ft_initialize_mlx(game);
	ft_initialize_sprites(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, ft_close_game,
		game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_render_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_allocated_memory(game);
	return (0);
}
