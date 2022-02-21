/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:18:53 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 17:57:39 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		else
		{
			write(1, "-", 1);
			nbr = -nbr;
		}
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + '0';
	write (1, &nbr, 1);
}

int	ft_atoi(const char *str)
{
	int	moin;
	int	res;

	res = 0;
	moin = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			moin = -1;
	while (*str <= '9' && *str >= '0' && *str)
		res = res * 10 + (*(str++) - '0');
	return (res * moin);
}

t_all	*ft_setlist(char *str, t_all *all)
{
	int	i;

	i = 0;
	while (str[i])
	{
		all->a->end = ft_lstnew(ft_atoi(&str[i]), all->a);
		if (all->a->end == 0)
			return (ft_free(all));
		while (str[i] != 0 && str[i] != ' ')
			i++;
		if (str[i] == ' ')
			i++;
	}
	return (all);
}

void	*ft_free(t_all *all)
{
	while (all->a->start != all->a->end)
	{
		all->a->start = all->a->start->next;
		free(all->a->start->back);
	}
	free(all->a->start);
	free(all->a->size);
	free(all->a);
	while (all->b->start != all->b->end)
	{
		all->b->start = all->b->start->next;
		free(all->b->start->back);
	}
	free(all->b->start);
	free(all->b->size);
	free(all->b);
	free(all);
	return (0);
}

int	ft_correct(t_all *all)
{
	t_list	*i;

	if (all->b->start != 0)
		return (0);
	i = all->a->start;
	while (i != all->a->end)
	{
		if (i->content > i->next->content)
			return (0);
		i = i->next;
	}
	return (1);
}
