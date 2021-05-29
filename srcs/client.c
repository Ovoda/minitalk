/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/29 14:17:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int	sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Message sent\n");
}

void	ft_send_byte(int c, int server_id)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)) == 0)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		usleep(200);
		--i;
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
		ft_send_byte(buffer[index], server_id);
	ft_send_byte(0, server_id);
}

int	main(int argc, char **argv)
{
	int	i;
	int	server_id;
	int	client_id;

	i = 0;
	if (check_params_client(argc, argv) == -1)
		return (0);
	signal(SIGUSR1, signal_handler);
	client_id = getpid();
	server_id = ft_atoi(argv[1]);
	send_client_pid(client_id, server_id);
	while (argv[2][i])
		ft_send_byte(argv[2][i++], server_id);
	ft_send_byte(0, server_id);
	return (0);
}
