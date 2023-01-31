/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:18:24 by anovikav          #+#    #+#             */
/*   Updated: 2023/01/31 00:47:18 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Check if args only have digit
/*---------------------------------------------------------------------------*/
static int	str_is_digit(char *str)
{
	register int	i;

	i = 0;
	if (str[i] == 0)
		return (FAIL);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_digit(char **str)
{
	register int	i;

	i = 0;
	while (str[i])
	{
		if (str_is_digit(str[i]) == FAIL)
		{
			ft_putstr_fd("Error\n", 2);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

//Check that a number isn't repeated
/*---------------------------------------------------------------------------*/
int	check_repetition(int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i != size)
	{
		j = i + 1;
		while (j != size)
		{
			if (list[i] == list[j])
			{
				ft_putstr_fd("Error\n", 2);
				return (FAIL);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

//Check that the number is whithin int limits
/*---------------------------------------------------------------------------*/
int	check_minimax(char *str)
{
	long long	nb;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		return (FAIL);
	}
	return (SUCCESS);
}
