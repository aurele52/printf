/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:33:46 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 17:55:11 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_all *all)
{
	ft_rotate_reverse(all->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_all *all)
{
	ft_rotate_reverse(all->b);
	write(1, "rrb\n", 4);
}

void	ft_rrs(t_all *all)
{
	ft_rotate_reverse(all->a);
	ft_rotate_reverse(all->b);
	write(1, "rrr\n", 4);
}
