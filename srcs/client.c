/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/27 16:33:54 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int	sig)
{
	if (sig == SIGUSR1)
		printf("\nBit sent to server !\n");
	else
	{
		printf("\nMessage fully received by server !\nexiting...");
		exit(0);
	}
}

void	ft_send_binary(int c, int server_id)
{
	for (int i = 7; i >= 0; --i)
	{
		if ((c & (1 << i)) == 0)
		{
			kill(server_id, SIGUSR1);
			printf("0");
		}
		else
		{
			kill(server_id, SIGUSR2);
			printf("1");
		}
		usleep(50);
	}
	printf("\n");
}

void	send_client_pid(int c, int server_id)
{
	int		index;
	char	buffer[65];

	index = 63;
	while (index >= 0)
	{
		if (c & 1)
			kill(server_id, SIGUSR1);
			//buffer[index] = '1';
		else
			kill(server_id, SIGUSR2);
			//buffer[index] = '0';
		c >>= 1;
		index--;
	}
	buffer[index] = 0;
//	index = 0;
//	while (index <= 63)
//	{
//		if (buffer[index] == '1')
//			kill(server_id, SIGUSR1);
//		else
//			kill(server_id, SIGUSR2);
//		index++;
//	}
	ft_send_binary(0, server_id);
}

int main(int argc, char **argv)
{
	int	i;
	int	server_id;
	int	client_id;

	i = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	client_id = getpid();
	printf("client PID = %d\n", client_id);
	server_id = atoi(argv[1]);
	send_client_pid(client_id, server_id);
	while (argv[2][i])
	{
		//		pause();
		ft_putstr("Executing signal...\n");
		ft_send_binary(argv[2][i++], server_id);
	}
	ft_send_binary(0, server_id);
	return (0);
}
