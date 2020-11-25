/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_decimal_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:43:35 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 16:07:59 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_putnbr(unsigned int n)
{
	long long safe;

	safe = n;
	if (safe >= 10)
	{
		ft_putnbr(safe / 10);
		ft_putchar_count(safe % 10 + '0', 1);
	}
	else
		ft_putchar_count(safe + '0', 1);
}

int		symbols_counter(int n)
{
	int		digits_counter;

	digits_counter = 1;
	if (n < 0)
	{
		n = -n;
		digits_counter++;
	}
	while (n /= 10)
	{
		digits_counter++;
	}
	return (digits_counter);
}

void	special_case(t_format specificator)
{
	if (specificator.width == 0)
		return ;
	else
		print_spaces(specificator.width + 1);
}

void	printing_decimal_unsigned_number(t_format specificator, unsigned int n)
{
	if (n == 0 && specificator.precision == 0)
		return (special_case(specificator));
	if (specificator.precision != -1)
		specificator.flag_zero = 0;
	specificator.precision = (specificator.precision > symbols_counter(n) ?
	specificator.precision : symbols_counter(n));
	if (!specificator.flag_minus)
		print_delimeter(specificator.width - specificator.precision + 1,
		specificator.flag_zero);
	if (specificator.flag_plus)
		ft_putchar_count('+', 1);
	else if (specificator.flag_space)
		ft_putchar_count(' ', 1);
	print_zeros(specificator.precision - symbols_counter(n) + 1);
	ft_putnbr(n);
	if (specificator.flag_minus)
		print_spaces(specificator.width - specificator.precision + 1);
}

void	printing_decimal_signed_number(t_format specificator, int n)
{
	if (n >= 0)
		printing_decimal_unsigned_number(specificator, (unsigned int)n);
	else
	{
		n = -n;
		if (n == 0 && specificator.precision == 0)
			return (special_case(specificator));
		if (specificator.precision != -1)
			specificator.flag_zero = 0;
		specificator.precision = (specificator.precision > symbols_counter(n) ? specificator.precision : symbols_counter(n));
		if (specificator.flag_zero)
			ft_putchar_count('-', 1);
		if (!specificator.flag_minus)
			print_delimeter(specificator.width - specificator.precision,
			specificator.flag_zero);
		if (!specificator.flag_zero)
			ft_putchar_count('-', 1);
		print_zeros(specificator.precision - symbols_counter(n) + 1);
		ft_putnbr(n);
		if (specificator.flag_minus)
			print_spaces(specificator.width - specificator.precision);
	}
}
