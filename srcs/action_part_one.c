/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_part_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:28:06 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/23 05:44:53 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the two number of stack
static int	*swap_index(int *index)
{
	int	tmp;

	tmp = index[0];
	index[0] = index[1];
	index[1] = tmp;
	return (index);
}

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	stack->index = swap_index(stack->index);
	ft_printf("s%c\n", stack->name);
}
// Push the first element of stack_2 to put it at the top of stack_1

static void	push_index(t_stack *a, t_stack *b)
{
	int	tmp;
	int	tmp2;
	int	i;

	tmp2 = b->index[0];
	i = 0;
	while (i < b->size)
	{
		tmp = b->index[i];
		b->index[i] = b->index[i + 1];
		b->index[i + 1] = tmp;
		i++;
	}
	i = a->size - 1;
	while (i > 0)
	{
		tmp = a->index[i];
		a->index[i] = a->index[i - 1];
		a->index[i - 1] = tmp;
		i--;
	}
	a->index[0] = tmp2;
	ft_printf("p%c\n", a->name);
}

void	push(t_stack *stack_1, t_stack *stack_2)
{
	int	tmp;
	int	tmp2;
	int	i;

	tmp2 = stack_2->array[0];
	i = 0;
	while (i < stack_2->size - 1)
	{
		tmp = stack_2->array[i];
		stack_2->array[i] = stack_2->array[i + 1];
		stack_2->array[i + 1] = tmp;
		i++;
	}
	stack_2->size -= 1;
	stack_1->size += 1;
	i = stack_1->size - 1;
	while (i > 0)
	{
		tmp = stack_1->array[i];
		stack_1->array[i] = stack_1->array[i - 1];
		stack_1->array[i - 1] = tmp;
		i--;
	}
	stack_1->array[0] = tmp2;
	push_index(stack_1, stack_2);
}
