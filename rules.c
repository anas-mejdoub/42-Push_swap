/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:16:42 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/25 22:23:03 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list *stack_a)
{
    int tmp;

    if (ft_lstsize(stack_a) > 1)
    {
        tmp = stack_a->content;
        stack_a->content = stack_a->next->content;
        stack_a->next->content = tmp;
    }
}

void sb(t_list *stack_b)
{
    int tmp;

    if (ft_lstsize(stack_b) > 1)
    {
        tmp = stack_b->content;
        stack_b->content = stack_b->next->content;
        stack_b->next->content = tmp;
    }
}

void ss(t_list *stack_a, t_list *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;
    t_list *tmp2;

    if (*stack_b)
    {
        ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->content));
        tmp = *stack_b;
        tmp2 = (*stack_b)->next;
        if (tmp != NULL && tmp2 != NULL)
        {
            while (*stack_b)
            {
                *stack_b = (*stack_b)->next;
            }
            *stack_b = tmp2;
            free(tmp);
        }
    }
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;
    t_list *tmp2;
    
    if (*stack_a)
    {
        ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->content));
        tmp = *stack_a;
        tmp2 = (*stack_a)->next;
        if (tmp != NULL && tmp2 != NULL)
        {
            while (*stack_a)
            {
                *stack_a = (*stack_a)->next;
            }
            *stack_a = tmp2;
            free(tmp);
        }
    }
}