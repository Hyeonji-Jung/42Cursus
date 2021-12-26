NAME	=	push_swap

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
SRC		=	main.c \
			preprocess.c \
			re_a.c \
			re_b.c \
			stack_operate1.c \
			stack_operate2.c \
			stack_operate3.c \
			sort_three_only.c \
			sort_three.c \
			sort_four_only.c \
			sort_four.c \
			util_preprocess.c \
			util_stack1.c \
			util_stack2.c \
			util_std1.c \
			util_std2.c \
			util_sort.c \
			util_list1.c \
			util_list2.c
OBJ		= $(SRC:.c=.o)

RM		= rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

${NAME} : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I. -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
