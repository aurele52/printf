/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:31:26 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/19 13:15:58 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_flagclean(int c) {
	if (c < 0)
		return (0);
	return (c);
}

int	ft_strlen(const char *str) {
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_hexa(size_t nbr, char maj) {
	char	c;

	c = (char)nbr;
	if (nbr <= 9)
		c = c + '0';
	else if (maj != 'X')
		c = c - 10 + 'a';
	else if (maj == 'X')
		c = c - 10 + 'A';
	write(1, &c, 1);
}

void	ft_putbase(size_t nbr, size_t base, char c) {
	if (nbr > base - 1)
		ft_putbase(nbr / base, base, c);
	nbr = nbr % base;
	if (base == 16)
		ft_hexa(nbr, c);
	else if (base == 10) {
		nbr = nbr % 10 + '0';
		write (1, &nbr, 1);
	}
}

t_flag	ft_padding(t_flag flag, int i) {
	while (flag.nbr-- > 0 && (((i == 1 || i == 2) && flag.tiret == 1)
			|| ((i == 0 || i == 2) && flag.tiret == 0))) {
		if (flag.zero == 1 && flag.tiret == 0 && flag.point == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	while (flag.dotnbr-- > 0 && flag.c != 's' && ((i == 0 || i == 2)))
		write(1, "0", 1);
	return (flag);
}
