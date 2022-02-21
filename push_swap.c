/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:41:00 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 19:22:19 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_aurelesort(t_all *all)
{
	t_list	*min;

	ft_transfer(all);
	ft_triathree(all);
	while (*all->b->size != 0)
	{
		if (ft_movebest(all, ft_best(all)) == 0)
			return ;
	}
	min = ft_min(all->a);
	if (ft_range(min) < *min->pos->size / 2)
		while (all->a->start != min)
			ft_rra(all);
	else
		while (all->a->start != min)
			ft_ra(all);
}

int	ft_test(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == ' ')
			return (1);
		if ((str[i] == ' ' && (str[i + 1] == 0 || str[i + 1] == ' '))
			|| (str[i] == '-' && (str[i + 1] == 0 || str[i + 1] == '-')))
			return (1);
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == ' ' || str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!(str))
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!(str))
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	if (s1[0] != 0)
		str[i++] = ' ';
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}
