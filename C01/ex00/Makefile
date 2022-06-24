NAME	= zombies
CC		= g++
CPPFLAGS = -Wall -Werror -Wextra
CXXFLAGS = -std=c++98
SRCS	= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp 

all: $(NAME)

$(NAME):
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re