/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:20:35 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/17 20:03:25 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *stored, int len)
{
	int	i;
	int	j;
	int	res;
	int	tmp;

	j = 0;
	i = 0;
	while (i != len)
	{
		res = stored[i];
		while (j != len)
		{
			if (res < stored[j] && i != j)
			{
				res = stored[j];
				tmp = stored[i];
				stored[i] = res;
				stored[j] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	cont_of_push(t_stack *stack_a, t_stack *stack_b, int *std_cpy, int max)
{
	int	b;
	int	len;

	b = (stack_b->len - 1) / 2;
	len = (stack_b->len - 1);
	if (stack_b->stored[len - 1] == std_cpy[len])
	{
		ft_rev_res(stack_b, "rrb");
		ft_rev_res(stack_b, "rrb");
		ft_push(stack_b, stack_a, "pa");
	}
	else if (max <= b)
		ft_rotate(stack_b, "rb");
	else
		ft_rev_res(stack_b, "rrb");
}

void	from_b_to_a(t_stack *stored_a, t_stack *stored_b, int *std_cpy)
{
	int	b;
	int	max;
	int	len;

	while (stored_b->len != 0)
	{
		b = (stored_b->len - 1) / 2;
		max = get_max_num(stored_b->stored, stored_b->len);
		len = (stored_b->len - 1);
		if (stored_b->stored[0] == std_cpy[(stored_b->len - 1)])
			ft_push(stored_b, stored_a, "pa");
		else if (stored_b->stored[1] == std_cpy[(stored_b->len - 1)])
		{
			ft_swap(stored_b, "sb");
			ft_push(stored_b, stored_a, "pa");
		}
		else if (stored_b->stored[len] == std_cpy[len])
		{
			ft_rev_res(stored_b, "rrb");
			ft_push(stored_b, stored_a, "pa");
		}
		else
			cont_of_push(stored_a, stored_b, std_cpy, max);
	}
}

void	from_a_to_b(t_stack *stored_a, t_stack *stored_b, int *std_cpy, int len)
{
	int	s;

	s = 0;
	while (stored_a->len != 0)
	{
		if (stored_a->stored[0] < std_cpy[s])
		{
			ft_push(stored_a, stored_b, "pb");
			ft_rotate(stored_b, "rb");
			if (len != (stored_a->len - 1))
				len++;
			if (s != (stored_a->len - 1))
				s++;
		}
		else if (in_range(stored_a->stored[0], std_cpy, s, len))
		{
			ft_push(stored_a, stored_b, "pb");
			if (len != (stored_a->len - 1))
				len++;
			if (s != (stored_a->len - 1))
				s++;
		}
		else
			ft_rotate(stored_a, "ra");
	}
}

void	sort_stack(t_stack *stored_a, t_stack *stored_b)
{
	int	*std_cpy;
	int	len;
	int	s;

	s = 0;
	len = 0;
	if (stored_a->len >= 21 && stored_a->len <= 199)
		len = 10;
	else if (stored_a->len >= 500 || stored_a->len >= 200)
		len = 33;
	std_cpy = malloc((stored_a->len + 1) * sizeof(int));
	std_cpy = ft_memcpy(std_cpy, stored_a->stored, stored_a->len, -1);
	sort_arr(std_cpy, stored_a->len);
	from_a_to_b(stored_a, stored_b, std_cpy, len);
	from_b_to_a(stored_a, stored_b, std_cpy);
	free(std_cpy);
}
