/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:31 by amejdoub          #+#    #+#             */
/*   Updated: 2024/04/07 22:02:06 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	swap(t_list *stack_a, char *operation);
int		find_half(t_list *stack_);
void	fill_a(t_list **stack_a, t_list **stack_b);
void	free2d(void **res);
int		check_empty_n(char *str);
void	_sort_(t_list **stack_a, t_list **stack_b);
void	option_sort(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
int		correct_number(char *number);
t_list	*fill_stack(char **numbers);
int		check_numbers(t_list *stack_a, int to_search);
void	swap_both(t_list *stack_a, t_list *stack_b);
int		find_half(t_list *stack_);
int		find_half_min(t_list *stack_);
void	push(t_list **src, t_list **dest, char *operation);
char	**parse_input(char *argv[]);
void	rotate(t_list **stack_, char *operation);
void	reverse_rotate(t_list **stack_, char *operation);
int		get_max(t_list *stack_);
int		is_sorted(t_list *stack_);
int		find_min(t_list *stack_, int n);
void	indexing(t_list *stack_);
int		range_eq(int n);
int		find_min2(t_list *stack_);
int		test_0(char *str);

#endif