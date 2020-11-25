/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:58:02 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/25 16:03:04 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

# define FIRST_WHITESPACE			9
# define LAST_WHITESPACE			13
# define SPACE						32
# define C_LONG_MAX					2147483647
# define C_LONG_MIN					-2147483648
# define C_LONG_MAX_STR				"2147483647"
# define C_LONG_MIN_STR				"-2147483648"

typedef struct	s_format
{
	char		type;
	int			flag_minus;
	int			flag_zero;
	int			flag_plus;
	int			flag_hash;
	int			flag_space;
	int			width;
	int			precision;
	int			symbols_to_skip;
}				t_format;

int				ft_printf(const char *format, ...);

int				ft_strlen(const char *s);
int				ft_putchar_count(const char c, int flag);
void			ft_putstr(char *s);
void			ft_nputstr(char *s, int n);

void			ft_putnbr(unsigned int n);
int				symbols_counter(int n);
int				symbols_counter_base16(int n);
void			ft_putdigit_16base_lowercase(int n);
void			ft_putdigit_16base_uppercase(int n);

int				ft_isdigit(int c);
int				ft_atoi(const char *str);

void			printing_char(t_format specificator, int c);
void			printing_strings(t_format specificator, char *string);
void			print_delimeter(int number, int flag);
void			print_spaces(int number);
void			print_zeros(int number);

void			printing(t_format specificator, va_list arg);
void			printing_decimal_unsigned_number(t_format specificator, unsigned int n);
void			printing_decimal_signed_number(t_format specificator, int n);
void			special_case(t_format specificator);

void			ft_putnbr_16base_lowercase(unsigned long n);
void			printing_base_16_lowercase(t_format specificator, unsigned long n);
void			ft_putnbr_16base_uppercase(unsigned int n);
void			printing_base_16_uppercase(t_format specificator, unsigned int n);

t_format		specificator_to_zero(void);

void			flag_parsing(t_format *specificator, const char *format);
void			width_parsing(t_format *specificator, const char *format, va_list arg);
void			presicion_parsing(t_format *specificator, const char *format, va_list arg);
void			type_parsing(t_format *specificator, const char *format);
t_format		format_parsing(const char *format, va_list arg);

void			ft_put_pointer(unsigned long n);
void			special_case_pointer(t_format specificator);
void			printing_pointer(t_format specificator, unsigned long n);
void			printing_percent(t_format specificator);

#endif
