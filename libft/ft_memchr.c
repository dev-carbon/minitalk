/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:37:03 by humanfou          #+#    #+#             */
/*   Updated: 2020/04/29 20:05:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	if (n == 0)
		return (NULL);
	cs = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (*(cs + i) == (unsigned char)c)
			return ((void *)(cs + i));
	return (NULL);
}
