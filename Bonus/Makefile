SRCS = main_bonus.c parsing_bonus.c rules_bonus.c rules2_bonus.c
OBJBS = $(SRCS:.c=.o)
NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	make -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ../libft/libft.a

%.o : %.c push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ../libft
	rm -rf $(OBJBS)

fclean : clean
	make fclean -C ../libft
	rm -rf $(NAME)
