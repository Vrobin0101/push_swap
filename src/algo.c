/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:20:41 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/02 16:48:41 by vrobin           ###   ########.fr       */
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
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	algo(int *tab1, int len1, int *bat)
{
	int *tab2;
	int len2;
	int med;
	int i;

	tab2 = (int*)malloc(sizeof(int) * 1);
	len2 = 0;
	i = 0;
	bat = quicksort(bat, len1);
	med = bat[len1 / 2];
	printf("med = %d\n", med);
	show_tab(tab1, len1);
	while (check_tab(tab1, len1, len2) == 0)
	{
		if (tab1[0] > tab1[1])
		{
			ft_putstr("sa\n");
			swap(tab1, len1);
			continue;
		}
		if (tab1[0] > med)
		{
			ft_putstr("pb\n");
			push(&tab2, &tab1, &len2, &len1);
		}
	}
	printf("tab 1\n");
	show_tab(tab1, len1);
}
