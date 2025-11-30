##
# MiniRT
#
# @file
# @version 0.1

# Variables

NAME=minirt
CC=gcc
UNUSEDFLAGS = -Wunused -Wunreachable-code
CFLAGS=-Wall -Werror -Wextra -g -I$(INC_DIR) $(UNUSEDFLAGS)

RELEASE_SRC= src/minirt.c \
			 src/init.c \
             src/parse.c \
             src/lines.c \
             src/get_data_basic.c \
             src/get_data_common.c \
             src/get_data_geo_els.c \
             src/check_boundaries.c \
             src/input_validation.c \
             src/exit.c \
             src/ray.c \
             src/color.c \
             src/canvas.c \
             src/color_ops.c \
			 src/intersect.c \
             src/intersect_sp.c \
             src/intersect_sp_2.c \
             src/transform.c \
             src/transform_2.c \
             src/sphere.c \
             src/plane.c \
             src/cylinder.c \
             src/camera.c \
             src/ambient_light.c \
             src/world.c \
			 src/comps.c	\
			 src/render.c	\
             src/material.c \
			 src/lighting.c \
			 src/light.c	\
             src/object.c \
             src/interfase_world_parse.c \
			 src/draw.c	\
			 src/gui.c	\
			 src/gui_2.c	\
			 src/destroy.c	\
			 src/destroy_2.c

RELEASE_OBJ=$(subst src/,obj/,$(RELEASE_SRC:.c=.o))

INC_DIR = inc/
OBJ_DIR = obj/

LIBFT	= $(addprefix $(INC_DIR), libft/)
LIBFT_A	= $(addprefix $(LIBFT), libft.a)

LINMATH	= $(addprefix $(INC_DIR), liblinmath/)
LINMATH_A = $(addprefix $(LINMATH), liblinmath.a)

MLX	= ./../minilibx-linux/
MLX_A	= $(addprefix $(MLX), minilibx-Linux.a)

LIBRE = $(addprefix $(INC_DIR), libregex/)
LIBRE_A	= $(addprefix $(LIBRE), libregex.a)

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

$(NAME): $(RELEASE_OBJ) $(LIBFT_A) $(LINMATH_A) $(LIBRE_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(RELEASE_OBJ) -L$(LIBFT) -lft -L$(LINMATH) -llinmath -L$(LIBRE) -lregex -L$(MLX) -lmlx -lm -lXext -lX11 -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Compiled $(LIBFT_A)"

$(LIBRE_A):
	@$(MAKE) -s -C $(LIBRE)
	@echo "Compiled $(LIBRE_A)"

$(LINMATH_A):
	@$(MAKE) -s -C $(LINMATH)
	@echo "Compiled $(LINMATH_A)"

$(MLX_A):
	#@$(MAKE) -s -C $(MLX) do not uncomment this line, it does not compile
	@make CC=clang -s -C $(MLX) 2>/dev/null;
	@echo "Compiled $(MLX_A)"

$(OBJ_DIR)%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "release objects created"

$(OBJ_DIR):
	mkdir -p $@

clean:
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(LIBRE) clean
	@$(MAKE) -s -C $(LINMATH) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)$(NAME) release object files succesfully cleaned!$(DEF_COLOR)"
	@rm -f src/minirt.h.gch

fclean: clean
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(LIBRE) fclean
	@$(MAKE) -s -C $(LINMATH) fclean
	@rm -rf $()
	@rm -f $(LIBFT)/$(LIBFT_A)
	@echo "$(CYAN)$(LIBFT) executable files succesfully cleaned!$(DEF_COLOR)"
	@rm -f $(LIBRE)/$(LIBRE_A)
	@echo "$(CYAN)$(LIBRE) executable files succesfully cleaned!$(DEF_COLOR)"
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) main executable file succesfully cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Everything was cleaned and the rebuilt for $(NAME)!$(DEF_COLOR)"

getmlx:
	if [ -d $(MLX) ]; then echo "mlx is alredy cloned"; else git clone https://github.com/42Paris/minilibx-linux $(MLX); fi

.PHONY: all clean fclean re norm getmlx

# end
