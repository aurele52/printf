/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:19:25 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/19 13:25:47 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_conversion(t_flag flag, va_list args, char str, int ret) {
	flag.c = str;
	if (str == 'c')
		ret = ft_c((char)va_arg(args, int), ret, flag);
	else if (str == 'i' || str == 'd')
		ret = ft_i(va_arg(args, int), ret, flag);
	else if (str == 's')
		ret = ft_s(va_arg(args, char *), ret, flag);
	else if (str == 'p')
		ret = ft_p((unsigned long int)va_arg(args, void *), ret, flag);
	else if (str == 'u')
		ret = ft_u((unsigned int)va_arg(args, int), ret, flag, 10);
	else if (str == '%')
		return (ret + write(1, "%", 1));
	else if (str == 'x')
		ret = ft_u((unsigned int)va_arg(args, int), ret, flag, 16);
	else if (str == 'X')
		ret = ft_u((unsigned int)va_arg(args, int), ret, flag, 16);
	return (ret);
}

t_flag	ft_setzeroflag(t_flag flag) {
	flag.tiret = 0;
	flag.zero = 0;
	flag.point = 0;
	flag.diese = 0;
	flag.plus = 0;
	flag.espace = 0;
	flag.nbr = 0;
	flag.dotnbr = 0;
	flag.c = 0;
	return (flag);
}

t_flag	ft_setflagnbr(t_flag flag, const char *c) {
	int	i;

	i = 0;
	if (*c == '0' && !(*(c - 1) <= '9' && *(c - 1) >= '0')) {
		flag.zero = 1;
		return (flag);
	}
	while (c[i] <= '9' && c[i] >= '0')
		i--;
	if (c[i] == '.')
		flag.dotnbr = flag.dotnbr * 10 + *c - '0';
	else
		flag.nbr = flag.nbr * 10 + *c - '0';
	return (flag);
}

t_flag	ft_setflag(t_flag flag, const char *c) {
	if (*c == ' ')
		flag.espace = 1;
	if (*c == '+')
		flag.plus = 1;
	if (*c == '.')
		flag.point = 1;
	if (*c == '-')
		flag.tiret = 1;
	if (*c == '#')
		flag.diese = 1;
	if (*c <= '9' && *c >= '0')
		return (ft_setflagnbr(flag, c));
	return (flag);
}

int	ft_printf(const char *str, ...) {
	int		ret;
	t_flag	flag;
	va_list	args;

	ret = 0;
	va_start (args, str);
	while (*str) {
		flag = ft_setzeroflag(flag);
		if (*str == '%') {
			while (*++str == ' ' || *str == '-' || *str == '0'
				|| *str == '+' || *str == '.' || *str == '#'
				|| (*str >= '0' && *str <= '9'))
				flag = ft_setflag(flag, str);
			if (*str == 'i' || *str == 'u' || *str == 'd'
				|| *str == 'x' || *str == 'X' || *str == 'p'
				|| *str == 's' || *str == 'c' || *str == '%')
				ret = ft_conversion(flag, args, *str++, ret);
		}
		else
			ret = ret + write(1, str++, 1);
	}
	va_end (args);
	return (ret);
}
