/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:44:38 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 17:00:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ptr	*ft_init_a(int ac, char **av)
{
	t_ptr	*ptr;

	ptr = malloc(sizeof(t_ptr));
	if (!ptr)
		return (NULL);
	ptr->top = ft_fill_a(ac, av);
	return (ptr);
}

t_ptr	*ft_init_b(void)
{
	t_ptr	*ptr;
	t_lst	*b;

	b = NULL;
	ptr = malloc(sizeof(t_lst));
	if (!ptr)
		return (NULL);
	ptr->top = b;
	return (ptr);
}

void	ft_sort(t_ptr *a, t_ptr *b, int n)
{
	if (n == 2)
		swap_a(a);
	else if (n == 3)
		ft_sort_3(a);
	else if (n == 4)
		ft_small_sort(a, b, 4);
	else if (n == 5)
		ft_small_sort(a, b, 5);
	else if (n > 5)
		ft_big_sort(a, b);
}

bool	ft_check_args(int ac, char **av)
{
	int	i;
	int	*args;

	i = ac;
	while (--i)
	{
		if (!(ft_isnum(av[i])))
			return (false);
	}
	args = ft_convert_params(ac, av);
	if (!args)
		return (false);
	if (!ft_check_double(ac, args))
		return (false);
	if (ft_is_sorted(ac, args))
		return (false);
	free(args);
	return (true);
}

int	main(int ac, char **av)
{
	t_ptr	*a;
	t_ptr	*b;

	if (ac < 3)
		exit (0);
	if (!ft_check_args(ac, av))
		return (1);
	a = ft_init_a(ac, av);
	b = ft_init_b();
	if (!a || !b)
		return (1);
	ft_index_list(a);
	ft_sort(a, b, ac - 1);
	ft_free_all(a->top, a, b->top, b);
	return (0);
}
