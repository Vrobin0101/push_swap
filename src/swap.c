/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 05:54:36 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/02 13:52:04 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		*swap(int *tab, int len)
{
	int swap;

	if (len > 1)
	{
		swap = tab[0];
		tab[0] = tab[1];
		tab[1] = swap;
	}
	return (tab);
}

void	ss(int **tab_a, int **tab_b, int len_a, int len_b)
{
	*tab_a = swap(*tab_a, len_a);
	*tab_b = swap(*tab_b, len_b);
}
