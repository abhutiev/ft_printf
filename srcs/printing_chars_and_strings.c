/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_chars_and_strings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:27:21 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 16:06:27 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_putstr(char *s)
{
	size_t	length;
	size_t	i;

	if (s == NULL)
		return ;
	length = ft_strlen(s);
	i = 0;
	while (i < length)
	{
		ft_putchar_count(s[i], 1);
		i++;
	}
}

void	ft_nputstr(char *s, int n)
{
	size_t	length;
	size_t	i;

	if (s == NULL)
		return ;
	length = ft_strlen(s);
	i = 0;
	while (i < length && i < n)
	{
		ft_putchar_count(s[i], 1);
		i++;
	}
}

void	printing_char(t_format specificator, int c)
{
	if (specificator.flag_zero && specificator.width > 1 && !specificator.flag_minus)
		print_zeros(specificator.width);
	if (!specificator.flag_zero && specificator.width > 1 && !specificator.flag_minus)
		print_spaces(specificator.width);
	ft_putchar_count(c, 1);
	if (!specificator.flag_zero && specificator.width > 1 && specificator.flag_minus)
		print_spaces(specificator.width);
}

void	printing_percent(t_format specificator)
{
	if (specificator.precision != -1)
		specificator.flag_zero = 0;
	specificator.precision = (specificator.precision > 1 ? specificator.precision : 1);
	if (!specificator.flag_minus)
		print_delimeter(specificator.width - specificator.precision + 1, specificator.flag_zero);
	print_zeros(specificator.precision);
	ft_putchar_count('%', 1);
	if (specificator.flag_minus)
		print_spaces(specificator.width - specificator.precision + 1);
}

void	printing_strings(t_format specificator, char *string)
{
	if (!string)
		return (printing_strings(specificator, "(null)"));
	if (specificator.precision < 0)
		specificator.precision = -1;
	if ((specificator.precision < 0 || specificator.precision >= ft_strlen(string)) && !specificator.flag_minus)
		print_delimeter(specificator.width - ft_strlen(string) + 1, specificator.flag_zero);
	else if (specificator.precision != -1 && !specificator.flag_minus)
		print_delimeter(specificator.width - specificator.precision + 1, specificator.flag_zero);
	if (specificator.precision == -1)
		ft_putstr(string);
	else
		ft_nputstr(string, specificator.precision);
	if ((specificator.precision == -1 || specificator.precision >= ft_strlen(string)) && specificator.flag_minus)
		print_delimeter(specificator.width - ft_strlen(string) + 1, specificator.flag_zero);
	else if (specificator.precision != -1 && specificator.flag_minus)
		print_delimeter(specificator.width - specificator.precision + 1, specificator.flag_zero);
}


