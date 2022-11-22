/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:02:18 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/20 18:54:22 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_id(int nb)
{
	int	count;

	ft_putnbr_fd(nb, 1);
	count = number_len(nb, 10);
	return (count);
}
