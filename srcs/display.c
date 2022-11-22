/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcha <matcha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:31:02 by anovikav          #+#    #+#             */
/*   Updated: 2022/11/22 14:29:37 by matcha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("--------------------------------------------------------\n");
	ft_printf("size a= %d\n", a->size);
	ft_printf("a: ");
	while (i < a->size)
	{
		ft_printf("%d ", a->array[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("index a: ");
	i = 0;
	while (i < a->size)
	{
		ft_printf("%d ", a->index[i]);
		i++;
	}
	ft_printf("\n\n");
	ft_printf("size b = %d\n", b->size);
	ft_printf("b: ");
	i = 0;
	while (i < b->size)
	{
		ft_printf("%d ", b->array[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("index b: ");
	i = 0;
	while (i < b->size)
	{
		ft_printf("%d ", b->index[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("--------------------------------------------------------\n");
}
