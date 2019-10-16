/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:50:57 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:39:46 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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

int				*copy_tab(int *bat, int *tab, int len)
{
	int i;

	i = 0;
	if (!(bat = (int*)malloc(sizeof(int) * len)))
		return (0);
	while (i < len)
	{
		bat[i] = tab[i];
		i++;
	}
	return (bat);
}

int				get_med(int *tab, int len)
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
