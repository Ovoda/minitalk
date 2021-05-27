/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:56:31 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/27 15:46:31 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIALK_H
# define MINIALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct  s_byte
{
    int     index;
	int		cid;
	int		client_is_new;
    char    int_buffer[65];
    char    char_buffer[9];
}               t_byte;

int		ft_null(char *buffer);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);


#endif
