/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:30:48 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 15:58:43 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int			ft_printf(const char *format, ...)
{
	size_t		i;
	t_format	specificator;
	va_list		arg;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_count(format[i], 1);
		else if (format[i] == '%')
		{
			specificator = format_parsing(format + i + 1, arg);
			printing(specificator, arg);
			i += specificator.symbols_to_skip;
		}
		i++;
	}
	va_end(arg);
	return (ft_putchar_count('~', 0));
}
