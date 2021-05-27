/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/27 16:35:17 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_byte	g_byte;

void    handle_signal(int signum)
{
	if (g_byte.client_is_new)
	{
		if (signum == SIGUSR1)
			g_byte.int_buffer[g_byte.index] = '0';
		else
			g_byte.int_buffer[g_byte.index] = '1';
	}
	else
	{
		if (signum == SIGUSR1)
			g_byte.char_buffer[g_byte.index] = '0';
		else
			g_byte.char_buffer[g_byte.index] = '1';
	}
	g_byte.index++;
}

char    get_byte()
{
	int dnum;
	int index;

	index = 0;
	dnum = 0;
	while (index <= 7)
	{
		if (g_byte.char_buffer[index] == '1')
			dnum = dnum | (128 >> index);
		index++;
	}
	return (dnum);
}

void    ft_send_binary(int c)
{
	for (int i = 7; i >= 0; --i)
	{   
		if ((c & (1 << i)) == 0)
			printf("0");
		else
			printf("1");
	}   
	printf("\n");
}

int	get_client_pid()
{
	int	client_id;
	int	index;
	char	tmp[19];

	g_byte.index = 0;
	client_id = 0;
	pause();
	index = 0;
	while (index < 64)
	{
		client_id += (g_byte.int_buffer[index] - 48) << index;
		index++;
	}
	return (client_id);
}

int main(int argc, char **argv)
{
	int	p_id;
	int	count_byte = 0;
	int	client_id;

	g_byte.index = 0;
	g_byte.cid = -1;
	g_byte.client_is_new = 1;
	p_id = getpid();
	ft_putstr("The server's PID is [");
	ft_putnbr(p_id);
	ft_putstr("]\nWaiting for communication...\n");
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	client_id = get_client_pid();
	g_byte.cid = client_id;
	g_byte.index = 0;
	printf("client_id = %d\n", client_id);
	while (1)
	{
		if (g_byte.index == 8)
		{
			ft_putchar(get_byte());
			if (ft_null(g_byte.char_buffer) == 1)
			{
				kill(client_id, SIGUSR2);
				client_id = get_client_pid();
				g_byte.cid = client_id;
				printf("client_id = %d\n", client_id);
			}
			g_byte.char_buffer[8] = 0;
			g_byte.index = 0;
		}
	}
	return (0);
}
