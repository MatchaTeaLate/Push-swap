/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:21:30 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/08 19:23:16 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (sr < dst)
	{
		while (n > 0)
		{
			dst[n - 1] = sr[n - 1];
			n--;
		}
	}
	dest = ft_memcpy(dest, src, n);
	return (dest);
}
