/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:11:53 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/27 17:39:43 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<limits.h>
# include	<unistd.h>

typedef struct stack
{
	int	len;
	int	*stored;
}	t_stack;

int		check_if_sorted(t_stack *stored_a);
void	ft_swap(t_stack *stored, char *str);
void	swap_a_b(t_stack *stored_a, t_stack *stored_b, char *str);
void	ft_rotate(t_stack *stored, char *str);
void	ft_rev_res(t_stack *stored, char *str);
void	ft_push(t_stack *or_stored, t_stack *cp_stored, char *str);
void	ft_check_str(char *str, t_stack *stored_a);
void	check_if_double(t_stack *stored_a);
void	check_if_tidy(t_stack *stored_a);
void	ft_cal_str(char	*str, t_stack *stored_a);
int		get_max_num(int *stored, int len);
int		in_range(int top, int *std, int s, int len);
void	sort_arr(int *stored, int len);
void	ckeck_if_valid(long long num);
void	sort_stack(t_stack *stored_a, t_stack *stored_b);
long	ft_atoi(char *s);
int		ft_strlen(const char *s);
int		ft_cal_len(char	*str);
void	*ft_memcpy(int *dst, int *src, int n, int i);
void	sort_three(t_stack *stored_a, int *stored);
void	sort_five(t_stack *stored_a, t_stack *stored_b);
void	ft_exit(void);

#endif