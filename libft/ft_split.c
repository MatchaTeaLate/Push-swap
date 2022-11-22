/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:32:31 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/09 10:33:04 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeall(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		tab[j] = NULL;
		j--;
	}
	free(tab);
	return (NULL);
}

static int	word_count(const char *s, char charset)
{
	size_t	i;
	size_t	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		while (s[i] == charset && s[i])
			i++;
		if (!s[i])
			break ;
		else
			total += 1;
		while (!(s[i] == charset) && s[i])
			i++;
	}
	return (total);
}

static int	word_len(const char *s, char charset)
{
	size_t	i;

	i = 0;
	while (s[i] && !(s[i] == charset))
		i++;
	return (i);
}

static char	**ft_split2(char **tab, const char *str, char charset)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else
		{
			k = word_len(str + i, charset);
			tab[j] = malloc(sizeof(char) * (k + 1));
			if (!tab[j])
				return (freeall(tab, j));
			ft_strlcpy(tab[j], str + i, k + 1);
			i += k;
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(const char *str, char charset)
{
	char	**tab;

	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (!tab)
		return (NULL);
	ft_split2(tab, str, charset);
	return (tab);
}
