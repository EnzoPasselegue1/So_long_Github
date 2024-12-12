/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:27:22 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 13:40:19 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_check_command_line_arguments(int argc, char **argv, t_game *game)
{
	int	map_parameter_len;

	game->map_alloc = false;
	if (argc > 2)
		ft_error_msg("Too many arguments (It should be only two).", game);
	if (argc < 2)
		ft_error_msg("The Map file is missing.", game);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong (It should be .ber).", game);
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
	free(line_temp);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int		i;

	i = 0;
	if (map[i] == '\n')
	{
		free(map);
		ft_error_msg("The Map has an empty line.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error_msg("The Map has an empty line.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("The Map has an empty line.", game);
		}
		i++;
	}
}
