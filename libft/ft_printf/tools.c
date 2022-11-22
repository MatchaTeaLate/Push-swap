/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:29:39 by anovikav          #+#    #+#             */
/*   Updated: 2022/05/30 11:18:45 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_base(unsigned long nb, char *base)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (nb > baselen - 1)
	{
		ft_putnbr_base(nb / baselen, base);
		nb = nb % baselen;
	}
	ft_putchar_fd(base[nb % baselen], 1);
}

int	number_len_base(unsigned long nb, unsigned int base_len)
{
	int				count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / base_len;
		count += 1;
	}
	return (count);
}

int	number_len(long long nb, unsigned int base_len)
{
	int				count;
	unsigned long	nbr;

	count = 0;
	if (nb <= 0)
	{
		count += 1;
		nbr = nb * -1;
	}
	else
		nbr = nb;
	while (nbr != 0)
	{
		nbr = nbr / base_len;
		count += 1;
	}
	return (count);
}
