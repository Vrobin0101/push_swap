/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 04:37:59 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/15 17:58:37 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		*rotate(int *tab, int len)
{
	int swap;
	int	i;

	i = 0;
	swap = 0;
	if (len > 0)
	{
		while (i < len - 1)
		{
			swap = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = swap;
			i++;
		}
	}
	return (tab);
}

void	rr(int **tab_a, int **tab_b, int len_a, int len_b)
{
	*tab_a = rotate(*tab_a, len_a);
	*tab_b = rotate(*tab_b, len_b);
}

int		*r_rotate(int *tab, int len)
{
	int swap;

	swap = 0;
	if (len > 0)
	{
		len -= 1;
		while (len)
		{
			len--;
			swap = tab[len + 1];
			tab[len + 1] = tab[len];
			tab[len] = swap;
		}
	}
	return (tab);
}

void	rrr(int **tab_a, int **tab_b, int len_a, int len_b)
{
	*tab_a = r_rotate(*tab_a, len_a);
	*tab_b = r_rotate(*tab_b, len_b);
}
