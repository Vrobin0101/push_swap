/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:51:18 by vrobin            #+#    #+#             */
/*   Updated: 2019/07/08 12:58:15 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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

int		main(int nb, char **av)
{
	

}
