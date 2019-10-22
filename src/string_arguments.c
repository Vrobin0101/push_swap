/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:52:13 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/22 15:36:26 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		string_arguments(char **av, int nb)
{
	int i;
	int j;
	int nbr;

	i = 1;
	j = 0;
	nbr = 0;
	while (i < nb + 1)
	{
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9' && (av[i][j + 1] == ' '
						|| av[i][j + 1] == '\0'))
				nbr++;
			j++;
		}
		if (nbr > 1)
			return (0);
		nbr = 0;
		i++;
	}
	return (1);
}

int		search_ret(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[1] == '\0')
			return (1);
		i++;
	}
	return (0);
}
