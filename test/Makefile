##
# MiniRT Tests Makefile
#
# @file
# @version 0.1

CC		= gcc
RM		= rm -f
INC_DIR = ../inc/
SRC_DIR = ../src/
OBJ_DIR = ../obj/
BIN_DIR = ../bin/
HEADERS = ../src/minirt.h
CFLAGS	= -Wall -Werror -Wextra -g -I$(INC_DIR)

LIBFT	= $(addprefix $(INC_DIR), libft/)
LIBFT_A	= $(addprefix $(LIBFT), libft.a)

$(BIN_DIR)test_parse: parse_test.o
	@$(CC) $(CFLAGS) $(OBJ_DIR)parser.o parse_test.o -L$(LIBFT) -lft -o $(BIN_DIR)test_parse

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


# end
