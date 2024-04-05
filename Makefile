SRCS = ./Mandatory/main.c ./Mandatory/parsing.c ./Mandatory/push_swap_utils.c ./Mandatory/rules.c ./Mandatory/sorting.c
SRCS_BONUS = ./Bonus/main_bonus.c ./Bonus/parsing_bonus.c ./Bonus/rules_bonus.c
OBJBS = $(SRCS:.c=.o)
OBJBS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ./libft/libft.a

bonus : $(OBJBS_BONUS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJBS_BONUS) ./libft/libft.a

%.o : %.c ./Mandatory/push_swap.h #./bonus/pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ./libft
	rm -rf $(OBJBS) $(OBJBS_BONUS)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all