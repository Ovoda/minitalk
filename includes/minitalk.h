/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:56:31 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/28 19:41:08 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_byte
{
	int			index;
	int			pid;
	int			lient_is_new;
	char		buffer[9];
}				t_byte;

int		ft_null(char *buffer);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		singleton(int mode, int value);

#endif
