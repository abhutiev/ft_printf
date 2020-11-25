/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:25:18 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 16:07:05 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

t_format	specificator_to_zero(void)
{
	t_format	specificator;

	specificator.type = '~';
	specificator.flag_minus = 0;
	specificator.flag_plus = 0;
	specificator.flag_space = 0;
	specificator.flag_zero = 0;
	specificator.flag_hash = 0;
	specificator.precision = -1;
	specificator.width = 0;
	return (specificator);
}

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void		print_delimeter(int number, int flag)
{
	while (number-- && number > 0)
	{
		if (flag == 1)
			ft_putchar_count('0', 1);
		else
			ft_putchar_count(' ', 1);
	}
}

void		print_spaces(int number)
{
	while (number-- && number > 0)
	{
		ft_putchar_count(' ', 1);
	}
}

void		print_zeros(int number)
{
	while (number-- && number > 0)
	{
		ft_putchar_count('0', 1);
	}
}
