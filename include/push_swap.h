/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:04:24 by vtestut           #+#    #+#             */
/*   Updated: 2023/05/17 17:11:04 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct t_lst
{
	int				content;
	int				index;
	struct t_lst	*next;
}					t_lst;

typedef struct t_ptr
{
	t_lst		*top;
}					t_ptr;

typedef struct t_val
{
	t_lst			*node;
	int				rra;
	int				rrb;
	int				ra;
	int				rb;
	int				rr;
	int				rrr;

}					t_val;

//			PARSING
bool	ft_check_double(int ac, int *args);
bool	ft_is_sorted(int ac, int *args);
int		*ft_convert_params(int ac, char **av);
bool	ft_isnum(const char *str);
bool	ft_isdigit(const int c);

//			INDEX
void	ft_index_list(t_ptr *a);
t_lst	*ft_find_smallest(t_lst *start);
int		ft_next_smallest(t_lst *start, int min);
int		ft_find_biggest(t_lst *start);

//			PUSH_SWAP
void	push_a(t_ptr *a, t_ptr *b);
void	push_b(t_ptr *a, t_ptr *b);
void	swap_a(t_ptr *lst);
void	swap_b(t_ptr *lst);
void	swap_s(t_ptr *a, t_ptr *b);

//			ROTATE
void	rotate_a(t_ptr *a, int flag);
void	rotate_b(t_ptr *b, int flag);
void	rotate_r(t_ptr *a, t_ptr *b);

//			REVERSE_ROTATE
void	reverse_rotate_a(t_ptr *a, int flag);
void	reverse_rotate_b(t_ptr *b, int flag);
void	reverse_rotate_r(t_ptr *a, t_ptr *b);

//			SORT_UP_TO_5
void	ft_small_sort(t_ptr *a, t_ptr *b, int n);
void	ft_sort_3(t_ptr *a);
void	ft_sort_5(t_lst *tmp, t_ptr *a, t_ptr *b);
void	ft_small_on_top(t_ptr *a, int min);

//			SORT_UP_TO_500
void	ft_big_sort(t_ptr *a, t_ptr *b);
void	ft_push_smallest(t_ptr *a, t_lst *first);
void	ft_last_move(t_val smallest, t_ptr *a);
void	ft_insertion_sort(t_ptr *a, t_ptr *b);

//			GET_MEDIAN
void	ft_median_sort(int median, t_ptr *b, t_ptr *a);
void	ft_push_to_median(t_lst *start, t_ptr *b, t_ptr *a, int median);
t_lst	*ft_max_a(t_lst *start);

//			COUNT_MOVE
int		ft_compare_moves(t_val current, t_val next_node);
t_val	ft_move_count_b(t_ptr *a, t_lst *node_b, t_ptr *b, t_val cur);
t_val	ft_move_count_a(t_lst *node_a, t_ptr *a, t_val current);
t_lst	*ft_find_a_max(t_lst *node_b, t_ptr *a);

//			QUICK_MOVE
void	ft_quick_move(t_val val, t_ptr *a, t_ptr *b);
t_val	ft_getmax_rotation(t_val val);
t_val	ft_getmax_reverse_rotation(t_val val);
void	ft_rotate(t_val val, t_ptr *a, t_ptr *b);
void	ft_reverse_rotate(t_val val, t_ptr *a, t_ptr *b);

//			PARSING_UTILS
int		ft_is_space(char c);
int		ft_atoi(char *str);
int		ft_count_num(int n);
char	*ft_itoa(int n);
bool	ft_check_arg_size(char *arg);

//			LIST_UTILS
int		ft_lstsize(t_lst *lst);
void	ft_lstaddback(t_lst **lst, t_lst *new);
t_lst	*ft_fill_a(int ac, char **av);
void	ft_free_all(t_lst *a_top, t_ptr *a, t_lst *b_top, t_ptr *b);

//			UTILS
int		ft_strcmp(char *s1, char *s2);
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_second_last_node(t_lst *lst);

#endif