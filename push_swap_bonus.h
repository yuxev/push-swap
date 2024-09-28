/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:11:53 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/27 18:46:17 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<limits.h>
# include	"./get_next_line/get_next_line.h"

typedef struct stack
{
	int	len;
	int	*stored;
}	t_stack;

void	ft_swap(t_stack *stored);
void	swap_a_b(t_stack *stored_a, t_stack *stored_b);
void	ft_rotate(t_stack *stored);
void	ft_rev_res(t_stack *stored);
void	ft_push(t_stack *or_stored, t_stack *cp_stored);
void	ft_rr(t_stack *stored_a, t_stack *stored_b);
void	ft_rrr(t_stack *stored_a, t_stack *stored_b);
void	ft_check_str(char *str, t_stack *stored_a);
void	check_if_double(t_stack *stored_a);
void	ft_exit(t_stack *stored_a, int v);
void	ft_cal_str(char	*str, t_stack *stored_a);
void	sort_arr(int *stored, int len);
void	ckeck_if_valid(long long num);
void	sort_stack(t_stack *stored_a, t_stack *stored_b);
long	ft_atoi(char *s);
int		ft_cal_len(char	*str);
int		ft_strcmp(const char *s1, const char *s2);

#endif