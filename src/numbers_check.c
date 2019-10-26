/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:28:34 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/26 11:25:11 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		check_digits(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (i != 0 && str[i - 1] != ' ')
				return (0);
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (0);
		}
		if (ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			check = 1;
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (check);
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

int		behavior_check(t_stack *stack)
{
	if (stack->tab_a == NULL)
	{
		ft_printf("Error\n");
		free(stack);
		return (0);
	}
	return (1);
}
