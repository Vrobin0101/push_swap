/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:09:45 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 11:22:56 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void		three_sort_a_next(int *tab, int len, t_string *string)
{
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		string_push_back(string, initialize_string("rra"));
		tab = r_rotate(tab, len);
		string_push_back(string, initialize_string("sa"));
		tab = swap(tab, len);
		return ;
	}
	if (bol_check(tab, len, 0) == 1)
	{
		string_push_back(string, initialize_string("ra"));
		tab = rotate(tab, len);
		string_push_back(string, initialize_string("sa"));
		tab = swap(tab, len);
		return ;
	}
}

void		three_sort_a(int *tab, int len, t_string *string)
{
	if (bol_check(tab, len, 1) == 1)
		return ;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
	{
		string_push_back(string, initialize_string("sa"));
		tab = swap(tab, len);
		return ;
	}
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
	{
		string_push_back(string, initialize_string("ra"));
		tab = rotate(tab, len);
		return ;
	}
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
	{
		string_push_back(string, initialize_string("rra"));
		tab = r_rotate(tab, len);
		return ;
	}
	three_sort_a_next(tab, len, string);
}

void		three_sort_b_next(int *tab, int len, t_string *string)
{
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
	{
		string_push_back(string, initialize_string("rrb"));
		tab = r_rotate(tab, len);
		string_push_back(string, initialize_string("sb"));
		tab = swap(tab, len);
		return ;
	}
	if (bol_check(tab, len, 1) == 1)
	{
		string_push_back(string, initialize_string("rb"));
		tab = rotate(tab, len);
		string_push_back(string, initialize_string("sb"));
		tab = swap(tab, len);
		return ;
	}
}

void		three_sort_b(int *tab, int len, t_string *string)
{
	if (bol_check(tab, len, 0) == 1)
		return ;
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		string_push_back(string, initialize_string("sb"));
		tab = swap(tab, len);
		return ;
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		string_push_back(string, initialize_string("rb"));
		tab = rotate(tab, len);
		return ;
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
	{
		string_push_back(string, initialize_string("rrb"));
		tab = r_rotate(tab, len);
		return ;
	}
	three_sort_b_next(tab, len, string);
}

int			test_ret(t_stack *stack, t_string *string, int check, int size)
{
	if (size < 2)
		return (0);
	if (size == 2)
	{
		if (check == 0 && stack->tab_a[0] > stack->tab_a[1])
		{
			stack->tab_a = swap(stack->tab_a, stack->size_a);
			string_push_back(string, initialize_string("sa"));
		}
		if (check == 1 && stack->tab_b[0] < stack->tab_b[1])
		{
			stack->tab_b = swap(stack->tab_b, stack->size_b);
			string_push_back(string, initialize_string("sb"));
		}
		return (0);
	}
	if (size == 3 && (stack->size_a == 3 || stack->size_b == 3))
	{
		if (check == 0)
			three_sort_a(stack->tab_a, stack->size_a, string);
		else if (check == 1)
			three_sort_b(stack->tab_b, stack->size_b, string);
		return (0);
	}
	return (1);
}
