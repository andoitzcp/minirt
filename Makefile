##
# MiniRT
#
# @file
# @version 0.1

# Variables

NAME=minirt
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g -I$(INC_DIR)
TESTS_LDFLAGS=-lcriterion

RELEASE_SRC= src/parse.c src/parse_utils.c src/input_validation.c src/exit.c src/debugging.c
RELEASE_OBJ=$(subst src/,obj/,$(RELEASE_SRC:.c=.o))

TESTS_SRC=$(shell find test/src/ -type f -name '*.c')
TESTS_OBJ=$(subst src/,obj/,$(TESTS_SRC:.c=.o))
TESTS_BIN=$(subst src/,bin/,$(TESTS_SRC:.c=))

INC_DIR = inc/

HEADERS = src/minirt.h
LIBFT	= $(addprefix $(INC_DIR), libft/)
LIBFT_A	= $(addprefix $(LIBFT), libft.a)

MLX		= ./../minilibx-linux/
MLX_A	= $(addprefix $(MLX), minilibx-Linux.a)

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

all: $(NAME)

$(NAME): obj/minirt.o $(RELEASE_OBJ) $(LIBFT_A) $(MLX_A) $(HEADERS)
	@$(CC) $(CFLAGS) obj/$(NAME).o $(RELEASE_OBJ) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -lXext -lX11 -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Compiled $(LIBFT_A)"

$(MLX_A):
	#@$(MAKE) -s -C $(MLX) do not uncomment this line, it does not compile
	@make CC=clang -s -C $(MLX) 2>/dev/null;
	@echo "Compiled $(MLX_A)"

obj/minirt.o: src/minirt.c
	@$(CC) $(CFLAGS) -c $^ -o $@

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "release objects created"

test/obj/%.o: test/src/%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "test objects created"

test/bin/%: test/obj/%.o $(RELEASE_OBJ) $(LIBFT_A)
	@$(CC) $(TESTS_LDFLAGS) $^ -o $@

# prevent deleting object in rules chain
$(TESTS_BIN): $(RELEASE_OBJ) $(TESTS_OBJ)

run-tests: $(TESTS_BIN)
	./$^ || true

clean:
	rm -f $(RELEASE_OBJ) $(TESTS_OBJ)

	@$(RM) -f $(LIBFT)/$(LIBFT_A)
	@echo "$(CYAN)$(LIBFT) executable files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) -rf $(RELEASE_OBJ)
	@echo "$(BLUE)$(NAME) release object files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) -rf $(TESTS_OBJ)
	@echo "$(BLUE)$(NAME) test object files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) -f $(SRC_DIR)/minirt.h.gch

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(CYAN)$(NAME) main executable file succesfully cleaned!$(DEF_COLOR)"
	rm -f $(TESTS_BIN)
	@echo "$(CYAN)$(NAME) test executable files succesfully cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Everything was cleaned and the rebuilt for $(NAME)!$(DEF_COLOR)"

getmlx:
	if [ -d $(MLX) ]; then echo "mlx is alredy cloned"; else git clone https://github.com/42Paris/minilibx-linux $(MLX); fi

.PHONY: all clean fclean re norm getmlx

# end
