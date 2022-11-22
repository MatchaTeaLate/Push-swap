/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:41:40 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/03 16:38:29 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_minimum(const char *s, unsigned int a, size_t b)
{
	if (ft_strlen(s) <= b + 1)
		return (ft_strlen(s) - a);
	return (b);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	str = malloc(sizeof(char) * (ft_minimum(s, start, len) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy((void *)str, (s + start), ft_minimum(s, start, len) + 1);
	return (str);
}
