/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:12:39 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/27 20:17:20 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	i = -1;
	str = ft_strnew(n);
	if (!str)
		return (NULL);
	while (++i < n && s1[i] != '\0')
		str[i] = s1[i];
	return (str);
}
