/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:44:38 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/04 17:51:02 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_top *init_stack_a(int ac, char **av)
{
	t_top	*ptr;
	
	ptr = malloc(sizeof(t_top));
	if (!ptr)
		return (NULL);
	ptr->top = fill_list_a(ac, av);
	return (ptr);
}

t_top *init_stack_b(void)
{
	t_top	*ptr;
	t_list	*b;

	b = NULL;
	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->top = b;
	return (ptr);
}

bool	check_args(int ac, char **av)
{
	int	i;

	i = ac;
	while (--i)
	{
		if (!(ft_isnum(av[i])))
			return (false);
	}
	if (!check_double(ac, av))
		return (true);
	return (false);
}

void	ft_sort(t_top *a, t_top *b, int n)
{
	if (n == 2)
		swap_a(a);
	else if (n == 3)
		ft_sort_3(a);
	else if (n == 4)
		ft_sort_5(a, b, 4);
	else if (n == 5)
		ft_sort_5(a, b, 5);
	else if (n > 5)
		ft_big_sort(a, b);
}

int	main(int ac, char **av)
{
	t_top	*a;
	t_top	*b;

	if (ac == 1)
		return (0);
	if (!check_args(ac, av))
		return (1); // print error
	a = init_stack_a(ac, av);
	b = init_stack_b();
	if (!a || !b)
		return (0);
	index_list(a);
	ft_sort(a, b, ac - 1);
	free_list(a->top, a);
	free_list(b->top, b);
	return (0);
}
