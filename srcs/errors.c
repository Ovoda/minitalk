/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:50:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/29 14:14:19 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_error(char *str)
{
	ft_putstr(str);
	return (-1);
}

int	check_params_server(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
		return (ft_error("Server doesn't require any arguments\n"));
	return (0);
}

int	ft_is_only_digits(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	return (0);
}

int	check_params_client(int argc, char **argv)
{
	if (argc != 3)
		return (ft_error("Error: wrong number of arguments\n"));
	if (ft_is_only_digits(argv[1]) == -1
		|| ft_atoi(argv[1]) > 2147483647 || ft_atoi(argv[1]) < 0)
		return (ft_error("Error: arg2 invalid\n"));
	return (0);
}
