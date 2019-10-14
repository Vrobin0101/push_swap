/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:40:52 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/10 15:09:47 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void		three_sort_a(int *tab, int len, t_string *string)
{
	if (bol_check(tab, len, 0, 1) == 1)
		return;
	if (tab[0] > tab[1] && tab[0] < tab[2] && tab[1] < tab[2])
	{
		list_push_back(string, initialize_list("sa"));
		tab = swap(tab, len);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
	{
		list_push_back(string, initialize_list("ra"));
		tab = rotate(tab, len);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
	{
		list_push_back(string, initialize_list("rra"));
		tab = r_rotate(tab, len);
	}
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		list_push_back(string, initialize_list("ra"));
		tab = rotate(tab, len);
		list_push_back(string, initialize_list("sa"));
		tab = swap(tab, len);
	}
}

void		three_sort_b(int *tab, int len, t_string *string)
{
	if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		return;
	if (tab[0] < tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
	{
		list_push_back(string, initialize_list("sb"));
		tab = swap(tab, len);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		list_push_back(string, initialize_list("rb"));
		tab = rotate(tab, len);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
	{
		list_push_back(string, initialize_list("rrb"));
		tab = r_rotate(tab, len);
	}
	else if (tab[0] < tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
	{
		list_push_back(string, initialize_list("rb"));
		tab = rotate(tab, len);
		list_push_back(string, initialize_list("sb"));
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

void		show_all(t_stack *stack)
{
	ft_printf("Pile A vaut\n%t", stack->tab_a, stack->size_a);
	ft_printf("Pile B vaut\n%t", stack->tab_b, stack->size_b);
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
			list_push_back(string, initialize_list("pb"));
			push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
			p++;
			div--;
		}
		else
		{
			list_push_back(string, initialize_list("ra"));
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
			list_push_back(string, initialize_list("pa"));
			push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
			p++;
			div--;
		}
		else
		{
			list_push_back(string, initialize_list("rb"));
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
				list_push_back(string, initialize_list("rb"));
			}
			else
			{
				stack->tab_a = rotate(stack->tab_a, stack->size_a);
				list_push_back(string, initialize_list("ra"));
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
				list_push_back(string, initialize_list("rrb"));
			}
			else
			{
				stack->tab_a = r_rotate(stack->tab_a, stack->size_a);
				list_push_back(string, initialize_list("rra"));
			}
		}
	}
}

void		check_swap(t_stack *stack, t_string *string, int check)
{
	if (check == 1)
		if (stack->tab_a[0] > stack->tab_a[1])
		{
			stack->tab_a = swap(stack->tab_a, stack->size_a);
			list_push_back(string, initialize_list("sa"));
		}
	if (check == 0)
		if (stack->tab_a[1] > stack->tab_a[0])
		{
			stack->tab_b = swap(stack->tab_b, stack->size_b);
			list_push_back(string, initialize_list("sb"));
		}
}

void		algo(t_stack *stack, t_string *string, int size, int check)
{
	int p;
	int rot;

	rot = 0;
	if (size < 2)
		return ;
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
			list_push_back(string, initialize_list("pa"));
			push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
		}
		else
		{
			list_push_back(string, initialize_list("pb"));
			push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
		}
		--p;
	}
}
