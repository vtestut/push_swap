/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:04:24 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/29 14:02:46 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct	s_stack
{
	t_list	*a;
	t_list	*b;
}				t_stack;

/****   MOVES 1   ****/
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	ss(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

/****   MOVES 2   ****/
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rr(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);

/****   MOVES 3  ****/
void	rrr(t_stack *stack);

/****   LIST_UTILS   ****/
t_list	*ft_lstnew(int content);
void	ft_push_front(t_list **lst, int content);
void	ft_pop_back(t_list **lst);
void	ft_pop_front(t_list **lst);
void	ft_push_back(t_list **lst, int content);

/****   UTILS   ****/
t_list	*push_args(int argc, char **argv);
int		ft_isspace(char c);
int		ft_atoi(char *str);
void	display_list(t_list *a);

# endif
