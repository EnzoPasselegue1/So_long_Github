# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 20:37:12 by acesar-l          #+#    #+#              #
#    Updated: 2024/12/06 15:05:54 by enpassel         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

GREEN			= \033[0;32m
RED					= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./Libft/libft.a

MLX_DIR:= ./minilibx-linux/

CC 				= gcc

STANDARD_FLAGS 	= -Wall -Werror -Wextra -g3
MLX:= minilibx-linux/libmlx_Linux.a
MINILIBX_FLAGS	= -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX)

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./sources/

SRCS 			= $(addprefix $(SRCS_DIR),\
				ft_so_long.c			\
				ft_init_vars.c		\
				ft_initialize_game.c \
				ft_initialize_map.c \
				utils.c			\
				ft_check_map.c \
				ft_close_game.c \
				ft_free.c \
				ft_handle_input.c \
				ft_render_map.c)
				
all:			${LIBFT} ${NAME}

${NAME}: 		
				make -C $(MLX_DIR)
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make bonus -C Libft

clean:
				make clean -C Libft
				@echo

fclean:
				${REMOVE} ${NAME} 
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo

re:				fclean all

run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/map1.ber

.PHONY:			all clean fclean re rebonus valgrind run