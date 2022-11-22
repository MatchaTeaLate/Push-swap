/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:02:11 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/21 00:31:22 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_p(void *ptr)
{
	unsigned int	count;

	count = 2;
	if (!ptr)
	{
		ft_putstr_fd(NULL_POINTER, STDOUT_FILENO);
		return (ft_strlen(NULL_POINTER));
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	count = count + number_len_base((unsigned long)ptr, 16);
	return (count);
}
