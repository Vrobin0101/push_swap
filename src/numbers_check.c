/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:28:34 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/22 12:39:11 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		check_digits(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		check_duplicate(int *tab, int len)
{
	int i;
	int *cpy;

	cpy = NULL;
	cpy = copy_tab(cpy, tab, len);
	cpy = quicksort(cpy, len);
	i = 0;
	while (i + 1 < len)
	{
		if (cpy[i + 1] == cpy[i] || cpy[i] > INT_MAX || cpy[i] < INT_MIN)
		{
			ft_putendl("Error");
			free(cpy);
			return (0);
		}
		i++;
	}
	free(cpy);
	return (1);
}

int		check_multiples_digits(char **av, int nb)
{
	int i;

	i = 1;
	while (i < nb)
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN
				|| check_digits(av[i]) == 0)
		{
			ft_putendl("Error");
			return (0);
		}
		i++;
	}
	return (1);
}
