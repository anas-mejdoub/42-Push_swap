/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:16:42 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/26 22:12:19 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list *stack_a)
{
    int tmp;

    if (ft_lstsize(stack_a) > 1)
    {
        tmp = stack_a->content;
        stack_a->content = stack_a->next->content;
        stack_a->next->content = tmp;
    }
}

void swap_both(t_list *stack_a, t_list *stack_b)
{
    swap(stack_a);
    swap(stack_b);
}

void push(t_list **src, t_list **dest)
{
    t_list *tmp;

    if (*src)
    {
        tmp = *src;
        *src = (*src)->next;
        tmp->next = *dest;
        *dest = tmp;
    }
}
void rotate(t_list **stack_)
{
    t_list *last;
    t_list *tmp;

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
// 1 2 3 4
// 4 1 2 3