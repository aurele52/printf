/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:19:25 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/19 11:29:39 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_flagclean(int c)
{
	if (c < 0)
		return (0);
	return (c);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_hexa(size_t nbr, char c)
{
	char hexa[] = "0123456789abcdef";
	char hexamaj[] = "0123456789ABCDEF";

	if (c != 'X')
		write(1, &hexa[nbr], 1);
	if (c == 'X')
		write(1, &hexamaj[nbr], 1);

}

void	ft_putbase(size_t nbr, size_t base, char c)
{
	if (nbr > base - 1)
		ft_putbase(nbr / base, base, c);
	nbr = nbr % base;
	if (base == 16)
		ft_hexa(nbr, c);
	else if (base == 10)
	{
		nbr = nbr % 10 + '0';
		write (1, &nbr, 1);
	}
}

t_flag	ft_padding(t_flag flag, int	i)
{
	while (flag.nbr-- > 0 && (((i == 1 || i == 2) && flag.tiret == 1) || ((i == 0 || i == 2) && flag.tiret == 0)))
	{
		if (flag.zero == 1 && flag.tiret == 0 && flag.point == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	while (flag.dotnbr-- > 0 && flag.c != 's' && ((i == 0 || i == 2)))
		write(1, "0", 1);
	return (flag);
}

int	ft_c(char c, int ret, t_flag flag)
{
	if (flag.nbr > 0)
		flag.nbr--;
	if (flag.tiret == 0)
		ft_padding(flag, 2);
	write(1, &c, 1);
	if (flag.tiret == 1)
		ft_padding(flag, 2);
	return (ret + 1 + flag.nbr);
}

int	ft_izero(int ret, t_flag flag)
{
	flag.dotnbr--;
	if (!(flag.point == 1 && flag.dotnbr == -1))
		flag.nbr--;
	
	ft_padding(flag, 0);
	if (flag.plus == 1)
		ret = ret + write(1, "+", 1);
	else if (flag.espace == 1)
		ret = ret + write(1, " ", 1);
	if (!(flag.point == 1 && flag.dotnbr == -1))
		ret = ret + write(1, "0", 1);
	ft_padding(flag, 1);
	return (ret + ft_flagclean(flag.nbr) + ft_flagclean(flag.dotnbr));
}

int	ft_u(unsigned int nb, int ret, t_flag flag, int base)
{
	unsigned int nbr;

	if (flag.diese == 1 && flag.c == 'x' && nb != 0 && base == 16)
		ret = ret + write(1, "0x", 2);
	if (flag.diese == 1 && flag.c == 'X' && nb != 0 && base == 16)
		ret = ret + write(1, "0X", 2);
	if (nb == 0)
		return (ft_izero(ret, flag));
	nbr = nb;
	while (nb > 0)
	{
		flag.nbr--;
		flag.dotnbr--;
		nb = nb / base;
		ret++;
	}
	flag.nbr = flag.nbr - ft_flagclean(flag.dotnbr);
	ft_padding(flag, 0);
	ft_putbase(nbr, base, flag.c);
	ft_padding(flag, 1);
	return (ret + ft_flagclean(flag.nbr) + ft_flagclean(flag.dotnbr));
}

t_flag	ft_padding2(t_flag flag, int i, int moin)
{

	while (flag.nbr-- > 0 && (((i == 1 || i == 2) && flag.tiret == 1) || ((i == 0 || i == 2) && flag.tiret == 0)))
	{
		if (flag.zero == 1 && flag.tiret == 0 && flag.point == 0)
		{
			if (moin-- == 1)
				write(1, "-", 1);
			write(1, "0", 1);
		}
		else
			write(1, " ", 1);
	}
	if (moin-- == 1)
		write(1, "-", 1);
	while (flag.dotnbr-- > 0 && flag.c != 's' && ((i == 0 || i == 2)))
		write(1, "0", 1);
	return (flag);
}

void	ft_i2(int nb, t_flag flag)
{
	if (nb < 0)
		ft_padding2(flag, 0, 1);
	else
		ft_padding2(flag, 0, 0);
	if (nb < 0)
		nb = -nb;
	else if (flag.plus == 1)
		write(1, "+", 1);
	else if (flag.espace == 1)
		write(1, " ", 1);
	ft_putbase(nb, 10, 0);
	ft_padding(flag, 1);
}

int	ft_iintmin(int ret, t_flag flag)
{
	flag.dotnbr = flag.dotnbr - 10;
	flag.nbr = flag.nbr - 11 - ft_flagclean(flag.dotnbr);
	ft_padding2(flag, 0, 1);
	write(1, "2147483648",10);
	ft_padding(flag, 1);
	return (ret + 11 + ft_flagclean(flag.nbr) + ft_flagclean(flag.dotnbr));
}

int	ft_i(int nb, int ret, t_flag flag)
{
	int	nbr;

	nbr = nb;
	if (nb == -2147483648)
		return (ft_iintmin(ret, flag));
	if (nb == 0)
		return (ft_izero(ret, flag));
	if (flag.plus == 1 || flag.espace == 1 || nb < 0)
	{
		ret++;
		flag.nbr--;
	}
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		flag.nbr--;
		flag.dotnbr--;
		nb = nb / 10;
		ret++;
	}
	flag.nbr = flag.nbr - ft_flagclean(flag.dotnbr);
	ft_i2(nbr, flag);
	return (ret + ft_flagclean(flag.nbr) + ft_flagclean(flag.dotnbr));
}

int	ft_null(t_flag flag)
{
	if (flag.point == 1)
	{
		if (flag.dotnbr > 6)
			flag.dotnbr = 6;
		return (write(1, "(null)", flag.dotnbr));
	}
	flag.nbr = flag.nbr - 6;
	ft_padding(flag, 0);
	write(1, "(null)", 6);
	ft_padding(flag, 1);
	if (flag.nbr < 0)
		return (6);
	else
		return (6 + flag.nbr);
}

int	ft_s(char *str, int ret, t_flag flag)
{
	if (!str)
		return (ret + ft_null(flag));
	if (flag.point == 0 || ft_strlen(str) < flag.dotnbr)
		flag.dotnbr = ft_strlen(str);
	flag.point = 0;
	flag.nbr = flag.nbr - flag.dotnbr;
	if (flag.tiret == 0)
		ft_padding(flag, 2);
	write(1, str, flag.dotnbr);
	if (flag.tiret == 1)
		ft_padding(flag, 2);
	return (ret + flag.dotnbr + ft_flagclean(flag.nbr));
}

int	ft_p(unsigned long int addr, int ret, t_flag flag)
{
	unsigned long int	mem;

	mem = addr;
	flag.nbr = flag.nbr - 2;
	if (addr == 0)
	{
		ret++;
		flag.nbr--;
	}
	while (addr > 0)
	{
		addr = addr / 16;
		flag.nbr--;
		ret++;
	}
	if (flag.nbr > 0)
		ret = ret + flag.nbr;
	ft_padding(flag, 0);
	ret = ret + write(1, "0x", 2);
	ft_putbase(mem, 16, 0);
	ft_padding(flag, 1);
	return (ret);
}

int	ft_conversion(t_flag flag, va_list args, char str, int ret)
{
	int		i;

	i = 0;
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

t_flag	ft_setzeroflag(t_flag flag)
{
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

t_flag	ft_setflagnbr(t_flag flag, const char *c)
{
	int	i;

	i = 0;
	if (*c == '0' && !(*(c - 1) <= '9' && *(c - 1) >= '0'))
	{
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

t_flag	ft_setflag(t_flag flag, const char *c)
{
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

int	ft_printf(const char* str, ...)
{
	int		i;
	int		ret;
	t_flag	flag;
	va_list	args;

	ret = 0;
	va_start (args, str);
	while (*str)
	{
		i = 1;
		flag = ft_setzeroflag(flag);
		if (*str == '%')
		{
			while (str[i] == ' ' || str[i] == '-' || str[i] == '0' || str[i] == '+' ||str[i] == '.' || str[i] == '#' || (str[i] >= '0' && str[i] <= '9'))
				flag = ft_setflag(flag, &str[i++]);
			if (str[i] == 'i' || str[i] == 'u' || str[i] == 'd' || str[i] == 'x' || str[i] == 'X' || str[i] == 'p' || str[i] == 's' || str[i] == 'c' || str[i] == '%')
				ret = ft_conversion(flag, args, str[i], ret);
			str = str + i + 1;
		}
		else
		{
			write(1, str, 1);
			ret++;
			str++;
		}
	}
	va_end (args);
	return (ret);
}
