/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:44:20 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/01 19:44:31 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystick;

	i = 0;
	haystick = (char *)str;
	if (to_find[i] == '\0')
		return (haystick);
	if (len > 0)
	{
		while (str[i] && i < len)
		{
			j = 0;
			while ((str[i + j] == to_find[j] || !to_find[j]) && (i + j) <= len)
			{
				if (to_find[j] == '\0')
					return (haystick + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
