/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:16:31 by anovikav          #+#    #+#             */
/*   Updated: 2021/11/30 22:56:48 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		else if (str1[i] == '\0')
			return (0);
		i++;
		n--;
	}
	return (0);
}
