/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:46:28 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/08 19:24:18 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
