/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:29:20 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/15 15:45:02 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

int		*str_to_tab(char *str, int *tab, int *len)
{
	char **split;
	int	 i;

	split = ft_strsplit(str, ' ');
	i = 0;
	while (split[i] != NULL)
		i++;
	*len = i;
	if (!(tab = (int*)malloc(sizeof(int) * *len)))
		return (0);
	i = 0;
	while (i < *len)
	{
		tab[i] = ft_atoi(split[i]);
		if (ft_atoi(split[i]) > INT_MAX || ft_atoi(split[i]) < INT_MIN)
			return (NULL);
		i++;
	}
	return (tab);
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
