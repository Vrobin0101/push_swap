/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:28:34 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:45:31 by vrobin           ###   ########.fr       */
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
	while (i < len)
	{
		if (i + 1 < len)
			if (cpy[i + 1] == cpy[i] || cpy[i] > INT_MAX || cpy[i] < INT_MIN)
				return (0);
		i++;
	}
	free(cpy);
	return (1);
}
