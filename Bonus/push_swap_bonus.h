/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:07:13 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/05 14:35:46 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include "../libft/libft.h"
void rotate(t_list **stack_);
void rotate_both(t_list **stack_a, t_list **stack_b);
void reverse_rotate(t_list **stack_);
void swap_both(t_list *stack_a, t_list *stack_b);
void swap(t_list *stack_a);
void push(t_list **src, t_list **dest);
void re_rotate_both(t_list **stack_a, t_list **stack_b);
void	free2d(void **res);
int check_empty_n(char *str);
int	correct_number(char *number);
t_list	*fill_stack(char **numbers);
int	check_numbers(t_list *stack_a, int to_search);
char	**parse_input(char *argv[]);

#endif