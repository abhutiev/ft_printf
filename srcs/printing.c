/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_of_printing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 03:11:29 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 16:12:16 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	printing(t_format specificator, va_list arg)
{
	if (specificator.type == 'i' || specificator.type == 'd')
		printing_decimal_signed_number(specificator, va_arg(arg, int));
	else if (specificator.type == 'u')
		printing_decimal_unsigned_number(specificator, va_arg(arg, unsigned int));
	else if (specificator.type == '%')
		printing_percent(specificator);
	else if (specificator.type == 'c')
		printing_char(specificator, (va_arg(arg, int)));
	else if (specificator.type == 's')
		printing_strings(specificator, va_arg(arg, char *));
	else if (specificator.type == 'x')
		printing_base_16_lowercase(specificator, va_arg(arg, unsigned int));
	else if (specificator.type == 'X')
		printing_base_16_uppercase(specificator, va_arg(arg, unsigned int));
	else if (specificator.type == 'p')
		printing_pointer(specificator, va_arg(arg, unsigned long));
}

int		ft_putchar_count(char c, int flag)
{
	static int	counter;
	int			tmp;

	if (flag)
	{
		counter++;
		write(1, &c, 1);
		return (0);
	}
	else
	{
		tmp = counter;
		counter = 0;
		return (tmp);
	}
}
