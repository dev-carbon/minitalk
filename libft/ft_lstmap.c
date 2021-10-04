/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:00:05 by humanfou          #+#    #+#             */
/*   Updated: 2020/01/11 16:00:19 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	result = ft_lstnew((*f)(lst->content));
	if (!result)
		return (NULL);
	first = result;
	lst = lst->next;
	while (lst)
	{
		result->next = ft_lstnew((*f)(lst->content));
		if (!result)
		{
			ft_lstclear(&first, (*del));
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	return (first);
}
