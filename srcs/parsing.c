/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 07:47:30 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 15:58:48 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void		flag_parsing(t_format *specificator, const char *format)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (format[i] == '-')
			(*specificator).flag_minus = 1;
		else if (format[i] == '+')
			(*specificator).flag_plus = 1;
		else if (format[i] == '0')
			(*specificator).flag_zero = 1;
		else if (format[i] == ' ')
			(*specificator).flag_space = 1;
		else if (format[i] == '#')
			(*specificator).flag_hash = 1;
		else
			break ;
		i++;
	}
	(*specificator).symbols_to_skip = i;
}

void		width_parsing(t_format *specificator, const char *format, va_list arg)
{
	if (format[(*specificator).symbols_to_skip] == '*')
	{
		(*specificator).width = va_arg(arg, int);
		if ((*specificator).width < 0)
		{
			(*specificator).width *= -1;
			(*specificator).flag_minus = 1;
		}
		(*specificator).symbols_to_skip++;
		return ;
	}
	(*specificator).width = ft_atoi(format + (*specificator).symbols_to_skip);
	while (ft_isdigit(format[(*specificator).symbols_to_skip]))
		(*specificator).symbols_to_skip++;
}

void		presicion_parsing(t_format *specificator, const char *format, va_list arg)
{
	if (format[(*specificator).symbols_to_skip] == '.')
		(*specificator).symbols_to_skip++;
	else
		return ;
	if (format[(*specificator).symbols_to_skip] == '*')
	{
		(*specificator).precision = va_arg(arg, int);
		(*specificator).symbols_to_skip++;
		return ;
	}
	(*specificator).precision = ft_atoi(format + (*specificator).symbols_to_skip);
	while (ft_isdigit(format[(*specificator).symbols_to_skip]))
		(*specificator).symbols_to_skip++;
}

void		type_parsing(t_format *specificator, const char *format)
{
	(*specificator).type = format[(*specificator).symbols_to_skip];
	(*specificator).symbols_to_skip++;
}

t_format	format_parsing(const char *format, va_list arg)
{
	t_format	specificator;
	size_t		i;

	i = 0;
	specificator = specificator_to_zero();
	flag_parsing(&specificator, format);
	i = specificator.symbols_to_skip;
	width_parsing(&specificator, format, arg);
	presicion_parsing(&specificator, format, arg);
	type_parsing(&specificator, format);
	return (specificator);
}
