##q
# Lib LINNMATH
#
# @file
# @version 0.1

NAME = liblinmath
CC = gcc
CFLAGS	= -Wall -Werror -Wextra

RELEASE_OBJ_DIR=obj/

RELEASE_SRC=$(shell find src/ -type f -name '*.c')
RELEASE_OBJ=$(subst src/,obj/,$(RELEASE_SRC:.c=.o))

HEADERS = src/linmath.h
RM = rm -rf

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
	@echo "liblinmath compiled"

$(NAME): $(RELEASE_OBJ)
	@ar rcs $(NAME).a $(RELEASE_OBJ)

$(RELEASE_OBJ_DIR)%.o: src/%.c | $(RELEASE_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "release objects created"

$(RELEASE_OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) $(RELEASE_OBJ_DIR)
	@echo "$(BLUE)$(NAME) library object files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) src/$(NAME).h.gch

fclean: clean
	@$(RM) $(NAME).a
	@echo "$(CYAN)$(NAME) library file succesfully cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

# end
