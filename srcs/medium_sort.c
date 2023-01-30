/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:08:45 by anovikav          #+#    #+#             */
/*   Updated: 2023/01/28 01:13:49 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorting 5 number
static void	refill_condition(t_stack *a, t_stack *b, int lengh)
{
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

static void	refill_stack_a(t_stack *a, t_stack *b, int lengh)
{
	if ((a->size == 3) & (b->index[0] == lengh))
		push(a, b);
	refill_condition(a, b, lengh);
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
