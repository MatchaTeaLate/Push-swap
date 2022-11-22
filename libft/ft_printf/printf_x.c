/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:01:45 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/20 18:54:02 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_x(unsigned int nb, char c)
{
	int	count;

	if (c == 'x')
		ft_putnbr_base(nb, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(nb, "0123456789ABCDEF");
	count = number_len(nb, 16);
	return (count);
}
