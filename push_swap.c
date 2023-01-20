/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:05:26 by mberri            #+#    #+#             */
/*   Updated: 2023/01/20 14:13:33 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int print_error(int x)
{
    if(x >= 1)
        write(1, "Error\n", 6);
    exit(1);
    return(-1);
}

t_numbers *ft_stack_new(void)
{
    t_numbers *new_alloc;
    
    new_alloc = NULL;
    new_alloc = (t_numbers *)malloc(sizeof(t_numbers));
    new_alloc->prev = NULL;
    new_alloc->number = 0;
    new_alloc->next = NULL;
    return(new_alloc);
}

t_data *ft_data_new(void)
{
    t_numbers *stack_a;
    t_data    *new_data;
    
    new_data = NULL;
    new_data = (t_data *)malloc(sizeof(t_data));
    stack_a = ft_stack_new();
    new_data->array = NULL;
    new_data->size_a = 0;
    new_data->top_a = stack_a;
    new_data->bottom_a = stack_a;
    new_data->size_b = 0;
    return(new_data);
}

void ft_check(int *array, int size)
{
    int i;
    int j;
    
    i = 0;
    while(i < size - 1)
    {
        j = i + 1;
        while (array[j])
        {
            if (array[i] == array[j])
                print_error(1);
            j++;
        }
        i++;
    }
}

int main(int ac, char *av[])
{
    int array_size;
    int *array_nbr;
    t_data    *data;
    
    if(ac < 2)
    {
        print_error(-1);
    }
    array_size = 0;
    data = ft_data_new();
    array_size = get_str_size(ac, av);
    array_nbr = ft_av_to_array(ac, av, array_size);
    ft_check (array_nbr, array_size);
    ft_arr_to_stack (data, array_nbr, array_size);
    ft_check_array_sort (array_nbr, array_size, 0);
    data->array = (int *)array_nbr;
    ft_sort (data);
    return (0);
}
