/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont_of_instru.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:26:27 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/17 21:46:42 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(int *dst, int *src, int n, int i)
{
	if (!src)
		return (0);
	if (i == 1)
	{
		while (i != n)
		{
			dst[i - 1] = src[i];
			i++;
		}
	}
	else if (i == 2)
	{
		i = 0;
		while (i != n)
		{
			dst[i + 1] = src[i];
			i++;
		}
	}
	else
	{
		while (i++ != n)
			dst[i] = src[i];
	}
	return (dst);
}

void	ft_push(t_stack *from, t_stack *to, char *str)
{
	int	i;

	i = -1;
	if (from->len != 0)
	{
		to->len++;
		if (to->len >= 2)
		{
			ft_rev_res(to, NULL);
		}
		to->stored[0] = from->stored[0];
		ft_rotate(from, NULL);
		from->len--;
	}
	while (i++ != ft_strlen(str) - 1)
		write(1, &str[i], 1);
	write(1, "\n", 1);
}
