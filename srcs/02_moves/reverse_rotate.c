/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:53:08 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 12:48:57 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate_a(t_ptr *a, int flag)
{
	t_lst	*start_a;
	t_lst	*last;
	t_lst	*tmp;

	start_a = a->top;
	if (ft_lstsize(start_a) > 1)
	{
		tmp = ft_second_last_node(start_a);
		last = ft_lstlast(start_a);
		a->top = last;
		tmp->next = NULL;
		last->next = start_a;
		if (flag != 0)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_ptr *b, int flag)
{
	t_lst	*start_b;
	t_lst	*last;
	t_lst	*tmp;

	start_b = b->top;
	if (ft_lstsize(start_b) > 1)
	{
		tmp = ft_second_last_node(start_b);
		last = ft_lstlast(start_b);
		b->top = last;
		tmp->next = NULL;
		last->next = start_b;
		if (flag != 0)
			write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_r(t_ptr *a, t_ptr *b)
{
	if (ft_lstsize(a->top) > 1 && ft_lstsize(b->top) > 1)
	{
		reverse_rotate_a(a, 0);
		reverse_rotate_b(b, 0);
		write(1, "rrr\n", 4);
	}
}
