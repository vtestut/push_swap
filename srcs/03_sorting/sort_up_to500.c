/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:33:38 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/09 12:33:39 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	test_instr(t_top *a, t_top *b)
{
	t_list          *start_b;
	t_algo_values	current;
	t_algo_values	next_node;

	current.node = b->top;
	start_b = b->top;
	while (start_b)
	{
		current = number_moves(a, start_b, b, current);
		while (start_b != NULL)
		{
			next_node = number_moves(a, start_b, b, next_node);
			if (calc_instructions(current, next_node) == 1)
				current = next_node;
			start_b = start_b->next;
		}
		movefastest(current, a, b);
		push_a(a, b);
		start_b = b->top;
	}
}

void	zero_zero(t_algo_values go_zero, t_top *a)
{
	while (go_zero.rra != 0)
	{
		reverse_rotate_a(a);
		go_zero.rra--;
	}
	while (go_zero.ra != 0)
	{
		rotate_a(a);
		go_zero.ra--;
	}
}

void	push_zero(t_top *a, t_list *zero)
{
	int				size;
	int				count;
	t_algo_values	go_zero;
	t_list		    *starta;

	starta = a->top;
	size = ft_lstsize(starta);
	count = 0;
	go_zero.ra = 0;
	go_zero.rra = 0;
	while (starta != zero)
	{
		count++;
		starta = starta->next;
	}
	if (count <= size / 2)
		go_zero.ra = count;
	else if (count > size / 2)
		go_zero.rra = size - count;
	zero_zero(go_zero, a);
}

void	ft_big_sort(t_top *a, t_top *b)
{
	int		median;
	t_list	*zero;
	t_list	*start;

	start = a->top;
	zero = find_smallest(start);
	median = ft_lstsize(start) / 2;
	presort(median, b, a);
	test_instr(a, b);
	push_zero(a, zero);
}