NAME	= RPN
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 

SRCS	= main.cpp RPN.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re