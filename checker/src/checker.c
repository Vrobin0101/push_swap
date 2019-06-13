/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 02:54:49 by vrobin            #+#    #+#             */
/*   Updated: 2019/06/13 06:01:57 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

void	show_tab(int *tab, int len)
{
	int i;

	i = 0;
	ft_putchar('\n');
	while (i < len)
		ft_putendl(ft_itoa(tab[i++]));
	ft_putchar('\n');
}

int		*fill_tab(char **av, int *tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (tab);
}

int		main(int nb, char **av)
{
	int *tab1;
	int	*tab2;
	int	len1;
	int	len2;

	len2 = 0;
	tab2 = NULL;
	nb -= 1;
	len1 = nb;
	if (!(tab1 = (int*)malloc(sizeof(int) * nb)))
			return (0);
	tab1 = fill_tab(av, tab1, nb);
	swap(tab1, len1);
	show_tab(tab1, len1);
	return (0);
}
