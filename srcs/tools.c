/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:16:09 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/23 06:17:06 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//create a sorted list of the stack
static int	*sort_list(int *list, t_stack *stack)
{
	int	i;
	int	j;
	int	sorted;
	int	tmp;

	i = stack->size;
	sorted = 0;
	while (i > 1 && sorted == 0)
	{
		sorted = 1;
		j = 1;
		while (j < i)
		{
			if (list[j - 1] > list[j])
			{
				tmp = list[j - 1];
				list[j - 1] = list[j];
				list[j] = tmp;
				sorted = 0;
			}
			j++;
		}
		i--;
	}
	return (list);
}

/*---------------------------------------------------------------------------*/
//get index filled
static void	fill_index(t_stack *stack, int *sorted_list)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{	
		j = 0;
		while (j < stack->size)
		{	
			if (stack->array[i] == sorted_list[j])
				stack->index[i] = j;
			j++;
		}
		i += 1;
	}
	return ;
}

//create index
void	get_index(t_stack *stack)
{
	int	i;
	int	*sorted_list;

	i = 0;
	sorted_list = malloc(sizeof(int) * stack->size);
	if (!sorted_list)
		return ;
	while (i < stack->size)
	{
		sorted_list[i] = stack->array[i];
		i++;
	}
	i = 0;
	sorted_list = sort_list(sorted_list, stack);
	fill_index(stack, sorted_list);
	free(sorted_list);
	return ;
}

/*---------------------------------------------------------------------------*/
//choose if use rotate or reverse rotate 
void	shortcut(t_stack *stack, int max_size)
{
	if (stack->index[0] > max_size / 2)
		rotate(stack);
	else if (stack->index[0] <= max_size / 2)
		reverse_rotate(stack);
}
