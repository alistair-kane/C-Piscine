NAME		= harlFilter
CC			= g++
CPPFLAGS	= -Wall -Werror
CXXFLAGS	= -std=c++98
SRCS		= main.cpp Harl.cpp 

all: $(NAME)

$(NAME):
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re