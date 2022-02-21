/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:36:46 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 18:20:56 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_min(t_pos *pos)
{
	t_list	*min;
	t_list	*list;

	min = pos->start;
	list = pos->start->next;
	while (list != pos->start)
	{
		if (min->content > list->content)
			min = list;
		list = list->next;
	}
	return (min);
}

int	ft_range(t_list *list)
{
	t_list	*mem;
	int		nbr;

	nbr = 0;
	mem = list->pos->start;
	while (list != mem)
	{
		nbr++;
		mem = mem->next;
	}
	return (nbr);
}

t_list	*ft_max(t_pos *pos)
{
	t_list	*max;
	t_list	*list;

	max = pos->start;
	list = pos->start->next;
	while (list != pos->start)
	{
		if (max->content < list->content)
			max = list;
		list = list->next;
	}
	return (max);
}

t_list	*ft_median(t_list *start, t_list *end)
{
	t_list	*medianpot;
	t_list	*mem;
	int		nbr;

	medianpot = start;
	while (1)
	{
		nbr = 0;
		mem = start;
		while (mem != end && nbr < *start->pos->size / 2 + 1)
		{
			if (mem->content > medianpot->content)
				nbr++;
			mem = mem->next;
		}
		if (mem->content > medianpot->content)
			nbr++;
		if ((nbr == *start->pos->size / 2 && *start->pos->size % 2 == 1)
			|| ((nbr == *start->pos->size / 2 - 1
					|| nbr == *start->pos->size / 2)
				&& *start->pos->size % 2 == 0))
			return (medianpot);
		medianpot = medianpot->next;
	}
	return (0);
}
