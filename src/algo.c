/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:40:52 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/15 17:57:48 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void		three_sort_a(int *tab, int len, t_string *string)
{
	if (bol_check(tab, len, 1) == 1)
		return;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
	{
		string_push_back(string, initialize_string("sa"));
		tab = swap(tab, len);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
	{
		string_push_back(string, initialize_string("ra"));
		tab = rotate(tab, len);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
	{
		string_push_back(string, initialize_string("rra"));
		tab = r_rotate(tab, len);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		string_push_back(string, initialize_string("rra"));
		tab = r_rotate(tab, len);
		string_push_back(string, initialize_string("sa"));
		tab = swap(tab, len);
	}
	else if (bol_check(tab, len, 0) == 1)
	{
		string_push_back(string, initialize_string("ra"));
		tab = rotate(tab, len);
		string_push_back(string, initialize_string("sa"));
		tab = swap(tab, len);
	}
}

void		three_sort_b(int *tab, int len, t_string *string)
{
	if (bol_check(tab, len, 0) == 1)
		return;
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		string_push_back(string, initialize_string("sb"));
		tab = swap(tab, len);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		string_push_back(string, initialize_string("rb"));
		tab = rotate(tab, len);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
	{
		string_push_back(string, initialize_string("rrb"));
		tab = r_rotate(tab, len);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
	{
		string_push_back(string, initialize_string("rrb"));
		tab = r_rotate(tab, len);
		string_push_back(string, initialize_string("sb"));
		tab = swap(tab, len);
	}
	else if (bol_check(tab, len, 1) == 1)
	{
		string_push_back(string, initialize_string("rb"));
		tab = rotate(tab, len);
		string_push_back(string, initialize_string("sb"));
		tab = swap(tab, len);
	}
}

int			*copy_tab(int *bat, int *tab, int len)
{
	int i;

	i = 0;
	bat = (int*)malloc(sizeof(int) * len);
	while (i < len)
	{
		bat[i] = tab[i];
		i++;
	}
	return (bat);
}

int			get_med(int *tab, int len)
{
	int *bat;
	int med;

	bat = NULL;
	bat = copy_tab(bat, tab, len);
	bat = quicksort(bat, len);
	med = bat[len / 2];
	free(bat);
	return (med);
}

int		quickswap_a(t_stack *stack, t_string *string, int len, int *r)
{
	int med;
	int div;
	int p;
	int i;

	p = 0;
	i = 0;
	med = get_med(stack->tab_a, len);
	div = len / 2;
	while (i < len)
	{
		if (stack->tab_a[0] < med)
		{
			string_push_back(string, initialize_string("pb"));
			push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
			p++;
			div--;
		}
		else
		{
			string_push_back(string, initialize_string("ra"));
			stack->tab_a = rotate(stack->tab_a, stack->size_a);
			(*r)++;
		}
		i++;
	}
	return (p);
}

int		quickswap_b(t_stack *stack, t_string *string, int len, int *r)
{
	int med;
	int div;
	int p;
	int i;

	p = 0;
	i = 0;
	med = get_med(stack->tab_b, len);
	div = len / 2;
	while (i < len)
	{
		if (stack->tab_b[0] >= med)
		{
			string_push_back(string, initialize_string("pa"));
			push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
			p++;
			div--;
		}
		else
		{
			string_push_back(string, initialize_string("rb"));
			stack->tab_b = rotate(stack->tab_b, stack->size_b);
			(*r)++;
		}
		i++;
	}
	return (p);
}

void		rotate_back(t_stack *stack, t_string *string, int rr, int check)
{
	int	c;

	c = check ? stack->size_b : stack->size_a;
	if (rr > c / 2)
	{
		while (c - rr++)
		{
			if (check == 1)
			{
				stack->tab_b = rotate(stack->tab_b, stack->size_b);
				string_push_back(string, initialize_string("rb"));
			}
			else
			{
				stack->tab_a = rotate(stack->tab_a, stack->size_a);
				string_push_back(string, initialize_string("ra"));
			}
		}
	}
	else
	{
		while (rr--)
		{
			if (check == 1)
			{
				stack->tab_b = r_rotate(stack->tab_b, stack->size_b);
				string_push_back(string, initialize_string("rrb"));
			}
			else
			{
				stack->tab_a = r_rotate(stack->tab_a, stack->size_a);
				string_push_back(string, initialize_string("rra"));
			}
		}
	}
}

void		algo(t_stack *stack, t_string *string, int size, int check)
{
	int p;
	int rot;

	rot = 0;
	if (size < 2)
		return ;
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
		return;
	}
	if (size == 3)
	{
		if (check == 0 && stack->size_a == 3)
		{
			three_sort_a(stack->tab_a, stack->size_a, string);
			return;
		}
		if (check == 1 && stack->size_b == 3)
		{
			three_sort_b(stack->tab_b, stack->size_b, string);
			return;
		}
	}
	if (check == 0)
		p = quickswap_a(stack, string, size, &rot);
	else
		p = quickswap_b(stack, string, size, &rot);
	if (stack->size_a != 2)
		rotate_back(stack, string, rot, check);
	if (size > 1)
	{
		algo(stack, string, size - p, (check == 0 ? 0 : 1));
		algo(stack, string, p, (check == 0 ? 1 : 0));
	}
	while (p)
	{
		if (check == 0)
		{
			string_push_back(string, initialize_string("pa"));
			push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
		}
		else
		{
			string_push_back(string, initialize_string("pb"));
			push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
		}
		--p;
	}
}