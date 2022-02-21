/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:27:36 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 19:21:59 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_freevaria(int i, ...)
{
	va_list	param;
	void	*p;

	va_start(param, i);
	while (i > 0)
	{
		p = va_arg(param, void *);
		free(p);
		i--;
	}
	return (0);
}

t_pos	*ft_setpos(t_pos *pos, int *size)
{
	pos->end = 0;
	pos->size = size;
	pos->start = 0;
	*size = 0;
	return (pos);
}

t_all	*ft_init(t_all *all, char *str)
{
	t_pos	*posa;
	t_pos	*posb;
	int		*sizea;
	int		*sizeb;

	sizea = malloc(sizeof(*sizea));
	if (sizea == 0)
		return (0);
	sizeb = malloc(sizeof(*sizeb));
	if (sizeb == 0)
		return (ft_freevaria(1, sizea));
	all = malloc(sizeof(*all));
	if (all == 0)
		return (ft_freevaria(2, sizea, sizeb));
	posa = malloc(sizeof(*posa));
	if (posa == 0)
		return (ft_freevaria(3, sizea, sizeb, all));
	posb = malloc(sizeof(*posb));
	if (posb == 0)
		return (ft_freevaria(4, sizea, sizeb, all, posa));
	all->a = ft_setpos(posa, sizea);
	all->b = ft_setpos(posb, sizeb);
	all = ft_setlist(str, all);
	return (all);
}

t_list	*ft_lstnew(int content, t_pos *pos)
{
	t_list	*liste;

	liste = malloc(sizeof(*liste));
	if (liste == 0)
		return (0);
	liste->content = content;
	liste->pos = pos;
	*liste->pos->size = *liste->pos->size + 1;
	if (pos->end == 0 || pos->start == 0)
	{
		liste->next = liste;
		liste->back = liste;
		pos->start = liste;
		pos->end = liste;
	}
	else
	{
		liste->next = pos->start;
		liste->back = pos->end;
		pos->start->back = liste;
		pos->end->next = liste;
	}
	return (liste);
}

void	ft_lstprint(t_pos *pos)
{
	t_list	*list;

	if (pos->end != 0 && pos->start != 0)
	{
		list = pos->start;
		while (list != list->pos->end)
		{
			ft_putnbr(list->content);
			write(1, "\n", 1);
			list = list->next;
		}
		ft_putnbr((*list).content);
		write(1, "\n", 1);
	}
}
