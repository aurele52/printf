/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:44:34 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/09 18:34:33 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_pos *pos)
{
	pos->end = pos->end->next;
	pos->start = pos->start->next;
}

void	ft_rotate_reverse(t_pos *pos)
{
	pos->end = pos->end->back;
	pos->start = pos->start->back;
}

void	ft_ra(t_all *all)
{
	ft_rotate(all->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_all *all)
{
	ft_rotate(all->b);
	write(1, "rb\n", 3);
}

void	ft_rs(t_all *all)
{
	ft_rotate(all->a);
	ft_rotate(all->b);
	write(1, "rr\n", 3);
}
