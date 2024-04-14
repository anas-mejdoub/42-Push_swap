SRCS = main.c parsing.c push_swap_utils.c rules.c sorting.c push_swap_utils_extended.c
OBJBS = $(SRCS:.c=.o)
NAME = ../push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	@make -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ../libft/libft.a
	@echo "\033[1;32mthe Mandatory target has been mad with success\033[0m"

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -C ../libft
	rm -rf $(OBJBS)
	@echo "\033[1;31mthe Mandatory part object files had been deleted\033[0m"

fclean : clean
	@make fclean -C ../libft
	rm -rf $(NAME)
	@echo "\033[1;31mthe Mandatory part target has been deleted\033[0m"
re : fclean all