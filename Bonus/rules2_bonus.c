/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:03:05 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/05 21:03:19 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_list **stack_)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_) <= 1)
		return ;
	first = *stack_;
	last = ft_lstlast(*stack_);
	(*stack_) = (*stack_)->next;
	last->next = first;
	first->next = NULL;
}

void	re_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
