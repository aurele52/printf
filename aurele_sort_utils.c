/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aurele_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:15:39 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 19:21:45 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_triathree(t_all *all)
{
	t_list	*mem;
	int		nbr;

	nbr = 0;
	mem = all->a->start;
	while (mem != mem->pos->end)
	{
		if (mem->content < mem->next->content)
			nbr++;
		mem = mem->next;
	}
	if (mem->content < mem->next->content)
		nbr++;
	if (nbr == 1)
		ft_sa(all);
	if (all->a->start->content > all->a->start->next->content)
		ft_ra(all);
	if (all->a->start->next->content > all->a->start->next->next->content)
		ft_rra(all);
}

void	ft_transfer(t_all *all)
{
	t_list	*median;
	t_list	*max;
	t_list	*min;

	max = ft_max(all->a);
	median = ft_median(all->a->start, all->a->end);
	min = ft_min(all->a);
	while (*all->a->size > 3)
	{
		if (all->a->start != median
			&& all->a->start != max && all->a->start != min)
		{
			ft_pb(all);
			if (all->b->start->content < median->content)
				ft_rb(all);
		}
		else
			ft_ra(all);
	}
}

int	ft_moverra(t_all *all, t_list *list)
{
	int		nbr;
	t_list	*mem;

	nbr = 0;
	mem = all->a->start;
	while (!(list->content < mem->content
			&& list->content > mem->back->content))
	{
		mem = mem->back;
		nbr++;
	}
	return (nbr);
}

int	ft_movera(t_all *all, t_list *list)
{
	int		nbr;
	t_list	*mem;

	nbr = 0;
	mem = all->a->start;
	while (!(list->content < mem->content
			&& list->content > mem->back->content))
	{
		mem = mem->next;
		nbr++;
	}
	return (nbr);
}

void	ft_setintzerovaria(int i, ...)
{
	va_list	param;
	int		*p;

	va_start(param, i);
	while (i > 0)
	{
		p = va_arg(param, int *);
		*p = 0;
		i--;
	}
}
