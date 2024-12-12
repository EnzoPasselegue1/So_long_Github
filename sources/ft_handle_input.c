/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:39:30 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 14:16:30 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_close_game(game);
	else if (keysym == KEY_UP || keysym == KEY_W)
		ft_move_player(game, game->map.player.y - 1, game->map.player.x, BACK);
	else if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_move_player(game, game->map.player.y + 1, game->map.player.x, FRONT);
	else if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_move_player(game, game->map.player.y, game->map.player.x - 1, LEFT);
	else if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_move_player(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	return (0);
}

void	ft_move_player(t_game *game, int y, int x, int sprite)
{
	if (game->map.full[y][x] == WALL)
		return ;
	if (game->map.full[y][x] == COINS)
		game->map.coins--;
	if (game->map.full[y][x] == MAP_EXIT && game->map.coins == 0)
		ft_close_game(game);
	if (game->map.full[y][x] == MAP_EXIT && game->map.coins != 0)
		return ;
	if (game->map.full[y][x] == PLAYER)
		game->map.players--;
	if (game->map.full[y][x] == ENEMY)
		ft_close_game(game);
	game->map.full[game->map.player.y][game->map.player.x] = FLOOR;
	game->map.full[y][x] = PLAYER;
	game->map.player.x = x;
	game->map.player.y = y;
	game->player_sprite = sprite;
	game->movements++;
	ft_render_map(game);
}
