SRCS = main_bonus.c parsing_bonus.c rules_bonus.c rules2_bonus.c
OBJBS = $(SRCS:.c=.o)
NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	@make -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ../libft/libft.a
	@echo "\033[1;32mthe Bonus target has been mad with success\033[0m"

%.o : %.c push_swap_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJBS)
	@echo "\033[1;31mthe bonus part object files had been deleted\033[0m"

fclean : clean
	rm -rf $(NAME)
	@echo "\033[1;31mthe bonus part target has been deleted\033[0m"
