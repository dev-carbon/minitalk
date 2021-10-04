/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 22:30:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/01 22:30:03 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	quit(int err)
{
	if (err == ERR_NUM_PARAMS)
		ft_putstr_fd("Usage:\t./client <server PID> <message>.\n", STDOUT_FILENO);
	if (err == ERR_BAD_PID)
		ft_putstr_fd("Error\nInvalid pid.\n", STDOUT_FILENO);
	if (err == ERR_UNKNOW)
		ft_putstr_fd("Error\nSomething when wring while sending signal.\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	send_message(pid_t pid, char const *msg)
{
	int		i;
	int		bit;
	int		shift;
	int		ret;

	i = -1;
	while (msg[++i] != '\0')
	{
		shift = -1;
		while (++shift < 8)
		{
			bit = (msg[i] >> shift) & 0x01;
			if (bit == 0)
				ret = kill(pid, SIGUSR1);
			else
				ret = kill(pid, SIGUSR2);
			if (ret == -1)
				quit(ERR_UNKNOW);
			usleep(MS);
		}
	}
	if (msg[i] == '\0')
	{
		shift = -1;
		while (++shift < 8)
		{
			if (kill(pid, SIGUSR1) == -1)
				quit(ERR_UNKNOW);
			usleep(MS);
		}
	}
}

void	display_pid(int	pid)
{
	ft_putstr_fd("PID : ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
		quit(ERR_NUM_PARAMS);
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
		quit(ERR_BAD_PID);
	send_message(server_pid, argv[2]);
	return (0);
}
