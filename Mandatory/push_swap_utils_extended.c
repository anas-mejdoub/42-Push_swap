/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_extended.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:55:21 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/07 22:02:33 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_half_min(t_list *stack_)
{
	int	min;
	int	size;
	int	i;

	min = find_min2(stack_);
	size = ft_lstsize(stack_);
	i = 0;
	while (stack_)
	{
		if (stack_->index == min)
			break ;
		i++;
		stack_ = stack_->next;
	}
	if (i <= size / 2)
		return (1);
	else
		return (2);
	return (0);
}

int	test_0(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 0)
		i++;
	return (i == (int)ft_strlen(str));
}
