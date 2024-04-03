/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:31 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/27 21:56:39 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

void swap(t_list *stack_a, char *operation);

void swap_both(t_list *stack_a, t_list *stack_b);
int find_half(t_list *stack_);
void push(t_list **src, t_list **dest, char *operation);
void rotate(t_list **stack_, char *operation);
void rotate_both(t_list **stack_a, t_list **stack_b);
void reverse_rotate(t_list **stack_, char *operation);
void sort_three(t_list **stack_a, t_list **stack_b);
#endif