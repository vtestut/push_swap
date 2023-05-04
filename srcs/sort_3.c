/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:48 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/04 17:47:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_3(t_top *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->content;
	second = a->top->next->content;
	third = a->top->next->next->content;
	if ((first > second) && (first < third) && (second < third))
		swap_a(a);
	else if ((first > second) && (second > third) && (first > third))
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
}
