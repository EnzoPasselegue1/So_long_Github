NAME := so_long

SRC:= $(addprefix $(SRC_DIR), ft_check_map.c ft_close_game.c ft_free.c ft_handle_input.c ft_init_vars.c ft_initialize_game.c ft_initialize_map.c ft_render_map.c ft_so_long.c utils.c)
OBJ_DIR:= sources/.obj/
OBJ:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS:= $(OBJ:%.o=%.d)

CC:= gcc
CCFLAGS:= -Wextra -Wall -Werror -g3
CPPFLAGS = -MMD -MP
SRC_DIR:= sources/
INCLUDES:= sources/


MLX_DIR:= minilibx-linux/
MLX:= $(MLX_DIR)libmlx_Linux.a
MLX_FLAG:= -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX)

LIBFT_DIR := Libft/
LIBFT := $(LIBFT_DIR)libft.a
LIBFT_FLAG := -L $(LIBFT_DIR) $(LIBFT)

HEADERS:= -I $(INCLUDES) -I $(MLX_DIR) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CCFLAGS) $(OBJ) $(MLX_FLAG) $(LIBFT_FLAG) -o $(NAME)
	@echo "👉 $(BLUE)$(CC) $(CCFLAGS) $(OBJ)  $(MLX_FLAG) $(LIBFT_FLAG) -o $(NAME)$(DEF_COLOR) 👀👀👀"
	@echo "$(GREEN) 💪💪💪💪💪💪👉 🦸🦸 $(NAME) compiled! 🦸🦸 💪💪💪💪💪💪 $(DEF_COLOR)"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "✅ $(MAGENTA)Compiling: $< $(DEF_COLOR) ✅"
	$(CC) $(CCFLAGS) $(CPPFLAGS)  $(HEADERS) -o $@ -c $<

-include $(DEPS)
# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m




clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	@echo "$(RED)💩💩💩💩💩💩💩 $(NAME) removed! 💩💩💩💩💩💩💩$(DEF_COLOR)"
	rm -f $(NAME)

re: fclean all

info:
	@echo "OBJ": $(OBJ)
	@echo "DEPS": $(DEPS)

.PHONY: all clean fclean re