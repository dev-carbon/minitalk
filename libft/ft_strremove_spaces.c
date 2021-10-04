/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:07:03 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 15:05:46 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strremove_spaces(char *src)
{
	int		i;
	int		j;
	char	*trim;

	trim = ft_strtrim(src, " ");
	i = -1;
	j = -1;
	while (trim[++i] != '\0')
		if (trim[i] != ' ')
			src[++j] = trim[i];
	src[++j] = '\0';
	free(trim);
	return (src);
}
