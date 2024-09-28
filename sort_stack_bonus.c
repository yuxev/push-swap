/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:20:35 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/26 21:21:19 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	others_cond(t_stack *stored_a, t_stack *stored_b, char *str)
{
	if (ft_strcmp(str, "pb\n"))
		ft_push(stored_a, stored_b);
	else if (ft_strcmp(str, "sb\n"))
		ft_swap(stored_b);
	else if (ft_strcmp(str, "rb\n"))
		ft_rotate(stored_b);
	else if (ft_strcmp(str, "rrb\n"))
		ft_rev_res(stored_b);
	else if (ft_strcmp(str, "ss\n"))
		swap_a_b(stored_a, stored_b);
	else if (ft_strcmp(str, "rr\n"))
		ft_rr(stored_a, stored_b);
	else if (ft_strcmp(str, "rrr\n"))
		ft_rrr(stored_a, stored_b);
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	check_if_sorted(t_stack *stored_a)
{
	int	i;
	int	k;
	int	c;

	c = 0;
	i = 0;
	k = 0;
	while (i != stored_a->len)
	{
		k = i;
		while (k != stored_a->len)
		{
			if (stored_a->stored[i] > stored_a->stored[k])
				c++;
			k++;
		}
		k = 0;
		i++;
	}
	if (c == 0)
		ft_exit(stored_a, 1);
	else
		ft_exit(stored_a, 0);
}

void	sort_stack(t_stack *stored_a, t_stack *stored_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (ft_strcmp(str, "sa\n"))
			ft_swap(stored_a);
		else if (ft_strcmp(str, "ra\n"))
			ft_rotate(stored_a);
		else if (ft_strcmp(str, "rra\n"))
			ft_rev_res(stored_a);
		else if (ft_strcmp(str, "pa\n"))
			ft_push(stored_b, stored_a);
		else
			others_cond(stored_a, stored_b, str);
		free(str);
	}
	if (stored_b->len != 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	check_if_sorted(stored_a);
}
