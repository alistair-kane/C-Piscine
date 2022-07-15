NAME	= a.out
CC		= g++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS	= A_Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re