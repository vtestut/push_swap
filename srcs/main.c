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
	ptr->top = new_list(ac, av);
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

void	ft_sort(t_top *a, t_top *b, int ac)
{
	(void)b;
	if (ac - 1 == 2)
		swap_a(a);
	else if (ac - 1 == 3)
		ft_sort_3(a);
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
	// b = init_stack_a(ac, av);
	if (!a || !b)
		return (0);
	index_list(a);
	// index_list(b);
	printf("\n");
	printf("-----------------------------------\n");
	display_list(a);
	// display_list(b);
	printf("-----------------------------------\n");
	ft_sort(a, b, ac);
	// ss(a, b);
	// push_a(a, b);
	// rotate_a(a);
	display_list(a);
	// display_list(a);
	// display_list(b);
	return (0);
}
