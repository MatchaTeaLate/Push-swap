/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 07:26:53 by anovikav          #+#    #+#             */
/*   Updated: 2022/10/23 06:48:29 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*---------------------------------------------------------------------------*/
//free the allocated element tab if i use split (ac == 2)
void	free_tab(char **str)
{
	int	i;

	i = 0;
	if (str[i][0] == 0)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

//free all elements of the struct stack
void	free_stack(t_stack *stack)
{
	stack->size = 0;
	free(stack->array);
	free(stack->index);
	stack->array = NULL;
	stack->index = NULL;
}

//free both stack at once if allocated
void	free_all(t_stack *a, t_stack *b)
{
	if (a != NULL)
		free_stack(a);
	if (b != NULL)
		free_stack(b);
	exit(EXIT_FAILURE);
}

/*---------------------------------------------------------------------------*/
t_stack	init_stack(char **input, int len, int size_max, char name)
{
	t_stack	stack;
	int		i;

	i = 0;
	stack.array = NULL;
	stack.index = NULL;
	stack.size = len;
	stack.name = name;
	stack.array = malloc(sizeof(int) * size_max);
	if (stack.array == NULL)
		return (stack);
	stack.index = malloc(sizeof(int) * size_max);
	if (stack.index == NULL)
	{
		free(stack.array);
		return (stack);
	}
	while (i < len)
	{
		stack.array[i] = ft_atoi(input[i]);
		i++;
	}
	return (stack);
}
