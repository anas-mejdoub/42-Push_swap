/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:20:31 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/26 20:55:05 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

void swap(t_list *stack_a);

void swap_both(t_list *stack_a, t_list *stack_b);
void push(t_list **src, t_list **dest);
void rotate(t_list *stack_);

#endif