/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:13:52 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/09 14:41:32 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	len;
	int	nb;
	int	is_word;

	i = 0;
	nb = 0;
	len = ft_strlen((char *)s);
	while (i < len && s[i] != '\0')
	{
		is_word = 0;
		while (s[i] != c && i < len)
		{
			is_word = 1;
			i++;
		}
		nb += is_word;
		i++;
	}
	return (nb);
}

static int	word_len(char const *s, char c)
{
	int	word_len;

	word_len = 0;
	while (s[word_len] != c && s[word_len] != '\0')
		word_len += 1;
	return (word_len);
}

static char	**init_tab(int nbwords)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (nbwords + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	*init_word(int wordlen)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = init_tab(count_words(s, c));
	j = 0;
	k = 0;
	while (*(s + j) != 0)
	{
		if (*(s + j) != c && *(s + j) != 0)
		{
			tab[k] = init_word(word_len(s, c));
			i = 0;
			while (*(s + j) != c && *(s + j) != 0)
				tab[k][i++] = *(s + j++);
			tab[k++][i] = 0;
		}
		if (*(s + j++) == '\0')
			j -= 1;
	}
	tab[k] = NULL;
	return (tab);
}
