/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/28 19:34:27 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_byte	g_byte;

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		singleton(0, 0);
	else
		singleton(0, 1);
	if (g_byte.cpid > 0)
	{
		usleep(200);
		kill(g_byte.cpid, SIGUSR1);
	}
	g_byte.index++;
}

void	server_pid_prompt(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server PID [");
	ft_putnbr(pid);
	ft_putstr("]\n");
}

int	new_client(void)
{
	int	pid;
	int	byte;

	while (1)
	{
		byte = singleton(1, 0);
		if (byte == 0)
			break ;
		if (byte != -1)
			pid = pid * 10 + byte - 48;
	}
	g_byte.cpid = pid;
	while (1)
	{
		byte = singleton(1, 0);
		if (byte == 0)
		{
			ft_putchar('\n');
			break ;
		}
		if (byte != -1)
			ft_putchar(byte);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	client_pid;
	int	byte;

	server_pid_prompt();
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		g_byte.cpid = 0;
		new_client();
	}
	return (0);
}
