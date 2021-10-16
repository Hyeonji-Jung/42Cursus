NAME = so_long

SRC = src/main.c src/check.c src/util.c src/read.c src/init.c

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = -L mlx/ -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c inc/so_long.h
	gcc $(FLAGS) -I inc/ -I mlx/ -c $< -o $@

${NAME} : $(OBJ) inc/so_long.h
	gcc $(FLAGS) $(OBJ) -I inc/ $(FLAGS_MLX) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

# bonus : $(OBJ_B) inc/so_long_bonus.h
# 	gcc $(FLAGS) $(OBJ_B) -I inc/ $(FLAGS_MLX) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
