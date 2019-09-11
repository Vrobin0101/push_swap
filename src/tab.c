/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:18:21 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/11 10:09:47 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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
		if (!check_digits(av[i + 1]))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		if (ft_atoi(av[i + 1]) > INT_MAX || ft_atoi(av[i + 1]) < INT_MIN)
			return (NULL);
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	if (!check_doublon(tab, nb))
		return (NULL);
	return (tab);
}

void	checkn(int *tab, int len1, int len2)
{
	int i;

	i = 0;
	if (len2)
	{
		ft_putendl("KO");
		return ;
	}
	while (i < len1 - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			ft_putendl("KO");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
}
