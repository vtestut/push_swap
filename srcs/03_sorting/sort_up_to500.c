/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:33:38 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 17:17:47 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_last_move(t_val smallest, t_ptr *a)
{
	while (smallest.rra != 0)
	{
		reverse_rotate_a(a, 1);
		smallest.rra--;
	}
	while (smallest.ra != 0)
	{
		rotate_a(a, 1);
		smallest.ra--;
	}
}

void	ft_push_smallest(t_ptr *a, t_lst *first)
{
	int		len;
	int		n;
	t_val	smallest;
	t_lst	*start_a;

	start_a = a->top;
	len = ft_lstsize(start_a);
	n = 0;
	smallest.ra = 0;
	smallest.rra = 0;
	while (start_a != first)
	{
		n++;
		start_a = start_a->next;
	}
	if (n <= len / 2)
		smallest.ra = n;
	else if (n > len / 2)
		smallest.rra = len - n;
	ft_last_move(smallest, a);
}

void	ft_insertion_sort(t_ptr *a, t_ptr *b)
{
	t_lst	*start_b;
	t_val	current;
	t_val	next_node;

	current.node = b->top;
	start_b = b->top;
	while (start_b)
	{
		current = ft_move_count_b(a, start_b, b, current);
		while (start_b != NULL)
		{
			next_node = ft_move_count_b(a, start_b, b, next_node);
			if (ft_compare_moves(current, next_node) == 1)
				current = next_node;
			start_b = start_b->next;
		}
		ft_quick_move(current, a, b);
		push_a(a, b);
		start_b = b->top;
	}
}

void	ft_big_sort(t_ptr *a, t_ptr *b)
{
	int		median;
	t_lst	*smallest;
	t_lst	*start;

	start = a->top;
	smallest = ft_find_smallest(start);
	median = ft_lstsize(start) / 2;
	ft_median_sort(median, b, a);
	ft_insertion_sort(a, b);
	ft_push_smallest(a, smallest);
}
