/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:20:30 by mberri            #+#    #+#             */
/*   Updated: 2023/01/20 14:20:32 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_a_location(int num, t_data *info)
{
	int	ret;

	if (num < get_stack_min(info->top_a))
		ret = set_a_location_min(info);
	else if (num > get_stack_max(info->top_a))
		ret = set_a_location_max(info);
	else
		ret = set_a_location_mid(num, info);
	return (ret);
}

void	ft_rotate_same(t_data *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	ft_rotate_a(t_data *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info);
			a--;
		}
		else
		{
			rra(info);
			a++;
		}
	}
}

void	ft_rotate_b(t_data *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info);
			b--;
		}
		else
		{
			rrb(info);
			b++;
		}
	}
}
