/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:18:16 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 16:14:03 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "../Libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_HEIGHT 64
# define IMG_WIDTH 64

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'
# define ENEMY 'X'

# define DEAD1 'D'
# define DEAD2 'F'
# define DEAD3 'G'
# define DEAD4 'H'

# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_ESC 65307

# define WALL_XPM "assets/sprites/wall4.xpm"
# define FLOOR_XPM "assets/sprites/Floor2.xpm"
# define COINS_XPM "assets/sprites/coin.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/front/Blue_warrior.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/left/Blue_warrior.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/right/Blue_warrior.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/back/Blue_warrior.xpm"
# define EXIT_XPM "assets/sprites/exit.xpm"
# define EXIT_OPEN_XPM "assets/sprites/exit_open.xpm"
# define EXIT_CONSTRUCT_XPM "assets/sprites/exit_construct.xpm"
# define ENEMY_XPM "assets/sprites/enemy/Torch_blue.xpm"

//////STRUCT//////
typedef struct s_fill
{
	int			x;
	int			y;
}				t_fill;

typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_position
{
	int			x;
	int			y;
}				t_positon;

typedef struct s_image
{
	void		*xpm_ptr;
	int			x;
	int			y;
}				t_image;

typedef struct s_map
{
	char		**full;
	char		**temp_full;
	int			rows;
	int			columns;
	int			coins;
	int			temp_coins;
	int			exit;
	int			temp_exit;
	int			exit_construct;
	int			exit_open;
	int			players;
	int			enemy;
	t_positon	parsing_player;
	t_positon	player;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	int			x;
	int			y;
	t_map		map;
	t_image		player_front;
	t_image		player_back;
	t_image		player_left;
	t_image		player_right;
	t_image		wall;
	t_image		coin;
	t_image		exit;
	t_image		exit_construct;
	t_image		exit_open;
	t_image		floor;
	t_image		enemy;
	t_image		dead1;
	t_image		dead2;
	t_image		dead3;
	t_image		dead4;
	t_bool		map_alloc;
}				t_game;

//////INITIALIZE_MAP////////
void			ft_check_command_line_arguments(int argc, char **argv,
					t_game *game);
void			ft_init_map(t_game *game, char *argv);
void			ft_check_for_empty_line(char *map, t_game *game);

///////INITIALIZE_VARS////////
void			ft_initialize_vars(t_game *game);

///////FT_CHECH_MAP////////
void			ft_check_rows(t_game *game);
void			ft_check_columns(t_game *game);
void			ft_check_map_parameters(t_game *game);
void			ft_verify_map(t_game *game);
void			ft_check_map(t_game *game);

///////FT_RENDER_MAP////////
void			ft_render_mapping(t_game *game, int line, int column);
int				ft_render_map(t_game *game);
void			ft_render_player(t_game *game, int line, int column);
void			ft_render_sprite(t_game *game, t_image sprite, int line,
					int column);
void			ft_print_movement(t_game *game);

///////FT_INITIALIZE_GAME////////
void			ft_initialize_mlx(t_game *game);
void			ft_initialize_sprites(t_game *game);
t_image			ft_new_sprite(void *mlx, char *path, t_game *game);

///////FT_HANDLE_INPUT////////
int				ft_handle_input(int keysym, t_game *game);
void			ft_move_player(t_game *game, int x, int y, int sprite);

///////UTILS////////
char			*ft_strappend(char **s1, const char *s2);
void			ft_player_position(t_game *game);
void			ft_flood_fill(t_game *game, int x, int y);

///////CLOSE_GAME////////
int				ft_close_game(t_game *game);
int				ft_error_msg(char *message, t_game *game);

///////FT_FREE////////
void			ft_free_all_allocated_memory(t_game *game);
void			ft_kill_image(t_game *game);
void			ft_free_map(t_game *game);

#endif