/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:16:42 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/02 23:43:05 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list *stack_a, char *operation)
{
    int tmp;

    if (ft_lstsize(stack_a) > 1)
    {
        tmp = stack_a->content;
        stack_a->content = stack_a->next->content;
        stack_a->next->content = tmp;
    }
    ft_printf("%s\n", operation);
}

void swap_both(t_list *stack_a, t_list *stack_b)
{
    swap(stack_a, "sa");
    swap(stack_b, "sb");
}

void push(t_list **src, t_list **dest, char *operation)
{
    t_list *tmp;

    if (*src)
    {
        tmp = *src;
        *src = (*src)->next;
        tmp->next = *dest;
        *dest = tmp;
    }
    ft_printf("%s\n", operation);
}

void reverse_rotate(t_list **stack_, char *operation)
{
    t_list *last;
    t_list *tmp;

    if (ft_lstsize(*stack_) <= 1)
        return;
    last = ft_lstlast(*stack_);
    tmp = *stack_;
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    last->next = *stack_;
    *stack_ = last;
    ft_printf("%s\n", operation);
}

void rotate_both(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a, "ra");
    rotate(stack_b, "rb");
}

void rotate(t_list **stack_, char *operation)
{
    t_list  *first;
    t_list  *last;

    if (ft_lstsize(*stack_) <= 1)
        return ;
    first = *stack_;
    last = ft_lstlast(*stack_);
    (*stack_) = (*stack_)->next;
    last->next = first;
    first->next = NULL;
    ft_printf("%s\n", operation);
}

void re_rotate_both(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a, "rra");
    reverse_rotate(stack_b, "rrb");
}