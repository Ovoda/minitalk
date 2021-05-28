/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/28 19:31:29 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int	sig)
{
	static int	i = 0;

	if (sig == SIGUSR1)
	{
		ft_putstr("\033[0;32m✓");
		i++;
	}
}

void	ft_send_byte(int c, int server_id, int wait)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if ((c & (1 << i)) == 0)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		if (wait == 0)
			usleep(200);
		else
			pause();
		i++;
	}
}

void	send_client_pid(int c, int server_id)
{
	char	buffer[65];
	int		index;

	index = 0;
	while (c)
	{
		buffer[index] = c % 10 + 48;
		c /= 10;
		index++;
	}
	while (index--)
		ft_send_byte(buffer[index], server_id, 0);
	ft_send_byte(0, server_id, 0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	server_id;
	int	client_id;

	i = 0;
	signal(SIGUSR1, signal_handler);
	client_id = getpid();
	server_id = atoi(argv[1]);
	send_client_pid(client_id, server_id);
	while (argv[2][i])
		ft_send_byte(argv[2][i++], server_id, 1);
	ft_send_byte(0, server_id, 1);
	ft_putchar('\n');
	return (0);
}
