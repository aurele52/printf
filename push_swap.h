/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:52:31 by audreyer          #+#    #+#             */
/*   Updated: 2022/02/12 17:10:46 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>

typedef struct s_move
{
	struct	s_list	*p;
	int	movenbr;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rrs;
	int	rs;
	int	upup;
	int	downdown;
	int	updown;
	int	downup;
}	t_move;

typedef struct s_all
{
	struct s_pos	*a;
	struct s_pos	*b;
}	t_all;

typedef struct s_pos
{
	struct s_list	*start;
	struct s_list	*end;
	int	*size;
}	t_pos;

typedef void	(*t_tab)(t_all *all);

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*back;
	int	content;
	struct s_pos	*pos;
}	t_list;

int	ft_strlen(char	*str);
void	*ft_freevaria(int i, ...);
int	push_swap(char *str);
t_all	*ft_init(t_all *all, char *str);
t_list	*ft_lstnew(int content, t_pos *pos);
void	ft_lstprint(t_pos *pos);
void    ft_delone(t_list *list);
t_list  *ft_min(t_pos   *pos);
int     ft_range(t_list *list);
t_list  *ft_max(t_pos   *pos);
t_list  *ft_median(t_list *start, t_list *end);
void    ft_push(t_pos *from, t_pos *to);
void    ft_pb(t_all *all);
void    ft_pa(t_all *all);
void    ft_ps(t_all *all);
void	ft_putnbr(int nbr);
int	ft_atoi(const char *str);
t_all	*ft_setlist(char *str, t_all *all);
void	*ft_free(t_all *all);
int	ft_correct(t_all *all);
void	ft_triathree(t_all *all);
void	ft_transfer(t_all *all);
int	ft_moverra(t_all *all, t_list *list);
int	ft_movera(t_all *all, t_list *list);
t_move	*ft_moveclean(t_move *move);
t_move	*ft_bestmove(t_all *all, t_list *list);
t_move	*ft_best(t_all *all);
int	ft_movebest(t_all *all, t_move *move);
void	ft_aurelesort(t_all *all);
void    ft_rra(t_all *all);
void    ft_rrb(t_all *all);
void    ft_rrs(t_all *all);
void	ft_rotate(t_pos *pos);
void	ft_rotate_reverse(t_pos *pos);
void	ft_ra(t_all *all);
void	ft_rb(t_all *all);
void	ft_rs(t_all *all);
void	ft_swap(t_pos *pos);
void	ft_sa(t_all *all);
void	ft_ss(t_all *all);
void	ft_sb(t_all *all);
void	ft_setintzerovaria(int i, ...);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int	ft_checkall(t_all *all);
int	ft_test(char *str);
char	*ft_join(int argc, char **argv);

#endif
