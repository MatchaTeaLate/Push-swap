/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:01:55 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/20 18:53:54 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_u(unsigned int n)
{
	int	count;

	ft_putnbr_base(n, "0123456789");
	count = number_len(n, 10);
	return (count);
}
