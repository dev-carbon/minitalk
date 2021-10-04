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

int	g_acked;

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

void	send_byte(pid_t pid, char byte)
{
	int		bit;
	int		shift;
	int		ret;

	shift = -1;
	while (++shift < 8)
	{
		g_acked = 0;
		bit = (byte >> shift) & 0x01;
		if (bit == 0)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
			quit(ERR_UNKNOW);
		while (g_acked == 0)
			pause();
	}
}

void	send_message(pid_t pid, char const *msg)
{
	int		i;

	i = -1;
	while (msg[++i] != '\0')
		send_byte(pid, msg[i]);
	send_byte(pid, msg[i]);
}

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)siginfo;
	(void)context;
	g_acked = 1;
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		quit(ERR_NUM_PARAMS);
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
		quit(ERR_BAD_PID);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(server_pid, argv[2]);
	return (0);
}
