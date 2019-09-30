/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:40:52 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/30 17:11:43 by vrobin           ###   ########.fr       */
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
}

void		three_sort_b(int *tab, int len, t_string *string)
{
	if (bol_check(tab, len, 0, 0) == 1)
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

int			max_value(int *tab, int len)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (tab[i] == max)
			break;
		i++;
	}
	return (max);
}

int			get_path_a(int *tab, int len, int min)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == min)
			break;
		i++;
	}
	if (i > len / 2)
		return (len - i);
	else
		return (i);
}

int			get_path_b(int *tab, int len, int max)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == max)
			break;
		i++;
	}
	if (i > len / 2)
		return (i - len);
	else
		return (i);
}

void		algo(t_stack *stack, t_string *string)
{
	int med;
	int div;

	med = get_med(stack->tab_a, stack->size_a);
	div = stack->size_a / 2;
	while (stack->size_a >= 3)
	{
		while (div)
		{
			if (stack->tab_a[0] < med)
			{
				list_push_back(string, initialize_list("pb"));
				push(&stack->tab_b, &stack->tab_a, &stack->size_b, &stack->size_a);
				div--;
			}
			else
			{
				list_push_back(string, initialize_list("ra"));
				stack->tab_a = rotate(stack->tab_a, stack->size_a);
			}
		}
		med = get_med(stack->tab_a, stack->size_a);
		div = stack->size_a / 2;
	}
	if (stack->size_a == 2)
	{
		if (stack->tab_a[0] > stack->tab_a[1])
		{
			list_push_back(string, initialize_list("sa"));
			stack->tab_a = swap(stack->tab_a, stack->size_a);
		}
	}
	else if (stack->size_a == 3)
		three_sort_a(stack->tab_a, stack->size_a, string);
	finish_push(stack, string);
}

void	finish_push(t_stack *stack, t_string *string)
{
	int index;
	int r;
	int check;

	index = 0;
	check = 0;
	while (stack->size_b)
	{
		check = 1;
		index = max_value(stack->tab_b, stack->size_b);
		if (stack->tab_b[0] != index)
		{
			r = get_path_b(stack->tab_b, stack->size_b, index);
			if (r < 0)
			{
				while (r != 0)
				{
					list_push_back(string, initialize_list("rrb"));
					stack->tab_b = r_rotate(stack->tab_b, stack->size_b);
					r++;
				}
			}
			else if (r > 0)
			{
				while (r != 0)
				{
					list_push_back(string, initialize_list("rb"));
					stack->tab_b = rotate(stack->tab_b, stack->size_b);
					r--;
				}
			}
		}
		list_push_back(string, initialize_list("pa"));
		push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
	}
	//ft_printf("Pile A vaut \n%t\n", stack->tab_a, stack->size_a);
	print_list(string);
}
