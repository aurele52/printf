/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:34:37 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/19 12:44:29 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_iintmin(int ret, t_flag flag) {
	flag.dotnbr = flag.dotnbr - 10;
	flag.nbr = flag.nbr - 11 - ft_flagclean(flag.dotnbr);
	ft_padding2(flag, 0, 1);
	write(1, "2147483648", 10);
	ft_padding(flag, 1);
	return (ret + 11 + ft_flagclean(flag.nbr) + ft_flagclean(flag.dotnbr));
}

int	ft_i(int nb, int ret, t_flag flag) {
	int	nbr;

	nbr = nb;
	if (nb == -2147483648)
		return (ft_iintmin(ret, flag));
	if (nb == 0)
		return (ft_izero(ret, flag));
	if (flag.plus == 1 || flag.espace == 1 || nb < 0) {
		ret++;
		flag.nbr--;
	}
	if (nb < 0)
		nb = -nb;
	while (nb > 0) {
		flag.nbr--;
		flag.dotnbr--;
		nb = nb / 10;
		ret++;
	}
	flag.nbr = flag.nbr - ft_flagclean(flag.dotnbr);
	ft_i2(nbr, flag);
	return (ret + ft_flagclean(flag.nbr) + ft_flagclean(flag.dotnbr));
}

int	ft_null(t_flag flag) {
	if (flag.point == 1) {
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

int	ft_s(char *str, int ret, t_flag flag) {
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

int	ft_p(unsigned long int addr, int ret, t_flag flag) {
	unsigned long int	mem;

	mem = addr;
	flag.nbr = flag.nbr - 2;
	if (addr == 0) {
		ret++;
		flag.nbr--;
	}
	while (addr > 0) {
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
