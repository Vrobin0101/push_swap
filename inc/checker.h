/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:40:15 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/22 15:24:29 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_string
{
	char			*s;
	struct s_string *next;
}				t_string;
typedef struct	s_stack
{
	int			*tab_a;
	int			size_a;
	int			*tab_b;
	int			size_b;
}				t_stack;

void			check_end(int *tab, int len1, int len2);
void			string_push_back(t_string *src, t_string *to_add);
void			free_string(t_string *to_delete);
void			string_remove(t_string *src, size_t index);
void			free_all(t_stack *stack, t_string *string);
void			free_check(t_stack *stack, char *str);
void			string_clear(t_string *to_clear);
void			print_string(t_string *src);
void			push(int **dst, int **src, int *len_dst, int *len_src);
void			rr(int **tab_a, int **tab_b, int len_a, int len_b);
void			rrr(int **tab_a, int **tab_b, int len_a, int len_b);
void			ss(int **tab_a, int **tab_b, int len_a, int len_b);
void			show_tab(int *tab, int len, int d);
void			show_all(int *tab1, int *tab2, int len1, int len2);
void			convert_num(t_stack *stack, char **av, int nb);
void			remove_check(t_string *list);
void			set_zero(t_stack *stack);
void			three_sort_a(int *tab, int len, t_string *string);
void			three_sort_b(int *tab, int len, t_string *string);
void			algo(t_stack *stack, t_string *string, int size, int check);

int				*quicksort(int *v, int i);
int				*copy_tab(int *bat, int *tab, int len);
int				quickswap_a(t_stack *stack, t_string *string, int len, int *r);
int				quickswap_b(t_stack *stack, t_string *string, int len, int *r);
int				bol_check(int *tab, int len, int check);
int				remove_instructions(t_string *list);
int				get_med(int *tab, int len);
int				check_duplicate(int *tab, int len);
int				check_digits(char *str);
int				test_ret(t_stack *stack, t_string *string, int check, int size);
int				*swap(int *tab, int len);
int				*rotate(int *tab, int len);
int				*r_rotate(int *tab, int len);
int				*str_to_tab(char *str, int *tab, int *len);
int				*fill_tab(char **av, int *tab, int nb);
int				check_multiples_digits(char **av, int nb);
int				string_arguments(char **av, int nb);
int				search_ret(char *str);

t_string		create_string(char *p_s);
t_string		*initialize_string(char *p_s);
#endif
