##
# MiniRT
#
# @file
# @version 0.1

# Variables

NAME	= minirt
CC		= gcc
RM		= rm -f
INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/
HEADERS = src/minirt.h
CFLAGS	= -Wall -Werror -Wextra -g -I$(INC_DIR)

TEST	= test/
LIBFT	= $(addprefix $(INC_DIR), libft/)
LIBFT_A	= $(addprefix $(LIBFT), libft.a)

MLX		= ./../minilibx-linux/
MLX_A	= $(addprefix $(MLX), minilibx-Linux.a)

# Colours

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

SRC_FILES	= minirt parser

SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

# Rules

all: $(NAME)

build_tests: $(NAME)
	@$(MAKE) -s -C $(TEST)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX_A) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -lXext -lX11 -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Compiled $(LIBFT_A)"

$(MLX_A):
	#@$(MAKE) -s -C $(MLX)
	@make CC=clang -s -C $(MLX) 2>/dev/null;
	@echo "Compiled $(MLX_A)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -f $(LIBFT)/$(LIBFT_A)
	@echo "$(CYAN)$(LIBFT) executable files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)$(NAME) object files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) -f $(SRC_DIR)/minirt.h.gch

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(CYAN)$(NAME) executable files succesfully cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Everything was cleaned and the rebuilt for $(NAME)!$(DEF_COLOR)"

norm:
	@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

getmlx:
	if [ -d $(MLX) ]; then echo "mlx is alredy cloned"; else git clone https://github.com/42Paris/minilibx-linux $(MLX); fi

.PHONY: all clean fclean re norm getmlx

# end
