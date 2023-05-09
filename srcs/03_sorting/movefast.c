/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:34:03 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/09 12:34:04 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_algo_values	max_pul_rr(t_algo_values current)
{
	current.rr = 0;
	if (current.rb > current.ra && current.ra > 0)
	{
		current.rr = current.ra;
		current.ra = 0;
		current.rb = current.rb - current.rr;
	}
	if (current.ra > current.rb && current.rb > 0)
	{
		current.rr = current.rb;
		current.rb = 0;
		current.ra = current.ra - current.rr;
	}
	if (current.ra == current.rb && (current.ra > 0 && current.rb > 0))
	{
		current.rr = current.rb;
		current.rb = 0;
		current.ra = 0;
	}
	return (current);
}

t_algo_values	max_pull_rrr(t_algo_values current)
{
	current.rrr = 0;
	if (current.rrb > current.rra && current.rra > 0)
	{
		current.rrr = current.rra;
		current.rra = 0;
		current.rrb = current.rrb - current.rrr;
	}
	if (current.rra > current.rrb && current.rrb > 0)
	{
		current.rrr = current.rrb;
		current.rrb = 0;
		current.rra = current.rra - current.rrr;
	}
	if (current.rra == current.rrb && (current.rra > 0 && current.rrb > 0))
	{
		current.rrr = current.rrb;
		current.rrb = 0;
		current.rra = 0;
	}
	return (current);
}

void	run_rotate(t_algo_values current, t_top *a, t_top *b)
{
	while (current.rr != 0)
	{
		rr(a, b);
		current.rr--;
	}
	while (current.ra != 0)
	{
		rotate_a(a);
		current.ra--;
	}
	while (current.rb != 0)
	{
		rotate_b(b);
		current.rb--;
	}
}

void	run_reverse_rotate(t_algo_values current, t_top *a, t_top *b)
{
	while (current.rrr != 0)
	{
		rrr(a, b);
		current.rrr--;
	}
	while (current.rra != 0)
	{
		reverse_rotate_a(a);
		current.rra--;
	}
	while (current.rrb != 0)
	{
		reverse_rotate_b(b);
		current.rrb--;
	}
}

void	movefastest(t_algo_values current, t_top *a, t_top *b)
{
	current = max_pul_rr(current);
	current = max_pull_rrr(current);
	run_rotate(current, a, b);
	run_reverse_rotate(current, a, b);
}