NAME	= HI_THIS_IS_BRAIN
CC		= g++
CPPFLAGS = -Wall -Werror -Wextra
CXXFLAGS = -std=c++98
SRCS	= main.cpp 

all: $(NAME)

$(NAME):
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re