/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:28 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/27 21:40:37 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_sort(t_list *stack_a, int to_search)
{
	 
}
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
void sort_three(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		reverse_rotate(stack_a);
		swap(*stack_a);
		ft_printf("ra\nsa\n");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->next->content < (*stack_a)->next->next->content)
	{
		swap(*stack_a);
		ft_printf("sa\n");
	}
	else if ((*stack_a)->content < (*stack_a)->next->content && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		if ((*stack_a)->content < (*stack_a)->next->next->content)
		{
			rotate(stack_a);
			swap(*stack_a);
			ft_printf("ra\nsa\n");			
		}
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
	}
}
int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b = NULL;
	
	stack_a = fill_stack(parse_input(argc, argv));
	if (!stack_a)
		return 0;
	sort_three(&stack_a, &stack_b);
	while (stack_a)
	{
		ft_printf("a->%d\n", stack_a->content);
		stack_a = stack_a->next;
	}

}

