NAME	= a.out
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS	= Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re