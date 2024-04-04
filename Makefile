SRCS = ./Mandatory/main.c ./Mandatory/parsing.c ./Mandatory/push_swap_utils.c ./Mandatory/rules.c ./Mandatory/sorting.c
# SRCS_BONUS = ./bonus/main_bonus.c ./bonus/malloc_free_bonus.c ./bonus/pipes_fork_bonus.c ./bonus/strings_bonus.c ./bonus/strings_2_bonus.c ./bonus/path_helper_bonus.c
OBJBS = $(SRCS:.c=.o)
# OBJBS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ./libft/libft.a

# bonus : $(OBJBS_BONUS)
# 	make -C ./libft
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS_BONUS) ./libft/libft.a

%.o : %.c ./Mandatory/push_swap.h #./bonus/pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ./libft
	rm -rf $(OBJBS)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all