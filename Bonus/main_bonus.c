/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:06:59 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/05 14:48:54 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int operations_options(t_list **stack_a, t_list **stack_b, char *operation)
{
    if (ft_strncmp("sa\n", operation, ft_strlen(operation)))
        return (swap(*stack_a), 1);
    else if (ft_strncmp("sb\n", operation, ft_strlen(operation)))
        return (swap(*stack_b), 1);
    else if (ft_strncmp("pa\n", operation, ft_strlen(operation)))
        return (push(stack_b, stack_a), 1);
    else if (ft_strncmp("pb\n", operation, ft_strlen(operation)))
        return (push(stack_a, stack_b), 1);
    else if (ft_strncmp("ra\n", operation, ft_strlen(operation)))
        return (rotate(stack_a), 1);
    else if (ft_strncmp("rb\n", operation, ft_strlen(operation)))
        return (rotate(stack_b), 1);
    else if (ft_strncmp("rra\n", operation, ft_strlen(operation)))
        return (reverse_rotate(stack_a), 1);
    else if (ft_strncmp("rrb\n", operation, ft_strlen(operation)))
        return (reverse_rotate(stack_b), 1);
    else if (ft_strncmp("rr\n", operation, ft_strlen(operation)))
        return (rotate_both(stack_a, stack_b), 1);
    else if (ft_strncmp("ss\n", operation, ft_strlen(operation)))
        return (swap_both(*stack_a, *stack_b), 1);
    else if (ft_strncmp("rrr\n", operation, ft_strlen(operation)))
        return (re_rotate_both(stack_a, stack_b), 1);
    return (0);
}

int operations_ckeck(t_list **stack_a, t_list **stack_b)
{
    char    *operation;
    
    operation = get_next_line(0);
    while (operation)
    {
        ft_printf("%s\n", operation);
        operation = get_next_line(0);
    }
}
int main(int argc, char *argv[])
{
    t_list	*stack_a;
	t_list	*stack_b;


	stack_b = NULL;
	if (argc == 1)
		return 0;
	stack_a = fill_stack(parse_input(argv));
	if (!stack_a)
		return (0);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
