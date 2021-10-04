/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:21:19 by humanfou          #+#    #+#             */
/*   Updated: 2020/10/05 12:21:57 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putwchar_1(wchar_t c, int fd)
{
	char	put[1];

	put[0] = (char)c;
	write(fd, put, 1);
}

void	putwchar_2(wchar_t c, int fd)
{
	char	put[2];

	put[0] = (char)((c >> 6) | 0xc0);
	put[1] = (char)((c & 0x3f) | 0x80);
	write(fd, put, 2);
}

void	putwchar_3(wchar_t c, int fd)
{
	char	put[3];

	put[0] = (char)((c >> 12) | 0xe0);
	put[1] = (char)(((c >> 6 & 0x3f)) | 0x80);
	put[2] = (char)((c & 0x3f) | 0x80);
	write(fd, put, 3);
}

void	putwchar_4(wchar_t c, int fd)
{
	char	put[4];

	put[0] = (char)((c >> 18) | 0xf0);
	put[1] = (char)(((c >> 12) & 0x3f) | 0x80);
	put[2] = (char)(((c >> 6) & 0x3f) | 0x80);
	put[3] = (char)((c & 0x3f) | 0x80);
	write(fd, put, 4);
}

void	ft_putchar_fd(wchar_t c, int fd)
{
	if (c < 0x80)
		putwchar_1(c, fd);
	else if (c < 0x800)
		putwchar_2(c, fd);
	else if (c < 0x10000)
		putwchar_3(c, fd);
	else if (c < 0x20000)
		putwchar_4(c, fd);
}
