NAME = pipex

FLAGS = -Wall -Wextra -Werror -I ./inc

SRCS = src/main.c src/util_1.c src/util_2.c src/split.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

${NAME} : $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

bonus : ${OBJS}
	gcc $(FLAGS) $(OBJS) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
