/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 04:44:33 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/30 14:45:52 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		check_digits(char *str)
{
	int i;
	int checker;

	i = 0;
	checker = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		if (ft_isdigit(str[i]))
			checker = 1;
		i++;
	}
	if (checker == 1)
		return (1);
	else
		return (0);
}

int		check_doublon(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i + 1 < len)
			if (tab[i + 1] == tab[i] || tab[i] > INT_MAX || tab[i] < INT_MIN)
				return (0);
		i++;
	}
	return (1);
}
