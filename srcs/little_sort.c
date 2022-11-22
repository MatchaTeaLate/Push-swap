/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcha <matcha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:05:26 by anovikav          #+#    #+#             */
/*   Updated: 2022/11/22 20:09:25 by matcha           ###   ########.fr       */
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

//sorting 5 numbers
/*----------------------------------------------------------------------------*/
static void	refill_stack_a(t_stack *a, t_stack *b, int lengh)
{
	if ((a->size == 3) & (b->index[0] == lengh))
		push(a, b);
	if (a->index[0] == 0 && b->index[0] == lengh)
	{
		push(a, b);
		reverse_rotate(a);
	}
	else if (b->index[0] == 0 && (a->index[0] == 1
			|| a->index[a->size - 1] == lengh))
		push(a, b);
	else if (a->index[0] < b->index[0])
	{
		rotate(a);
		if (a->index[0] == 0 && (b->index[0] == lengh
				|| b->index[0] == lengh - 1))
			push(a, b);
		if (a->index[0] > b->index[0])
			push(a, b);
	}
	else if (a->index[0] > b->index[0])
	{
		if (a->index[lengh] < b->index[0])
			push(a, b);
		else
			reverse_rotate(a);
	}
}

void	five_sort(t_stack *a, t_stack *b)
{	
	int	lengh;

	if (check_order(a) == FAIL)
	{
		lengh = a->size - 1;
		while (a->size != 3)
			push(b, a);
		three_sort(a);
		while (b->size > 0)
			refill_stack_a(a, b, lengh);
		while (check_order(a) == FAIL)
			shortcut(a, lengh);
	}
	return ;
}
