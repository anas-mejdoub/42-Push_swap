/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:11:18 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/05 22:53:45 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *stack_)
{
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

int	find_min2(t_list *stack_)
{
	int	min;

	min = stack_->index;
	while (stack_)
	{
		if (min > stack_->index)
			min = stack_->index;
		stack_ = stack_->next;
	}
	return (min);
}
