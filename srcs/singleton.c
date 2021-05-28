/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:55:20 by calide-n          #+#    #+#             */
/*   Updated: 2021/05/27 20:09:51 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	singleton(int mode, int value)
{
	static char	c;
	static int	index = 0;
	char		ret;

	if (mode == 1)
	{
		if (index == 8)
		{
			ret = c;
			index = 0;
			c = 0;
			return (ret);
		}
		return (-1);
	}
	else if (value == 1)
		c = c | (128 >> index);
	index++;
	return (c);
}
