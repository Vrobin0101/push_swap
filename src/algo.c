/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:20:41 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/05 18:22:22 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	b_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
void			echanger(int *v, int i, int j)
{
	int		temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void			trirapide(int *v, int gauche, int droit)
{
	int		i;
	int		dernier;

	if (gauche >= droit)
		return ;
	echanger(v, gauche, (gauche + droit) / 2);
	dernier = gauche;
	i = gauche + 1;
	while (i <= droit)
	{
		if (v[i] < v[gauche])
			echanger(v, ++dernier, i);
		i++;
	}
	echanger(v, gauche, dernier);
	trirapide(v, gauche, dernier - 1);
	trirapide(v, dernier + 1, droit);
}

int				*quicksort(int *v, int i)
{
	trirapide(v, 0, i - 1);
	return (v);
}

int				check_tab(int *tab1, int len1, int len2)
{
	int i;

	i = 0;
	if (len2)
		return (0);
	while (i + 1 < len1)
	{
		if (tab1[i] > tab1[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		*copy_tab(int *tab, int *bat, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		bat[i] = tab[i];
		i++;
	}
	return (bat);
}

int		*b_move(int *tab, int len)
{
	if (len > 1)
	{
		if (tab[0] < tab[len - 1])
		{
			ft_printf("rb\n");
			tab = rotate(tab, len);
		}
		if (tab[0] < tab[1])
		{
			ft_printf("sb\n");
			tab = swap(tab, len);
		}
	}
	return (tab);
}

int		*a_move(int *tab, int len)
{
	if (len > 1)
	{
		if (tab[0] > tab[1])
			tab = swap(tab, len);
	}
	return (tab);
}

void	algo(int *tab1, int len1)
{
	int *tab2;
	int *bat;
	int len2;
	int med;
	int div;
	int i;

	tab2 = (int*)malloc(sizeof(int) * 1);
	bat = (int*)malloc(sizeof(int) * len1);
	len2 = 0;
	i = 0;
	bat = copy_tab(tab1, bat, len1);
	bat = quicksort(bat, len1);
	med = bat[len1 / 2];
	div = len1 / 2;
	while (len1 > 3)
	{
		while (div)
		{
			if (tab1[0] < med)
			{
				ft_putstr("pb\n");
				push(&tab2, &tab1, &len2, &len1);
				tab2 = b_move(tab2, len2);
				div--;
			}
			else
			{
				ft_putstr("rra\n");
				tab1 = r_rotate(tab1, len1);
			}
		}
		bat = copy_tab(tab1, bat, len1);
		bat = quicksort(bat, len1);
		med = bat[len1 / 2];
		div = len1 / 2;
	}
	if (tab1[len1 - 1] < tab1[0] && tab1[0] > tab1[1])
	{
		ft_printf("ra\n");
		tab1 = rotate(tab1, len1);
	}
	else if (tab1[len1 - 1] > tab1[0] && tab1[0] < tab1[1])
	{
		ft_printf("rra\n");
		tab1 = r_rotate(tab1, len1);
	}
	else if (tab1[0] > tab1[1])
	{
		ft_printf("sa\n");
		tab1 = swap(tab1, len1);
	}
	free(bat);
	bat = (int*)malloc(sizeof(int) * len2);
	bat = copy_tab(tab2, bat, len2);
	bat = quicksort(bat, len2);
	med = bat[len2 / 2];
	div = len2 / 2;
	while (len2)
	{
		ft_putstr("pa\n");
		push(&tab1, &tab2, &len1, &len2);
		tab1 = a_move(tab1, len1);
	}
	ft_printf("tab 1\n");
	show_tab(tab1, len1);
	ft_printf("tab 2\n");
	show_tab(tab2, len2);
}
