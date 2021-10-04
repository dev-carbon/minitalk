/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:34:01 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 14:50:34 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	unsigned int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strrtrim(char const *s1, char const *set)
{
	char	*str;

	if (!s1)
		return (0);
	str = ft_strrev((char *)s1);
	while (check_set(*str, set))
		str++;
	str = ft_strrev(str);
	return (str);
}
