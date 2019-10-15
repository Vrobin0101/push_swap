/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:40:15 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/15 15:57:05 by vrobin           ###   ########.fr       */
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

int			check_digits(char *str);
int			check_duplicate(int *tab, int len);
int			*str_to_tab(char *str, int *tab, int *len);
int			*fill_tab(char **av, int *tab, int nb);
void		check_end(int *tab, int len1, int len2);
t_string	create_string(char *p_s);
t_string	*initialize_string(char *p_s);
void		string_push_back(t_string *src, t_string *to_add);
void		free_string(t_string *to_delete);
void		string_remove(t_string *src, size_t index);
void		string_clear(t_string *to_clear);
void		print_string(t_string *src);


int			*swap(int *tab, int len);
int			*rotate(int *tab, int len);
int			*r_rotate(int *tab, int len);
void		push(int **dst, int **src, int *len_dst, int *len_src);
void		rr(int **tab_a, int **tab_b, int len_a, int len_b);
void		rrr(int **tab_a, int **tab_b, int len_a, int len_b);
void		ss(int **tab_a, int **tab_b, int len_a, int len_b);
void		show_tab(int *tab, int len);

void	set_zero(t_stack *stack);
void	three_sort_a(int *tab, int len, t_string *string);
void	three_sort_b(int *tab, int len, t_string *string);
void	algo(t_stack *stack, t_string *string, int size, int check);
int		bol_check(int *tab, int len, int check);
int		remove_instructions(t_string *list);
int		*quicksort(int *v, int i);
#endif
