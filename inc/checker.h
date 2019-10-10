/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:40:15 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/10 13:38:22 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct	s_string
{
	char		*s;
	struct		s_string *next;
}				t_string;
typedef struct	s_chunk
{
	int			size;
	struct		s_chunk *next;
}				t_chunk;
typedef struct	s_stack
{
	int			*tab_a;
	int			size_a;
	int			*tab_b;
	int			size_b;
}				t_stack;
t_chunk	create_chunk(int p_i);
t_chunk	*initialize_chunk(int chunk);
void	free_chunk(t_chunk *to_delete);
void	chunk_push_back(t_chunk *src, t_chunk *to_add);
void	chunk_remove(t_chunk *src, size_t index);
void	chunk_clear(t_chunk *to_clear);
void	print_chunk(t_chunk *src);
t_chunk		*rev_chunk(t_chunk **begin);
t_string	create_list(char *p_s);
t_string	*initialize_list(char *p_s);
void	set_zero(t_stack *stack);
void	free_list(t_string *to_delete);
void	list_push_back(t_string *src, t_string *to_add);
void	list_remove(t_string *src, size_t index);
void	print_list(t_string *src);
void	list_clear(t_string *to_clear);
void	remove_push(t_string *list, int pb);
int		check_push(t_string *list);
int		check_rr(t_string *list);
int		check_digits(char *str);
int		check_doublon(int *tab, int len);
int		*string_tab(char *str, int *tab, int *len);
int		*swap(int *tab, int len);
int		*rotate(int *tab, int len);
int		*r_rotate(int *tab, int len);
int		*fill_tab(char **av, int *tab, int nb);
int		bol_check(int *tab, int len, int len2, int check);
int		*quicksort(int *v, int i);
void	rr(int **tab_a, int **tab_b, int len_a, int len_b);
void	rrr(int **tab_a, int **tab_b, int len_a, int len_b);
void	ss(int **tab_a, int **tab_b, int len_a, int len_b);
void	push(int **dst, int **src, int *len_dst, int *len_src);
void	show_tab(int *tab, int len);
void	checkn(int *tab, int len1, int len2);
void	algo(t_stack *stack, t_string *string, int size, int check);
#endif
