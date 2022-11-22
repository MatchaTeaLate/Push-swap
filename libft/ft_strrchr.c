/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:24:07 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/08 18:51:03 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*s;

	if (str[0] == '\0' && c != 0)
		return (NULL);
	s = (char *)str;
	len = ft_strlen(str) - 1;
	if ((char)c == '\0')
		return (s + (len + 1));
	while (str[len] != (char)c)
	{
		if (len == 0)
			return (NULL);
		len--;
	}
	return (s + len);
}
