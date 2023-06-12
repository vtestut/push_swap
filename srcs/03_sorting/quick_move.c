/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:34:03 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 13:16:37 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rotate(t_val val, t_ptr *a, t_ptr *b)
{
	while (val.rr != 0)
	{
		rotate_r(a, b);
		val.rr--;
	}
	while (val.ra != 0)
	{
		rotate_a(a, 1);
		val.ra--;
	}
	while (val.rb != 0)
	{
		rotate_b(b, 1);
		val.rb--;
	}
}

void	ft_reverse_rotate(t_val val, t_ptr *a, t_ptr *b)
{
	while (val.rrr != 0)
	{
		reverse_rotate_r(a, b);
		val.rrr--;
	}
	while (val.rra != 0)
	{
		reverse_rotate_a(a, 1);
		val.rra--;
	}
	while (val.rrb != 0)
	{
		reverse_rotate_b(b, 1);
		val.rrb--;
	}
}

t_val	ft_getmax_rotation(t_val val)
{
	val.rr = 0;
	if (val.rb > val.ra && val.ra > 0)
	{
		val.rr = val.ra;
		val.ra = 0;
		val.rb = val.rb - val.rr;
	}
	if (val.ra > val.rb && val.rb > 0)
	{
		val.rr = val.rb;
		val.rb = 0;
		val.ra = val.ra - val.rr;
	}
	if (val.ra == val.rb && (val.ra > 0 && val.rb > 0))
	{
		val.rr = val.rb;
		val.rb = 0;
		val.ra = 0;
	}
	return (val);
}

/*	détermine le nombre maximal de reverse_rotate qu'on peut faire
	sur A et B fonction des compteurs rrb et rra.						*/
t_val	ft_getmax_reverse_rotation(t_val val)
{
	val.rrr = 0;
	if (val.rrb > val.rra && val.rra > 0)
	{
		val.rrr = val.rra;
		val.rra = 0;
		val.rrb = val.rrb - val.rrr;
	}
	if (val.rra > val.rrb && val.rrb > 0)
	{
		val.rrr = val.rrb;
		val.rrb = 0;
		val.rra = val.rra - val.rrr;
	}
	if (val.rra == val.rrb && (val.rra > 0 && val.rrb > 0))
	{
		val.rrr = val.rrb;
		val.rrb = 0;
		val.rra = 0;
	}
	return (val);
}

void	ft_quick_move(t_val val, t_ptr *a, t_ptr *b)
{
	val = ft_getmax_rotation(val);
	val = ft_getmax_reverse_rotation(val);
	ft_rotate(val, a, b);
	ft_reverse_rotate(val, a, b);
}
