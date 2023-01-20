/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:48 by mberri            #+#    #+#             */
/*   Updated: 2023/01/20 14:19:52 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct numbers
{
	struct numbers	*prev;
	int					number;
	struct numbers	*next;
}t_numbers;

typedef struct s_data
{
	int		*array;
	int		size_a;
	t_numbers	*top_a;
	t_numbers	*bottom_a;
	int		size_b;
	t_numbers	*top_b;
	t_numbers	*bottom_b;
}t_data;

size_t		ft_strlen(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(char c);
char		**ft_split(char const *s, char c);
void		ft_check(int *array, int size);
void		ft_free_str(char **str);
int			print_error(int x);
t_data		*ft_data_new(void);
t_numbers	*ft_stack_new(void);
int			ft_atoil(const char *str);
void		set_str_to_array(int *array, int *arr_index, char **str);
int			get_str_size(int ac, char *av[]);
int			get_split_str_size(char **split_str);
int			*ft_av_to_array(int ac, char *av[], int size);
void		ft_arr_to_stack(t_data *info, int *array, int size);
void		ft_check_array_sort(int *array, int size, int index);
void		ra(t_data *info);
void		rb(t_data *info);
void		rr(t_data *info);
void		rra(t_data *info);
void		rrb(t_data *info);
void		rrr(t_data *info);
void		sa(t_data *info);
void		sb(t_data *info);
void		ss(t_data *info);
void		pa(t_data *info);
void		pb(t_data *info);
void		ft_sort(t_data *info);
void		ft_sort_three(t_data *info);
void		ft_big_sort(t_data *info);
int			set_a_location(int num, t_data *info);
void		get_min_rotate(t_data *info, int *a, int *b);
void		ft_sort_big_last(t_data *info);
void		ft_sort_3div_insruct(t_data *info, int pivot1, int pivot2);
void		ft_sort_three_division(t_data *info);
int			ft_get_bigger(int a, int b, int a_loc, int b_loc);
void		ft_rotate_same(t_data *info, int *a, int *b);
void		ft_rotate_a(t_data *info, int a);
void		ft_rotate_b(t_data *info, int b);
int			get_stack_min(t_numbers *stack);
int			set_a_location_min(t_data *info);
int			get_stack_max(t_numbers	*stack);
int			set_a_location_max(t_data *info);
int			set_a_location_mid(int num, t_data *info);
#endif
