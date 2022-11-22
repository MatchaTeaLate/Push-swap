/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:20:45 by anovikav          #+#    #+#             */
/*   Updated: 2021/11/30 17:37:28 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*nbr1;
	unsigned char	*nbr2;	

	nbr1 = (unsigned char *)s1;
	nbr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((nbr1[i] == nbr2[i]) && i < n - 1)
		i++;
	return (nbr1[i] - nbr2[i]);
}
