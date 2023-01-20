/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:28 by mberri            #+#    #+#             */
/*   Updated: 2023/01/20 14:19:31 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_split_str_size(char **split_str)
{
    int index;

    index = 0;
    while (split_str[index])
        index++;
    return(index);
}

void    ft_free_str(char **str)
{
    int index;

    index = 0;
    while (str[index])
    {
        free(str[index]);
        index++;
    }
    free(str);
}

int ft_atoil(const char *str)
{
	long long	result;
	int			np;
	int			checker;

	result = 0;
	np = 1;
	checker = 0;
	while(ft_isspace(*str))
		str++;
	if (*str == '-')
		np = -1;
	if (*str == '+' || *str == '-')
		str++;
	while(ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		checker++;
	}
	result = result * np;
	if (*str != '\0' || checker > 10
		|| result > 2147483647 || result < -2147483648)
		print_error(1);
	return ((int)result);
}

void    set_str_to_array(int *array, int *arr_index, char **str)
{
	int	tmp_number;
	int	index;

	index = 0;
	while (str[index])
	{
		tmp_number = ft_atoil(str[index]);
		array[*arr_index] = tmp_number;
		(*arr_index)++;
		index++;
	}
}
