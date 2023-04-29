/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:44:38 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/29 15:07:09 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 2)
	{
		stack.a = push_args(argc, argv);
		stack.b = push_args(argc, argv);
		ss(&stack);
		rrr(&stack);
		display_list(stack.a);
		display_list(stack.b);
	}
	return (0);
}
