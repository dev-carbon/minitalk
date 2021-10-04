/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:20:25 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/11 19:32:35 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	while (*src && n--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	while (n--)
		*dest = '\0';
	return (ptr);
}
