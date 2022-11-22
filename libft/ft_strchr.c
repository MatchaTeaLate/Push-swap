/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:07:43 by anovikav          #+#    #+#             */
/*   Updated: 2021/11/30 18:35:43 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (ptr[i] != (char)c)
	{
		if (ptr[i] == '\0')
			return (0);
		i++;
	}
	return (ptr + i);
}
