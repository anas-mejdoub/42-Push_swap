SRCS = main.c parsing.c push_swap_utils.c rules.c sorting.c push_swap_utils_extended.c
OBJBS = $(SRCS:.c=.o)
NAME = ../push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	make -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ../libft/libft.a

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ../libft
	rm -rf $(OBJBS)

fclean : clean
	make fclean -C ../libft
	rm -rf $(NAME)

re : fclean all