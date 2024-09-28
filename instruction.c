/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:26:27 by aasselma          #+#    #+#             */
/*   Updated: 2023/04/17 21:46:01 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stored, char *str)
{
	int	num;
	int	i;

	i = -1;
	num = stored->stored[0];
	stored->stored[0] = stored->stored[1];
	stored->stored[1] = num;
	if (str != NULL)
	{
		while (i++ != ft_strlen(str) - 1)
			write(1, &str[i], 1);
		write(1, "\n", 1);
	}
}

void	swap_a_b(t_stack *stored_a, t_stack *stored_b, char *str)
{
	int	i;

	i = -1;
	ft_swap(stored_a, NULL);
	ft_swap(stored_b, NULL);
	if (str != NULL)
	{
		while (i++ != ft_strlen(str) - 1)
			write(1, &str[i], 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate(t_stack *stored, char *str)
{
	int	first;
	int	i;

	i = 0;
	first = stored->stored[0];
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
	i = -1;
	if (str != NULL)
	{
		while (i++ != ft_strlen(str) - 1)
			write(1, &str[i], 1);
		write(1, "\n", 1);
	}
}

void	ft_rev_res(t_stack *stored, char *str)
{
	int	last;
	int	i;

	i = stored->len - 1;
	last = stored->stored[i];
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
	i = -1;
	if (str != NULL)
	{
		while (i++ != ft_strlen(str) - 1)
			write(1, &str[i], 1);
		write(1, "\n", 1);
	}
}
