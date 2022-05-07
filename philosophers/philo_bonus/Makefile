# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 19:48:00 by hyeojung          #+#    #+#              #
#    Updated: 2022/05/07 19:48:05 by hyeojung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror -I ./inc

SRCS = src/main.c

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
