/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:32:38 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/19 12:45:56 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_c(char c, int ret, t_flag flag) {
	if (flag.nbr > 0)
		flag.nbr--;
	if (flag.tiret == 0)
		ft_padding(flag, 2);
	write(1, &c, 1);
	if (flag.tiret == 1)
		ft_padding(flag, 2);
	return (ret + 1 + flag.nbr);
}

int	ft_izero(int ret, t_flag flag) {
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

int	ft_u(unsigned int nb, int ret, t_flag flag, int base) {
	unsigned int	nbr;

	if (flag.diese == 1 && flag.c == 'x' && nb != 0 && base == 16)
		ret = ret + write(1, "0x", 2);
	if (flag.diese == 1 && flag.c == 'X' && nb != 0 && base == 16)
		ret = ret + write(1, "0X", 2);
	if (nb == 0)
		return (ft_izero(ret, flag));
	nbr = nb;
	while (nb > 0) {
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

t_flag	ft_padding2(t_flag flag, int i, int moin) {
	while (flag.nbr-- > 0 && (((i == 1 || i == 2)
				&& flag.tiret == 1) || ((i == 0 || i == 2) && flag.tiret == 0))) {
		if (flag.zero == 1 && flag.tiret == 0 && flag.point == 0) {
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

void	ft_i2(int nb, t_flag flag) {
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
