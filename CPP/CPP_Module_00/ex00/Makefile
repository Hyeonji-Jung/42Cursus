NAME	=	megaphone
CLANG	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_FILES	=	megaphone

SRCS	=	$(addsuffix .cpp, $(SRC_FILES))
OBJS	=	$(SRCS:cpp=o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CLANG) $(FLAGS) $(OBJS) -o $(NAME)

%.o	:	%.c
	$(CLANG) $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:
	rm -f $(OBJS) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re