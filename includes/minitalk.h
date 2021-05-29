/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:56:31 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/29 14:16:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

typedef struct s_byte
{
	int			index;
	int			cpid;
}				t_byte;

int		ft_null(char *buffer);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		singleton(int mode, int value);
int		ft_error(char *str);
int		check_params_server(int argc, char **argv);
int		check_params_client(int argc, char **argv);
int		ft_atoi(char const *str);

#endif
