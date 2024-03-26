/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:16:42 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/26 15:13:01 by amejdoub         ###   ########.fr       */
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

void push(t_list *stack_a, t_list *stack_b)
{
    
    t_list *tmp;

    tmp = ft_lstlast(stack_b);
    ft_lstadd_back(&stack_a, tmp);
    if (stack_b->next == NULL)
    {
        free(stack_b);
        stack_b = NULL;
        return;
    }
    while (stack_b->next->next)
    {
        stack_b = stack_b->next;
    }
    stack_b->next = NULL;
}
void push_helper(t_list **node)
{
    *node = NULL;
}
