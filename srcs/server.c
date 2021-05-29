/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/29 14:14:42 by calide-n         ###   ########.fr       */
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

	pid = 0;
	while (1)
	{
		byte = singleton(1, 0);
		if (byte == 0)
			break ;
		if (byte != -1)
			pid = pid * 10 + byte - 48;
	}
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
	kill(pid, SIGUSR1);
	return (pid);
}

int	main(int argc, char **argv)
{
	if (check_params_server(argc, argv) == -1)
		return (0);
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
