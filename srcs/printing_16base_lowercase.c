/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_16base_lowercase.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 05:12:13 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 16:11:41 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int		symbols_counter_base16(int n)
{
	int		digits_counter;

	digits_counter = 1;
	if (n < 0)
	{
		n = -n;
		digits_counter++;
	}
	while (n /= 16)
	{
		digits_counter++;
	}
	return (digits_counter);
}

void	ft_putnbr_16base_lowercase(unsigned long n)
{
	long long safe;

	safe = n;
	if (safe >= 16)
	{
		ft_putnbr_16base_lowercase(safe / 16);
		ft_putdigit_16base_lowercase(safe % 16);
	}
	else
		ft_putdigit_16base_lowercase(safe);
}

void	printing_base_16_lowercase(t_format specificator, unsigned long n)
{
	if (n == 0 && specificator.precision == 0)
		return (special_case(specificator));
	if (specificator.precision != -1)
		specificator.flag_zero = 0;
	specificator.precision = (specificator.precision >
		symbols_counter_base16(n) ? specificator.precision : symbols_counter_base16(n));
	if (!specificator.flag_minus)
		print_delimeter(specificator.width - specificator.precision + 1, specificator.flag_zero);
	print_zeros(specificator.precision - symbols_counter_base16(n) + 1);
	if (specificator.flag_plus)
		ft_putchar_count('+', 1);
	else if (specificator.flag_space)
		ft_putchar_count(' ', 1);
	if (specificator.flag_hash)
		ft_nputstr("0X", 2);
	ft_putnbr_16base_lowercase(n);
	if (specificator.flag_minus)
		print_spaces(specificator.width - specificator.precision + 1);
}

void	ft_putdigit_16base_lowercase(int n)
{
	if (n == 15)
		ft_putchar_count('f', 1);
	else if (n == 14)
		ft_putchar_count('e', 1);
	else if (n == 13)
		ft_putchar_count('d', 1);
	else if (n == 12)
		ft_putchar_count('c', 1);
	else if (n == 11)
		ft_putchar_count('b', 1);
	else if (n == 10)
		ft_putchar_count('a', 1);
	else
		ft_putchar_count(n + '0', 1);
}
