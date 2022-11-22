/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovikav <anovikav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:15:59 by anovikav          #+#    #+#             */
/*   Updated: 2021/12/09 16:15:51 by anovikav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	t_list	**tmp;

	new_lst = NULL;
	tmp = &new_lst;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(tmp, del);
			return (NULL);
		}
		ft_lstadd_back(tmp, node);
		lst = lst->next;
	}
	return (new_lst);
}
