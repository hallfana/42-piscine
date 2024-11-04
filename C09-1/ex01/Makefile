NAME = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

INCLUDES = includes

SOURCES := \
	./srcs/ft_putchar.c \
	./srcs/ft_swap.c \
	./srcs/ft_putstr.c \
	./srcs/ft_strlen.c \
	./srcs/ft_strcmp.c

OBJECTS := $(SOURCES:%.c=%.o)

%.o : %.c
	$(CC) $(CCFLAGS) -I $(INCLUDES) -c $< -o $@

.PHONY: $(NAME)
$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

.PHONY: fclean
fclean : clean
	rm -rf $(NAME)

.PHONY: clean
clean :
	rm -rf $(OBJECTS)

.PHONY: all
all : $(NAME)

.PHONY: re
re : fclean all
