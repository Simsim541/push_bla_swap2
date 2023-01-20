/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:20:22 by mberri            #+#    #+#             */
/*   Updated: 2023/01/20 14:20:23 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_data *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->top_a->number;
	mid = info->top_a->next->number;
	bot = info->top_a->next->next->number;
	if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else if (mid > top && mid > bot && top > bot)
		rra(info);
}

void	ft_big_sort(t_data *info)
{
	int	a;
	int	b;

	ft_sort_three_division(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
	{
		if (info->top_a->number > info->top_a->next->number)
			sa(info);
	}
	if (info->size_a == 3)
		ft_sort_three(info);
	while (info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(info, &a, &b);
		ft_rotate_same(info, &a, &b);
		ft_rotate_a(info, a);
		ft_rotate_b(info, b);
		pa(info);
	}
	ft_sort_big_last(info);
}

void	ft_sort(t_data *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->number > info->top_a->next->number)
			sa(info);
	}
	else if (info->size_a == 3)
	{
		ft_sort_three(info);
	}
	else
	{
		ft_big_sort(info);
	}
}
