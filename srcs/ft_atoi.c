/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:25:25 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 15:58:34 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static int	ft_iswhitespace(char str)
{
	if ((str >= FIRST_WHITESPACE && str <= LAST_WHITESPACE) || (str == SPACE))
		return (1);
	else
		return (0);
}

static int	ft_is_sign(char str)
{
	if ((str == '-') || (str == '+'))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	res;
	unsigned int	big;

	big = C_LONG_MAX / 10;
	sign = 1;
	i = 0;
	res = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (ft_is_sign(str[i]))
		if (str[i++] == '-')
			(sign = -1);
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return ((int)(res) * sign);
}
