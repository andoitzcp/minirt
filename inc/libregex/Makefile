##
# LibRegEX
#
# @file
# @version 0.1

NAME = libregex
CC = gcc
CFLAGS	= -Wall -Werror -Wextra -g

RELEASE_OBJ_DIR=obj/

RELEASE_SRC= $(shell find src/ -type f -name '*.c')
RELEASE_OBJ=$(subst src/,obj/,$(RELEASE_SRC:.c=.o))


HEADERS = src/libregex.h
RM		= rm -f

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
	@echo "libregex compiled"

$(NAME): $(RELEASE_OBJ)
	@ar rcs $(NAME).a $(RELEASE_OBJ)

obj/%.o: src/%.c | $(RELEASE_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "release objects created"

$(RELEASE_OBJ_DIR):
	@[ -d $(RELEASE_OBJ_DIR) ] || mkdir -p $(RELEASE_OBJ_DIR)
clean:
	@$(RM) -r $(RELEASE_OBJ_DIR)
	@echo "$(BLUE)$(NAME) library object files succesfully cleaned!$(DEF_COLOR)"
	@$(RM) -f src/$(NAME).h.gch

fclean: clean
	@$(RM) $(NAME).a
	@echo "$(CYAN)$(NAME) library file succesfully cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

# end
