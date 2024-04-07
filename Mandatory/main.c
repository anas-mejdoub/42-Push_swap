/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:28 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/07 15:15:49 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free2d(void **res)
{
	int	i;

	i = 0;
	if (res != NULL)
	{
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
}

int	range_eq(int n)
{
	int	range;

	if (n <= 50)
		range = 8;
	else if (n <= 100)
		range = 15;
	else
		range = 35;
	return (range);
}

void	fill_a(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_b))
	{
		if (get_max(*stack_b) == (*stack_b)->index)
			push(stack_b, stack_a, "pa");
		else
		{
			if (find_half(*stack_b) == 1)
				rotate(stack_b, "rb");
			else if (find_half(*stack_b) == 2)
				reverse_rotate(stack_b, "rrb");
		}
	}
}

int	find_half(t_list *stack_)
{
	int	max;
	int	size;
	int	i;

	max = get_max(stack_);
	size = ft_lstsize(stack_);
	i = 0;
	while (stack_)
	{
		if (stack_->index == max)
			break ;
		i++;
		stack_ = stack_->next;
	}
	if (i < size / 2)
		return (1);
	else
		return (2);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = fill_stack(parse_input(argv));
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	indexing(stack_a);
	option_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
