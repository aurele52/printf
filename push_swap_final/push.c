/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:30:35 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 18:12:16 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_pos *from, t_pos *to)
{
	to->start = ft_lstnew(from->start->content, to);
	ft_delone(from->start);
}

void	ft_pb(t_all *all)
{
	ft_push(all->a, all->b);
	write(1, "pb\n", 3);
}

void	ft_pa(t_all *all)
{
	ft_push(all->b, all->a);
	write(1, "pa\n", 3);
}

void	ft_ps(t_all *all)
{
	ft_push(all->b, all->a);
	ft_push(all->a, all->b);
	write(1, "ps\n", 3);
}
