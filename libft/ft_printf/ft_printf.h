/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:45:13 by anovikav          #+#    #+#             */
/*   Updated: 2022/05/30 11:15:50 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

# ifdef __APPLE__
#  define NULL_POINTER "0x0"
# elif __linux__
#  define NULL_POINTER "(nil)"
# endif

int		number_len_base(long long nb, unsigned int base_len);
void	ft_putnbr_base(unsigned long n, char *base);
int		number_len(long long nb, unsigned int base_len);
int		printf_x(unsigned int nb, char c);
int		ft_printf(const char *str, ...);
int		printf_u(unsigned int n);
int		printf_p(void *ptr);
int		printf_s(char *str);
int		printf_id(int nb);
int		printf_c(int a);

#endif
