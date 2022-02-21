/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aurele_sort_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:16:52 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 19:16:07 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*ft_bestmove(t_all *all, t_list *list)
{
	t_move	*move;

	move = malloc(sizeof(*move));
	if (move == 0)
		return (0);
	move->p = list;
	move->ra = ft_movera(all, list);
	move->rb = ft_range(list);
	move->rra = ft_moverra(all, list);
	move->rrb = *all->b->size - ft_range(list);
	if (move->rrb == *all->b->size)
		move->rrb = 0;
	if (move->ra < move->rb)
		move->rs = move->ra;
	else
		move->rs = move->rb;
	if (move->rra < move->rrb)
		move->rrs = move->rra;
	else
		move->rrs = move->rrb;
	move->upup = move->ra + move->rb - move->rs * 2;
	move->downdown = move->rra + move->rrb - move->rrs * 2;
	move->updown = move->ra + move->rrb;
	move->downup = move->rra + move->rb;
	return (ft_moveclean(move));
}

t_move	*ft_best(t_all *all)
{
	t_list	*mem;
	t_move	*yolo;
	t_move	*bestmove;

	mem = all->b->start;
	bestmove = 0;
	while (mem != all->b->start || bestmove == 0)
	{
		yolo = ft_bestmove(all, mem);
		if (yolo == 0)
			return (0);
		if (bestmove == 0 || yolo->movenbr < bestmove->movenbr)
		{
			if (bestmove != 0)
				free(bestmove);
			bestmove = yolo;
			if (bestmove->movenbr == 0 || bestmove->movenbr == 1)
				return (bestmove);
		}
		else
			free(yolo);
		mem = mem->next;
	}
	return (bestmove);
}

void	ft_intremoveonevaria(int i, ...)
{
	va_list	param;
	int		*p;

	va_start(param, i);
	while (i > 0)
	{
		p = va_arg(param, int *);
		(*p)--;
		i--;
	}
}

int	ft_movebest2(t_all *all, t_move *move)
{
	while (move->rra != 0)
	{
		ft_rra(all);
		move->rra--;
	}
	while (move->rb != 0)
	{
		ft_rb(all);
		move->rb--;
	}
	while (move->rrb != 0)
	{
		ft_rrb(all);
		move->rrb--;
	}
	return (1);
}

int	ft_movebest(t_all *all, t_move *move)
{
	if (move == 0)
		return (1);
	while (move->rs != 0)
	{
		ft_intremoveonevaria(3, &move->rb, &move->ra, &move->rs);
		ft_rs(all);
	}
	while (move->rrs != 0)
	{
		ft_intremoveonevaria(3, &move->rrb, &move->rra, &move->rrs);
		ft_rrs(all);
	}
	while (move->ra != 0)
	{
		ft_ra(all);
		move->ra--;
	}
	ft_movebest2(all, move);
	ft_pa(all);
	free(move);
	return (1);
}
