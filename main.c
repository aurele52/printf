/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:20:32 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/11 23:41:38 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char *str)
{
	t_all	*all;

	all = 0;
	all = ft_init(all, str);
	if (all == 0)
		return (1);
	if (ft_checkall(all) == 1)
	{
		ft_free(all);
		return (1);
	}
	ft_aurelesort(all);
	ft_free(all);
	return (0);
}

/*int	main(int argc, char **argv)
{
	char	*str;

	if (argc == 1)
		return (0);
	if (argc == 2)
		str = ft_strdup(argv[1]);
	if (argc > 2)
		str = ft_join(argc, argv);
	if (str == 0)
		return (0);
	if (ft_test(str) == 1)
	{
		free(str);
		return (0);
	}
	push_swap(str);
	free(str);
}*/
