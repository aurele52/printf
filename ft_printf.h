/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:22:00 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/19 12:51:14 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag
{
	int		tiret;
	int		zero;
	int		point;
	int		diese;
	int		plus;
	int		espace;
	int		nbr;
	int		dotnbr;
	char	c;
}	t_flag;

int		ft_conversion(t_flag flag, va_list args, char str, int ret);
t_flag	ft_setzeroflag(t_flag flag);
t_flag	ft_setflagnbr(t_flag flag, const char *c);
t_flag	ft_setflag(t_flag flag, const char *c);
int		ft_flagclean(int c);
int		ft_strlen(const char *str);
void	ft_hexa(size_t nbr, char c);
void	ft_putbase(size_t nbr, size_t base, char c);
t_flag	ft_padding(t_flag flag, int i);
int		ft_c(char c, int ret, t_flag flag);
int		ft_izero(int ret, t_flag flag);
int		ft_u(unsigned int nb, int ret, t_flag flag, int base);
t_flag	ft_padding2(t_flag flag, int i, int moin);
void	ft_i2(int nb, t_flag flag);
int		ft_iintmin(int ret, t_flag flag);
int		ft_i(int nb, int ret, t_flag flag);
int		ft_null(t_flag flag);
int		ft_s(char *str, int ret, t_flag flag);
int		ft_p(unsigned long int addr, int ret, t_flag flag);
int		ft_printf(const char *str, ...);

#endif
