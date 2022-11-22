/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:24:35 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/09 10:46:14 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *charset)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*str;

	if (!s1 || !charset)
		return (NULL);
	i = 0;
	while (is_charset(s1[i], charset))
		++i;
	start = i;
	i = ft_strlen(s1) - 1;
	while (is_charset(s1[i], charset))
		--i;
	len = i - start + 1;
	str = ft_substr(s1, start, len);
	return (str);
}
