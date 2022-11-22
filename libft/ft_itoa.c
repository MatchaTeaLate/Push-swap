/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:47:42 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/08 18:14:28 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_len(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		count += 1;
	}
	return (count);
}

static unsigned int	get_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t		count;
	size_t		i;
	char		*str;
	long int	nb;

	count = number_len(n);
	str = malloc(sizeof(char) * (count + 1));
	if (str == 0)
		return (NULL);
	nb = get_abs(n);
	i = count - 1;
	while (nb > 0 || i == 0)
	{
		if (i == 0 && n < 0)
			str[0] = '-';
		else
		{
			str[i] = (nb % 10) + 48;
			nb = nb / 10;
		}
		i--;
	}
	str[count] = '\0';
	return (str);
}
