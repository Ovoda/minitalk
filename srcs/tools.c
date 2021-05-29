/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:19:52 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/29 13:59:29 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(char const *str)
{
	int				i;
	long long int	sign;
	long long int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + ((long long int)str[i] - 48);
		if (nb > 2147483648 && sign == 1)
			return (-1);
		if (nb > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (nb * sign);
}

int	ft_null(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		if (buffer[i++] != '0')
			return (0);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	write(1, str, i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putstr("-");
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	ft_putchar(nb + 48);
}
