/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:23:02 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/21 03:19:26 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_conversion(char c, va_list params)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += printf_c(va_arg(params, int));
	else if (c == 's')
		count += printf_s(va_arg(params, char *));
	else if (c == 'p')
		count += printf_p(va_arg(params, void *));
	else if (c == 'd' || c == 'i')
		count += printf_id(va_arg(params, int));
	else if (c == 'u')
		count += printf_u(va_arg(params, unsigned int));
	else if (c == 'x' || c == 'X')
		count += printf_x(va_arg(params, unsigned int), c);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		count ++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	register int	i;
	int				count;
	va_list			params;

	i = 0;
	count = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count = count + check_conversion(str[i + 1], params);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count ++;
		}
		i++;
	}
	return (count);
}
