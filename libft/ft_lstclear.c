/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:59:02 by humanfou          #+#    #+#             */
/*   Updated: 2020/01/11 15:59:11 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*elmt_now;
	t_list		*elmt_next;

	if (lst && del)
	{
		elmt_now = *lst;
		elmt_next = *lst;
		while (elmt_next)
		{
			elmt_now = elmt_next;
			elmt_next = elmt_next->next;
			del(elmt_now->content);
			free(elmt_now);
		}
	}
	*lst = NULL;
}
