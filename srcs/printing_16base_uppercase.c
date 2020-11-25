/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_16base_uppercase.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:09:57 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 16:11:01 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_putnbr_16base_uppercase(unsigned int n)
{
	long long safe;

	safe = n;
	if (safe >= 16)
	{
		ft_putnbr_16base_uppercase(safe / 16);
		ft_putdigit_16base_uppercase(safe % 16);
	}
	else
		ft_putdigit_16base_uppercase(safe);
}

void	printing_base_16_uppercase(t_format specificator, unsigned int n)
{
	if (n == 0 && specificator.precision == 0)
		return (special_case(specificator));
	if (specificator.precision != -1)
		specificator.flag_zero = 0;
	specificator.precision = (specificator.precision > symbols_counter_base16(n) ? specificator.precision : symbols_counter_base16(n));
	if (!specificator.flag_minus)
		print_delimeter(specificator.width - specificator.precision + 1, specificator.flag_zero);
	print_zeros(specificator.precision - symbols_counter_base16(n) + 1);
	if (specificator.flag_plus)
		ft_putchar_count('+', 1);
	else if (specificator.flag_space)
		ft_putchar_count(' ', 1);
	if (specificator.flag_hash)
		ft_nputstr("0X", 2);
	ft_putnbr_16base_uppercase(n);
	if (specificator.flag_minus)
		print_spaces(specificator.width - specificator.precision + 1);
}

void	ft_putdigit_16base_uppercase(int n)
{
	if (n == 15)
		ft_putchar_count('F', 1);
	else if (n == 14)
		ft_putchar_count('E', 1);
	else if (n == 13)
		ft_putchar_count('D', 1);
	else if (n == 12)
		ft_putchar_count('C', 1);
	else if (n == 11)
		ft_putchar_count('B', 1);
	else if (n == 10)
		ft_putchar_count('A', 1);
	else
		ft_putchar_count(n + '0', 1);
}
