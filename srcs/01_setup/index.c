/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:16:09 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/09 12:34:58 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_max(t_list *start)
{
	t_list	*max;
	
	max = start;
	while (start != NULL)
	{
		if (start->content > max->content)
			max = start;
		start = start->next;
	}
	return (max->content);
}

int	find_next_smallest(t_list *start, int min)
{
	int	next_min;

	next_min = find_max(start);
	while (start != NULL)
	{
		if ((start->content < next_min) && (start->content > min))
			next_min = start->content;
		start = start->next;
	}
	return (next_min);
}

t_list	*find_smallest(t_list *start)
{
	t_list	*smallest;
	
	smallest = start;
	while (start != NULL)
	{
		if (start->content < smallest->content)
			smallest = start;
		start = start->next;
	}
	return (smallest);
}

void index_list(t_top *a)
{
	int		size;
	int		i;
	int		min;
	t_list	*smallest;
	t_list	*start;

	start = a->top;
	size = ft_lstsize(start);
	smallest = find_smallest(start);
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
		min = find_next_smallest(start, min);
		i++;
	}
}