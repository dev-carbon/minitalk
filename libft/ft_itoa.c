/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:03:19 by humanfou          #+#    #+#             */
/*   Updated: 2020/09/23 19:57:06 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	secure_number(intmax_t nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}

static int	get_number_lenght(uintmax_t unbr, intmax_t nbr)
{
	if (nbr < 0)
		return (ft_nbrlen(unbr) + 1);
	return (ft_nbrlen(unbr));
}

char	*ft_itoa(intmax_t nbr)
{
	uintmax_t	unbr;
	int			number_length;
	int			i;
	char		*res;

	unbr = secure_number(nbr);
	number_length = get_number_lenght(unbr, nbr);
	res = (char *)malloc(sizeof(char) * (number_length + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (unbr > 0)
	{
		res[++i] = (int)unbr % 10 + '0';
		unbr /= 10;
	}
	if (nbr < 0)
		res[++i] = '-';
	res[++i] = '\0';
	return (ft_strrev(res));
}
