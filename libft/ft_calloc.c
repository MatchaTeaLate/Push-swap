/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:17:04 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/09 16:25:20 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t type, size_t size)
{
	char	*ptr;

	ptr = malloc(size * type);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, size * type);
	return (ptr);
}
