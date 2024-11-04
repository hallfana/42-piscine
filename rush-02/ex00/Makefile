# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgamba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 20:47:34 by lgamba            #+#    #+#              #
#    Updated: 2024/09/22 15:42:42 by lgamba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -g -fsanitize=address

OUT_DIR = srcs

SOURCES := \
	main.c \
	parser_util.c \
	parser.c \
	util.c \
	dict.c \
	print.c \
	number.c \
	number_999.c
OBJECTS := $(SOURCES:.c=.o)


# Rule to transform any .c →  .o
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Makes all objects and archiv them together
.PHONY: all
all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(NAME): all

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
