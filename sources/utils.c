/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:27:28 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 14:00:46 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	ft_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.parsing_player.x = x;
				game->map.parsing_player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_flood_fill(t_game *game, int x, int y)
{
	while (game->map.full[x][y] != '1' && game->map.full[x][y] != 't')
	{
		if (game->map.full[x][y] == COINS)
			game->map.temp_coins--;
		if (game->map.full[x][y] == MAP_EXIT)
		{
			game->map.temp_exit = 0;
		}
		if (game->map.full[x][y] == 'V')
		{
			game->map.full[x][y] = 't';
			return ;
		}
		game->map.full[x][y] = 'V';
		ft_flood_fill(game, x + 1, y);
		ft_flood_fill(game, x - 1, y);
		ft_flood_fill(game, x, y + 1);
		ft_flood_fill(game, x, y - 1);
	}
}
