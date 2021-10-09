/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:45:22 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/04 23:43:26 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ping_client(int bit, int pid)
{
	if (bit == -1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

static char	*build_message(char	*msg, char byte)
{
	char	*buff;
	char	tmp[2];

	tmp[0] = byte;
	tmp[1] = 0;
	if (msg == NULL)
		msg = ft_strdup(tmp);
	else
	{
		buff = msg;
		msg = ft_strjoin(buff, tmp);
		free(buff);
	}
	return (msg);
}

static void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	int			bit;
	static int	size = 0;
	static char	byte = 0;
	static char	*msg = NULL;

	(void)context;
	bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	byte += (bit << size++);
	if (size == 8)
	{
		msg = build_message(msg, byte);
		if (byte == '\0')
		{
			write(STDOUT_FILENO, msg, ft_strlen(msg) + 1);
			free(msg);
			msg = NULL;
			bit = -1;
		}
		byte = 0;
		size = 0;
	}
	ping_client(bit, siginfo->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
		pause();
	return (0);
}
