/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:16:09 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 12:46:59 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_find_biggest(t_lst *start)
{
	t_lst	*big;

	big = start;
	while (start != NULL)
	{
		if (start->content > big->content)
			big = start;
		start = start->next;
	}
	return (big->content);
}

int	ft_next_smallest(t_lst *start, int min)
{
	int	next_min;

	next_min = ft_find_biggest(start);
	while (start != NULL)
	{
		if ((start->content < next_min) && (start->content > min))
			next_min = start->content;
		start = start->next;
	}
	return (next_min);
}

t_lst	*ft_find_smallest(t_lst *start)
{
	t_lst	*smallest;

	smallest = start;
	while (start != NULL)
	{
		if (start->content < smallest->content)
			smallest = start;
		start = start->next;
	}
	return (smallest);
}

void	ft_index_list(t_ptr *a)
{
	int		size;
	int		i;
	int		min;
	t_lst	*smallest;
	t_lst	*start;

	start = a->top;
	size = ft_lstsize(start);
	smallest = ft_find_smallest(start);
	min = smallest->content;
	i = 0;
	while (i < size)
	{
		while (start != NULL)
		{
			if (start->content >= min)
				start->index = i;
			start = start->next;
		}
		start = a->top;
		min = ft_next_smallest(start, min);
		i++;
	}
}
