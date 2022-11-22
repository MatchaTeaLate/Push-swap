/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:44:38 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/23 01:21:16 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//support function for check order rotate until true order
static void	choose_and_rotate(t_stack *stack, int count)
{
	if (count <= stack->size / 2)
	{
		while (count != 0)
		{
			rotate(stack);
			count--;
		}
	}
	else
	{
		while (count != 0)
		{
			reverse_rotate(stack);
			count--;
		}
	}
}

//set up condition to see u can use choose and rotate
static int	get_true_order(t_stack *stack, int i, int count)
{
	if (stack->index[stack->size - 1] > stack->index[i] < stack->index[0])
	{
		while ((stack->index[i] < stack->index[i + 1]) && stack->index[i])
		{
			if (i == stack->size - 2)
			{
				choose_and_rotate(stack, count);
				return (SUCCESS);
			}
			i++;
		}
	}
	return (FAIL);
}

//check order and rotate until it start from the top 
int	check_order(t_stack *stack)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	if (stack->size == 1)
		return (SUCCESS);
	while (stack->index[i] < stack->index[i + 1])
	{
		if (i == stack->size - 2)
			return (SUCCESS);
		i++;
		count++;
	}
	if (get_true_order(stack, i, count) == SUCCESS)
		return (SUCCESS);
	return (FAIL);
}

//check order only if it's from the top of the stack
int	check_true_order(t_stack *stack)
{
	register int	i;

	i = 0;
	while (stack->index[i + 1] == stack->index[i] + 1)
	{
		if (i == stack->size - 2)
			return (SUCCESS);
		i++;
	}
	return (FAIL);
}
