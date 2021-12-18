NAME = push_swap
CC = gcc
RM = rm -rf

SRC = 

FLAGS = -Wall -Wextra -Werror


OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -I -c $< -o $@

${NAME} : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
