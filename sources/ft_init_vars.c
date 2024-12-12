/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:27:15 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 15:20:59 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_initialize_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.exit_open = 0;
	game->map.players = 0;
	game->map.enemy = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->player_sprite = RIGHT;
}
