#include "../include/push_swap.h"

void	pushto_median(t_list *start, t_top *b, t_top *a, int median)
{
	if (start->index <= median)
	{
		push_b(a, b);
		rotate_b(b);
	}
	else
		push_b(a, b);
}

void	presort(int median, t_top *b, t_top *a)
{
	int		maximum;
	t_list	*start;

	start = a->top;
	maximum = ft_lstsize(start) - 1;
	while (start->next != NULL)
	{
		if (start->index != maximum)
			pushto_median(start, b, a, median);
		else
			rotate_a(a);
		start = a->top;
	}
}

t_list	*find_max_nnode(t_list *start)
{
	t_list	*max;

	max = start;
	while (start != NULL)
	{
		if (start->content > max->content)
			max = start;
		start = start->next;
	}
	return (max);
}
