/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 04:44:33 by vrobin            #+#    #+#             */
/*   Updated: 2019/09/11 10:42:44 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		check_digits(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_doublon(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i + 1 < len)
			if (tab[i + 1] == tab[i])
				return (0);
		i++;
	}
	return (1);
}
