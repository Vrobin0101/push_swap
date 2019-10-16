/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:29:20 by vrobin            #+#    #+#             */
/*   Updated: 2019/10/16 18:46:56 by vrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int		*str_to_tab(char *str, int *tab, int *len)
{
	char	**split;
	int		i;

	if (!(tab = (int*)malloc(sizeof(int) * ft_strlen(str))))
		return (NULL);
	split = ft_strsplit(str, ' ');
	i = 0;
	while (split[i] != NULL)
		i++;
	*len = i;
	i = 0;
	while (i < *len)
	{
		tab[i] = ft_atoi(split[i]);
		i++;
	}
	if (!check_duplicate(tab, *len))
		return (NULL);
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
		if (!check_digits(av[i + 1]))
			return (NULL);
		i++;
	}
	if (!check_duplicate(tab, i))
		return (NULL);
	return (tab);
}

void	convert_num(t_stack *stack, char **av, int nb)
{
	if (nb == 2)
		stack->tab_a = str_to_tab(av[1], stack->tab_a, &stack->size_a);
	else if (nb > 2)
	{
		nb -= 1;
		stack->size_a = nb;
		if (!(stack->tab_a = (int*)malloc(sizeof(int) * nb)))
			return ;
		stack->tab_a = fill_tab(av, stack->tab_a, nb);
	}
}

void	set_zero(t_stack *stack)
{
	stack->tab_a = NULL;
	stack->size_a = 0;
	stack->tab_b = NULL;
	stack->size_b = 0;
}
