NAME	=	megaphone
CLANG	=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -I incs/

SRC_FILES	=	main Contact PhoneBook

SRCS	=	$(addsuffix .cpp, $(addprefix srcs/, $(SRC_FILES)))
OBJS	=	$(SRCS:cpp=o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CLANG) $(FLAGS) $(OBJS) -o $(NAME)

%.o	:	%.cpp
	$(CLANG) $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:
	rm -f $(OBJS) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re