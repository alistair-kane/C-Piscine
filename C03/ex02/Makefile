NAME	= a.out
CC		= g++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS	= FragTrap.cpp ClapTrap.cpp main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re