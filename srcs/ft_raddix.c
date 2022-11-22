/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raddix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:44:42 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/23 05:46:49 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bitshift(t_stack *stack)
{
	int	result;
	int	i;

	result = 0;
	i = stack->size;
	while (i != 0)
	{
		i = i / 2;
		result++;
	}
	return (result);
}

void	ft_raddix(t_stack *a, t_stack *b)
{
	int	bit_pos;
	int	size;
	int	count;
	int	max_shift;

	size = a->size;
	bit_pos = 0;
	max_shift = max_bitshift(a);
	while (check_order(a) == FAIL || bit_pos < max_shift)
	{
		count = 0;
		while (count < size)
		{
			if (((a->index[0] >> bit_pos) & 1) == 1)
				rotate(a);
			else
				push(b, a);
			count++;
		}
		while (b->size != 0)
			push(a, b);
		bit_pos++;
	}
	return ;
}
