/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:49:04 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 15:59:03 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_put_pointer(unsigned long n)
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

void	printing_pointer(t_format specificator, unsigned long n)
{
	if (specificator.precision != -1)
		specificator.flag_zero = 0;
	specificator.precision = (specificator.precision >
			symbols_counter_base16(n) ? specificator.precision : symbols_counter_base16(n));
	if (!specificator.flag_minus)
		print_delimeter(specificator.width - specificator.precision - 3, specificator.flag_zero);
	print_zeros(specificator.precision - symbols_counter_base16(n) - 3);
	ft_nputstr("0x", 2);
	ft_put_pointer(n);
	if (specificator.flag_minus)
		print_spaces(specificator.width - specificator.precision - 3);
}
