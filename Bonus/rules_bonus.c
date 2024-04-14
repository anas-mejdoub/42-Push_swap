/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:09:20 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/14 16:42:49 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list *stack_a)
{
	int	tmp;

	if (ft_lstsize(stack_a) > 1)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
	}
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (ft_lstsize(*src) >= 1)
	{
		ft_printf ("%d\n", (*src)->content);
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	reverse_rotate(t_list **stack_)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(*stack_) <= 1)
		return ;
	last = ft_lstlast(*stack_);
	tmp = *stack_;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	last->next = *stack_;
	*stack_ = last;
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
