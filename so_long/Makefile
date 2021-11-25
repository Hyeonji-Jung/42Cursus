NAME = so_long
NAME_B = so_long_bonus

SRC_M = src/main.c src/check.c src/util.c src/read.c src/init.c\
	src/draw.c src/move.c

SRC_B = src/main_bonus.c src/check_bonus.c src/util_bonus.c src/read_bonus.c\
	src/init_bonus.c src/draw_bonus.c src/move_bonus.c

FLAGS = -g -Wall -Wextra -Werror

FLAGS_MLX = -L mlx/ -lmlx -framework OpenGL -framework AppKit

OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

%.o : %.c inc/so_long.h
	gcc $(FLAGS) -I inc/ -I mlx/ -c $< -o $@

${NAME} : $(OBJ_M) inc/so_long.h
	gcc $(FLAGS) $(OBJ_M) -I inc/ $(FLAGS_MLX) -o $(NAME)

clean :
	$(RM) $(OBJ_M) ${OBJ_B}

fclean : clean
	$(RM) $(NAME) ${NAME_B}

bonus : ${OBJ_B} inc/so_long_bonus.h
	gcc $(FLAGS) $(OBJ_B) -I inc/ $(FLAGS_MLX) -o $(NAME_B)

re : fclean all

.PHONY: all clean fclean re bonus
