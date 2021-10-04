/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:55:45 by humanfou          #+#    #+#             */
/*   Updated: 2021/02/20 10:57:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nbr_to_string(int nbr)
{
	int		i;
	char	*str;
	int		len;

	i = -1;
	len = ft_nbrlen(nbr);
	str = ft_strnew(len);
	while (++i < len)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	ft_strrev(str);
	return (str);
}
