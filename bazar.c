/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:16:57 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 19:22:49 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*ft_moveclean(t_move *mv)
{
	if (mv->upup <= mv->updown && mv->upup <= mv->downup
		&& mv->upup <= mv->downdown)
		ft_setintzerovaria(3, &mv->rra, &mv->rrb, &mv->rrs);
	else if (mv->downdown <= mv->updown && mv->downdown <= mv->downup
		&& mv->downdown <= mv->upup)
		ft_setintzerovaria(3, &mv->ra, &mv->rb, &mv->rs);
	else if (mv->updown <= mv->upup && mv->updown <= mv->downup
		&& mv->updown <= mv->downdown)
		ft_setintzerovaria(4, &mv->rra, &mv->rb, &mv->rrs, &mv->rs);
	else if (mv->downup <= mv->updown && mv->downup <= mv->upup
		&& mv->downup <= mv->downdown)
		ft_setintzerovaria(4, &mv->ra, &mv->rrb, &mv->rrs, &mv->rs);
	mv->movenbr = mv->ra + mv->rb + mv->rra + mv->rrb - mv->rrs - mv->rs;
	return (mv);
}

void	ft_delone(t_list *list)
{
	*list->pos->size = *list->pos->size - 1;
	if (list->pos->end == list->pos->start)
	{
		list->pos->end = 0;
		list->pos->start = 0;
	}
	else
	{
		if (list->pos->end == list)
			list->pos->end = list->back;
		if (list->pos->start == list)
			list->pos->start = list->next;
		list->back->next = list->next;
		list->next->back = list->back;
	}
	free(list);
}

char	*ft_join(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup("");
	if (str == 0)
		return (0);
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		if (str == 0)
			return (0);
		i++;
	}
	return (str);
}

int	ft_checkall(t_all *all)
{
	t_list	*a;
	t_list	*b;

	a = all->a->start;
	b = 0;
	while (b == 0 || a != all->a->start)
	{
		b = a->next;
		while (b != all->a->start)
		{
			if (b->content == a->content)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}
