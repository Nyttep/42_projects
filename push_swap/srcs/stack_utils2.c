/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 04:17:48 by pdubois           #+#    #+#             */
/*   Updated: 2022/01/28 02:29:09 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_Stack	*stack_a)
{
	int	tmp;

	if (ft_is_empty(stack_a) || stack_a->top == 0)
		return ;
	tmp = stack_a->array[stack_a->top];
	stack_a->array[stack_a->top] = stack_a->array[stack_a->top -1];
	stack_a->array[stack_a->top -1] = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_Stack	*stack_b)
{
	int	tmp;

	if (ft_is_empty(stack_b) || stack_b->top == 0)
		return ;
	tmp = stack_b->array[stack_b->top];
	stack_b->array[stack_b->top] = stack_b->array[stack_b->top -1];
	stack_b->array[stack_b->top -1] = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_Stack *stack_a, t_Stack *stack_b)
{
	int	tmp;

	if (ft_is_empty(stack_a) || stack_a->top == 0)
		return ;
	tmp = stack_a->array[stack_a->top];
	stack_a->array[stack_a->top] = stack_a->array[stack_a->top -1];
	stack_a->array[stack_a->top -1] = tmp;
	if (ft_is_empty(stack_b) || stack_b->top == 0)
		return ;
	tmp = stack_b->array[stack_b->top];
	stack_b->array[stack_b->top] = stack_b->array[stack_b->top -1];
	stack_b->array[stack_b->top -1] = tmp;
	write(1, "ss\n", 3);
}

void	ft_pa(t_Stack *stack_a, t_Stack *stack_b)
{
	if (ft_is_empty(stack_b))
		return ;
	ft_add(stack_a, stack_b->array[stack_b->top--]);
	write(1, "pa\n", 3);
}

void	ft_pb(t_Stack *stack_a, t_Stack *stack_b)
{
	if (ft_is_empty(stack_a))
		return ;
	ft_add(stack_b, stack_a->array[stack_a->top--]);
	write(1, "pb\n", 3);
}
