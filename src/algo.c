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

int			prev_max_value(int *tab, int len, int max)
{
	int i;
	int prev_max;

	i = 0;
	prev_max = 0;
	while (i < len)
	{
		if (tab[i] > prev_max)
		{
			if (tab[i] != max)
				prev_max = tab[i];
		}
		i++;
	}
	i = 0;
	return (prev_max);
}

void		show_all(t_stack *stack)
{
	ft_printf("Pile A vaut\n%t", stack->tab_a, stack->size_a);
	ft_printf("Pile B vaut\n%t", stack->tab_b, stack->size_b);
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

void	print_all(t_stack *stack, t_chunk *chunk)
{
	while (chunk->next != NULL)
	{
		ft_printf("\nPile B vaut \n%t\n", stack->tab_b, chunk->size);
		stack->tab_b += chunk->size;
		chunk = chunk->next;
	}
}

//ft_printf("med vaut %d, div vaut %d\n", med, div);

int		quickswap_a(t_stack *stack, t_string *string, int len, int *r)
{
	int med;
	int div;
	int p;

	p = 0;
	med = get_med(stack->tab_a, len);
	div = len / 2;
	while (div)
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
	}
	return (p);
}

int		quickswap_b(t_stack *stack, t_string *string, int len, int *r)
{
	int med;
	int div;
	int p;

	p = 0;
	med = get_med(stack->tab_b, len);
	div = len / 2;
	while (div)
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
	}
	return (p);
}

void		rotate_back(t_stack *stack, t_string *string, int *r, int check)
{
	if (check == 0 && bol_check(stack->tab_a, stack->size_a, 0, 1) == 0)
	{
		if (*r > stack->size_a / 2)
		{
			while (*r != 0)
			{
				list_push_back(string, initialize_list("rra"));
				stack->tab_a = r_rotate(stack->tab_a, stack->size_a);
				(*r)--;
			}
		}
		else
		{
			while (*r != 0)
			{
				list_push_back(string, initialize_list("ra"));
				stack->tab_a = rotate(stack->tab_a, stack->size_a);
				(*r)--;
			}
		}
	}
	else
	{
		if (*r > stack->size_b / 2)
		{
			while (*r != 0)
			{
				list_push_back(string, initialize_list("rrb"));
				stack->tab_b = r_rotate(stack->tab_b, stack->size_b);
				(*r)--;
			}
		}
		else
		{
			while (*r != 0)
			{
				list_push_back(string, initialize_list("rb"));
				stack->tab_b = rotate(stack->tab_b, stack->size_b);
				(*r)--;
			}
		}
	}
}

void		algo(t_stack *stack, t_string *string, int size, int check)
{
	int p;
	int r;

	if (size == 1)
	{
		list_push_back(string, initialize_list("pa"));
		push(&stack->tab_a, &stack->tab_b, &stack->size_a, &stack->size_b);
		return;
	}
	if (check == 0)
	{
		p = quickswap_a(stack, string, size, &r);
		if (r > 0)
			rotate_back(stack, string, &r, check);
		algo(stack, string, p, 1);
	}
	else
	{
		p = quickswap_b(stack, string, size, &r);
		if (r > 0)
			rotate_back(stack, string, &r, check);
		algo(stack, string, stack->size_a - p, 0);
	}
}
