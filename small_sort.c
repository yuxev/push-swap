/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:08:52 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/18 01:34:40 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_range(int top, int *std, int s, int len)
{
	int	i;

	i = s;
	while (i <= len)
	{
		if (std[i] == top)
			return (1);
		i++;
	}
	return (0);
}

int	get_min_num(int *stored, int len)
{
	int	j;
	int	max;
	int	index;

	index = 0;
	j = 0;
	max = stored[0];
	while (j != len)
	{
		if (max > stored[j])
		{
			max = stored[j];
			index = j;
		}
		j++;
	}
	return (index);
}

void	cont_of_func(t_stack *stored_a)
{
	int	min;

	min = get_min_num(stored_a->stored, stored_a->len);
	if (stored_a->len == 3)
	{
		if (min == 2)
		{
			if (stored_a->stored[1] < stored_a->stored[0])
			{
				ft_swap(stored_a, "sa");
				ft_rev_res(stored_a, "rra");
			}
			else
				ft_rev_res(stored_a, "rra");
			if (stored_a->stored[1] > stored_a->stored[2])
			{
				ft_rev_res(stored_a, "rra");
				ft_swap(stored_a, "sa");
			}
		}
	}
	if (stored_a->len == 2)
		ft_swap(stored_a, "sa");
}

void	sort_three(t_stack *stored_a, int *stored)
{
	if (stored_a->len == 3)
	{
		if (stored[1] < stored[0] && stored[1] < stored[2])
		{
			if (stored[0] < stored[2])
				ft_swap(stored_a, "sa");
			else
				ft_rotate(stored_a, "ra");
			if (stored[1] > stored[2])
			{
				ft_rev_res(stored_a, "rra");
				ft_swap(stored_a, "sa");
			}
		}
		else if (stored[0] < stored[1] && stored[0] < stored[2])
		{
			if (stored[1] > stored[2])
			{
				ft_rev_res(stored_a, "rra");
				ft_swap(stored_a, "sa");
			}
		}
	}
	cont_of_func(stored_a);
}

void	sort_five(t_stack *stored_a, t_stack *stored_b)
{
	int	min;

	while (stored_a->len != 3)
	{
		min = get_min_num(stored_a->stored, stored_a->len);
		if (min == 0)
			ft_push(stored_a, stored_b, "pb");
		else if (min <= 3)
			ft_rotate(stored_a, "ra");
		else
			ft_rev_res(stored_a, "rra");
	}
	if (check_if_sorted(stored_a) == 1)
		sort_three(stored_a, stored_a->stored);
	while (stored_b->len != 0)
		ft_push(stored_b, stored_a, "pa");
}
