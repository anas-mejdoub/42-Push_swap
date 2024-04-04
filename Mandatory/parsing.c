/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:04:48 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/04 15:21:38 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_input(char *argv[])
{
	int		i;
	char	*str;
	char	**numbers;

	i = 2;
	str = ft_strdup(argv[1]);
	while (argv[i])
	{
		if (!argv[i][0] || !check_empty_n(argv[i]))
			return (free(str), NULL);
		str = ft_strjoin2(str, " ");
		str = ft_strjoin2(str, argv[i]);
		i++;
	}
	numbers = ft_split(str, ' ');
	free(str);
	return (numbers);
}

t_list	*fill_stack(char **numbers)
{
	int		i;
	t_list	*stack_a;
	int		data;

	i = 0;
	stack_a = NULL;
	if (!numbers)
	{
		ft_printf("error\n");
		return (NULL);
	}
	while (numbers[i])
	{
		if (!check_numbers(stack_a, ft_atoi(numbers[i]))
			|| !correct_number(numbers[i]) || (ft_strlen(numbers[i]) > 1
				&& !ft_atoi(numbers[i])))
		{
			ft_printf("error\n");
			return (free2d((void **)numbers), NULL);
		}
		data = ft_atoi(numbers[i]);
		ft_lstadd_back(&stack_a, ft_lstnew((data)));
		i++;
	}
	free2d((void **)numbers);
	return (stack_a);
}

int	correct_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	while (number[i] && ft_isdigit(number[i]))
		i++;
	return (i == (int)ft_strlen(number));
}

int	check_numbers(t_list *stack_a, int to_search)
{
	while (stack_a != NULL)
	{
		if (stack_a->content == to_search)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int check_empty_n(char *str)
{
	int i = 0;
	
	while (str[i] && str[i] == ' ')
		i++;
	return ((int )ft_strlen(str) != i);
}
