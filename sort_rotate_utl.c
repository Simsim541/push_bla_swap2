/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_utl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:20:41 by mberri            #+#    #+#             */
/*   Updated: 2023/01/20 14:20:42 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_min(t_numbers *stack)
{
	int	ret;

	ret = stack->number;
	while (stack)
	{
		if (ret > stack->number)
		{
			ret = stack->number;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_min(t_data *info)
{
	int			ret;
	int			index;
	int			tmp;
	t_numbers     *stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->number;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	get_stack_max(t_numbers *stack)
{
	int	ret;

	ret = stack->number;
	while (stack)
	{
		if (ret < stack->number)
		{
			ret = stack->number;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_max(t_data *info)
{
	int			ret;
	int			index;
	int			tmp;
	t_numbers     *stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->number;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_data *info)
{
	t_numbers     *stack_a;
	int			ret;

	stack_a = info->top_a;
	ret = 1;
	while (stack_a->next)
	{
		if (num > stack_a->number && num < stack_a->next->number)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}
