/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:05:26 by anovikav          #+#    #+#             */
/*   Updated: 2023/01/28 01:12:47 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Sorting 3 numbers
/*----------------------------------------------------------------------------*/
static void	smaller_than(t_stack *stack)
{
	if (stack->index[0] > stack->index[2])
		reverse_rotate(stack);
	else
	{
		swap(stack);
		rotate(stack);
	}
	return ;
}

static void	bigger_than(t_stack *stack)
{
	if (stack->index[0] < stack->index[2])
		swap(stack);
	else if (stack->index[0] > stack->index[2])
	{
		if (stack->index[1] < stack->index[2])
			rotate(stack);
		else
		{
			swap(stack);
			reverse_rotate(stack);
		}
	}
	return ;
}

void	three_sort(t_stack *stack)
{
	if (stack->size == 3 && check_order(stack) == FAIL)
	{
		if (stack->index[0] > stack->index[1])
			bigger_than(stack);
		else if (stack->index[0] < stack->index[1])
			smaller_than(stack);
	}
	return ;
}
