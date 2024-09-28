/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:26:27 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/18 01:45:10 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack *stored)
{
	int	num;

	num = stored->stored[0];
	if (stored->len > 1)
	{
		stored->stored[0] = stored->stored[1];
		stored->stored[1] = num;
	}
}

void	swap_a_b(t_stack *stored_a, t_stack *stored_b)
{
	int	i;

	i = -1;
	ft_swap(stored_a);
	ft_swap(stored_b);
}

void	ft_rotate(t_stack *stored)
{
	int	first;
	int	i;

	i = 0;
	first = stored->stored[0];
	if (stored->len > 1)
	{
		while (i != stored->len)
		{
			stored->stored[i] = stored->stored[i + 1];
			if ((i + 2) == stored->len)
			{
				stored->stored[i + 1] = first;
				break ;
			}
			i++;
		}
	}
}

void	ft_rev_res(t_stack *stored)
{
	int	last;
	int	i;

	i = stored->len - 1;
	last = stored->stored[i];
	if (stored->len > 1)
	{
		while (i != 0)
		{
			stored->stored[i] = stored->stored[i - 1];
			if ((i - 1) == 0)
			{
				stored->stored[i - 1] = last;
				break ;
			}
			i--;
		}
	}
}
