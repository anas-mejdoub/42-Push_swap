/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:28 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/26 15:02:57 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_numbers(t_list *stack_a, int to_search)
{
	int i = 0;
	while (stack_a != NULL)
	{
		if (stack_a->content == to_search)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int correct_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	while (number[i] && ft_isdigit(number[i]))
		i++;
	return (i == ft_strlen(number));
}

t_list *fill_stack(char **numbers)
{
	int i;
	t_list *stack_a;
	int	data;
	
	i = 0;
	stack_a = NULL;
	t_list *head = stack_a;
	while (numbers[i])
	{
		if (!check_numbers(stack_a, ft_atoi(numbers[i])) || !correct_number(numbers[i]))
		{
			ft_printf("error\n");
			return (NULL);
		}
		data = ft_atoi(numbers[i]);
		ft_lstadd_back(&stack_a, ft_lstnew((data)));
		i++;
	}
	return (stack_a);
}

char **parse_input(int argc, char *argv[])
{
	int		i;
	char	*str;
	char	**numbers;
	
	i = 2;
	str = ft_strdup(argv[1]);
	while (argv[i])
	{
		str = ft_strjoin2(str, " ");
		str = ft_strjoin2(str, argv[i]);
		i++;
	}
	numbers = ft_split(str, ' ');
	return (numbers);
}

int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_a = fill_stack(parse_input(argc, argv));
	stack_b = ft_lstnew(1);
	int i = 2;
	while (i <= 5)
	{
		ft_lstadd_back(&stack_b, ft_lstnew(i));
		i++;
	}
	push(stack_a, stack_b);
	while (stack_b)
	{
		ft_printf("b->%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	while (stack_a)
	{
		ft_printf("a->%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}
