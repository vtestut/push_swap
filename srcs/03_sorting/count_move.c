/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:33:53 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 17:17:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_val	ft_move_count_a(t_lst *node_a, t_ptr *a, t_val current)
{
	int			n;
	int			size;
	t_lst		*start_a;

	current.ra = 0;
	current.rra = 0;
	start_a = a->top;
	size = ft_lstsize(start_a);
	n = 0;
	while (node_a != start_a)
	{
		n++;
		start_a = start_a->next;
	}
	if (n <= size / 2)
		current.ra = n;
	else if (n > size / 2)
		current.rra = size - n;
	return (current);
}

t_lst	*ft_find_a_max(t_lst *node_b, t_ptr *a)
{
	t_lst	*start_a;
	t_lst	*max;

	start_a = a->top;
	max = ft_max_a(start_a);
	while (start_a != NULL)
	{
		if ((start_a->index > node_b->index)
			&& (start_a->index < max->index))
			max = start_a;
		start_a = start_a->next;
	}
	return (max);
}

t_val	ft_move_count_b(t_ptr *a, t_lst *node_b, t_ptr *b, t_val cur)
{
	int		n;
	int		size;
	t_lst	*node;
	t_lst	*node_a;

	cur.rb = 0;
	cur.rrb = 0;
	node = b->top;
	size = ft_lstsize(node);
	n = 0;
	while (node_b != node)
	{
		n++;
		node = node->next;
	}
	if (n <= size / 2)
		cur.rb = n;
	else if (n > size / 2)
		cur.rrb = size - n;
	node_a = ft_find_a_max(node_b, a);
	cur = ft_move_count_a(node_a, a, cur);
	return (cur);
}

int	ft_compare_moves(t_val current, t_val next_node)
{
	int	total;
	int	total_next;

	total = current.rra + current.rrb + current.rb + current.ra;
	total_next = next_node.rra + next_node.rrb + next_node.rb + next_node.ra;
	if (total_next < total)
		return (1);
	else
		return (0);
}
