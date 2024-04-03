/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:28 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/03 14:52:30 by amejdoub         ###   ########.fr       */
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

int find_min(t_list *stack_, int n)
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

int is_sorted(t_list *stack_)
{
	int temp;

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

void print_list(t_list *stack_)
{
	while (stack_)
	{
		stack_ = stack_->next;
	}
}

void sort_four(t_list **stack_a, t_list **stack_b)
{
			print_list(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	while(1)
	{
		if (find_min(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b);
			ft_printf("pb\n");
			sort_three(stack_a, stack_b);
			push(stack_b, stack_a);
			ft_printf("pa\n");
			return ;
		}
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while(1)
	{
		if (find_min(*stack_a, (*stack_a)->content))
		{
			push(stack_a, stack_b);
			ft_printf("pb\n");
			sort_four(stack_a, stack_b);
			push(stack_b, stack_a);
			ft_printf("pa\n");
			return ;
		}
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void indexing(t_list *stack_)
{
	int	i;
	t_list *tmp;
	t_list *head;

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
void apply_postion(t_list *stack_)
{
	int i = 0;
	while (stack_)
	{
		stack_->position = i;
		stack_= stack_->next;
		i++;
	}
}
int get_max(t_list *stack_)
{
	int max = 0;
	while (stack_)
	{
		if (stack_->index > max)
			max = stack_->index;
		stack_ = stack_->next;
	}
	return (max);
}
void test_sort(t_list **stack_a, t_list **stack_b)
{
	int i = 0;
	int range = 4;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= range && (*stack_a)->index >= i)
		{
			push(stack_a, stack_b);
			ft_printf("pb\n");
			i++;
			range++;
		}
		else if ((*stack_a)->index < i)
		{
			push(stack_a, stack_b);
			reverse_rotate(stack_b);
			ft_printf("pb\n");
			ft_printf("rb\n");
			i++;
			range++;
		}
		else
		{
			reverse_rotate(stack_a);
			ft_printf("ra\n");
		}
	}
	i = 0;
	// int first_half = ft_lstsize(*stack_b) / 2;
	// apply_postion(stack_b);
	// print_list()
	while ((*stack_b))
	{
		if (get_max(*stack_b) == (*stack_b)->index)
		{
			push(stack_b, stack_a);
			ft_printf("pa\n");
		}
		else
		{
			rotate(stack_b);
			ft_printf("ra\n");

		}
		// while (i < size)
		// {
		// 	if ()
		// }
	}
}

int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b = NULL;
	
	stack_a = fill_stack(parse_input(argc, argv));
	if (!stack_a)
		return 0;
	indexing(stack_a);
	// apply_postion(stack_a);
	// ft_printf("%d\n", get_max(stack_a));
	test_sort(&stack_a, &stack_b);
	// while (stack_b)
	// {
	// 	ft_printf("index : %d", stack_b->index);
	// 	stack_b = stack_b->next;
	// }
	// while (stack_a)
	// {
	// 	ft_printf("a->%d\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
}
