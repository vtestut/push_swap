/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:04:24 by vtestut           #+#    #+#             */
/*   Updated: 2023/04/28 18:53:49 by vtestut          ###   ########.fr       */
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

t_list *ft_lstnew(int content);
void ft_push_front(t_list **lst, int content);
void ft_pop_back(t_list **lst);
void ft_pop_front(t_list **lst);
void ft_push_back(t_list **lst, int content);
int	ft_atoi(char *str);
void display_list(t_list *a);

# endif
