/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:38:12 by audreyer          #+#    #+#             */
/*   Updated: 2022/01/20 18:33:24 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_pos *pos)
{
	int	mem;

	mem = pos->start->content;
	pos->start->content = pos->start->next->content;
	pos->start->next->content = mem;
}

void	ft_sa(t_all *all)
{
	ft_swap(all->a);
	write(1, "sa\n", 3);
}

void	ft_ss(t_all *all)
{
	ft_swap(all->a);
	ft_swap(all->b);
	write(1, "ss\n", 3);
}

void	ft_sb(t_all *all)
{
	ft_swap(all->b);
	write(1, "sb\n", 3);
}
