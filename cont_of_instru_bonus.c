/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont_of_instru_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:26:27 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/18 01:53:28 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack *from, t_stack *to)
{
	int	i;

	i = -1;
	if (from->len != 0)
	{
		to->len++;
		if (to->len >= 2)
		{
			ft_rev_res(to);
		}
		to->stored[0] = from->stored[0];
		ft_rotate(from);
		from->len--;
	}
}

void	ft_rr(t_stack *stored_a, t_stack *stored_b)
{
	ft_rotate(stored_a);
	ft_rotate(stored_b);
}

void	ft_rrr(t_stack *stored_a, t_stack *stored_b)
{
	ft_rev_res(stored_a);
	ft_rev_res(stored_b);
}
