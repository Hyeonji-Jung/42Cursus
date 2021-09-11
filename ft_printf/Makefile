# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeojung <hyeojung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:37:42 by hyeojung          #+#    #+#              #
#    Updated: 2021/09/11 14:31:47 by hyeojung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -I.
AR = ar rsc
RM = rm -f

NAME = libftprintf.a

SRCS = ft_printf.c\
	   util_1.c\
	   util_2.c\
	   check_print_type.c\
	   check_print_num.c\

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME) : $(OBJS)
	$(AR) $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
