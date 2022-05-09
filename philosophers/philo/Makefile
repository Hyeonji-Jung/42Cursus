# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 19:47:47 by hyeojung          #+#    #+#              #
#    Updated: 2022/05/09 14:50:32 by hyeojung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I ./inc

SRCS = src/main.c src/action.c src/philo.c src/util.c

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
