/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:51:18 by vrobin            #+#    #+#             */
/*   Updated: 2019/07/18 04:32:02 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void		eswap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int		checkn(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i + 1] < tab[i])
			return (0);
		i++;
	}
	return (1);
}

int		*fill_tab(char **av, int *tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (ft_atoi(av[i + 1]) > INT_MAX || ft_atoi(av[i + 1]) < INT_MIN)
			return (NULL);
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (tab);
}

//ft_printf("%t\n", tab, nb);

int		main(int nb, char **av)
{
	int *tab;
	int	len;
	int pivot;

	nb -= 1;
	len = nb;
	if (!(tab = (int*)malloc(sizeof(int) * nb)))
				return (0);
	tab = fill_tab(av, tab, nb);
	pivot = len / 2;
	len -= 1;
	while (checkn(tab, nb) < 1)
	{
		eswap(&(tab[pivot]), &(tab[len]));
	}
}
