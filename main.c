/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:28 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/04 15:03:16 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(t_list *stack_a, int to_search)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		if (stack_a->content == to_search)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	correct_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	while (number[i] && ft_isdigit(number[i]))
		i++;
	return (i == ft_strlen(number));
}
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

t_list	*fill_stack(char **numbers)
{
	int		i;
	t_list	*stack_a;
	int		data;
	t_list	*head;

	i = 0;
	stack_a = NULL;
	head = stack_a;
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
int check_empty_n(char *str)
{
	int i = 0;
	
	while (str[i] && str[i] == ' ')
		i++;
	return (ft_strlen(str) == i);
}
char	**parse_input(int argc, char *argv[])
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

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		rotate(stack_a, "rra");
		swap(*stack_a, "sa");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		rotate(stack_a, "ra");
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		if ((*stack_a)->content < (*stack_a)->next->next->content)
		{
			reverse_rotate(stack_a, "ra");
			swap(*stack_a, "sa");
		}
		else
			reverse_rotate(stack_a, "ra\n");
	}
}

int	find_min(t_list *stack_, int n)
{
	int	min;

	min = stack_->content;
	while (stack_)
	{
		if (min > stack_->content)
			min = stack_->content;
		stack_ = stack_->next;
	}
	return (min == n);
}

int	is_sorted(t_list *stack_)
{
	int	temp;

	temp = stack_->content;
	while (stack_)
	{
		if (temp > stack_->content)
			return (0);
		temp = stack_->content;
		stack_ = stack_->next;
	}
	return (1);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (1)
	{
		if (find_min(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b, "pb");
			sort_three(stack_a, stack_b);
			push(stack_b, stack_a, "pa");
			return ;
		}
		rotate(stack_a, "ra");
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (1)
	{
		if (find_min(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b, "pb");
			sort_four(stack_a, stack_b);
			push(stack_b, stack_a, "pa");
			return ;
		}
		rotate(stack_a, "ra");
	}
}

void	indexing(t_list *stack_)
{
	int		i;
	t_list	*tmp;
	t_list	*head;

	head = stack_;
	while (stack_)
	{
		stack_->index = 0;
		tmp = head;
		while (tmp)
		{
			if (stack_->content > tmp->content)
				stack_->index++;
			tmp = tmp->next;
		}
		stack_ = stack_->next;
	}
}

int	get_max(t_list *stack_)
{
	int	max;

	max = 0;
	while (stack_)
	{
		if (stack_->index > max)
			max = stack_->index;
		stack_ = stack_->next;
	}
	return (max);
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

void	_sort_(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = 4;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= range && (*stack_a)->index >= i)
		{
			push(stack_a, stack_b, "pb");
			i++;
			range++;
		}
		else if ((*stack_a)->index < i)
		{
			push(stack_a, stack_b, "pb");
			rotate(stack_b, "rb");
			i++;
			range++;
		}
		else
			rotate(stack_a, "ra");
	}
	fill_a(stack_a, stack_b);
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

void	option_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 5)
		_sort_(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 2)
	{
		if (!is_sorted(*stack_a))
			swap(*stack_a, "sa");
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = fill_stack(parse_input(argc, argv));
	if (!stack_a)
		return (0);
	indexing(stack_a);
	option_sort(&stack_a, &stack_b);
	// while (stack_a)
	// {
	// 	ft_printf("a->%d\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	system("leaks a.out");
	return (0);
}
