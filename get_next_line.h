/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 09:57:25 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/12 16:59:38 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 2000
# include <unistd.h>
# include <stdlib.h>

int		ft_atoignl(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoingnl(char *s1, char *s2);
char	*get_next_line(int fd);
#endif
