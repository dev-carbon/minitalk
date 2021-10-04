/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:45:22 by humanfou          #+#    #+#             */
/*   Updated: 2021/10/01 01:45:25 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_pid(int	pid)
{
	ft_putstr_fd("PID : ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	int			bit;
	static int	size = 0;
	static char	byte = 0;
	static char	*msg = NULL;
	char		tmp[2];

	(void)context;
	(void)siginfo;
	bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	byte += (bit << size);
	size++;
	tmp[0] = '\0';
	tmp[1] = '\0';
	if (size == 8)
	{
		tmp[0] = byte;
		if (msg == NULL)
			msg = ft_strdup(tmp);
		else
			msg = ft_strjoin(msg, tmp);
		if (byte == '\0')
		{
			ft_putstr_fd(msg, STDOUT_FILENO);
			ft_putchar('\n');
			free(msg);
			msg = NULL;
		}
		byte = 0;
		size = 0;
		
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	display_pid(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}