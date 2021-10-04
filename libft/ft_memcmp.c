/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:36:46 by humanfou          #+#    #+#             */
/*   Updated: 2020/01/07 17:01:33 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = -1;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (++i < n)
		if (*(p1 + i) != *(p2 + i))
			return (*(p1 + i) - *(p2 + i));
	return (0);
}
