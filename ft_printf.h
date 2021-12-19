/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:22:00 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/18 13:01:49 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int	ft_printf(const char* str, ...);

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
} t_flag;

#endif
