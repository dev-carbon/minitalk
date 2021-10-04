/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:38:54 by humanfou          #+#    #+#             */
/*   Updated: 2020/01/11 16:50:47 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	dst_len;
	size_t	i;

	len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (len + dstsize);
	else
		len += dst_len;
	i = 0;
	while (src[i] != '\0' && dst_len < dstsize - 1)
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (len);
}
