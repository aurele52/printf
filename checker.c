/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:22:03 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/12 19:59:26 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strstr(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little == 0 || !(*little) || big == 0)
		return (-1);
	while (big[i])
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			if (little[j + 1] == 0)
			{
				free(little);
				return (i);
			}
			j++;
		}
		i++;
	}
	free(little);
	return (-1);
}

void	echec(t_all *all)
{
	(void)all;
	return ;
}

void	(*ft_fonction_tab(int mem))(t_all*)
{
	t_tab	tab[35];
	int	i;

	i = 0;
	if (mem == -1)
		return (0);
	while (i < 35)
		tab[i++] = &(echec);
	tab[0] = &(ft_ra);
	tab[3] = &(ft_rb);
	tab[6] = &(ft_rs);
	tab[9] = &(ft_rra);
	tab[13] = &(ft_rrb);
	tab[17] = &(ft_rrs);
	tab[21] = &(ft_pa);
	tab[24] = &(ft_pb);
	tab[27] = &(ft_sa);
	tab[30] = &(ft_sb);
	tab[33] = &(ft_ss);
	return (tab[mem]);
}

char	*ft_space(char *str)
{
	char	*ret;
	int	i;

	i = 0;
	if (ft_strlen(str) > 4)
		return(0);
	ret = malloc(sizeof(*ret) * (ft_strlen(str) + 3));
	ret[i++] = ' ';
	ret[i++] = str[0];
	ret[i++] = str[1];
	if (ft_strlen(str) == 4)
		ret[i++] = str[2];
	ret[i++] = ' ';
	ret[i++] = 0;
	free(str);
	return (ret);
}

int	ft_checker(char *liste, int fd)
{
	void	(*fonction)(t_all *);
	char	*str;
	t_all	*all;
	char	*allinstruction = " ra rb rr rra rrb rrr pa pb sa sb ss ";

	fonction = 0;
	all = 0;
	all = ft_init(all, liste);
	if (all == 0)
		return (0);
	if (ft_checkall(all) == 1)
	{
		ft_free(all);
		return (1);
	}
	str = get_next_line(fd);
	while ((str != 0 && all) && fonction == 0)
	{
		fonction = ft_fonction_tab(ft_strstr(allinstruction, ft_space(str)));
		if (fonction == 0)
		{
			free(str);
			ft_free(all);
			return (0);
		}
		(*fonction)(all);
		str = 0;
	}
	ft_lstprint(all->a);
	ft_free(all);
	free(str);
	if (ft_correct(all) == 1)
		return (1);
	return (0);
}


int	main(int argc, char **argv)
{
	int	fd;

	fd = open("a.txt", O_RDONLY);
	if (argc != 2)
		return (0);
	if (ft_test(argv[1]) == 1)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	if (ft_checker(argv[1], fd) == 1)
		write(1, "OK\n", 3);
	else	
		write(1, "KO\n", 3);
}
