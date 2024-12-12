/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:27:32 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 14:33:16 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_close_game(t_game *game)
{
	ft_printf("Movements: %d\n", game->movements);
	ft_free_all_allocated_memory(game);
	ft_printf("CLOSED\n");
	exit(EXIT_FAILURE);
}

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}
