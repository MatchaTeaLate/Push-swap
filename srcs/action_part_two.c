/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_part_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:31:52 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/23 05:44:27 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift number to the top of the stack; first number become the last
static int	*rotate_index(int *index, int len)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = 0;
	tmp2 = index[0];
	while (i < len - 1)
	{
		tmp = index[i];
		index[i] = index[i + 1];
		index[i + 1] = tmp;
		i++;
	}
	index[i] = tmp2;
	return (index);
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = 0;
	tmp2 = stack->array[0];
	while (i < stack->size - 1)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[i + 1];
		stack->array[i + 1] = tmp;
		i++;
	}
	stack->array[i] = tmp2;
	stack->index = rotate_index(stack->index, stack->size);
	ft_printf("r%c\n", stack->name);
}
//shift number to the bottom of the stack; last number become top

static int	*reverse_rotate_index(int *index, int len)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = len - 1;
	tmp2 = index[i];
	while (i > 0)
	{
		tmp = index[i];
		index[i] = index[i - 1];
		index[i - 1] = tmp;
		i--;
	}
	index[i] = tmp2;
	return (index);
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	tmp2;
	int	i;

	i = stack->size - 1;
	tmp2 = stack->array[i];
	while (i > 0)
	{
		tmp = stack->array[i];
		stack->array[i] = stack->array[i - 1];
		stack->array[i - 1] = tmp;
		i--;
	}
	stack->array[i] = tmp2;
	stack->index = reverse_rotate_index(stack->index, stack->size);
	ft_printf("rr%c\n", stack->name);
}
