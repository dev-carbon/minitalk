/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 22:30:02 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/04 23:43:36 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_acked = 0;

static void	escape(int err)
{
	if (err == ERR_NUM_PARAMS)
		ft_putstr_fd("Usage:\t./client <server PID> <message>.\n",
			STDOUT_FILENO);
	if (err == ERR_BAD_PID)
		ft_putstr_fd("Error\nInvalid pid.\n", STDOUT_FILENO);
	if (err == ERR_UNKNOW)
		ft_putstr_fd("Error\nSignal pending.\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

static void	send_byte(pid_t pid, char byte)
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
			escape(ERR_UNKNOW);
		while (g_acked == 0)
			pause();
	}
}

static void	send_message(pid_t pid, char const *msg)
{
	int	i;

	i = -1;
	while (msg[++i] != '\0')
		send_byte(pid, msg[i]);
	send_byte(pid, msg[i]);
}

static void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	count = 0;

	(void)sig;
	(void)siginfo;
	(void)context;
	if (sig == SIGUSR1)
	{
		count += 1;
		write(STDOUT_FILENO, "1 byte received\n", 16);
	}
	else if (sig == SIGUSR2)
	{
		write(STDOUT_FILENO, "Server received: ", 17);
		ft_putnbr_fd(++count / 8, STDOUT_FILENO);
		write(STDOUT_FILENO, " byte(s)\n", 9);
	}
	g_acked = 1;
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		escape(ERR_NUM_PARAMS);
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0)
		escape(ERR_BAD_PID);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_message(server_pid, argv[2]);
	return (0);
}
