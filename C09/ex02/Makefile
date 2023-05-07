NAME	= PmergeMe
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 

SRCS	= main.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re